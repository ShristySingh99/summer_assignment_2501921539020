#include<bits/stdc++.h>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2= s2.length();
        if(n1 > n2) return false;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(char ch: s1){
            freq1[ch-'a']++;
        }
        int i=0, j=0;
        while(j<n2){
            freq2[s2[j]- 'a']++;
            if((j-i+1) > n1){//shrink if len of window will be > than n1
                freq2[s2[i]- 'a']--;
                i++;
            }
            if(freq1== freq2) return true;
            j++;
        }  
        return false;     
    }
};
