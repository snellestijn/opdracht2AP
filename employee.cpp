//alle files importeren
#include <iostream>
#include <vector>
#include "warehouse.hpp"
#include "opslag.hpp"
#include "employee.hpp"


Employee::Employee(std::string name, bool forkLiftCertificate){
    this->name = name;
    this->forkLiftCertificate = forkLiftCertificate;
    busy = false;
}

//getters
std::string Employee::getName(){return name;}
bool Employee::getBusy(){return busy;}
bool Employee::getForkLiftCertificate(){return forkLiftCertificate;}

//setters
void Employee::setBusy(bool busy){this->busy = busy;}
void Employee::setForkLiftCertificate(bool forkLiftCertificate){
    this->forkLiftCertificate = forkLiftCertificate;
}