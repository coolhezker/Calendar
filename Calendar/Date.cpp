#include "Date.h"
#include <iostream>

std::string to_stringMonth(Month M) {
	switch (M) {
	case(Month::January):
		return "January";
	case(Month::February):
		return "February";
	case(Month::March):
		return "March";
	case(Month::April):
		return "April";
	case(Month::May):
		return "May";
	case(Month::June):
		return "June";
	case(Month::July):
		return "July";
	case(Month::August):
		return "August";
	case(Month::September):
		return "September";
	case(Month::October):
		return "October";
	case(Month::November):
		return "November";
	case(Month::December):
		return "December";
	default:
		return "Invalid month";
	}
}

bool Day::isValidDay(int N, int H, int M) {
	return (N >= 1 && N <= 31) && (H >= 0 && H < 24) && (M >= 0 && M < 60);
}

Day::Day() { // default day. kind of shit
	NumberOD = 1;
	Hour = 10;
	Minute = 0;
} 

Day::Day(int N, int H, int M) {
	if (!isValidDay(N, H, M)) {
		std::cerr << "Invalid arguments... Set default day(1, 10:00)11\n";
		Hour = 10; // it`s kind of magic constant
		Minute = 0;
		NumberOD = 1;
	}
	else {
		Hour = H;
		Minute = M;
		NumberOD = N;
	}
}

bool Day::setDay(int N, int H, int M) {
	if (!isValidDay(N, H, M))
		return false;
	Hour = H;
	Minute = M;
	NumberOD = N;
	return true;
}

Day Day::getDay() const {
	return *this;
}

int Day::getNOD() const {
	return this->NumberOD;
}

std::string Day::getTime() {
	std::string str;
	if (Hour % 10 > 0)
		str += std::to_string(Hour);
	else
		str += "0" + std::to_string(Hour);
	str += ":";
	if (Minute % 10 > 0)
		str += std::to_string(Minute);
	else
		str += "0" + std::to_string(Minute);
	return str;
}

bool Date::isLeapYear(int Y) {
	return Y % 4 == 0;
}

int Date::CountOfDays(int Y, Month M) {
	switch (M) {
	case(Month::January):
		return 31;
	case(Month::February):
		if (isLeapYear(Y)) return 29;
		return 28;
	case(Month::March):
		return 31;
	case(Month::April):
		return 30;
	case(Month::May):
		return 31;
	case(Month::June):
		return 30;
	case(Month::July):
		return 31;
	case(Month::August):
		return 31;
	case(Month::September):
		return 30;
	case(Month::October):
		return 31;
	case(Month::November):
		return 30;
	case(Month::December):
		return 31;
	default:
		return -1;
	}
}

bool Date::isValidYear(int Y) {
	return Y >= 0; // it`s kind of magic constant. sorry
}

bool Date::isValidDate(int Y, Month M, Day D) {
	if (isValidYear(Y) && D.getNOD() <= CountOfDays(Y, M)) {
		return true;
	}
	else 
		return false;
}

Date::Date() { // default date. kind of shit
	Year = 1970; // it`s kind of magic constant
	MonthOD = Month::January;
	DayOD = Day();
}

Date::Date(int Y, Month M, Day D) {
	if (!isValidDate(Y, M, D)) {
		std::cerr << "Invalid arguments of Date...\n";
	}
	else {
		Year = Y;
		MonthOD = M;
		DayOD = D;
	}
}

bool Date::setDate(int Y, Month M, Day D) {
	if (isValidDate(Y, M, D)) {
		Year = Y;
		MonthOD = M;
		DayOD = D;
		return true;
	} else {
		return false;
	}
}

Day Date::getDay() const {
	return DayOD;
}

std::string Date::to_stringDate() {
	std::string str;
	str += "Year: " + std::to_string(Year)
		+ "\nMonth: " + to_stringMonth(MonthOD)
		+ "\nDay: " + std::to_string(DayOD.getNOD())
		+ "\nTime: " + DayOD.getTime();
	return str;
}