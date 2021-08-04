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







//=============================================================================================

class Solution {
    
   boolean searchRec(int[] nums, int target, int start, int end)
{
    if(start <= end)
    {
         int mid = start + (end-start)/2;
        if(nums[mid] == target) return true;
        
        if(nums[mid]<nums[end]  && (nums[mid] < target && target <= nums[end]))
            return searchRec(nums, target, mid+1, end);
        
        if(nums[start]<nums[mid]  && (nums[start] < target && target <= nums[mid]))
            return searchRec(nums, target, start, mid-1);
        
          return searchRec(nums, target, start, mid-1) || 
                   searchRec(nums, target, mid+1, end);
        
    }
    return false;
   
}    
    
    public boolean search(int[] nums, int target) {
      int start = 0, end = nums.length-1;
    return searchRec(nums, target, 0, nums.length-1);    
        
    
        
    }
}













=========================================================================================


class Solution 
{
    int[] input;
    int tar;
    
    public boolean search(int[] nums, int target) 
    {
        int index = 0;
        input = nums;
        tar = target;
        
        for(int i = 0; i <= nums.length - 2 ; i++)
            if(nums[i] > nums[i+1]){
                index = i;
                break;
            }
        
        return (binarySearch(0, index) || binarySearch(index + 1, nums.length - 1)); 
    }
    
    public boolean binarySearch(int start, int end){
        if(start <= end){
            int mid = start +(end - start) / 2;
            
            if(input[mid] == tar) return true;
            
            else if(start == end) return false;
            
            else if(input[mid] >= tar) 
                return binarySearch(start, mid);
            
            else 
                return binarySearch(mid + 1, end);
        }
        return false;
    }
}