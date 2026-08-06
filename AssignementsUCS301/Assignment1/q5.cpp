#include<bits/stdc++.h>
using namespace std;

int main(){
    int r, c;
    int a[10][10];

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }

    cout<< "Sum of each row:"<<endl;
    for(int i =0;i<r;i++){
        int sum =0;
        for(int j =0;j<c;j++){
            sum+=a[i][j];
        }
        cout<< "Sum of row " << i << ": " << sum << endl;
    }

    cout<< "Sum of each column:"<<endl;
    for(int j=0;j<c;j++){
        int sum =0;
        for(int i =0;i<r;i++){
            sum+=a[i][j];
        }
        cout<< "Sum of column " << j << ": " << sum << endl;
    }


    
}