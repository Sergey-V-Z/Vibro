EESchema Schematic File Version 4
EELAYER 29 0
EELAYER END
$Descr A2 23386 16535
encoding utf-8
Sheet 2 4
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
L Triac_Thyristor:BT139-600 Q?
U 1 1 5E842F0F
P 3550 3450
F 0 "Q?" H 3678 3496 50  0000 L CNN
F 1 "BT139-600" H 3678 3405 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 3750 3375 50  0001 L CIN
F 3 "https://www.rapidonline.com/pdf/47-3240.pdf" H 3550 3450 50  0001 L CNN
	1    3550 3450
	1    0    0    -1  
$EndComp
$Comp
L Relay_SolidState:MOC3063M U?
U 1 1 5E84809D
P 2450 3300
F 0 "U?" H 2450 3625 50  0000 C CNN
F 1 "MOC3063M" H 2450 3534 50  0000 C CNN
F 2 "Package_DIP:DIP-6_W7.62mm_LongPads" H 2250 3100 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/MO/MOC3061M.pdf" H 2415 3300 50  0001 L CNN
	1    2450 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3050 4450 3050
Wire Wire Line
	3550 3050 3550 3300
$Comp
L Device:R R?
U 1 1 5E8A517D
P 3300 3050
F 0 "R?" V 3093 3050 50  0000 C CNN
F 1 "380" V 3184 3050 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3230 3050 30  0001 C CNN
F 3 "" H 3300 3050 30  0000 C CNN
	1    3300 3050
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E8A5B18
P 3300 3850
F 0 "R?" V 3093 3850 50  0000 C CNN
F 1 "330" V 3184 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3230 3850 30  0001 C CNN
F 3 "" H 3300 3850 30  0000 C CNN
	1    3300 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 3050 3550 3050
Connection ~ 3550 3050
Wire Wire Line
	3400 3550 3050 3550
Wire Wire Line
	3050 3550 3050 3850
Wire Wire Line
	3050 3850 3150 3850
Wire Wire Line
	2750 3400 3050 3400
Wire Wire Line
	3050 3400 3050 3550
Connection ~ 3050 3550
Wire Wire Line
	3150 3050 2750 3050
Wire Wire Line
	2750 3050 2750 3200
$Comp
L Device:R R?
U 1 1 5E892164
P 4450 3200
F 0 "R?" H 4520 3276 50  0000 L CNN
F 1 "39" H 4520 3185 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0516_L15.5mm_D5.0mm_P20.32mm_Horizontal" H 4520 3109 30  0001 L CNN
F 3 "" H 4450 3200 30  0000 C CNN
	1    4450 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3850 3550 3850
Wire Wire Line
	3550 3600 3550 3850
Connection ~ 3550 3850
Wire Wire Line
	3550 3850 4450 3850
Text Label 1750 3200 2    50   ~ 0
ON-OFF
Wire Wire Line
	2050 3200 2150 3200
$Comp
L power:GNDD #PWR?
U 1 1 5FCC25C2
P 2100 3450
AR Path="/5E899CB6/5FCC25C2" Ref="#PWR?"  Part="1" 
AR Path="/5FCC25C2" Ref="#PWR0122"  Part="1" 
AR Path="/5E8C7B27/5FCC25C2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2100 3200 50  0001 C CNN
F 1 "GNDD" H 2105 3277 50  0000 C CNN
F 2 "" H 2100 3450 60  0000 C CNN
F 3 "" H 2100 3450 60  0000 C CNN
	1    2100 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 3400 2100 3400
Wire Wire Line
	2100 3400 2100 3450
$Comp
L Device:R R?
U 1 1 5FCF0695
P 1900 3200
AR Path="/5E899CB6/5FCF0695" Ref="R?"  Part="1" 
AR Path="/5FCF0695" Ref="R16"  Part="1" 
AR Path="/5E8C7B27/5FCF0695" Ref="R?"  Part="1" 
F 0 "R?" V 1850 3350 50  0000 C CNN
F 1 "330" V 1784 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1830 3200 30  0001 C CNN
F 3 "" H 1900 3200 30  0000 C CNN
	1    1900 3200
	0    1    1    0   
