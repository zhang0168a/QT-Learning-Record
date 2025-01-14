#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>  // 添加这一行来包含 QVBoxLayout 的头文件



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)  // 初始化 ui
{
   // ui->setupUi(this);  // 如果不需要自动生成的UI界面，可以注释掉
    radarWidget = new RadarWidget(this);  // 在这里初始化 radarWidget
    QWidget *centralWidget = new QWidget(this);

    // 设置主窗口的布局
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(radarWidget);  // 将 RadarWidget 添加到布局中
    setCentralWidget(centralWidget);  // 设置主窗口的中央控件



}


MainWindow::~MainWindow()
{
    delete ui;
}

