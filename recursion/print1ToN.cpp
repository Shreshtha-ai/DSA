#include<bits/stdc++.h>
using namespace std;

// void printNtimes(int i, int n){
//     if(i>n){
//         return;
//     }
//     cout << i << endl;
//     printNtimes(i+1, n);
// }

// int main(){
//     int n;
//     cout << "Enter the value of n: ";
//     cin >> n;
//     printNtimes(1, n);
//     return 0;
// }             

// method 2 by backtracking

void printNtimesBacktrack(int i, int n){
    if(i<1){
        return;
    }     
    printNtimesBacktrack(i-1, n);

    cout << i<< endl; 

}
int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    printNtimesBacktrack(n, n);
    return 0;
}