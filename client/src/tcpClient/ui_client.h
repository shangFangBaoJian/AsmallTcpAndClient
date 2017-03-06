/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QLabel *label2;
    QLineEdit *hostLineEdit;
    QLabel *lablel;
    QLineEdit *portLineEdit;
    QLabel *messageLabel;
    QPushButton *connectButton;

    void setupUi(QDialog *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(400, 300);
        label2 = new QLabel(Client);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(40, 60, 41, 18));
        hostLineEdit = new QLineEdit(Client);
        hostLineEdit->setObjectName(QStringLiteral("hostLineEdit"));
        hostLineEdit->setGeometry(QRect(90, 60, 113, 21));
        lablel = new QLabel(Client);
        lablel->setObjectName(QStringLiteral("lablel"));
        lablel->setGeometry(QRect(40, 110, 55, 18));
        portLineEdit = new QLineEdit(Client);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        portLineEdit->setGeometry(QRect(90, 110, 113, 26));
        messageLabel = new QLabel(Client);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        messageLabel->setGeometry(QRect(40, 180, 121, 18));
        connectButton = new QPushButton(Client);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(250, 220, 80, 26));

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QDialog *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", 0));
        label2->setText(QApplication::translate("Client", "\344\270\273\346\234\272\357\274\232", 0));
        lablel->setText(QApplication::translate("Client", "\347\253\257\345\217\243\357\274\232", 0));
        messageLabel->setText(QApplication::translate("Client", "\346\216\245\346\224\266\345\210\260\347\232\204\344\277\241\346\201\257\343\200\202\343\200\202\343\200\202", 0));
        connectButton->setText(QApplication::translate("Client", "\350\277\236\346\216\245", 0));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
