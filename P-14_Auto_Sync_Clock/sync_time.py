"""Sends the laptop's current time to the Arduino clock over USB.

Setup (once):   pip install pyserial
Run:            python sync_time.py          (auto-detects the Arduino port)
                python sync_time.py COM5     (or give the port yourself)

Keep this running while the Uno is plugged in. It re-sends the time every
30 seconds so the clock stays accurate. Close it (Ctrl+C) before uploading
a new sketch from the Arduino IDE, since the port can only be used by one program.
"""
import sys
import time
import datetime

import serial
from serial.tools import list_ports


def find_port():
    ports = list(list_ports.comports())
    for p in ports:
        text = ((p.description or "") + " " + (p.manufacturer or "")).upper()
        if "CH340" in text or "ARDUINO" in text or "USB-SERIAL" in text or "USB SERIAL" in text:
            return p.device
    return ports[0].device if ports else None


port = sys.argv[1] if len(sys.argv) > 1 else find_port()
if not port:
    sys.exit("No serial port found. Is the Arduino plugged in?")

print(f"Using {port}. Press Ctrl+C to stop.")
ser = serial.Serial(port, 9600, timeout=1)
time.sleep(2.5)  # the Uno resets when the port opens; give it time to boot

try:
    while True:
        now = datetime.datetime.now()  # laptop local time (should be set to IST)
        ser.write(now.strftime("T%H:%M:%S\n").encode())
        print("Sent", now.strftime("%H:%M:%S"))
        time.sleep(30)
except KeyboardInterrupt:
    print("Stopped.")
finally:
    ser.close()
