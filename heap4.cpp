// q5- Top K frequent numbers
// initial thoughts- sounds like we have the find the largest frequency so min heap(we get rid of small ones) by storing pair
// priority_queue<pair<int,pair<int,int>,vector<int>,greater<int>

// from video - we have to use hash
// hashing -  hashing refers to the process of converting input data (like a string or number) into a fixed-size value, typically called a hash code or hash value. This is done using a hash function.4
// first I'll study about hash function, hash table, collision, and applucation of hashing
// then move onto the q5

// hash function - takes input data(key) and returns fixed sized integer called hash value
// eg of hash function
/*
int hash(int key, int table_size) {
    return key % table_size;
}
int hash(int key, int table_size) {
    float A = 0.618033; // A fractional constant (could be any constant between 0 and 1)
    return floor(table_size * fmod(key * A, 1));
}


int hash(string s, int table_size) {
    int hash_value = 0;
    int p = 31;  // Prime number
    int p_pow = 1;

    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % table_size;
        p_pow = (p_pow * p) % table_size;
    }

    return hash_value;
}

explanation of this code
This hash function is designed to compute a polynomial rolling hash for a string s
(c - 'a' + 1):

This converts the character c (which is assumed to be a lowercase English letter) to a numerical value between 1 and 26.
p_pow:

This variable represents powers of a prime number p. The prime p (31 in this case) is chosen because it spreads out the character
values effectively, giving each position in the string increasing significance as you move from left to right. Initially,
 p_pow is 1 (i.e., 31^0), but it gets multiplied by 31 in each iteration (p_pow * p) to generate powers of 31 (p_pow becomes 31^1, 31^2, etc.).
ach character in the string contributes to the overall hash based on its position and value.


Even with a good hash function, collisions can still happen. Here are the common strategies to deal with collisions:

Chaining-In this method, each slot in the hash table points to a linked list (or another structure). When a collision occurs, the item is simply appended to the linked list at that slot.

Open Addressing-Instead of storing multiple elements in a single slot, open addressing finds another empty slot using various probing methods:
Linear Probing: Check the next available slot (e.g., hash_value + 1, hash_value + 2, etc.).
Quadratic Probing: Probe using a quadratic function (e.g., hash_value + 1^2, hash_value + 2^2, etc.).
Double Hashing: Use a second hash function to determine the next slot to check.


common hash functions in use - division method (modulo) -{clustering issue if table_size is not prime},
                                Multiplcation,cryptographic hash function, hash functions for strings -{combine char values using various schemees}

Application of hash functions - 1.cpp - unordered_map, python-dict are used for constant-time insertion and lookups
                                2.Load balancing - hash functions are used in distributed systems

Designing custom hash function - 1.Take all aspects of the key into accound
                                    2. Spread values evenly over the hash table
                                    3. Avoid clustering


Q-how is the calculated value used and in which scenarioes is it useful and and which type of dsa problems can be made efficient using hash
-Hashing plays a crucial role in optimizing various data structures and algorithms, enabling faster access, searching, and manipulation.
Hash tables provide constant-time average-case access for insertion, deletion, and lookup operations, making them faster than other data structures like arrays or linked lists, which often have linear time complexity for these operations.
Once the hash value is calculated, it's typically used to map a given input (key) to a specific index in a hash table or similar data structure.


** - Store ->The key-value pair or object can be stored at the location indicated by the hash value (index).
** - Retrieve -> hash value is recalculated hence no time taken in searcb

Hashing is often used in caching algorithms to store previously computed results and retrieve them in constant time, avoiding redundant calculations.

DSA probs made efficient using hashing
Frequency counting/ word counting
Finding duplicates
Two sum problem

// 0, no negatives
Longest Subarray with a Given Sum:
int* answer(int arr[],int n,int k){
int currentWindowIndex = 0;
int sum;
int maxLenght = 0;

for(int i=0;i<n;i++){
    sum+= arr[i];
    if(sum == k){
        maxLength = (maxLength, i-currentWindowIndex+1);
        sum -= arr[currentWindowIndex];
currentWindowIndex++;
}
while(sum>k){
sum -= arr[currentWindowIndex];
currentWindowIndex++;
}
}
return maxLength;
}


// hash  --- complete this tomorrow
int answer(int arr[],int n,int k){
int start;
int sum;
int maxLenght = 0;
unordered_map<int,int> hashMap;
int required_num;




for(int i=0;i<n;i++){
    sum += arr[i];
    required_num = sum - target;

}
}

actual answer gpt - using sliding window and hash map

*/
