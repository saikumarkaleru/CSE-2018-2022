TSP WITH BITMASKING
#include<bits/stdc++.h>
using namespace std;
int mat[10][10];
int N;
int dp[1<<10][10];
int tsp(int mask,int pos)
{
    if(mask==(1<<N)-1)
    {
        return mat[pos][0];
    }
 if(dp[mask][pos]!=-1) return dp[mask][pos];
    //try to go to unvisted city
    int ans=INT_MAX;
    for(int city=0;city<N;city++)
    {
           
           if(((1<<city)&mask)==0)
           {
               int newdis=mat[pos][city] +
               tsp(mask|1<<city,city);
                 ans=min(ans,newdis);
           }
    }
    return  dp[mask][pos]=ans;
}
int main()
{
 
freopen("C:/Users/welcome/Desktop/input.in","r",stdin);
freopen("C:/Users/welcome/Desktop/output.out","w",stdout);
memset(dp,-1,sizeof dp);
cin>>N;
for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
    {
        cin>>mat[i][j];
    }
}
for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
    {
        cout<<mat[i][j]<<" ";
    }
    cout<<endl;
}
cout<<tsp(1,0)<<endl;
 
}
 
 

