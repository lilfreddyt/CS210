#include <iostream>
#include <vector>
using namespace std;

int iterativeCount;
int recursiveCount;

int iterativeBinarySearch(vector<int>&nums, int target) {
    iterativeCount = 0;
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            iterativeCount++;
            return mid;
        }
        else if (nums[mid] < target) {
            iterativeCount++;
            low = mid + 1;
        }
        else if (nums[mid] > target) {
            iterativeCount++;
            high = mid - 1;
        }
    }    
    return -1;
}

int recursiveBinarySearch(vector<int>&nums, int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (nums[mid] == target) {
        recursiveCount++;
        return mid;
    }
    else if (nums[mid] < target) {
        recursiveCount++;
        return recursiveBinarySearch(nums, mid + 1, high, target);
    }
    else if (nums[mid] > target) {
        recursiveCount++;
        return recursiveBinarySearch(nums, low, mid - 1, target);
    }
}


int main() {
    vector<int>nums = {2, 6, 13, 19, 24};
    
    cout << "Iterative Search Test" << endl;
    cout << "Index : " << iterativeBinarySearch(nums, 2) << endl;
    cout << "Comparisons: " << iterativeCount << endl;
    cout << "Index : " <<iterativeBinarySearch(nums, 24) << endl;
    cout << "Comparisons: " << iterativeCount << endl;
    cout << "Index : " << iterativeBinarySearch(nums, 13) << endl;
    cout << "Comparisons: " << iterativeCount << endl;
    cout << "Index : " << iterativeBinarySearch(nums, 1) << endl;
    cout << "Comparisons: " << iterativeCount << endl;
    cout << "Index : " << iterativeBinarySearch(nums, 25) << endl;
    cout << "Comparisons: " << iterativeCount << endl << endl;

    cout << "Recursive Search Test" << endl;
    cout << "Index : " << recursiveBinarySearch(nums, 0, nums.size() - 1, 2) << endl;
    cout << "Comparisons: " << recursiveCount << endl;
    recursiveCount = 0;
    cout << "Index : " <<recursiveBinarySearch(nums, 0, nums.size() - 1, 24) << endl;
    cout << "Comparisons: " << recursiveCount << endl;
    recursiveCount = 0;
    cout << "Index : " << recursiveBinarySearch(nums, 0, nums.size() - 1, 13) << endl;
    cout << "Comparisons: " << recursiveCount << endl;
    recursiveCount = 0;
    cout << "Index : " << recursiveBinarySearch(nums, 0, nums.size() - 1, 1) << endl;
    cout << "Comparisons: " << recursiveCount << endl;
    recursiveCount = 0;
    cout << "Index : " << recursiveBinarySearch(nums, 0, nums.size() - 1, 25) << endl;
    cout << "Comparisons: " << recursiveCount << endl;
}