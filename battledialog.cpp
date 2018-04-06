#include "battledialog.h"
#include "ui_battledialog.h"
BattleDialog::BattleDialog(Enemy *enemy) :
	ui(new Ui::BattleDialog) {
	ui->setupUi(this);
	ui->label->setText(QString::fromStdString("A menacing " + enemy->getName() + " appears before you. What do you do?"));
	ui->progressBar->setValue(enemy->getCurrentHealthPercentage());
	ui->optionOne->setText("Run");
	ui->optionTwo->setText("Attack");
	ui->optionThree->setText("Hide");
	ui->optionFour->setText("Play Dead");
}

BattleDialog::~BattleDialog() {
    delete ui;
}

void BattleDialog::on_optionOne_clicked() {
    ui->buttonBox->setEnabled(true);
	result = RUN;
}

void BattleDialog::on_optionTwo_clicked() {
    ui->buttonBox->setEnabled(true);
	result = ATTACK;
}

void BattleDialog::on_optionThree_clicked() {
    ui->buttonBox->setEnabled(true);
	result = HIDE;
}

void BattleDialog::on_optionFour_clicked() {
    ui->buttonBox->setEnabled(true);
	result = PLAYDEAD;
}

void BattleDialog::on_buttonBox_accepted() {
	finished(result);
}
