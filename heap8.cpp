// K -closed points to origin

// Given a list of points on a 2D plane, the task is to find the K closest points to the origin (0, 0). The distance between two points (x1, y1) and (x2, y2) is given by the Euclidean distance formula:
// distance = sqrt(x1^2-x2^2 + y1^2-y2^2)
// for this question it'll be sqrt(x1^2+y1^2) as we are talking about origin
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// vector<pair<int, int>> answer(vector<pair<int, int>> arr, int k)
// {
//     vector<pair<int, int>> result;
//     // min heap
//     priority_queue<pair<float, pair<int, int>>, vector<pair<int, int>>, greater<pair<float, pair<int, int>>>> min;

//     int n = arr.size();
//     int distance;

//     for (int i = 0; i < n; i++)
//     {
//         distance = math.sqrt(arr[i].first * arr[i].first + arr[i].second * arr[i].second);

//         min.push({distance, {arr[i].first, arr[i].second}});

//         if (min.size() > K)
//         {
//             min.pop();
//         }
//     }

//     while (!min.empty())
//     {
//         result.push_back(min.top().second);
//         min.pop();
//     }

//     return result;
// }

// vector<pair<int, int>> answer(vector<pair<int, int>> arr, int k)
// {
//     vector<pair<int, int>> result;
//     // we need max heap
//     // priority_queue<pair<float, pair<int, int>>, vector<pair<int, int>>, greater<pair<float, pair<int, int>>>> min;

//     int n = arr.size();
//     // didn't change variable type after changing it in queue
//     int distance;

//     for (int i = 0; i < n; i++)
//     {
//         // sqrt() not math.
//         distance = math.sqrt(arr[i].first * arr[i].first + arr[i].second * arr[i].second);

//         min.push({distance, {arr[i].first, arr[i].second}});

//         if (min.size() > K)
//         {
//             min.pop();
//         }
//     }
//     // rest logic is good
//     while (!min.empty())
//     {
//         result.push_back(min.top().second);
//         min.pop();
//     }

//     return result;
// }

// gpt reviewed answer

#include <cmath> // for sqrt

using namespace std;

vector<pair<int, int>> answer(vector<pair<int, int>> arr, int k)
{
    vector<pair<int, int>> result;
    // min heap with pair<distance, point>
    priority_queue<pair<float, pair<int, int>>> min;

    int n = arr.size();
    float distance;

    for (int i = 0; i < n; i++)
    {
        distance = sqrt(arr[i].first * arr[i].first + arr[i].second * arr[i].second);

        // Add point to min heap
        min.push({distance, {arr[i].first, arr[i].second}});

        // Keep only the top K closest points
        if (min.size() > k)
        {
            min.pop();
        }
    }

    // Extract the k closest points from the heap
    while (!min.empty())
    {
        result.push_back(min.top().second);
        min.pop();
    }

    return result;
}
