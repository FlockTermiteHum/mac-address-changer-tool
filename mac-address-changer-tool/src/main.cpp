#include <iostream>
#include "mac_changer.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <interface> <new_mac|random>\n";
        return 1;
    }

    std::string interface = argv[1];
    std::string new_mac = argv[2];

    if (new_mac == "random") {
        new_mac = mac_changer::generate_random_mac();
    }

    if (!mac_changer::change_mac_address(interface, new_mac)) {
        std::cerr << "Failed to change MAC address\n";
        return 1;
    }

    std::cout << "MAC address changed successfully to: " << new_mac << "\n";
    return 0;
}