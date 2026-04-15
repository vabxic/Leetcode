/*The method used here is Sieve of Eratosthenes in which we consider a array size till the
number+1 as all primes (true) then iteratively we check cancel out the multiple of that number(fasle)
at laast we'll left with only prime numbers.  */
#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n) {
        vector<bool>isPrime(n+1,true); // initialized all with 1
        int count = 0;
        for (int i = 2 ; i<n ; i++){
            if (isPrime[i]){
                count++;
                
                for (int j = i*2; j<n ; j = j+i){
                isPrime[j] = false;
            }
            
            }
        }
        return count;
    }
int main()
{
    int n = 10;
    cout<<countPrimes(n);
    return 0;
}
