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
    for(int i = 0; i < ui->listWidget->count(); ++i){
        wid->addItem(item[i].clone());
        break;
    }
}

// Addin favorites contacts to form and starting Favorites form // only one!!!!
void ContactListProvider::on_Favorites_clicked()
{
    QListWidgetItem *item = new QListWidgetItem;
    QListWidget* wid = new QListWidget;

    on_listWidget_itemClicked(wid);

    for(int i = 0; i < wid->count(); ++i){
        item[i] = wid->item(i)[i];
    }

    Favorites* favorites = new Favorites(item->clone());
    favorites->setModal(true);
    favorites->exec();

    delete item;
    delete wid;
    delete favorites;
}

//Show different styles
void ContactListProvider::on_Grid_clicked()
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
    QMessageBox::information(this, "Calling", "Calling...");
}

//Searching
void ContactListProvider::on_lineEdit_textChanged(const QString& arg1)
{
    QList<QListWidgetItem*> all = ui->listWidget->findItems("", Qt::MatchContains | Qt::MatchRecursive);
    foreach(QListWidgetItem* item, all)
        item->setHidden(true);

    QList<QListWidgetItem*> items = ui->listWidget->findItems(arg1, Qt::MatchContains | Qt::MatchRecursive);
    foreach(QListWidgetItem* item, items)
        item->setHidden(false);
}


