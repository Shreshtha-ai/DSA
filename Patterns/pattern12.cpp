#include<iostream>
using namespace std;

int main(){
    int n;
    int iniS = 0;
    cout<<"Enter the number of rows:";
    cin>>n;
    for(int i = n; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        for(int j = 0; j<iniS; j++){
            cout<<" ";
        }
        iniS += 2;
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    int newis = iniS-2;
    for(int i = 1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        for(int j = 0; j<newis; j++){
            cout<<" ";
        }
        newis -= 2;
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}