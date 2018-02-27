/********************************************************************************
** Form generated from reading UI file 'exchangepage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCHANGEPAGE_H
#define UI_EXCHANGEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExchangePage
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;

    void setupUi(QWidget *ExchangePage)
    {
        if (ExchangePage->objectName().isEmpty())
            ExchangePage->setObjectName(QStringLiteral("ExchangePage"));
        ExchangePage->setWindowModality(Qt::NonModal);
        ExchangePage->resize(713, 477);
        gridLayout = new QGridLayout(ExchangePage);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        frame = new QFrame(ExchangePage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(213, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(ExchangePage);

        QMetaObject::connectSlotsByName(ExchangePage);
    } // setupUi

    void retranslateUi(QWidget *ExchangePage)
    {
        ExchangePage->setWindowTitle(QApplication::translate("ExchangePage", "Digging", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExchangePage: public Ui_ExchangePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCHANGEPAGE_H
