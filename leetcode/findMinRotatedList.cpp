class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[left] <= nums[mid] && nums[mid] < nums[right]) {
                right = mid;
            }
            else if(nums[left] <= nums[mid]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return nums[mid];
    }
};
