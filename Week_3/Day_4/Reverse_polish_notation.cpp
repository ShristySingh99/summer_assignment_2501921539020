#include<bits/stdc++.h>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n= tokens.size();
        int res=0;
        stack<int>st;
        for(string ch: tokens){
            if(ch=="+"){
                int n1= st.top();
                st.pop();
                int n2= st.top();
                st.pop();
                st.push(n1+n2);
            }
            else if(ch=="-"){
                int n1= st.top();
                st.pop();
                int n2= st.top();
                st.pop();
                st.push(n2-n1);
            }
            else if(ch=="*"){
                int n1= st.top();
                st.pop();
                int n2= st.top();
                st.pop();
                st.push(n1*n2);
            }
            else if(ch=="/"){
                int n1= st.top();
                st.pop();
                int n2= st.top();
                st.pop();
                st.push(n2/n1);
            }    
            else st.push(stoi(ch));                             
        }
        return st.top();
    }
};
