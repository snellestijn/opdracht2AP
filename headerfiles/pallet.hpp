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