Given two strings X and Y. The task is to find the length of the longest subsequence of string 
X which is a substring in sequence Y.
Examples: 
 

Input : X = "ABCD",  Y = "BACDBDCD"
Output : 3
"ACD" is longest subsequence of X which
is substring of Y.

Input : X = "A",  Y = "A"
Output : 1
 
int maxSubsequenceSubstring(string &X,string &Y,int n,int m)
{
    // Base Case
    if (n==0 || m==0) return 0;
    
    // Calls on smaller inputs
    
    // if the last char of both strings are equal
    if(X[n-1] == Y[m-1])
    {
        return  1 + maxSubsequenceSubstring(X,Y,n-1,m-1);
    }
    
    // if the last char of both strings are not equal
    else
    {
        return maxSubsequenceSubstring(X,Y,n-1,m);    
    }









    // Java program to find maximum length of
// subsequence of a string X such it is
// substring in another string Y.

public class GFG
{
	static final int MAX = 1000;
	
	// Return the maximum size of substring of
	// X which is substring in Y.
	static int maxSubsequenceSubstring(char x[], char y[],
								int n, int m)
	{
		int dp[][] = new int[MAX][MAX];
	
		// Initialize the dp[][] to 0.
		for (int i = 0; i <= m; i++)
			for (int j = 0; j <= n; j++)
				dp[i][j] = 0;
	
		// Calculating value for each element.
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
	
				// If alphabet of string X and Y are
				// equal make dp[i][j] = 1 + dp[i-1][j-1]
				if (x[j - 1] == y[i - 1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
	
				// Else copy the previous value in the
				// row i.e dp[i-1][j-1]
				else
					dp[i][j] = dp[i][j - 1];
			}
		}
	
		// Finding the maximum length.
		int ans = 0;
		for (int i = 1; i <= m; i++)
			ans = Math.max(ans, dp[i][n]);
	
		return ans;
	}
	
	// Driver Method
	public static void main(String[] args)
	{
		char x[] = "ABCD".toCharArray();
		char y[] = "BACDBDCD".toCharArray();
		int n = x.length, m = y.length;
		System.out.println(maxSubsequenceSubstring(x, y, n, m));
	}
}
