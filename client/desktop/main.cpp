#include "window.h"
#include "tcpservice.h"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    TCPService service;
    Window myWindow(&service);

    myWindow.show();

    return app.exec();
}
