#include<bits/stdc++.h>
class Solution {
public:
    string decodeString(string s) {
        int n= s.length();
        stack<string> strStack;
        stack<int> numStack;
        int currNum=0;
        string  currStr="";
        for(char ch:s){
            if(isdigit(ch)) currNum = currNum*10 +(ch-'0');
            else if(ch=='['){
                numStack.push(currNum);
                strStack.push(currStr);
                currNum=0;
                currStr="";
            }
            else if(ch==']'){
                int repeat= numStack.top();
                numStack.pop();
                string decodedStr= "";
                for(int i=0;i<repeat; i++){
                    decodedStr+= currStr;
                }
                currStr = strStack.top()+ decodedStr;
                strStack.pop();
            }
            else currStr += ch;
        }

        return currStr;
    }
};
