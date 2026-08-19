class Solution {
public:
bool isAvailable(int a,int &num){
    return ((a&num) == 0);
}
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        unordered_map<long long,int> gp;
        long long count = 0;
        for(int i=0;i<m;i++){
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];
            int bit = (1<<seat);
           gp[row] |= bit;
        }
        int mask3= 0b1111000000;
        int mask2 = 0b0011110000;
        int mask1 = 0b0000111100;
       for(auto [key,val]: gp){
        bool g1 = isAvailable(val,mask1);
        bool g2 = isAvailable(val,mask2);
        bool g3 = isAvailable(val,mask3);
        if(g1 && g3) count+=2;
        else if(g1 || g2 || g3) count++;
       }
        return (n-gp.size())*2 + count; 
    }
};