#include<bits/stdc++.h>
using namespace std;

//method1 - by parameter
// int sum(int n, int s){
//     if (n<1) return s;
//     return sum(n-1, s+n);
// }

// int main(){
//     int n;
//     cout << "Enter the value of n: ";
//     cin >> n;
//     cout << "Sum of first " << n << " natural numbers is: " << sum(n, 0) << endl;
//     return 0;
// }
//method2- by functional return type

int sum2(int n){
    if(n==0) return 0;
    return n + sum2(n-1);
}
int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Sum of first " << n << " natural numbers is: " << sum2(n) << endl;
    return 0;
}