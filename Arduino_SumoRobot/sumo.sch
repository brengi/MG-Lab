EESchema Schematic File Version 2
LIBS:power
LIBS:sumo-cache
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
L CONN_8 P1
U 1 1 5788ED5D
P 2575 6300
F 0 "P1" V 2525 6300 60  0000 C CNN
F 1 "Power" V 2625 6300 60  0000 C CNN
F 2 "huellas:Socket_Strip_Arduino_1x08" H 2575 6300 60  0001 C CNN
F 3 "" H 2575 6300 60  0000 C CNN
	1    2575 6300
	1    0    0    -1  
$EndComp
$Comp
L CONN_6 P2
U 1 1 5788ED5E
P 2575 7100
F 0 "P2" V 2525 7100 60  0000 C CNN
F 1 "Analog" V 2625 7100 60  0000 C CNN
F 2 "huellas:Socket_Strip_Arduino_1x06" H 2575 7100 60  0001 C CNN
F 3 "" H 2575 7100 60  0000 C CNN
	1    2575 7100
	1    0    0    -1  
$EndComp
$Comp
L CONN_8 P4
U 1 1 5788ED5F
P 2900 7000
F 0 "P4" V 2850 7000 60  0000 C CNN
F 1 "Digital" V 2950 7000 60  0000 C CNN
F 2 "huellas:Socket_Strip_Arduino_1x08" H 2900 7000 60  0001 C CNN
F 3 "" H 2900 7000 60  0000 C CNN
	1    2900 7000
	-1   0    0    -1  
$EndComp
$Comp
L CONN_10 P3
U 1 1 5788ED60
P 2900 6000
F 0 "P3" V 2850 6000 60  0000 C CNN
F 1 "Digital" V 2950 6000 60  0000 C CNN
F 2 "huellas:Socket_Strip_Arduino_1x10" H 2900 6000 60  0001 C CNN
F 3 "" H 2900 6000 60  0000 C CNN
	1    2900 6000
	-1   0    0    -1  
$EndComp
Text Label 2225 6150 2    60   ~ 0
Reset
Text Label 2225 6050 2    60   ~ 0
IOREF
Text Label 1475 6850 0    60   ~ 0
A0
Text Label 1475 6950 0    60   ~ 0
A1
Text Label 1475 7050 0    60   ~ 0
A2
Text Label 1475 7150 0    60   ~ 0
A3
Text Label 1475 7250 0    60   ~ 0
A4(SDA)
Text Label 1475 7350 0    60   ~ 0
A5(SCL)
Text Label 3400 7350 0    60   ~ 0
0(Rx)
Text Label 3400 7150 0    60   ~ 0
2
Text Label 3400 7250 0    60   ~ 0
1(Tx)
Text Label 3400 7050 0    60   ~ 0
3(**)
Text Label 3400 6950 0    60   ~ 0
4
Text Label 3400 6850 0    60   ~ 0
5(**)
Text Label 3400 6750 0    60   ~ 0
6(**)
Text Label 3400 6650 0    60   ~ 0
7
Text Label 3400 6450 0    60   ~ 0
8
Text Label 3400 6350 0    60   ~ 0
9(**)
Text Label 3400 6250 0    60   ~ 0
10(**/SS)
Text Label 3400 6150 0    60   ~ 0
11(**/MOSI)
Text Label 3400 6050 0    60   ~ 0
12(MISO)
Text Label 3400 5950 0    60   ~ 0
13(SCK)
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR01
U 1 1 5788ED61
P 3325 5850
F 0 "#PWR01" H 3325 5850 30  0001 C CNN
F 1 "GND" H 3325 5780 30  0001 C CNN
F 2 "" H 3325 5850 60  0000 C CNN
F 3 "" H 3325 5850 60  0000 C CNN
	1    3325 5850
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR02
U 1 1 5788ED62
P 2150 6700
F 0 "#PWR02" H 2150 6700 30  0001 C CNN
F 1 "GND" H 2150 6630 30  0001 C CNN
F 2 "" H 2150 6700 60  0000 C CNN
F 3 "" H 2150 6700 60  0000 C CNN
	1    2150 6700
	1    0    0    -1  
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR03
U 1 1 5788ED63
P 1900 4975
F 0 "#PWR03" H 1900 5065 20  0001 C CNN
F 1 "+5V" H 1900 5065 30  0000 C CNN
F 2 "" H 1900 4975 60  0000 C CNN
F 3 "" H 1900 4975 60  0000 C CNN
	1    1900 4975
	1    0    0    -1  
$EndComp
$Comp
L +3.3V-RESCUE-Arduino_As_Uno #PWR04
U 1 1 5788ED64
P 2025 4975
F 0 "#PWR04" H 2025 4935 30  0001 C CNN
F 1 "+3.3V" H 2025 5085 30  0000 C CNN
F 2 "" H 2025 4975 60  0000 C CNN
F 3 "" H 2025 4975 60  0000 C CNN
	1    2025 4975
	1    0    0    -1  
$EndComp
NoConn ~ 2225 5950
$Comp
L CONN_1 P5
U 1 1 5788ED65
P 3725 5075
F 0 "P5" H 3805 5075 40  0000 L CNN
F 1 "CONN_1" H 3725 5130 30  0001 C CNN
F 2 "huellas:Arduino_1pin" H 3725 5075 60  0001 C CNN
F 3 "" H 3725 5075 60  0000 C CNN
	1    3725 5075
	0    -1   -1   0   
$EndComp
$Comp
L CONN_1 P6
U 1 1 5788ED66
P 3800 5075
F 0 "P6" H 3880 5075 40  0000 L CNN
F 1 "CONN_1" H 3800 5130 30  0001 C CNN
F 2 "huellas:Arduino_1pin" H 3800 5075 60  0001 C CNN
F 3 "" H 3800 5075 60  0000 C CNN
	1    3800 5075
	0    -1   -1   0   
$EndComp
$Comp
L CONN_1 P7
U 1 1 5788ED67
P 3875 5075
F 0 "P7" H 3955 5075 40  0000 L CNN
F 1 "CONN_1" H 3875 5130 30  0001 C CNN
F 2 "huellas:Arduino_1pin" H 3875 5075 60  0001 C CNN
F 3 "" H 3875 5075 60  0000 C CNN
	1    3875 5075
	0    -1   -1   0   
