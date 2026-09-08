class Solution {
public:
    int countRotations(string str, int k) {
        int n = str.length();
        int ans = 0;
        for(int i = 0;i<n;i++){
            string s = str;
            reverse(s.begin()+i,s.end());
            reverse(s.begin(),s.begin()+i);
            reverse(s.begin(),s.end());
            int score = 0;
            for(int j=1;j<n;j++){
                if(s[j]==s[j-1]) score++;
            }
            if(score == k) ans++;
        }
        return ans;
    }
};