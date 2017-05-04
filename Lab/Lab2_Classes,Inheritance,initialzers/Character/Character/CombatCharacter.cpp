/*
*   LAB #2 CLASSES, INHERITANCE, ...
*   GROUP: AMY JIANG
*   MARCH 26,2017
*/



#include <iostream>
#include <string>
#include "CombatCharacter.h"
#include "Character.h"

CombatCharacter::CombatCharacter(string charName, string charHeight, double charWeight, string wepName, int wepStr, string shiName, int shiStr) :Character(charName, charHeight, charWeight),  weaponName(wepName), weaponStrength(wepStr), shieldName(shiName), shieldStrength(shiStr)
{
    
}
bool CombatCharacter::useWeapon() {
    if(getWeaponStrength() == 0 || getHealth() == 0) {
        return false;
    } else {
        injure(0.05);
        weaponStrength -= 1;
        takeAction(takeAction(getTendency()) - 0.2);
        return true;
    }
}
bool CombatCharacter::getAttacked() {
    if( getShieldStrength() ==  0) {
        injure(0.15);
    } else {
        shieldStrength -= 1;
    }
    return true;
}
bool CombatCharacter::saveAnotherCharacter() {
    if(getHealth() == 0.0) {
        return false;
    } else {
        takeAction(takeAction(getTendency()) + 0.2);
        heal(0.05);
        shieldStrength += 1;
        return true;
    }
}
bool CombatCharacter::reloadWeapon() {
    if(getHealth() == 0) {
        return false;
    } else {
        weaponStrength += 1;
        takeAction(takeAction(getTendency()) - 0.1);
        return true;
    }
}
bool CombatCharacter::noHealth() {
    if(getHealth() == 0) {
        return false; //character has no health return 0.
    } else {
        return true; //character has health return 1.
    }
}
void CombatCharacter::displayAttributes() const {
    Character::displayAttributes();
    cout << "Weapon Name: " << getWeaponName() << endl
    << "Weapon Strength: " << getWeaponStrength() << endl
    << "Shield Name: " << getShieldName() << endl
    << "Shield Strength: " << getShieldStrength() << endl;
    if(getHealth() == 0) {
        cout << getName() << " has unfortunately died!" << endl;
    }
}
void CombatCharacter::setWeaponName(string wepName) {
    weaponName = wepName;
}
string CombatCharacter::getWeaponName() const {
    return weaponName;
}
void CombatCharacter::setShieldName(string shiName) {
    shieldName = shiName;
}
string CombatCharacter::getShieldName() const {
    return shieldName;
}
int CombatCharacter::getWeaponStrength() const {
    return weaponStrength;
}
int CombatCharacter::getShieldStrength() const {
    return shieldStrength;
}
