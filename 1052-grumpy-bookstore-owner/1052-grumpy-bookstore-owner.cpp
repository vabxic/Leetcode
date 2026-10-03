class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        size_t numCustomers = customers.size();
        int totalSatisfiedCustomers = 0, windowSum = 0, maxWindowSum = 0;

        for (int i = 0; i < numCustomers; i++) {

            if (i - minutes >= 0 && grumpy[i - minutes] == 1)
                windowSum -= customers[i - minutes];

            if (grumpy[i] == 1)
                windowSum += customers[i];
            else
                totalSatisfiedCustomers += customers[i];
        

                maxWindowSum = max(maxWindowSum, windowSum);
        }

        return totalSatisfiedCustomers + maxWindowSum;
    }
};