#include<bits/stdc++.h>
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n= s.length();
        int m= t.length();
        int idx=0;
        for(int i=0;i<m; i++){
            if(t[i]== s[idx]) idx++;//count number of character matched in s
        }
        return idx==n;
    }
};
