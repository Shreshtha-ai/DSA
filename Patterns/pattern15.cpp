#include<iostream>

using namespace std;

// int main(){
//     int n;
//     cout<< "Enter the value of n: ";
//     cin>> n;
//     for(int i=0; i<2*n-1;i++){
//         for(int j =0; j<2*n-1;j++){
//             if(i==0 || i==2*n-2 || j==0 || j==2*n-2){
//                 cout<< "0";
//             }
//             else if (i==1 || j==1 || i == 2*n-3 || j ==2*n-3)
//             {
//                 cout<< "1";
//             }
//              else if (i==2 || j==2 || i == 2*n-4 || j ==2*n-4)
//             {
//                 cout<< "2";
//             }
//             else if (i==3 || j==3 || i == 2*n-5 || j ==2*n-5)
//             {
//                 cout<< "3";
//             }
//             else if (i==4 || j==4 || i == 2*n-6 || j ==2*n-6)
//             {
//                 cout<< "4";
//             }
//             else if (i==5 || j==5 || i == 2*n-7 || j ==2*n-7)
//             {
//                 cout<< "5";
//             }
//             else if (i==6 || j==6 || i == 2*n-8 || j ==2*n-8)
//             {
//                 cout<< "6";
//             }
//              else if (i==7 || j==7 || i == 2*n-9 || j ==2*n-9)
//             {
//                 cout<< "7";
//             }
//              else if (i==8 || j==8 || i == 2*n-10 || j ==2*n-10)
//             {
//                 cout<< "8";
//             }
//              else if (i==9 || j==9 || i == 2*n-11 || j ==2*n-11)
//             {
//                 cout<< "9";
//             }
            
//             else{
//                 cout<< " ";
//             }
//         }
//         cout<< endl;
//     }

// }
int main(){
    int n;
    cout<< "Enter the value of n: ";
    cin>> n;
for(int i =0; i<2*n-1; i++){
    for( int j = 0; j<2*n-1; j++){
        int top = i;
        int left = j;
        int right = (2*n-2)-j;
        int bottom = (2*n-2)-i;
        cout<< (n-min(min(top,left),min(right,bottom)));
    }
    cout<< endl;
}
}