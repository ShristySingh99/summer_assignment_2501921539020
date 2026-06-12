#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n= strs.size();
        map<vector<int>, vector<string>>anagram;
        for(const string& s: strs){
            vector<int>count(26,0);
            for(char ch :s){
                count[ch-'a']++;
            }
            anagram[count].push_back(s);
        }
        vector<vector<string>>res;
        for(auto it: anagram){
            res.push_back(it.second);
        }
        return res;     
    }
};
