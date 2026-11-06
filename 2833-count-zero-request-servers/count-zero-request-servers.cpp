class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        auto lambda = [](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        };
        sort(logs.begin(),logs.end(),lambda);
        int q = queries.size();
        vector<int> result(q,0);
        vector<pair<int,int>> timeIndex(q);
        for(int i=0;i<q;i++){
            timeIndex[i] = {queries[i],i};
        }
        sort(begin(timeIndex),end(timeIndex));
        unordered_map<int,int> mp;
        int i = 0;
        int j = 0;
        for(int k = 0;k<q;k++){
            int e = timeIndex[k].first;
            int s = e - x;
            int idx = timeIndex[k].second;
            while(j<logs.size() && logs[j][1] <= e){
                mp[logs[j][0]]++;
                j++;
            }
            while(i<logs.size() && logs[i][1] < s){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]] == 0) mp.erase(logs[i][0]);
                i++;
            }
            result[idx] = n - mp.size(); 
        }
        return result;
    }
};