#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, string& str){
    if( i>= str.length()/2)
    return true;

    if(str[i] != str[str.length()-i-1])
    return false;

    return isPalindrome(i+1, str);
}

int main(){
    string str;
    cout << "Enter a string: ";
    // cin >> str; // cin doesnt read spaces, so it will only read until the first space character
    getline(cin, str); // to read the entire line including spaces

    
    str.erase(remove(str.begin(), str.end(), '!'), str.end()); // remove exclamation marks from the string
    str.erase(remove(str.begin(), str.end(), ':'), str.end()); // remove colons from the string
    str.erase(remove(str.begin(), str.end(), '.'), str.end()); // remove periods from the string
    str.erase(remove(str.begin(), str.end(), ','), str.end()); // remove commas from the string
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); // remove spaces from the string

    if(isPalindrome(0, str))
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;

    return 0;
}

 