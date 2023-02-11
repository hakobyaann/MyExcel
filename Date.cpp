#include "Date.h"

#include <string>

Day::Day(int d) : day(d) {}
Month::Month(int m) : month(m) {}
Year::Year(int y) : year(y) {}
Date::Date(const Day& d, const Month& m, const Year& y) 
    : day(d.day), month(m.month), year(y.year) {}