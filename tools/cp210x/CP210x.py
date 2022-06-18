#   TODO:
#	- Attaching USB device
#		- Read configuration
#		- Handsaking, default is using RTS/CTS?
#	- Using GPIO pins
#		- Figure out why LEDs are so dim, writes toggling pull-up?
#		- Read Latch
#		- Check configuration of GPIO0 and GPIO1 as activity LEDs?

import usb.core
import usb.util

## Find and attach USB-device
def find():
	# From CP2104 datasheet
	vendor_id = 0x10C4
	product_id = 0xEA60

	dev = usb.core.find(idVendor = vendor_id, idProduct = product_id)
	
	if dev is None:
		print("Couldn't find a CP210x device")
	else:
		print("Found a CP210x device!")

	return dev

## Set GPIO pin
def set_pin(device, pin_num, pin_state):
	# From AN571 page 18
	bmRequestType = 0b01000001
	bRequest = 0xFF	# VENDOR_SPECIFIC
	wValue = 0x37E1
	wIndex = 0x0000 # placeholder
	wLength = 0	# Length of return data
	# Data is None, i.e. there's no return data

	# Write latch values are supplied in wIndex
	# bits 0-7: mask of latch state to write
	# bits 8-15: latch state to write
	if pin_state is True:
		print("Setting pin {} to ON".format(pin_num))
		wIndex = (1 << pin_num) | ((1 << pin_num) << 8)	
	else:
		print("Setting pin {} to OFF".format(pin_num))
		wIndex = (1 << pin_num)

	## Relying on the argument order
	# ctrl_transfer() does a control transfer to endpoint 0
	return device.ctrl_transfer(bmRequestType, bRequest, wValue, wIndex, wLength)

## Read GPIO pin
def read_pin(device, pin_num):
	# From AN571 page 18
	bmRequestType = 0b11000001
	bRequest = 0xFF	# VENDOR_SPECIFIC
	wValue = 0x00C2
	wIndex = 0
	wLength = 1	# Length of return data
	# Data is a byte representing the current latch states

	print("Reading pin {}".format(pin_num))
	# The return value is an array when wLength is the length of data to read
	latch_states = device.ctrl_transfer(bmRequestType, bRequest, wValue, wIndex, wLength)
	
	# Mask out the latch state of interest
	if (latch_states[0] & (1 << pin_num)) > 0:
		return True
	else:
		return False

