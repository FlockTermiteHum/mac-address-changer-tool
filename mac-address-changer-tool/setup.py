from setuptools import setup, find_packages

setup(
    name="mac-address-changer-tool",
    version="0.1.0",
    packages=find_packages(),
    install_requires=[
        "netifaces>=0.10.0",
    ],
    entry_points={
        "console_scripts": [
            "mac-changer=mac_changer.cli:main",
        ],
    },
    author="Example Dev",
    description="A simple MAC address changer tool for Linux",
    python_requires=">=3.6",
)