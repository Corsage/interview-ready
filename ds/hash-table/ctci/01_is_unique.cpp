#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * Q 1.1
 * Is Unique: Implement an algorithm to determine if a string
 * has all unique characters.
 */

/**
 * This solution uses a hash table as a set.
 * Since we just need to know if the characters
 * are unique, order does NOT matter. Hence,
 * we are able to use an unordered_set.
 * 
 * The benefit of an unordered_set is that
 * it averages O(1) runtime and O(n) worst case.
 * 
 * Unfamiliar with unordered_set? Check out this link:
 * https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/
 */

/** Time complexity: O(n) where n is the length of the input string. */
bool isUnique(string str)
{
    unordered_set<char> set;

    for (int i = 0; i < str.length(); i++)
    {
        // O(1) search.
        if (set.find(str[i]) != set.end())
        {
            return false;
        }

        // O(1) insertions.
        set.insert(str[i]);
    }

    return true;
}

int main()
{
    // Test cases.
    string s1 = "abcde";
    string s2 = "abcda";
    string s3 = "";

    cout << s1 << " is unique? " << isUnique(s1) << endl;
    cout << s2 << " is unique? " << isUnique(s2) << endl;
    cout << s3 << " is unique? " << isUnique(s3) << endl;
    return 0;
}