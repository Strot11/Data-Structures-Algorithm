class Solution {
public:
string result = "";
bool solve(int i,vector<int> &alph,string &target,bool &greater,string& ans){
    if(i == target.length()){
        if(greater){
            result = ans;
            return true;
        }
        return false;
    }
    for(char ch='a';ch<='z';ch++){
        if(alph[ch-'a']==0) continue;
        if(!greater && ch < target[i]) continue;
        if(ch > target[i]) greater = true;
        alph[ch-'a']--;
        ans.push_back(ch);
        bool isGreater = (greater || ch>target[i]);
        if(solve(i+1,alph,target,isGreater,ans)) return true;
        ans.pop_back();
        alph[ch-'a']++;
    }
    return false;
}
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> alph(26,0);
        for(int i=0;i<n;i++){
            alph[s[i]-'a']++;
        }
        string ans = "";
        bool greater = false;
        bool can = solve(0,alph,target,greater,ans);
        if(can) return result;
        return "";
    }
};