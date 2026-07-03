class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {

        set<pair<int, int>> pointSet;
        for (auto& point : points) {
            pointSet.insert({point[0], point[1]});
        }

        int maxArea = -1; 

        for (auto& p1 : pointSet) {
            for (auto& p2 : pointSet) {

                if (p1 == p2 || p1.first >= p2.first || p1.second >= p2.second) {
                    continue;
                }

                pair<int, int> p3 = {p1.first, p2.second};
                pair<int, int> p4 = {p2.first, p1.second};

                if (pointSet.find(p3) == pointSet.end() || pointSet.find(p4) == pointSet.end()) {
                    continue;
                }
                bool hasInternalPoint = false;
                for (auto& other : pointSet) {
                    if (other == p1 || other == p2 || other == p3 || other == p4) {
                        continue;
                    }

                    if (other.first >= p1.first && other.first <= p2.first &&
                        other.second >= p1.second && other.second <= p2.second) {
                        hasInternalPoint = true;
                        break; 
                    }
                }
                if (!hasInternalPoint) {
                    int area = (p2.first - p1.first) * (p2.second - p1.second);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea == 0 ? -1 : maxArea;
    }
};