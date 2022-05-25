//opdracht 2 van adaptive programming

//alle files importeren
#include <iostream>
#include <vector>
#include "warehouse.hpp"
#include "opslag.hpp"
#include "employee.hpp"


int main(){
    
/* Demonstratie van werkende code.
 De output van de code kan als leeg beschouwd worden. Maar dit is gedaan
 zodat het een overzichtelijke weergave biedt. In de comments van de code
 is terug te lezen wat deze output inhoudt*/

/* Enkele ojecten maken van de gemaakte klassen */
Employee stijn = Employee("stijn",false);
Pallet schoenen = Pallet("schoen",100,5);
Pallet shirts = Pallet("shirt",20,3);
Shelf kleding = Shelf();
Warehouse kelder = Warehouse();

/* verbanden leggen tussen de objecten */
kleding.insertPallet(0,schoenen);
kleding.insertPallet(0,shirts);
kelder.addShelf(kleding);
kelder.addEmployee(stijn);

/* demo employee */
std::cout << stijn.getBusy() << "\n";       //output: 0, want busy is standaard false in de constructor
stijn.setBusy(true);                        //*zet busy-status true*
std::cout << stijn.getBusy() << "\n\n";     //output: 1, want busy-status is op true gezet /

/* demo pallet */
std::cout << shirts.getRemainingSpace() << "\n";        //output: 17, want 3 van de 20 plekken zijn bezet
shirts.putOne();                                        //*voeg een shirt toe*
std::cout << shirts.getRemainingSpace() << "\n\n";      //output: 16, want 4 van de 20 plekken zijn bezet

/* demo warehouse */
std::cout << kelder.rearrangeShelf(kleding,stijn) << "\n\n"; //output: 0, taak is false want employee heeft
                                                             //niet de forkliftcertificaat

/* demo shelf */
std::cout << kleding.isEmpty() << "\n";             //output: 0, want kleding is niet leeg
kleding.removePallet(0); kleding.removePallet(0);   //*verwijder shirts en schoenen uit kleding*
std::cout << kleding.isEmpty() << "\n\n";           //output: 1, want kleding is nu wel leeg


return 0;
}