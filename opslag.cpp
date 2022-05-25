#include <iostream>
#include <vector>
#include "warehouse.hpp"
#include "opslag.hpp"
#include "employee.hpp"


//getters
bool Shelf::getSlotStatus(){
    if (this->isFull()){
        return false;
    } else {return true;}
}

//pallet methods
    bool Shelf::removePallet(int slot){
        if (pallets[slot].getItemCount()){
        this->pallets.erase(this->pallets.begin()+slot);
        return true;}
        return false;
    }
    bool Shelf::insertPallet(int slot, Pallet * pallet){
        if (!(this->isFull())){
        this->pallets.insert(pallets.begin()+slot,*pallet);
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
        if (this->pallets.size() >= 4){
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