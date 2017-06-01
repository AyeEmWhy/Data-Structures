/* LAB #5: Pointers, Dynamic Memory Allocation, Linked Bags
* DATE: 05/31/2017
* GROUP MEMBERS: Amy Jiang
*/
#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations
using namespace std;

int main()
{
	LinkedList<int> llist;
	LinkedList<int>* listptr = &llist;
	//note: inserts from head
	llist.insert(1,4);
	llist.insert(2,123);
	llist.insert(3,72);
	llist.insert(4, 5);
	llist.insert(1, 65);

	cout << "The current length is: " << llist.getLength() << endl;
	llist.remove(5);
	cout << "Once the last position is removed the length is: " << llist.getLength() << endl;
	cout << "Is number 66 contained in the LinkedList? If so at position: " << llist.contains(66) << endl;
	cout << "The largest value in the current LinkedList is: " << llist.findLargest() << endl;
	cout << "The last value in the LinkedList is: " << llist.getLast() << endl;

	system("PAUSE");
	return 0;
}  // end main
