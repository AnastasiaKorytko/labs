#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include <QMainWindow>
#include <QListView>
#include <QStringListModel>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
     QList<QString> getStringList() const;
    ~MainWindow();

private slots:
    void showContextMenu(const QPoint &pos);
    void handleMenuAction();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *window;
    QList<QString>history;
    QStringList readListFromFile();
    void showListInMessageBox(const QStringList& items);

};

#endif // MAINWINDOW_H
