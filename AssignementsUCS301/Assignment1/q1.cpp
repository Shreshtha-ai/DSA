#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[100], n = 0;
    int choice =0;

    while(choice !=6){
        cout<< "1. Create"<<endl;
        cout<< "2. display "<<endl;
        cout<< "3. insert"<<endl;
        cout<< "4. delete"<<endl;
        cout<< "5. linear  search"<<endl;
        cout<< "6. exit"<<endl;
        cout<< "Enter your choice:";
        cin>> choice;

        switch(choice){
            case 1:
            int n;
            cout<< "Enter the number of elements for the array";
            cin>>n;
            cout << "Enter the elements of the array: ";
            for(int i=0; i<n; i++){
                cin >> a[i];
            }
            break;
            case 2:
             if (n == 0)
                {
                    cout << "Array is empty.\n";
                }
                else
                {
                    cout << "Array elements are: ";
                    for (int i = 0; i < n; i++)
                        cout << a[i] << " ";
                    cout << endl;
                }
                break;
            case 3:
                int pos, value;
                cout << "Enter the position to insert (0 to " << n << "): ";
                cin >> pos;

                if(pos < 0 || pos > n){
                    cout << "Invalid position.\n";
                } else {
                    cout << "Enter the value to insert: ";
                    cin >> value;

                    for (int i = n; i > pos; i--){
                        a[i] = a[i - 1];
                    }
                    a[pos] = value;
                    n++;
                }
                case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}


       