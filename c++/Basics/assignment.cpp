/*

Input a side of a Square . You have to output the area of the square 

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    float side , area ; 
    cout << "Enter the value of side of square: " << endl ; 
    cin >> side ; 
    area = side*side ; 
    cout << setw(4) << "Area of square with side " << side << " is : " << area << endl ;
}