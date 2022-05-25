//alle files importeren
#include <iostream>
#include <vector>
#include "warehouse.hpp"
#include "opslag.hpp"
#include "employee.hpp"

//constructor
Warehouse::Warehouse(){
    shelves = {};
    employees = {};
}


//adds
void Warehouse::addEmployee(Employee employee){
    this->employees.push_back(employee);
}
void Warehouse::addShelf(Shelf shelf){
    this->shelves.push_back(shelf);
}

//methods
bool Warehouse::rearrangeShelf(Shelf & shelf,Employee employee){
    if (!employee.getForkLiftCertificate() || employee.getBusy()){return false;}
    int x = 0;
    if (shelf.pallets.size() > 1){
        while (x < 3){
            int een = shelf.pallets[x].getItemCount(); int twee = shelf.pallets[(x+1)].getItemCount();
            if (een > twee){
                std::swap(shelf.pallets[x],shelf.pallets[(x+1)]);
                x = 0;
            }
            else { x++;}}
    } return true;
}
bool Warehouse::pickItems(std::string itemName, int itemCount){
    for (Shelf shelf : this->shelves){
        for (Pallet pallet : shelf.pallets){
            std::cout << pallet.getItemName() << " " << pallet.getItemCount()<<"\n";
            if ((pallet.getItemName() == itemName) && (pallet.getItemCount() >= itemCount)){
                for (int i = 0; i < itemCount ; i++){
                    pallet.takeOne();
                }
                return true;
            }
        }
    }
    return false;
}
