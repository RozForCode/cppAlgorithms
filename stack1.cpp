// Intro to stack and identification
/*

all question can be solved with brute force O(n^2)
DSA rounds need you to identify which D.S or algorithm  to use
to solve the question in O(best)

So identification is the most important thing

Identification
usually on array or heap (heap usaully related to sorting)
if brute force solution is of O(n^2) and the inner loop has following patterns:
-> j= 0 to i j++
-> j= i to 0 j--
-> j=i to n j++
-> j=n to i j--
then it's likely it can be solved with stack


after identifying solve the variation
*/
// q1 - NGR | Nearest Greater to right | Next Largest Element
