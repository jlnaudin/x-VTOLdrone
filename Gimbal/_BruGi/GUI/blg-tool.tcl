#!/usr/bin/wish
#
# Copyright by Oliver Dippel <oliver@multixmedia.org>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# any later version. see <http://www.gnu.org/licenses/>
# 

set VERSION 49

#####################################################################################
# Big hexdata
#####################################################################################

set HEXDATA ""

image create photo logo -data {
R0lGODlhyAA2APcAAFxbV1tbW3RsX3hsX2NjY25uZ25sbH9nZ3NsZnpuZXJra3tsanlxZXZzbXty
a21tc21sfHFrc3BsfmxxdWxze3Nzc3t1cnR6d314cXN0fHV5e3x7e4JtZoNtaY5sbod2Z4RzbYlx
bod7aIt8bZB4bo1vcYlxc4R5cYp+dIN+e5V+dZR+eo6FdI6EeZKEdZyBd5eIcZGFepWKfp2Me6yP
c6qQc6SSfmxtgXJqgW91g2x9hG16iHR2gnZ7hHp9g3V6inl9i3yBhneBiHyDjH6Ij3qIkHmGmn6M
mYSEhYiFgoSDi4GMj42NjZeHgpWMhJyMhJCLip2ThZSRi5yUiJ+ejIKHlYmHl4SJkoiNkISGmoOM
m4qJm4WRnoyUnJWVlZuYk5OXnJubnKGUg66TgKSYh62ag6Wai62cjaWblKedma+gj7Clj66ikayl
ma+pmbWik7qlkreqlbqplbWlm7qnmLapm7iqnrGwmIKNoIiNpIaSpIiQoo6Zp4SQqJKUo5Sdq5Kf
spOkrZqhrZ2msJurtpumupqsu52yvamloKGkq6Wqr6mrrLiqoryxorSzrb2+rqWqsKqtsqOtvKqv
v66xtaKwurKztrO1ubW5vL29v8Ctnca1mMKxpMq5psCzqcO9rMy9rc2+sdC/stTEr9LEs9jHsdvI
tNXMut7PuOHUvKevwqS1xqy2xKe5wqu6xaOzy6e/zKq7yrC8xru+wq7Cz77AxavI1rPF07DI0r3P
3b7R1cLExcLEyc3Nz9HR0ePWxOjXxOPaxOnbxM7i3+zgxOvizfDkzu7l0PHo1s7j6tHj5dHm69Ho
6/385f776eP0+gAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACH5BAEAANAALAAAAADIADYA
AAj+AKEJHEiwoMGDCBMqXMiwocOHECNKnEixosWLGDNq3Mixo8ePIEOKHEmypMmTKFOqXMmypcuX
MGPKnEmzps2bOHPq3Mmzp8+fQIMKHUq0qNGjSJMqXcq0qdOnODNBW7TBAAECBgwEgcp1YyZLvbwE
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
}


image create photo sensor -data {
R0lGODlheABmAOf8ACQlJiUmKScoKysrLSgpJy4wLzExLi0uMjEvMy8wMy4yOTIzNTY4Nzk5NjU2
OTc4Ozo7PTk3OjEvLBwdH0c9PFg9OFI6L3I6Mz5BPz5GN0FBPklFOlhEOlVRPWRIO3RLOz0+QTg7
Q0I+REk+ST9BQz1IRzlVVEJDRUtEREVJRkpKRkVFSUpFS0ZJTEpLTVNFQ1JNTFhKR05RTkdSSlJS
TVlTSkZMUkxNUkpJVlJNU1ZMVk5RU0xTW0hVV1NTVFpUVFZYVlpZVlRVWVtUW1ZZW1tbXGVKR2dT
SXdVSmNcW2hYV3ZbWHJNRl1hXlVlXEZgX2JiXmpjXXhjW21gTktaYl1eYVZZY2JdZGpeZ3Jeal5h
Y11laltoaFZsbmNjZGtkZGVpZmtqZmVlaWpla2Vpa2trbHJsbHdoZ25xbmVxbHJybnlybWVtcmxt
cmhpdHJtdHdqdW5xdG1zemh0dXNzdHp0c3Z4dXt6dXR1eXd4e3t7fHp1fJ1YNdBnPYhZSo5dU61c
T4hkW5hnWJJqVKlpWLVpV7hzWbBoT4dpZpdsZ4h0bpd1a4J+e4V4dZZ6dotscad4aLh4Z614co1f
YchqVsh1V9FvTMZ5Zcp1a8BeQ36AfXiDd4KCfoqFe5yLfrWGebSGdMqKdOWHZ31+gXR3hGdugYh9
gn+AgoODhIuKhYWGiYeIiouLjIiHhJGOipWKhI6RjpOSjZmVjI2OkY+QkpOUlJualZWWmZeYmpuc
nJiXlJeMkLWKhbiVi6Obl7aal6ePiZ6gnqSinauhmbmhmp2eoZ+goqOjpKusq6iop7iqp7S0s7q5
uLGvrsiViNWVicicls+RjMijmdanl9KtlcSrp9m3qse7uM6zreS4ruSjmc7EuerIu8jIx9TSzdTU
09zc3NnY1tXMx+jVyPjYyufb2PDRy9zi3Prm2e/q2uTk4+zs6+vo5vjr5+vz7PXz7f707P777Pv4
5u39/O369/X19Pz29PT79fz79fX1+/32/PX8/f////nu9t/g5MC/wSH+EUNyZWF0ZWQgd2l0aCBH
SU1QACH5BAEKAP0ALAAAAAB4AGYAAAj+APsJHEiwoMGDCBMqXMiwocOHECNKnEixosWLGBOq+5ax
o8ePCsNx8oEhD8iTKC+GW5UiRQMNGvS4S0mzpkJvqVycOMGgAQSXumwKtRmvWxgVGjCAeMDgAYQH
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
}

#####################################################################################
# Tooltip
#####################################################################################

proc setTooltip {widget text} {
	if { $text != "" } {

		bind $widget <Any-Enter>    [list .helptext configure -text "$text"]

#		bind $widget <Any-Enter>    [list after 500 [list showTooltip %W $text]]
#		bind $widget <Any-Leave>    [list after 500 [list destroy %W.tooltip]]
#		bind $widget <Any-KeyPress> [list after 500 [list destroy %W.tooltip]]
#		bind $widget <Any-Button>   [list after 500 [list destroy %W.tooltip]]
	}
}

