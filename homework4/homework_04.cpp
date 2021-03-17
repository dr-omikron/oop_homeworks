#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <utility> 

//Ex 1

class ArrayInt
{
private:
	int m_length;
	int *m_data;
public:
	ArrayInt() : m_length(0), m_data(nullptr) {}
	ArrayInt(int length);
	~ArrayInt() { delete[] m_data; }
	int getLength() { return m_length; }
	void erase();
	int &operator[](int index);
	void resize(int newLength);
	void insertBefore(int value, int index);
	void push_back(int value) { insertBefore(value, m_length); }
	void pop_back();
	void pop_front();
	void sort();
	void print();
	void fill();
};

ArrayInt::ArrayInt(int length) : m_length(length)
{
	assert(length >= 0);
	if (length > 0)
		m_data = new int[length];
	else
		m_data = nullptr;
}
void ArrayInt::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}
int &ArrayInt::operator[](int index)
{
	assert(index >= 0 && index < m_length);
	return m_data[index];
}
void ArrayInt::resize(int newLength)
{
	if (newLength == m_length)
		return;
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int *data = new int[newLength];
	if (m_length > 0)
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
		for (int index = 0; index < elementsToCopy; ++index)
			data[index] = m_data[index];
	}
	delete[] m_data;
	m_data = data;
	m_length = newLength;
}
void ArrayInt::insertBefore(int value, int index)
{
	assert(index >= 0 && index <= m_length);
	int *data = new int[m_length + 1];
	for (int before = 0; before < index; ++before)
		data[before] = m_data[before];
	data[index] = value;
	for (int after = index; after < m_length; ++after)
		data[after + 1] = m_data[after];
	delete[] m_data;
	m_data = data;
	++m_length;
}

void ArrayInt::pop_back()
{
	
	int *data = new int[m_length - 1];
	for (int i = 0; i < m_length - 1; ++i)
		data[i] = m_data[i];
	delete[] m_data;
	m_data = data;
	--m_length;
}

void ArrayInt::pop_front()
{
	int *data = new int[m_length - 1];
	for (int i = 0; i < m_length - 1; ++i)
		data[i] = m_data[i+1];
	delete[] m_data;
	m_data = data;
	--m_length;
}

void ArrayInt::sort()
{
	for (int i = 0; i < m_length - 1; ++i)
	{
		int smIndx = i;
		for (int j = i+1; j < m_length; j++)
		{
			if (m_data[j] < m_data[smIndx])
				smIndx = j;
		}
		std::swap(m_data[i], m_data[smIndx]);
	}
}

void ArrayInt::fill()
{
	for (int i = 0; i < m_length; ++i)
		m_data[i] = rand() % 100;
}

void ArrayInt::print()
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << "" << std::endl;
}


//Ex 2

int DiffNumCounter(std::vector <int> &vec)
{
	int val = 0;
	int counter = 0;
	std::sort(vec.begin(), vec.end());
	std::vector<int> :: iterator it;
	std::vector<int> :: iterator it2;
	it = vec.begin();
	it2 = vec.begin();
	it2++;
	while (it != vec.end())
	{
		if (val != *it)
		{
			while (it2 != vec.end())
			{
				if (*it2 = !*it) { counter++;	break; }
				else { break; }
			
			}
		}   
	val = *it;
	it++;
	if(it2 != vec.end())
	it2++;
	}
	return counter;
}

void PrintCounter(std::vector <int> &vec)
{
	std::cout << "Different numbers in vector: "
		<< DiffNumCounter(vec) << std::endl;
}

int main()
{
	//Ex 1
	ArrayInt arr(10);
	arr.erase();
	arr.push_back(235);
	arr.print();
	arr.resize(10);
	arr.fill();
	arr.insertBefore(569,3);
	arr.push_back(235);
	arr.print();
	arr.sort();
	arr.print();
	arr.pop_back();
	arr.pop_front();
	arr.print();
	
	//Ex 2
	std::vector <int> vec = { 2, 4, 5, 5, 5, 9, 4, 4, 8, 3, 10 };
	PrintCounter(vec);
}

