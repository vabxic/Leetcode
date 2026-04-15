// Input: n = 8
// Output: 3
// Explanation: 8 -> 4 -> 2 -> 1
#include <bits/stdc++.h>
using namespace std;
int integerReplacement(int n) {
        long long num = n;
        int operation = 0;

        while (num != 1) {
            if (num % 2 == 0) {
                num = num / 2;
            } else {
                long long a = num - 1;
                long long b = num + 1;

                int c1 = 0, c2 = 0;

                long long t1 = a;
                long long t2 = b;

                while (t1 % 2 == 0) {
                    t1 /= 2;
                    c1++;
                }

                while (t2 % 2 == 0) {
                    t2 /= 2;
                    c2++;
                }

                num = (c1 >= c2) ? a : b;
            }
            operation++;
        }

        return operation;
    }
int main()
{
    cout<<integerReplacement(10);
    return 0;
}
