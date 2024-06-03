#include "addgardener.h"
#include "ui_addgardener.h"

AddGardener::AddGardener(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddGardener)
{
    ui->setupUi(this);
}

AddGardener::~AddGardener()
{
    delete ui;
}

void AddGardener::on_btnSave_clicked()
{
    QString EmployeeID = ui->txtEmployeeID->text();
    QString NationalID = ui->txtNationalID->text();
    QString Name = ui->txtName->text();
    QString MiddleName = ui->txtMiddleName->text();
    QString LastName = ui->txtLastName->text();
    QString JobTitle = ui->txtJobTitle->text();
    QString Description = ui->txtDescription->toPlainText();


//Check if the information can be passed // if I can get the information
    qDebug() << "EmployeeID :"
             <<EmployeeID
             << "NationalID :"
             <<NationalID
             << "Name :"
             <<Name
             << "MiddleName :"
             <<MiddleName
             <<"LastName :"
             <<LastName
             <<"JobTile :"
             <<JobTitle
             <<"Description :"
             <<Description;

    //I am able to get the information, but now it must be saved in the database

}

