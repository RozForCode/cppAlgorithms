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

how is the calculated value used and in which scenarioes is it useful and and which type of dsa problems can be made efficient using hash


*/
