class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        int n = s.length();
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                if(st.size()>=1) ans = ans + '(';
                st.push(i);
                continue;
            }
            else{
               if(st.size()>1){
                ans = ans + ")";
               }
               st.pop();
            }
        }
        return ans;
    }
};