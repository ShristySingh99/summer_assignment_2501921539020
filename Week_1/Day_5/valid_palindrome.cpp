#include<bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(char ch:s){
            ch= tolower(ch);
            if(isalnum(ch)) temp+=ch;
        }
        int i=0,j=temp.length()-1;
        while(i<=j){
            if(temp[i++]!=temp[j--]) return false;
        }
        return true;
    }
};
