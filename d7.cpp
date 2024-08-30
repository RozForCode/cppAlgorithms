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
// return maxLength
