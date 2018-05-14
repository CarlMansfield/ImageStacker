/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QTreeWidget *lightsTree;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QTreeWidget *darksTree;
    QTreeWidget *flatsTree;
    QTreeWidget *biasTree;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QLabel *platform;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton_5;
    QWidget *verticalLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *buttonReg;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menuHello;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1080, 720);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(44, 44, 44, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 460, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 500, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 540, 75, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 580, 75, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 0, 61, 16));
        lightsTree = new QTreeWidget(centralWidget);
        lightsTree->setObjectName(QStringLiteral("lightsTree"));
        lightsTree->setEnabled(true);
        lightsTree->setGeometry(QRect(100, 450, 961, 192));
        lightsTree->setMinimumSize(QSize(259, 192));
        lightsTree->setFrameShadow(QFrame::Sunken);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(100, 430, 231, 80));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        QPalette palette1;
        QBrush brush2(QColor(0, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush3(QColor(240, 240, 240, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        tabWidget->setPalette(palette1);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        darksTree = new QTreeWidget(centralWidget);
        darksTree->setObjectName(QStringLiteral("darksTree"));
        darksTree->setEnabled(true);
        darksTree->setGeometry(QRect(100, 450, 961, 192));
        darksTree->setMinimumSize(QSize(259, 192));
        flatsTree = new QTreeWidget(centralWidget);
        flatsTree->setObjectName(QStringLiteral("flatsTree"));
        flatsTree->setEnabled(true);
        flatsTree->setGeometry(QRect(100, 450, 961, 192));
        flatsTree->setMinimumSize(QSize(259, 192));
        biasTree = new QTreeWidget(centralWidget);
        biasTree->setObjectName(QStringLiteral("biasTree"));
        biasTree->setEnabled(true);
        biasTree->setGeometry(QRect(100, 450, 961, 192));
        biasTree->setMinimumSize(QSize(259, 192));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(400, 20, 661, 401));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setFrameShadow(QFrame::Raised);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(3, 450, 90, 201));
        QPalette palette2;
        QBrush brush4(QColor(74, 74, 74, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        graphicsView_2->setPalette(palette2);
        graphicsView_2->setFrameShape(QFrame::StyledPanel);
        graphicsView_2->setFrameShadow(QFrame::Raised);
        platform = new QLabel(centralWidget);
        platform->setObjectName(QStringLiteral("platform"));
        platform->setGeometry(QRect(550, 660, 521, 16));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush5(QColor(120, 120, 120, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        platform->setPalette(palette3);
        platform->setLayoutDirection(Qt::LeftToRight);
        platform->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(200, 650, 251, 22));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setEnabled(true);
        comboBox_2->setGeometry(QRect(470, 650, 201, 22));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 620, 75, 23));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 161, 63));
        formLayout = new QFormLayout(verticalLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        buttonReg = new QPushButton(verticalLayoutWidget);
        buttonReg->setObjectName(QStringLiteral("buttonReg"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonReg->sizePolicy().hasHeightForWidth());
        buttonReg->setSizePolicy(sizePolicy2);

        formLayout->setWidget(0, QFormLayout::LabelRole, buttonReg);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        formLayout->setWidget(1, QFormLayout::SpanningRole, label);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(920, 0, 84, 15));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(840, 0, 81, 20));
        MainWindow->setCentralWidget(centralWidget);
        graphicsView_2->raise();
        tabWidget->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        label_2->raise();
        darksTree->raise();
        flatsTree->raise();
        biasTree->raise();
        lightsTree->raise();
        graphicsView->raise();
        platform->raise();
        comboBox->raise();
        comboBox_2->raise();
        pushButton_5->raise();
        verticalLayoutWidget->raise();
        horizontalSlider->raise();
        label_3->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1080, 22));
        menuHello = new QMenu(menuBar);
        menuHello->setObjectName(QStringLiteral("menuHello"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHello->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Add Lights...", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Add Darks...", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Add Flats...", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Add Bias...", 0));
        label_2->setText(QApplication::translate("MainWindow", "Preview:", 0));
        QTreeWidgetItem *___qtreewidgetitem = lightsTree->headerItem();
        ___qtreewidgetitem->setText(6, QApplication::translate("MainWindow", "Temp", 0));
        ___qtreewidgetitem->setText(5, QApplication::translate("MainWindow", "Camera", 0));
        ___qtreewidgetitem->setText(4, QApplication::translate("MainWindow", "Date/Time", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Resolution", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Exposure", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "ISO", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Name", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Lights", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Darks", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Flats", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Bias", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = darksTree->headerItem();
        ___qtreewidgetitem1->setText(5, QApplication::translate("MainWindow", "Camera", 0));
        ___qtreewidgetitem1->setText(4, QApplication::translate("MainWindow", "Date/Time", 0));
        ___qtreewidgetitem1->setText(3, QApplication::translate("MainWindow", "Exposure", 0));
        ___qtreewidgetitem1->setText(2, QApplication::translate("MainWindow", "ISO", 0));
        ___qtreewidgetitem1->setText(1, QApplication::translate("MainWindow", "Name", 0));
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Path", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = flatsTree->headerItem();
        ___qtreewidgetitem2->setText(5, QApplication::translate("MainWindow", "Camera", 0));
        ___qtreewidgetitem2->setText(4, QApplication::translate("MainWindow", "Date/Time", 0));
        ___qtreewidgetitem2->setText(3, QApplication::translate("MainWindow", "Exposure", 0));
        ___qtreewidgetitem2->setText(2, QApplication::translate("MainWindow", "ISO", 0));
        ___qtreewidgetitem2->setText(1, QApplication::translate("MainWindow", "Name", 0));
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Path", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = biasTree->headerItem();
        ___qtreewidgetitem3->setText(5, QApplication::translate("MainWindow", "Camera", 0));
        ___qtreewidgetitem3->setText(4, QApplication::translate("MainWindow", "Date/Time", 0));
        ___qtreewidgetitem3->setText(3, QApplication::translate("MainWindow", "Exposure", 0));
        ___qtreewidgetitem3->setText(2, QApplication::translate("MainWindow", "ISO", 0));
        ___qtreewidgetitem3->setText(1, QApplication::translate("MainWindow", "Name", 0));
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Path", 0));
        platform->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Directory", 0));
        buttonReg->setText(QApplication::translate("MainWindow", "Register", 0));
        label->setText(QApplication::translate("MainWindow", "Star threshold: 50", 0));
#ifndef QT_NO_TOOLTIP
        horizontalSlider->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Adjust threshold until 10-20 stars are visible</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "Brightness", 0));
        menuHello->setTitle(QApplication::translate("MainWindow", "Hello", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
