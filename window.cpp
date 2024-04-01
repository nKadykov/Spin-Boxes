#include "window.h"
#include <QSpinBox>
#include <QGroupBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QLabel>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    createSpinBoxes();
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBoxesGroup);

    setLayout(layout);
    setWindowTitle(tr("Spin Boxes"));
}

void Window::createSpinBoxes() {
    spinBoxesGroup = new QGroupBox(tr("Spinboxes"));

    QLabel *integerLabel = new QLabel(tr("Enter a value between -20 and 20"));
    QSpinBox *integerSpinBox = new QSpinBox;
    integerSpinBox->setRange(-20, 20);

    QVBoxLayout *spinBoxLayout = new QVBoxLayout;
    spinBoxLayout->addWidget(integerLabel);
    spinBoxLayout->addWidget(integerSpinBox);

    spinBoxesGroup->setLayout(spinBoxLayout);
}
