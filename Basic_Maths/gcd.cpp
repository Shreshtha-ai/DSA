#include<bits/stdc++.h>
using namespace std;

// int main(){
//     int n1, n2;
//     cout << "Enter the values of n1 and n2: ";
//     cin >> n1 >> n2;

//     for(int i = min(n1,n2); i>=1; i--){ // time complexity is O(min(n1,n2))
//         if(n1%i == 0 && n2%i == 0){
//             cout << "GCD of " << n1 << " and " << n2 << " is: " << i << endl;
//             break;
//         }
//     }
// }

//method 2 - using Euclidean algorithm

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    while(a>0 && b>0){
        if(a>b){
            a = a%b;
        }
        else{
            b = b%a;
        }
    }
    if(a==0){
        return b;
    }
    else{
        return a;
    }
}

int main() {
    int n1, n2;
    cout << "Enter the values of n1 and n2: ";
    cin>> n1 >> n2;
    
    int gcd_result = gcd(n1, n2);

    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd_result << endl;

    return 0;
}
    