#ifndef SPREADSHEET
#define SPREADSHEET

#include <vector>

#include "Cell.h"

class Spreadsheet
{
private:
    size_t m_row;
    size_t m_column;
    std::vector<std::vector<Cell>> m_cells;
    std::vector<Cell> vec;
public:
    Spreadsheet() = default;
    ~Spreadsheet() = default;
    int get_row() const;
    int get_column() const;
    void setCellAt(int, int, Cell&);
    void setCellAt(int, int, const std::string&);
    Cell getCellAt(int, int);
    void addRow(int);
    void removeRow(int);
    void addColumn(int);
    void removeColumn(int);
    void swapRows(int, int);
    void swapColumns(int, int);
    void print();
    void insert_row(int);
    void insert_column(int);

};

#endif