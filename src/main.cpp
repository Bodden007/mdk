#include <iostream>
#include <vector>
#include "includes/detectorSerial.hpp"

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */

int main(int argc, char *argv[])
{
    std::vector<std::string> nameSerialPort;

    detectorSerial detect;
    nameSerialPort = detect.nameSerial();

    if (nameSerialPort.size() > 0)
    {
        std::cout << "main :  " << std::endl;
        for (int i = 0; i < nameSerialPort.size(); i++)
        {
            std::cout << "Detected port: " << nameSerialPort[i] << std::endl;
        }
    }
    else
    {
        // std::cout << "Serial port not detected" << std::endl;
    }

    return 0;
}
