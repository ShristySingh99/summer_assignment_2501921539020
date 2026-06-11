class Solution {
public:
    void solve(int idx, vector<string>&ans, string str, int n){
        if(idx== 2*n){
            ans.push_back(str);
            return;
        }

        solve(idx+1, ans, str+ '(', n);

        solve(idx+1, ans,str+')',n);

    }
    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
        string str="";
        vector<string> res;
        solve(0, ans, str,n);
        for(int i=0;i< ans.size(); i++){
            string s = ans[i];
            stack<char>st;
            bool isvalid= true;
            for(char ch: s){
                if(ch=='(') st.push(ch);
                else{
                    if(st.empty()){
                        isvalid= false;
                        break;
                    } 
                    st.pop();
                }
            }
            if(isvalid && st.empty()) {
                res.push_back(s);
            }
        }
        return res;
    }
};
