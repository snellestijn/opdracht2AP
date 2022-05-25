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

    //get employee naam
    std::string getName();
    //get busy status
    bool getBusy();
    //get forkliftcertificaat: geeft aan of in staat is tot bepaalde taken te doen
    bool getForkLiftCertificate();

    //set busy status
    void setBusy(bool busy);
    //set forkliftcertificaat 
    void setForkLiftCertificate(bool forkLiftCertificate);

};