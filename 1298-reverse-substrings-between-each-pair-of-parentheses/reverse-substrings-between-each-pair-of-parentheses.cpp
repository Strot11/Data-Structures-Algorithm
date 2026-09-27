class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(i);
                continue;
            }
            else if(s[i] == ')'){
                int last = st.top();
                st.pop();
                reverse(s.begin()+last,s.begin()+i);
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == ')'){
                s.erase(i,1);
                i--;
            }
        }
        return s;
    }
};