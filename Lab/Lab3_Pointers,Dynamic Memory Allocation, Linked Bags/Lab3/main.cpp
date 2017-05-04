/* LAB #3: Pointers, Dynamic Memory Allocation, Linked Bags
 * DATE: 04/11/2017
 * GROUP MEMBERS: Amy Jiang
 */
#include <iostream>
#include <vector>
#include "LinkedBag.h"
using namespace std;

int main() {
    LinkedBag<int> bag1;
    bag1.add(1);
    bag1.add(2);
    bag1.add(3);
    bag1.add(4);
	bag1.add(4);
	bag1.add(4);
	bag1.add(7);

	LinkedBag<int> bag2;
    bag2.add(4);
	bag2.add(4);
    bag2.add(5);
    bag2.add(1);
    bag2.add(5);

	cout << "The items in bag1 are: ";
	vector<int> vec1 = bag1.toVector();
	for (int a = 0; a < bag1.getCurrentSize(); a++) {
		cout << vec1[a] << " ";
	}

	cout << "\nThe items in bag2 are: ";
	vector<int> vecTwo = bag2.toVector();
	for (int b = 0; b < bag2.getCurrentSize(); b++) {
		cout << vecTwo[b] << " ";
	}
	cout << "\n";
    /**TEST FOR: UNION METHOD**/
    LinkedBag<int> uni;
	LinkedBag<int> uni2 = uni.unionMethod(bag1, bag2);
    vector<int> vec = uni.unionMethod(bag1, bag2).toVector();
    cout << "\n The union method has executed. The size of LinkedBag is: " << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
    
    /**TEST FOR: INTERSECTION METHOD*/
	LinkedBag<int> inter;
    vector<int> vec2 = inter.intersection(bag1, bag2).toVector(); //returns a newBag & turn it into a vector
    cout << "\nThe intersection method has executed. The size of LinkedBag is: " << vec2.size() << endl;
    for (int j = 0; j < vec2.size(); j++){
        cout << vec2[j] << " ";
    }
    cout << "\n"; 
	system("PAUSE");
    return 0;
}
