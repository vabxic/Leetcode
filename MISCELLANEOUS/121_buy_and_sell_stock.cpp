#include <iostream>
#include <vector>
using namespace std;
 int maxprofit(vector <int> prices){
      int n = prices.size();
        int buy = 0, sell = 1 , maxprofit =0 ;
        while (sell < n){
            if (prices[sell]>prices[buy]){
                int profit = prices[sell]-prices[buy];
                if (profit > maxprofit){
                    maxprofit = profit;
                }
            }
            else {
                buy = sell;
            }
            sell++;
        }
        return maxprofit;
 }

int main()
{
    vector<int>vec = {7,1,5,3,6,4};
    cout<<maxprofit(vec);
    return 0;
}
