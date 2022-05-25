#include <iostream>
#include <vector>
#include "warehouse.hpp"
#include "opslag.hpp"
#include "employee.hpp"

//Constructor
Shelf::Shelf(){
    pallets = {};
}

//getters
bool Shelf::getSlotStatus(){
    if (this->isFull()){
        return false;
    } else {return true;}
}

//pallet methods
bool Shelf::removePallet(int slot){
    if (pallets.size() > slot){
    this->pallets.erase(this->pallets.begin()+slot);
    return true;}
    return false;
}
bool Shelf::insertPallet(int slot, Pallet pallet){
    if (!(isFull())){
    pallets.insert(pallets.begin()+slot,pallet);
    return true;
    } return false;
}

//overrides
bool Shelf::isEmpty(){
    if (this->pallets.size()){
        return false;
    } else { return true; }
}
bool Shelf::isFull(){
    if (pallets.size() == 4){
        return true;
    } else { return false; }
}

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
        this->itemCount = 0;
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
    if (!isFull()){
        this->itemCount++;
        return true;
    } else {return false;}
}

//override
bool Pallet::isFull(){return (getRemainingSpace() == 0? true : false);}
bool Pallet::isEmpty(){return (itemCount == 0);}