#ifndef VIEWGARDENTOOLS_H
#define VIEWGARDENTOOLS_H
#include "mydb.h"
#include <QDialog>

namespace Ui {
class ViewGardenTools;
}

class ViewGardenTools : public QDialog
{
    Q_OBJECT

public:
    explicit ViewGardenTools(QWidget *parent = nullptr);
    ~ViewGardenTools();

private:
    Ui::ViewGardenTools *ui;
};

#endif // VIEWGARDENTOOLS_H
