#include <iostream>
#include <cstring>

using namespace std;


int main(){

    char name1[] = "yash";
    char name2[] = "yasha"; 
    int result = strcmp(name1 , name2) ; 
    cout << result << endl;
    return 0;
}