
int binomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;
  
    // Calculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
  
            // Calculate value using previously stored values
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
  
    return C[n][k];
}










NCR= N-1CR-1 + N-1CR

N elements   selecting R items

considering N th element selected + Nth element not selected
N-1 C R-1   +   N-1 C R

Selecting   the ith student n-1 cr-1  +  not   selecting ith student n-1 c r
 
 Ncr = n-1Cr-1 + n-1 C r
 
[n][r]= [n-1][r-1] + [n-1][r] 
 
 
[n][0]=1;  // {}
[n][n]=1;  // {1,2,3,..N}
#define MAXN 100 
long binomial_coefficient(n,m)
{
 
long bc[MAXN][MAXN];
for (i=0; i<=n; i++)
    for (j=0; j<=i; j++)
		if(i==j or j==0) bc[i][j]=1
           else 
            bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
return bc[n][m];
}
 

