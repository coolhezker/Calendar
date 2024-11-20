#include "Task.h"

template<Concepts::General T>
Task<T>::Task() : Name{ "" }, T{ T() }, DateOT{ Date() } {};

template<Concepts::General T>
Task<T>::Task(std::string N, T C, Date D) : Name{ N }, T{ C }, Date{ D } {};

template<Concepts::General T>
void Task<T>::setDate(Date D) {
	DateOT = D;
}

template<Concepts::General T>
void Task<T>::setName(std::string N) {
	Name = N;
}

template<Concepts::General T>
void Task<T>::setContent(const T& cont) {
	Content = cont;
}

template<Concepts::General T>
void Task<T>::printTask() {
	cout<<"Name: "<<Name
		<< DateOT.printDate()
}