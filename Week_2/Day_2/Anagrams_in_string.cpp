#include<bits/stdc++.h>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1= s.length();
        int n2= p.length();
        if(n1< n2) return {};
        vector<int>ans;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(char ch: p){
            freq1[ch-'a']++;
        }
        int i=0,j=0;
        while(j<n1){
            freq2[s[j]-'a']++;
            if((j-i+1)>n2){
                freq2[s[i]- 'a']--;
                i++;
            }
            if((j-i+1)== n2 && freq1==freq2){
                ans.push_back(i);
                freq2[s[i]- 'a']--;
                i++;
            }
            j++;
        }
        return ans;    
    }
};
