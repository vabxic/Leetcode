class Solution {
public:
    double triangleArea(vector<int>& a, vector<int>& b, vector<int>& c) {
        return fabs(
            a[0]*(b[1] - c[1]) +
            b[0]*(c[1] - a[1]) +
            c[0]*(a[1] - b[1])
        ) / 2.0;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                for (int k = j+1; k < points.size(); k++) {
                    double area = triangleArea(points[i], points[j], points[k]);
                    if (max_area < area){
                        max_area = area;
                    }
                }
            }
        }
        return max_area;
    }
};