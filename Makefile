# Uncomment lines below if you have problems with $PATH
#SHELL := /bin/bash
#PATH := /usr/local/bin:$(PATH)

all:
	platformio --force run --target upload
#	platformio  serialports monitor

clean:
	platformio --force run --target clean

