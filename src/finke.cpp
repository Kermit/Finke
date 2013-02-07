#include "finke.h"
#include "ui_finke.h"

class QSqlError;

Finke::Finke(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Finke), database(new Database())
{
    ui->setupUi(this);
}

Finke::~Finke()
{
    delete ui;
}

bool Finke::init()
{
    setStatus(tr("Sprawdzam konfigurację ..."));
    if (!Configuration::checkConfiguration()) {
        if (!Configuration::createConfiguration()) {
            QMessageBox::critical(this, tr("Finke - błąd krytyczny"), tr("Błąd podczas tworzenia katalogu domowego"));
            return false;
        }
    }

    setStatus(tr("Sprawdzam bazę danych ..."));
    if (!database.checkDatabase()) {
        if (!database.createDatabase()) {
            QMessageBox::critical(this, tr("Finke - błąd krytyczny"), tr("Błąd podczas tworzenia bazy danych"));
            return false;
        }
    }

    setStatus(tr("Otwieram bazę danych..."));
    if (!database.openDatabaseConnection()) {
        QMessageBox::critical(NULL, tr("Finke - błąd krytyczny"),
                              tr("Nie można otworzyć bazy danych. Program zostanie zakońćzony.\n")
                              + database.getLastError(),
                              QMessageBox::Ok, QMessageBox::No);
        return false;
    }

    setStatus(tr("Finke 0.1 Alpha"));
    return true;
}

void Finke::setStatus(QString status, int timeout) {
    ui->statusBar->showMessage(status, timeout);
}
