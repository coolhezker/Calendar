#include "Date.h"
#include <iostream>

bool Day::isValidDay(int H, int M, int N) {
	return (H >= 0 && H < 24) && (M >= 0 && M < 60) && (N >= 1 && N <=31);
}

Day::Day() {
	Hour = 10;
	Minute = 0;
	std::cerr << "Invalid arguments... Set default day(1, 10:00)\n";
} 

Day::Day(int H, int M, int N) {
	if (!isValidDay(H, M, N)) {
		std::cerr << "Invalid arguments... Set default day(1, 10:00)\n";
		Hour = 10;
		Minute = 0;
		NumberOD = 1;
	}
	else {
		Hour = H;
		Minute = M;
		NumberOD = N;
	}
}

bool Day::setDay(int H, int M, int N) {
	if (!isValidDay(H, M, N))
		return false;
	Hour = H;
	Minute = M;
	NumberOD = N;
	return true;
}

Day Day::getDay() {
	return *this;
}

int Day::getNOD() const {
	return this->NumberOD;
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
	return Y >= 1970; // it`s kind of magic constant. sorry
}

bool Date::isValidDate(int Y, Month M, Day D) {
	if (isValidYear(Y) && D.getNOD() <= CountOfDays(Y, M)) 
		return true;
	else 
		return false;
}

Date::Date() {}

Date::Date(int Y, Month M, Day D) {
	if (!isValidDate(Y, M, D)) {
		std::cerr << "Invalid arguments...\n";
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

std::string Date::stringDay() {

}

std::string Date::stringMonth() {
	switch (MonthOD) {
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

void Date::printDate() {
	std::cout<<"Year: " << Year << '\n'
		<< "Month: " << stringMonth() << '\n'
		<< "Day: " << stringDay()
}