class Solution {
public:
bool canCover(int r,vector<int>& houses, vector<int>& heaters){
    int n = houses.size();
    int m = heaters.size();
    vector<bool> covered(n,false);
    int i = 0;
    int j = 0;
    while(i<n){
        if(( houses[i] <= (heaters[j] + r)) && ( houses[i] >= (heaters[j] - r))){
            covered[i] = true;
            i++;
        }
        else{
            if(j+1<m) j++;
            else break;
        }
    }
    for(int i=0;i<n;i++){
        if(!covered[i]) return false;
    }
    return true;
    
}
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int m = heaters.size();
        int n = houses.size();
        int radius = max(houses[n-1],heaters[m-1]);
        int l = 0;
        int r = max(houses[n-1],heaters[m-1]);
        while(l<=r){
            int mid = l + (r-l)/2;
            if(canCover(mid,houses,heaters)){
                radius = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return radius;
     }
};