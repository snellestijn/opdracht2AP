#pragma once
//interface klasse
class IContainer
{
public:
    //functie kijkt of iets vol is
    virtual bool isEmpty() = 0;
    //functie kijkt of iets leeg is
    virtual bool isFull() = 0;
};

//klasse van pallet
class Pallet : public IContainer
{
private:
    int itemCount;          //only mutable through taking an putting
    std::string itemName;   //only mutable if empty
    int itemCapacity;       //only mutable if empty

public:
    //constructor
    Pallet(std::string itemName, int itemCapacity, int itemCount);

    //get naam van item
    std::string getItemName();
    //get aantal van item
    int getItemCount();
    //get aantal plekken over in de pallet
    int getRemainingSpace();

    //verkrijg een lege plek in de pallet
    bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
    //pak een item
    bool takeOne();
    //leg een item neer
    bool putOne();

    //override de is vol functie
    bool isFull() override;
    //override de is leeg functie
    bool isEmpty() override;
};

//klasse van shelf
class Shelf : public IContainer
{
public:
    std::vector<Pallet> pallets;
    
    //constructor
    Shelf();

    //get de de beschikbaarheid van een slot (niet vol)
    bool getSlotStatus();

    //verwijder een pallet
    bool removePallet(int slot);
    //voeg een pallet toe
    bool insertPallet(int slot, Pallet pallet);
    
    //overrides
    bool isEmpty() override;
    bool isFull() override;

};

