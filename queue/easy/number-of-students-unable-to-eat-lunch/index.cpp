#include <iostream>
using namespace std;
int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    queue<int> q;
    for (int s : students)
        q.push(s);

    int i = 0;
    int rotations = 0;

    while (!q.empty() && rotations < q.size())
    {
        if (q.front() == sandwiches[i])
        {
            q.pop();
            i++;
            rotations = 0;
        }
        else
        {
            q.push(q.front());
            q.pop();
            rotations++;
        }
    }
    return q.size();
}
int main()
{
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    cout << countStudents(students, sandwiches) << endl;
    return 0;
}