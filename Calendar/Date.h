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
	Day();
	explicit Day(int N, int H, int M);
	bool setDay(int N, int H, int M);
	bool checkDay(Day D);
};

class Date {
private:
	int Year;
	Month MonthOD; // Month of Date
	Day DayOD; // Day of Date
public:
	Date();
	explicit Date(int Y, Month M, Day D);
	bool setDate(int Y, Month M, Day D);
	bool checkDate(Date D);
};

#endif // !DATE_H