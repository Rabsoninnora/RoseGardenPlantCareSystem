#ifndef ADMINPANEL_H
#define ADMINPANEL_H
#include "mydb.h"
#include <QMessageBox>
#include "addgardentool.h"
#include "availableplants.h"
#include "suppliers.h"
#include "addgardener.h"
#include "addplant.h"
#include "gardenerdetails.h"
#include "species.h"
#include "viewplants.h"
#include "plantdetail.h"
#include "adduser.h"


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

   // void on_ViewGardenTools_clicked();



    void on_btn_Add_Admin_clicked();


    void on_btn_Add_Supplier_clicked();

    void on_btn_Employees_clicked();

    void on_btn_employee_view_clicked();

    void on_Admin_panel_close_app_clicked();

    void on_AddPlant_clicked();


    void on_btn_view_plant_dmin_clicked();


    void on_btn_view_Available_Plants_Admin_clicked();

    void on_Admin_panel_close_log_out_clicked();

private:
    //Pointer varables
    Ui::AdminPanel *ui;
    AddGardenTool *ptrAddgardentool;
    //ViewGardenTools *ptrViewGardenTools;
    //AddSystemAdmin *ptrAddSystemAdmin;
    //ViewSystemAdmin *ptrViewSystemAdmin;
    AvailablePlants *ptrAvailablePlants;
    Suppliers        *ptrSuppliers;
    AddGardener *ptrAddGardener;
    GardenerDetails *ptrGardenerDetails;
    AddPlant    *ptrAddPlant;


    ViewPlants  *ptrViewPlants;

    AddUser *ptrAddUser;

};

#endif // ADMINPANEL_H
