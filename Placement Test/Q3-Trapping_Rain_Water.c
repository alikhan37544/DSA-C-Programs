#include <stdio.h>

// Function to calculate the amount of trapped rainwater
int trap(int* height, int heightSize) {
    if (heightSize < 3) return 0; // Not enough bars to trap water

    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    int waterTrapped = 0;

    while (left <= right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left]; // Update left maximum
            } else {
                waterTrapped += leftMax - height[left]; // Water trapped at current left
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right]; // Update right maximum
            } else {
                waterTrapped += rightMax - height[right]; // Water trapped at current right
            }
            right--;
        }
    }

    return waterTrapped;
}

int main() {
    // Example 1
    int height1[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size1 = sizeof(height1) / sizeof(height1[0]);
    printf("Output for Example 1: %d\n", trap(height1, size1)); // Output: 6

    // Example 2
    int height2[] = {4, 2, 0, 3, 2, 5};
    int size2 = sizeof(height2) / sizeof(height2[0]);
    printf("Output for Example 2: %d\n", trap(height2, size2)); // Output: 9

    return 0;
}
