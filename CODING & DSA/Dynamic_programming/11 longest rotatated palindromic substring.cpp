Intuition

https://binarysearch.com/problems/Longest-Rotated-Palindromic-Substring/editorials/3922625
int solve(string s) {
    // Storing the original length for further use
    int original = s.length();

    // Concatenating the string
     s = s + s;

    // Storing length and intialising answer = 1, min length will be 1.
    int n = s.length(), ans = 1;

    // Declaring a boolean matrix to store the nature of substring from i to j
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Setting every 1 length substring to true.
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Checking palindromic substring
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                if (dp[i + 1][j - 1] || j - i == 1) {
                    int len = j - i + 1;

                    // If len of current substring is <= original length
                    // It may or may not be a rotation
                    // Either case it is a valid substring
                    if (len <= original) {
                        ans = max(ans, len);
                    }

                    // Marking this substring as true
                    dp[i][j] = true;
                }
            }
        }
    }
    return ans;
}
