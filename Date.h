#ifndef DATE
#define DATE

struct Day
{
    explicit Day(int);
    int day;
};

struct Month
{
    explicit Month(int);
    int month;
};

struct Year
{
    explicit Year(int);
    int year;
};

class Date
{
private:
    int year;
    int month;
    int day;
public:
    Date(const Day&, const Month&, const Year&);
};

#endif