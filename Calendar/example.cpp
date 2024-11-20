#include <iostream>
#include <string>
#include "Date.h"
#include "Task.h"

using namespace std;

struct Houdini { // example of using class Task
	int someInt;
	string someStr;
	Houdini() : someInt{ 228 }, someStr{ "fuk" } {};
    Houdini(const Houdini& H) : someInt(H.someInt), someStr(H.someStr) {}
    Houdini& operator=(const Houdini& H) {
        if (this != &H) {
            someInt = H.someInt;
            someStr = H.someStr;
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Houdini& H) {
        os << H.someInt << "\n" << H.someStr;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Houdini& H) {
        is >> H.someInt >> H.someStr;
        return is;
    }
};

int main(int argc, char* argv[]) {
	string p = argv[0];
	cout << p << endl;
	Day dd(22, 22, 22);
	Date D(1972, Month::April, dd);
	Task<Houdini> t{ "Zhupa", Houdini(), D};
    cout << t.getDate().to_stringDate() << endl <<t.getContent();
	return 0;
}