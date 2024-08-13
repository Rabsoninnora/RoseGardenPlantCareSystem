#include "addgardener.h"
#include "ui_addgardener.h"
#include <QFileDialog> //For file opening
#include <QMessageBox> //pop up messages alerts infos and warning
#include <QPixmap> //
#include <QImage>  // Load Image
#include <QVector> // for arrays in the system code
#include <QQueue> // Queue data structures
#include <QPixmap>
#include <QLabel>
#include<QLineEdit>


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
    //pass data to be acceseable for posting to the database
    QString Employee_id = ui->txtEmployeeID->text();
    QString National_id = ui->txtNationalID->text();
    QString Name = ui->txtName->text();
    QString Middle_name = ui->txtMiddleName->text();
    QString Last_name = ui->txtLastName->text();
    QString Job_title = ui->txtJobTitle->text();
    QString Description = ui->txtDescription->toPlainText();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





// Posting data in the database, the addgardener table/relation
    db.open();
    QSqlDatabase::database().transaction();
    QSqlQuery postGardener(db);
    postGardener.prepare("insert into addgardener(Employee_id, National_id, Name, Middle_name, Last_name, Job_title, Description) values('"+ Employee_id +"', '"+ National_id +"', '"+ Name +"','"+ Middle_name +"','"+ Last_name +"','"+ Job_title +"', '"+ Description +"')");
    postGardener.exec();
    qDebug() <<" Last error : "<< postGardener.lastError().text();

    QSqlDatabase::database().commit();
    db.close();
    qDebug() << "Databse closed  successfuly, Happy coding !";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Clear the form fields

    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){
        widget->clear();
    }


    foreach(QPlainTextEdit *widget, this->findChildren<QPlainTextEdit*>()){widget->clear();}


}



void AddGardener::on_btnBrowse_2_clicked()
{

}



void AddGardener::on_btn_home2_clicked()
{
    QMessageBox::warning(this, "Warning!", "Leaving to Home!");



}


void AddGardener::on_btnReset_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){
             widget->clear();
    }

    foreach(QPlainTextEdit *widget, this->findChildren<QPlainTextEdit*>()){
        widget->clear();
    }
}

