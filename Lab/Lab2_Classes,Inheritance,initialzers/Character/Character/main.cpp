/*
*   LAB #2 CLASSES, INHERITANCE, ...
*   GROUP: AMY JIANG
*   MARCH 26,2017
*/


#include <iostream>
#include <string>
#include "Character.h"
#include "CombatCharacter.h"
using namespace std;

int main() {
    Character newChar("Amy", "5'5", 105.0);
    newChar.takeAction(0.5);
    newChar.injure(.02);
    newChar.heal(.1);
    newChar.setHeight("4'5");
    newChar.setWeight(200);
    newChar.displayAttributes();
    cout << endl;
    
    CombatCharacter comChar("Abby", "6'1", 105.0 , "History", 7 , "Axel" , 10);
    comChar.setShieldName("Angel");
    comChar.saveAnotherCharacter();
    comChar.getShieldName();
    comChar.getAttacked();
    comChar.getAttacked();
    comChar.injure(1.0);
    comChar.injure(.05);
    comChar.displayAttributes();
    return 0;
}
