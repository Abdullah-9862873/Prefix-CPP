#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool isValid(string s){
    int len = s.length();
    stack<char> st;

    bool ans = true;

    for(int i=0; i<len; i++){
        if(s[i] == '(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!st.empty() && st.top()=='('){
                st.pop();
            }
        }
        else if(s[i] == '}'){
            if(!st.empty() && st.top()=='{'){
                st.pop();
            }
        }
        else if(s[i] == ']'){
            if(!st.empty() && st.top()=='['){
                st.pop();
            }
        }
        else{
            ans = false;
            break;
        }
    }

    if(!st.empty()){
        return false;
    }
    else{
        return ans;
    }
}

int main(){
    string s = "{([])}";
    if(isValid(s)){
        cout<<"Balanced parenthesis"<<endl;
    }
    else{
        cout<<"UnBalanced parenthesis";
    }

    return 0;
}