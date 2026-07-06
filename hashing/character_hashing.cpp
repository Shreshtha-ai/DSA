#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Input a string:";
    cin>> s;

    int hash[256] = {0};
    for(int i=0; i<s.size(); i++ ){
        hash[s[i]]++;
    }
    cout<<"What character do you want to find the frequency of? ";
    char ch;
    cin>> ch;
    cout << hash[ch];

}