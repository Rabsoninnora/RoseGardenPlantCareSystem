#ifndef ADMINPANEL_H
#define ADMINPANEL_H
#include "addsystemadmin.h"
#include "viewgardentools.h"
#include "viewsystemadmin.h"
#include "addgardentool.h"
#include "availableplants.h"

#include <QDialog>

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

private slots:


    void on_AddGardenTool_clicked();

    void on_ViewGardenTools_clicked();

    void on_btn_Available_Plants_clicked();

private:
    Ui::AdminPanel *ui;
    AddGardenTool *ptrAddgardentool;
    ViewGardenTools *ptrViewGardenTools;
    AddSystemAdmin *ptrAddSystemAdmin;
    ViewSystemAdmin *ptrViewSystemAdmin;
    AvailablePlants *ptrAvailablePlants;

};

#endif // ADMINPANEL_H
