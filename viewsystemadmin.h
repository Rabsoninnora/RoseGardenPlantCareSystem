#ifndef VIEWSYSTEMADMIN_H
#define VIEWSYSTEMADMIN_H

#include <QDialog>

namespace Ui {
class ViewSystemAdmin;
}

class ViewSystemAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit ViewSystemAdmin(QWidget *parent = nullptr);
    ~ViewSystemAdmin();

private:
    Ui::ViewSystemAdmin *ui;
};

#endif // VIEWSYSTEMADMIN_H
