#ifndef INDEX_H
#define INDEX_H

#include <QDialog>

namespace Ui {
class index;
}

class index : public QDialog
{
    Q_OBJECT

public:
    explicit index(QWidget *parent = nullptr);
    ~index();

private:
    Ui::index *ui;
};

#endif // INDEX_H
