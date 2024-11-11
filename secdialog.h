#ifndef SECDIALOG_H
#define SECDIALOG_H
#include <QMessageBox>
#include "mydb.h"
#include "addplant.h"
#include "species.h"
#include "viewplants.h"
#include "plantdetail.h"

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









    void on_btn_logout_clicked();

    void on_btn_Plant_Detail_clicked();

private:
    Ui::SecDialog *ui;
    //creating objects

    Species     *ptrSpecies;
    ViewPlants  *ptrViewPlants;
    PlantDetail * ptrPlantDetail;





};

#endif // SECDIALOG_H
