#ifndef TASK_H
#define TASK_H

#include <string>
#include "Date.h"

using namespace std;

class Task {
protected:
	int Id;
	string Name;
	string Content;
	string Path;
	Date DateOT; // Date of Task
public:
	bool setContent(const string& cont);
	bool setDate(Date d);
};

#endif // !TASK_H
