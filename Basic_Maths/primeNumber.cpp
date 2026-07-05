#include<bits/stdc++.h>
using namespace std;

int  isPrime(int n){
    if(n<=1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    for(int i =2; i<=sqrt(n); i++){ // brute force approach - taking n 
        if(n%i ==0){
            return 0;
        }
    }
    return 1;
}
// time complexity is O(sqrt(n))
int main(){
    int n;
    cout <<"Enter a number n:";
    cin>> n;
    if(isPrime(n)){
        cout<< n << " is a prime number";
    }
    else{
        cout<< n << " is not a prime number";
    }
}