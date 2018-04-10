#ifndef BATTLEDIALOG_H
#define BATTLEDIALOG_H

#include <QDialog>
#include "enemy.h"

#define RUN 2
#define ATTACK 3
#define HIDE 4
#define PLAYDEAD 5


namespace Ui {
class BattleDialog;
}

class BattleDialog : public QDialog
{
    Q_OBJECT

public:
    BattleDialog(Enemy* enemy);
    ~BattleDialog();
	int result = 0;

private slots:
    void on_optionOne_clicked();

    void on_optionTwo_clicked();

    void on_optionThree_clicked();

    void on_optionFour_clicked();

	void on_buttonBox_accepted();

private:
    Ui::BattleDialog *ui;
};

#endif // BATTLEDIALOG_H