$EndComp
$Comp
L CONN_1 P8
U 1 1 5788ED68
P 3950 5075
F 0 "P8" H 4030 5075 40  0000 L CNN
F 1 "CONN_1" H 3950 5130 30  0001 C CNN
F 2 "huellas:Arduino_1pin" H 3950 5075 60  0001 C CNN
F 3 "" H 3950 5075 60  0000 C CNN
	1    3950 5075
	0    -1   -1   0   
$EndComp
Text Notes 3725 5350 0    60   ~ 0
Holes
NoConn ~ 3725 5225
NoConn ~ 3800 5225
NoConn ~ 3875 5225
NoConn ~ 3950 5225
$Comp
L CNY70 U4
U 1 1 5788F740
P 1900 4225
F 0 "U4" H 1900 4225 60  0000 C CNN
F 1 "CNY70" H 1900 4225 60  0000 C CNN
F 2 "huellas:cny70-4" H 1900 4225 60  0001 C CNN
F 3 "" H 1900 4225 60  0000 C CNN
	1    1900 4225
	1    0    0    -1  
$EndComp
$Comp
L CNY70 U3
U 1 1 5788F741
P 1900 3525
F 0 "U3" H 1900 3525 60  0000 C CNN
F 1 "CNY70" H 1900 3525 60  0000 C CNN
F 2 "huellas:cny70-4" H 1900 3525 60  0001 C CNN
F 3 "" H 1900 3525 60  0000 C CNN
	1    1900 3525
	1    0    0    -1  
$EndComp
$Comp
L CNY70 U2
U 1 1 5788F742
P 1900 2825
F 0 "U2" H 1900 2825 60  0000 C CNN
F 1 "CNY70" H 1900 2825 60  0000 C CNN
F 2 "huellas:cny70-4" H 1900 2825 60  0001 C CNN
F 3 "" H 1900 2825 60  0000 C CNN
	1    1900 2825
	1    0    0    -1  
$EndComp
$Comp
L CNY70 U1
U 1 1 5788F743
P 1900 2175
F 0 "U1" H 1900 2175 60  0000 C CNN
F 1 "CNY70" H 1900 2175 60  0000 C CNN
F 2 "huellas:cny70-4" H 1900 2175 60  0001 C CNN
F 3 "" H 1900 2175 60  0000 C CNN
	1    1900 2175
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-Arduino_As_Uno R1
U 1 1 5788F744
P 1275 2275
F 0 "R1" V 1355 2275 50  0000 C CNN
F 1 "220" V 1275 2275 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 1205 2275 50  0001 C CNN
F 3 "" H 1275 2275 50  0000 C CNN
	1    1275 2275
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-Arduino_As_Uno R2
U 1 1 5788F745
P 1250 2925
F 0 "R2" V 1330 2925 50  0000 C CNN
F 1 "220" V 1250 2925 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 1180 2925 50  0001 C CNN
F 3 "" H 1250 2925 50  0000 C CNN
	1    1250 2925
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-Arduino_As_Uno R3
U 1 1 5788F746
P 1275 3625
F 0 "R3" V 1355 3625 50  0000 C CNN
F 1 "220" V 1275 3625 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 1205 3625 50  0001 C CNN
F 3 "" H 1275 3625 50  0000 C CNN
	1    1275 3625
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-Arduino_As_Uno R4
U 1 1 5788F747
P 1275 4325
F 0 "R4" V 1355 4325 50  0000 C CNN
F 1 "220" V 1275 4325 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 1205 4325 50  0001 C CNN
F 3 "" H 1275 4325 50  0000 C CNN
	1    1275 4325
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-Arduino_As_Uno R5
U 1 1 5788F748
P 2425 2275
F 0 "R5" V 2505 2275 50  0000 C CNN
F 1 "47K" V 2425 2275 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 2355 2275 50  0001 C CNN
F 3 "" H 2425 2275 50  0000 C CNN
	1    2425 2275
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-Arduino_As_Uno R6
U 1 1 5788F749
P 2425 2925
F 0 "R6" V 2505 2925 50  0000 C CNN
F 1 "47K" V 2425 2925 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 2355 2925 50  0001 C CNN
F 3 "" H 2425 2925 50  0000 C CNN
	1    2425 2925
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-Arduino_As_Uno R7
U 1 1 5788F74A
P 2425 3625
F 0 "R7" V 2505 3625 50  0000 C CNN
F 1 "47K" V 2425 3625 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 2355 3625 50  0001 C CNN
F 3 "" H 2425 3625 50  0000 C CNN
	1    2425 3625
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-Arduino_As_Uno R8
U 1 1 5788F74B
P 2425 4325
F 0 "R8" V 2505 4325 50  0000 C CNN
F 1 "47K" V 2425 4325 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 2355 4325 50  0001 C CNN
F 3 "" H 2425 4325 50  0000 C CNN
	1    2425 4325
	0    1    1    0   
$EndComp
Text Notes 2950 2125 0    60   ~ 0
A1\n
Text Notes 2950 2775 0    60   ~ 0
A2\n\n
Text Notes 2950 3375 0    60   ~ 0
A3\n
Text Notes 2950 4075 0    60   ~ 0
A4
$Comp
L C-RESCUE-Arduino_As_Uno C1
U 1 1 5788F74C
P 1650 1225
F 0 "C1" H 1675 1325 50  0000 L CNN
F 1 "100nF" H 1675 1125 50  0000 L CNN
F 2 "huellas:C_Rect_L7_W6_P5" H 1688 1075 50  0001 C CNN
F 3 "" H 1650 1225 50  0000 C CNN
	1    1650 1225
	1    0    0    -1  
$EndComp
Text Label 3050 1825 0    60   ~ 0
VCC
$Comp
L 40106D IC1
U 1 1 5788F752
P 3500 2175
F 0 "IC1" H 3600 2300 50  0000 L BNN
F 1 "40106D" H 3600 1975 50  0000 L BNN
F 2 "huellas:40xx-DIL16" H 3500 2325 50  0001 C CNN
F 3 "" H 3500 2175 60  0000 C CNN
	1    3500 2175
	1    0    0    -1  
