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
