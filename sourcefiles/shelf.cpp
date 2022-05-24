//alle files importeren
#include <iostream>
#include <vector>
#include "headerfiles/warehouse.hpp"
#include "headerfiles/incontainer.hpp"
#include "headerfiles/shelf.hpp"
#include "headerfiles/pallet.hpp"
#include "headerfiles/employee.hpp"

//getters
bool Shelf::getSlotStatus(){
    if (this->isFull()){
        return false;
    } else {return true;}
}

//pallet methods
    Pallet Shelf::removePallet(int slot){
        this->pallets.erase(this->pallets.begin()+slot);
    }
    bool Shelf::insertPallet(int slot, Pallet * pallet){
        if (!(this->isFull())){
        this->pallets.insert(pallets.begin()+slot,*pallet);
        }
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