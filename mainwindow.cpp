#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BigNumberLibrary/BigNumberLib.h"

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

void MainWindow::on_Zero_clicked()
{
    ui->textEdit->insertPlainText("0");
}

void MainWindow::on_One_clicked()
{
    ui->textEdit->insertPlainText("1");
}

void MainWindow::on_Two_clicked()
{
    ui->textEdit->insertPlainText("2");
}

void MainWindow::on_Three_clicked()
{
    ui->textEdit->insertPlainText("3");
}

void MainWindow::on_Four_clicked()
{
    ui->textEdit->insertPlainText("4");
}

void MainWindow::on_Five_clicked()
{
    ui->textEdit->insertPlainText("5");
}

void MainWindow::on_Six_clicked()
{
    ui->textEdit->insertPlainText("6");
}

void MainWindow::on_Seven_clicked()
{
    ui->textEdit->insertPlainText("7");
}

void MainWindow::on_Eight_clicked()
{
    ui->textEdit->insertPlainText("8");
}

void MainWindow::on_Nine_clicked()
{
    ui->textEdit->insertPlainText("9");
}

void MainWindow::on_Negative_clicked()
{
    ui->textEdit->insertPlainText("-");
}

void MainWindow::on_Clear_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_Mod_clicked()
{
    ui->textEdit->insertPlainText("%");
}

void MainWindow::on_Divide_clicked()
{
    ui->textEdit->insertPlainText("/");
}

void MainWindow::on_Multiply_clicked()
{
    ui->textEdit->insertPlainText("*");
}

void MainWindow::on_Subtract_clicked()
{
    ui->textEdit->insertPlainText("_");
}

void MainWindow::on_Add_clicked()
{
    ui->textEdit->insertPlainText("+");
}

void MainWindow::on_Equals_clicked()
{
    QString equation = ui->textEdit->toPlainText();
    QString first = "";
    QString second = "";
    bool next = false;
    QChar op = ' ';
    for(int i = 0;i < equation.length();i++){
        if(!next && equation[i] != '%' && equation[i] != '/' && equation[i] != '*' && equation[i] != '+' && equation[i] != '_'){
            first.push_back(equation.at(i));
        }else{
            if(!next){
                op = equation.at(i);
                next = true;
            }else{
                second.push_back(equation.at(i));
            }
        }
    }
    std::string f = first.toStdString();
    std::string s = second.toStdString();

    BigNumber n1(f);
    BigNumber n2(s);
    BigNumber answer("");

    if(op == '+'){
        answer = n1.add(n2);
    }else if (op == '_') {
        answer = n1.subtract(n2);
    }else if (op == '*') {
        answer = n1.multiply(n2);
    } else if (op == '%') {
        answer = n1.mod(n2);
    }else if (op == '/') {
        answer = n1.divide(n2);
    }

    QString a = QString::fromStdString(answer.toString());
    ui->textEdit->insertPlainText(a);
}
