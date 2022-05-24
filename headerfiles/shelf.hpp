class Shelf : public IContainer
{
public:
    std::vector<Pallet> pallets;
    
    //constructor
    Shelf();

    //getters
    bool getSlotStatus();

    //pallet methods
    Pallet removePallet(int slot);
    bool insertPallet(int slot, Pallet * pallet);
    
    //overrides
    bool isEmpty() override;
    bool isFull() override;
};