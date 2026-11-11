class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1+cost2 <= costBoth) return 1LL* cost1 * need1 + 1LL*cost2*need2;;
        long long mini = min(need1,need2);
        long long cost = mini*costBoth;
        need1 -= mini;
        need2 -= mini;
        cost += 1LL*need1*min(cost1,costBoth) + 1LL*need2*min(cost2,costBoth);
        return cost; 
    }
};