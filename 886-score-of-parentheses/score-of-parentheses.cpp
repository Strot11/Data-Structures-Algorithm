class Solution {
public:
    int dfs(string &s, int &i) {
        int score = 0;

        while (i < s.size() && s[i] == '(') {
            i++;  // skip '('

            if (s[i] == ')') {
                // ()
                score += 1;
                i++;  // skip ')'
            }
            else {
                // (A)
                int inside = dfs(s, i);
                score += 2 * inside;
                i++;  // skip ')'
            }
        }

        return score;
    }

    int scoreOfParentheses(string s) {
        int i = 0;
        return dfs(s, i);
    }
};