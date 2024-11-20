#ifndef CONCEPTS_H
#define CONCEPTS_H

#include <iostream>

namespace Concepts {
	template<typename T>
	concept OStream = requires(T t, std::ostream & os) { // check operator<<
		os << t;
	};

	template<typename T>
	concept IStream = requires(T t, std::istream & is) { // check operator>>
		is >> t;
	};

	template<typename T>
	concept Streams = IStream<T> && OStream<T>; // combine IStream concept and OStream concept

	template<typename T>
	concept CConstruct = requires(T t) { // check Copy Constructor
		T(t);
	};

	template<typename T> // check Copy Assign
	concept CAssign = requires(T t1, T t2) {
		t1 = t2;
	};

	template<typename T> // combine CAssign concept and CConstruct concept
	concept CopyCA = CAssign<T> && CConstruct<T>;

	template<typename T> // combine CopyCA concept and Streams concept. (combine all concepts)
	concept General = CopyCA<T> && Streams<T>;
}

#endif // !CONCEPTS_H