proc showTooltip {widget text} {
	global tcl_platform
	if { [string match $widget* [winfo containing  [winfo pointerx .] [winfo pointery .]] ] == 0  } {
		return
	}
	catch { destroy $widget.tooltip }
	set scrh [winfo screenheight $widget]    ; # 1) flashing window fix
	set scrw [winfo screenwidth $widget]     ; # 1) flashing window fix
	set tooltip [toplevel $widget.tooltip -bd 1 -bg black]
	wm geometry $tooltip +$scrh+$scrw        ; # 1) flashing window fix
	wm overrideredirect $tooltip 1
	if {$tcl_platform(platform) == {windows}} { ; # 3) wm attributes...
		wm attributes $tooltip -topmost 1   ; # 3) assumes...
	}                                           ; # 3) Windows
	pack [label $tooltip.label -bg lightyellow -fg black -text $text -justify left]
	set width [winfo reqwidth $tooltip.label]
	set height [winfo reqheight $tooltip.label]
	set pointer_below_midline [expr [winfo pointery .] > [expr [winfo screenheight .] / 2.0]]                ; # b.) Is the pointer in the bottom half of the screen?
	set positionX [expr [winfo pointerx .] - round($width / 2.0)]    ; # c.) Tooltip is centred horizontally on pointer.
	set positionY [expr [winfo pointery .] + 35 * ($pointer_below_midline * -2 + 1) - round($height / 2.0)]  ; # b.) Tooltip is displayed above or below depending on pointer Y position.
	if  {[expr $positionX + $width] > [winfo screenwidth .]} {
		set positionX [expr [winfo screenwidth .] - $width]
	} elseif {$positionX < 0} {
		set positionX 0
	}
	wm geometry $tooltip [join  "$width x $height + $positionX + $positionY" {}]
	raise $tooltip
	bind $widget.tooltip <Any-Enter> {destroy %W}
	bind $widget.tooltip <Any-Leave> {destroy %W}
}

#####################################################################################
# Menu
#####################################################################################

menu .menu -tearoff 0
menu .menu.file -tearoff 0
.menu add cascade -label "File" -menu .menu.file -underline 0

	.menu.file add command -label "Connect" -command {
		connect_serial
	}
	.menu.file add command -label "Close" -command {
		close_serial
	}
	.menu.file add command -label "Open file..." -command {
		load_values_from_file
	}
	.menu.file add command -label "Save file..." -command {
		save_values2file
	}
	.menu.file add separator
	.menu.file add command -label "Exit" -command {
		exit 0
	}

menu .menu.options -tearoff 0
.menu add cascade -label "Options" -menu .menu.options -underline 0
	.menu.options add command -label "set Defaults" -command {
		set_defaults
	}
	.menu.options add command -label "Load from Board" -command {
		send_par
	}
	.menu.options add command -label "Save to Board" -command {
		save_values
	}
	.menu.options add command -label "Load from Flash" -command {
		load_from_flash
	}
	.menu.options add command -label "Save to Flash" -command {
		save_to_flash
	}
	.menu.options add command -label "Gyro-Cal" -command {
		gyro_cal
	}

if {$HEXDATA != ""} {
	menu .menu.firmware -tearoff 0
	.menu add cascade -label "Firmware" -menu .menu.firmware -underline 0
		.menu.firmware add command -label "Upload" -command {
			close_serial
			set device [.device.spin get]
			set ArduinoSerial [ArduinoSerial_Init [.device.spin get] 57600]
			ArduinoReset
			ArduinoSerial_SendCMD $defs(STK_GET_SIGN_ON)
			if {$ArduinoTimeout != 0} {
				.bottom.info configure -text "ERROR: upload firmware"
				.bottom.info configure -background red
				update
				after 1000
			} else {
				.bottom.info configure -text "start uploading firmware"
				ArduinoSendData "0x0000" $HEXDATA
				ArduinoReset
			}
			after 500
			connect_serial
		}
}


menu .menu.help -tearoff 0
	.menu add cascade -label "Help" -menu .menu.help -underline 0
	.menu.help add command -label "Tuning" -command {
		show_help_tuning
	}
	.menu.help add separator
	.menu.help add command -label "Homepage" -command {
		launchBrowser "http://brushlessgimbal.de/"
	}
	.menu.help add command -label "Documentation" -command {
		launchBrowser "http://brushlessgimbal.de/brugi-v1/software/"
	}
	.menu.help add separator
	.menu.help add command -label "About..." -command {
		show_help_about
	}

. configure -menu .menu

#####################################################################################
# serialports
#####################################################################################

if {[string match "*Linux*" $tcl_platform(os)]} {
	set comports ""
	set device ""
	catch {
		set comports "[glob /dev/ttyUSB*] [glob /dev/ttyACM*]"
		set device "[lindex $comports end]"
	}
} elseif {[string match "*Windows*" $tcl_platform(os)]} {
	set comports {"com1:" "com2:" "com3:" "com4:" "com5:" "com6:" "com7:" "com8:" "com9:" "com10:" "com11:" "com12:" "com13:" "com14:" "com15:"}
	catch {
		set serial_base "HKEY_LOCAL_MACHINE\\HARDWARE\\DEVICEMAP\\SERIALCOMM"
		set values [registry values $serial_base]
		set res {}
#		foreach valueName $values {
#			set PortName "[registry get $serial_base $valueName]"
#			lappend res "$PortName"
#		}
		foreach valueName $values {
			set PortName "//./[registry get $serial_base $valueName]"
			lappend res "$PortName"
		}
		set comports $res
	}
	set device "[lindex $comports end]"
} elseif {[string match "*Darwin*" $tcl_platform(os)] || [string match "*MacOS*" $tcl_platform(os)]} {
	set comports ""
	set device ""
	catch {
		set comports [glob /dev/cu.usbserial-*]
		set device "[lindex $comports end]"
	}
}

#####################################################################################
# Global variables
#####################################################################################

set Serial 0
set LastValX 0
set LastValY 0
set chart 0
set params "gyroPitchKp gyroPitchKi gyroPitchKd gyroRollKp gyroRollKi gyroRollKd accTimeConstant mpuLPF angleOffsetPitch angleOffsetRoll dirMotorPitch dirMotorRoll motorNumberPitch motorNumberRoll maxPWMmotorPitch maxPWMmotorRoll minRCPitch maxRCPitch minRCRoll maxRCRoll rcGain rcLPF rcModePPM rcChannelPitch rcChannelRoll rcMid rcAbsolute accOutput enableGyro enableACC axisReverseZ axisSwapXY"

foreach var $params {
	if {$var == "vers"} {
	} elseif {! [string match "*,*" $var]} {
		set par($var) 0
		set par($var,scale) 1
		set par($var,offset) 0
	}
}


set par(gyroPitchKp,scale) 1000.0
set par(gyroPitchKi,scale) 1000.0
set par(gyroPitchKd,scale) 1000.0
set par(gyroRollKp,scale) 1000.0
set par(gyroRollKi,scale) 1000.0
set par(gyroRollKd,scale) 1000.0
set par(angleOffsetPitch,scale) 100.0
set par(angleOffsetRoll,scale) 100.0
set par(rcLPF,scale) 10.0
set par(maxPWMmotorPitch,scale) 2.5
set par(maxPWMmotorRoll,scale) 2.5
set par(rcChannelPitch,offset) 1
set par(rcChannelRoll,offset) 1
set par(motorNumberPitch,offset) 1
set par(motorNumberRoll,offset) 1



set CHART_SCALE 0.5
set buffer ""
set count 0
set chart_count 0

#####################################################################################
# Serial-Functions
#####################################################################################

