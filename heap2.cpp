// q2 - k largest element

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int answer1(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> min;
    for (int i = 0; i < n; i++)
    {
        min.push(arr[i]);
        if (min.size() > k)
        {
            min.pop();
        }
    }
    return min.top();
}

// q3 - You are given a nearly sorted array where each element is at most k positions
// away from its correct position in the sorted array. Your task is to completely sort the array.
// q3 - sort a k sorted array or nearly sorted array
// values in the given array differ from there complete sorted array
// index value by k... so range 0-k or 0+k
int *answerq3(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> min;
    int *ans = new int[n];
    for (int i = 0; i < n; i++)
    {
        min.push(arr[i]);
        if (min.size() > k)
        {

            ans[i - k] = min.top();
            min.pop();
        }
    }
    int j = 0;
    while (!min.empty())
    {
        ans[n - k + j] = min.top();
        min.pop();
        j++;
    }
    return ans;
}
// heap is not sorted only the first element is in the right position
// whenever popped , heap re-heaped

vector<int> answer4(int arr[], int n, int k)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> min;

    for (int i = 0; i < n; i++)
    {
        min.push(arr[i]);
        if (min.size() > k)
        {
            ans.push_back(min.top());
            min.pop();
        }
    }
    while (!min.empty())
    {
        ans.push_back(min.top());
        min.pop();
    }
}