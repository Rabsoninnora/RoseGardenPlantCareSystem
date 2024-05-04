#ifndef SPECIES_H
#define SPECIES_H

#include <QDialog>

namespace Ui {
class Species;
}

class Species : public QDialog
{
    Q_OBJECT

public:
    explicit Species(QWidget *parent = nullptr);
    ~Species();

private:
    Ui::Species *ui;
};

#endif // SPECIES_H