proc Serial_Init {ComPort ComRate} {
	global Serial
	catch {close $Serial}
	catch {fileevent $Serial readable ""}
	set iChannel 0
	if {[catch {
		set iChannel [open $ComPort w+]
		fconfigure $iChannel -mode $ComRate,n,8,1 -ttycontrol {RTS 1 DTR 0} -blocking FALSE
		fileevent $iChannel readable [list rd_chid $iChannel]
		.bottom.version configure -text "Serial-Ok: $ComPort @ $ComRate"
		.bottom.info configure -text "Serial-Ok: $ComPort @ $ComRate"
		.device.connect configure -text "Reconnect"
	}]} {
		.bottom.version configure -text "Serial-Error: $ComPort @ $ComRate"
		.bottom.version configure -background red
		.bottom.info configure -text "Serial-Error: $ComPort @ $ComRate"
		.device.connect configure -text "Connect"
		return 0
	}
	return $iChannel
}

proc close_serial {} {
	global Serial
	catch {close $Serial}
	.device.connect configure -text "Connect"
}

#####################################################################################
# CLI-Functions
#####################################################################################

proc connect_serial {} {
	global Serial
	global count
	global device
	global buffer
#	.bottom.info configure -background yellow
	set device [.device.spin get]
	set Serial [Serial_Init $device 115200]
	set count 0
	if {$Serial == 0} {
		.bottom.info configure -background red
		.bottom.info configure -text "not connected"
		return
	} else {
		.bottom.info configure -background green
		.bottom.info configure -text "connected"
	}
	after 6000 send_par
}

proc draw_chart {} {
	global Serial
	global chart
	if {$Serial == 0} {
		.bottom.info configure -background red
		.bottom.info configure -text "not connected"
		return
	}
	if {$chart == 1} {
		set chart 0
		.bottom.info configure -text "SEND: oac 0"
        	puts -nonewline $Serial "oac 0\n"
		flush $Serial
		.note.general.chart.fr1.button configure -text "Start"
	} else {
		set chart 1
		.bottom.info configure -text "SEND: oac 1"
        	puts -nonewline $Serial "oac 1\n"
		flush $Serial
		.note.general.chart.fr1.button configure -text "Stop"
	}
}

proc send_parvar {n1 n2 op} {
	global Serial
	global par

	if {$Serial == 0} {
		.bottom.info configure -background red
		.bottom.info configure -text "not connected"
		return
	}
	if {$n2 == "vers"} {
	} elseif {$n2 == "dirMotorPitch" || $n2 == "dirMotorRoll"} {
		if {$par($n2) == 1} {
			.bottom.info configure -text "SEND: par $n2 -1"
		        puts -nonewline $Serial "par $n2 -1\n"
		} else {
			.bottom.info configure -text "SEND: par $n2 1"
		        puts -nonewline $Serial "par $n2 1\n"
		}
	} else {
		.bottom.info configure -text "SEND: par $n2 [expr $par($n2) * $par($n2,scale) - $par($n2,offset)]"
	        puts -nonewline $Serial "par $n2 [expr $par($n2) * $par($n2,scale) - $par($n2,offset)]\n"
	}
	flush $Serial
	after 20
}

proc send_par {} {
	global Serial
	global count
	global device
	global buffer
	set count 0
	set buffer ""
	if {$Serial == 0} {
		.bottom.info configure -background red
		.bottom.info configure -text "not connected"
		return
	}
	.bottom.info configure -text "PAR: reading values..."

        puts -nonewline $Serial "par\n"
	flush $Serial
}

proc save_values {} {
	global Serial
	global count
	global device
	global par
	.bottom.info configure -text "saving values"
	.bottom.info configure -background yellow
	update
	if {$Serial == 0} {
		.bottom.info configure -background red
		.bottom.info configure -text "not connected"
		return
	}
	foreach var [array names par] {
		if {$var == "vers"} {
		} elseif {! [string match "*,*" $var]} {
			send_parvar "par" $var "w"
			after 20
		}
	}
	.bottom.info configure -text "saving values done"
	.bottom.info configure -background green
}

proc load_values_from_file {} {
	global Serial
	set types {
		{"Text files"		{.txt}	}
		{"Text files"		{}		TEXT}
		{"All files"		*}
	}
	global selected_type
	if {![info exists selected_type]} {
		set selected_type "Tcl Scripts"
	}
	set file [tk_getOpenFile -filetypes $types -parent . -typevariable selected_type]
	if {$file != ""} {
		set fp [open $file r]
		if {$fp > 0} {
			set file_data [read $fp]
			close $fp
			foreach line "[split $file_data "\n"]" {
				if {$line != ""} {
				        puts $Serial "$line"
					flush $Serial
					after 20
				}
			}
			.bottom.info configure -text "load: done"
			update
			connect_serial
		} else {
			.bottom.info configure -text "load: error, reading file: $file"
			update
		}
	}
	after 200 send_par
}

proc save_values2file {} {
	global Serial
	global device
	global par
	set types {
		{"Text files"		{.txt}	}
		{"Text files"		{}		TEXT}
		{"All files"		*}
	}
	set file [tk_getSaveFile -filetypes $types -parent . -initialfile blg-gimbal -defaultextension .txt]
	if {$file != ""} {
		set fp [open $file w]
		foreach var [array names par] {
			if {$var == "vers"} {
			} elseif {! [string match "*,*" $var]} {
				if {$var == "dirMotorPitch" || $var == "dirMotorRoll"} {
					if {$par($var) == 1} {
					        puts -nonewline $fp "par $var -1\n"
					} else {
					        puts -nonewline $fp "par $var 1\n"
					}
				} else {
				        puts -nonewline $fp "par $var [expr $par($var) * $par($var,scale) - $par($var,offset)]\n"
				}
			}
		}
		close $fp
	}
}

proc gyro_cal {} {
	global Serial
	global count
	global device
	set count 0
	if {$Serial == 0} {
		.bottom.info configure -background red
		.bottom.info configure -text "not connected"
		return
	}
	.bottom.info configure -background red
	.bottom.info configure -text "gyro recalibration"
	update
        puts -nonewline $Serial "GC\n"
	flush $Serial
}

proc save_to_flash {} {
	global Serial
	global count
	global device
	set count 0
	if {$Serial == 0} {
		.bottom.info configure -background red
		.bottom.info configure -text "not connected"
		return
	}
        puts -nonewline $Serial "WE\n"
	flush $Serial
}

proc load_from_flash {} {
	global Serial
	global count
	global device
	set count 0
	.bottom.info configure -text "loading from flash"
	update
	if {$Serial == 0} {
		.bottom.info configure -background red
		.bottom.info configure -text "not connected"
		return
	}
        puts -nonewline $Serial "RE\n"
	flush $Serial
	after 200 send_par
}

proc set_defaults {} {
	global Serial
	global count
	global device
	set count 0
	.bottom.info configure -text "setting defaults"
	update
	if {$Serial == 0} {
		.bottom.info configure -background red
		.bottom.info configure -text "not connected"
		return
	}
        puts -nonewline $Serial "SD\n"
	flush $Serial
	after 200 send_par
}

#####################################################################################
# Serial-Calback
#####################################################################################

