'''
Dynamic Programming:
Let the given set of vertices be {1, 2, 3, 4,….n}.
 Let us consider 1 as starting and ending point of output. For every other vertex i (other than 1),
 we find the minimum cost path with 1 as the starting point, i as the ending point and all vertices appearing exactly once. Let the cost of this path be cost(i), the cost of corresponding Cycle would be cost(i) + dist(i, 1) where dist(i, 1) is the distance from i to 1. Finally, we return the minimum of all [cost(i) + dist(i, 1)] values. This looks simple so far. Now the question is how to get cost(i)?
To calculate cost(i) using Dynamic Programming, we need to have some recursive relation in terms of sub-problems.
 Let us define a term C(S, i) be the cost of the minimum cost path visiting each vertex in set S exactly once, starting at 1 and ending at i.
We start with all subsets of size 2 and calculate C(S, i) for all subsets where S is the subset, then we calculate C(S, i) 
for all subsets S of size 3 and so on. Note that 1 must be present in every subset.

If size of S is 2, then S must be {1, i},
 C(S, i) = dist(1, i) 
Else if size of S is greater than 2.
 C(S, i) = min { C(S-{i}, j) + dis(j, i)} where j belongs to S, j != i and j != 1.
For a set of size n, we consider n-2 subsets each of size n-1 such that all subsets don’t have nth in them.
Using the above recurrence relation, we can write dynamic programming based solution. 
There are at most O(n*2^n) subproblems, and each one takes linear time to solve. The total running time is therefore O(n^2*2^n). 
The time complexity is much less than O(n!), but still exponential. 
Space required is also exponential. So this approach is also infeasible even for slightly higher number of vertices.





=====================bitmasking====================================

'''
#include <bits/stdc++.h>
using namespace std;
int n=4;
int dist[5][5]={    {0,20,42,25},
                    {20,0,30,34},
                    {42,30,0,10},
                    {24,34,10,0}
                };
int  VISITED_ALL=(1<<n) -1;

 int tsp(int mask,int pos){    //mask set of cities we have visited so far and not visited ex:001100
     if(mask==VISITED_ALL){
         return dist[pos][0];
     }
     //try to go to unvisted cities
     int ans=INT_MAX;
     for(int city=0;city<n;city++)
     {
         if((mask&(1<<city))==0){
             int newans=dist[pos][city] + tsp(mask | (1<<city),city);
            ans=min(ans,newans);
         }
     }
             
     return ans;
 }
int main()
{
 
   
    
    cout<<tsp(1,0)<<endl;

    return 0;
}
=========================================dp top down=======================
#include <bits/stdc++.h>
using namespace std;
int n=4;
int dist[5][5]={    {0,20,42,25},
                    {20,0,30,34},
                    {42,30,0,10},
                    {24,34,10,0}
                };
vector<vector<int>> dp(1<<n);
int  VISITED_ALL=(1<<n) -1;

 int tsp(int mask,int pos){    //mask set of cities we have visited so far and not visited ex:001100
     if(mask==VISITED_ALL){
         return dist[pos][0];
     }
     if(dp[mask][pos]!=-1){
         return dp[mask][pos];
     }
     //try to go to unvisted cities
     int ans=INT_MAX;
     for(int city=0;city<n;city++)
     {
         if((mask&(1<<city))==0){
             int newans=dist[pos][city] + tsp(mask | (1<<city),city);
            ans=min(ans,newans);
         }
     }
        return  dp[mask][pos]=ans;    

 }
int main()
{
 
   for(int i=0;i<1<<n;i++)
   {
       
       for(int j=0;j<n;j++){
           dp[i].push_back(-1);
       }
   }
    
    cout<<tsp(1,0)<<endl;
  
    
    return 0;
}
