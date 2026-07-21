class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int maxSections = 0;
       int curr = 0;
       int prev = 0;
       int maxOperate = 0;
       int zeroBlock = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '1'){ 
                maxSections++;
              if(curr>0){
                zeroBlock++;
                maxOperate = max(maxOperate,curr+prev);
                   prev = curr;
              }
              curr = 0;
            }
            else curr++;
        }
        if(curr>0){
            zeroBlock++;
             maxOperate = max(maxOperate,curr+prev);
        }
        if(zeroBlock <= 1) return maxSections;
      return maxSections + maxOperate;
    }
};