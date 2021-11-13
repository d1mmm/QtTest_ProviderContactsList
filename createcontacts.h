#ifndef CREATECONTACTS_H
#define CREATECONTACTS_H
#include <QListWidget>

//Creating new items
class CreateContacts
{
public:
    QListWidgetItem* item1 = new QListWidgetItem(QIcon(":/rec/img/Cartman_normal_icon_30695.png"),"Kevin Green");
    QListWidgetItem* item2 = new QListWidgetItem(QIcon(":/rec/img/Butters_Mr_Biggles_icon_30664.png"),"Adam Petrik");
    QListWidgetItem* item3 = new QListWidgetItem(QIcon(":/rec/img/Randy_Marsh_Guitar_Hero_Icon_3_30683.png"),"Glen Hughes");
    QListWidgetItem* item4 = new QListWidgetItem(QIcon(":/rec/img/Butters_Marjorine_icon_30702.png"),"Samantha Smith");
     CreateContacts();
    ~CreateContacts();
};

#endif // CREATECONTACTS_H