proc rd_chid {chid} {
	global buffer
	global count
	global chart_count
	global VERSION
	global par
	if {$chid == 0} {
		return
	}
#	catch {
		set ch [read $chid 1]
		if {$ch == "\r"} {
		} elseif {$ch == "\n"} {
			if {1 == 1} {
				.bottom.info configure -text "INFO: $buffer"
#				update
				set var [lindex $buffer 0]
				set val [lindex $buffer 1]

				if {$var == "vers"} {
					set par(vers) "$val"
					.bottom.version configure -text "Firmware-Version: $par(vers)"
					.bottom.version configure -background lightgray
				} elseif {$var == "dirMotorPitch" || $var == "dirMotorRoll"} {
					if {$val == -1} {
						set par($var) 1
					} else {
						set par($var) 0
					}

				} elseif {[info exists par($var,scale)]} {
					set par($var) [expr ($val + $par($var,offset)) / $par($var,scale)]
				} elseif {[string match "* ACC *" $buffer]} {
					set chart 1
					.bottom.info configure -text "OAC: $buffer"
					global LastValX
					global LastValY
					global CHART_SCALE
					set ValX [expr [lindex $buffer 0] / 1000.0]
					set TEST [lindex $buffer 1]
					set ValY [expr [lindex $buffer 2] / 1000.0]
					if {($TEST == "ACC" || $TEST == "DMP") && [string is double -strict $ValX] && [string is double -strict $ValY]} {
						incr chart_count 1
						if {$chart_count >= 450} {
							set chart_count 0
						}
						.note.general.chart.chart1 delete "line_$chart_count"
						.note.general.chart.chart1 create line $chart_count [expr 100 - ($LastValX / 2 * $CHART_SCALE + 50)] [expr $chart_count + 1] [expr 100 - ($ValX * $CHART_SCALE / 2 + 50)] -fill orange -tags "line_$chart_count"
						.note.general.chart.chart1 create line $chart_count [expr 100 - ($LastValY / 2 * $CHART_SCALE + 50)] [expr $chart_count + 1] [expr 100 - ($ValY * $CHART_SCALE / 2 + 50)] -fill green -tags "line_$chart_count"
						.note.general.chart.chart1 delete "pos"
						.note.general.chart.chart1 create line [expr $chart_count + 1] 0 [expr $chart_count + 1] 100 -fill yellow -tags "pos"
						.note.general.chart.chart1 create text 5 10 -text "Pitch: $ValX" -anchor w -fill orange -tags "pos"
						.note.general.chart.chart1 create text 5 25 -text "Roll:  $ValY" -anchor w -fill green -tags "pos"
						.note.general.chart.chart1 create text 5 90 -text "Scale:  $CHART_SCALE" -anchor w -fill green -tags "pos"
						set LastValX $ValX
						set LastValY $ValY
					}

				} elseif {[string match "*recalibration: done*" $buffer]} {

					#tk_messageBox -icon info -message "Gyro-Recalibration done" -type ok -parent .
					.bottom.info configure -text "Gyro-Recalibration done"
					.bottom.info configure -background green
					update
				} elseif {[string match "* ddddd *" $buffer]} {
					.bottom.info configure -text "READY!"
					.bottom.info configure -background green
				} else {
				}
			}
			set buffer ""
		} else {
			append buffer $ch
		}
#	}
}

#####################################################################################
# Arduino-Flashloader
#####################################################################################

set defs(STK_OK)		"0x10"
set defs(STK_INSYNC)		"0x14"
set defs(STK_GET_SIGN_ON)	"0x30"
set defs(STK_LOAD_ADDRESS)	"0x55"
set defs(STK_READ_PAGE)		"0x74"
set defs(STK_WRITE_PAGE)	"0x64"
set defs(CRC_EOP)		"0x20"
set ArduinoTimeout 0

proc ArduinoSerial_Init {ComPort ComRate} {
	global ArduinoSerial
	catch {close $ArduinoSerial}
	set iChannel 0
	if {[catch {
		set iChannel [open $ComPort w+]
		fconfigure $iChannel -mode $ComRate,n,8,2 -translation binary -ttycontrol {RTS 1 DTR 0} -blocking FALSE
		.bottom.info configure -text "ArduinoSerial-OK: $ComPort @ $ComRate"
		update
	}]} {
		.bottom.info configure -text "ArduinoSerial-Error: $ComPort @ $ComRate"
		update
	}
	return $iChannel
}

proc ArduinoWait_reply {} {
	global ArduinoSerial
	global ArduinoTimeout
	global defs
	set num 0
	set num2 0
	set ch [read $ArduinoSerial 1]
	binary scan $ch c num
	set counter 0
	while {$num == 0 && $counter < 1000} {
		set ch [read $ArduinoSerial 1]
		binary scan $ch c num
		after 10
		incr counter
	}
	if {$counter >= 1000} {
		.bottom.info configure -text "#### timeout ####"
		update
		set ArduinoTimeout 1
		after 1000
		return
	}
	binary scan $ch c num
	set ch2 [read $ArduinoSerial 1]
	binary scan $ch2 c num2
	set counter 0
	while {$num2 == 0 && $counter < 1000} {
		set ch2 [read $ArduinoSerial 1]
		binary scan $ch2 c num2
		after 10
		incr counter
	}
	if {$counter >= 1000} {
		.bottom.info configure -text "#### timeout ####"
		update
		set ArduinoTimeout 1
		after 1000
		return
	}
	binary scan $ch2 c num2
	set ret "[format 0x%02x $num]"
	set ret2 "[format 0x%02x $num2]"
	if {$ret == $defs(STK_INSYNC) && $ret2 == $defs(STK_OK)} {
#		puts "	STK_INSYNC"
	} else {
		puts "Error: "
		puts "	< $ret"
		puts "	< $ret2"
		.bottom.info configure -text "Flash-Error"
		update
		after 1000
#		return
	}
}

proc ArduinoSerial_SendCMD {CMD} {
	global ArduinoSerial
	global defs
	puts -nonewline $ArduinoSerial "[binary format c $CMD]"
	flush $ArduinoSerial
	puts -nonewline $ArduinoSerial "[binary format c $defs(CRC_EOP)]"
	flush $ArduinoSerial
	ArduinoWait_reply
}

proc ArduinoReset {} {
	global ArduinoSerial
	fconfigure $ArduinoSerial -ttycontrol {RTS 0}
	flush $ArduinoSerial
	after 200
	fconfigure $ArduinoSerial -ttycontrol {RTS 1}
	flush $ArduinoSerial
	after 200
}

proc ArduinoSendWORD {WORD} {
	global ArduinoSerial
	global defs
	set WORD [expr $WORD / 2]
	set WORD_BYTE2 "0x[string range [format %04x $WORD] 2 3]"
	set WORD_BYTE1 "0x[string range [format %04x $WORD] 0 1]"
	puts -nonewline $ArduinoSerial "[binary format c $WORD_BYTE2]"
	flush $ArduinoSerial
	puts -nonewline $ArduinoSerial "[binary format c $WORD_BYTE1]"
	flush $ArduinoSerial
}

proc ArduinoSetAddr {ADDR} {
	global ArduinoSerial
	global defs
	puts -nonewline $ArduinoSerial "[binary format c $defs(STK_LOAD_ADDRESS)]"
	flush $ArduinoSerial
	ArduinoSendWORD "$ADDR"
	puts -nonewline $ArduinoSerial "[binary format c $defs(CRC_EOP)]"
	flush $ArduinoSerial
	ArduinoWait_reply
}

