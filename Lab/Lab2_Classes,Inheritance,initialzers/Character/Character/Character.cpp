/*
*   LAB #2 CLASSES, INHERITANCE, ...
*   GROUP: AMY JIANG
*   MARCH 26,2017
*/


#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

/**CHARACTER MEMEBER FUNCTIONS**/

Character::Character(string charName, string charHeight, double charWeight) : name(charName), height(charHeight), weight(charWeight), tendency(0.0), health(100.0) {
    
}

void Character::heal(double percent) {
    health += percent*100;
}
void Character::injure(double percent) {
    health -= percent*100;
}
bool Character::takeAction(double charTendency) {
    if(charTendency < -1.0 || charTendency > 1.0) {
        return false;
    } else {
        tendency = charTendency;
        return true;
    }
}
void Character::setHeight(string charHeight) {
    height = charHeight;
}
string Character::getHeight() const {
    return height;
}
void Character::setWeight(double charWeight) {
    weight = charWeight;
}
double Character::getWeight() const {
    return weight;
}
string Character::getName() const {
    return name;
}
double Character::getTendency() const {
    return tendency;
}
double Character::getHealth() const {
    return health;
}
void Character::displayAttributes() const {
    cout << "Name: " << getName() << endl
         << "Height: " << getHeight() << endl
         << "Weight: " << getWeight() << endl
         << "Tendency: " << getTendency() << endl
         << "Health: " << getHealth() << endl;
}
