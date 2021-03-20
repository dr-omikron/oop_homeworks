#include <iostream>

//Ex1

template<class T>
class Pair1
{
private:
	T m_value1;
	T m_value2;
public:
	Pair1(T value1, T value2)
		: m_value1 (value1), m_value2 (value2) {}
	T first() const { return m_value1; }
	T second() const { return m_value2; }
};

//Ex2

template<class T1, class T2>
class Pair
{
private:
	T1 m_value1;
	T2 m_value2;
public:
	Pair(T1 value1, T2 value2)
		: m_value1(value1), m_value2(value2) {}
	T1 first() const { return m_value1; }
	T2 second() const { return m_value2; }
};

//Ex3

template<class T3>
class Pair <std::string, T3>
{
private:
	std::string m_value1;
	T3 m_value2;
public:
	Pair(std::string value1, T3 value2)
		: m_value1(value1), m_value2(value2) {}
	std::string first() const { return m_value1; }
	T3 second() const { return m_value2; }
};

template<class T3>
class StringValuePair : public Pair  <std::string, T3>
{
public:
	  StringValuePair(std::string value1, T3 value2) 
		  : Pair<std::string, T3>(value1, value2) {}
};

int main()
{
	//Ex1
	Pair1<int> p1(6, 9);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
	const Pair1<double> p2(3.4, 7.8);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	//Ex2
	Pair<int, double> p3(6, 7.8);
	std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
	const Pair<double, int> p4(3.4, 5);
	std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
	//Ex3
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return EXIT_SUCCESS;
}
