#ifndef ADDPLANT_H
#define ADDPLANT_H

#include <QDialog>

namespace Ui {
class AddPlant;
}

class AddPlant : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlant(QWidget *parent = nullptr);
    ~AddPlant();

private slots:
    void on_btnBrowse_clicked();

private:
    Ui::AddPlant *ui;
};

#endif // ADDPLANT_H
