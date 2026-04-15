// Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
// Output: 45
#include <bits/stdc++.h>
using namespace std;
 int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = 0 , area2 = 0 , intersection = 0;

        int length1 = abs(ax1)+abs(ax2);
        int breath1 = abs(ay1)+abs(ay2);
        area1 = length1*breath1;
        int length2 = abs(bx1)+abs(bx2);
        int breath2 = abs(by1)+abs(by2);
        area2 = length2*breath2;

        int area = area1+area2;
        return area;
    }
int main()
{
    cout<<computeArea(-3,0,3,4,0,-1,9,2);
    return 0;
}
