//Libraries
#include "Blackout-Control.h"
#include <TimerOne.h>

void setup() {
	//Input object declaration.
	Input in;

	//Database object declaration. The Comunication object build the SdFile and Sd too.
	Database db = Database(in.get_pin_chipSelect());

	//BlaoutControl object declaration.
	BlackoutControl blk;

	// Setting the Timer One.
	// Set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second).
	Timer1.initialize(100000);
	// Attach the service routine here.
	Timer1.attachInterrupt(in.timer_one);

	// Attach the Extern Interruptions.
	attachInterrupt(digitalPinToInterrupt(in.get_pin_relay_substation()), in.extIntSubstation, FALLING);
	attachInterrupt(digitalPinToInterrupt(in.get_pin_relay_ff()), in.extIntFF, FALLING);

	// Setting the boudrate of Xbee.
	Serial.begin(9600);

	// Wait the Xbee configurations.
	delay(5000);

	dbInit();
}

int count = 0;
void loop()
{

	//if (count % 2 == 0) {
	//	xbee.remoteRequest(XBeeAddress64(0x00, BROADCAST_ADDRESS), 0, 4);
	//}
	//else {
	//	xbee.remoteRequest(XBeeAddress64(0x0013A200, 0x4091572D), 0, 5);
	//}

	//count++;
	delay(1000);
	db.print();
}

void dbInit() {
	db.del();
	db = Database(in.get_pin_chipSelect());
	db.add(0x0013A200, 0x4091572D);
}