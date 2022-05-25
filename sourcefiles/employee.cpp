//alle files importeren
#include <iostream>
#include <vector>
#include "headerfiles/warehouse.hpp"
#include "headerfiles/incontainer.hpp"
#include "headerfiles/shelf.hpp"
#include "headerfiles/pallet.hpp"
#include "headerfiles/employee.hpp"

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