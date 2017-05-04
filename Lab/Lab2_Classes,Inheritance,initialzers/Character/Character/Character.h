/*
*   LAB #2 CLASSES, INHERITANCE, ...
*   GROUP: AMY JIANG
*   MARCH 26,2017
*/



#ifndef Character_h
#define Character_h
#include <iostream>
#include <string>
using namespace std;

class Character {
    private:
        string name;
        string height;
        double weight;
        double tendency;
        double health;
    
    public:
        Character(string charName, string charHeight, double charWeight);
        void heal(double percent);
        void injure(double percent);
        bool takeAction(double charTendency);
    
        void setHeight(string charHeight);
        string getHeight() const;

        void setWeight(double charWeight);
        double getWeight() const;
   
        string getName() const;
        double getTendency() const;
        double getHealth() const;
    
        void displayAttributes() const;
};

#endif /* Character_h */
