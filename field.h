#ifndef FIELD_H
#define FIELD_H

#include <QWidget>

namespace Ui {
class Field;
}

class Field : public QWidget
{
    Q_OBJECT

public:
    explicit Field(QWidget *parent = nullptr);
    ~Field();

private:
    Ui::Field *ui;
};

#endif // FIELD_H
