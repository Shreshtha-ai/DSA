#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=1; i<=n; i++){
        char ch = 'A'+i-1;
        for(char j='A'; j<=ch;j++){
            cout<<j<<" "; 
        }
        cout<<endl;
    }
}
