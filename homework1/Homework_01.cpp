#include <iostream>
#include <cassert>
#include <math.h>
#include <cstdint>

//Ex1

class Power
{
 private:
    int m_valueX;
    int m_valueY;
 public:
    void SetValues(int valueX, int valueY)
    {
        m_valueX = valueX;
        m_valueY = valueY;
    }
    int GetCalculateValues()
    {
        return pow(m_valueX, m_valueY);
    }
};

//Ex2 (uint8_t интерпритируется как char, приводить к типу int, думаю не имеет смысла, поэтому использую uint16_t)

class RGBA
{
 private:
    const uint16_t m_red = 0;                         
    const uint16_t m_green = 0;
    const uint16_t m_blue = 0;
    const uint16_t m_alpha = 255;
 public:
    RGBA() {};
    RGBA(uint16_t red, uint16_t green, uint16_t blue, uint16_t alpha)
        : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha){}
    void PrintColor()
    {
        std::cout << "R\t" << m_red << "\nG\t" << m_green << "\nB\t" << m_blue << "\nA\t" << m_alpha << std::endl;
        std::cout <<""<< std::endl;
    }
};

//Ex3

class Stack
{
private:

	int* m_array = nullptr;
	int m_lenght;
	int m_index;
	
	bool CheckNullPoiner()
	{
		if (m_array == nullptr) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void CheckLenght()
	{
		if (m_lenght <= 0)
		{
			PrintErrorLenght();
		}
	}

	void CheckIndexToLenght()
	{
		if (m_index < 0 || m_lenght <= m_index)
		{
			PrintErrorLenght();
		}
	}

	void CheckValuesForPop()
	{
		if (m_array[m_index] == 0)
		{
			PrintErrorStackEmptyValue();
		}

	}

	void CheckValuesForFill()
	{
		for (int count = 0; count < m_lenght; ++count)
		{
			if (m_array[count] != 0)
			{
				PrintErrorStack();
				break;
			}

		}
		
	}
	void CheckStackValue()
	{
		if (m_array[m_index] != 0)
		{
			PrintErrorStack();
	    }
			
	}

	void PrintErrorStackEmptyValue()
	{
		std::cout << "Error! The stack value is empty!\n";
		exit(EXIT_FAILURE);
	}
	
	void PrintErrorStack()
	{
		std::cout << "Error! The stack is already filled!\n";
		exit(EXIT_FAILURE);
	}

	void PrintErrorLenght()
	{
		std::cout << "Error! Invalid length!\n";
		exit(EXIT_FAILURE);
	}

	void PrintErrorIndex()
	{
		std::cout << "Error! Invalid index!\n";
		exit(EXIT_FAILURE);
	}

public:

	Stack(int lenght)
	{
		m_lenght = lenght;
		CheckLenght();
		if (CheckNullPoiner())
		{
			m_array = new int[m_lenght] {0};
		}
		
	}

	void Reset()
	{
		for (int count = 0; count < m_lenght; ++count)
		{
			m_array[count] = 0;
		}
	
	}

	void FillIncrementValues()
	{
		CheckValuesForFill();
		for (int count = 0; count < m_lenght; ++count)
		{
			m_array[count] = count + 1;
		}
	}

	void FillRandomValues(const int limit)
	{
		CheckValuesForFill();
		for (int count = 0; count < m_lenght; ++count)
		{
  			m_array[count] = rand() % limit + 1;
		}
	}

	void PushValue(const int index, const int value)
	{
		m_index = index;
		CheckIndexToLenght();
		CheckStackValue();
		m_array[m_index] = value;
	}

	int PopValue(const int index)
	{
		m_index = index;
		CheckIndexToLenght();
		CheckValuesForPop();
		return m_array[m_index];
	}

	void Print()
	{
		for (int count = 0; count < m_lenght; ++count)
		{
			std::cout << m_array[count] << std::endl;
		}
		std::cout << "" << std::endl;
	}

	~Stack()
	{
		delete[] m_array;
		m_array = nullptr;
	}

};

int main()
{
	//Ex1
	
	Power pow;
    pow.SetValues(9, 2);
    std::cout << pow.GetCalculateValues() << "\n" << std::endl;
	
	//Ex2
	
	RGBA def;
    RGBA yellow(242, 238, 87, 0);
    def.PrintColor();
    yellow.PrintColor();
	
	//Ex3

	Stack stack(10);
	stack.FillIncrementValues();
	stack.Print();
	stack.Reset();
	stack.Print();
	stack.FillRandomValues(500);
	stack.Print();
	stack.Reset();
	stack.Print();
	stack.PushValue(0, 56);
	stack.PushValue(2, 17);
	stack.PushValue(9, 33);
	stack.Print();
	std::cout << stack.PopValue(0) << std::endl;

	// Проверки

	// stack.PushValue(-1, 15); // Выполнение программы прекратится, так как индекс отрицательный
	// stack.PushValue(10, 15); // Выполнение программы прекратится, так как индекс больше или равен длинне массива
	// stack.FillIncrementValues(); // Выполнение программы прекратится, так как стек уже заполнен значениями
	// stack.FillRandomValues(350); // Выполнение программы прекратится, так как стек уже заполнен значениями
	// stack.PushValue(9, 33); // Выполнение программы прекратится, так как в этом индексе уже есть значение
	// stack.PopValue(5); // Выполнение программы прекратится, так как значение, которое находится по этому индексу равно нулю

	return EXIT_SUCCESS;
}


