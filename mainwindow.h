#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "biguint.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_addition_clicked();

    void on_subtract_clicked();

    void on_multiply_clicked();

    void on_power_clicked();

    void on_factorial_clicked();

    void on_store_clicked();

    void on_recall_clicked();

    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_lefto_textChanged(const QString &arg1);

    void on_righto_textChanged(const QString &arg1);

    void on_memory_textChanged(const QString &arg1);

private:
     biguint _left;
    biguint _right;
    biguint _mem;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
