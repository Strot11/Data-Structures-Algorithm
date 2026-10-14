class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        for(int i=0;i<num;i++){
            bool taken = false; 
            for(int d=9;d>=0;d--){
              if(sum-d>=0){
                  taken = true;
                  sum -= d;
                  ans.push_back(d + '0');
                  break;
              }
            }
            if(!taken) return "";
        }
        if(sum != 0) return "";
        return ans;
    }
};