class Solution {
public:

    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> st;
        st.push(0);
        for(int i=0;i<s.length();i++){
           if(s[i] == '(') st.push(0);
           else{
            int inside = st.top();
            st.pop();
            int value = (inside==0) ? 1 : 2*inside;
            st.top() += value; 
           }
        }
        return st.top();
    }
};