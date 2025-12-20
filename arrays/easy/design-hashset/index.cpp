#include <iostream>
using namespace std;
#include <vector>

class MyHashSet
{
private:
    vector<bool> table;

public:
    MyHashSet()
    {
        table.resize(1000001, false);
    }

    void add(int key)
    {
        table[key] = true;
    }

    void remove(int key)
    {
        table[key] = false;
    }

    bool contains(int key)
    {
        return table[key];
    }
};

int main()
{
    MyHashSet myHashSet;

    myHashSet.add(1); // set = [1]
    myHashSet.add(2); // set = [1,2]

    cout << myHashSet.contains(1) << endl; // true -> 1
    cout << myHashSet.contains(3) << endl; // false -> 0

    myHashSet.add(2);                      // set = [1,2]
    cout << myHashSet.contains(2) << endl; // true -> 1

    myHashSet.remove(2);                   // set = [1]
    cout << myHashSet.contains(2) << endl; // false -> 0
    return 0;
}