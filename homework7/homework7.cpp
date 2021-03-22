
#include<iostream>
#include<memory>

//Ex1

class Date
{
private:
   int m_day;
   int m_month;
   int m_year;
public:
    Date();
    Date(int day, int month, int year);
    int GetDay() { return m_day; }
    int GetMonth() { return m_month; }
    int GetYear() { return m_year; }
    friend std::ostream &operator << (std::ostream &out, const Date &data);
 };
Date::Date()
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}
Date::Date(int day, int month, int year) :
    m_day(day), m_month(month), m_year(year) {}

std::ostream &operator<<(std::ostream &out, const Date &data)
{
    out << data.m_day << "." << data.m_month 
        << "." << data.m_year << std::endl;
    return out;
}

void PrintDate1(std::unique_ptr <Date> &date1)
{
    std::cout << "date1 - " << *date1 << std::endl;
}
void PrintDate2(std::unique_ptr <Date> &date2)
{
    std::cout << "date2 - " << *date2 << std::endl;
}

//Ex2

void datesCompare(std::unique_ptr <Date> &date1, std::unique_ptr <Date> &date2)
{
    if (date2->GetYear() > date1->GetYear())
        PrintDate2(date2);
    else if (date2->GetYear() < date1->GetYear())
        PrintDate1(date1);
    else  
    {
        if (date2->GetMonth() > date1->GetMonth())
            PrintDate2(date2);
        else if (date2->GetMonth() < date1->GetMonth())
            PrintDate1(date1);
        else 
        {
            if (date2->GetDay() > date1->GetDay())
                PrintDate2(date2);
            if (date2->GetDay() < date1->GetDay())
                PrintDate1(date1);
        }
    }
 }
void datesSwap(std::unique_ptr <Date> &date1, std::unique_ptr <Date> &date2)
{
    date2.swap(date1);
}
int main()
{
    //Ex1
    std::unique_ptr <Date> today = std::make_unique<Date>(22, 3, 2021);
    std::unique_ptr <Date> data = std::make_unique<Date>();
    today->GetDay();
    today->GetMonth();
    today->GetYear();
    std::cout << "today pointer-> " << today << "\n" << *today << std::endl;
    data = std::move(today);
    std::cout << "data pointer-> " << data << "\n" << *data << std::endl;
    std::cout << "today pointer-> " << today << "\n\n";
    //Ex2
    std::unique_ptr <Date> date1 = std::make_unique<Date>(11, 1, 2021);
    std::unique_ptr <Date> date2 = std::make_unique<Date>(22, 2, 2022);
    datesCompare(date1, date2);
    PrintDate1(date1);
    datesSwap(date1, date2);
    PrintDate1(date1);
    datesCompare(date1, date2);
}
    


