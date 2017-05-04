/*  LAB #1 Recursion - maxArray
 *   Group: Amy Jiang
 *   March 16, 2017
 *   CS/IS 211
 */



#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
T maxArray(const T anArray[],int first, int last);

int main() {
    double arr[] = { 1.5 , 2.3 , 5.6 , 2.3};
    
    cout << fixed << setprecision(2) << maxArray(arr, 0, 3) << endl;
    
    return 0;
}

template <typename T>
T maxArray(const T anArray[],int first, int last) {
    T maxValue;
    if(first == last) //**BASE CASE:**  return value @ index: 0
        maxValue = anArray[first]; //return this value since it is the only one in the array
    else {          //**RECURSIVE CASE ** compares leftArr to rightArr. maxValue is returned.
        int midpoint = first + (last - first)/2;
        T leftArr = maxArray(anArray, first, midpoint);
        T rightArr = maxArray(anArray, midpoint+1, last);
    
        if(leftArr > rightArr) //when leftArr's value is greater than rightArr's value
            maxValue = leftArr;
        
        else if (leftArr < rightArr) //when rightArr's value is greater than leftArr's value
            maxValue = rightArr;
            
        else //leftArr == rightArr
            maxValue = leftArr; //this can be either rightArr or leftArr, it doesn't matter
    }
    return maxValue;
}
