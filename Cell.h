#ifndef CELL
#define CELL

#include <string> 

#include "Date.h"

enum class Color
{
    RED,
    GREEN,
    YELLOW,
    NOCOLOR
};

class Cell
{
private:
    std::string m_value;
    Color m_color; 
public:
    Cell();
    ~Cell();
public:
    void setValue(const std::string&);
    std::string getValue();
    Color getColor();
    int to_Int();
    double to_Double();
    Date to_Date();
    void reset();
    void set_Color(const std::string&);
    Color to_enum(const std::string&);
    std::string to_string(Color);
};

#endif