#!/bin/bash

# install libxbee3

cd ../lib/libxbee3/
make configure
make all
sudo make install -y
cd ../scripts/