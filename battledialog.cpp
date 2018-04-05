#include "battledialog.h"
#include "ui_battledialog.h"

BattleDialog::BattleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BattleDialog) {
    ui->setupUi(this);
}

BattleDialog::BattleDialog(Enemy *enemy) {
    ui->optionOne->setText("");
}

BattleDialog::~BattleDialog() {
    delete ui;
}

void BattleDialog::on_optionOne_clicked() {
    ui->buttonBox->setEnabled(true);
}

void BattleDialog::on_optionTwo_clicked() {
    ui->buttonBox->setEnabled(true);
}

void BattleDialog::on_optionThree_clicked() {
    ui->buttonBox->setEnabled(true);
}

void BattleDialog::on_optionFour_clicked() {
    ui->buttonBox->setEnabled(true);
}
