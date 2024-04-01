#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QSpinBox;
class QGroupBox;
class QDateTimeEdit;
class QLabel;
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

private:
    void createSpinBoxes();
    void createDateTimeEdit();

    QGroupBox *spinBoxesGroup;
    QGroupBox *editsGroup;
    QSpinBox *groupSeparatorSpinBox;
    QDateTimeEdit *meetingEdit;
    QLabel *meetingLabel;
};
#endif // WINDOW_H
