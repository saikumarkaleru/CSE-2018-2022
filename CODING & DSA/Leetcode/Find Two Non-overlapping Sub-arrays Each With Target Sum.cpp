Given an array of integers arr and an integer target.

You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.

Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.

According to the constraints, we know that values stored in "arr" are all positive value.
Which give us 2 preconditions:

there's no duplicates if we calculate accumulative sum "Accum" for all possible value of i. (0 <= i < arr.size())
Accum[i] stores the sum of arr[0] + arr[1] + ... + arr[i]
"Accum" array is in increasing order.
With above preconditions,

We loop through "arr" for the first time and setup a hash table "tbl" that store {accum[i], i} as {key, value} pair.
Loop through "arr" again, this time we keep track of current accumulative sum "sum". (current index).
if "sum - target" exist in the hash table, which means there's a subarray on the left and ends at index i with length of i - tbl[sum - target]. Update the "l_len" to keep track of minimum length of left subarray .
Since "sum" and "target" are both positive integer and accum[i] is in increasing order, tbl[sum - target] would guarantee to be smaller than i
if "sum + target" exist in the hash table, which means there's a subarray on the right that starts from index i + 1 with length of tbl[sum + target] - i. Update "ret" to keep track of minimum sum of two subarray length.
Note that Step#3 & #4 would guarantee two subrarry are non-overlapping.

int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> tbl;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            tbl[sum] = i;
        }
        int l_len = INT_MAX;
        int ret = INT_MAX;
        sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (tbl.count(sum - target))
                l_len = min(l_len, i - tbl[sum - target]);
            else if (sum == target)
                l_len = min(l_len, tbl[sum] + 1);
            if (tbl.count(sum + target) && l_len != INT_MAX)
                ret = min(ret, tbl[sum + target] - i + l_len);
        }
        return (ret == INT_MAX) ? (-1):(ret);
    }