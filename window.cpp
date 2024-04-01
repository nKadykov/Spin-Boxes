#include "window.h"
#include <QSpinBox>
#include <QGroupBox>
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
    QSpinBox *integerSpinBox = new QSpinBox;

    QVBoxLayout *spinBoxLayout = new QVBoxLayout;
    spinBoxLayout->addWidget(integerSpinBox);
}
