class Solution {
public:
bool solve(int n,int t){
      int mul = 1;
    while(n>0){
      mul*= (n%10);
      n/=10;
    }
    return (mul%t==0);
}
    int smallestNumber(int n, int t) {
        int num = n;
       for(int i=0;i<=100;i++){
        if(solve(num+i,t)) return num+i;
       }
       return -1;
    }
};