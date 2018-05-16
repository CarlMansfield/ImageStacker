#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QSettings>
#include "imagedata.h"
#include "imagetools.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    std::vector<ImageData> images;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lightsTree_itemClicked(QTreeWidgetItem *item, int column);

    void on_tabWidget_tabBarClicked(int index);

    void on_comboBox_currentIndexChanged(int index);

    void refreshUsedDevice();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_5_clicked();

    void on_horizontalSlider_sliderMoved(int position);

protected:
    void mouseMoveEvent(QMouseEvent * event);

    void open_image(QString filename);

    void updateTable();

    void display_preview();

    void display_changed_brightness();
private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsItem* item;
    QAction *myAction;
    cv::Mat tempImage;
    uchar* tempData = nullptr;
    QSettings defaultSettings;
};

#endif // MAINWINDOW_H
