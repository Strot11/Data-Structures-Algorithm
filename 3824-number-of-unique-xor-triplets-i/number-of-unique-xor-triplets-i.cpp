class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n==2) return n;
        for(int i=2;i<=32;i++){
            if((1<<i) > n) return (1<<i);
        }
        return -1;
    }
};