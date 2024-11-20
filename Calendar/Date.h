#ifndef DATE_H
#define DATE_H

#include <string>

enum class Month {
	January = 1, February,
	March, April, May,
	June, July, August,
	September, October, November,
	December
};

class Day {
protected:
	int NumberOD;
	int Hour;
	int Minute;
	bool isValidDay(int H, int M, int N);
public:
	Day();
	explicit Day(int H, int M, int N);
	bool setDay(int H, int M, int N);
	Day getDay();
	int getNOD() const; // get Number Of Day
	virtual std::string stringDay();
};

class Date {
protected:
	int Year;
	Month MonthOD; // Month of Date
	Day DayOD; // Day of Date
	bool isLeapYear(int Y);
	int CountOfDays(int Y, Month M);
	bool isValidYear(int Y);
	bool isValidDate(int Y, Month M, Day D);
public:
	Date();
	explicit Date(int Y, Month M, Day D);
	bool setDate(int Y, Month M, Day D);
	virtual std::string stringDay();
	virtual std::string stringMonth();
	virtual void printDate();
};

#endif // !DATE_H