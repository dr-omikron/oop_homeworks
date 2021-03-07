#include <iostream>
#include <string>

//Ex1

class Person
{
private:
    std::string m_name;
    std::string m_gender;
    int m_age;
    int m_weight;
public:
    Person(const std::string& name, const std::string& gender, int age, int weight);
    void SetName(const std::string& name) {m_name = name;}
    void SetGender(const std::string& gender){m_gender = gender;}
    void SetAge(int age){m_age = age;}
    void SetWeight(int weight){m_weight = weight;}
    void PrintPerson();
};

class Student : public Person
{
private:
    int m_yearOfStudy;
    static int studentCount;
public:
    Student(const std::string& name, const std::string& gender, int age, int weight, int yearOfStudy) 
        : Person(name, gender, age, weight), m_yearOfStudy (yearOfStudy) {studentCount++;}
    void SetYear (int yearOfStudy) {m_yearOfStudy = yearOfStudy;}
    void PrintNumberStudent();
    void PrintStudent();
};

int Student::studentCount = 0;

Person::Person(const std::string& name, const std::string& gender, int age, int weight)
{
    m_name = name;
    m_gender = gender;
    m_age = age;
    m_weight = weight;
}

void Person::PrintPerson()
{
    std::cout << "Name: " << m_name << "\nGender: " << m_gender << "\nAge: " << m_age << "\nWeight: " << m_weight << std::endl;
}

void Student::PrintNumberStudent()
{
    std::cout << "Number of students: " << studentCount <<"\n"<< std::endl;
}

void Student::PrintStudent()
{
    PrintPerson();
    std::cout << "Year of study: " << m_yearOfStudy <<"\n"<< std::endl;
}

//Ex2

class Fruit
{
protected:
    std::string m_name;
    std::string m_color;
};

class Apple : public Fruit
{
public:
    Apple(){}
    Apple (const std::string& color) {m_color = color; m_name = "Apple";}
    std::string GetName() {return m_name;}
    std::string GetColor() {return m_color;}
};

class Banana: public Fruit
{
public:
    Banana() {m_color = "yellow"; m_name = "Banana";}
    std::string GetName() {return m_name;}
    std::string GetColor() {return m_color;}
};

class GrannySmith : public Apple
{
public:
    GrannySmith() {m_color = "green"; m_name = "Granny Smith apple";}
    std::string GetName() {return m_name;}
    std::string GetColor() {return m_color;}
};

//Ex3

class Card
{
private:
public:
};

class Hand : public Card
{
private:
public:
};

class Deck : public Hand
{
private:
public:
};

class GenericPlayer : public Hand
{
private:
public:
};

class Player : public GenericPlayer
{
private:
public:
};

class House : public GenericPlayer
{
private:
public:
};

class Game
{
private:
public:
};

int main()
{
    //Ex1
    Student student1("Petr","Male",22,65,2018);
    student1.PrintStudent();
    student1.PrintNumberStudent();
    Student student2("Maria", "Female", 19, 55, 2021);
    student2.PrintStudent();
    student2.PrintNumberStudent();
    student2.SetName("Alex");
    student2.SetGender("Male");
    student2.SetAge(20);
    student2.SetWeight(70);
    student2.SetYear(2019);
    student2.PrintStudent();
    //Ex2
    Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.GetName() << " is " << a.GetColor() << ".\n";
    std::cout << "My " << b.GetName() << " is " << b.GetColor() << ".\n";
    std::cout << "My " << c.GetName() << " is " << c.GetColor() << ".\n";
   
    return EXIT_SUCCESS;
}


