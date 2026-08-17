class Solution {
public:
int dp[501][501];
int solve(int l,int r,vector<int>& cumSum){
    if(l >= r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int sum = 0;
    for(int mid = l;mid<=r-1;mid++){
        int leftSum = cumSum[mid] - ((l-1<0) ? 0 : cumSum[l-1]);
        int rightSum = cumSum[r] - cumSum[mid];
        if(leftSum < rightSum){
            sum = max(sum,leftSum + solve(l,mid,cumSum));
        }
        else if(leftSum>rightSum){
            sum = max(sum,rightSum + solve(mid+1,r,cumSum));
        }
        else{
            sum = max({sum,leftSum + solve(l,mid,cumSum),rightSum + solve(mid+1,r,cumSum)});
        }
    }
        return dp[l][r] = sum;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> cumSum(n,0);
        memset(dp,-1,sizeof(dp));
        cumSum[0] = stoneValue[0];
        for(int i=1;i<n;i++){
          cumSum[i] = cumSum[i-1] + stoneValue[i];
        }
        return solve(0,n-1,cumSum);
    }
};