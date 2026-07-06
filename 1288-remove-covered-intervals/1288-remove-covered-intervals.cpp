class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) {
                 if (a[0] == b[0]) return a[1] > b[1];
                 return a[0] < b[0];
             });

        int count = 0;
        int maxEnd = 0;
        /* before comp sort
        1....4
           3.....6
         2..........8
         after comp sort
         1....4
            2.........8 <- max end
               3....6

        */
        for (auto& interval : intervals) {
            if (interval[1] > maxEnd) {
                count++;
                maxEnd = interval[1];
            }
        }

        return count;
    }
};