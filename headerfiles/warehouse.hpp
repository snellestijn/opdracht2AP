class Warehouse
{
private:
    std::vector<Shelf> shelves;
    std::vector<Employee> employees;

public:
    //constructor
    Warehouse();

    //adds
    void addEmployee(Employee employee);
    void addShelf(Shelf shelf);

    //methods
    bool rearrangeShelf(Shelf & shelf);
    bool pickItems(std::string itemName, int itemCount);

};