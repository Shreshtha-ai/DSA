#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<< "Enter a number:";
    cin>> n;
    int orig = n;
    int sum = 0;
    

    while(n>0){
        int lastdigit = n%10;
        n = n/10;
        sum = sum+ pow(lastdigit,3);
    }

    if(sum == orig){
        cout<< "Armstrong number";
    }
    else{
        cout<< "Not an Armstrong number";
    }
    return 0;
}