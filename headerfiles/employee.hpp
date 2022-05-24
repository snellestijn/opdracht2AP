class Employee
{
private:
    std::string name;   //immutable
    bool busy;
    bool forkliftCertificate;

public:
    //constructor
    Employee(std::string name, bool forkLiftCertificate);

    //getters
    std::string getName();
    bool getBusy();
    bool getForkLiftCertificate();

    //setters
    void setBusy(bool busy);
    void setForkLiftCertificate(bool forkLiftCertificate);
};