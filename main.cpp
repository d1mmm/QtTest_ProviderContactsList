#include "contactlistprovider.h"
#include "createcontacts.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CreateContacts* contacts = new CreateContacts;
    ContactListProvider* w = new ContactListProvider(contacts);
    w->show();
    return a.exec();
}
