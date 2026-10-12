#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int k = i + 1; k < nums.size(); k++)
        if (nums[i] + nums[k] == target) {
            return {i, k};
        }
    }
    return {};
}

vector<int> twoSumHash(vector<int>& nums, int target) {
    unordered_map<int, int> indexes;
    for (int i = 0; i < nums.size(); i++) {
        int needed = target - nums[i];
        if (indexes.count(needed)) {
            return {indexes[needed], i};
        }
        indexes[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums1 = {
        15, 4, 18, 8, 19, 22, 24, 59,
        59, 20, 18, 12, 36, 42, 9
    };
    int target1 = 24;

    vector<int> bruteAnswer1 = twoSumBruteForce(nums1, target1);
    vector<int> hashAnswer1 = twoSumHash(nums1, target1);

    cout << "Test Case 1\n";

    if (!bruteAnswer1.empty()) {
        cout << "Brute Force Indices: ["
             << bruteAnswer1[0] << ", "
             << bruteAnswer1[1] << "]\n";
    }

    if (!hashAnswer1.empty()) {
        cout << "Hash Map Indices: ["
             << hashAnswer1[0] << ", "
             << hashAnswer1[1] << "]\n";
    }

    vector<int> nums2 = {2, 7, 11, 15};
    int target2 = 9;

    vector<int> bruteAnswer2 = twoSumBruteForce(nums2, target2);
    vector<int> hashAnswer2 = twoSumHash(nums2, target2);

    cout << "\nTest Case 2\n";

    if (!bruteAnswer2.empty()) {
        cout << "Brute Force Indices: ["
             << bruteAnswer2[0] << ", "
             << bruteAnswer2[1] << "]\n";
    }

    if (!hashAnswer2.empty()) {
        cout << "Hash Map Indices: ["
             << hashAnswer2[0] << ", "
             << hashAnswer2[1] << "]\n";
    }

    vector<int> nums3 = {-3, 4, 8, 12};
    int target3 = 5;

    vector<int> bruteAnswer3 = twoSumBruteForce(nums3, target3);
    vector<int> hashAnswer3 = twoSumHash(nums3, target3);

    cout << "\nTest Case 3\n";

    if (!bruteAnswer3.empty()) {
        cout << "Brute Force Indices: ["
             << bruteAnswer3[0] << ", "
             << bruteAnswer3[1] << "]\n";
    }

    if (!hashAnswer3.empty()) {
        cout << "Hash Map Indices: ["
             << hashAnswer3[0] << ", "
             << hashAnswer3[1] << "]\n";
    }

    vector<int> nums4 = {3, 3, 10, 20};
    int target4 = 6;

    vector<int> bruteAnswer4 = twoSumBruteForce(nums4, target4);
    vector<int> hashAnswer4 = twoSumHash(nums4, target4);

    cout << "\nTest Case 4\n";

    if (!bruteAnswer4.empty()) {
        cout << "Brute Force Indices: ["
             << bruteAnswer4[0] << ", "
             << bruteAnswer4[1] << "]\n";
    }

    if (!hashAnswer4.empty()) {
        cout << "Hash Map Indices: ["
             << hashAnswer4[0] << ", "
             << hashAnswer4[1] << "]\n";
    }

    vector<int> nums5 = {0, 5, 12, 20};
    int target5 = 5;

    vector<int> bruteAnswer5 = twoSumBruteForce(nums5, target5);
    vector<int> hashAnswer5 = twoSumHash(nums5, target5);

    cout << "\nTest Case 5\n";

    if (!bruteAnswer5.empty()) {
        cout << "Brute Force Indices: ["
             << bruteAnswer5[0] << ", "
             << bruteAnswer5[1] << "]\n";
    }

    if (!hashAnswer5.empty()) {
        cout << "Hash Map Indices: ["
             << hashAnswer5[0] << ", "
             << hashAnswer5[1] << "]\n";
    }

    return 0;
}