// void fxn doesnt return any value. It is used when we want to perform some task but not return any value.
#include <iostream>
using namespace std;

void printName(string name) {
    cout << "Hello, " << name << "!" << endl;
}
int main(){
    printName("Shreshtha");
    return 0;
}