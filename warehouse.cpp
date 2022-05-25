//alle files importeren
#include <iostream>
#include <vector>
#include "warehouse.hpp"
#include "opslag.hpp"
#include "employee.hpp"


//adds
void Warehouse::addEmployee(Employee employee){
    this->employees.push_back(employee);
}
void Warehouse::addShelf(Shelf shelf){
    this->shelves.push_back(shelf);
}

//methods
bool Warehouse::rearrangeShelf(Shelf & shelf){
    int x = 0;
    while (x < 3){
        int een = shelf.pallets[x].getItemCount(); int twee = shelf.pallets[(x+1)].getItemCount();
        if (een > twee){
            int temp = een;
            een = twee;
            twee = temp;
            x +=1;
        }
        else { x = 0;}
    } return true;
}
bool Warehouse::pickItems(std::string itemName, int itemCount){
    for (Shelf shelf : this->shelves){
        for (Pallet pallet : shelf.pallets){
            if ((pallet.getItemName() == itemName) && (pallet.getItemCount() == itemCount)){
                return true;
            }
        }
    }
    return false;
}