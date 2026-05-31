#include "network_utils.h"
#include <regex>
#include <cstdlib>
#include <array>
#include <memory>
#include <stdexcept>

namespace network_utils {

bool is_valid_mac(const std::string& mac) {
    std::regex mac_regex("^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$");
    return std::regex_match(mac, mac_regex);
}

std::string exec_command(const std::string& cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);

    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}

} // namespace network_utils