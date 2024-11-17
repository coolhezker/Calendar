#include <iostream>
#include <filesystem>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	filesystem::path absolute = filesystem::absolute(argv[0]);
	string p = absolute.string();
	cout << absolute << endl << p << endl;
	return 0;
}