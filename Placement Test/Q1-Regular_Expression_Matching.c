#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Helper function to check if the character in s matches the character in p
bool isMatchChar(char s, char p) {
    return p == '.' || s == p;
}

// Function to check if the string s matches the pattern p
bool isMatch(const char *s, const char *p) {
    int m = strlen(s);
    int n = strlen(p);

    bool dp[m + 1][n + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true; // Empty string matches empty pattern

    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (isMatchChar(s[i - 1], p[j - 2]) && dp[i - 1][j]);
            } else {
                dp[i][j] = isMatchChar(s[i - 1], p[j - 1]) && dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][n];
}

int main() {
    const char *s1 = "aa", *p1 = "a";
    const char *s2 = "aa", *p2 = "a*";
    const char *s3 = "ab", *p3 = ".*";

    printf("Example 1: %s\n", isMatch(s1, p1) ? "true" : "false");
    printf("Example 2: %s\n", isMatch(s2, p2) ? "true" : "false");
    printf("Example 3: %s\n", isMatch(s3, p3) ? "true" : "false");

    return 0;
}
