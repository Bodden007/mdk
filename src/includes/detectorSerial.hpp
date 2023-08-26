#pragma once
#include <iostream>
#include <vector>
#include <boost/asio/serial_port.hpp>

namespace ba = boost::asio;

class detectorSerial
{
private:
    std::vector<std::string> nameSerialPort;
    std::string nameBuf;

public:
    std::string namePort;
    std::vector<std::string> nameSerial();
};