proc ArduinoSendData {START_ADDR file_data} {
	global ArduinoSerial
	global defs
	set BUFFER ""
	set COUNT 0
	if {$file_data != ""} {
		set MAX_ADDR [expr [llength $file_data]]
		foreach BYTE $file_data {
			lappend BUFFER "$BYTE"
			if {$COUNT == 127} {
				.bottom.info configure -text "write: [format 0x%02x $START_ADDR] ([expr [format 0x%x $START_ADDR] * 100 / [format 0x%x $MAX_ADDR]]%)"
				update
				ArduinoSetAddr "[format 0x%x $START_ADDR]"
				puts -nonewline $ArduinoSerial "[binary format c $defs(STK_WRITE_PAGE)]"
				flush $ArduinoSerial
				puts -nonewline $ArduinoSerial "[binary format c "0x0"]"
				flush $ArduinoSerial
				puts -nonewline $ArduinoSerial "[binary format c "0x80"]"
				flush $ArduinoSerial
				puts -nonewline $ArduinoSerial "F"
				flush $ArduinoSerial
				foreach SEND_BYTE $BUFFER {
					puts -nonewline $ArduinoSerial "[binary format c $SEND_BYTE]"
					flush $ArduinoSerial
				}
				puts -nonewline $ArduinoSerial "[binary format c $defs(CRC_EOP)]"
				flush $ArduinoSerial
				ArduinoWait_reply
				incr START_ADDR 128
				set BUFFER ""
				set COUNT 0
			} else {
				incr COUNT
			}
		}
		set NUM 0
		while {$NUM < [expr 128 - $COUNT]} {
			lappend BUFFER "0xFF"
			incr NUM
		}
		.bottom.info configure -text "write: [format 0x%02x $START_ADDR] ([expr [format 0x%x $START_ADDR] * 100 / [format 0x%x $MAX_ADDR]]%)"
		update
		ArduinoSetAddr "[format 0x%x $START_ADDR]"
		puts -nonewline $ArduinoSerial "[binary format c $defs(STK_WRITE_PAGE)]"
		flush $ArduinoSerial
		puts -nonewline $ArduinoSerial "[binary format c "0x0"]"
		flush $ArduinoSerial
		puts -nonewline $ArduinoSerial "[binary format c "0x80"]"
		flush $ArduinoSerial
		puts -nonewline $ArduinoSerial "F"
		flush $ArduinoSerial
		foreach SEND_BYTE $BUFFER {
			puts -nonewline $ArduinoSerial "[binary format c $SEND_BYTE]"
			flush $ArduinoSerial
		}
		puts -nonewline $ArduinoSerial "[binary format c $defs(CRC_EOP)]"
		flush $ArduinoSerial
		ArduinoWait_reply
		.bottom.info configure -text "write: done (100%)"
		update
	} else {
		.bottom.info configure -text "error no data found"
		update
		after 1000
	}
}

proc ArduinoConvertData {file_data} {
	global ArduinoSerial
	global defs
	set BUFFER ""
	if {$file_data != ""} {
		foreach BYTE [split $file_data ""] {
			binary scan $BYTE c num
			if {$num < 0} {
				set num [expr $num + 256]
			}
			lappend BUFFER "[format 0x%x $num]"
		}
		return $BUFFER
	} else {
		.bottom.info configure -text "error no data found"
		update
		after 1000
	}
}

proc ArduinoSendBIN {START_ADDR BINFILE} {
	global ArduinoSerial
	set binfile [open $BINFILE r]
	fconfigure $binfile -translation binary
	set file_data [read $binfile]
	close $binfile
	if {$file_data != ""} {
		ArduinoSendData $START_ADDR [ArduinoConvertData $file_data]
	} else {
		.bottom.info configure -text "error loading BIN-File"
		update
		after 1000
	}
}

proc ArduinoExportBIN {BINFILE} {
	set binfile [open $BINFILE r]
	fconfigure $binfile -translation binary
	set file_data [read $binfile]
	close $binfile
	if {$file_data != ""} {
		return "[ArduinoConvertData $file_data]"
	} else {
		.bottom.info configure -text "error loading BIN-File"
		update
		after 1000
	}
}

#####################################################################################
# GUI-Helper-Functions
#####################################################################################

set tline 0
proc show_textline {wid line} {
	global tline
	label $wid.tline_$tline -anchor nw -text "$line"
	pack $wid.tline_$tline -side top -expand yes -fill x
	incr tline
}

proc motorNumberPitch_check {n1 n2 op} {
	global par
	catch {
		if {$par(motorNumberPitch) == 1} {
			set par(motorNumberRoll) 2
		} else {
			set par(motorNumberRoll) 1
		}
	}
}
trace variable par(motorNumberPitch) w motorNumberPitch_check

proc motorNumberRoll_check {n1 n2 op} {
	global par
	catch {
		if {$par(motorNumberRoll) == 1} {
			set par(motorNumberPitch) 2
		} else {
			set par(motorNumberPitch) 1
		}
	}
}
trace variable par(motorNumberRoll) w motorNumberRoll_check

proc show_help {helptext} {
	tk_messageBox -icon info -message "$helptext" -type ok -parent .
}

proc gui_slider {wid variable min max step title tooltiptext helptext} {
	global par
	label $wid
	pack $wid -side top -expand yes -fill x
	setTooltip $wid "$tooltiptext"

		label $wid.label -text "$title" -width 14 -anchor w
		pack $wid.label -side left -expand no -fill x

		frame $wid.frame
		pack $wid.frame -side left -expand yes -fill x

			eval button $wid.frame.help -text \"?\" -width 1 -command \{show_help \"$helptext\"\}
			pack $wid.frame.help -side right -expand no -fill none

			spinbox $wid.frame.spin -from $min -to $max -increment $step -width 10 -textvariable par($variable) -width 4
			pack $wid.frame.spin -side right -expand yes -fill x

			scale $wid.frame.scale -orient horizontal -from $min -to $max -showvalue 0 -resolution $step -variable par($variable)
			pack $wid.frame.scale -side right -expand yes -fill x
}

proc gui_spin {wid variable min max step title tooltiptext helptext} {
	global par
	frame $wid
	pack $wid -side top -expand yes -fill x
	setTooltip $wid "$tooltiptext"

		label $wid.label -text "$title" -width 14 -anchor w
		pack $wid.label -side left -expand no -fill x

		frame $wid.frame
		pack $wid.frame -side left -expand yes -fill x

			eval button $wid.frame.help -text \"?\" -width 1 -command \{show_help \"$helptext\"\}
			pack $wid.frame.help -side right -expand no -fill none

			set diff [expr $max - $min]
			if {$diff <= 8} {
				set options ""
				set num $min
				while {$num <= $max}  {
					set options "$options $num"
					incr num
				}
				ttk::combobox $wid.frame.spin -textvariable par($variable) -state readonly -values $options
			} else {
				spinbox $wid.frame.spin -from $min -to $max -increment $step -width 10 -textvariable par($variable) -width 4
			}
			pack $wid.frame.spin -side right -expand yes -fill x
}

proc gui_check {wid variable title title2 tooltiptext helptext} {
	global par
	frame $wid
	pack $wid -side top -expand yes -fill x
	setTooltip $wid "$tooltiptext"

		label $wid.label -text "$title" -width 14 -anchor w
		pack $wid.label -side left -expand no -fill x

		frame $wid.frame
		pack $wid.frame -side left -expand yes -fill x

			checkbutton $wid.frame.check -text "$title2" -variable par($variable) -relief flat -anchor w
			pack $wid.frame.check -side left -expand yes -fill x

			eval button $wid.frame.help -text \"?\" -width 1 -command \{show_help \"$helptext\"\}
			pack $wid.frame.help -side left -expand no -fill none
}

