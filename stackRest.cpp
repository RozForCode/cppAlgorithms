// Nearest Greater to left
/* brute has inner loop -> j= 0 to i j++
-> j= i-1 to 0 j--
-> j=i-1 to n j++
-> j=n to i j--
so likely stack
*/
// str = ["","one","two"...]
// for()
// map {0:str[0]}
// use this map  for
#include <stack>
#include <vector>
using namespace std;
// Nearest Greater to left
vector<int> ngl(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        result.push_back(st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    return result;
}
// Nearest Greater to right
// opposite of ngr
vector<int> ngr(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> result;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        result.push_back(st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    return result;
}

// Nearest Smallest to left
vector<int> nsl(vector<int> arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        result.push_back(!st.empty() ? -1 : st.top());
        st.push(arr[i]);
    }
    return result;
}

// STOCK SPAN PROBLEM
