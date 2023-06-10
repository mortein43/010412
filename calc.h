
#ifndef CALC_H
#define CALC_H

#include <QMainWindow>
#include <QRegularExpressionValidator>
#include <QRegularExpression>



QT_BEGIN_NAMESPACE
namespace Ui { class calc; }
QT_END_NAMESPACE

class calc : public QMainWindow

{
    Q_OBJECT

public:
    calc(QWidget *parent = nullptr);
    ~calc();

private slots:
    void on_pushButton_clicked();
    void actions();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

private:
    Ui::calc *ui;
};

#endif // CALC_H