proc gui_radio {wid variable options title tooltiptext helptext} {
	global par
	frame $wid
	pack $wid -side top -expand yes -fill x
	setTooltip $wid "$tooltiptext"

		label $wid.label -text "$title" -width 14 -anchor w
		pack $wid.label -side left -expand no -fill x

		frame $wid.frame
		pack $wid.frame -side left -expand yes -fill x

			foreach option $options  {
				set option_title [lindex $option 0]
				set option_value [lindex $option 1]
				radiobutton $wid.frame.check_$option -text "$option_title" -value $option_value -variable par($variable) -relief flat
				pack $wid.frame.check_$option -side left -expand yes -fill x
			}

			eval button $wid.frame.help -text \"?\" -width 1 -command \{show_help \"$helptext\"\}
			pack $wid.frame.help -side left -expand no -fill none
}

proc gui_button {wid title tooltiptext command} {
	eval button $wid -text \"$title\" -width 14 -command $command
	pack $wid -side left -expand yes -fill x
	setTooltip $wid "$tooltiptext"
}

proc disable_all {path} {
    catch {$path configure -state disabled}
    foreach child [winfo children $path] {
        disable_all $child
    }
}

proc enable_all {path} {
    catch {$path configure -state normal}
    foreach child [winfo children $path] {
        enable_all $child
    }
}

proc launchBrowser url {
	global tcl_platform
	switch $tcl_platform(os) {
		Darwin {
		  set command [list open $url]
		}
		HP-UX -
		Linux  -
		SunOS {
		  foreach executable {firefox mozilla netscape iexplorer opera lynx w3m links epiphany galeon konqueror mosaic amaya browsex elinks} {
		    set executable [auto_execok $executable]
		    if [string length $executable] {
		      set command [list $executable $url &]
		      set command [list $executable $url]
		      break
		    }
		  }
		}
		{Windows 95} -
		{Windows NT} {
		  set command "[auto_execok start] {} [list $url]"
		}
	}
	if [info exists command] {
		if [catch {exec {*}$command &} err] {
		  tk_messageBox -icon error -message "error '$err' with '$command'"
		}
	} else {
		tk_messageBox -icon error -message "Please tell CL that ($tcl_platform(os), $tcl_platform(platform)) is not yet ready for browsing."
	}
}

#####################################################################################
# the GUI
#####################################################################################

wm title . "Brushless-Gimbal-Tool (for v$VERSION)"


proc update_mpu {n1 n2 op} {
	global par
	.note.general.settings.sensor.img.canv delete "arrows"
	if {$par(axisSwapXY) == 1} {
		.note.general.settings.sensor.img.canv create line 18 38 60 15 -fill green -arrow last -tag arrows
		.note.general.settings.sensor.img.canv create line 18 38 50 75 -fill red -arrow last -tag arrows
		.note.general.settings.sensor.img.canv create text 55 75 -text "X" -fill red -tag arrows
		.note.general.settings.sensor.img.canv create text 65 15 -text "Y" -fill green -tag arrows
	} else {
		.note.general.settings.sensor.img.canv create line 18 38 60 15 -fill red -arrow last -tag arrows
		.note.general.settings.sensor.img.canv create line 18 38 50 75 -fill green -arrow last -tag arrows
		.note.general.settings.sensor.img.canv create text 65 15 -text "X" -fill red -tag arrows
		.note.general.settings.sensor.img.canv create text 55 75 -text "Y" -fill green -tag arrows
	}
	if {$par(axisReverseZ) == 1} {
		.note.general.settings.sensor.img.canv create line 18 38 18 100 -fill blue -arrow last -tag arrows
		.note.general.settings.sensor.img.canv create text 23 100 -text "Z" -fill blue -tag arrows
	} else {
		.note.general.settings.sensor.img.canv create line 18 38 18 5 -fill blue -arrow last -tag arrows
		.note.general.settings.sensor.img.canv create text 23 7 -text "Z" -fill blue -tag arrows
	}
}

trace variable par(axisReverseZ) w update_mpu
trace variable par(axisSwapXY) w update_mpu


