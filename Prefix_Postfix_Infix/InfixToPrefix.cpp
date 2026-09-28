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

string infixToPrefix(string s){

    reverse(s.begin(),s.end());

    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
    }
    stack<char> st;
    string ans;
    int i=0;

    while(i<s.size()){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                ans+=st.top();
                st.pop();
            }              
            st.pop();
        }
        else{
            if(s[i]=='^'){
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            } // this while loop 
            else{
                while(!st.empty()&& priority(s[i])<priority(st.top())){
                ans+=st.top();
                st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<infixToPrefix(s)<<endl;
    return 0;
}
