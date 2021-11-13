#include "contactlistprovider.h"
#include "ui_contactlistprovider.h"
#include <favorites.h>
#include <QMessageBox>

ContactListProvider::ContactListProvider(CreateContacts* contacts, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ContactListProvider)
{
    ui->setupUi(this);
    ui->verticalLayout->setContentsMargins(0,0,0,0);
    ui->lineEdit->setContentsMargins(0,0,0,0);
    ui->listWidget->setSpacing(5);

    //Adding new contacts to ListWidget
    ui->listWidget->addItem(contacts->item1);
    ui->listWidget->addItem(contacts->item2);
    ui->listWidget->addItem(contacts->item3);
    ui->listWidget->addItem(contacts->item4);
    ui->listWidget->addItem(contacts->item1->clone());
    ui->listWidget->addItem(contacts->item1->clone());
    ui->listWidget->addItem(contacts->item4->clone());
    ui->listWidget->addItem(contacts->item3->clone());
    ui->listWidget->addItem(contacts->item4->clone());
    ui->listWidget->addItem(contacts->item2->clone());
}

ContactListProvider::~ContactListProvider()
{
    delete ui;
}

//Сreating additional widget for chosen contacts
void ContactListProvider::on_listWidget_itemClicked(QListWidget *wid)
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    wid->addItem(item->clone());
}

// Addin favorites contacts to form and starting Favorites form
void ContactListProvider::on_Favorites_clicked()
{
    QListWidgetItem *item;
    QListWidget* wid = new QListWidget;
    on_listWidget_itemClicked(wid);

    item = wid->item(0);

    Favorites* favorites = new Favorites(item->clone());
    favorites->setModal(true);
    favorites->exec();
    delete wid;
    delete favorites;
}

//Show different styles
void ContactListProvider::on_Grid_clicked() const
{
    if(ui->listWidget->viewMode() == QListView::ListMode){
        ui->listWidget->setFlow(QListView::LeftToRight);
        ui->listWidget->setResizeMode(QListView::Fixed);
        ui->listWidget->setGridSize(QSize(100, 100));
        ui->listWidget->setViewMode(QListView::IconMode);
    }
    else if(ui->listWidget->viewMode() == QListView::IconMode){
        ui->listWidget->setFlow(QListView::TopToBottom);
        ui->listWidget->setResizeMode(QListView::Fixed);
        ui->listWidget->setGridSize(QSize(70, 70));
        ui->listWidget->setViewMode(QListView::ListMode);
    }
}

// Calling to somebody
void ContactListProvider::on_listWidget_itemDoubleClicked()
{
    ui->statusbar->showMessage("Calling");
    QMessageBox::information(this, "Calling", "Calling...");
    ui->statusbar->clearMessage();
}

//Searching
void ContactListProvider::on_lineEdit_textChanged(const QString& arg1) const
{
    QList<QListWidgetItem*> all = ui->listWidget->findItems("", Qt::MatchContains | Qt::MatchRecursive);
    foreach(QListWidgetItem* item, all)
        item->setHidden(true);

    QList<QListWidgetItem*> items = ui->listWidget->findItems(arg1, Qt::MatchContains | Qt::MatchRecursive);
    foreach(QListWidgetItem* item, items)
        item->setHidden(false);
}


