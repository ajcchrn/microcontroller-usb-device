#!/bin/sh

UDEV_RULE="50-usb-cp210x.rules"
UDEV_RULES_PATH="/etc/udev/rules.d"

if [ "$(id -u)" -eq 0 ]; then
	if [ -f "$UDEV_RULE" ]; then
		if [ -f "$UDEV_RULES_PATH/$UDEV_RULE" ]; then
			echo "There's already a $UDEV_RULE file? Exiting."
			exit 1
		else
			# Copy udev-config
			echo "Copying $UDEV_RULE to $UDEV_RULES_PATH"
			cp $UDEV_RULE $UDEV_RULES_PATH
		fi
	else
		echo "udev rules file is missing, exiting!"
		exit 2
	fi
	
	# Reload udev
	echo "Reloading udev"
	udevadm control --reload-rules
	udevadm trigger

	echo "Done!"
	exit 0
else
	echo "Must run as super-user, exiting."
	exit 1
fi
