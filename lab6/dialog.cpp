#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include <QFile>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
void Dialog::setStringList(const QList<QString> &list) {
    history1 = list;}
QFile FileOut("C:\\Users\\Anastasia\\Desktop\\qt project\\lab6\\history.txt");
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        if(!(FileOut.exists()))
        {
            qWarning("The file doesn't exists");
        }
        else
        {
            if(FileOut.open(QIODevice::Append))
            {
                QTextStream write(&FileOut);
                for (int i=0; i<history1.size(); i++)
                {
                    write<<history1[i];
                }
            }
        }
        this->close();
    }
    if (ui->radioButton_2->isChecked())
    {
        this->close();
    }


}

