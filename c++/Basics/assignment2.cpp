#include <iostream>
#include <iomanip>

using namespace std; 

enum Category{
    ESSENTIAL, 
    FOOD,
    GENERAL, 
    LUXURY
};

struct Item{
    string name ;
    float price ;
    int quantity ; 
    Category category ;
};

typedef struct Item item ;

int main(){
    int n; float sum = 0 , gst_value = 0.18 ;
    cout << "Enter the number of items: " << endl ; 
    cin >> n ; 
    item arr[n] ;

    for(int i = 0 ; i<n ; i++){
        cout << "Enter the name of item " << i+1 << ": " << endl ; 
        cin >> arr[i].name ; 
        cout << "Enter the price of item " << i+1 << ": " << endl ; 
        cin >> arr[i].price ; 
        cout << "Enter the quantity of item " << i+1 << ": " << endl ; 
        cin >> arr[i].quantity ; 
    }

    // calculate bill amount 

    for(int i = 0 ; i<n ; i++){
        float bill = arr[i].price * arr[i].quantity ; 
        cout << "Bill amount for item " << arr[i].name << " is : " << bill << endl ; 
        sum += bill ;
    }

    cout << "Total bill amount is : " << sum + (sum * gst_value) << endl ; 
}
