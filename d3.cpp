#include <vector>
#include <iostream>
#include <climits>
using namespace std;

// First negative number in window of size K
vector<int> answer1(const vector<int> arr, int K)
{
    int n = arr.size();
    vector<int> negatives;
    vector<int> result;
    for (int i = 0; i < K; i++)
    {
        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
    }
    for (int i = K; i < n; i++)
    {
        if (negatives.size() == 0)
        {
            result.push_back(0);
        }
        else
        {

            result.push_back(negatives.front());
        }

        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
        if (arr[i - K] < 0)
        {
            negatives.erase(negatives.begin());
        }
    }
    return result;
}

// revision of answer on day4

vector<int> answer(const vector<int> arr, int k)
{
    vector<int> negatives;
    vector<int> result;
    int n = arr.size();

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
    }
    for (int i = k; i < n; i++)
    {
        if (negatives.size() == 0)
        {
            result.push_back(0);
        }
        else
        {
            result.push_back(negatives.front());
        }
        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
        if (arr[i - k] < 0)
        {
            negatives.erase(negatives.begin());
        }
    }
    return result;
}

// incorrect - doesn't take care of window without negative
vector<int> revision(const vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> negatives;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n - k + 1; i++)
    {
        result.push_back(negatives[i]);
    }
    return result;
}

// to correct implement we need to do first window in separate loop
vector<int> revision1(const vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> negatives;
    vector<int> result;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
    }
    for (int i = k; i < n; i++)
    {
        if (negatives.size() == 0)
        {
            result.push_back(0);
        }
        else
        {
            result.push_back(negatives.front());
        }
        if (arr[i] < 0)
        {
            negatives.push_back(arr[i]);
        }
        if (arr[i - k] < 0)
        {
            negatives.erase(negatives.begin());
        }
    }
    return result;
}

// push_back, erase(pointer), begin()->iterator,end(), front()->value, back(), size(), empty()
// pop_back(), reverse(.begin(),.end()), sort(.begin(),.end());

// 2 vectors - neg and result, fill neg one loop for k; next loop- remove n.front() if i-k < 0, if neg.size()!=0; add to result;
//