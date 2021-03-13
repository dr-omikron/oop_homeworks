#include <iostream>
#include <math.h>
#include <string>

//Ex 1

class Figure
{
protected:
    float m_valueA = 0;
    float m_valueB = 0;
public:
    float virtual Area() = 0;
    Figure(float valueA, float valueB) 
        : m_valueA(valueA), m_valueB(valueB) {}
};
class Parallelogram : public Figure
{
public:
    Parallelogram(float base, float height) 
        : Figure (base, height){}
    float Area() override { return m_valueA * m_valueB; }
 };
class Circle : public Figure
{
public:
    Circle (float radius) : Figure(radius, 3.14) {}
    float Area() override { return pow(m_valueA, 2) * m_valueB; }
};
class Rectangle : public Parallelogram
{
public:
    Rectangle(float width, float height) 
        : Parallelogram (width, height) {}
};
class Square : public Parallelogram
{
public:
    Square (float side)
        : Parallelogram (side, side) {}
};
class Rhombus : public Parallelogram
{
public:
    Rhombus (float side, float height)
        : Parallelogram(side, height) {}
};

void Print(Figure *figure)
{
    std::cout << figure->Area() << std::endl;
}

//Ex2

class Car 
{
protected:
    std::string m_company;
    std::string m_model;
public:
    Car (std::string company, std::string model)
        : m_company (company), m_model (model) 
    {
        std::cout << "Class car: " << m_company << " " << m_model << std::endl;
    }
};
class PassengerCar : virtual public Car
{
public:
    PassengerCar (std::string company, std::string model)
        : Car (company, model) 
    {
        std::cout << "Class passenger car: " <<  m_company << " " << m_model << std::endl;
    }
};
class Bus : virtual public Car
{
public:
    Bus (std::string company, std::string model)
        : Car (company, model)
    {
        std::cout << "Class bus: " << m_company << " " << m_model << std::endl;
    }
};
class Minivan : public PassengerCar, public Bus
{
public:
    Minivan (std::string company, std::string model)
        : Bus(company, model), PassengerCar(company, model), Car (company, model)
    {
        std::cout << "Class minivan: " << m_company << " " << m_model << std::endl;
    }
};

//Ex3

class Fraction
{
private:
    int m_numerator;
    int m_divisor;
    
    void LCM (Fraction& other)
    {
        m_numerator = m_numerator * other.m_divisor;
        other.m_numerator = other.m_numerator * m_divisor;
        m_divisor = other.m_divisor = m_divisor * other.m_divisor;
    }
public:
    int GetNumerator() { return m_numerator; }
    int GetDivisor() { return m_divisor; }
    Fraction(int numerator, int divisor)
    {
        m_numerator = numerator;
        if (divisor) {
            m_divisor = divisor;
        }
        else {
            std::cout << "The divisor equal 0!";
            exit(EXIT_FAILURE);
        }
    }
    bool operator == (Fraction& other)
    {
        if (m_divisor != other.m_divisor) {
            LCM(other);
            return (m_numerator == other.m_numerator);
        }
        else {
            return (m_numerator == other.m_numerator);
        }
    }
    bool operator != (Fraction& other)
    {
        if (m_divisor != other.m_divisor) {
            LCM(other);
            return (m_numerator != other.m_numerator);
        }
        else {
            return (m_numerator != other.m_numerator);
        }
    }
    bool operator >= (Fraction& other)
    {
        if (m_divisor != other.m_divisor) {
            LCM(other);
            return (m_numerator >= other.m_numerator);
        }
        else {
            return (m_numerator >= other.m_numerator);
        }
    }
    bool operator <= (Fraction& other)
    {
        if (m_divisor != other.m_divisor) {
            LCM(other);
            return (m_numerator <= other.m_numerator);
        }
        else {
            return (m_numerator <= other.m_numerator);
        }
    }
    bool operator > (Fraction& other)
    {
        if (m_divisor != other.m_divisor) {
            LCM(other);
            return (m_numerator > other.m_numerator);
        }
        else {
            return (m_numerator > other.m_numerator);
        }
    }
    bool operator < (Fraction& other)
    {
        if (m_divisor != other.m_divisor) {
            LCM(other);
            return (m_numerator < other.m_numerator);
        }
        else {
            return (m_numerator < other.m_numerator);
        }
    }
    Fraction operator- () const { return Fraction(-m_numerator, m_divisor); }
    
