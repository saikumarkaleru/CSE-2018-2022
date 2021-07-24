/*
https://www.geeksforgeeks.org/maximize-gcd-of-an-array-by-increments-or-decrements-by-k/
Q) Maximize GCD of an array by increments or decrements by K


*/
/*
#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int k;

int maxgcd(int *arr,int n,int val){
    
    int a1= gcd(val,arr[n]);
    int a2= gcd(val,arr[n]+k);
    int a3= gcd(val,arr[n]-k);
    if(n==0)
       return max({a1,a2,a3});
    
    return max({maxgcd(arr,n-1,a1),maxgcd(arr,n-1,a2),maxgcd(arr,n-1,a3)});
    
}
*/
int main()
{

       int arr[] = {5, 9, 2};
       k = 1;
       cout<<maxgcd(arr,2,0);
        
}

/*
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum GCD
// by taking each operation
int findGCD(int x, int y, int z, int res)
{
	// Store the maximum GCD obtained
	// by either incrementing, decrementing
	// or not changing A[i]
	int ans = __gcd(x, res);
	ans = max(ans, __gcd(y, res));
	ans = max(ans, __gcd(z, res));

	// Return the maximum GCD
	return ans;
}

// Function to find the maximum GCD of
// the array arrA[] by either increasing
// or decreasing the array elements by K
int maximumGCD(int A[], int N, int K)
{
	// Initialize a dp table of size N*3
	int dp[N][3];
	memset(dp, 0, sizeof(dp));

	// Base Cases:
	// If only one element is present
	dp[0][0] = A[0];
	dp[0][1] = A[0] + K;
	dp[0][2] = A[0] - K;
	for (int i = 1; i < N; i++) {
		int x = dp[i - 1][0];
		int y = dp[i - 1][1];
		int z = dp[i - 1][2];

		// Store maximum GCD result
		// for each current state
		dp[i][0] = findGCD(x, y, z, A[i]);
		dp[i][1] = findGCD(x, y, z, A[i] + K);
		dp[i][2] = findGCD(x, y, z, A[i] - K);
	}

	int mx = max(
		{ 3, dp[N - 1][0], dp[N - 1][1],
		dp[N - 1][2] });

	// Return the result
	return mx;
}

// Driver Code
int main()
{
	int arr[] = { 3, 9, 15, 24 };
	int K = 1;
	int N = sizeof(arr) / sizeof(arr[0]);

	cout << maximumGCD(arr, N, K);

	return 0;
}

*/






