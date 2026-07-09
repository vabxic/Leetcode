class Solution {
public:
    const int MOD=1e9+7;
    int countPrimes(int n){
        vector<bool>isPrime(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;

        for(int i=2;i*i<=n;i++){
            if(isPrime[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        return count(isPrime.begin(),isPrime.end(),true);
    }
    long long factorial(int a){
        long long ans=1;
        for(int i=2;i<=a;i++){
            ans=(ans*i)%MOD;
        }
        return ans;
    }
    int numPrimeArrangements(int n) {
        int primeCount=countPrimes(n);
        long long ans=(factorial(primeCount)*factorial(n-primeCount))%MOD;
        return ans;
    }
};