#pragma once
#include "opslag.hpp"
#include "employee.hpp"
#include <vector>
class Warehouse
{
private:
    std::vector<Shelf> shelves;
    std::vector<Employee> employees;

public:
    //constructor
    Warehouse();

    //voeg employee toe aan vector met employees
    void addEmployee(Employee employee);
    //voeg shelf toe aan vector met shelfves
    void addShelf(Shelf shelf);

    //verander de volgorde van pallets in een shelf
    bool rearrangeShelf(Shelf & shelf, Employee employee);
    //pak voorwerpen uit een shelf
    bool pickItems(std::string itemName, int itemCount);

};