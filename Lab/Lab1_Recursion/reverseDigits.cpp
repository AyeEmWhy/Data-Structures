/*  LAB #1 Recursion - reverseDigits
 *   Group: Amy Jiang
 *   March 16, 2017
 *   CS/IS 211
 */

#include <iostream>
using namespace std;
int reverseDigits(int num);


int main() {
    cout << reverseDigits(456);
    return 0;
}
int reverseDigits(int num){
    static int sum = 0,temp = 1; //need static variables in order to keep the prev answers
    //temp will increase the values place (100th , 10th, 1th)
    if (num <= 0) // since int returns a decimal when theres a fraction
        sum = num; // Base case: when we divide and a value of zero/neg is returned
    else {
        reverseDigits(num/10); //reduce num by it's right most digit
        sum = sum + (num%10)*temp;
        
        temp = temp *10; //will also increase by a multiple of 10 and
        //will be multipled by mod and added by sum
        //cout << "The value of sum is " << sum << endl;
    }
    
    return sum;
    
}
