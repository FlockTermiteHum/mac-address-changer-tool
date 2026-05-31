#ifndef MAC_CHANGER_H
#define MAC_CHANGER_H

#include <string>
#include <vector>

namespace mac_changer {

bool change_mac_address(const std::string& interface, const std::string& new_mac);
std::string generate_random_mac();
std::vector<std::string> list_network_interfaces();

} // namespace mac_changer

#endif // MAC_CHANGER_H