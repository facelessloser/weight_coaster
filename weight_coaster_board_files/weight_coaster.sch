EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:My_stuff
LIBS:push_button
LIBS:weight_coaster-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ARDUINO_PRO_MICRO U3
U 1 1 5994A629
P 5850 3400
F 0 "U3" V 6600 3400 60  0000 C CNN
F 1 "ARDUINO_PRO_MICRO" H 5850 3400 60  0000 C CNN
F 2 "arduino_leonard_custom:arduino_leonardo" H 6000 3100 60  0001 C CNN
F 3 "" H 6000 3100 60  0000 C CNN
	1    5850 3400
	1    0    0    -1  
$EndComp
$Comp
L HX711 U6
U 1 1 5995D8F6
P 7400 3400
F 0 "U6" H 7400 3750 60  0000 C CNN
F 1 "HX711" H 7400 3050 60  0000 C CNN
F 2 "hx711:hx711" H 7200 3500 60  0001 C CNN
F 3 "" H 7200 3500 60  0001 C CNN
	1    7400 3400
	-1   0    0    1   
$EndComp
$Comp
L push_button U4
U 1 1 59972651
P 6000 4500
F 0 "U4" H 6000 4400 60  0000 C CNN
F 1 "push_button" H 6000 4700 60  0000 C CNN
F 2 "small_button_2pin_custom:small_button_2pin_custom" H 6000 4500 60  0001 C CNN
F 3 "" H 6000 4500 60  0001 C CNN
	1    6000 4500
	0    1    1    0   
$EndComp
$Comp
L push_button U2
U 1 1 599726D5
P 5600 4500
F 0 "U2" H 5600 4400 60  0000 C CNN
F 1 "push_button" H 5600 4700 60  0000 C CNN
F 2 "small_button_2pin_custom:small_button_2pin_custom" H 5600 4500 60  0001 C CNN
F 3 "" H 5600 4500 60  0001 C CNN
	1    5600 4500
	0    1    1    0   
$EndComp
$Comp
L push_button U5
U 1 1 59972718
P 6400 2100
F 0 "U5" H 6400 2000 60  0000 C CNN
F 1 "push_button" H 6400 2300 60  0000 C CNN
F 2 "small_button_2pin_custom:small_button_2pin_custom" H 6400 2100 60  0001 C CNN
F 3 "" H 6400 2100 60  0001 C CNN
	1    6400 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 4000 6000 4200
Wire Wire Line
	5900 4000 5900 4150
Wire Wire Line
	5900 4150 5600 4150
Wire Wire Line
	5600 4150 5600 4200
Wire Wire Line
	6400 2400 6400 2800
Wire Wire Line
	5100 4800 6000 4800
Connection ~ 5600 4800
Wire Wire Line
	7000 2500 7000 3250
Wire Wire Line
	5600 2500 5600 2800
Wire Wire Line
	7000 3550 6750 3550
Wire Wire Line
	7000 3350 6600 3350
Wire Wire Line
	6600 3350 6600 2700
Wire Wire Line
	6600 2700 6000 2700
Wire Wire Line
	6000 2700 6000 2800
Wire Wire Line
	5900 2800 5900 2600
Wire Wire Line
	5900 2600 6900 2600
Wire Wire Line
	6900 2600 6900 3450
Wire Wire Line
	6900 3450 7000 3450
Wire Wire Line
	7000 2500 5600 2500
Wire Wire Line
	6400 1800 5100 1800
Wire Wire Line
	5400 1800 5400 2800
Connection ~ 5400 1800
Wire Wire Line
	6750 3550 6750 2400
Wire Wire Line
	6750 2400 5850 2400
Wire Wire Line
	5850 2400 5850 1800
Connection ~ 5850 1800
$Comp
L WS2812_RING U1
U 1 1 5997269A
P 4250 2350
F 0 "U1" H 4600 2750 60  0000 C CNN
F 1 "WS2812_RING" H 4250 3050 60  0000 C CNN
F 2 "ws2812:ws2812_custom" H 4250 2350 60  0001 C CNN
F 3 "" H 4250 2350 60  0000 C CNN
	1    4250 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 4000 5800 4100
Wire Wire Line
	5800 4100 4100 4100
Wire Wire Line
	4100 4100 4100 2650
Wire Wire Line
	4200 2650 4200 2750
Wire Wire Line
	4200 2750 6500 2750
Connection ~ 5600 2750
Wire Wire Line
	4300 2650 4300 2700
Wire Wire Line
	4300 2700 5100 2700
Connection ~ 5100 2700
Wire Wire Line
	5100 1800 5100 4950
Wire Wire Line
	7000 4400 6500 4400
Wire Wire Line
	6500 4400 6500 2750
Wire Wire Line
	7000 4500 6500 4500
Wire Wire Line
	6500 4500 6500 4950
Wire Wire Line
	6500 4950 5100 4950
Connection ~ 5100 4800
$Comp
L battery_custom U7
U 1 1 5999C56C
P 7350 4450
F 0 "U7" H 7350 4200 60  0000 C CNN
F 1 "battery_custom" H 7350 4850 60  0000 C CNN
F 2 "power_connector_custom:Power_connector" H 7350 4750 60  0001 C CNN
F 3 "" H 7350 4750 60  0000 C CNN
	1    7350 4450
	0    -1   -1   0   
$EndComp
$Comp
L power_bank_board U8
U 1 1 59A15C8D
P 7700 5350
F 0 "U8" H 8050 5350 60  0000 C CNN
F 1 "power_bank_board" H 7700 5750 60  0000 C CNN
F 2 "pound_shop_power_bank_custom:pound_shop_power_bank_custom" H 7700 5750 60  0001 C CNN
F 3 "" H 7700 5750 60  0001 C CNN
	1    7700 5350
	1    0    0    -1  
$EndComp
$Comp
L monut_pin_custom U10
U 1 1 59A2B73A
P 8450 4150
F 0 "U10" H 8450 4000 60  0000 C CNN
F 1 "monut_pin_custom" H 8450 4300 60  0000 C CNN
F 2 "mount_pin_custom:mount_pin_custom" H 8450 4150 60  0001 C CNN
F 3 "" H 8450 4150 60  0001 C CNN
	1    8450 4150
	1    0    0    -1  
$EndComp
$Comp
L monut_pin_custom U9
U 1 1 59A2B781
P 8400 4600
F 0 "U9" H 8400 4450 60  0000 C CNN
F 1 "monut_pin_custom" H 8400 4750 60  0000 C CNN
F 2 "mount_pin_custom:mount_pin_custom" H 8400 4600 60  0001 C CNN
F 3 "" H 8400 4600 60  0001 C CNN
	1    8400 4600
	1    0    0    -1  
$EndComp
$EndSCHEMATC