$EndComp
$Comp
L 40106D IC1
U 2 1 5788F753
P 3500 2775
F 0 "IC1" H 3600 2900 50  0000 L BNN
F 1 "40106D" H 3600 2575 50  0000 L BNN
F 2 "huellas:40xx-DIL16" H 3500 2925 50  0001 C CNN
F 3 "" H 3500 2775 60  0000 C CNN
	2    3500 2775
	1    0    0    -1  
$EndComp
$Comp
L 40106D IC1
U 3 1 5788F754
P 3500 3475
F 0 "IC1" H 3600 3600 50  0000 L BNN
F 1 "40106D" H 3600 3275 50  0000 L BNN
F 2 "huellas:40xx-DIL16" H 3500 3625 50  0001 C CNN
F 3 "" H 3500 3475 60  0000 C CNN
	3    3500 3475
	1    0    0    -1  
$EndComp
$Comp
L 40106D IC1
U 4 1 5788F755
P 3500 4175
F 0 "IC1" H 3600 4300 50  0000 L BNN
F 1 "40106D" H 3600 3975 50  0000 L BNN
F 2 "huellas:40xx-DIL16" H 3500 4325 50  0001 C CNN
F 3 "" H 3500 4175 60  0000 C CNN
	4    3500 4175
	1    0    0    -1  
$EndComp
$Comp
L 40106D IC1
U 7 1 5788F756
P 5350 1275
F 0 "IC1" H 5450 1400 50  0000 L BNN
F 1 "40106D" H 5450 1075 50  0000 L BNN
F 2 "huellas:40xx-DIL16" H 5350 1425 50  0001 C CNN
F 3 "" H 5350 1275 60  0000 C CNN
	7    5350 1275
	-1   0    0    1   
$EndComp
NoConn ~ 2225 6650
NoConn ~ 2225 6150
NoConn ~ 2225 6050
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR05
U 1 1 578FFDCC
P 1450 2050
F 0 "#PWR05" H 1450 1900 50  0001 C CNN
F 1 "+5V" H 1450 2190 50  0000 C CNN
F 2 "" H 1450 2050 50  0000 C CNN
F 3 "" H 1450 2050 50  0000 C CNN
	1    1450 2050
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR06
U 1 1 57901012
P 975 4325
F 0 "#PWR06" H 975 4075 50  0001 C CNN
F 1 "GND" H 975 4175 50  0000 C CNN
F 2 "" H 975 4325 50  0000 C CNN
F 3 "" H 975 4325 50  0000 C CNN
	1    975  4325
	0    1    1    0   
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR07
U 1 1 5790106A
P 975 3625
F 0 "#PWR07" H 975 3375 50  0001 C CNN
F 1 "GND" H 975 3475 50  0000 C CNN
F 2 "" H 975 3625 50  0000 C CNN
F 3 "" H 975 3625 50  0000 C CNN
	1    975  3625
	0    1    1    0   
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR08
U 1 1 5790147A
P 950 2925
F 0 "#PWR08" H 950 2675 50  0001 C CNN
F 1 "GND" H 950 2775 50  0000 C CNN
F 2 "" H 950 2925 50  0000 C CNN
F 3 "" H 950 2925 50  0000 C CNN
	1    950  2925
	0    1    1    0   
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR09
U 1 1 57901956
P 975 2275
F 0 "#PWR09" H 975 2025 50  0001 C CNN
F 1 "GND" H 975 2125 50  0000 C CNN
F 2 "" H 975 2275 50  0000 C CNN
F 3 "" H 975 2275 50  0000 C CNN
	1    975  2275
	0    1    1    0   
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR010
U 1 1 57907B74
P 850 1375
F 0 "#PWR010" H 850 1125 50  0001 C CNN
F 1 "GND" H 850 1225 50  0000 C CNN
F 2 "" H 850 1375 50  0000 C CNN
F 3 "" H 850 1375 50  0000 C CNN
	1    850  1375
	0    1    1    0   
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR011
U 1 1 57908A68
P 1050 1125
F 0 "#PWR011" H 1050 975 50  0001 C CNN
F 1 "+5V" H 1050 1265 50  0000 C CNN
F 2 "" H 1050 1125 50  0000 C CNN
F 3 "" H 1050 1125 50  0000 C CNN
	1    1050 1125
	0    -1   -1   0   
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR012
U 1 1 5790A261
P 1400 3425
F 0 "#PWR012" H 1400 3275 50  0001 C CNN
F 1 "+5V" H 1400 3565 50  0000 C CNN
F 2 "" H 1400 3425 50  0000 C CNN
F 3 "" H 1400 3425 50  0000 C CNN
	1    1400 3425
	1    0    0    -1  
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR013
U 1 1 5790A76B
P 1425 2725
F 0 "#PWR013" H 1425 2575 50  0001 C CNN
F 1 "+5V" H 1425 2865 50  0000 C CNN
F 2 "" H 1425 2725 50  0000 C CNN
F 3 "" H 1425 2725 50  0000 C CNN
	1    1425 2725
	1    0    0    -1  
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR014
U 1 1 5791702B
P 1375 4125
F 0 "#PWR014" H 1375 3975 50  0001 C CNN
F 1 "+5V" H 1375 4265 50  0000 C CNN
F 2 "" H 1375 4125 50  0000 C CNN
F 3 "" H 1375 4125 50  0000 C CNN
	1    1375 4125
	1    0    0    -1  
