/*
class Solution:
    def expand(self,s,L,R):
        while(L>=0 and  R<len(s) and s[L]==s[R]):
            L-=1
            R+=1
        return R-L-1
    def longestPalindrome(self, s: str) -> str:
        if (s == None or len(s) < 1):
            return "";
        start=0
        end=0
        for i in range(len(s)):
            ans1=self.expand(s,i,i)
            ans2=self.expand(s,i,i+1)
            len=max(ans1,ans2)
            if(len>end-start):
                start=i-(len-1)//2
                end=i+len//2
        return s[start:end+1]
            
            
*/


#include <bits/stdc++.h>
using namespace std;

int longestPalSubstr(string str)
{
	int n = str.size();
	// Stores the dp states
	bool table[n][n];
	memset(table, 0, sizeof(table));
	int maxLength = 1;

	for (int i = 0; i < n; ++i)
		table[i][i] = true;

	int start = 0;

	for (int i = 0; i < n - 1; ++i) {

		if (str[i] == str[i + 1]) {
			table[i][i + 1] = true;
			start = i;
			maxLength = 2;
		}
	}

	for (int k = 3; k <= n; ++k) {
		for (int i = 0; i < n - k + 1; ++i) {
			int j = i + k - 1;
			if (table[i + 1][j - 1]
				&& str[i] == str[j]) {
				table[i][j] = true;
				if (k > maxLength) {
					start = i;
					maxLength = k;
				}
			}
		}
	}

	return maxLength;
}

int main()
{

	string str = "forgeeksskeegfor";
	cout << longestPalSubstr(str);

	return 0;
}
