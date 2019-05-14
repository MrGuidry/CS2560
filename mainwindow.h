#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Zero_clicked();

    void on_One_clicked();

    void on_Two_clicked();

    void on_Three_clicked();

    void on_Four_clicked();

    void on_Five_clicked();

    void on_Six_clicked();

    void on_Seven_clicked();

    void on_Eight_clicked();

    void on_Nine_clicked();

    void on_Negative_clicked();

    void on_Clear_clicked();

    void on_Mod_clicked();

    void on_Divide_clicked();

    void on_Multiply_clicked();

    void on_Subtract_clicked();

    void on_Add_clicked();

    void on_Equals_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