    Fraction operator- (Fraction& other)
    {
        if (m_divisor != other.m_divisor) {
            LCM(other);
            return Fraction(m_numerator - other.m_numerator, m_divisor);
        }
        else {
            return Fraction(m_numerator - other.m_numerator, m_divisor);
        }
    }
    Fraction operator+ (Fraction& other)
    {
        if (m_divisor != other.m_divisor) {
            LCM(other);
            return Fraction(m_numerator + other.m_numerator, m_divisor);
        }
        else {
            return Fraction(m_numerator + other.m_numerator, m_divisor);
        }
    }
    Fraction operator* (Fraction& other)
    {
        return Fraction(m_numerator * other.m_numerator, m_divisor * other.m_divisor);
    }
    Fraction operator/ (Fraction& other)
    {
        return Fraction(m_numerator * other.m_divisor, m_divisor * other.m_numerator);
    }
 };

void fractionPrint(Fraction *fraction)
{
    std::cout << fraction->GetNumerator() << "/" << fraction->GetDivisor() << std::endl;
}

//Ex4

class Card
{
private:
    enum class Suit
    {
        Hearts,
        Spades,
        Crosses,
        Tambourines

    } m_Suit;
    enum class Rank
    {
        Ace,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King

    } m_Rank;
    bool m_faceUp = false;

public:
    bool Flip() { 
        m_faceUp ? m_faceUp = false : m_faceUp = true;
        return m_faceUp;
    }
    int GetValue()
    {
        switch (m_Rank)
        {
        case Card::Rank::Ace:
            return 1;
        case Card::Rank::Two:
            return 2;
        case Card::Rank::Three:
            return 3;
        case Card::Rank::Four:
            return 4;
        case Card::Rank::Five:
            return 5;
        case Card::Rank::Six:
            return 6;
        case Card::Rank::Seven:
            return 7;
        case Card::Rank::Eight:
            return 8;
        case Card::Rank::Nine:
            return 9;
        case Card::Rank::Ten:
            return 10;
        case Card::Rank::Jack:
            return 10;
        case Card::Rank::Queen:
            return 10;
        case Card::Rank::King:
            return 10;
        default:
            return 0;
        }
    }
 };

int main()
{
    //Ex1

    Parallelogram par(10.3,7.7);
    Square sqr(12.5);
    Circle crl(9.8);
    Rhombus rmb(20.1,15.3);
    Rectangle rec(13.6,8);
    Print(&par);
    Print(&sqr);
    Print(&crl);
    Print(&rmb);
    Print(&rec);

    //Ex2
    
    std::cout << " " << std::endl;
    Car car("Volvo", "S90");                        // Конструктор вызывается один раз
    std::cout <<" "<< std::endl;
    PassengerCar pCar("Volkswagen", "Taos");        // Конструктор вызывается два раза, сначала создается родительский класс Car 
    std::cout << " " << std::endl;                  
    Bus bus ("Mersedes", "Intuoro");                // Конструктор вызывается два раза, сначала создается родительский класс Car 
    std::cout << " " << std::endl;
    Minivan("BMW", "Grand Tourer");                 // Конструктор вызывается четыре раза, сначала создаются все родительские классы
    std::cout << " " << std::endl;

    //Ex3

    Fraction fraction1(2, 3);
    fractionPrint(&fraction1);
    Fraction fraction2(3, 4);
    fractionPrint(&fraction2);
    Fraction fraction3 = fraction1 + fraction2;
    fractionPrint(&fraction3);
    std::cout << " " << std::endl;
    Fraction fraction4(5, 7);
    fractionPrint(&fraction4);
    Fraction fraction5(2, 7);
    fractionPrint(&fraction5);
    Fraction fraction6 = fraction4 - fraction5;
    fractionPrint(&fraction6);
    std::cout << " " << std::endl;
    Fraction fraction7 = fraction4 * fraction5;
    fractionPrint(&fraction7);
    std::cout << " " << std::endl;
    Fraction fraction8 = fraction4 / fraction5;
    fractionPrint(&fraction8);
    std::cout << " " << std::endl;
    bool compare = fraction4 < fraction5;
    std::cout << compare << std::endl;
    compare = fraction4 > fraction5;
    std::cout << compare << std::endl;
    compare = fraction4 == fraction5;
    std::cout << compare << std::endl;
    compare = fraction4 != fraction5;
    std::cout << compare << std::endl;
    compare = fraction4 <= fraction5;
    std::cout << compare << std::endl;
    compare = fraction4 >= fraction5;
    std::cout << compare << std::endl;

    //Ex4
    
    Card card;
    std::cout << card.Flip() << std::endl;
    std::cout << card.Flip() << std::endl;
    std::cout << card.Flip() << std::endl;
    std::cout << card.GetValue() << std::endl;

    return EXIT_SUCCESS;
}