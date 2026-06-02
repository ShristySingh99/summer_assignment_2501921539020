//answer to problem
class Solution {
public:
#include <vector>
#include <unordered_map>
    vector<int> twoSum(vector<int> &nums, int target) {
        int n= nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n; i++){
            int sec = target-nums[i];
            if(mp.find(sec)!= mp.end()){
                int j= mp[sec];
                return {i,j};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
