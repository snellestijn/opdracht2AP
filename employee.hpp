#pragma once
#include <iostream>
class Employee
{
private:
    std::string name;   //immutable
    bool busy;
    bool forkLiftCertificate;

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