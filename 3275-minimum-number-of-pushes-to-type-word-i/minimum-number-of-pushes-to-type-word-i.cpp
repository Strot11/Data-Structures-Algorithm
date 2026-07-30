class Solution {
public:
    int minimumPushes(string word) {
        int minPushes = 0;
        for(int i=0;i<word.length();i++){
           minPushes += ((i/8) + 1);
        }
        return minPushes;
    }
};