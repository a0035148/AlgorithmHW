#include <vector>
#include <cstdlib> // For rand()

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        // The index we are looking for in a theoretical sorted array
        int targetIndex = nums.size() - k; 
        
        while (left <= right) {
            int pivotIndex = partition(nums, left, right);
            
            if (pivotIndex == targetIndex) {
                return nums[pivotIndex]; // Found the kth largest!
            } else if (pivotIndex < targetIndex) {
                left = pivotIndex + 1;   // Search the right half
            } else {
                right = pivotIndex - 1;  // Search the left half
            }
        }
        
        return -1; // Should not be reached with valid inputs
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        // Randomize pivot to avoid O(N^2) worst-case on already sorted arrays
        int pivotIndex = left + rand() % (right - left + 1);
        swap(nums[pivotIndex], nums[right]);
        
        int pivot = nums[right];
        int p = left;
        
        for (int i = left; i < right; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        
        // Move the pivot to its final, correct sorted position
        swap(nums[p], nums[right]);
        return p; 
    }
};