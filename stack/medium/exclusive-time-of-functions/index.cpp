#include <iostream>
using namespace std;
vector<int> exclusiveTime(int n, vector<string> &logs)
{
    vector<int> ans(n, 0);
    stack<int> st;
    int prevTime = 0;
    for (string log : logs)
    {
        int firstColon = log.find(':');
        int secondColon = log.find(':', firstColon + 1);
        int id = stoi(log.substr(0, firstColon));
        string type =
            log.substr(firstColon + 1, secondColon - firstColon - 1);
        int time = stoi(log.substr(secondColon + 1));
        if (type == "start")
        {
            if (!st.empty())
            {
                ans[st.top()] += time - prevTime;
            }
            st.push(id);
            prevTime = time;
        }
        else
        {
            ans[st.top()] += time - prevTime + 1;
            st.pop();
            prevTime = time + 1;
        }
    }
    return ans;
}
int main()
{
    vector<string> arr = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
    vector<int> output = exclusiveTime(2, arr);
    cout << "[ ";
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << "]";
    return 0;
}