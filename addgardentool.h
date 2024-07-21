#ifndef ADDGARDENTOOL_H
#define ADDGARDENTOOL_H
#include"databaseheader.h"
#include <QDialog>

namespace Ui {
class AddGardenTool;
}

class AddGardenTool : public QDialog
{
    Q_OBJECT

public:
    explicit AddGardenTool(QWidget *parent = nullptr);
    ~AddGardenTool();

private slots:
    void on_btn_View_Record_clicked();

    void on_btn_Delete_Record_clicked();

    void on_btn_Insert_Record_clicked();

    void on_btn_Update_Record_clicked();

private:
    Ui::AddGardenTool *ui;
    QSqlDatabase DB_GardenTools;
};

#endif // ADDGARDENTOOL_H
