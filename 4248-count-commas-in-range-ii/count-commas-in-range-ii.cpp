class Solution {
public:
    long long countCommas(long long n) {
        if(n-999 <=0) return 0;
        long long count = 0;
        if(n>999999999999999LL){
            count+=(n-999999999999999LL)*5;
        }
        if(n>999999999999LL){
            count += (min(n,999999999999999LL)-999999999999LL)*4;
        };
        if(n-999999999LL > 0){
            count += (min(999999999999LL,n)-999999999LL)*3;
            
        };
        if(n-999999 > 0){
            count += (min(999999999LL,n)-999999)*2;
        };
        if(n-999 > 0){
            count += (min(999999LL,n)-999);
        };
        
       return count;
    }
};