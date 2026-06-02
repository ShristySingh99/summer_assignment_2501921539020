#include<bits/stdc++.h>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n= nums.size();
        double CurrSum=0;
        for(int i=0; i<k;i++){
            CurrSum+= nums[i];
        }

        double maxSum= CurrSum;
        for(int i=k; i<n;i++){
            CurrSum += nums[i]- nums[i-k];
            maxSum= max(maxSum, CurrSum);
        }
        return maxSum/k;
    }
};

