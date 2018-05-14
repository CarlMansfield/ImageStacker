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
    previewData.clear();
    int row;
    QModelIndex index = ui->lightsTree->currentIndex();
    row = index.row();
    QString filename = images[row].getPath();
    /*LibRaw processor;
    processor.open_file(filename.toStdString().c_str());
    processor.unpack();
    processor.imgdata.params.no_auto_bright = 1;
    processor.dcraw_process();
    libraw_processed_image_t *output = processor.dcraw_make_mem_image();
    uchar *pixels;
    int pixelCount = images[row].getWidth() * images[row].getHeight();
    int colorSize = output->bits / 8;
    qDebug(QString::number(colorSize).toStdString().c_str());
    int pixelSize = output->colors * colorSize;
    qDebug(QString::number(pixelSize).toStdString().c_str());
    pixels = new uchar[pixelCount * 4];
    uchar *data = output->data;
    for (int i = 0; i < pixelCount; i++, data += pixelSize) {
        if (output->colors == 3) {
            pixels[i * 4] = data[2 * colorSize];
            pixels[i * 4 + 1] = data[1 * colorSize];
            pixels[i * 4 + 2] = data[0];
        } else {
            pixels[i * 4] = data[0];
            pixels[i * 4 + 1] = data[0];
            pixels[i * 4 + 2] = data[0];
        }
    }*/
    previewData = images[row];
    qDebug("Testststst");
    previewData.data = previewData.loadFromFile();
    qDebug("Loaded successfully");
    display_preview();
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

void MainWindow::display_changed_brightness(uchar* data)
{
    QImage image(data, previewData.getWidth(), previewData.getHeight(), QImage::Format_RGB32);
    QPixmap pixmap = QPixmap::fromImage(image);
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

    QSettings settings("ImageStacker", "CarlSoftware");
    folder = QFileDialog::getExistingDirectory(0, ("Select default directory"), QDir::currentPath());
    settings.setValue("path", folder);
}


void MainWindow::open_image(QString file) {
    LibRaw processor;
    processor.open_file(file.toStdString().c_str());

    qDebug("Temp: %f", processor.imgdata.other.CameraTemperature);

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
        item->setText(0, name.c_str());

        item->setText(1, QString::number(images[i].getISO()));
        item->setText(3, images[i].getDimensions());
        item->setText(4, images[i].getDateTime());
        item->setText(5, images[i].getCamera());
        ss.clear();
        ss.str(std::string());
        ss.precision(2);
        ss << images[i].getTemp();
        item->setText(6, QString::fromStdString(ss.str()).append("°C"));


        ui->lightsTree->addTopLevelItem(item);

        pixmap = QPixmap(filename);

    }
    ui->lightsTree->raise();
    scene->clear();
    scene->addPixmap(pixmap);
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->label->setText("Star threshold: " + QString::number(position));
    tempData = new uchar[(previewData.getWidth() * previewData.getHeight()) * 4];
    ImageTools::increaseBrightness(previewData, position-50, tempData);
    display_changed_brightness(tempData);
    qDebug("before delete");
    delete[] tempData;
    qDebug("after delete");
}
