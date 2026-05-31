#include <gtest/gtest.h>
#include "mac_changer.h"
#include "network_utils.h"

TEST(MacChangerTest, ValidMacAddress) {
    EXPECT_TRUE(network_utils::is_valid_mac("00:1A:2B:3C:4D:5E"));
    EXPECT_TRUE(network_utils::is_valid_mac("00-1A-2B-3C-4D-5E"));
    EXPECT_FALSE(network_utils::is_valid_mac("00:1A:2B:3C:4D"));
    EXPECT_FALSE(network_utils::is_valid_mac("00:1A:2B:3C:4D:5G"));
}

TEST(MacChangerTest, GenerateRandomMac) {
    std::string mac = mac_changer::generate_random_mac();
    EXPECT_TRUE(network_utils::is_valid_mac(mac));
}

TEST(MacChangerTest, ListInterfaces) {
    auto interfaces = mac_changer::list_network_interfaces();
    EXPECT_FALSE(interfaces.empty());
}