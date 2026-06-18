class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        vector<int>ans(n, INT_MAX);     
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }

        for(int i=0; i<nums1.size(); i++){
            int idx= mp[nums1[i]];
            for(int j= idx+1;j<nums2.size(); j++){
                if(nums2[j]>nums1[i]){
                    ans[i]= nums2[j];
                    break;
                } 
            }
            if(ans[i]==INT_MAX) ans[i]=-1;
        }

        return ans;
    }
};
