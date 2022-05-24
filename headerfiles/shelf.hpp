class Shelf : public IContainer
{
private:
    std::vector<Pallet> pallets;

public:
    //constructor
    Shelf();

    //getters
    bool getSoloStatus();

    //pallet methods
    Pallet removePallet(int slot);
    bool insertPallet(int slot, Pallet* pallet);
    
};