#include "createcontacts.h"

//Setup settings for items
CreateContacts::CreateContacts()
{

    item1->setSizeHint(QSize(60, 60));
    item1->setBackground(QBrush(Qt::darkCyan));
    item1->setTextAlignment(-100);

    item2->setSizeHint(QSize(60, 60));
    item2->setBackground(QBrush(Qt::darkCyan));
    item2->setTextAlignment(-100);

    item3->setSizeHint(QSize(60, 60));
    item3->setBackground(QBrush(Qt::darkCyan));
    item3->setTextAlignment(-100);

    item4->setSizeHint(QSize(60, 60));
    item4->setBackground(QBrush(Qt::darkCyan));
    item4->setTextAlignment(-100);
}

//Clear memory
CreateContacts::~CreateContacts()
{
    delete item1;
    delete item2;
    delete item3;
    delete item4;
}
