/********************************************************************************
** Form generated from reading UI file 'msgbox.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGBOX_H
#define UI_MSGBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_msgBox
{
public:
    QDialogButtonBox *buttonBox;
    QListView *listView;

    void setupUi(QDialog *msgBox)
    {
        if (msgBox->objectName().isEmpty())
            msgBox->setObjectName("msgBox");
        msgBox->resize(400, 300);
        buttonBox = new QDialogButtonBox(msgBox);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        listView = new QListView(msgBox);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(70, 30, 256, 192));

        retranslateUi(msgBox);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, msgBox, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, msgBox, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(msgBox);
    } // setupUi

    void retranslateUi(QDialog *msgBox)
    {
        msgBox->setWindowTitle(QCoreApplication::translate("msgBox", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class msgBox: public Ui_msgBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGBOX_H
