class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        for(int i=0;i<num;i++){
            int needed = min(sum,9);
            sum -= needed;
            ans.push_back('0'+needed);
        }
        if(sum!=0) return "";
        return ans;
    }
};