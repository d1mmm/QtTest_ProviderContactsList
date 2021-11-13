#ifndef FAVORITES_H
#define FAVORITES_H
#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class Favorites;
}

class Favorites : public QDialog
{
    Q_OBJECT

public:
    explicit Favorites(QListWidgetItem* item, QWidget *parent = nullptr);
    explicit Favorites(QWidget *parent = nullptr);
    ~Favorites();

private slots:
    void on_favoritesListWidget_itemDoubleClicked(); // Calling to favorite contact

private:
    Ui::Favorites *ui;
};

#endif // FAVORITES_H
