#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(char *word , int length ){
    int start = 0 , end = length -1 ;
    while(start < end){
        if(word[start++] != word[end--]){
            return false;
        }
    }

    return true;
}

int main(){
    // char s1[] = "apple";
    char s1[] = "racecar";
    cout <<  isPalindrome(s1 , strlen(s1));

}