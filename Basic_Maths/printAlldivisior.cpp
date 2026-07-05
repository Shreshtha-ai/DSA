#include<bits/stdc++.h>
using namespace std;

void printAllDivisors(int n){
    vector<int> divisors;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            divisors.push_back(i);
            if(i != n/i){
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(), divisors.end()); // it sorts the list of divisors in ascending order
    for(int divisor : divisors){ // it iterates through the sorted list of divisors
        cout<< divisor<< " ";
    }
}

int main(){
    int n;
    cout<< "Enter a number n:";
    cin>> n;
    cout<< "All divisors of " << n << " are: ";
    printAllDivisors(n);
    return 0;
}

