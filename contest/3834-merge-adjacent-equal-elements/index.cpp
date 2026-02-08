#include <iostream>
using namespace std;
vector<long long> mergeAdjacent(vector<int> &nums)
{
    vector<long long> st;
    for (int x : nums)
    {
        st.push_back(x);
        while (st.size() >= 2 && st.back() == st[st.size() - 2])
        {
            long long val = st.back(); // FIXED
            st.pop_back();
            st.pop_back();
            st.push_back(val * 2);
        }
    }

    return st;
}
int main()
{

    vector<int> nums = {3, 1, 1, 2};
    vector<long long> result = mergeAdjacent(nums);
    cout << "[ ";
    for (long long x : result)
    {
        cout << x << " ";
    }
    cout << "]";

    return 0;
}