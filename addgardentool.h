#ifndef ADDGARDENTOOL_H
#define ADDGARDENTOOL_H

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

private:
    Ui::AddGardenTool *ui;
};

#endif // ADDGARDENTOOL_H
