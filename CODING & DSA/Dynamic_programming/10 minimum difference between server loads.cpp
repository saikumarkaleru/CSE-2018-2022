https://www.geeksforgeeks.org/minimum-absolute-difference-of-server-loads/

There are some processes that need to be executed. The amount of load that process causes a server that runs it, is being represented by a single integer. The total load caused on a server is the sum of the loads of all the processes that run on that server. You have at your disposal two servers, on which the mentioned processes can be run. Your goal is to distribute given processes between those two servers in a way that, the absolute difference of their loads will be minimized. 
Given an array of A[] of N integers, which represents loads caused by successive processes, the task is to print the minimum absolute difference of server loads. 
Examples:

Input: A[] = {1, 2, 3, 4, 5} 
Output: 1 
Explanation: 
Distribute the processes with loads {1, 2, 4} on the first server and {3, 5} on the second server, so that their total loads will be 7 and 8, respectively. 
The difference of their loads will be equal to 1.

Input: A[] = {10, 10, 9, 9, 2} 
Output: 0


The problem can be visualized as a variation of the 0/1 Knapsack problem in which 2 servers are given, and we have to distribute the loads as equally possible. Therefore, it can be solved using Dynamic Programming. Below are the steps:



Compute required_load, which is equal to (sum of all loads / 2), 
since the loads need to distributed as equally possible.
Create a memoization table DP[][] to consider all the possible server
 loads in the range [1, required_load].
The state DP[i][j] stores the maximum value of j – load considering up to the ith element. 
So, considering li(load in ith row), it can be filled in all the columns having load values > li.
Now two possibilities arise, either to fill li in the given column or not.
Now, take a maximum of the above two possibilities, i.e.
DP[i][j] = max(DP[i – 1][j], DP[i – 1][j – li] + li]

Finally, DP[n][required_load] will contain the load on server1 which is as balanced as possible.


// C++14 program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function which returns the minimum
// difference of loads
int minServerLoads(int n, vector<int>& servers)
{
	
	// Compute the overall server load
	int totalLoad = 0;
	for(int i : servers) totalLoad += i;

	int requiredLoad = totalLoad / 2;

	// Stores the results of subproblems
	vector<vector<int>> dp(n + 1,
	vector<int>(requiredLoad + 1, 0));

	// Fill the partition table
	// in bottom up manner
	for(int i = 1; i < n + 1; i++)
	{
		for(int j = 1; j < requiredLoad + 1; j++)
		{
			
			// If i-th server is included
			if (servers[i - 1] > j)
				dp[i][j] = dp[i - 1][j];

			// If i-th server is excluded
			else
				dp[i][j] = max(dp[i - 1][j],
						servers[i - 1] +
						dp[i - 1][j - servers[i - 1]]);
		}
	}

	// Server A load: total_sum-ans
	// Server B load: ans
	// Diff: abs(total_sum-2 * ans)
	return totalLoad - 2 * dp[n][requiredLoad];
}

// Driver Code
int main()
{
	int N = 5;
	
	vector<int> servers = { 1, 2, 3, 4, 5 };
	
	// Function call
	cout << (minServerLoads(N, servers));
}

// This code is contributed by mohit kumar 29




=========================================

How to divide a set into two subsets such that difference between the sum of numbers in two sets is minimal?

public int minDiffernce(int set[]) {      
    int sum = 0;
    int n = set.length;
    for(int i=0; i<n; i++)
        sum+=set[i];

    //finding half of total sum, because min difference can be at max 0, if one subset reaches half
    int target = sum/2;
    boolean[][] dp = new boolean[n+1][target+1];//2

    for(int i = 0; i<=n; i++)
        dp[i][0] = true;
    for(int i= 1; i<=n; i++){
        for(int j = 1; j<=target;j++){
            if(set[i-1]>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
        }
    }

    // we now find the max sum possible starting from target
    int firstPart = 0;
    for(int j = target; j>=0; j--){
        if(dp[n][j] == true) {
            firstPart = j; break;
        }
    }

    int secondPart = sum - firstPart;
    return Math.abs(firstPart - secondPart);
}
