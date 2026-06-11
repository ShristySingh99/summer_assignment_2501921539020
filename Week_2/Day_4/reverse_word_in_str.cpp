#include<bits/stdc++.h>
class Solution {
public:
    string reverseWords(string s) {
        int n= s.length();
        int i=0;
        string res="";
        while(i<n){
            string word="";
            while( i<n && (s[i] != ' ')){
                word+=s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            res+=word+=" ";
            i++;
        }
        if(!res.empty()) res.pop_back();
        return res;
    }
};
