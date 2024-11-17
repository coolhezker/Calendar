#ifndef DATE_H
#define DATE_H

enum class Month {
	January = 1, February,
	March, April, May,
	June, July, August,
	September, October, November,
	December
};

class Day {
private:
	int NumberOD; // Number of Day
	int Hour;
	int Minute;
public:

};

class Date {
private:
	int Year;
	Month MonthOD; // Month of Date
	Day DayOD; // Day of Date
public:

};

#endif // !DATE_H