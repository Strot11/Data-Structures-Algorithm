class Solution {
public:
bool empty(vector<int> &alph){
    for(int i=0;i<26;i++){
        if(alph[i]!=0) return false;
    }
    return true;
}
int findMaxIdx(vector<int> &alph){
    int idx = 0;
    for(int i=0;i<26;i++){
        if(alph[idx] < alph[i]){
            idx = i;
        }
    }
    return idx;
}
    int minimumPushes(string word) {
        vector<int> alph(26,0);
        int pushes = 8;
        int ans = 0;
        for(int i=0;i<word.length();i++){
            alph[word[i]-'a']++;
        }
        while(!empty(alph)){
           int idx = findMaxIdx(alph);
           ans += ( (pushes/8)* alph[idx]);
           pushes++;
           alph[idx] = 0;
        }
        return ans;
    }
};