$EndComp
NoConn ~ 3250 5950
NoConn ~ 3250 5750
NoConn ~ 3250 5650
NoConn ~ 3250 6050
NoConn ~ 3250 5550
$Comp
L R-RESCUE-Arduino_As_Uno R14
U 1 1 578E8C7B
P 7950 4225
F 0 "R14" V 8030 4225 50  0000 C CNN
F 1 "510" V 7950 4225 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 7880 4225 50  0001 C CNN
F 3 "" H 7950 4225 50  0000 C CNN
	1    7950 4225
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-Arduino_As_Uno R15
U 1 1 578E8E36
P 7950 4825
F 0 "R15" V 8030 4825 50  0000 C CNN
F 1 "510" V 7950 4825 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 7880 4825 50  0001 C CNN
F 3 "" H 7950 4825 50  0000 C CNN
	1    7950 4825
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-Arduino_As_Uno R13
U 1 1 578E8ECE
P 7925 5475
F 0 "R13" V 8005 5475 50  0000 C CNN
F 1 "510" V 7925 5475 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 7855 5475 50  0001 C CNN
F 3 "" H 7925 5475 50  0000 C CNN
	1    7925 5475
	0    1    1    0   
$EndComp
$Comp
L R-RESCUE-Arduino_As_Uno 1K1
U 1 1 578E9515
P 7900 6200
F 0 "1K1" V 7980 6200 50  0000 C CNN
F 1 "510" V 7900 6200 50  0000 C CNN
F 2 "huellas:Resistor_Horizontal_RM7mm" V 7830 6200 50  0001 C CNN
F 3 "" H 7900 6200 50  0000 C CNN
	1    7900 6200
	0    1    1    0   
$EndComp
$Comp
L S8050 Q1
U 1 1 578EAC70
P 7100 2075
F 0 "Q1" H 7300 2150 50  0000 L CNN
F 1 "S8050" H 7300 2075 50  0000 L CNN
F 2 "huellas:TO-92_Rugged" H 7300 2000 50  0001 L CIN
F 3 "" H 7100 2075 50  0000 L CNN
	1    7100 2075
	0    -1   -1   0   
$EndComp
$Comp
L S8050 Q2
U 1 1 578EAD2F
P 8425 2075
F 0 "Q2" H 8625 2150 50  0000 L CNN
F 1 "S8050" H 8625 2075 50  0000 L CNN
F 2 "huellas:TO-92_Rugged" H 8625 2000 50  0001 L CIN
F 3 "" H 8425 2075 50  0000 L CNN
	1    8425 2075
	0    -1   -1   0   
$EndComp
$Comp
L S8050 Q3
U 1 1 578EADDE
P 9575 2075
F 0 "Q3" H 9775 2150 50  0000 L CNN
F 1 "S8050" H 9775 2075 50  0000 L CNN
F 2 "huellas:TO-92_Rugged" H 9775 2000 50  0001 L CIN
F 3 "" H 9575 2075 50  0000 L CNN
	1    9575 2075
	0    -1   -1   0   
$EndComp
$Comp
L S8050 Q4
U 1 1 578EAE7F
P 10725 2050
F 0 "Q4" H 10925 2125 50  0000 L CNN
F 1 "S8050" H 10925 2050 50  0000 L CNN
F 2 "huellas:TO-92_Rugged" H 10925 1975 50  0001 L CIN
F 3 "" H 10725 2050 50  0000 L CNN
	1    10725 2050
	0    -1   -1   0   
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR015
U 1 1 578F5352
P 5650 1975
F 0 "#PWR015" H 5650 1825 50  0001 C CNN
F 1 "+5V" H 5650 2115 50  0000 C CNN
F 2 "" H 5650 1975 50  0000 C CNN
F 3 "" H 5650 1975 50  0000 C CNN
	1    5650 1975
	0    -1   -1   0   
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR016
U 1 1 578F53C0
P 7575 2600
F 0 "#PWR016" H 7575 2450 50  0001 C CNN
F 1 "+5V" H 7575 2740 50  0000 C CNN
F 2 "" H 7575 2600 50  0000 C CNN
F 3 "" H 7575 2600 50  0000 C CNN
	1    7575 2600
	-1   0    0    1   
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR017
U 1 1 578F542E
P 8925 2100
F 0 "#PWR017" H 8925 1950 50  0001 C CNN
F 1 "+5V" H 8925 2240 50  0000 C CNN
F 2 "" H 8925 2100 50  0000 C CNN
F 3 "" H 8925 2100 50  0000 C CNN
	1    8925 2100
	-1   0    0    1   
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR018
U 1 1 578F549C
P 10050 2075
F 0 "#PWR018" H 10050 1925 50  0001 C CNN
F 1 "+5V" H 10050 2215 50  0000 C CNN
F 2 "" H 10050 2075 50  0000 C CNN
F 3 "" H 10050 2075 50  0000 C CNN
	1    10050 2075
	-1   0    0    1   
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR019
U 1 1 578F8E49
P 10925 1950
F 0 "#PWR019" H 10925 1700 50  0001 C CNN
F 1 "GND" H 10925 1800 50  0000 C CNN
F 2 "" H 10925 1950 50  0000 C CNN
F 3 "" H 10925 1950 50  0000 C CNN
	1    10925 1950
	0    -1   -1   0   
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR020
U 1 1 578F8EB7
P 9775 1975
F 0 "#PWR020" H 9775 1725 50  0001 C CNN
F 1 "GND" H 9775 1825 50  0000 C CNN
F 2 "" H 9775 1975 50  0000 C CNN
F 3 "" H 9775 1975 50  0000 C CNN
	1    9775 1975
	0    -1   -1   0   
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR021
U 1 1 578F95D3
P 8625 1975
F 0 "#PWR021" H 8625 1725 50  0001 C CNN
F 1 "GND" H 8625 1825 50  0000 C CNN
F 2 "" H 8625 1975 50  0000 C CNN
F 3 "" H 8625 1975 50  0000 C CNN
	1    8625 1975
	0    -1   -1   0   
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR022
U 1 1 578F9911
P 7300 1975
F 0 "#PWR022" H 7300 1725 50  0001 C CNN
F 1 "GND" H 7300 1825 50  0000 C CNN
F 2 "" H 7300 1975 50  0000 C CNN
F 3 "" H 7300 1975 50  0000 C CNN
	1    7300 1975
	0    -1   -1   0   
$EndComp
$Comp
L D 1n1
U 1 1 57903F9B
P 6625 1975
F 0 "1n1" H 6625 2075 50  0000 C CNN
F 1 "D" H 6625 1875 50  0000 C CNN
F 2 "huellas:SMC_Standard" H 6625 1975 50  0001 C CNN
F 3 "" H 6625 1975 50  0000 C CNN
	1    6625 1975
	1    0    0    -1  
