/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
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
    QLabel *platform;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QSlider *horizontalSlider;
    QLabel *label_3;
    QPushButton *pushButton_6;
    QLabel *ramLabel;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QPushButton *buttonReg;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
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
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 0, 61, 16));
        lightsTree = new QTreeWidget(centralWidget);
        lightsTree->headerItem()->setText(0, QString());
        lightsTree->setObjectName(QStringLiteral("lightsTree"));
        lightsTree->setEnabled(true);
        lightsTree->setGeometry(QRect(20, 450, 1041, 192));
        lightsTree->setMinimumSize(QSize(259, 192));
        lightsTree->setFrameShadow(QFrame::Sunken);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 430, 231, 80));
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
        darksTree->setGeometry(QRect(20, 450, 1041, 192));
        darksTree->setMinimumSize(QSize(259, 192));
        flatsTree = new QTreeWidget(centralWidget);
        flatsTree->setObjectName(QStringLiteral("flatsTree"));
        flatsTree->setEnabled(true);
        flatsTree->setGeometry(QRect(20, 450, 1041, 192));
        flatsTree->setMinimumSize(QSize(259, 192));
        biasTree = new QTreeWidget(centralWidget);
        biasTree->setObjectName(QStringLiteral("biasTree"));
        biasTree->setEnabled(true);
        biasTree->setGeometry(QRect(20, 450, 1041, 192));
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
        platform = new QLabel(centralWidget);
        platform->setObjectName(QStringLiteral("platform"));
        platform->setGeometry(QRect(550, 660, 521, 16));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
        platform->setPalette(palette2);
        platform->setLayoutDirection(Qt::LeftToRight);
        platform->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(200, 650, 251, 22));
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setEnabled(true);
        comboBox_2->setGeometry(QRect(470, 650, 201, 22));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(920, 0, 84, 15));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(840, 0, 81, 20));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(720, 0, 80, 21));
        ramLabel = new QLabel(centralWidget);
        ramLabel->setObjectName(QStringLiteral("ramLabel"));
        ramLabel->setGeometry(QRect(10, 660, 47, 13));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 161, 401));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(verticalLayoutWidget_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_5->addWidget(pushButton);

        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_5->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_5->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_5->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_5->addWidget(pushButton_5);


        verticalLayout_4->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(verticalLayoutWidget_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        buttonReg = new QPushButton(groupBox_4);
        buttonReg->setObjectName(QStringLiteral("buttonReg"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonReg->sizePolicy().hasHeightForWidth());
        buttonReg->setSizePolicy(sizePolicy2);

        verticalLayout_6->addWidget(buttonReg);

        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        verticalLayout_6->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        verticalLayout_4->addWidget(groupBox_4);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(350, 370, 41, 41));
        label_4->setMaximumSize(QSize(64, 64));
        MainWindow->setCentralWidget(centralWidget);
        tabWidget->raise();
        label_2->raise();
        darksTree->raise();
        flatsTree->raise();
        biasTree->raise();
        graphicsView->raise();
        platform->raise();
        comboBox->raise();
        comboBox_2->raise();
        horizontalSlider->raise();
        label_3->raise();
        pushButton_6->raise();
        ramLabel->raise();
        verticalLayoutWidget_2->raise();
        lightsTree->raise();
        label_4->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1080, 20));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Preview:", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = lightsTree->headerItem();
        ___qtreewidgetitem->setText(8, QApplication::translate("MainWindow", "Stars", Q_NULLPTR));
        ___qtreewidgetitem->setText(7, QApplication::translate("MainWindow", "Temp", Q_NULLPTR));
        ___qtreewidgetitem->setText(6, QApplication::translate("MainWindow", "Camera", Q_NULLPTR));
        ___qtreewidgetitem->setText(5, QApplication::translate("MainWindow", "Date/Time", Q_NULLPTR));
        ___qtreewidgetitem->setText(4, QApplication::translate("MainWindow", "Resolution", Q_NULLPTR));
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Exposure", Q_NULLPTR));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "ISO", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Lights", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Darks", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Flats", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Bias", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem1 = darksTree->headerItem();
        ___qtreewidgetitem1->setText(5, QApplication::translate("MainWindow", "Camera", Q_NULLPTR));
        ___qtreewidgetitem1->setText(4, QApplication::translate("MainWindow", "Date/Time", Q_NULLPTR));
        ___qtreewidgetitem1->setText(3, QApplication::translate("MainWindow", "Exposure", Q_NULLPTR));
        ___qtreewidgetitem1->setText(2, QApplication::translate("MainWindow", "ISO", Q_NULLPTR));
        ___qtreewidgetitem1->setText(1, QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Path", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = flatsTree->headerItem();
        ___qtreewidgetitem2->setText(5, QApplication::translate("MainWindow", "Camera", Q_NULLPTR));
        ___qtreewidgetitem2->setText(4, QApplication::translate("MainWindow", "Date/Time", Q_NULLPTR));
        ___qtreewidgetitem2->setText(3, QApplication::translate("MainWindow", "Exposure", Q_NULLPTR));
        ___qtreewidgetitem2->setText(2, QApplication::translate("MainWindow", "ISO", Q_NULLPTR));
        ___qtreewidgetitem2->setText(1, QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Path", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = biasTree->headerItem();
        ___qtreewidgetitem3->setText(5, QApplication::translate("MainWindow", "Camera", Q_NULLPTR));
        ___qtreewidgetitem3->setText(4, QApplication::translate("MainWindow", "Date/Time", Q_NULLPTR));
        ___qtreewidgetitem3->setText(3, QApplication::translate("MainWindow", "Exposure", Q_NULLPTR));
        ___qtreewidgetitem3->setText(2, QApplication::translate("MainWindow", "ISO", Q_NULLPTR));
        ___qtreewidgetitem3->setText(1, QApplication::translate("MainWindow", "Name", Q_NULLPTR));
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Path", Q_NULLPTR));
        platform->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        horizontalSlider->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Adjust threshold until 10-20 stars are visible</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "Brightness", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Show stars", Q_NULLPTR));
        ramLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Add Images", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Add Lights...", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Add Bias...", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Add Flats...", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Add Darks...", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Directory", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Registration", Q_NULLPTR));
        buttonReg->setText(QApplication::translate("MainWindow", "Register", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Star threshold: 50", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        menuHello->setTitle(QApplication::translate("MainWindow", "Hello", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
