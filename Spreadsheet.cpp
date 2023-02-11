#include "Spreadsheet.h"
#include <iostream>
#include <vector>

int Spreadsheet::get_row() const 
{
    return m_row;
}

int Spreadsheet::get_column() const 
{
    return m_column;
}

void Spreadsheet::setCellAt(int row, int column, Cell& cell)
{   
    if (row < 0 || row > m_row) 
    {
        std::out_of_range("Out of range");
    }
    if (column < 0 || column > m_column)
    {
        std::out_of_range("Out of range");
    }

    for (int i = 0; i < m_row; ++i)
    {
        for (int j = 0; j < m_column; ++j)
        {
            if (i == row && j == column)
            {
                m_cells[i][j] = cell;
            }
        }
    }
}

void Spreadsheet::setCellAt(int row_ind, int column_ind, const std::string& c)
{   
    if (!m_row || !m_column)
    {
        throw std::out_of_range("Invalid index!");
        return;
    }
    if (row_ind < 0 || row_ind >= m_row || column_ind < 0 || column_ind >= m_column)
    {
        throw std::out_of_range("Invalid index!");
        return;
    }
    m_cells[row_ind][column_ind].setValue(c);
}

void Spreadsheet::insert_row(int row_ind)
{
    if (row_ind >= m_row || row_ind < 0)
    {
        throw std::out_of_range("Invalid index!");
    }
    std::vector<Cell> tmp;
    m_cells.insert(m_cells.begin() + row_ind, tmp);
    ++m_row;
}

void Spreadsheet::insert_column(int column_ind)
{
    if (column_ind > 0 || column_ind < m_column)
    {
        std::vector<Cell> tmp(m_column + 1);
        for (int i = 0; i < m_row; ++i)
        {
            for (int j = 0, t = 0; j < m_column + 1; ++j, ++t)
            {
                if (j == column_ind)
                {
                    --t;
                    continue;
                }
                tmp[j] = m_cells[i][t];
            }
            m_cells[i] = tmp;
        }
    }
    ++m_column;
}

void Spreadsheet::addRow(int row_ind)
{
    if (row_ind >= 0)
    {
        m_row = row_ind;
        m_cells.resize(row_ind);
    }
    else
    {
        std::cout << "ERROR" << '\n';
        exit(0);
    }
}

void Spreadsheet::removeRow(int row_ind)
{
    if (row_ind < 0 || row_ind > m_row)
    {
        throw std::out_of_range("Invalid index!");
    }
   m_cells.erase(m_cells.begin() + row_ind);
   --m_row;
}

void Spreadsheet::removeColumn(int column_ind)
{
    if (column_ind >= m_column || column_ind < 0)
    {
        throw std::out_of_range("Invalid index!");
    }
    for (int i = 0; i < m_row; ++i)
    {
            m_cells[i].erase(m_cells[i].begin() + column_ind);
    }
    m_column--;
}


void Spreadsheet::addColumn(int column_ind)
{
    if (column_ind >= 0)
    {
        m_column = column_ind;
        vec.resize(column_ind);
        for (int i = 0; i < m_cells.size(); ++i)
        {
            if (m_cells[i].size() < column_ind)
            {
                m_cells[i].resize(column_ind);
            }
            else
            {
                m_cells.push_back(vec);
            }
        }
    }
    else
    {
        std::cout << "ERROR" << '\n';
        exit(0);
    }
}

void Spreadsheet::swapRows(int row1, int row2)
{
    std::swap(m_cells[row1], m_cells[row2]);
}

void Spreadsheet::swapColumns(int col1, int col2)
{
    for (int i = 0; i < m_row; ++i)
    {
        Cell tmp = m_cells[i][col1];
        m_cells[i][col1] = m_cells[i][col2];
        m_cells[i][col2] = tmp;
    }
}

void Spreadsheet::print()
{
    std::cout << "Row = " << m_row << std::endl;
    std::cout << "Column = " << m_column << std::endl;
    std::cout << "Size = " << m_cells.size() << std::endl;

    auto it = m_cells;
    for (int i = 0; i < m_row; ++i)
    {
        auto ii = it[i];
        std::cout << i << " ";
        for (int j = 0; j < ii.size(); ++j)
        {
            std::cout << ii[j].getValue() << " ";
        }
        std::cout << '\n';
    }
}

Cell Spreadsheet::getCellAt(int row_ind, int column_ind)
{
    if (row_ind < 0 || row_ind >= m_row || column_ind < 0 || column_ind >= m_column)
    {
        throw std::out_of_range("Can't get cell at this index!");
    }

    Cell result;
    for (int i = 0; i < m_row; ++i)
    {
        for (int j = 0; j < m_column; ++j)
        {
            if (i == row_ind && j == column_ind)
            {
                
                result = m_cells[i][j];
            }
        }
    }
    return result;
}