$EndComp
$Comp
L D 1n2
U 1 1 5790406A
P 7950 1950
F 0 "1n2" H 7950 2050 50  0000 C CNN
F 1 "D" H 7950 1850 50  0000 C CNN
F 2 "huellas:SMC_Standard" H 7950 1950 50  0001 C CNN
F 3 "" H 7950 1950 50  0000 C CNN
	1    7950 1950
	1    0    0    -1  
$EndComp
$Comp
L D 1n3
U 1 1 57907597
P 9125 1975
F 0 "1n3" H 9125 2075 50  0000 C CNN
F 1 "D" H 9125 1875 50  0000 C CNN
F 2 "huellas:SMC_Standard" H 9125 1975 50  0001 C CNN
F 3 "" H 9125 1975 50  0000 C CNN
	1    9125 1975
	1    0    0    -1  
$EndComp
$Comp
L D 1n4
U 1 1 5790B65A
P 10250 1950
F 0 "1n4" H 10250 2050 50  0000 C CNN
F 1 "D" H 10250 1850 50  0000 C CNN
F 2 "huellas:SMC_Standard" H 10250 1950 50  0001 C CNN
F 3 "" H 10250 1950 50  0000 C CNN
	1    10250 1950
	1    0    0    -1  
$EndComp
$Comp
L RELAY_C K1
U 1 1 578EAD64
P 6675 1350
F 0 "K1" H 6675 1600 60  0000 C CNN
F 1 "RELAY_C" H 6675 1115 60  0000 C CNN
F 2 "huellas:Relay_SANYOU_SRD_Series_Form_C" H 6675 1350 60  0001 C CNN
F 3 "" H 6675 1350 60  0000 C CNN
	1    6675 1350
	0    -1   -1   0   
$EndComp
$Comp
L RELAY_C K2
U 1 1 578EB7EB
P 8000 1350
F 0 "K2" H 8000 1600 60  0000 C CNN
F 1 "RELAY_C" H 8000 1115 60  0000 C CNN
F 2 "huellas:Relay_SANYOU_SRD_Series_Form_C" H 8000 1350 60  0001 C CNN
F 3 "" H 8000 1350 60  0000 C CNN
	1    8000 1350
	0    -1   -1   0   
$EndComp
$Comp
L RELAY_C K3
U 1 1 578EB9B2
P 9125 1325
F 0 "K3" H 9125 1575 60  0000 C CNN
F 1 "RELAY_C" H 9125 1090 60  0000 C CNN
F 2 "huellas:Relay_SANYOU_SRD_Series_Form_C" H 9125 1325 60  0001 C CNN
F 3 "" H 9125 1325 60  0000 C CNN
	1    9125 1325
	0    -1   -1   0   
$EndComp
$Comp
L RELAY_C K4
U 1 1 578EC22D
P 10250 1375
F 0 "K4" H 10250 1625 60  0000 C CNN
F 1 "RELAY_C" H 10250 1140 60  0000 C CNN
F 2 "huellas:Relay_SANYOU_SRD_Series_Form_C" H 10250 1375 60  0001 C CNN
F 3 "" H 10250 1375 60  0000 C CNN
	1    10250 1375
	0    -1   -1   0   
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR023
U 1 1 578F4EF8
P 10300 1175
F 0 "#PWR023" H 10300 925 50  0001 C CNN
F 1 "GND" H 10300 1025 50  0000 C CNN
F 2 "" H 10300 1175 50  0000 C CNN
F 3 "" H 10300 1175 50  0000 C CNN
	1    10300 1175
	-1   0    0    1   
$EndComp
$Comp
L HEADER_4 J1
U 1 1 578F8441
P 8525 675
F 0 "J1" H 8525 925 60  0000 C CNN
F 1 "HEADER_4" H 8525 425 60  0000 C CNN
F 2 "huellas:Pin_Header_Straight_1x04" H 8525 675 60  0001 C CNN
F 3 "" H 8525 675 60  0000 C CNN
	1    8525 675 
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X04 P11
U 1 1 578E5B4B
P 6200 3375
F 0 "P11" H 6200 3625 50  0000 C CNN
F 1 "CONN_01X04" V 6300 3375 50  0000 C CNN
F 2 "huellas:Pin_Header_Straight_1x04_Pitch2.00mm" H 6200 3375 50  0001 C CNN
F 3 "" H 6200 3375 50  0000 C CNN
	1    6200 3375
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P10
U 1 1 578E5BE0
P 6200 2725
F 0 "P10" H 6200 2975 50  0000 C CNN
F 1 "CONN_01X04" V 6300 2725 50  0000 C CNN
F 2 "huellas:Pin_Header_Straight_1x04_Pitch2.00mm" H 6200 2725 50  0001 C CNN
F 3 "" H 6200 2725 50  0000 C CNN
	1    6200 2725
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR024
U 1 1 578E6C4D
P 5950 2575
F 0 "#PWR024" H 5950 2325 50  0001 C CNN
F 1 "GND" H 5950 2425 50  0000 C CNN
F 2 "" H 5950 2575 50  0000 C CNN
F 3 "" H 5950 2575 50  0000 C CNN
	1    5950 2575
	0    1    1    0   
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR025
U 1 1 578E6CCD
P 5950 3225
F 0 "#PWR025" H 5950 2975 50  0001 C CNN
F 1 "GND" H 5950 3075 50  0000 C CNN
F 2 "" H 5950 3225 50  0000 C CNN
F 3 "" H 5950 3225 50  0000 C CNN
	1    5950 3225
	0    1    1    0   
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR026
U 1 1 578E6D4D
P 5950 2875
F 0 "#PWR026" H 5950 2725 50  0001 C CNN
F 1 "+5V" H 5950 3015 50  0000 C CNN
F 2 "" H 5950 2875 50  0000 C CNN
F 3 "" H 5950 2875 50  0000 C CNN
	1    5950 2875
	0    -1   -1   0   
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR027
U 1 1 578E6DCD
P 5950 3525
F 0 "#PWR027" H 5950 3375 50  0001 C CNN
F 1 "+5V" H 5950 3665 50  0000 C CNN
F 2 "" H 5950 3525 50  0000 C CNN
F 3 "" H 5950 3525 50  0000 C CNN
	1    5950 3525
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X06 P9
U 1 1 578E7C39
P 1250 7100
F 0 "P9" H 1250 7450 50  0000 C CNN
F 1 "CONN_01X06" V 1350 7100 50  0000 C CNN
F 2 "huellas:Pin_Header_Straight_1x06" H 1250 7100 50  0001 C CNN
F 3 "" H 1250 7100 50  0000 C CNN
	1    1250 7100
	-1   0    0    1   
