#ifndef TASK_H
#define TASK_H

#include <string>
#include "Date.h"
#include "Concepts.h"

template<Concepts::General T>
class Task {
protected:
	std::string Name; // Name of task
	T Content; // Content of task
	Date DateOT; // Date of Task
public:
	Task(); // standart Constructor
	explicit Task(std::string N, T C, Date D);
	virtual void setContent(const T& cont);
	void setDate(Date D);
	void setName(std::string N);
	virtual void printTask();
};

#endif // !TASK_H
