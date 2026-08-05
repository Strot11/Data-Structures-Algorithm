class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        int m = invocations.size();
        for(int i=0;i<m;i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<bool> infected(n,false);
        queue<int> pq;
        pq.push(k);
        infected[k]=true;
        while(!pq.empty()){
            int top = pq.front();
            pq.pop();
            for(int& neigh:adj[top]){
                 indegree[neigh]--;
                if(!infected[neigh]){
                    pq.push(neigh);
                    infected[neigh]=true;
                }
            }
        }
       bool flag = false;
       for(int i=0;i<n;i++){
        if(infected[i] && indegree[i]!=0) {
            flag = true;
            break;
        }
       }
       vector<int> ans;
        if(!flag){
       for(int i=0;i<n;i++){
        if(!infected[i]) ans.push_back(i);
       }
        }
        else{
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }
       return ans;
    }
};