#!/bin/sh
CMDLINE_FILE="/boot/cmdline.txt"
CONFIG_FILE="/boot/config.txt"
SERIAL_DEV="/dev/serial0"
GROUP="dialout"
USER="$(logname)"

##  Check if /dev/serial0 is a symlink already
if [ -h "$SERIAL_DEV" ] && \
	[ "$(stat --dereference --format=%G $SERIAL_DEV)" = "$GROUP" ]
then
	echo "$SERIAL_DEV seem to be configured correctly already?"
	exit 0
fi

##  Remove serial console entry from /boot/cmdline.txt
if [ -f "$CMDLINE_FILE" ]; then
	echo "Updating $CMDLINE_FILE"
	# From raspi-conf.sh, -i: edit file in place
	sudo sed --in-place $CMDLINE_FILE \
		--expression="s/console=ttyAMA0,[0-9]\+ //"
	sudo sed --in-place $CMDLINE_FILE \
		--expression="s/console=serial0,[0-9]\+ //"
else
	echo "$CMDLINE_FILE is not a regular file, exiting."
	exit 2
fi

##  Add enable_uart=1 to /boot/config.txt
if [ -f "$CONFIG_FILE" ]; then
	echo "Updating $CONFIG_FILE"
	# Grep from begining of line
	if grep --quiet "^enable_uart=1" $CONFIG_FILE; then
		# Already enabled, skip
		true
	elif grep --quiet "^enable_uart=0" $CONFIG_FILE; then
		# Disabled, reenable
		sudo sed --in-place $CONFIG_FILE \
			--expression="s/^enable_uart=0/enable_uart=1/"
	else
		# Add the missing entry
		echo "enable_uart=1" | sudo tee -a $CONFIG_FILE
	fi
else
	echo "$CONFIG_FILE is not a regular file, exiting."
	exit 2
fi

##  Check if user is member of dialout
if [ "$(id -u)" -ne 0 ]; then
	# Regular user
	if groups | grep --silent $GROUP; then
		true
	else
		echo "Adding $USER to the $GROUP group"
		sudo usermod -a -G $GROUP "$USER"
	fi
elif [ "$(id -u)" -eq 0 ] && [ "$(whoami)" != "$(logname)" ]; then
	# Running as super-user
	if groups "$USER" | grep --silent $GROUP; then
		true
	else
		echo "Adding $USER to the $GROUP group"
		sudo usermod -a -G $GROUP "$USER"
	fi
else
	# Running as root
	echo "Tip: Add a regular user to the $GROUP group."
fi

##  End of script
echo "A reboot is required for the changes to take effect."
