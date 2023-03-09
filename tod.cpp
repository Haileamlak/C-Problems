#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int res = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (size_t j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    int sum = 0;
                    for (size_t k = j; k < nums.size(); k++)
                        sum += nums[k];
                    
                    res +(sum==k?2:1);
                    break;
                }
            }
        }
        return res + k == 0 ? 1 : 0;
    }
};

int main()
{
    Solution xx;
    cout << xx.myPow(1, 1);
    return 0;
}