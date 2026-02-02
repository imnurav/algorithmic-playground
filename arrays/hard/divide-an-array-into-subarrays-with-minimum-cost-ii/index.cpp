#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll minimumCost(vector<int> &nums, int k, int dist)
{
    int n = nums.size();
    set<P> kMinimum;
    set<P> remaining;
    ll sum = 0;
    int i = 1;
    while (i - dist < 1)
    {
        kMinimum.insert({nums[i], i});
        sum += nums[i];
        if (kMinimum.size() > k - 1)
        {
            P temp = *kMinimum.rbegin();
            sum -= temp.first;
            remaining.insert(temp);
            kMinimum.erase(temp);
        }
        i++;
    }
    ll result = LONG_MAX;
    while (i < n)
    {
        kMinimum.insert({nums[i], i});
        sum += nums[i];
        if (kMinimum.size() > k - 1)
        {
            P temp = *kMinimum.rbegin();
            sum -= temp.first;
            remaining.insert(temp);
            kMinimum.erase(temp);
        }
        result = min(result, sum);
        P remove = {nums[i - dist], i - dist};
        if (kMinimum.count(remove))
        {
            kMinimum.erase(remove);
            sum -= remove.first;
            if (!remaining.empty())
            {
                P temp = *remaining.begin();
                kMinimum.insert(temp);
                sum += temp.first;
                remaining.erase(temp);
            }
        }
        else
        {
            remaining.erase(remove);
        }
        i++;
    }
    return nums[0] + result;
}
int main()
{
    vector<int> nums = {1, 3, 2, 6, 4, 2};
    int k = 3;
    int dist = 3;
    cout << minimumCost(nums, k, dist) << endl;
    return 0;
}