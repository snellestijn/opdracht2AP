#pragma once
class IContainer
{
public:
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};

class Pallet : public IContainer
{
private:
    int itemCount;          //only mutable through taking an putting
    std::string itemName;   //only mutable if empty
    int itemCapacity;       //only mutable if empty

public:
    //constructor
    Pallet(std::string itemName, int itemCapacity, int itemCount);

    //getters
    std::string getItemName();
    int getItemCount();
    int getRemainingSpace();

    //methodes
    bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
    bool takeOne();
    bool putOne();

    //overrides
    bool isFull() override;
    bool isEmpty() override;
};

class Shelf : public IContainer
{
public:
    std::vector<Pallet> pallets;
    
    //constructor
    Shelf();

    //getters
    bool getSlotStatus();

    //pallet methods
    bool removePallet(int slot);
    bool insertPallet(int slot, Pallet * pallet);
    
    //overrides
    bool isEmpty() override;
    bool isFull() override;
};

