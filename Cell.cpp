#include "Cell.h"
#include "Date.h"
#include <iostream>
#include <map>

Cell::Cell()
{
    m_value = "";
    m_color = Color::NOCOLOR;
}

Cell::~Cell()
{
    reset();
}
    
void Cell::setValue(const std::string& value)
{
    m_value = value;
}

std::string Cell::getValue()
{
    return m_value;
}

Color Cell::getColor()
{
    return m_color;
}

int Cell::to_Int()
{
    int result = std::stoi(this->m_value);
    return result;
}

double Cell::to_Double()
{ 
    double result = std::stod(this->m_value);
    return result;
}

Date Cell::to_Date()
{
    int tmp = std::stoi(m_value);
    int d = tmp / 1000000;
    int m = (tmp % 1000000) / 10000;
    int y = tmp % 1000;
    Date date(Day(d), Month(m), Year(y + 2000));
    return date;
}

void Cell::reset()
{
    this->m_value = "";
    this->m_color = to_enum("Nocolor");
}

void Cell::set_Color(const std::string& c)
{
    this->m_color = to_enum(c);
}

Color Cell::to_enum(const std::string& c)
{
    std::map<std::string, Color> M;
    M["Green"] = Color::GREEN;
    M["Red"] = Color::RED;
    M["Yellow"] = Color::YELLOW;
    M["Nocolor"] = Color::NOCOLOR;

    return M[c];
}

std::string Cell::to_string(Color c)
{
    std::map<Color, std::string> C;
    C[Color::GREEN] = "Green";
    C[Color::RED] = "Red";
    C[Color::YELLOW] = "Yellow";
    C[Color::NOCOLOR] = "Nocolor";

    std::string result = C[c];
    return result;
}