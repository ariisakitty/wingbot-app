from setuptools import find_packages
from setuptools import setup

setup(
    name='bridge_interface',
    version='0.0.0',
    packages=find_packages(
        include=('bridge_interface', 'bridge_interface.*')),
)
