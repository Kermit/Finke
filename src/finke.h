#ifndef FINKE_H
#define FINKE_H

#include "configuration.h"
#include "model/database.h"

#include <QMainWindow>
#include <QtGui/QMessageBox>

namespace Ui {
class Finke;
}

class Finke : public QMainWindow
{
    Q_OBJECT
    
private:
    Ui::Finke *ui;
    Database database;
    void setStatus(QString status, int timeout = 0);

public:
    explicit Finke(QWidget *parent = 0);
    ~Finke();
    bool init();
};

#endif // FINKE_H
