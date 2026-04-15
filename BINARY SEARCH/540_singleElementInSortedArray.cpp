#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;

        if (n == 1) return nums[0];                  // single-element array
        if (nums[0] != nums[1]) return nums[0];      // first element is single
        if (nums[n-1] != nums[n-2]) return nums[n-1]; // last element is single

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // check if mid is the single element
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }

            if (mid % 2 == 0) {  // even index
                if (nums[mid] == nums[mid+1]) {
                    st = mid + 2;   // single element is after this pair
                } else {
                    end = mid - 1;  // single element is before
                }
            } else {  // odd index
                if (nums[mid] == nums[mid-1]) {
                    st = mid + 1;   // single element is after
                } else {
                    end = mid - 1;  // single element is before
                }
            }
        }

        return -1;  // should never reach here
    }


int main()
{
    vector<int>vec = {1,1,2,3,3,4,4,8,8};
    // vector <int> vec = {3,3,7,7,10,1,1};
    cout<< singleNonDuplicate(vec);
    return 0;
}
