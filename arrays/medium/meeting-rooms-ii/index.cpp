#include <iostream>
#include <map>
using namespace std;

int minMeetingRooms(vector<int> &start, vector<int> &end)
{
    // code here
    map<int, int> events;
    int n = start.size();

    for (int i = 0; i < n; i++)
    {
        events[start[i]]++;
        events[end[i]]--;
    }

    int overLaps = 0;
    int maxOverLaps = 0;

    for (auto &it : events)
    {
        overLaps += it.second;
        if (overLaps > maxOverLaps)
            maxOverLaps = overLaps;
    }
    return maxOverLaps;
}
int main()
{
    vector<int> start = {0, 30, 5, 15, 25};
    vector<int> end = {30, 75, 10, 20, 35};
    int result = minMeetingRooms(start, end);
    cout << "Minimum Number of Meeting Rooms Required: " << result;
    return 0;
}