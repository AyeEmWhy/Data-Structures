/* LAB #5: Pointers, Dynamic Memory Allocation, Linked Bags
* DATE: 05/31/2017
* GROUP MEMBERS: Amy Jiang
*/
#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include <string>
#include <cassert>
using namespace std;

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; // Pointer to first node in the chain;
	Node<ItemType>* tailPtr;
	// (contains the first entry in the list)
	int itemCount;           // Current count of list items 

	// Locates a specified node in this linked list.
	// @pre  position is the number of the desired node;
	//       position >= 1 and position <= itemCount.
	// @post  The node is found and a pointer to it is returned.
	// @param position  The number of the node to locate.
	// @return  A pointer to the node at the given position.
	Node<ItemType>* getNodeAt(int position) const;

public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	double sum() const;
	int getPosition(const ItemType);
	bool contains(ItemType) const;
	ItemType findLargest() const;
	ItemType getLast() const;
	/** @assert if position < 1 or
	position > getLength(). */
	ItemType getEntry(int position) const;

	/** @assert if position < 1 or
	position > getLength(). */
	void replace(int position, const ItemType& newEntry);
}; // end LinkedList

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0), tailPtr(nullptr)
{
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
	Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

	if (origChainPtr == nullptr)  
		headPtr = nullptr;  // Original list is empty
	
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());

		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
		origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			// Create a new node containing the next item 
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);

			// Advance pointer to new last node      
			newChainPtr = newChainPtr->getNext();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		}  // end while
		newChainPtr->setNext(nullptr);              // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		// Create a new node containing the new entry 
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		// Attach new node to chain
		if (newPosition == 1)
		{
			// Insert new node at beginning of chain
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;

			/**SET TAILPTR HERE ONCE ONLY WHEN LENGTH IS ZERO**/
			if (getLength() == 0)
				tailPtr = newNodePtr;
		}
		else
		{
			// Find node that will be before new 
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

			// Insert new node after node to which prevPtr points
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);

			/**ADD TAILPTR TO END OF THE LIST **/
			while(prevPtr != nullptr) {
				tailPtr = prevPtr;
				prevPtr = prevPtr->getNext();
			}

		}  // end if
		
		itemCount++;  // Increase count of entries
	}  // end if

	return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 1)
		{
			// Remove the first node in the chain
			curPtr = headPtr; // Save pointer to node
			headPtr = headPtr->getNext();
		}
		else
		{
			// Find node that is before the one to delete
			Node<ItemType>* prevPtr = getNodeAt(position - 1);

			// Point to node to delete
			curPtr = prevPtr->getNext();

			// Disconnect indicated node from chain by connecting the
			// prior node with the one after
			prevPtr->setNext(curPtr->getNext());

			/**CHANGE THE TAILPTR IF ITS THE LAST POSITION**/
			if (position == getLength()) 
				tailPtr = getNodeAt(position - 1);

		}  // end if

		// Return node to system
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;

		itemCount--;  // Decrease count of entries
	}  // end if

	return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
	// Enforce precondition with an assert - better with exception
	assert( (position >= 1) && (position <= itemCount));
	
	Node<ItemType>* nodePtr = getNodeAt(position);
	return nodePtr->getItem();
	
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::replace(int position, const ItemType& newEntry)
{
	// Enforce precondition with assert - better with exception
	assert((position >= 1) && (position <= itemCount));
	
	Node<ItemType>* nodePtr = getNodeAt(position);
	nodePtr->setItem(newEntry);
}  // end replace

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	// Debugging check of precondition
	assert((position >= 1) && (position <= itemCount));

	// Count from the beginning of the chain
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
		curPtr = curPtr->getNext();

	return curPtr;
}  // end getNodeAt
//  End of implementation file.

template<class ItemType>
double LinkedList<ItemType>::sum() const {
	double sumOfNumbers = 0;
	Node<ItemType>* curPtr = headPtr;
	for (int i = 0; i < itemCount; i++) {
		sumOfNumbers += curPtr->getItem();
		curPtr = curPtr->getNext();
	}
	return sumOfNumbers;
}

template<class ItemType>
int LinkedList<ItemType>::getPosition(const ItemType item) {
	Node<ItemType>* curPtr = headPtr;
	int count = 1;
	while (curPtr != nullptr) {
		if (curPtr->getItem() == item) 
			return count;
		else {
			count++;
			curPtr = curPtr->getNext();
		}
	}
	return -1; //-1 indicates not found
}
/*
 * 2. Add a contains method to the LinkedList (you already did this in homework)
 * Add a member method to the LinkedList named contains that takes one argument 
 * of type ItemType. The method should return true if the argument is in the List and false if not.
 */
template<class ItemType>
bool LinkedList<ItemType>::contains(ItemType itemToLookFor) const {
	bool checkIfContains = false;
	Node<ItemType>* curPtr = headPtr;
	while (curPtr != nullptr && !checkIfContains) {
		if (curPtr->getItem() != itemToLookFor) 
			curPtr = curPtr->getNext();
		checkIfContains = true;
	}
	return checkIfContains;
}

/* 3. Add a method named findLargest to the LinkedList
 * a. The findLargest method should return the largest item in the list.
 * So if it’s a list of ints and the node with the largest int contains a 1000
 * the method should return 1000. Note this method will only work with lists that 
 * contain items that can be compared with the < and >.
*/
template<class ItemType>
ItemType LinkedList<ItemType>::findLargest() const {
	ItemType largestValue;
	ItemType checkCurrent;
	Node<ItemType>* curPtr = headPtr;
	largestValue = curPtr->getItem();
	while (curPtr != nullptr) {
		checkCurrent = curPtr->getItem();
		if (checkCurrent >= largestValue) 
			largestValue = checkCurrent;
		curPtr = curPtr->getNext();

	}
	return largestValue;
}

/*
 * 4. Add a getLast method to the LinkedList
 * Add a getLast member method to the LinkedList that returns the 
 * value in the last node of the list
*/
template<class ItemType>
ItemType LinkedList<ItemType>::getLast() const {
	ItemType item = tailPtr->getItem();
	return item;
}

#endif 