ttk::notebook .note
pack .note -fill both -expand yes -fill both -padx 2 -pady 3

	ttk::frame .note.general
	.note add .note.general -text "Settings"

	label .note.general.image -relief flat -anchor center -image "logo"
	pack .note.general.image -side top -fill none -expand no

	labelframe .note.general.settings -text "General"
	pack .note.general.settings -side top -expand yes -fill both

		labelframe .note.general.settings.rc -text "RC"
		pack .note.general.settings.rc -side left -expand yes -fill both

			gui_check .note.general.settings.rc.rcModePPM  rcModePPM  "RC PPM/PWM" "PPM" "Mode of RC input, PPM sum oder single PWM RC inputs on A1/A2" "config.rcModePPM: PPM sum oder single PWM RC inputs on A0/A1/A2: PPM sum input on A2 or single RC PWM inputs on A2=Ch0, A1=Ch1, A0=Ch3"
			gui_check .note.general.settings.rc.rcAbsolute rcAbsolute "RC Abs/Prop" "Absolute" "Absolute or Incremental RC control" "config.rcAbsolute: Absolute or Incremental RC control, Absolute: gimbal postion follows RC transmitters directly, Proportional: RC controls the gimbal speed, thus in RC stick in center position (1500us) gimbal stops moving, where as the gimbal starts moving if stick is moved"
			gui_slider .note.general.settings.rc.rcGain rcGain -200 200.0 0.1 "RC Gain" "RC gain" "config.rcGain: RC Gain in Proportional mode: specifies the gain of the RC channel, larger values increas the speed of the gimbal movement"
			gui_slider .note.general.settings.rc.rcLPF rcLPF 1 20 0.1 "RC Low Pass" "RC low pass filter" "config.rcLPF: RC low pass filter in Absolute mode: specifies speed of gimbal movement (sec)"
			gui_slider .note.general.settings.rc.rcMid rcMid 1000 2000 1 "RC middle" "RC middle position" "config.rcMid: RC middle position: specifies the PWM time of the RC center position in us (default=1500)"

		labelframe .note.general.settings.sensor -text "Sensor"
		pack .note.general.settings.sensor -side left -expand yes -fill both


			frame .note.general.settings.sensor.set
			pack .note.general.settings.sensor.set -side left -expand yes -fill both

				gui_check .note.general.settings.sensor.set.axisReverseZ axisReverseZ "Reverse Z-axis" "reversed" "config.axisReverseZ: Set Sensor Orientation: 0=sensor mounted with component side up, 1=sensor mounted upside down" "Set Sensor Orientation Z-Axis: 0=sensor mounted with component side up, 1=sensor mounted upside down"
				gui_check .note.general.settings.sensor.set.axisSwapXY axisSwapXY "Swap XY-axis" "swapped" "config.axisSwapXY: Set Sensor Orientation XY-Axis: 0=normal, 1=swap X/Y axis" "Set Sensor Orientation XY-Axis: 0=normal, 1=functions of X/Y axis are exchanged"
				gui_slider .note.general.settings.sensor.set.accTimeConstant accTimeConstant 1 20 1 "ACC Time Const"  "ACC Time Constant(sec)" "tconfig.accTimeConstant: time constant of ACC complementary filter.  Controls how fast the gimbal follows ACC (sec)"
				gui_slider .note.general.settings.sensor.set.mpuLPF mpuLPF 0 6 1 "MPU LPF" "low pass filter of gyro" "config.mpuLPF: low pass filter of gyro (DLPFMode)   legal values are 0...6, 0=fastest(default) 6=slowest   use slow values if high frequency oscillations occur (still experimental)"
				gui_check .note.general.settings.sensor.set.enableGyro enableGyro "Gyro Update" "enabled" "Gyro update" "config.enableGyro: enable gyro update: 0=do not use gyro for attitude calcualtion, just for test and adjustment purposes"
				gui_check .note.general.settings.sensor.set.enableACC enableACC "ACC Update" "enabled" "ACC update" "config.enableACC: enable ACC update: 0=do not use ACC for attitude calculation, just for test and adjustment purposes"


			frame .note.general.settings.sensor.img
			pack .note.general.settings.sensor.img -side left -expand no -fill none

				canvas .note.general.settings.sensor.img.canv -relief raised -width 120 -height 120
				pack .note.general.settings.sensor.img.canv -side left
				.note.general.settings.sensor.img.canv create image 0 0 -anchor nw -image sensor
				update_mpu 0 0 0



	labelframe .note.general.chart -text "Chart"
	pack .note.general.chart -side top -expand no -fill both

		canvas .note.general.chart.chart1 -relief raised -width 450 -height 100
		pack .note.general.chart.chart1 -side left
		.note.general.chart.chart1 create rec 1 1 450 100 -fill black
		.note.general.chart.chart1 create line 0 50 450 50 -fill white
		setTooltip .note.general.chart.chart1 "acc chart"

		frame .note.general.chart.fr1
		pack .note.general.chart.fr1 -side left -expand yes -fill both

			button .note.general.chart.fr1.button -text "Start" -width 5 -relief raised -command {
				draw_chart
			}
			pack .note.general.chart.fr1.button -side top -expand yes -fill both
			setTooltip .note.general.chart.fr1.button "start/stop chart drawing"

			frame .note.general.chart.fr1.scale
			pack .note.general.chart.fr1.scale -side top -expand no -fill x

				scale .note.general.chart.fr1.scale.slider -orient horizontal -from 0.1 -to 10.0 -showvalue 0 -resolution 0.1 -variable CHART_SCALE
				pack .note.general.chart.fr1.scale.slider -side left -expand yes -fill x
				setTooltip .note.general.chart.fr1.scale.slider "Y-Scale for the chart"

				button .note.general.chart.fr1.scale.help -text "?" -width 1 -command {
					show_help "Y-Scale for the chart"
				}
				pack .note.general.chart.fr1.scale.help -side right -expand no -fill none


	ttk::frame .note.pitch
	.note add .note.pitch -text "Pitch"

		labelframe .note.pitch.pid -text "PID" -padx 10 -pady 10
		pack .note.pitch.pid -side top -expand no -fill x

			gui_slider .note.pitch.pid.p gyroPitchKp 0 100 0.001 "P" "P-Value" "config.gyroPitchKp: P-Value"
			gui_slider .note.pitch.pid.i gyroPitchKi 0 100 0.001 "I" "I-Value" "config.gyroPitchKi: I-Value"
			gui_slider .note.pitch.pid.d gyroPitchKd 0 100 0.001 "D" "D-Value" "config.gyroPitchKd: D-Value"

		labelframe .note.pitch.hw -text "Motor" -padx 10 -pady 10
		pack .note.pitch.hw -side top -expand no -fill x

			gui_radio .note.pitch.hw.number motorNumberPitch "{Motor-1 1} {Motor-2 2}" "Port-Number"  "Output-Port-Number" "config.motorNumberPitch: if you find that the wrong motor is connected you can just change the 0 to the 1 and this will save unplugging your motors"
			gui_check .note.pitch.hw.dir   dirMotorPitch            "Direction"     "reverse" "Motor-Direction" "config.Direction: this is for reversing your motor if it is rotating in the wrong direction"
			gui_slider .note.pitch.hw.maxpwm maxPWMmotorPitch 0 100 0.1 "max PWM (%)" "maximum Motor-PWM" "config.maxPWMmotorPitch: control of motor power, minimize the MAX PWM setting as much as possible this will help to stop vibrations in the motor as well"

		labelframe .note.pitch.rc -text "RC" -padx 10 -pady 10
		pack .note.pitch.rc -side top -expand no -fill x

			gui_spin .note.pitch.rc.rcChannelPitch rcChannelPitch 1 16 1 "RC Channel"  "rcChannelPitch" "config.rcChannelPitch: RC channel assignment for RC pitch, legal values 1..16 in PPM mode, 1..3 in PWM mode"
			gui_slider .note.pitch.rc.rcmin  minRCPitch -120 120 1       "RC min"  "minimum RC Angle" "config.minRCPitch: the amount or rotation your motor will make on that axis"
			gui_slider .note.pitch.rc.rcmax  maxRCPitch -120 120 1       "RC max"  "maximum RC Angle" "config.maxRCPitch: the amount or rotation your motor will make on that axis"
			gui_slider .note.pitch.rc.aop angleOffsetPitch -120 120 0.1  "Angle Offset" "Angle Offset" "config.angleOffsetPitch: offset adjust for pitch zero position (deg)"



	ttk::frame .note.roll
	.note add .note.roll -text "Roll"

		labelframe .note.roll.pid -text "PID" -padx 10 -pady 10
		pack .note.roll.pid -side top -expand no -fill x

			gui_slider .note.roll.pid.p gyroRollKp 0 100 0.001 "P" "P-Value" "config.gyroRollKp: P-Value"
			gui_slider .note.roll.pid.i gyroRollKi 0 100 0.001 "I" "I-Value" "config.gyroRollKi: I-Value"
			gui_slider .note.roll.pid.d gyroRollKd 0 100 0.001 "D" "D-Value" "config.gyroRollKd: D-Value"

		labelframe .note.roll.hw -text "Motor" -padx 10 -pady 10
		pack .note.roll.hw -side top -expand no -fill x

			gui_radio .note.roll.hw.number motorNumberRoll "{Motor-1 1} {Motor-2 2}" "Port-Number"  "Output-Port-Number" "config.motorNumberRoll: if you find that the wrong motor is connected you can just change the 0 to the 1 and this will save unplugging your motors"
			gui_check .note.roll.hw.dir   dirMotorRoll            "Direction"     "reverse" "Motor-Direction" "config.dirMotorRoll: this is for reversing your motor if it is rotating in the wrong direction"
			gui_slider .note.roll.hw.maxpwm maxPWMmotorRoll 0 100 0.1 "max PWM (%)" "maximum Motor-PWM" "config.maxPWMmotorRoll: control of motor power, minimize the MAX PWM setting as much as possible this will help to stop vibrations in the motor as well"

		labelframe .note.roll.rc -text "RC" -padx 10 -pady 10
		pack .note.roll.rc -side top -expand no -fill x

			gui_spin .note.roll.rc.rcChannelRoll rcChannelRoll 1 16 1 "RC Channel"  "rcChannelRoll" "config.rcChannelRoll: RC channel assignment for RC roll, llegal values 1..16 in PPM mode, 1..3 in PWM mode"
			gui_slider .note.roll.rc.rcmin  minRCRoll -120 120 1      "RC Min"  "minimum Angle" "config.minRCRoll: the amount or rotation your motor will make on that axis"
			gui_slider .note.roll.rc.rcmax  maxRCRoll -120 120 1      "RC Max"  "maximum Angle" "config.maxRCRoll: the amount or rotation your motor will make on that axis"
			gui_slider .note.roll.rc.aop angleOffsetRoll -120 120 0.1 "Angle Offset" "angleOffsetRoll" "config.angleOffsetRoll: offset adjust for roll zero position (deg)"



