#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * Q 1.4
 * Palindrome Permutation: Given a string,
 * write a function to check if it is a
 * permutation of a palindrome. A palindrome
 * is a word or phrase that is the same
 * forwards and backwards. A permutation is a
 * rearrangement of letters. The palindrome
 * does not need to be limited to just
 * dictionary words.
 */

/**
 * Recall the definition of palindrome:
 * A word, phrase, or sequence that
 * reads the same backward as forward.
 * 
 * This solution has two parts. Firstly,
 * we need to identify if the word is a
 * palindrome. After, we check if it is
 * a permutation of one.
 * 
 * The benefit of an unordered_set is that
 * it averages O(1) runtime and O(n) worst case.
 * 
 * Unfamiliar with unordered_map? Check out this link:
 * https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/
 */

bool palindrome_permutation(string str)
{
    unordered_set<char> set;

    // Palindrome requires pairs of characters.
    // Order does not matter due to permutation.
    // Since we are not limited to dictionary words,
    // spaces do not matter at all.
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }

        // O(1) operation.
        char c = tolower(str[i]);

        if (set.find(c) == set.end())
        {
            // O(1) insertions.
            set.insert(c);
        }
        else
        {
            // O(1) deletions.
            set.erase(c);
        }
    }

    return set.size() <= 1;
}

int main()
{
    string s1 = "Tact Coa";

    cout << palindrome_permutation(s1);
    return 0;
}