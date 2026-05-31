#include "mac_changer.h"
#include "network_utils.h"
#include <boost/algorithm/string.hpp>
#include <random>
#include <sstream>

namespace mac_changer {

bool change_mac_address(const std::string& interface, const std::string& new_mac) {
    if (!network_utils::is_valid_mac(new_mac)) {
        return false;
    }

    std::string cmd = "sudo ifconfig " + interface + " down";
    network_utils::exec_command(cmd);

    cmd = "sudo ifconfig " + interface + " hw ether " + new_mac;
    network_utils::exec_command(cmd);

    cmd = "sudo ifconfig " + interface + " up";
    network_utils::exec_command(cmd);

    return true;
}

std::string generate_random_mac() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    std::ostringstream oss;
    for (int i = 0; i < 6; ++i) {
        oss << std::hex << dis(gen);
        if (i < 5) oss << ":";
    }

    return oss.str();
}

std::vector<std::string> list_network_interfaces() {
    std::string output = network_utils::exec_command("ls /sys/class/net");
    std::vector<std::string> interfaces;
    boost::split(interfaces, output, boost::is_any_of("\n"));

    interfaces.erase(
        std::remove_if(interfaces.begin(), interfaces.end(),
            [](const std::string& s) { return s.empty(); }),
        interfaces.end()
    );

    return interfaces;
}

} // namespace mac_changer