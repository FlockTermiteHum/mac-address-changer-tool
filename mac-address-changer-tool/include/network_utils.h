#ifndef NETWORK_UTILS_H
#define NETWORK_UTILS_H

#include <string>

namespace network_utils {

bool is_valid_mac(const std::string& mac);
std::string exec_command(const std::string& cmd);

} // namespace network_utils

#endif // NETWORK_UTILS_H