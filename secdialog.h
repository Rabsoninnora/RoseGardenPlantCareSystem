#ifndef SECDIALOG_H
#define SECDIALOG_H


#include "addgardener.h"
#include "addplant.h"
#include "adminpanel.h"
#include "species.h"
#include "index.h"
#include "viewplants.h"
#include "gardenerdetails.h"
#include "admin.h"

#include <QDialog>


namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private slots:


    void on_ViewSpecies_clicked();

    void on_ViewPlants_clicked();

    void on_AddPlant_clicked();

    void on_AdminPanel_clicked();

    void on_AddGardener_clicked();

    void on_GardenerDetails_clicked();

private:
    Ui::SecDialog *ui;
    //creating objects
    AddGardener *ptrAddGardener;
    AddPlant    *ptrAddPlant;
    Species     *ptrSpecies;
    AdminPanel  *ptrAdminPanel;
    ViewPlants  *ptrViewPlants;

    GardenerDetails  *ptrGardenerDetails;
    Admin      *ptrAdmin;


};

#endif // SECDIALOG_H
