#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QProcess>
#include "info.h"
#include "about.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("CleanerTemp");
    MainWindow::setFixedSize(320, 151);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    {
    void clearDir( const QString path );
    QDir dir ("C:\\Windows\\Temp");
        dir.setFilter( QDir::NoDotAndDotDot | QDir::Files );
        foreach( QString dirItem, dir.entryList() )
            dir.remove( dirItem );

        dir.setFilter( QDir::NoDotAndDotDot | QDir::Dirs );
        foreach( QString dirItem, dir.entryList() )
        {
            QDir subDir( dir.absoluteFilePath( dirItem ) );
            subDir.removeRecursively();
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QProcess::startDetached("explorer", QStringList() << "C:\\Windows\\Temp");
}


void MainWindow::on_pushButton_3_clicked()
{
    info window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_pushButton_4_clicked()
{
    about window;
    window.setModal(true);
    window.exec();
}