$EndComp
$Comp
L Isolator:EL814 U?
U 1 1 5FDB1973
P 3050 1500
F 0 "U?" H 3050 1825 50  0000 C CNN
F 1 "EL814" H 3050 1734 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm_LongPads" H 2850 1300 50  0001 L CIN
F 3 "http://www.everlight.com/file/ProductFile/EL814.pdf" H 3075 1500 50  0001 L CNN
	1    3050 1500
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5FDFD0AC
P 3750 1600
F 0 "R?" V 3543 1600 50  0000 C CNN
F 1 "51K" V 3634 1600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3680 1600 30  0001 C CNN
F 3 "" H 3750 1600 30  0000 C CNN
	1    3750 1600
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FDFE33A
P 4100 1600
F 0 "R?" V 3893 1600 50  0000 C CNN
F 1 "51K" V 3984 1600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4030 1600 30  0001 C CNN
F 3 "" H 4100 1600 30  0000 C CNN
	1    4100 1600
	-1   0    0    1   
$EndComp
Wire Wire Line
	3350 1600 3600 1600
Wire Wire Line
	3900 1600 3900 2500
$Comp
L Device:R R?
U 1 1 5FE5861F
P 2600 1150
AR Path="/5F06B197/5FE5861F" Ref="R?"  Part="1" 
AR Path="/5FE5861F" Ref="R19"  Part="1" 
AR Path="/5E8C7B27/5FE5861F" Ref="R?"  Part="1" 
F 0 "R?" H 2670 1196 50  0000 L CNN
F 1 "10k" H 2670 1105 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2530 1150 30  0001 C CNN
F 3 "" H 2600 1150 30  0000 C CNN
	1    2600 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FE6F55B
P 2750 1700
AR Path="/5E899CB6/5FE6F55B" Ref="#PWR?"  Part="1" 
AR Path="/5FE6F55B" Ref="#PWR0126"  Part="1" 
AR Path="/5E8C7B27/5FE6F55B" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2750 1450 50  0001 C CNN
F 1 "GNDD" H 2755 1527 50  0000 C CNN
F 2 "" H 2750 1700 60  0000 C CNN
F 3 "" H 2750 1700 60  0000 C CNN
	1    2750 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 1600 2750 1700
$Comp
L power:VPP #PWR?
U 1 1 5FE8B6C7
P 2600 1000
AR Path="/5E899CB6/5FE8B6C7" Ref="#PWR?"  Part="1" 
AR Path="/5FE8B6C7" Ref="#PWR0127"  Part="1" 
AR Path="/5E8C7B27/5FE8B6C7" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2600 850 50  0001 C CNN
F 1 "VPP" H 2615 1173 50  0000 C CNN
F 2 "" H 2600 1000 60  0000 C CNN
F 3 "" H 2600 1000 60  0000 C CNN
	1    2600 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 1300 2600 1400
Wire Wire Line
	2600 1400 2750 1400
Text Label 2500 1400 2    50   ~ 0
Zero_Det
Wire Wire Line
	2500 1400 2600 1400
Connection ~ 2600 1400
$Comp
L pspice:CAP C?
U 1 1 5E891400
P 4450 3600
F 0 "C?" H 4628 3646 50  0000 L CNN
F 1 "0.01 mkF" H 4628 3555 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L13.0mm_W5.0mm_P10.00mm_FKS3_FKP3_MKS4" H 4450 3600 60  0001 C CNN
F 3 "" H 4450 3600 60  0000 C CNN
	1    4450 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 2500 3900 2500
$Comp
L Connector:Screw_Terminal_01x04 J?
U 1 1 5F9A17AC
P 4600 2300
F 0 "J?" V 4564 2012 50  0000 R CNN
F 1 "Screw_Terminal_01x04" V 4473 2012 50  0000 R CNN
F 2 "TerminalBlock_MetzConnect:TerminalBlock_MetzConnect_Type055_RT01504HDWU_1x04_P5.00mm_Horizontal" H 4600 2300 50  0001 C CNN
F 3 "~" H 4600 2300 50  0001 C CNN
	1    4600 2300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3350 1400 4100 1400
Wire Wire Line
	4100 1400 4100 1450
Wire Wire Line
	4100 1750 4100 2600
Wire Wire Line
	4100 2600 4600 2600
Wire Wire Line
	4600 2600 4600 2500
Wire Wire Line
	3550 2500 3550 3050
Wire Wire Line
	3550 2500 3900 2500
Connection ~ 3900 2500
Wire Wire Line
	3550 3850 3550 4100
Wire Wire Line
	3550 4100 4800 4100
Wire Wire Line
	4800 4100 4800 2500
Wire Wire Line
	4600 2600 4700 2600
Wire Wire Line
	4700 2600 4700 2500
Connection ~ 4600 2600
$EndSCHEMATC
