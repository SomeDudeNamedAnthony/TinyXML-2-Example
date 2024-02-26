#ifndef TX2E_ASKME
#define TX2E_ASKME

#include <iostream>
#include <string>

inline bool ask_question() {
    std::cout << "[y/n]" << '\n';
    std::string yn = "";
    std::cin >> yn;
    if (yn[0] == 'y' || yn[0] == 'Y') {
        return true;
    }
    return false;
}

#endif // TX2E_ASKME