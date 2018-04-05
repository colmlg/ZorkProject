#ifndef BATTLEDIALOG_H
#define BATTLEDIALOG_H

#include <QDialog>
#include "Enemy.h"

namespace Ui {
class BattleDialog;
}

class BattleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BattleDialog(QWidget *parent = 0);
    BattleDialog(Enemy* enemy);
    ~BattleDialog();

private slots:
    void on_optionOne_clicked();

    void on_optionTwo_clicked();

    void on_optionThree_clicked();

    void on_optionFour_clicked();

private:
    Ui::BattleDialog *ui;
};

#endif // BATTLEDIALOG_H
