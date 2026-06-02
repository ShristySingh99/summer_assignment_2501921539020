#include<bits/stdc++.h>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=  nums.size();
        map<int, int> mp;

        for(int i : nums){
            mp[i]++;
            if(mp[i]>1) return true;
        }
        return false;
    }
};
