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

void Suppliers::on_btn_View_Supplier_clicked()
{

    dbSupplier.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryReadData(dbSupplier);
    QueryReadData.prepare("SELECT * FROM Supplier");



    int NumberOFRowsToDisplay=1000;

    if(QueryReadData.exec())
    {
        ui->tableWidget->setRowCount(NumberOFRowsToDisplay);
        int RowNumber =0;
        while (QueryReadData.next()) {


            ui->tableWidget->setItem( RowNumber, 0, new QTableWidgetItem(QString(QueryReadData.value("SupplierID").toString())));
            ui->tableWidget->setItem( RowNumber, 1, new QTableWidgetItem(QString(QueryReadData.value("Legal_Name").toString())));
            ui->tableWidget->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryReadData.value("Pacra_reg").toString())));
            ui->tableWidget->setItem( RowNumber, 3, new QTableWidgetItem(QString(QueryReadData.value("Tpin").toString())));
            ui->tableWidget->setItem( RowNumber, 4, new QTableWidgetItem(QString(QueryReadData.value("Description").toString())));

            RowNumber = RowNumber +1;

        }

    }

    QSqlDatabase::database().commit();
    dbSupplier.close();
}


void Suppliers::on_btn_Insert_Supplier_clicked()
{

    dbSupplier.open();
    QSqlDatabase::database().transaction();
    QSqlQuery InsertRecord(dbSupplier);
    InsertRecord.prepare( "INSERT INTO Supplier(SupplierID,Legal_Name,Pacra_reg,Tpin,Product,Phone,Address,B_Acc) VALUES(:SupplierID,:Legal_Name,:Pacra_reg,:Tpin,:Product,:Phone,:Address,:B_Acc) ");
    InsertRecord.bindValue(":SupplierID", ui->lineEdit_SupplierID->text());
    InsertRecord.bindValue(":Legal_Name",ui->lineEdit_Supplier_Legal_Name->text());
    InsertRecord.bindValue(":Pacra_reg",ui->lineEdit_Supplier_Pacra_Reg->text());
    InsertRecord.bindValue(":Tpin",ui->lineEdit_Supplier_Tpin->text());
    InsertRecord.bindValue(":Product",ui->lineEdit_Supplier_Product_Service->text());
    InsertRecord.bindValue(":Phone",ui->lineEdit_Supplier_Phone->text());
    InsertRecord.bindValue(":Address",ui->lineEdit_Supplier_Business_Address->text());
    InsertRecord.bindValue(":B_Acc",ui->lineEdit_Supplier_B_Acc->text());
    InsertRecord.exec();
    QSqlDatabase::database().commit();
    dbSupplier.close();
   // qDebug() <<"     "<<InsertRecord.lastError().text();

    qDebug() <<"Query Last Error on this --> "<<InsertRecord.lastError().text();

    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()){widget->clear();}



}


void Suppliers::on_btn_Update_Supplier_clicked()
{

}


void Suppliers::on_btn_Delete_Supplier_clicked()
{

}

