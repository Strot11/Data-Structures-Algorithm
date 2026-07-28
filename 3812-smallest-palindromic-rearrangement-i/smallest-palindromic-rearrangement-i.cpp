class Solution {
public:
string reverse(string s){
    int n = s.length()-1;
    int m = 0;
    while(m<n){
        swap(s[m],s[n]);
        m++;
        n--;
    }
    return s;
}
    string smallestPalindrome(string s) {
        vector<int> alph(26,0);
        int n = s.length();
        for(int i=0;i<n;i++){
            alph[s[i]-'a']++;
        }
        int smallest = INT_MAX;
        s = "";
        for(int i=0;i<26;i++){
              while(alph[i] > 1){
                char ch = 'a' + i;
                s += ch;
                alph[i] -= 2;
              }
              if(alph[i] == 1){
                smallest = min(smallest,i);
              }
        }
        string ans = "";
       if(smallest !=INT_MAX){
        char ch = 'a' + smallest;
        ans = (s + ch + reverse(s));
       }
       else ans = s + reverse(s);
        return ans;
    }
};