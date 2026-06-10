#include<bits/stdc++.h>
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled= s+s;
        string total= doubled.substr(1, doubled.length()-2);
        return total.find(s)!= string::npos;
    }
};
