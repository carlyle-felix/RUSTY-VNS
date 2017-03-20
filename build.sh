#!/bin/bash

echo "config? y/n"
read config

export KBUILD_BUILD_USER="Carlyle_F"
export KBUILD_BUILD_HOST="XDA"

mkdir ../out

make ARCH=arm64 O=../out merge_hi6250_defconfig

if [ "$config" = "y" ]
then
	
	make ARCH=arm64 O=../out menuconfig
fi

make ARCH=arm64 O=../out -j8
# make O=../out CONFIG_DEBUG_SECTION_MISMATCH=y -j8

