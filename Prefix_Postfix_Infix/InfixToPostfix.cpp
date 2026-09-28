#include<bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c=='+' || c=='-'){
        return 1;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='^'){
        return 3;
    }
    return 0;
}

string infixToPostfix(string s){

    int i=0;
    stack<char> st;
    string ans;
    while(i<s.size()){
        if((s[i]>='A'&&s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0'&& s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(st.empty()){
                return "Invalid Expression";
            }
            st.pop();
        }
        else{
            while(!st.empty()&& priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
            
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<infixToPostfix(s)<<endl;
    return 0;
}