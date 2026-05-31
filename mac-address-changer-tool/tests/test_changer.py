import unittest
from unittest.mock import patch, MagicMock
from mac_changer import MACChanger

class TestMACChanger(unittest.TestCase):
    def setUp(self):
        self.changer = MACChanger(interface="eth0")

    @patch("mac_changer.changer.subprocess.run")
    def test_get_current_mac_success(self, mock_run):
        mock_run.return_value = MagicMock(
            stdout="link/ether 00:11:22:33:44:55 brd ff:ff:ff:ff:ff:ff\n",
            returncode=0
        )
        mac = self.changer.get_current_mac()
        self.assertEqual(mac, "00:11:22:33:44:55")

    @patch("mac_changer.changer.subprocess.run")
    def test_get_current_mac_failure(self, mock_run):
        mock_run.side_effect = Exception("Network error")
        mac = self.changer.get_current_mac()
        self.assertIsNone(mac)

    def test_generate_random_mac_format(self):
        mac = self.changer._generate_random_mac()
        self.assertRegex(mac, r"^([0-9a-f]{2}:){5}[0-9a-f]{2}$")

    @patch("mac_changer.changer.subprocess.run")
    def test_change_mac_success(self, mock_run):
        mock_run.return_value = MagicMock(returncode=0)
        new_mac = self.changer.change_mac("aa:bb:cc:dd:ee:ff")
        self.assertEqual(new_mac, "aa:bb:cc:dd:ee:ff")

if __name__ == "__main__":
    unittest.main()