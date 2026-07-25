class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        while (n > 0) {
            int digit = n % 10;
            pq.emplace(digit);
            if (pq.size() > 2)
                pq.pop();
            n /= 10;
        }
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        return a * b;
    }
};