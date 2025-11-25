#include <bits/stdc++.h>
using namespace std;

// LeetCode 1015. Smallest Integer Divisible by K

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if( K %2==0 || K %5==0)
        {
            return -1;
        }
        int rem=0;
        for(int i=1;i<=K;i++)
        {
          rem = (rem*10+1) % K;
          if(rem==0)
          {
            return i;
          }
        }
        return -1;
    }
};

int main() {
    Solution s;

    int K;
    cout << "Enter K: ";
    cin >> K;

    int result = s.smallestRepunitDivByK(K);
    cout << "Result: " << result << endl;

    return 0;
}
