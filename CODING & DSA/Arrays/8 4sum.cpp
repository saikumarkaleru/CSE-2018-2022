/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

*/

// C++ Two Pointer Sorting Approach

 int n=nums.size();
    vector<vector<int>> v;
    if(n<4){                                   //Base Condition
        return v;
    }
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-3;i++){
        if(i==0 || nums[i]>nums[i-1]){                //if repetitions then we avoid 
            for(int j=i+1;j<n-2;j++){
                if(j==i+1 || nums[j]>nums[j-1]){         //same for j but atleast once it has to execute
                    int k=j+1,l=n-1;
                    while(k<l){                                   //Remaining 3SUM extension
                        int sum=nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum==target){
                            v.push_back({nums[i],nums[j],nums[k],nums[l]});
                            while(k<l && nums[k]==nums[k+1]){
                                k++;
                            }
                            while(k<l && nums[l]==nums[l-1]){
                                l--;
                            }
                            k++,l--;
                        }else if(sum>target){
                            l--;
                        }else{
                            k++;
                        }
                    }
                }
            }
        }
    }
    return v;