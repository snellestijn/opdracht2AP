//alle files importeren
#include <iostream>
#include <vector>
#include "headerfiles/warehouse.hpp"
#include "headerfiles/incontainer.hpp"
#include "headerfiles/shelf.hpp"
#include "headerfiles/pallet.hpp"
#include "headerfiles/employee.hpp"

//constructor
Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount){
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    this->itemCount = itemCount;
}

//setters
std::string Pallet::getItemName(){return itemName;}
int Pallet::getItemCount(){return itemCount;}
int Pallet::getRemainingSpace(){return (itemCapacity - itemCount);}

//methodes
bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity){
    if (this->isEmpty()){
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        return true;
    } else {return false;}
}
bool Pallet::takeOne(){
    if (!(isEmpty())){
        itemCount--;
        return true;
    } else {return false;}
}
bool Pallet::putOne(){
    if (!(isFull())){
        itemCount++;
        return true;
    } else {return false;}
}

//override
bool Pallet::isFull(){return (itemCapacity - itemCount);}
bool Pallet::isEmpty(){return (itemCount == 0);}