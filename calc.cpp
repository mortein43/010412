
#include "calc.h"
#include "./ui_calc.h"
#include "math.h"


calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this);
}

calc::~calc()
{
    delete ui;
}



void calc::on_pushButton_clicked()
{
    //QVariant(3.2).toString();
    //QVariant("5.2").toFloat();

    if (ui->comboBox->currentText() == "Додавання")
    {
        double a = QVariant(ui->lineEdit->text()).toDouble();
        double b = QVariant(ui->lineEdit_2->text()).toDouble();
        double res = a+b;
        ui->label->setText(QVariant(res).toString());
    } else if (ui->comboBox->currentText() == "Віднімання")
    {
        double a = QVariant(ui->lineEdit->text()).toDouble();
        double b = QVariant(ui->lineEdit_2->text()).toDouble();
        double res = a-b;
        ui->label->setText(QVariant(res).toString());
    } else if (ui->comboBox->currentText() == "Множення")
    {
        double a = QVariant(ui->lineEdit->text()).toDouble();
        double b = QVariant(ui->lineEdit_2->text()).toDouble();
        double res = a*b;
        ui->label->setText(QVariant(res).toString());
    } else if (ui->comboBox->currentText() == "Ділення")
    {
        double a = QVariant(ui->lineEdit->text()).toDouble();
        double b = QVariant(ui->lineEdit_2->text()).toDouble();
        if (b==0)
        {
            ui->label_2->setText("На нуль ділити не можна!");
        } else
        {
            double res = a/b;
            ui->label->setText(QVariant(res).toString());
        }
    }

}

