#include "Tester.h"

void TestCellFunctions()
{
    std::cout << std::endl;
    std::cout << "Cell functions: " << std::endl;
    std::cout << std::endl;
    Cell cell;
    cell.setValue("41");
    if (cell.to_Int() == 41)
    {
        std::cout << "setValue() - passed!" << std::endl;
        std::cout << "toInt() - passed!" << std::endl;
    }

    std::string str = cell.getValue();
    if(str == "41")
    {
        std::cout << "getValue - passed!" << std::endl;
    }    

    cell.reset();
    if (cell.getValue() == "" && cell.getColor() == Color::NOCOLOR)
    {
        std::cout << "reset() - passed!" << std::endl;
    }

    cell.setValue("41.5");
    if (cell.to_Double() == 41.5)
    {
        std::cout << "to_Double() - passed!" << std::endl;
    }

    cell.set_Color("Green");
    if (cell.to_string(cell.getColor()) == "Green")
    {
        std::cout << "set_Color() - passed!" << std::endl;
        std::cout << "get_Color() - passed!" << std::endl;        
        std::cout << "to_string() - passed!" << std::endl;  
    }
}

void TestSpreadsheetFunctions()
{    
    std::cout << std::endl;
    std::cout << "Spreadsheet functions: " << std::endl;
    std::cout << std::endl;
    Spreadsheet spreadsheet;
    int size = 2;
    spreadsheet.addRow(size);
    spreadsheet.addColumn(size);
    if (spreadsheet.get_row() == size && spreadsheet.get_column() == size)
    {
        std::cout << "addRow() - passed! " << std::endl;
        std::cout << "addColumn() - passed! " << std::endl;
        std::cout << "get_row() - passed! " << std::endl;
        std::cout << "get_column() - passed! " << std::endl;
    }
    spreadsheet.setCellAt(0, 0, "42");
    Cell cl = spreadsheet.getCellAt(0, 0);
     if (cl.getValue() == "42")
    {
        std::cout << "setCellAt() - passed!" << std::endl;
        std::cout << "getCellAt() - passed!" << std::endl;
    }
    spreadsheet.insert_column(0);
    spreadsheet.insert_row(0);
    if (spreadsheet.get_column() == size + 1 && spreadsheet.get_row() == size + 1)
    {
        std::cout << "insert_column() - passed!" << std::endl;
        std::cout << "insert_row() - passed!" << std::endl;
    }

    spreadsheet.removeRow(0);
    spreadsheet.removeColumn(0);
    if (spreadsheet.get_row() == size && spreadsheet.get_column() == size)
    {
        std::cout << "removeRow() - passed!" << std::endl;
        std::cout << "removeColumn() - passed!" << std::endl;
    }
    spreadsheet.setCellAt(0, 0, "Anna");
    spreadsheet.setCellAt(1, 0, "Lily");
    spreadsheet.swapRows(0, 1);
    Cell c = spreadsheet.getCellAt(0, 0);
    if (c.getValue() == "Lily")
    {
        std::cout << "swapRows() - passed!" << std::endl;
    }
    c.reset();
    spreadsheet.swapColumns(0, 1);
    c = spreadsheet.getCellAt(0, 0);
    if (c.getValue() == "")
    {
        std::cout << "swapColumns() - passed!" << std::endl;
    }
}