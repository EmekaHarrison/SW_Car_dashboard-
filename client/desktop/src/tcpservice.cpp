#include "setting.h"
#include "tcpservice.h"
#include <QDebug>

void TCPService::run(void)
{
    sockaddr_in server_address{0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(Setting::TCP::PORT);
    server_address.sin_addr.s_addr = inet_addr(Setting::TCP::IP);
    while (!end)
    {

        socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd != -1)
        {
            if (0 == connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)))
            {
                status = true;
                while (!end)
                {
                    uint8_t temp[sizeof(buffer)]{0};
                    if (sizeof(temp) == read(socket_fd, temp, sizeof(temp)))
                    {
                        std::scoped_lock<std::mutex> lock(mtx);
                        memcpy(buffer, temp, sizeof(buffer));
                    }
                    else
                    {
                        status = false;
                        close(socket_fd);
                        break;
                    }
                }
            }
        }
    }
}
