#!/bin/bash

echo "enter device codename"
read device

#	echo "finding and placing modules"
#
#		rm -f ./Output/${device}/rusty/system/lib/modules/*
#		find -name "*.ko" -exec cp -f '{}'  ./Output/rusty/${device}/system/lib/modules/ \;
#

	echo "Creating new boot.img"
	
	cd ../zip
	echo "rm boot.extracted"
	rm -rf boot.extracted

	echo "clean boot.extracted from boot.img"
	mkbootimg_tools/mkboot boot.img boot.extracted
	
	echo "place Image.gz"
	cp ../out/arch/arm64/boot/Image.gz boot.extracted/kernel
	
	echo "create bootnew.img"
	mkbootimg_tools/mkboot boot.extracted bootnew.img


	make dtbs
	mkbootimg_tools/dtbTool -s 2048 -o ../out/arch/arm64/boot/dt.img -p mkbootimg_tools/dtc/ ../out/arch/arm64/boot/dts/auto-generate


	echo "finding and placing modules"

		rm -f ${device}/rusty/system/lib/modules/*
		cd ../out
		find -name "*.ko" -exec cp -f '{}'  ../zip/${device}/rusty/system/lib/modules/ \;


	echo "Copying image to root of unzipped directory renaming it boot."
	cd ../zip
	cp bootnew.img ${device}/rusty/boot.img
	cd ${device}/rusty

	echo "Creating flashable zip."

	zip -r RustyKernel_${device}-$(date +%F).zip . -x ".*"

	echo "move zip to root folder"
	mv RustyKernel_${device}-$(date +%F).zip ../../../

	echo "remove ../out"
	cd ../../../
cd kernel

#	rm -rf ../out
