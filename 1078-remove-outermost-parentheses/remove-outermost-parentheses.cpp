class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        int n = s.length();
        string ans = "";
       for(int i=0;i<n;i++){
        if(s[i] == '('){
            if(open) ans += "(";
            open++;
        }
        else{
            open--;
            if(open) ans +=  ")";
        }
       }
        return ans;
    }
};