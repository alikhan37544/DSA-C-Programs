#include <stdio.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    int sLen = strlen(s), tLen = strlen(t);

    if (sLen < tLen || tLen == 0) {
        return ""; // No valid window if t is longer than s
    }

    // Frequency map for characters in t
    int tFreq[128] = {0};
    for (int i = 0; i < tLen; i++) {
        tFreq[t[i]]++;
    }

    // Sliding window
    int left = 0, right = 0;
    int required = tLen; // Number of characters we still need to include
    int minLen = INT_MAX, startIdx = 0;

    while (right < sLen) {
        char rChar = s[right];
        if (tFreq[rChar] > 0) {
            required--;
        }
        tFreq[rChar]--;
        right++;

        // Contract the window
        while (required == 0) {
            if (right - left < minLen) {
                minLen = right - left;
                startIdx = left;
            }

            char lChar = s[left];
            tFreq[lChar]++;
            if (tFreq[lChar] > 0) {
                required++;
            }
            left++;
        }
    }

    if (minLen == INT_MAX) {
        return ""; // No valid window found
    }

    // Allocate memory for the result substring
    char* result = (char*)malloc((minLen + 1) * sizeof(char));
    strncpy(result, s + startIdx, minLen);
    result[minLen] = '\0'; // Null-terminate the substring
    return result;
}

int main() {
    // Example 1
    char s1[] = "ADOBECODEBANC";
    char t1[] = "ABC";
    printf("Output for Example 1: %s\n", minWindow(s1, t1)); // Output: "BANC"

    // Example 2
    char s2[] = "a";
    char t2[] = "a";
    printf("Output for Example 2: %s\n", minWindow(s2, t2)); // Output: "a"

    // Example 3
    char s3[] = "a";
    char t3[] = "aa";
    printf("Output for Example 3: %s\n", minWindow(s3, t3)); // Output: ""

    return 0;
}
