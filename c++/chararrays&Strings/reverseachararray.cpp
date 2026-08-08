#include <iostream>
#include <cstring>

using namespace std;

void reverse(char *word , int n ){


    int start = 0 , end = n-1; 
    for(int i = 0 ; i<n ; i++){
        if(start>end) break;
        swap(word[start] , word[end]);
        start++; 
        end--;
    }

}

void reverse2(char *word , int n ){

    int start = 0 , end = n-1 ; 
    while (start < end ){
        swap(word[start++] , word[end--]);
    }

}

int main(){
    char word[] = "code";

    cout << word << endl;

    // reverse(word , strlen(word));
    reverse2(word , strlen(word));

    cout << word << endl;
}