#include "dialog.h"
#include <QApplication>
#include "tcpservices.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    TCPServices services;
    Dialog dialog(&services);
    dialog.show();

    return app.exec();
}
