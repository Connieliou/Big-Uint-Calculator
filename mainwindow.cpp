#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addition_clicked()
{
   _left+=_right;
    ui->lefto->setText(_left.toQString());
}

void MainWindow::on_subtract_clicked()
{
    _left-=_right;
    ui->lefto->setText(_left.toQString());
}

void MainWindow::on_multiply_clicked()
{
    _left*=_right;
    ui->lefto->setText(_left.toQString());
}



void MainWindow::on_power_clicked()
{
    biguint ans(1);
    for(biguint i=1;i<= _right;i+=biguint(1))
    {
        ans=ans*_left;
    }
    _left=ans;
    ui->lefto->setText(_left.toQString());
}

void MainWindow::on_factorial_clicked()
{
    biguint fact(1);
    for(biguint i=1; i<=_left; i+=biguint(1))
    {
       fact=fact*i;
    }
    _left = fact;
    ui->lefto->setText(_left.toQString());
}


void MainWindow::on_store_clicked()
{
    _mem=_left;
    ui->memory->setText(_mem.toQString());
}


void MainWindow::on_recall_clicked()
{
    _right=_mem;
    ui->righto->setText(_right.toQString());

}


void MainWindow::on_actionQuit_triggered()
{
    exit(0);
}

void MainWindow::on_actionAbout_triggered()
{
     QMessageBox about;
     about.setText(tr("<h2>About HW4 Calculator</h2> <p> Connie Liou Copyright &copy; 2015"));



        about.exec();
}

void MainWindow::on_lefto_textChanged(const QString &arg1)
{_left=biguint(arg1.toStdString());
ui->lefto->setText(_left.toQString());
}

void MainWindow::on_righto_textChanged(const QString &arg1)
{_right=biguint(arg1.toStdString());
ui->righto->setText(_right.toQString());
}

void MainWindow::on_memory_textChanged(const QString &arg1)
{_mem=biguint(arg1.toStdString());
ui->memory->setText(_mem.toQString());
}
