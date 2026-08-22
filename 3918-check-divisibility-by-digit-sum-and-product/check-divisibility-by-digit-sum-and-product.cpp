class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0;
        int product = 1;
        while(num>0){
            sum += num%10;
            product *= num%10;
            num /=10; 
        }
        return (n%(sum+product)==0);
    }
};