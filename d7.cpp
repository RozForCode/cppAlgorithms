// general format for variable size sliding window problem
/*
while(j<size){calculations}
if(condition<k){j++}
elseif(condition==K){ans<-calculation;j++}
elseif(current>k){
while(current>k){remove calculation for i(currentWindowIndex);i++}
}
*/
// Longest substring with non-repeating characters
// answer
// My initial idea to solve this problem is to use map and pair along with the given string to solve.
// so each unique character would be paired with its index
// and map[c] would take care of the occurences of the specified character
// whenever map[c]++ makes map[c] == 2 we would return use maxLength = max(maxLength,i-currentWindowIndex+1)
// after this is where pair shines - we would get the pair of c from before and set the currentWindowIndex prior to it and continue the loop
// then decrement map[c]
// also remove that pair and create new pair
// return maxLength
#include <iostream>
#include <climits>
#include <string.h>
#include <unordered_map>
#include <utility>
using namespace std;

int intialanswer(string s)
{
    int currentWindowIndex;
    unordered_map<char, int> map;
    pair<char, int> pr;
    int maxLength = INT_MIN;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        map[s[i]]++;
        if (map[s[i]] == 2)
        {
            maxLength = max(maxLength, i - currentWindowIndex + 1);
            //     currentWindowIndex = //use pair to update the window index to the next element from s[i]
            // update pair[s[i]] with i thereby removing the previous second value of s[i]
        }
    }
    return maxLength;
}