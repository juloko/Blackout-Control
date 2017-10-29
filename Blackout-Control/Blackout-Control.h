#ifndef Blackout-Control_H
#define Blackout-Control_H

class Status {
private:
	char status;
public:
	Status(void);
	void set_stop(void);
	void set_automatic(void);
	void set_manual(void);
	void set_hibrid(void);
	char get_status(void);
};


class Time {
private:
	char day;
	char month;
	char year;
	char hour;
	char minute;
	char second;
public:
	void set_date(char day, char month, char year);
	void set_time(char hour, char minute, char second);
	int get_date(void);
	int get_time(void);
};

class Database {
	//CHANGE int TO STRING
public:
	int read_address(int i);
	int get_hour_address(int address);
	int get_minute_address(int address);
	void add_address(int address);
	void delete_address(int address);
	void set_time_turn_off(int address, char hour, char minute);
	void set_time_turn_on(int address, char hour, char minute);
};

class Update {
	//CHANGE int TO STRING
public:
	void set_turn_off(int address);
	void turn_on(int address, char hour);
};

class Hardware {
private:
	char relay_ff;
	char relay_substation;
	char chipSelect;
public:
	Hardware(void);
	char get_relay_ff(void);
	char get_relay_substation(void);
	char get_chipSelect(void);
	void set_TRISn(void);
};

class Input {
private:
	bool relay_substation;
	bool relay_ff;
	Hardware hard;
public:
	Input(void);
	void set_relay_substation(bool relay_substastion);
	void set_relay_ff(bool relay_ff);
	bool get_relay_substation(void);
	void timer_one(void);
	bool get_relay_ff(void);
};



#endif
