
#include "calc.h"
#include "./ui_calc.h"
#include "math.h"


calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this);
    //маска #	дозволяє цифри і знаки +,-
    //ui->lineEdit->setInputMask("#");
    QRegularExpression rx("^(-?)[0-9]{1,7}([\.][0-9]{1,2})?$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit_2->setValidator(validator);
}

calc::~calc()
{
    delete ui;
}

QString fromDecimalToBinary (QString numeric)
{
    QString res = "";
    QString resForDouble = "";
    bool flag = false;
    int num1 = 0;
    double num2 = 0.0;
    int temp;
    double tempForDouble;
    if (numeric.indexOf('.')!=-1)
    {
        flag = true;
        num2 = QVariant(numeric).toDouble();
    } else num1 = QVariant(numeric).toInt();

    if (flag == false)
    {
        int copyNum1 = num1;
        while (copyNum1!=0)
        {
            temp = copyNum1%2;
            copyNum1 = copyNum1/2;
            res = res.insert(0, QString::number(temp));

        }
    } else if (flag == true)
    {
        int copyNum1 = (int)num2;
        double copyNum2 = num2 - copyNum1;
        int tempForInt = 0;

        while (copyNum1!=0)
        {
            temp = copyNum1%2;
            copyNum1 = copyNum1/2;
            res = res.insert(0, QString::number(temp));
        }
        while (tempForInt < 1)
        {
            tempForDouble = copyNum2*2;
            tempForInt = (int)tempForDouble%2;
            copyNum2 = tempForDouble;
            resForDouble = resForDouble.insert(resForDouble.size(), QString::number(tempForInt));
        }

    }
    if (numeric.indexOf('.')>-1)
    {
        return res+","+resForDouble;
    } else return res;
}

void calc::actions ()
{
    if (ui->comboBox->currentText() == "Додавання")
    {
        ui->label_2->setText("");
        double a = QVariant(ui->lineEdit->text()).toDouble();
        double b = QVariant(ui->lineEdit_2->text()).toDouble();
        double res = a+b;
        ui->label_3->setText(QVariant(a).toString() + " + " + QVariant(b).toString() + " = " + QVariant(res).toString());
        ui->label->setText(QVariant(res).toString());
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->setFocus();
    } else if (ui->comboBox->currentText() == "Віднімання")
    {
        ui->label_2->setText("");
        double a = QVariant(ui->lineEdit->text()).toDouble();
        double b = QVariant(ui->lineEdit_2->text()).toDouble();
        double res = a-b;
        ui->label_3->setText(QVariant(a).toString() + " - " + QVariant(b).toString() + " = " + QVariant(res).toString());
        ui->label->setText(QVariant(res).toString());
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->setFocus();
    } else if (ui->comboBox->currentText() == "Множення")
    {
        ui->label_2->setText("");
        double a = QVariant(ui->lineEdit->text()).toDouble();
        double b = QVariant(ui->lineEdit_2->text()).toDouble();
        double res = a*b;
        ui->label_3->setText(QVariant(a).toString() + " * " + QVariant(b).toString() + " = " + QVariant(res).toString());
        ui->label->setText(QVariant(res).toString());
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit->setFocus();
    } else if (ui->comboBox->currentText() == "Ділення")
    {
        ui->label_2->setText("");
        double a = QVariant(ui->lineEdit->text()).toDouble();
        double b = QVariant(ui->lineEdit_2->text()).toDouble();
        if (b==0)
        {
            ui->label_2->setText("На нуль ділити не можна!");
        } else
        {
            double res = a/b;
            ui->label_3->setText(QVariant(a).toString() + " / " + QVariant(b).toString() + " = " + QVariant(res).toString());
            ui->label->setText(QVariant(res).toString());
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit->setFocus();
        }
    } else if (ui->comboBox->currentText() == "Остача")
    {
        ui->label_2->setText("");
        int a = QVariant(ui->lineEdit->text()).toInt();
        int b = QVariant(ui->lineEdit_2->text()).toInt();
        if (b==0)
        {
            ui->label_2->setText("На нуль ділити не можна!");
        } else
        {
            int res = a%b;
            ui->label_3->setText(QVariant(a).toString() + " % " + QVariant(b).toString() + " = " + QVariant(res).toString());
            ui->label->setText(QVariant(res).toString());
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit->setFocus();
        }
    } else if (ui->comboBox->currentText() == "У двійкову")
    {
        ui->label_2->setText("");
        QString numeric = ui->lineEdit->text();
        double res = QVariant(numeric).toDouble();
        if (res < 1)
        {
            ui->label_2->setText("Для переведення числа у двійкову систему, \nчисло має бути додатнє.");
        } else
        {
            ui->label_3->setText(numeric +  " = " + fromDecimalToBinary(numeric));
            ui->label->setText(fromDecimalToBinary(numeric));
            ui->lineEdit->clear();
            ui->lineEdit->setFocus();
        }
    }
}

void calc::on_pushButton_clicked()
{
    //QVariant(3.2).toString();
    //QVariant("5.2").toFloat();
    actions();
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
}


void calc::on_lineEdit_returnPressed()
{
  if (ui->comboBox->currentText() == "У двійкову" && ui->lineEdit_2->text().isEmpty())
    {
        actions();
    } else ui->label_2->setText("Перевірте умову до використання операції \"У двійкову\".");
}


void calc::on_lineEdit_2_returnPressed()
{
    if (ui->lineEdit->text().length()>0 && ui->lineEdit_2->text().length()>0)
    {
        actions();
    } else ui->label_2->setText("Перевірте чи заповненні поля вводу.");
}

