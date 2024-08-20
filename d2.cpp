// Sliding window problems
// aim is to do 5 fixed size prob and 5 variable
// Q1- Maximum sum subarray of size K

// identification- array/string type, size, subarray/substring/etc

// window size always = endofwindow(j)-startOfWindow(i)+1

// start with i=0,j=0 and check
//  j-i+1 < K -> j++
//  j-i+1 > K -> i++
//  j-i+1 = K -> maintian and calc code and j++,i++