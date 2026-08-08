#include <iostream>

using namespace std; 

bool validanagram(string str1 , string str2){
    if(str1.length() != str2.length()){
        return false;
    }

    int freq[26] = {0}; // to store the frequency of each character in the first string

    for(int i = 0 ; i<str1.length() ; i++){
        freq[str1[i] - 'a']++; // increment the frequency of the character in the first string
    }

    for(int i = 0 ; i<str2.length() ; i++){
        freq[str2[i] - 'a']--; // decrement the frequency of the character in the second string
    }

    for(int i = 0 ; i<26 ; i++){
        if(freq[i] != 0){ // if any character has a non-zero frequency, then the strings are not anagrams
            return false;
        }
    }

    return true; // if all characters have zero frequency, then the strings are anagrams
}

bool isanagram(string str1 , string str2){
    if(str1.length() != str2.length()){
        return false;
    }

    int freq[26] = {0}; // to store the frequency of each character in the first string

    for(int i = 0 ; i<str1.length() ; i++){
        freq[str1[i] - 'a']++; // increment the frequency of the character in the first string
    }

    for(int i = 0 ; i<str2.length() ; i++){
        int idx = str2[i] - 'a'; // get the index of the character in the second string
        if(freq[idx] == 0){ // if the frequency of the character is zero,
            return false; // then the strings are not anagrams
        }
        freq[idx]--; // decrement the frequency of the character in the second string
    }

    return true; // if all characters have zero frequency, then the strings are anagrams
}

int main(){
    string str1 = "anagram";
    string str2 = "nagaram";

    cout <<     isanagram(str1 , str2) << endl ; // function to check if two strings are anagrams of each other

    cout << (str1 == str2) << endl; // function to check if two strings are equal or not

    string s3 = str1 + " " + str2; // function to concatenate two strings
    cout  <<  s3 << endl; // function to print the concatenated string
    cout << (str1 != str2) << endl; // function to check if two strings are not equal or not
    
}