#pragma once

// ---------------------------------------------------
// all common functions/constants for this project
// ---------------------------------------------------

#include <string>
#include <vector>
#include <exception>

// if win-socket functions fail that shouldn't ever fail (like init winsockets...)
class WsaException : public std::runtime_error {
public:
    WsaException(std::string const& msg)
        : std::runtime_error(msg + " : " + std::to_string(WSAGetLastError()))
    {}
};



#define forever for (;;)


const std::string LocalServer = "127.0.0.1";
const int DefaultPort = 54000;

inline std::ostream& operator << (std::ostream& os, std::vector<char> vec)
{
    for (auto c : vec) {
        os << c;
    }
    return os;
}