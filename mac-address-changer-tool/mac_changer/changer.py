import subprocess
import re
import random

class MACChanger:
    def __init__(self, interface="eth0"):
        self.interface = interface

    def get_current_mac(self):
        try:
            result = subprocess.run(
                ["ip", "link", "show", self.interface],
                capture_output=True, text=True, check=True
            )
            match = re.search(r"link/ether ([0-9a-f:]{17})", result.stdout)
            return match.group(1) if match else None
        except subprocess.CalledProcessError:
            return None

    def _generate_random_mac(self):
        return ":".join(f"{random.randint(0,255):02x}" for _ in range(6))

    def change_mac(self, new_mac=None):
        if new_mac is None:
            new_mac = self._generate_random_mac()
        try:
            subprocess.run(["sudo", "ip", "link", "set", self.interface, "down"], check=True)
            subprocess.run(["sudo", "ip", "link", "set", self.interface, "address", new_mac], check=True)
            subprocess.run(["sudo", "ip", "link", "set", self.interface, "up"], check=True)
            return new_mac
        except subprocess.CalledProcessError:
            return None

    def restore_mac(self, original_mac):
        return self.change_mac(original_mac)