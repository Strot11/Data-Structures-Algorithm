class Solution {
public:
string s;
int n;
int idx;
set<string> getUnit(){
     set<string> result;
    if(s[idx] == '{'){
        idx++;
       result = performUnion();
    }
    else result.insert(string(1,s[idx]));
idx++;
    return result;
}

set<string> performConcat(){
    set<string> result = {""};
    while(idx<n && (isalpha(s[idx]) || s[idx] == '{') ){
      set<string> temp = getUnit();
      set<string> concatResult;
      for(const string& left :result){
        for(const string& right :temp){
            concatResult.insert(left+right);
        }
      }
      result = concatResult; 
    }
    return result;
}

set<string> performUnion(){
    set<string> result;
    while(true){
        set<string> temp = performConcat();
        result.insert(begin(temp),end(temp));
        if(idx<n && s[idx]==',') idx++;
        else break;
    }
    return result;
}
    vector<string> braceExpansionII(string expression) {
        n = expression.length();
        idx = 0;
        s = expression;
        set<string> st = performUnion();
        vector<string> ans(st.begin(),st.end());
        return ans;
    }
};