/* So I'm proficient in solving basic medium leetcodes problems
 however there are 3 algos that I plan on mastering
 1. sliding window
 2.DFS
 3.BFS

How I'll do them
1. Understand how and why a algo works
2. see solved solutions with that algo
3. solve problems that are solved using that algo
*/

// SLIDING WINDOW
// to better understand it
// solve something using brute force
// so sliding window works on the concept of optimizing by identifying repeative work and then avoiding that
// eg- we have a problem that makes use do arr[i]+arr[i+2]+arr[i+2] in a loop... lets say the window is quite big 1+2+3+4..
// next loop 2+3+4+5.... we see that 2+..4 is being repeated so we try to avoid that. brute force way of avoid that would be
// first iterations
// int later =arr[i+1]+arr[i+2]
// int result = arr[i]+later;
// int result = later+arr[i+2];
// later -= arr[i-1];
// later +=arr[i+2];
// arr.push(result);
// so the origin of sliding window is to avoid repeative work by sliding the window like keeping 2+3+4... and removing/shifting/adding/subtracting only in the front and the end
// this makes our code efficient

/* now lets focus on how to identify what problem is sliding window and what are it's types
 now after learning sliding window- ofcourse we'll be able to solve such  problems but understanding it will
 also help us in dealing with probs that are not sliding window
 1. We'll have a array or similar DS(string etc) where we'll apply our window
 2. Question will make use work on subarrays and not something that is discontinous + added to it they might ask largest, smallest or something similar
 since it's window we'll also have a constant K which will be our window size
 sometimes we'll have to get the window size but above terms will be mentioned in the question
 now if we don't have window size how will we deal with the prob. This leads us to the two types of sliding window
1. Fixed size window - eg. sum
2. Variable size window - ask about window size
- largest or smallest window based on condition
eg - we are given sum and we need to get subarrys for that sum and then get the largest or smallest from the result subarrays

*/