class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());

        vector<int>arr;
        while (n > 0){
            int prev = pq.top();    //2
            pq.pop();
            int curr = pq.top();   //3
            arr.emplace_back(curr);
            pq.pop();
            arr.emplace_back(prev);
            n-=2;
        }return arr;
    }
};