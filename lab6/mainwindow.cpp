#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QContextMenuEvent>
#include "dialog.h"
#include <QMenu>
#include <QAction>
#include <QFile>
#include <QTextStream>
#include <QListView>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &MainWindow::customContextMenuRequested,
            this, &MainWindow::showContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QStringList MainWindow::readListFromFile()
{
    QStringList items;
    QFile file("C:\\Users\\Anastasia\\Desktop\\qt project\\lab6\\history.txt");

    if (!file.open(QIODevice::ReadOnly )) {
        QMessageBox::warning(this, "Error", "Failed to open file");
        return items;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (!line.isEmpty()) {
            items << line;
        }
    }

    file.close();
    return items;
}
void MainWindow::showListInMessageBox(const QStringList& items)
{

    QMessageBox msgBox;
    msgBox.setWindowTitle("List Contents");
    msgBox.setText("History");

    QListView *listView = new QListView();
    QStringListModel *model = new QStringListModel();
    model->setStringList(items);
    listView->setModel(model);

    listView->setMinimumSize(400, 300);
    listView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    if (QGridLayout* layout = qobject_cast<QGridLayout*>(msgBox.layout())) {
        layout->addWidget(listView, 1, 0, 1, 2);
        layout->setRowStretch(1, 1);
    }

    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setFixedSize(500, 400);
    msgBox.exec();
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(this);

    QAction *showListAction = new QAction("Show List in MessageBox", this);
    showListAction->setData(1);

    QAction *exitAction = new QAction("Quit", this);
    exitAction->setData(2);

    connect(showListAction, &QAction::triggered, this, &MainWindow::handleMenuAction);
    connect(exitAction, &QAction::triggered, this, &MainWindow::handleMenuAction);

    contextMenu.addAction(showListAction);
    contextMenu.addAction(exitAction);

    contextMenu.exec(mapToGlobal(pos));
}

void MainWindow::handleMenuAction()
{
    QAction *action = qobject_cast<QAction*>(sender());
    if (!action) return;

    int actionId = action->data().toInt();

    switch (actionId) {
    case 1:
    {
        QStringList items = readListFromFile();
        if (!items.isEmpty()) {
            showListInMessageBox(items);
        }
        break;
    }
    case 2:
        QApplication::quit();
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_2_clicked()
{
    window = new Dialog(this);
    window->setStringList(history);
    window->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    qlonglong c1;
    c1 = (ui->lineEdit->text()).toLongLong();
    qreal c2;
    c2 = (ui->lineEdit->text()).toDouble();
    qint8 c3;
    c3 = (ui->lineEdit->text()).toInt();
    bool x;
    if(ui->lineEdit->text().contains("."))
    {
        x=0;
    }
    else
    {
        x=1;
    }
    if (c2>=-128 && c2<=127 && x==1)
    {
    QMessageBox::about(this, "", "Size of "+QString::number(c1)+" in qlonglong "+QString::number(sizeof(c1))+" bytes or "+QString::number(sizeof(c1)*8)+" bits"
                        +"\n"+"Size of "+QString::number(c2)+" in qreal "+QString::number(sizeof(c2))+" bytes or "+QString::number(sizeof(c2)*8)+" bits"
                           +"\n"+"Size of "+QString::number(c3)+" in qint8 "+QString::number(sizeof(c3))+" bytes or "+QString::number(sizeof(c3)*8)+" bits"
                           +"\n"+"Can be qlonglong or qreal or qint8");
        history.push_back("Size of "+QString::number(c1)+" in qlonglong "+QString::number(sizeof(c1))+" bytes or "+QString::number(sizeof(c1)*8)+" bits"
                      +"\n"+"Size of "+QString::number(c2)+" in qreal "+QString::number(sizeof(c2))+" bytes or "+QString::number(sizeof(c2)*8)+" bits"
                      +"\n"+"Size of "+QString::number(c3)+" in qint8 "+QString::number(sizeof(c3))+" bytes or "+QString::number(sizeof(c3)*8)+" bits"
                      +"\n"+"Can be qlonglong or qreal or qint8"+"\n");
    }
    if(x==0)
    {
        QMessageBox::about(this, "","Size of "+QString::number(c2)+" in qreal "+QString::number(sizeof(c2))+" bytes or "+QString::number(sizeof(c2)*8)+" bits"
                                         +"\n"+"Can be  qreal ");
        history.push_back("Size of "+QString::number(c2)+" in qreal "+QString::number(sizeof(c2))+" bytes or "+QString::number(sizeof(c2)*8)+" bits"
                          +"\n"+"Can be  qreal "+"\n");
    }
    if(x==1 && (c2<-128 || c2>127))
    {
        QMessageBox::about(this, "", "Size of "+QString::number(c1)+" in qlonglong "+QString::number(sizeof(c1))+" bytes or "+QString::number(sizeof(c1)*8)+" bits"
                                         +"\n"+"Size of "+QString::number(c2)+" in qreal "+QString::number(sizeof(c2))+" bytes or "+QString::number(sizeof(c2)*8)+" bits"
                                         +"\n"+"Can be qlonglong  or qreal");
        history.push_back("Size of "+QString::number(c1)+" in qlonglong "+QString::number(sizeof(c1))+" bytes or "+QString::number(sizeof(c1)*8)+" bits"
                          +"\n"+"Size of "+QString::number(c2)+" in qreal "+QString::number(sizeof(c2))+" bytes or "+QString::number(sizeof(c2)*8)+" bits"
                          +"\n"+"Can be qlonglong  or qreal"+"\n");
    }
}

QList<QString> MainWindow::getStringList() const {
    return history;
}

