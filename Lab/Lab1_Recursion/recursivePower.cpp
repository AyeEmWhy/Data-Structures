/*  LAB #1 Recursion - recursivePower
 *   Group: Amy Jiang
 *   March 16, 2017
 *   CS/IS 211
 */

#include <iostream>
#include <string>
using namespace std;

double recursivePower(double a, int n) ;
int main()
{
    cout << recursivePower(-5.5, 3);
}
/*pre: double a is a real number
 **     int n is a non-negative integer ( n >= 0 )
 **post: a double value will be returned computed by a raised to the power of n
 */
double recursivePower(double a, int n) {
    //a is the value being multipled by values of n; n cannot be neg
    //base case let n = 0 when this occurs we end the call
    if(n == 0) //a number raised to zero is always 1
        return 1;
    else {
        return a*recursivePower(a, n-1);
    }
}
