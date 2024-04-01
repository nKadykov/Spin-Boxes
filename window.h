#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QSpinBox;
class QGroupBox;
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

private:
    void createSpinBoxes();
    QGroupBox *spinBoxesGroup;
    QSpinBox *groupSeparatorSpinBox;
};
#endif // WINDOW_H
