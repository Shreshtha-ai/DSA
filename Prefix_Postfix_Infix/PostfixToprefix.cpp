#include<bits/stdc++.h>
using namespace std;

string postfixtoprefix(string s){
    int i =0;
    stack<string> st;

    while(i<s.size()){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string t3 = s[i] + t2 + t1;
            st.push(t3);
        }
        i++;
    }
    return st.top();
}

int main(){
    string s;
    cin>>s;
    cout<<postfixtoprefix(s)<<endl;
    return 0;
}



