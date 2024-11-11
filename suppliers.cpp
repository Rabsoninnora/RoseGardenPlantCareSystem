#include "suppliers.h"
#include "ui_suppliers.h"


Suppliers::Suppliers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Suppliers)
{
    ui->setupUi(this);


}

Suppliers::~Suppliers()
{
    delete ui;
}

void Suppliers::on_btn_View_Supplier_clicked() {
    QSqlQuery QueryReadData( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    QueryReadData.prepare("SELECT * FROM Contacts");
    int NumberOFRowsToDisplay=1000;

    if(QueryReadData.exec())
    {
        ui->tableWidget->setRowCount(NumberOFRowsToDisplay);
        int RowNumber =0;
        while (QueryReadData.next()) {

            ui->tableWidget->setItem( RowNumber, 0, new QTableWidgetItem(QString(QueryReadData.value("Contact_ID").toString())));
            ui->tableWidget->setItem( RowNumber, 1, new QTableWidgetItem(QString(QueryReadData.value("Business_Name").toString())));
            ui->tableWidget->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryReadData.value("Phone").toString())));
            ui->tableWidget->setItem( RowNumber, 3, new QTableWidgetItem(QString(QueryReadData.value("Product").toString())));
            ui->tableWidget->setItem( RowNumber, 4, new QTableWidgetItem(QString(QueryReadData.value("Business_Addr").toString())));
            ui->tableWidget->setItem( RowNumber, 5, new QTableWidgetItem(QString(QueryReadData.value("Email_addr").toString())));
            RowNumber = RowNumber +1;

        }

    }

    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();

}


void Suppliers::on_btn_Insert_Supplier_clicked()
{
    QSqlQuery InsertRecord( MyDB::getInstance()->getDBInstance());
    QSqlDatabase::database().transaction();
    InsertRecord.prepare( "INSERT INTO Contacts(Contact_ID,Business_Name,Phone,Product,Business_Addr,Email_addr) VALUES(:Contact_ID,:Business_Name,:Phone,:Product,:Business_Addr,:Email_addr) ");
    InsertRecord.bindValue(":Contact_ID", ui->lineEdit_SupplierID->text());
    InsertRecord.bindValue(":Business_Name",ui->lineEdit_Supplier_Legal_Name->text());
    InsertRecord.bindValue(":Phone",ui->lineEdit_Phone->text());
    InsertRecord.bindValue(":Product",ui->lineEdit_Product->text());
    InsertRecord.bindValue(":Business_Addr",ui->lineEdit_address->text());
    InsertRecord.bindValue(":Email_addr",ui->lineEdit_email->text());
    InsertRecord.exec();
    QSqlDatabase::database().commit();
    QSqlDatabase::database().close();

    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();}

}


void Suppliers::on_btn_Update_Supplier_clicked()
{

}


void Suppliers::on_btn_Delete_Supplier_clicked()
{

}


