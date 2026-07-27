class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(int& num:nums){
            pq.push(abs(num-1));
        }
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        return a*b;
    }
};