$EndComp
$Comp
L +12V-RESCUE-Arduino_As_Uno #PWR028
U 1 1 5790F36F
P 6825 1150
F 0 "#PWR028" H 6825 1000 50  0001 C CNN
F 1 "+12V" H 6825 1290 50  0000 C CNN
F 2 "" H 6825 1150 50  0000 C CNN
F 3 "" H 6825 1150 50  0000 C CNN
	1    6825 1150
	1    0    0    -1  
$EndComp
$Comp
L +12V-RESCUE-Arduino_As_Uno #PWR029
U 1 1 5790F3EF
P 8150 1150
F 0 "#PWR029" H 8150 1000 50  0001 C CNN
F 1 "+12V" H 8150 1290 50  0000 C CNN
F 2 "" H 8150 1150 50  0000 C CNN
F 3 "" H 8150 1150 50  0000 C CNN
	1    8150 1150
	1    0    0    -1  
$EndComp
$Comp
L +12V-RESCUE-Arduino_As_Uno #PWR030
U 1 1 5790FD15
P 9275 1125
F 0 "#PWR030" H 9275 975 50  0001 C CNN
F 1 "+12V" H 9275 1265 50  0000 C CNN
F 2 "" H 9275 1125 50  0000 C CNN
F 3 "" H 9275 1125 50  0000 C CNN
	1    9275 1125
	1    0    0    -1  
$EndComp
$Comp
L +12V-RESCUE-Arduino_As_Uno #PWR031
U 1 1 5790FD95
P 10400 1175
F 0 "#PWR031" H 10400 1025 50  0001 C CNN
F 1 "+12V" H 10400 1315 50  0000 C CNN
F 2 "" H 10400 1175 50  0000 C CNN
F 3 "" H 10400 1175 50  0000 C CNN
	1    10400 1175
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P12
U 1 1 57911255
P 6000 750
F 0 "P12" H 6000 900 50  0000 C CNN
F 1 "CONN_01X02" V 6100 750 50  0000 C CNN
F 2 "huellas:Pin_Header_Straight_1x02_Pitch2.00mm" H 6000 750 50  0001 C CNN
F 3 "" H 6000 750 50  0000 C CNN
	1    6000 750 
	0    -1   -1   0   
$EndComp
$Comp
L +12V-RESCUE-Arduino_As_Uno #PWR032
U 1 1 57911300
P 6050 950
F 0 "#PWR032" H 6050 800 50  0001 C CNN
F 1 "+12V" H 6050 1090 50  0000 C CNN
F 2 "" H 6050 950 50  0000 C CNN
F 3 "" H 6050 950 50  0000 C CNN
	1    6050 950 
	-1   0    0    1   
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR033
U 1 1 57911382
P 5950 950
F 0 "#PWR033" H 5950 700 50  0001 C CNN
F 1 "GND" H 5950 800 50  0000 C CNN
F 2 "" H 5950 950 50  0000 C CNN
F 3 "" H 5950 950 50  0000 C CNN
	1    5950 950 
	1    0    0    -1  
$EndComp
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR034
U 1 1 579199CD
P 6725 1150
F 0 "#PWR034" H 6725 900 50  0001 C CNN
F 1 "GND" H 6725 1000 50  0000 C CNN
F 2 "" H 6725 1150 50  0000 C CNN
F 3 "" H 6725 1150 50  0000 C CNN
	1    6725 1150
	-1   0    0    1   
$EndComp
Wire Wire Line
	1450 6850 2225 6850
Wire Wire Line
	1450 6950 2225 6950
Wire Wire Line
	1450 7050 2225 7050
Wire Wire Line
	1450 7150 2225 7150
Wire Wire Line
	1450 7250 2225 7250
Wire Wire Line
	1450 7350 2225 7350
Wire Wire Line
	3250 6450 4775 6450
Wire Wire Line
	3250 6350 4825 6350
Wire Wire Line
	3250 6250 4850 6250
Wire Wire Line
	3250 6150 4875 6150
Wire Wire Line
	2025 6250 2225 6250
Wire Wire Line
	2150 6450 2150 6700
Wire Wire Line
	3325 5850 3250 5850
Wire Wire Line
	3250 7150 5250 7150
Wire Wire Line
	3250 7050 5800 7050
Wire Wire Line
	3250 6950 5100 6950
Wire Wire Line
	3250 7350 5200 7350
Wire Wire Line
	3250 7250 5225 7250
Wire Wire Line
	2025 4975 2025 6250
Wire Wire Line
	2150 6450 2225 6450
Wire Wire Line
	2150 6550 2225 6550
Connection ~ 2150 6550
Wire Notes Line
	4075 5400 3625 5400
Wire Notes Line
	3625 5400 3625 4900
Wire Notes Line
	4075 7650 1375 7650
Wire Wire Line
	2200 2275 2200 2175
Wire Wire Line
	2200 2175 3100 2175
Wire Wire Line
	2200 2925 2200 2775
Wire Wire Line
	2200 2775 3100 2775
Wire Wire Line
	2200 3625 2200 3475
Wire Wire Line
	2200 3475 3100 3475
Wire Wire Line
	2200 4325 2200 4175
Wire Wire Line
	2200 4175 3100 4175
Wire Wire Line
	1850 1075 5100 1075
Wire Wire Line
	850  1375 5200 1375
Wire Wire Line
	3900 2175 4800 2175
Wire Wire Line
	4800 2175 4800 4225
