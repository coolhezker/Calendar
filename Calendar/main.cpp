#include <iostream>
#include <filesystem>
#include <string>
#include "Date.h"

using namespace std;

int main(int argc, char* argv[]) {
	filesystem::path absolute = filesystem::absolute(argv[0]);
	string p = absolute.string();
	cout << absolute << endl << p << endl;
	return 0;
}