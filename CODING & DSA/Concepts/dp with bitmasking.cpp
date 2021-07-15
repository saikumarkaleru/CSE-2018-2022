Problem 1: https://www.spoj.com/problems/ASSIGN/
In questions involving bitmasks, the constraints are generally very low. (n<=20 or 25)
Consider a set of n topics .

Let us consider in a ,mask, if ith bit is 1 represents that i^th student has been given a subject.
If i^th bit is 0, then that student has not taken any subject yet.
Let k = smallest index of topic left to be distributed 

int dp [ 1<<n ][ n ] // initially each value -1 
int solve(int mask, int k)
{
int ans=0;
if (k == n) {
  return 1;
}
 if (dp[mask][k]!=-1)
      return dp[mask][k];
    for(i=0; i<n; i++)
    {
         if(a[i][k]==1 && !(mask & (1<<i)) ) 
          {
             ans = ans + solve (mask | (1<<i), k+1 ) 
          }
     }
return dp[mask][k]=ans;
}

 // in main
 solve(0, 0)


Time complexity: O(n2*2n) or O(n*2n)

This solution will give MLE / TLE
We can reduce the state for k as follows:

int dp [ 1<<n ] 
int solve(int mask)
{
int k = __builtin_popcount(mask);
// Now, k = set bits in mask calculated in O(1)
// Effectively , k = index of topic to be assigned
int ans=0;
if (k == n) {
  return 1;
 }
 if (dp[mask]!=-1)
      return dp[mask];
    for(i=0; i<n; i++)
    {
         if(a[i][k]==1 && !(mask & (1<<i)) ) 
          {
             ans = ans + solve (mask | (1<<i)) 
          }
     }
return dp[mask]=ans;
}

// In main, 
solve(0)


Time complexity: O(2^n * n)


Another trick for some number theory + bitmask problems
Any number n can be represented as a mask of its prime divisors.
Prime numbers = {2,3,5,7,11}
Eg. n=6, 6=2*3, n = 001100
Sometimes, this helps to calculate GCD, LCM of 2 numbers effectively using bitwise & and bitwise | operations respectively.
If you want to iterate through all the prime divisors of n, just iterate through all the set bits of n
If you want to iterate through all the divisors of n, just iterate through all the submasks of n




