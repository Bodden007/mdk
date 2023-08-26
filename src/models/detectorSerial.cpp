#include "../includes/detectorSerial.hpp"

std::vector<std::string> detectorSerial::nameSerial()
{

#ifdef WIN32
    namePort = "COM";
#else
    namePort = "/dev/ttyS";
#endif

    ba::io_context io;

    // NOTE Open and close the port
    for (int i = 1; i < 10; i++)
    {
        nameBuf = namePort + std::to_string(i);

        try
        {
            ba::serial_port sPort(io, nameBuf);

            if (sPort.is_open())
            {
                // NOTE Adding name ports in vector nameSerialPort
                nameSerialPort.push_back(nameBuf);
                sPort.close();
            }
        }
        catch (const std::exception &e)
        {
        }
    }

    // TODO Port output in the console
    if (nameSerialPort.size() > 0)
    {
        std::cout << "Serial Port detected" << std::endl;
        for (int i = 0; i < nameSerialPort.size(); i++)
        {
            std::cout << "Detected port: " << nameSerialPort[i] << std::endl;
        }
    }
    else
    {
        std::cout << "Serial port not detected" << std::endl;
    }
    return nameSerialPort;
}