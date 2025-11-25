#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> pow2(n, 1);
        for (int i = 1; i < n; i++)
            pow2[i] = (pow2[i - 1] * 2) % MOD;

        int left = 0, right = n - 1;
        long long ans = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + pow2[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return ans % MOD;
    }
};

int main() {
    Solution s;
    int n, target;
    
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    int result = s.numSubseq(nums, target);
    cout << "Result: " << result << endl;

    return 0;
}
