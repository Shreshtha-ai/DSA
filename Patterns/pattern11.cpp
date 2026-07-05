#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=1; i<=n; i++){
        for(char ch= 'F'-i ; ch<='E'; ch++){
            cout<<ch<<" "; 
        }
     
        cout<<endl;
    }
}
