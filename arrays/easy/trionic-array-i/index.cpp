#include <iostream>
using namespace std;
bool isTrionic(vector<int> &nums)
{
    int n = nums.size();
    int firstPeakIndex = 0;
    while (firstPeakIndex < n - 2 &&
           nums[firstPeakIndex] < nums[firstPeakIndex + 1])
    {
        firstPeakIndex++;
    }
    if (firstPeakIndex == 0)
        return false;

    int valleyIndex = firstPeakIndex;
    while (valleyIndex < n - 1 &&
           nums[valleyIndex] > nums[valleyIndex + 1])
    {
        valleyIndex++;
    }
    if (valleyIndex == firstPeakIndex || valleyIndex == n - 1)
        return false;

    int currentIndex = valleyIndex;
    while (currentIndex < n - 1 &&
           nums[currentIndex] < nums[currentIndex + 1])
    {
        currentIndex++;
    }
    return currentIndex == n - 1;
}
int main()
{
    vector<int> nums = {2,1,3};
    if (isTrionic(nums))
        cout << "The array is trionic." << endl;
    else
        cout << "The array is not trionic." << endl;
    return 0;
}