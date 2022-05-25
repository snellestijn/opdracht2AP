#define CATCH_CONFIG_MAIN  
//files toevoegen
#include "catch.hpp"
#include "employee.hpp"
#include "warehouse.hpp"
#include "opslag.hpp"
#include <vector>

//de instanties definieren
Employee e = Employee("stijn",false);
Warehouse w = Warehouse();
Shelf s = Shelf();
Pallet p = Pallet("banaan",4,2);

//elke klasse testen
TEST_CASE("employee"){
    //getter methodes testen
    REQUIRE(e.getBusy() == false);
    REQUIRE(e.getForkLiftCertificate() == false);
    REQUIRE(e.getName() == "stijn");
    //verander atributen
    e.setBusy(true);
    e.setForkLiftCertificate(true);
    //test de getters opnieuw
    REQUIRE(e.getBusy() == true);
    REQUIRE(e.getForkLiftCertificate() == true);
}

TEST_CASE("Pallet"){
    //getter methodes testen
    REQUIRE(p.getItemName() == "banaan");
    REQUIRE(p.getItemCount() == 2);
    REQUIRE(p.getRemainingSpace() == 2);
    //probeer oopnieuw te assignen
    REQUIRE(p.reallocateEmptyPallet("appel", 4) == false);
    //verander de count en test het aantal
    p.takeOne();
    REQUIRE(p.getItemCount() == 1);
    p.putOne();p.putOne();p.putOne();
    REQUIRE(p.getItemCount()== 4);
    p.putOne();
    REQUIRE(p.getItemCount()== 4);
    p.takeOne();p.takeOne();p.takeOne();p.takeOne();
    //probeer opnieuw te assignen nu de itemcount leeg is
    REQUIRE(p.reallocateEmptyPallet("appel",4) == true);
    //getter methode testen
    REQUIRE(p.getRemainingSpace() == 4);
}

TEST_CASE("shelf"){
    //test get slotstatus (of er een slot beschikbaar is)
    REQUIRE(s.getSlotStatus() == true);
    //zet 4 pallets in de shelf
    Pallet p2 = Pallet("drop",4,3);
    Pallet p3 = Pallet("aardappel",4,1);
    Pallet p4 = Pallet("snoep",4,4);
    Pallet p5 = Pallet("shirt",4,2);
    std::vector<Pallet> pals = {p2,p3,p4,p5};
    for (Pallet pal : pals){
        s.insertPallet(0,pal);
    }
    //test opnieuw of de get slot status werkt wanneer er geen plek vrij is
    REQUIRE(s.getSlotStatus() == false);
    //verwijder een pallet
    s.removePallet(2);
    //kijk of de shelf vol zit
    REQUIRE(s.isFull() == false);
    //voeg pallet toe
    s.insertPallet(0,p);
    //test of de shelf nu wel vol zit
    REQUIRE(s.isFull() == true);
    
}

TEST_CASE("warehouse"){
    //voeg banaan toe aan shelf
    //voeg employee en shelf toe aan het warehouse
    w.addEmployee(e);
    w.addShelf(s);
    //test rearannge functie tijdens busy
    REQUIRE(w.rearrangeShelf(s,e) == false);
    //test rearange tijdens niet busy
    e.setBusy(false);
    REQUIRE(w.rearrangeShelf(s,e) == true);
    //pak items die op zijn
    REQUIRE(w.pickItems("appel",2) == false);
    //pak items die er wel nog zijn
    REQUIRE(w.pickItems("shirt",2) == true);
    
}  




