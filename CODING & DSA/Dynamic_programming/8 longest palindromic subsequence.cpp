// C++ program of above approach
#include<bits/stdc++.h>
using namespace std;

// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq, int i, int j)
{
// Base Case 1: If there is only 1 character
if (i == j)
	return 1;

// Base Case 2: If there are only 2
// characters and both are same
if (seq[i] == seq[j] && i + 1 == j)
	return 2;

// If the first and last characters match
if (seq[i] == seq[j])
	return lps (seq, i+1, j-1) + 2;

// If the first and last characters do not match
return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}

/* Driver program to test above functions */
int main()
{
	char seq[] = "GEEKSFORGEEKS";
	int n = strlen(seq);
	cout << "The length of the LPS is "
		<< lps(seq, 0, n-1);
	return 0;
}










// A Dynamic Programming based C++ program for LPS problem
// Returns the length of the longest palindromic subsequence in seq
#include<stdio.h>
#include<string.h>

// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
int n = strlen(str);
int i, j, len;
int L[n][n]; // Create a table to store results of subproblems

for (i = 0; i < n; i++)
	L[i][i] = 1;


	for (len=2; len<=n; len++)
	{
		for (i=0; i<n-len+1; i++)
		{
			j = i+len-1;
			if (str[i] == str[j] && len == 2)
			L[i][j] = 2;
			else if (str[i] == str[j])
			L[i][j] = L[i+1][j-1] + 2;
			else
			L[i][j] = max(L[i][j-1], L[i+1][j]);
		}
	}

	return L[0][n-1];
}
