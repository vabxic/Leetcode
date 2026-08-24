// spf
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; ++i) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= mx; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= mx; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
        unordered_set<int> primes;

        for (int x : nums) {
            while (x > 1) {
                primes.insert(spf[x]);
                x /= spf[x];
            }
        }
        return (int)primes.size();
    }
};
/*class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        // Sieve
        vector<bool> isPrime(mx + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= mx; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= mx; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        unordered_set<int> st;


        for (int x : nums) {
            for (int p = 2; p * p <= x; p++) {
                if (isPrime[p] && x % p == 0) {
                    st.insert(p);

                    while (x % p == 0)
                        x /= p;
                }
            }

            // Remaining x is prime
            if (x > 1)
                st.insert(x);
        }

        return st.size();
    }
};
*/