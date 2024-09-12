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

    db.open();
    QSqlDatabase::database().transaction();

    QSqlQuery QueryLoadData(db);
    QueryLoadData.prepare("SELECT * FROM Supplier");



    int NumberOFRowsToDisplay=100;

    if(QueryLoadData.exec())
    {
        ui->tableWidget->setRowCount(NumberOFRowsToDisplay);
        int RowNumber =0;
        while (QueryLoadData.next()) {


            ui->tableWidget->setItem( RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("SupplierID").toString())));
            ui->tableWidget->setItem( RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("Legal_Name").toString())));
            ui->tableWidget->setItem( RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("Pacra_reg").toString())));
            ui->tableWidget->setItem( RowNumber, 3, new QTableWidgetItem(QString(QueryLoadData.value("Tpin").toString())));
            ui->tableWidget->setItem( RowNumber, 4, new QTableWidgetItem(QString(QueryLoadData.value("Product").toString())));
            ui->tableWidget->setItem( RowNumber, 5, new QTableWidgetItem(QString(QueryLoadData.value("Phone").toString())));
            ui->tableWidget->setItem( RowNumber, 6, new QTableWidgetItem(QString(QueryLoadData.value("Address").toString())));
            ui->tableWidget->setItem( RowNumber, 7, new QTableWidgetItem(QString(QueryLoadData.value("B_Acc").toString())));

            RowNumber = RowNumber +1;

        }

    }

    QSqlDatabase::database().commit();
    db.close();
}


void Suppliers::on_btn_Insert_Supplier_clicked()
{

    db.open();
    QSqlDatabase::database().transaction();
    QSqlQuery InsertRecord(db);
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
    db.close();
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

