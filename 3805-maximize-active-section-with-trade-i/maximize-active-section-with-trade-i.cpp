class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int maxSections = 0;
        int countZero = 0;
        vector<int> store;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){ 
                maxSections++;
               if(countZero > 0) store.push_back(countZero);
                countZero = 0;
            }
            else countZero++;
        }
        if(countZero>0) store.push_back(countZero);
      if(store.size()<=1) return maxSections;
      int maxOperate = 0;
      for(int i=1;i<store.size();i++){
          maxOperate = max(maxOperate,store[i]+store[i-1]);
      }
      return maxSections + maxOperate;
    }
};