#ifndef CONTACTLISTPROVIDER_H
#define CONTACTLISTPROVIDER_H

#include <QMainWindow>
#include <createcontacts.h>

QT_BEGIN_NAMESPACE
namespace Ui { class ContactListProvider; }
QT_END_NAMESPACE

class ContactListProvider : public QMainWindow, CreateContacts
{
    Q_OBJECT

public:
    ContactListProvider(CreateContacts *contacts, QWidget *parent = nullptr);
    ~ContactListProvider();
private slots:
    void on_Grid_clicked(); // Button for different styles
    void on_Favorites_clicked(); // Button to favorites contacts
    void on_listWidget_itemDoubleClicked(); // Calling to somebody
    void on_listWidget_itemClicked(QListWidget* wid); // Contact selection
    void on_lineEdit_textChanged(const QString &arg1); // Searching
private:
    Ui::ContactListProvider *ui;
};
#endif // CONTACTLISTPROVIDER_H