Wire Wire Line
	4800 4225 5800 4225
Wire Wire Line
	3900 2775 4650 2775
Wire Wire Line
	4650 2775 4650 4325
Wire Wire Line
	4650 4325 5250 4325
Wire Wire Line
	3900 3475 4550 3475
Wire Wire Line
	4550 3475 4550 4425
Wire Wire Line
	4550 4425 5225 4425
Wire Wire Line
	4000 4175 4000 4525
Wire Wire Line
	4000 4525 5200 4525
Wire Wire Line
	975  4325 1125 4325
Connection ~ 1650 1375
Wire Wire Line
	1550 1125 1050 1125
Wire Wire Line
	3900 4175 4000 4175
Wire Wire Line
	5100 1075 5100 975 
Wire Wire Line
	5100 975  5200 975 
Wire Wire Line
	5200 1375 5200 1575
Wire Wire Line
	5200 1575 5350 1575
Wire Wire Line
	5700 2675 6000 2675
Wire Wire Line
	5700 3175 5700 2675
Wire Wire Line
	4875 3175 5700 3175
Wire Wire Line
	5750 2775 6000 2775
Wire Wire Line
	5750 3275 5750 2775
Wire Wire Line
	4850 3275 5750 3275
Wire Wire Line
	5700 3325 6000 3325
Wire Wire Line
	5700 3375 5700 3325
Wire Wire Line
	4825 3375 5700 3375
Wire Wire Line
	5650 3425 6000 3425
Wire Wire Line
	5650 3475 5650 3425
Wire Wire Line
	5200 4525 5200 7350
Wire Wire Line
	5225 4425 5225 7250
Wire Wire Line
	5250 4325 5250 7150
Wire Wire Line
	5800 4225 5800 7050
Wire Wire Line
	4775 6450 4775 3475
Wire Wire Line
	4825 6350 4825 3375
Wire Wire Line
	4850 6250 4850 3275
Wire Wire Line
	4875 6150 4875 3175
Wire Wire Line
	4775 3475 5650 3475
Wire Wire Line
	1550 1125 1550 1025
Wire Wire Line
	1850 1075 1850 950 
Wire Wire Line
	1850 950  1650 950 
Wire Wire Line
	1650 950  1650 1075
Wire Wire Line
	1550 1025 1650 1025
Connection ~ 1650 1025
Wire Wire Line
	5200 975  5200 925 
Wire Wire Line
	5200 925  5350 925 
Wire Wire Line
	5350 925  5350 975 
Wire Wire Line
	950  2925 1100 2925
Wire Wire Line
	1125 2275 975  2275
Wire Wire Line
	2225 6350 1900 6350
Wire Wire Line
	1900 6350 1900 4975
Wire Wire Line
	5100 6950 5100 6200
Wire Wire Line
	5100 6200 7750 6200
Wire Wire Line
	3250 6850 5075 6850
Wire Wire Line
	5075 6850 5075 5475
Wire Wire Line
	5075 5475 7775 5475
Wire Wire Line
	3250 6750 5050 6750
Wire Wire Line
	5050 6750 5050 4825
Wire Wire Line
	5050 4825 7800 4825
Wire Wire Line
	3250 6650 5000 6650
Wire Wire Line
	5000 6650 5000 4300
Wire Wire Line
	5000 4300 6800 4300
Wire Wire Line
	6800 4225 7800 4225
Wire Wire Line
	6800 4300 6800 4225
Wire Wire Line
	6800 4825 6800 4825
Wire Wire Line
	6775 5475 6775 5475
Wire Wire Line
	6750 6200 6750 6200
Wire Wire Line
	6775 1975 6900 1975
Wire Wire Line
	8100 1975 8225 1975
Wire Wire Line
	8100 1975 8100 1950
Wire Wire Line
	9275 1975 9375 1975
Wire Wire Line
	10400 1950 10525 1950
Wire Wire Line
	5650 1975 6475 1975
Wire Wire Line
	8925 1725 8925 2100
Wire Wire Line
	7575 1950 7575 2600
Wire Wire Line
	8175 4225 8175 2975
Wire Wire Line
	8175 2975 7100 2975
Wire Wire Line
	7100 2975 7100 2275
Wire Wire Line
	8100 4825 8425 4825
Wire Wire Line
	8425 4825 8425 2275
Wire Wire Line
	8075 5475 9575 5475
Wire Wire Line
	9575 5475 9575 2275
Wire Wire Line
	7575 1950 7800 1950
Wire Wire Line
	8975 1975 8925 1975
Wire Wire Line
	10725 2250 10725 6200
Wire Wire Line
	10725 6200 8050 6200
Connection ~ 6375 1975
Wire Wire Line
	6775 1875 6825 1875
Wire Wire Line
	6825 1875 6825 1975
Connection ~ 6825 1975
Wire Wire Line
	7725 1150 7725 1950
Connection ~ 7725 1950
Connection ~ 8175 1975
Connection ~ 8925 1975
Wire Wire Line
	9325 1650 9325 1975
Connection ~ 9325 1975
Connection ~ 10450 1950
Wire Wire Line
	8175 1650 8175 1975
Wire Wire Line
	7850 1650 8175 1650
Wire Wire Line
	8975 1650 9325 1650
Wire Wire Line
	10350 1575 10350 1650
Wire Wire Line
	8575 875  8575 775 
Wire Wire Line
	8100 4225 8175 4225
Wire Wire Line
	6000 2575 5950 2575
Wire Wire Line
	6000 2875 5950 2875
Wire Wire Line
	6000 3225 5950 3225
Wire Wire Line
	6000 3525 5950 3525
Wire Wire Line
	6275 1150 6275 1750
Wire Wire Line
	6275 1750 6375 1750
Wire Wire Line
	6375 1750 6375 1975
Wire Wire Line
	6775 1875 6775 1675
Wire Wire Line
	6775 1675 6525 1675
Wire Wire Line
	6525 1675 6525 1550
Wire Wire Line
	6775 1550 7450 1550
Wire Wire Line
	7450 1550 7450 775 
Wire Wire Line
	7450 775  8375 775 
Wire Wire Line
	6275 1150 6525 1150
