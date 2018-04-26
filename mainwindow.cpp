#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QDebug>
#include<sstream>
#include<string>
#include<utility>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <libraw/libraw.h>
#include <exiv2/exiv2.hpp>

#ifdef __APPLE__
#include <cl.hpp>
#else
#include <CL/cl.hpp>
#endif

std::vector<cl::Platform> all_platforms;
std::vector<cl::Device> all_devices;
cl::Platform temp_platform;
cl::Platform current_platform;
cl::Device temp_device;
cl::Device current_device;
QString defaultDir;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->label_2->setPalette(QPalette::Light);
    this->setFixedSize(this->maximumSize());
    ui->lightsTree->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction* removeAction;
    removeAction = new QAction("Remove", this);
    ui->lightsTree->addAction(removeAction);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setStyleSheet("background: transparent");
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    cl::Platform::get(&all_platforms);
    if(all_platforms.size()==0) {
        QMessageBox::information(
                    this,
                    tr("OpenCL error"),
                    tr("No OpenCL compatible platforms found"));
    } else {
        for (int i = 0; i < all_platforms.size(); i++) {
            temp_platform = all_platforms[i];
            std::stringstream ss;
            ss << temp_platform.getInfo<CL_PLATFORM_NAME>();
            std::string s = ss.str();
            ui->comboBox->addItem(QString::fromStdString(s));
        }
        current_platform = all_platforms[0];
        current_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);
        current_device = all_devices[0];
        std::stringstream ss;
        ss << "Using platform: " << current_platform.getInfo<CL_PLATFORM_NAME>() << " on device: " << current_device.getInfo<CL_DEVICE_NAME>();
        std::string s = ss.str();

        ui->platform->setText(QString::fromStdString(s));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename;
    QStringList files = QFileDialog::getOpenFileNames(
                this,
                tr("Select light frames"),
                defaultDir,
                tr("Image files (*.tif *.jpg *.CR2"));
    if (!files.size() == 0) {
        for (int i = 0; i < files.size(); i++) {
            filename = files.at(i);
            open_image(filename);
        }
    }
    updateTable();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->comboBox_2->clear();
    current_platform = all_platforms[index];
    current_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);
    for (int i = 0; i < all_devices.size(); i++) {
        current_device = all_devices[i];
        std::stringstream ss;
        ss << current_device.getInfo<CL_DEVICE_NAME>();
        std::string s = ss.str();
        ui->comboBox_2->addItem(QString::fromStdString(s));
    }
    current_device = all_devices[0];
    refreshUsedDevice();
}

void MainWindow::refreshUsedDevice()
{
    std::stringstream ss;
    ss << "Using platform: " << current_platform.getInfo<CL_PLATFORM_NAME>() << " on device: " << current_device.getInfo<CL_DEVICE_NAME>();
    std::string s = ss.str();

    ui->platform->setText(QString::fromStdString(s));
}

void MainWindow::on_lightsTree_itemClicked(QTreeWidgetItem *item, int column)
{
    QString filename = item->text(0);
    QPixmap pixmap(filename);
    scene->clear();
    scene->addPixmap(pixmap);
    ui->graphicsView->ensureVisible(scene->sceneRect());
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void MainWindow::on_lightsTree_itemSelectionChanged()
{
    QString filename = ui->lightsTree->selectedItems().takeFirst()->text(0);
    QString test = "test.jpg";
    QByteArray name(filename.toStdString().c_str());
    QByteArray output(test.toStdString().c_str());
    QPixmap pixmap(filename);
    scene->clear();
    scene->addPixmap(pixmap);
    ui->graphicsView->ensureVisible(scene->sceneRect());
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //QPoint local_pt = ui->graphicsView->mapFromGlobal(event);
    //QPointF img_coords = ui->graphicsView->mapToScene(local_pt);
    qDebug("Test");
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    switch (index)
    {
    case 0:
        ui->lightsTree->raise();
        break;
    case 1:
        ui->darksTree->raise();
        break;
    case 2:
        ui->biasTree->raise();
        break;
    case 3:
        ui->flatsTree->raise();
        break;
    }
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    //current_device = all_devices[index];
    refreshUsedDevice();
}

void MainWindow::on_pushButton_5_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    QString folder;

    folder = QFileDialog::getExistingDirectory(0, ("Select default directory"), QDir::currentPath());



    defaultDir = folder;
}


void MainWindow::open_image(QString file) {
    LibRaw processor;
    processor.open_file(file.toStdString().c_str());


    try {
        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(file.toStdString().c_str(), sizeof(file.toStdString().c_str()));
        assert(image.get() != 0);
        image->readMetadata();

        Exiv2::ExifData &exifData = image->exifData();
        if (exifData.empty()) {
            std::string error(file.toStdString().c_str());
            error += ": No Exif data found in the file";
            throw Exiv2::Error(1, error);
        }
        Exiv2::Exifdatum& tag = exifData["Exif.Photo.ISOSpeedRatings"];
        QString iso = QString::fromStdString(tag.toString());
        tag = exifData["Exif.Image.Model"];
        QString model = QString::fromStdString(tag.toString());
        tag = exifData["Exif.Image.DateTime"];
        QString dateTime = QString::fromStdString(tag.toString());
        tag = exifData["Exif.Photo.ExposureTime"];
        QString exposure = QString::fromStdString(tag.toString());

        ImageData data;
        data.setPath(file.toStdString().c_str());
        data.setCamera(model);
        data.setISO(iso.toInt());
        //data.setExposure();
        data.setDateTime(dateTime);
        data.setWidth(processor.imgdata.sizes.width);
        data.setHeight(processor.imgdata.sizes.height);

        images.push_back(data);

        /*
         * Exif.Photo.ISOSpeedRatings                   0x8827 Short       1  1600
         * Exif.Image.DateTime                          0x0132 Ascii      20  2018:01:06 21:46:15
         * Exif.Image.Model                             0x0110 Ascii      16  Canon EOS 1000D
         * Exif.Photo.ExposureTime                      0x829a Rational    1  600/1
        */
    } catch (Exiv2::AnyError& e) {
        //std::cout << "Caught Exiv2 exception '" << e.what() << "'\n";
        qDebug(e.what());
    }
}

void MainWindow::updateTable() {

    QPixmap pixmap;

    for (int i = 0; i < images.size(); i++) {

        QTreeWidgetItem *item = new QTreeWidgetItem();
        QString filename = images[i].getPath();
        std::vector<std::string> path;
        std::stringstream ss(filename.toStdString().c_str());
        std::string part;
        while (std::getline(ss, part, '/')) {
            path.push_back(part);
        }
        int temp = 0;
        temp = std::count(filename.begin(), filename.end(), '/');
        //QString name = QString::fromStdString(path[temp - 1]);
        std::string name = path[temp];
        item->setText(0, name.c_str());

        item->setText(1, QString::number(images[i].getISO()));
        item->setText(3, images[i].getDimensions());
        item->setText(4, images[i].getDateTime());
        item->setText(5, images[i].getCamera());


        ui->lightsTree->addTopLevelItem(item);

        pixmap = QPixmap(filename);

    }
    ui->lightsTree->raise();
    scene->clear();
    scene->addPixmap(pixmap);
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}
