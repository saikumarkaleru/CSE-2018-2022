/*
* Return the index of the number, if we could find in the array.
 * Otherwise return -1
 * 
 * @aglo 1 search linear
 *  Obviously, we have to provide a better solution than in linear time 
 * 
 * @aglo 2 Improve linear to logarithm - Binary Search
 *  1. Firstly, try to find the start of the array by Binary Search
 *  2. With the start point, we can easily to decide which side we should implement the binary search for the target
 * 
 *  Time O(logN)
 *  Space O(1)
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = binarySearchStartPoint(0, nums.size()-1, nums);
        int ans = 0;
        if(target <= nums[nums.size()-1]) {
            // target is between start point and last index
            ans = binarySearchTarget(start, nums.size()-1, target, nums);
        }
        else {
            // target is between and first index and start point
            ans = binarySearchTarget(0, max(0, start-1), target, nums);
        }
        return ans;
    }

    int binarySearchStartPoint(int left, int right, vector<int>& nums) {
        if(nums[left] <= nums[right]) return 0;

        while(left <= right) {
            int pivot = (left + right) / 2;
            if(nums[pivot] >= nums[pivot+1]) {
                // find the start point
                return pivot+1;
            }
            else {
                // continue the searching
                if(nums[left] > nums[pivot]) {
                    // the concave point is in the left side of the pivot
                    right = pivot - 1;
                }
                else {
                    // the concave point is in the right side of the pivot
                    left = pivot + 1;
                }
            }
        }
        return 0;
    }
    
    int binarySearchTarget(int left, int right, int target, vector<int>& nums) {
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;

        while(left <= right) {
            int pivot = (left + right) / 2;
            if(nums[pivot] == target) {
                return pivot;
            }
            else {
                if(nums[pivot] >= target) {
                    // the target is in the left side of the pivot
                    right = pivot - 1;
                }
                else {
                    left = pivot + 1;
                }
            }
        }
        return -1;
    }
};