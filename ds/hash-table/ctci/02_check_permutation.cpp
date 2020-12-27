#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Q 1.2
 * Check Permutation: Given two strings, write a
 * method to decide if one is a permutation of the
 * other.
 */

/**
 * Recall the definition of permutation:
 * Consider a set s1 and s2, s2 is a
 * permutation of s1 iff s2 contains
 * the same elements but the order
 * does not matter.
 * 
 * This solution uses a hash table.
 * We just need to match the counts of
 * each character between s1 and s2.
 * 
 * The benefit of an unordered_map is that
 * it averages O(1) runtime.
 * 
 * Unfamiliar with unordered_map? Check out this link:
 * https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
 */

/** Time complexity: O(n + m) where n and m is the length of the first and second input string respectively. */
bool check_permutation(string s1, string s2)
{
    // A permutation requires both s1 and s2 to be the same length.
    // O(1) comparison.
    if (s1.length() != s2.length())
    {
        return false;
    }

    unordered_map<char, int> m1, m2;

    for (int i = 0; i < s1.length(); i++)
    {
        // O(1) search.
        if (m1.find(s1[i]) == m1.end())
        {
            m1[s1[i]] = 1;
        }
        else
        {
            m1[s1[i]]++;
        }
    }

    for (int i = 0; i < s2.length(); i++)
    {
        // O(1) search.
        if (m2.find(s2[i]) == m2.end())
        {
            m2[s2[i]] = 1;
        }
        else
        {
            m2[s2[i]]++;
        }
    }

    // Reference: https://en.cppreference.com/w/cpp/container/unordered_map/operator_cmp
    // This operation is average O(n) runtime and O(n^2) worst case.
    return m1 == m2;
}

int main()
{
    // Test cases.
    string s1 = "abcde";
    string s2 = "edcba";
    string s3 = "abcdef";

    cout << s1 << " vs. " << s2 << " check permutation? " << check_permutation(s1, s2) << endl;
    cout << s1 << " vs. " << s3 << " check permutation? " << check_permutation(s1, s3) << endl;
    return 0;
}