#include<bits/stdc++.h>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0; i<n; i++){
            //shrink if window exceed
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();

            //check max is at front
            while(!dq.empty() && nums[i]> nums[dq.back()]) dq.pop_back();

            dq.push_back(i);
            
            //ye check krta h ki phle k elements visit hogye h n
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
