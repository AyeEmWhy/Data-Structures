/*  LAB #1 Recursion - binarySearch
 *   Group: Amy Jiang
 *   March 16, 2017
 *   CS/IS 211
 */

#include <iostream>
#include <string>
using namespace std;


template <typename T, typename K>
int binarySearch(const T anArray[], int first, int last, K target) {
    int index = 0;
    if (first > last)
        index = -1; //no matches
    else {
        int mid = first + (last - first)/2; //get the midpoint
        if(target == anArray[mid])
            index = mid;
        else if (target < anArray[mid])
            index = binarySearch(anArray, first, mid - 1, target);
        else
            index = binarySearch(anArray, mid + 1, last, target);
    }
    return index;
}

int main()
{
    //double array[] = {1.2, 2.2, 3.2 };
    //char array[] = {'a','b','c'};
    string array[] = {"a", "aa", "aaaa"};
    int value = binarySearch(array, 0, 2, "aaaa");
    cout << value << endl;
    
}

