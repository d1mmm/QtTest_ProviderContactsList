#include "favorites.h"
#include "ui_favorites.h"
#include <QMessageBox>

//Constcuctor with parametrs
Favorites::Favorites(QListWidgetItem* item, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Favorites)
{
    ui->setupUi(this);
    ui->gridLayout->setContentsMargins(0,0,0,0);

    //Adding favorites contacts to List Widget from Contact List Provider
    ui->favoritesListWidget->addItem(item);
}

//Default constructor
Favorites::Favorites(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Favorites)
{
    ui->setupUi(this);
    ui->gridLayout->setContentsMargins(0,0,0,0);
}

Favorites::~Favorites()
{
    delete ui;
}

// Calling to somefavotites
void Favorites::on_favoritesListWidget_itemDoubleClicked()
{
    ui->lineEdit->setText("Calling");
    QMessageBox::information(this, "Calling", "Calling...");
    ui->lineEdit->clear();
}

