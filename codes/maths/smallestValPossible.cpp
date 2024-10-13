// @leet start
//2507. Smallest Value After Replacing With Sum of Prime Factors
class Solution {
public:
    int getPFactorsSum(int num){
        int sum = 0;
        for(int i = 2; i*i <= num ; i++){
            while(num%i == 0){
                sum +=i;
                num /= i;
            }
        }
        if(num > 1) sum += num;
        return sum;
    }
    bool checkPrime(int num){
        for(int i = 2; i< num;i++){
            if(num%i == 0) return false;
        }
        return true;
    }
    int smallestValue(int n) {
        while(true){
            int prev = n;
            n = getPFactorsSum(n);
            if(n == prev){
                break;
            }
        }
        return n;
    }
};
// @leet end
