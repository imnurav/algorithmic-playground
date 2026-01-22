#include <iostream>
using namespace std;
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    // int n = temperatures.size();
    // vector<int> res(n, 0);
    // stack<int> st;

    // for (int i = 0; i < n; i++)
    // {
    //     while (!st.empty() && temperatures[i] > temperatures[st.top()])
    //     {
    //         int idx = st.top();
    //         st.pop();
    //         res[idx] = i - idx;
    //     }
    //     st.push(i);
    // }
    // return res;
    int n = temperatures.size();
    stack<int> st;
    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && temperatures[i] >= temperatures[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            result[i] = 0;
        }
        else
        {
            result[i] = st.top() - i; 
        }
        st.push(i);
    }
    return result;
}
int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(temperatures);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}