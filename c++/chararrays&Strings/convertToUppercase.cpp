#include <iostream>
#include <cstring>


using namespace std;

void convertToUpper(char *ch , int n){

    for(int i = 0 ;i<n; i++){
        char character = ch[i];
        if(character >= 65 && character <=90){
            continue ;
        }else{
            int pos = character - 'a';
            ch[i] = 'A' + pos;
        }
    }
}
void convertToLower(char *ch , int n){

    for(int i = 0 ;i<n; i++){
        char character = ch[i];
        if(character >= 97 && character <=122){
            continue ;
        }else{
            int pos = character - 'A';
            ch[i] = 'a' + pos;
        }
    }
}



void convertToUpper2(char *ch , int n){

    for(int i = 0 ;i<n; i++){
        char character = ch[i];
        if(islower(character)){
            ch[i] = toupper(character);
        }
    }
}

int main(){
    // char str[] = "ApPle";
    // char str[] = "abcde";
    char str[] = "ABCDE";

    cout << str << endl;
    convertToLower(str , strlen(str));
    cout << str << endl;
}