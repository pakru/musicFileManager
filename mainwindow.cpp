#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString sPath = "E:/";
    //dirModel = new QFileSystemModel(this);
    //dirModel->setRootPath(sPath);
    //dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    fileModel->setRootPath(sPath);

    //ui->treeView->setModel(dirModel);
    ui->tableView->setModel(fileModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
//    std::count << "Selected row: " << row << std::endl;
    qDebug() << "Selected row: " << row;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit(0);
}
