import argparse
from .changer import MACChanger

def main():
    parser = argparse.ArgumentParser(description="Change MAC address of a network interface")
    parser.add_argument("interface", help="Network interface (e.g., eth0, wlan0)")
    parser.add_argument("-m", "--mac", help="New MAC address (random if omitted)")
    args = parser.parse_args()

    changer = MACChanger(args.interface)
    current = changer.get_current_mac()
    print(f"Current MAC: {current}")

    new_mac = changer.change_mac(args.mac)
    if new_mac:
        print(f"Changed to: {new_mac}")
    else:
        print("Failed to change MAC address.")

if __name__ == "__main__":
    main()