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

// Stack NGR && NRL revision
// ngr
vector<int> ngrRevision(vector<int> arr)
{
    vector<int> result;
    int n = arr.size();
    stack<int> st;

    for (int i = n - 1; i <= 0; i++)
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

vector<int> nglRevision(vector<int> arr)
{
    vector<int> result;
    int n = arr.size();
    stack<int> st;
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

// STOCK SPAN PROBLEM - nearest greater to left
vector<int> stockSpan(vector<int> arr)
{
    int n = arr.size();
    vector<int> result;
    stack<pair<int, int>> st;
    vector<int> span;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first < arr[i])
        {
            st.pop();
        }
        result.push_back(st.empty() ? -1 : st.top().second);
        st.push(make_pair(arr[i], i));
    }
    for (int i = 0; i < n; i++)
    {
        result[i] = result[i] - i;
    }
    return result;
}
// stock span revision
vector<int> stockRevision(vector<int> arr)
{
    int n = arr.size();
    stack<pair<int, int>> st;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first < arr[i])
        {
            st.pop();
        }
        result.push_back(st.empty() ? -1 : st.top().second);
        st.push(make_pair(arr[i], i));
    }
    for (int i = 0; i < n; i++)
    {
        result[i] = i - result[i];
    }
}
// do smallest nearest questions for revision