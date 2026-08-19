class Solution {
public:
bool isAvailable(int a,int b,int c,int d,vector<int> &num){
    for(auto n:num){
        if(n == a||n==b||n==c||n==d) return false;
    }
    return true;
}
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        unordered_map<long long,vector<int>> gp;
        long long count = 0;
        for(int i=0;i<m;i++){
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];
           gp[row].push_back(seat);
        }
       for(auto [key,val]: gp){
        bool g1 = isAvailable(2,3,4,5,val);
        bool g2 = isAvailable(4,5,6,7,val);
        bool g3 = isAvailable(6,7,8,9,val);
        if(g1 && g3) count+=2;
        else if(g1 || g2 || g3) count++;
       }
        return (n-gp.size())*2 + count; 
    }
};