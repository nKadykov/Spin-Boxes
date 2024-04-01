#include "window.h"
#include <QSpinBox>
#include <QGroupBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QDateEdit>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    createSpinBoxes();
    createDateTimeEdit();
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBoxesGroup);
    layout->addWidget(editsGroup);

    setLayout(layout);
    setWindowTitle(tr("Spin Boxes"));
}

void Window::createSpinBoxes() {
    spinBoxesGroup = new QGroupBox(tr("Spinboxes"));

    QLabel *integerLabel = new QLabel(tr("Enter a value between -20 and 20"));
    QSpinBox *integerSpinBox = new QSpinBox;
    integerSpinBox->setRange(-20, 20);
    integerSpinBox->setSingleStep(1);
    integerSpinBox->setValue(0);

    QLabel *zoomLabel = new QLabel(tr("Enter a zoom value between 0 and 1000"));
    QSpinBox *zoomSpinBox = new QSpinBox;
    zoomSpinBox->setRange(0, 1000);
    zoomSpinBox->setSingleStep(10);
    zoomSpinBox->setSuffix("%");
    zoomSpinBox->setSpecialValueText(tr("Automatic"));
    zoomSpinBox->setValue(100);

    QLabel *priceLabel = new QLabel(tr("Enter a price between 0 and 999"));
    QSpinBox *priceSpinBox = new QSpinBox;
    priceSpinBox->setRange(0, 999);
    priceSpinBox->setSingleStep(1);
    priceSpinBox->setPrefix("$");
    priceSpinBox->setValue(99);

    groupSeparatorSpinBox = new QSpinBox;
    groupSeparatorSpinBox->setRange(-99999999, 99999999);
    groupSeparatorSpinBox->setValue(1000);
    groupSeparatorSpinBox->setGroupSeparatorShown(true);
    QCheckBox *groupSeparatorCheckBox = new QCheckBox;
    groupSeparatorCheckBox->setText(tr("Show group separator"));
    groupSeparatorCheckBox->setChecked(true);
    connect(groupSeparatorCheckBox, &QCheckBox::clicked, groupSeparatorSpinBox, &QSpinBox::setGroupSeparatorShown);

    QVBoxLayout *spinBoxLayout = new QVBoxLayout;
    spinBoxLayout->addWidget(integerLabel);
    spinBoxLayout->addWidget(integerSpinBox);
    spinBoxLayout->addWidget(zoomLabel);
    spinBoxLayout->addWidget(zoomSpinBox);
    spinBoxLayout->addWidget(priceLabel);
    spinBoxLayout->addWidget(priceSpinBox);
    spinBoxLayout->addWidget(groupSeparatorCheckBox);
    spinBoxLayout->addWidget(groupSeparatorSpinBox);

    spinBoxesGroup->setLayout(spinBoxLayout);
}

void Window::createDateTimeEdit() {
    editsGroup = new QGroupBox(tr("Date boxes"));

    QLabel *dateLabel = new QLabel;
    QDateEdit *dateEdit = new QDateEdit(QDate::currentDate());
    dateEdit->setDateRange(QDate(2005, 1, 1), QDate(2010, 12, 31));

    QVBoxLayout *dateLayout = new QVBoxLayout;
    dateLayout->addWidget(dateLabel);
    dateLayout->addWidget(dateEdit);

    editsGroup->setLayout(dateLayout);
}
