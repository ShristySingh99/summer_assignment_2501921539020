class Solution {
public:
    int compress(vector<char>& chars) {
        int n= chars.size();
        int idx=0,i=0;
        while(i<n){
            char ch= chars[i];
            int count=0;
            while(i<n && chars[i]== ch){
                count++;
                i++;
            }
            chars[idx++]=ch;
            if(count>1){
                string cnt_str= to_string(count);
                for(char digit: cnt_str){
                    chars[idx++] = digit;
                }
            }
        }
        return idx;
    }
};
