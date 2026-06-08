#include<bits/stdc++.h>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length()) return false;
        vector<int>count(26,0);
        for(char ch: s){
            count[ch-'a']+=1;
        }
        for(char ch:t){
            if(count[ch-'a']==0) return false;
            count[ch-'a']-=1;

        }
        return true;
        
    }
};
