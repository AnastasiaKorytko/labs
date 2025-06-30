#ifndef MSGBOX_H
#define MSGBOX_H

#include <QDialog>

namespace Ui {
class msgBox;
}

class msgBox : public QDialog
{
    Q_OBJECT

public:
    explicit msgBox(QWidget *parent = nullptr);
    ~msgBox();

private slots:
    void on_listView_indexesMoved(const QModelIndexList &indexes);

private:
    Ui::msgBox *ui;
};

#endif // MSGBOX_H