labelframe .device -text "Connection"
pack .device -side top -expand no -fill x
setTooltip .device "serial port selection"

	label .device.label -text "Port" -width 5
	pack .device.label -side left -expand no -fill x

	if {[catch {ttk::combobox .device.spin -textvariable device -state readonly -values $comports}]} {
		spinbox .device.spin -values $comports -width 10  -textvariable device
	}
	pack .device.spin -side left -expand yes -fill x

	button .device.connect -text "Connect" -width 9 -command {
		connect_serial
	}
	pack .device.connect -side left -expand no -fill x

	button .device.close -text "Close" -width 9 -command {
		close_serial
	}
	pack .device.close -side left -expand no -fill x


frame .buttons
pack .buttons -side top -expand no -fill x

	gui_button .buttons.defaults "Defaults" "set defaults values" set_defaults
	gui_button .buttons.load "Load" "load values from board into gui" send_par
	gui_button .buttons.save "Save" "save values from gui into board" save_values
	gui_button .buttons.load_from_file "Load from File" "load values from file into board and gui" load_values_from_file


frame .buttons_ext
pack .buttons_ext -side top -expand no -fill x

	gui_button .buttons_ext.gyro_cal "Gyro-Cal" "gyro recalibration" gyro_cal
	gui_button .buttons_ext.load_from_flash "Load from Flash" "load values from flash into board and gui" load_from_flash
	gui_button .buttons_ext.save_to_flash "Save to Flash" "save values from board into flash" save_to_flash
	gui_button .buttons_ext.save2file "Save to File" "save values from gui into file" save_values2file


label .helptext -relief sunken -text "BLG-Tool"
pack .helptext -side top -expand no -fill x

frame .bottom
pack .bottom -side top -expand no -fill x

	label .bottom.version -relief sunken -width 30 -text "Version: $tcl_platform(os)/$tcl_platform(osVersion)"
	pack .bottom.version -side left -expand no -fill x
	setTooltip .bottom.version "board/system version"

	label .bottom.info -relief sunken -text "Not connected"
	pack .bottom.info -side left -expand yes -fill x
	setTooltip .bottom.info "status informations"


## Trace parameters to update on change
foreach var [array names par] {
	if {$var == "vers"} {
	} elseif {! [string match "*,*" $var]} {
		trace variable par($var) w send_parvar
	}
}


#####################################################################################
# check arguments
#####################################################################################

if {[lindex $argv 0] == "-b" || [lindex $argv 0] == "--help"} {
	if {[lindex $argv 1] == ""} {
		puts "[info script] -b firmware.bin"
		exit 0
	}
	set FILE [lindex $argv 1]

	if {[string match "*.hex" $FILE]} {
		exec objcopy -I ihex -O binary "$FILE" "$FILE.bin"
		set FILE "$FILE.bin"
	}

	set scriptfile [open "[info script]" r]
	set scriptdata [read $scriptfile]
	close $scriptfile

	set scriptfile [open "[info script].new" w]
	foreach line "[split $scriptdata "\n"]" {
		if {[string match "set HEXDATA *" $line]} {
			puts $scriptfile "set HEXDATA \"[ArduinoExportBIN $FILE]\""
		} else {
		        puts $scriptfile "$line"
		}
	}
	close $scriptfile
	exit 0
}


proc show_help_tuning {} {
	catch {destroy .help}
	toplevel .help
	wm title .help "Help: Tuning your Gimbal"
	frame .help.f -highlightthickness 1 -borderwidth 1 -relief sunken
	pack .help.f -expand yes -fill both
	text .help.f.t -yscrollcommand ".help.f.scroll set" -setgrid true -width 120 -height 50 -wrap word -highlightthickness 0 -borderwidth 0
	pack .help.f.t -side left -expand  yes -fill both
	scrollbar .help.f.scroll -command ".help.f.t yview"
	pack .help.f.scroll -side right -fill y
	.help.f.t tag configure header -font "times 24 bold" -justify center
	.help.f.t tag configure center -justify center -spacing1 10p -spacing2 2p -lmargin1 12m -lmargin2 6m -rmargin 10m
	.help.f.t tag configure text -spacing1 10p -spacing2 2p -lmargin1 12m -lmargin2 6m -rmargin 10m
	.help.f.t insert end "\n\n\n\n"
	.help.f.t insert end "Tuning your Gimbal\n" header
	.help.f.t insert end "when you have uploaded the software and connect to your board, the software will load the default\n" text
	.help.f.t insert end "settings.You will need to change these to suit your gimbal and motors\n" text
	.help.f.t insert end "\n      " text
	.help.f.t insert end "\n" text
	.help.f.t insert end "Note: help text to be added ... \n" text
	.help.f.t insert end "\n\n\n" text

	button .help.exit -text "Exit" -width 14 -command {
		destroy .help
	}
	pack .help.exit -side bottom -expand no -fill x
}

proc show_help_about {} {
	catch {destroy .help}
	toplevel .help
	wm title .help "About"
	frame .help.f -highlightthickness 1 -borderwidth 1 -relief sunken
	pack .help.f -expand yes -fill both
	text .help.f.t -yscrollcommand ".help.f.scroll set" -setgrid true -width 80 -height 20 -wrap word -highlightthickness 0 -borderwidth 0
	pack .help.f.t -side left -expand  yes -fill both
	scrollbar .help.f.scroll -command ".help.f.t yview"
	pack .help.f.scroll -side right -fill y
	.help.f.t tag configure header -font "times 24 bold" -justify center
	.help.f.t tag configure center -justify center -spacing1 10p -spacing2 2p -lmargin1 12m -lmargin2 6m -rmargin 10m
	.help.f.t tag configure text -spacing1 10p -spacing2 2p -lmargin1 12m -lmargin2 6m -rmargin 10m
	.help.f.t insert end "\n" text
	.help.f.t insert end "Credits\n" center
	.help.f.t insert end "Manual: By Graham Miller\n" center
	.help.f.t insert end "Brushless Gimbal: By Ludwig Faerber\n" center
	.help.f.t insert end "GUI: By Oliver Dippel\n" center
	.help.f.t insert end "Software: By\n" center
	.help.f.t insert end "Christian Winkler , Ludwig Faerber and Alexander Rehfeld\n" center
	.help.f.t insert end "All rights reserved\n" center

	button .help.exit -text "Exit" -width 14 -command {
		destroy .help
	}
	pack .help.exit -side bottom -expand no -fill x
}








