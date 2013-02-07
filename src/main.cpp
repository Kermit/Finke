#include "finke.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Finke mainWindow;
    mainWindow.show();
    
    if (mainWindow.init()) {
        return a.exec();
    } else {
        return 1;
    }
}
