#include <iostream>
using namespace std;

int main() {
    int n=6;
    int factorial = 1;
    while (n >0) {
        factorial *= n;
        n--;

       
    }
    cout << "Factorial of 6 is : " << factorial << endl;
    return 0;
}