# Back Tracking

Back Tracking algorithms usually work on questions that look for **all** combinations that meet set constraints.

## Three Keys

The best way to visualize a back tracking problem is by defining the following:

- Choice: *What are the possible choices I can make that will define a new outcome*
- Constraint: *What are my limitations to my choices that define how I make them*
- Goal: *What is the end result that I am looking to validate the set choices I made*

Defining these allows us to build a blueprint of how we want to approach our back tracking algorithm. 

*Source: https://www.youtube.com/watch?v=Zq4upTEaQyM*

In questions where it involves all possibilities of a set constraint, we try to say *"Lets go down this road and see our possibility, then back track and try a new set of choices."* At the end, we then store the result to a List which builds our solution from the different sequence of choices we made.

Good Leetcode Problems to try out with this are the following:

Subsets: https://leetcode.com/problems/subsets/

Subsets II: https://leetcode.com/problems/subsets-ii/
 
Permutations: https://leetcode.com/problems/permutations/

Permutations II: https://leetcode.com/problems/permutations-ii/
 
Combination Sum - https://leetcode.com/problems/combination-sum/
 
Combination Sum II - https://leetcode.com/problems/combination-sum-ii/
 
Palindrome Partitioning - https://leetcode.com/problems/palindrome-partitioning/

Generally the algorithms follow a recursive pattern defined by the following. Most problems will be comporable to this, while there will be key differences such as how the abstraction of choices becomes a data structure.

```
backtrack(List<List<X>> output, List<X> current, List<X> choices) {
    if(Goal is Met) {
        output.add(clone of current);
        return; 
    }
    //otherwise
    for(choices given constraints) {
        
        choice = choices.remove(); //So you don't loop the same choice 
        current.add(choice); //Try this choice
        backtrack(output, current, choices); //Continue down this sequence
        current.remove(current.size()-1); //Back track that decision
        choices.add(choice); //Put the choice back for later

    }

}
```

This is reflected in a handful of examples in this post.

*Source: https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)*