Wire Wire Line
	7725 1150 7850 1150
Wire Wire Line
	7850 1650 7850 1550
Wire Wire Line
	8100 1550 8475 1550
Wire Wire Line
	8475 1550 8475 775 
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR035
U 1 1 57932E4D
P 8050 1150
F 0 "#PWR035" H 8050 900 50  0001 C CNN
F 1 "GND" H 8050 1000 50  0000 C CNN
F 2 "" H 8050 1150 50  0000 C CNN
F 3 "" H 8050 1150 50  0000 C CNN
	1    8050 1150
	-1   0    0    1   
$EndComp
Wire Wire Line
	8925 1725 8725 1725
Wire Wire Line
	8725 1725 8725 1075
Wire Wire Line
	8725 1075 8975 1075
Wire Wire Line
	8975 1075 8975 1125
Wire Wire Line
	8975 1650 8975 1525
Wire Wire Line
	9225 1525 9475 1525
Wire Wire Line
	9475 1525 9475 875 
Wire Wire Line
	9475 875  8575 875 
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR036
U 1 1 5793E038
P 9175 1125
F 0 "#PWR036" H 9175 875 50  0001 C CNN
F 1 "GND" H 9175 975 50  0000 C CNN
F 2 "" H 9175 1125 50  0000 C CNN
F 3 "" H 9175 1125 50  0000 C CNN
	1    9175 1125
	-1   0    0    1   
$EndComp
Wire Wire Line
	10100 1950 10050 1950
Wire Wire Line
	10050 1575 10100 1575
Wire Wire Line
	10350 1650 10625 1650
Wire Wire Line
	10625 1650 10625 775 
Wire Wire Line
	10625 775  8675 775 
Wire Wire Line
	10050 1750 10050 2075
Wire Wire Line
	10050 1750 9850 1750
Wire Wire Line
	9850 1750 9850 1075
Wire Wire Line
	9850 1075 10100 1075
Wire Wire Line
	10100 1075 10100 1175
Connection ~ 10050 1950
Wire Wire Line
	10450 1950 10450 1700
Wire Wire Line
	10450 1700 10050 1700
Wire Wire Line
	10050 1700 10050 1575
Wire Wire Line
	1500 2075 1450 2075
Wire Wire Line
	1450 2075 1450 2050
Wire Wire Line
	2200 2075 2250 2075
Wire Wire Line
	2250 2075 2250 2050
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR037
U 1 1 5798C4F4
P 2250 2050
F 0 "#PWR037" H 2250 1900 50  0001 C CNN
F 1 "+5V" H 2250 2190 50  0000 C CNN
F 2 "" H 2250 2050 50  0000 C CNN
F 3 "" H 2250 2050 50  0000 C CNN
	1    2250 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2575 2275 2675 2275
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR038
U 1 1 5798C7E9
P 2675 2275
F 0 "#PWR038" H 2675 2025 50  0001 C CNN
F 1 "GND" H 2675 2125 50  0000 C CNN
F 2 "" H 2675 2275 50  0000 C CNN
F 3 "" H 2675 2275 50  0000 C CNN
	1    2675 2275
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 2725 1425 2725
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR039
U 1 1 5798D2D7
P 2300 2725
F 0 "#PWR039" H 2300 2575 50  0001 C CNN
F 1 "+5V" H 2300 2865 50  0000 C CNN
F 2 "" H 2300 2725 50  0000 C CNN
F 3 "" H 2300 2725 50  0000 C CNN
	1    2300 2725
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2725 2300 2725
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR040
U 1 1 5798D53C
P 2575 2925
F 0 "#PWR040" H 2575 2675 50  0001 C CNN
F 1 "GND" H 2575 2775 50  0000 C CNN
F 2 "" H 2575 2925 50  0000 C CNN
F 3 "" H 2575 2925 50  0000 C CNN
	1    2575 2925
	0    -1   -1   0   
$EndComp
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR041
U 1 1 5798F307
P 2300 3425
F 0 "#PWR041" H 2300 3275 50  0001 C CNN
F 1 "+5V" H 2300 3565 50  0000 C CNN
F 2 "" H 2300 3425 50  0000 C CNN
F 3 "" H 2300 3425 50  0000 C CNN
	1    2300 3425
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3425 2300 3425
Wire Wire Line
	1400 3425 1500 3425
Wire Wire Line
	975  3625 1125 3625
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR042
U 1 1 5798F7F0
P 2700 3625
F 0 "#PWR042" H 2700 3375 50  0001 C CNN
F 1 "GND" H 2700 3475 50  0000 C CNN
F 2 "" H 2700 3625 50  0000 C CNN
F 3 "" H 2700 3625 50  0000 C CNN
	1    2700 3625
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2575 3625 2700 3625
Wire Wire Line
	1375 4125 1500 4125
$Comp
L +5V-RESCUE-Arduino_As_Uno #PWR043
U 1 1 57994F34
P 2325 4125
F 0 "#PWR043" H 2325 3975 50  0001 C CNN
F 1 "+5V" H 2325 4265 50  0000 C CNN
F 2 "" H 2325 4125 50  0000 C CNN
F 3 "" H 2325 4125 50  0000 C CNN
	1    2325 4125
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 4125 2325 4125
Wire Wire Line
	2575 4325 2675 4325
$Comp
L GND-RESCUE-Arduino_As_Uno #PWR044
U 1 1 579952B3
P 2675 4325
F 0 "#PWR044" H 2675 4075 50  0001 C CNN
F 1 "GND" H 2675 4175 50  0000 C CNN
F 2 "" H 2675 4325 50  0000 C CNN
F 3 "" H 2675 4325 50  0000 C CNN
	1    2675 4325
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1425 4325 1500 4325
Wire Wire Line
	2200 4325 2275 4325
Wire Wire Line
	2275 3625 2200 3625
Wire Wire Line
	1425 3625 1500 3625
Wire Wire Line
	2275 2925 2200 2925
Wire Wire Line
	1500 2925 1400 2925
Wire Wire Line
	1425 2275 1500 2275
Wire Wire Line
	2275 2275 2200 2275
$EndSCHEMATC