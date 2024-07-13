#ifndef ADDSYSTEMADMIN_H
#define ADDSYSTEMADMIN_H

#include <QDialog>

namespace Ui {
class AddSystemAdmin;
}

class AddSystemAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit AddSystemAdmin(QWidget *parent = nullptr);
    ~AddSystemAdmin();

private:
    Ui::AddSystemAdmin *ui;
};

#endif // ADDSYSTEMADMIN_H
