#!/bin/bash

echo "enter device codename"
read device
echo "config? y/n"
read config

mkdir ../out

make ARCH=arm64 O=../out merge_hi6250_defconfig

if [ "$config" = "y" ]
then
	
	make ARCH=arm64 O=../out menuconfig
fi

make ARCH=arm64 O=../out -j8
make O=out CONFIG_DEBUG_SECTION_MISMATCH=y -j8

