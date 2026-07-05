#include<bits/stdc++.h>
using namespace std;

int reverse(int n){
    

    int rev =0;
    if(n>0){
        while (n>0){
            int lastdigit = n%10;
            rev = rev*10 + lastdigit;
            n = n/10;
        }
    }
    else{
        n = -n;
        while (n>0){
            int lastdigit = n%10;
            rev = rev*10 + lastdigit;
            n = n/10;
        }
        rev = -rev;
    }
    return rev;
}

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Reverse of " << n << " is: " << reverse(n) << endl;
    return 0;
}