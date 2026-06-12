class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.length();
        if(n==0) return "";
        string res="";
        vector<int>range(2);
        for(int i=0;i<n; i++){
            //odd
            int j=i-1, k=i+1;
            while(j>=0 && k<n && s[j]==s[k]){
                if((k-j)> range[1]-range[0]){
                    range[0]=j, range[1]=k;
                }
                j--, k++;
            }
            

            //even
            j=i,k=i+1;
            while(j>=0 && k<n && s[j]==s[k]){
                if((k-j)> range[1]-range[0]){
                    range[0]=j, range[1]=k;
                }                
                j--,k++;
            }
        }
        for(int i=range[0]; i<=range[1] ; i++) res+=s[i];
        return res;
    }
};
