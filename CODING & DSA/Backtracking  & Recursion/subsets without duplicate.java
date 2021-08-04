

class Solution {
public List<List> subsetsWithDup(int[] nums) {

    Arrays.sort(nums);
    
    List<List<Integer>> ans = new ArrayList<>();
    
    HashSet<List<Integer>> hs=new HashSet<>();
    
    for(int i=0;i<(1<<nums.length);i++){
        List<Integer> set=new ArrayList<Integer>();
        for(int j=0;j<nums.length;j++){
            if(((1)&(i>>j))==1){
                set.add(nums[j]);
            }
        }
        if(!hs.contains(set)){
            hs.add(set);
            ans.add(set);
        }
    }
    return ans;
}





public List<List<Integer>> subsetsWithDup(int[] nums) {
    List<List<Integer>> out = new ArrayList<>();
    int n = nums.length;
    Arrays.sort(nums);
    subset(0, nums, n, new ArrayList<>(), out);
    return out;
}

private void subset(int idx, int[] nums, int n, List<Integer> arr, List<List<Integer>> out) {
    out.add(new ArrayList<>(arr));
    for(int i=idx;i<n;i++){
        if(i>idx && nums[i]==nums[i-1])
            continue;
        arr.add(nums[i]);
        subset(i+1, nums, n, arr, out);
        arr.remove(arr.size()-1);
    }
}






















