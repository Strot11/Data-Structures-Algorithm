class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i = 0;
        int j = 0;
        int n = arr.size();
        int sum = 0;
        vector<int> minLen(n,INT_MAX);
        int ans = INT_MAX;
        int bestMin= INT_MAX;
        while(j<n){
            sum+=arr[j];
            while(sum > target){
                sum-=arr[i];
                i++;
            }
            if(sum == target){
                int len = j-i+1;
                if(i > 0 && minLen[i-1] != INT_MAX){
                  ans = min(ans,minLen[i-1]+len);
                }
                bestMin = min(bestMin,len);
            }
             minLen[j] = bestMin;
             j++;
        }
        return ans ==INT_MAX ? -1:ans;
    }
};