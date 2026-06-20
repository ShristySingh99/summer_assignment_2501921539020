#include<bits/stdc++.h>
class Solution {
public:
    vector<int> right_great_ele(vector<int>&arr, int n){
        vector<int>right(n);
        stack<int>st;
        for(int i=n-1; i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) right[i]= n;
            else right[i]= st.top();
            st.push(i);
        }
        return right;
    }
    vector<int> left_small_ele(vector<int>&arr, int n){
        vector<int>left(n);
        stack<int>st;
        for(int i=0; i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) left[i]= -1;
            else left[i]= st.top();
            st.push(i);
        }
        return left;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        int ans=0;
        int maxArea= 0;
        vector<int>right= right_great_ele(heights,n);
        vector<int>left= left_small_ele(heights,n);
        for(int i=0;i<n;i++){
            int width= right[i]-left[i]-1;
            int area= heights[i]*width;
            maxArea= max(maxArea, area);
        }
        return maxArea;
    }
};

















//tle
        // int n= heights.size();
        // int maxArea=0;
        // for(int i=0; i<n; i++){
        //     int area=0;
        //     int minLen=heights[i];
        //     for(int j=i; j<n; j++){
        //         minLen= min(minLen, heights[j]);
        //         area= minLen* (j-i+1);
        //         maxArea= max(maxArea, area);
                
        //     }
        // }
        // return maxArea;
