class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int cnt = 0;
        int n = s.length();
        for(int i=0;i<s.length();i++){
           if(s[i] == ')'){
            if(open == 0){
                cnt++;
                continue;
            }
            open--;
           }
           else open++;
        }
        while(open > 0){
            cnt++;
            open--;
        }
        return cnt;
    }
};