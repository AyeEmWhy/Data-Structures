/*
*   LAB #2 CLASSES, INHERITANCE, ...
*   GROUP: AMY JIANG
*   MARCH 26,2017
*/



#ifndef CombatCharacter_h
#define CombatCharacter_h
#include "Character.h"
#include <iostream>
#include <string> 
using namespace std;

class CombatCharacter : public Character {
private:
    string weaponName;
    int weaponStrength;
    string shieldName;
    int shieldStrength;
    
public:
    CombatCharacter(string charName, string charHeight, double charWeight, string wepName, int wepStr, string shiName, int shiStr);
    bool useWeapon();
    bool getAttacked();
    bool saveAnotherCharacter();
    bool reloadWeapon();
    bool noHealth();
    //overlod display attributes.
    void displayAttributes() const;
    void setWeaponName(string wepName);
    void setShieldName(string shiName);
    string getWeaponName() const;
    string getShieldName() const;
    int getWeaponStrength() const;
    int getShieldStrength() const;
};


#endif /* CombatCharacter_h */
