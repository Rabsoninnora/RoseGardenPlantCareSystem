#ifndef MAINWINDOWPLANTCARE_H
#define MAINWINDOWPLANTCARE_H
#include <QMainWindow>
#include "secdialog.h"




QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowPlantCare;
}
QT_END_NAMESPACE


class MainWindowPlantCare : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowPlantCare(QWidget *parent = nullptr);
    ~MainWindowPlantCare();

private slots:
    void on_pushButton_login_clicked();


private:
    Ui::MainWindowPlantCare *ui;

    //creating an object for SecDialog

    SecDialog *secDialog;

};


#endif // MAINWINDOWPLANTCARE_H
