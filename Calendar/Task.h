#ifndef TASK_H
#define TASK_H

#include <string>
#include "Date.h"

using namespace std;

namespace Concepts {
	template<typename T>
	concept OStream = requires(T t, ostream & os) {
		os << t;
	};

	template<typename T>
	concept IStream = requires(T t, istream & is) {
		is >> t;
	};

	template<typename T>
	concept Streams = IStream<T> && OStream<T>;

	template<typename T>
	concept CConstruct = requires(T t) { // check CopyConstruct
		T(t);
	};

	template<typename T>
	concept CAssign = requires(T t1, T t2) {
		t1 = t2;
	};

	template<typename T>
	concept CopyCA = CAssign<T> && CConstruct<T>;

	template<typename T>
	concept General = CopyCA<T> && Streams<T>;
}

template<Concepts::General T>
class Task {
protected:
	string Name;
	T Content;
	Date DateOT; // Date of Task
public:
	bool setContent(const T& cont);
	bool setDate(Date d);
	bool setName(string n);
	void printTask();
};

#endif // !TASK_H
