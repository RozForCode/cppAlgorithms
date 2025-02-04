// Connect Ropes to Minimize the Cost
/*
You are given multiple ropes with different lengths. Your task is to connect all the ropes into a single rope.
Each time you connect two ropes, the cost of connecting them is equal to the sum of their lengths.
You need to find the minimum cost required to connect all the ropes into one.

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int answer(vector<int> arr)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> min;

    for (int i = 0; i < n; i++)
    {
        min.push(arr[i]);
    }

    int result;
    int num1;
    int num2;
    while (!min.empty())
    {
        if (min.size() == 1)
        {
            result = min.top();
            min.pop();
        }
        num1 = min.top();
        min.pop();
        num2 = min.top();
        min.pop();
        min.push(num1 + num2);
    }
    return result;
}

// gpt reviewed
// result can be handled differently and more efficiently, although I think it is correct this way as well
int reviewed(vector<int> arr)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> min;

    for (int i = 0; i < n; i++)
    {
        min.push(arr[i]);
    }

    int result = 0;
    int num1;
    int num2;
    while (!min.empty())
    {

        num1 = min.top();
        min.pop();
        num2 = min.top();
        min.pop();
        result += (num1 + num2);
        // is it that we need to add to result whenever the event of connecting ropes occurs?
        //  ChatGPT
        //  Yes, exactly! You need to add to the result whenever the event of connecting ropes occurs because that event incurs a cost.
        min.push(num1 + num2);
    }
    return result;
}
// done