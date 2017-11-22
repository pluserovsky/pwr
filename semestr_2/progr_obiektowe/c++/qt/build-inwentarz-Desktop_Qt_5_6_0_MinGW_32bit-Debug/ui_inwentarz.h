/********************************************************************************
** Form generated from reading UI file 'inwentarz.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INWENTARZ_H
#define UI_INWENTARZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inwentarz
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_pomieszczenie;
    QSpinBox *spinBox_nrPomieszczenia;
    QLabel *label_komputer;
    QComboBox *comboBox_komputer;
    QLabel *label_ilosc;
    QSpinBox *spinBox_ilosc;
    QPushButton *pushButton_zapisz;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QMenu *menuInwentarz;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *inwentarz)
    {
        if (inwentarz->objectName().isEmpty())
            inwentarz->setObjectName(QStringLiteral("inwentarz"));
        inwentarz->resize(546, 310);
        centralWidget = new QWidget(inwentarz);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 171, 221));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_pomieszczenie = new QLabel(widget);
        label_pomieszczenie->setObjectName(QStringLiteral("label_pomieszczenie"));

        verticalLayout->addWidget(label_pomieszczenie);

        spinBox_nrPomieszczenia = new QSpinBox(widget);
        spinBox_nrPomieszczenia->setObjectName(QStringLiteral("spinBox_nrPomieszczenia"));

        verticalLayout->addWidget(spinBox_nrPomieszczenia);

        label_komputer = new QLabel(widget);
        label_komputer->setObjectName(QStringLiteral("label_komputer"));

        verticalLayout->addWidget(label_komputer);

        comboBox_komputer = new QComboBox(widget);
        comboBox_komputer->setObjectName(QStringLiteral("comboBox_komputer"));
        comboBox_komputer->setMouseTracking(false);
        comboBox_komputer->setEditable(false);

        verticalLayout->addWidget(comboBox_komputer);

        label_ilosc = new QLabel(widget);
        label_ilosc->setObjectName(QStringLiteral("label_ilosc"));

        verticalLayout->addWidget(label_ilosc);

        spinBox_ilosc = new QSpinBox(widget);
        spinBox_ilosc->setObjectName(QStringLiteral("spinBox_ilosc"));

        verticalLayout->addWidget(spinBox_ilosc);

        pushButton_zapisz = new QPushButton(widget);
        pushButton_zapisz->setObjectName(QStringLiteral("pushButton_zapisz"));

        verticalLayout->addWidget(pushButton_zapisz);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(250, 20, 256, 221));
        inwentarz->setCentralWidget(centralWidget);
        label_pomieszczenie->raise();
        label_komputer->raise();
        label_ilosc->raise();
        comboBox_komputer->raise();
        spinBox_nrPomieszczenia->raise();
        spinBox_ilosc->raise();
        pushButton_zapisz->raise();
        textBrowser->raise();
        textBrowser->raise();
        menuBar = new QMenuBar(inwentarz);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 546, 20));
        menuInwentarz = new QMenu(menuBar);
        menuInwentarz->setObjectName(QStringLiteral("menuInwentarz"));
        inwentarz->setMenuBar(menuBar);
        mainToolBar = new QToolBar(inwentarz);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        inwentarz->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(inwentarz);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        inwentarz->setStatusBar(statusBar);

        menuBar->addAction(menuInwentarz->menuAction());

        retranslateUi(inwentarz);

        QMetaObject::connectSlotsByName(inwentarz);
    } // setupUi

    void retranslateUi(QMainWindow *inwentarz)
    {
        inwentarz->setWindowTitle(QApplication::translate("inwentarz", "inwentarz", 0));
        label_pomieszczenie->setText(QApplication::translate("inwentarz", "Pomieszczenie:", 0));
        label_komputer->setText(QApplication::translate("inwentarz", "Komputer:", 0));
        comboBox_komputer->clear();
        comboBox_komputer->insertItems(0, QStringList()
         << QApplication::translate("inwentarz", "stacjonarny", 0)
         << QApplication::translate("inwentarz", "notebook", 0)
        );
        label_ilosc->setText(QApplication::translate("inwentarz", "Ilo\305\233\304\207:", 0));
        pushButton_zapisz->setText(QApplication::translate("inwentarz", "Zapisz", 0));
        menuInwentarz->setTitle(QApplication::translate("inwentarz", "Inwentarz ", 0));
    } // retranslateUi

};

namespace Ui {
    class inwentarz: public Ui_inwentarz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INWENTARZ_H
