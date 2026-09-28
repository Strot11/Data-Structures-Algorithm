class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for(int i = 0; i < knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans = "";

        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])){
                ans.push_back(s[i]);
            }
            else{
                i++;
                int start = i;

                while(s[i] != ')'){
                    i++;
                }

                string key = s.substr(start, i - start);

                auto it = mp.find(key);

                if(it != mp.end())
                    ans += it->second;
                else
                    ans += '?';
            }
        }

        return ans;
    }
};