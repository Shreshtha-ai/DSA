 //Method1

// #include<iostream>
// using namespace std;

// int count(int n){
//     int cnt = 0;

//     while(n>0){
//         n = n/10;
//         cnt++;
//     }
//     return cnt;
// }

// int main(){
//     int n;
//     cout << "Enter the value of n: ";
//     cin >> n;
//     cout << "Number of digits in " << n << " is: " << count(n) << endl;
//     return 0;
// }
//time complexity: O(log10(n))


//Method2

#include<iostream>
#include<cmath>
using namespace std;

int count(int n){
    int cnt = (int)(log10(n) + 1);

    return cnt;
}

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Number of digits in " << n << " is: " << count(n) << endl;
    return 0;
}
//time complexity: O(1)