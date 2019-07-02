/********************************************************************************
** Form generated from reading UI file 'new_imagen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_IMAGEN_H
#define UI_NEW_IMAGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_New_imagen
{
public:
    QPushButton *Add_new;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *input_name;
    QLineEdit *input_path;
    QLineEdit *input_label;

    void setupUi(QWidget *New_imagen)
    {
        if (New_imagen->objectName().isEmpty())
            New_imagen->setObjectName(QString::fromUtf8("New_imagen"));
        New_imagen->resize(711, 389);
        Add_new = new QPushButton(New_imagen);
        Add_new->setObjectName(QString::fromUtf8("Add_new"));
        Add_new->setGeometry(QRect(310, 290, 93, 28));
        label = new QLabel(New_imagen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 100, 81, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(New_imagen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 150, 81, 31));
        label_2->setFont(font);
        label_3 = new QLabel(New_imagen);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 210, 81, 21));
        label_3->setFont(font);
        input_name = new QLineEdit(New_imagen);
        input_name->setObjectName(QString::fromUtf8("input_name"));
        input_name->setGeometry(QRect(350, 100, 113, 22));
        input_path = new QLineEdit(New_imagen);
        input_path->setObjectName(QString::fromUtf8("input_path"));
        input_path->setGeometry(QRect(350, 150, 113, 22));
        input_label = new QLineEdit(New_imagen);
        input_label->setObjectName(QString::fromUtf8("input_label"));
        input_label->setGeometry(QRect(350, 210, 113, 22));

        retranslateUi(New_imagen);

        QMetaObject::connectSlotsByName(New_imagen);
    } // setupUi

    void retranslateUi(QWidget *New_imagen)
    {
        New_imagen->setWindowTitle(QApplication::translate("New_imagen", "Form", nullptr));
        Add_new->setText(QApplication::translate("New_imagen", "Add", nullptr));
        label->setText(QApplication::translate("New_imagen", "Name :", nullptr));
        label_2->setText(QApplication::translate("New_imagen", "Path : ", nullptr));
        label_3->setText(QApplication::translate("New_imagen", "Label :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class New_imagen: public Ui_New_imagen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_IMAGEN_H
