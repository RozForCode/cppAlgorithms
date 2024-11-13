// Identificaion - 1. Kth, 2. Largest or smallest element    1 and 2 together
// k will be the size of heap - top of the heap will have the answer after calc
// 2 types - min heap, max heap
// k+smallest - max heap
// k+largest  - min heap

// pop top push

// all heap questions are sorting questions - nlogk
// heap make sorting complexity from nlogn (array) to nlogk

// max heap cpp - priority_queue<int> max; -- largest on top, which is the first one to be accessed
// min heap cpp - priority_queue<int,vector<int>, greater<int>> max; -- smallest on top

// if the heap requires there to be pair in each insertion than replace
// all int occurences with pair<int,int>
// if in some case there is need of inserting a int with a pair you'll need pair<int,pair<int,int>>
// in such case it is better to define type
// type def pair<int,pair<int,int>> ppi;// this code line comes after include statements

// q1 - kth smallest element
#include <iostream>
#include <queue>
using namespace std;

// int answer1(int[] arr, int n, int k)
// {
//     // int n = arr.size(); C-style arrays don't have inbuilt function to get the size of the array
// }
int answer1(int arr[], int n, int k)
{
    priority_queue<int> max;

    for (int i = 0; i < n; i++)
    {
        max.push(arr[i]);
        if (max.size() > k)
        {
            max.pop();
        }
    }
    return max.top();
}