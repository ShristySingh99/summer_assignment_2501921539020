#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        unordered_set<char>st;
        int maxLen=0;
        int j=0,i=0;
        while(j< n){
            while(st.count(s[j])>0){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            maxLen= max(maxLen, j-i+1);
            j++;        
        }
        return maxLen;
    }
};
