class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        int nearX = max(x1, min(x2, xCenter));
        int nearY = max(y1, min(y2, yCenter));

        int dist = (nearX - xCenter) * (nearX - xCenter) +
                   (nearY - yCenter) * (nearY - yCenter);
        return dist <= radius * radius;
    }
};