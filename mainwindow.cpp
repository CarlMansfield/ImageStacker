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
#include "opencv2/core/cuda.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"

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
ImageData previewData;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCoreApplication::setApplicationName("CarlSoftware");
    QCoreApplication::setOrganizationName("ImageStacker");
    QVariant value = defaultSettings.value("path");
    if (value.type() == QVariant::String) {
        defaultDir = value.toString();
    }
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::white);
    ui->label_2->setPalette(palette);
    ui->label->setPalette(palette);
    ui->label_3->setPalette(palette);
    ui->ramLabel->setPalette(palette);
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
    ui->ramLabel->setText("RAM usage: ");
    workerT = new QThread();
    imgTools = new ImageTools();
    imgTools->doSetup(*workerT);
    imgTools->moveToThread(workerT);
    connect(imgTools, SIGNAL(imageRead()), this, SLOT(display_changed_brightness()));
}

MainWindow::~MainWindow()
{
    delete ui;
    workerT->wait();
    workerT->quit();
    delete workerT;
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
    imgTools->tempData = &previewData;
    workerT->start();
}

void MainWindow::storeData(ImageData imgData)
{
    //imgData.data = pixels;
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
    //previewData.clear();
    int row;
    QModelIndex index = ui->lightsTree->currentIndex();
    row = index.row();
    QString filename = images[row].getPath();
    previewData = images[row];
    imgTools->tempData = &previewData;
    workerT->start();
    std::cout << &previewData << std::endl;
}

void MainWindow::display_preview()
{
    QImage image(previewData.data, previewData.getWidth(), previewData.getHeight(), QImage::Format_RGB32);
    QPixmap pixmap = QPixmap::fromImage(image);
    scene->clear();
    scene->addPixmap(pixmap);
    ui->graphicsView->ensureVisible(scene->sceneRect());
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void MainWindow::display_changed_brightness()
{
    workerT->terminate();
    //previewData = *imgTools->tempData;
    qDebug() << "displaying image";
    tempImage = ImageTools::increaseBrightness(previewData, ui->horizontalSlider->value()-50);
    qDebug("Before return");
    QImage image(tempImage.data, previewData.getWidth(), previewData.getHeight(), QImage::Format_RGB32);
    QPixmap pixmap = QPixmap::fromImage(image);
    scene->clear();
    scene->addPixmap(pixmap);
    ui->graphicsView->ensureVisible(scene->sceneRect());
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
    imgTools->clearCache();
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

    QSettings settings("ImageStacker", "CarlSoftware");
    folder = QFileDialog::getExistingDirectory(0, ("Select default directory"), QDir::currentPath());
    settings.setValue("path", folder);
}


void MainWindow::open_image(QString file) {
    LibRaw processor;
    processor.open_file(file.toStdString().c_str());

    qDebug("Temp: %f", processor.imgdata.other.CameraTemperature);
    ImageData data;
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
        qDebug() << exposure;

        data.setPath(file.toStdString().c_str());
        data.setCamera(model);
        data.setISO(iso.toInt());
        //data.setExposure();
        data.setDateTime(dateTime);
        data.setExposure(exposure);
        data.setWidth(processor.imgdata.sizes.width);
        data.setHeight(processor.imgdata.sizes.height);
        data.setTemp(processor.imgdata.other.CameraTemperature);

        images.push_back(data);
        /*Exiv2::ExifData::const_iterator end = exifData.end();
        for (Exiv2::ExifData::const_iterator i = exifData.begin(); i != end; ++i) {
            const char* tn = i->typeName();
            std::cout << std::setw(44) << std::setfill(' ') << std::left
                      << i->key() << " "
                      << "0x" << std::setw(4) << std::setfill('0') << std::right
                      << std::hex << i->tag() << " "
                      << std::setw(9) << std::setfill(' ') << std::left
                      << (tn ? tn : "Unknown") << " "
                      << std::dec << std::setw(3)
                      << std::setfill(' ') << std::right
                      << i->count() << "  "
                      << std::dec << i->value()
                      << "\n";
        }*/

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
    previewData = data;
}

void MainWindow::updateTable() {
    ui->lightsTree->clear();
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
        item->setText(1, name.c_str());

        item->setText(2, QString::number(images[i].getISO()));
        item->setText(3, images[i].getExposure());
        qDebug() << images[i].getExposure();
        item->setText(4, images[i].getDimensions());
        item->setText(5, images[i].getDateTime());
        item->setText(6, images[i].getCamera());
        ss.clear();
        ss.str(std::string());
        ss.precision(2);
        ss << images[i].getTemp();
        item->setText(7, QString::fromStdString(ss.str()).append("°C"));
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item->setCheckState(0, Qt::Checked);
        ui->lightsTree->addTopLevelItem(item);

        pixmap = QPixmap(filename);

    }
    ui->lightsTree->raise();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->label->setText("Star threshold: " + QString::number(position));
    tempImage = ImageTools::increaseBrightness(previewData, position-50);
    display_changed_brightness();
}

void MainWindow::on_buttonReg_clicked()
{
    StarDetection detector;
    starsDetected = detector.detectStars(tempImage, contours, hierarchy);
    int stars = contours.size();
    QTreeWidgetItem *item = ui->lightsTree->currentItem();
    item->setText(8, QString::number(stars));
}

void MainWindow::on_pushButton_6_pressed()
{
    /*QImage image(starsDetected.data, starsDetected.cols, starsDetected.rows, QImage::Format_Indexed8);
    qDebug() << "after conversion";
    QPixmap pixmap = QPixmap::fromImage(image);
    scene->clear();
    scene->addPixmap(pixmap);
    ui->graphicsView->ensureVisible(scene->sceneRect());
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);*/

    for (int i = 0; i < contours.size(); i++) {
        cv::Scalar colour = cv::Scalar(255, 0 , 255);
        cv::drawContours(tempImage, contours, i, colour, 2, 8, hierarchy, 0, cv::Point(0, 0));
    }

    QImage image(tempImage.data, tempImage.cols, tempImage.rows, QImage::Format_RGB32);
    qDebug() << "after conversion";
    QPixmap pixmap = QPixmap::fromImage(image);
    scene->clear();
    scene->addPixmap(pixmap);
    ui->graphicsView->ensureVisible(scene->sceneRect());
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);

    //cv::cuda::GpuMat test;

}

void MainWindow::on_pushButton_6_released()
{
    display_changed_brightness();
}

void MainWindow::getRamUsage()
{
    /*MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatus(&statex);

    qDebug() << "Memory usage: %*ld"*/
}
