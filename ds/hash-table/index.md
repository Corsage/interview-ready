# Hash Table

A hash table is a data structure that maps keys to values for **highly efficient lookup**. There are two common implementations of a hash table. The first uses an array of linked lists, while the second uses a binary search tree.

#### Check out these [Leetcode Questions](https://leetcode.com/tag/hash-table/)!

#### Average Case

| Search | Insert | Delete |
|--------|--------|--------|
| O(1)   | O(1)   | O(1)   |

#### Worst Case

| Search | Insert | Delete |
|--------|--------|--------|
| O(n)   | O(n)   | O(n)   |

## Introduction

The primary idea around a hash table is to design a *hash function* $h$ such that it maps every possible item $x$ to a small integer $h(x)$. Then we store $x$ in an array at index $h(x)$; the array itself is the hash table.

In order to create a **good** hash function, we must consider the number of *expected* items that it will hold. For example, if we expect to store $n$ items where each item is an element of a **fixed** set $U$. Then our hash table will have a **maximum** size of $U$ and is usually depicted as an array $T[1 .. m]$ where $m$ is the *table size*. A hash function in this scenario will be any function of the form:

$$
h : U \rightarrow \{0, 1, ..., m - 1\}
$$

In this case, we map every possible item in $U$ to a *unique* slot in the hash table. We say that an item $x$ **hashes** to the slot $T[h(x)]$. Through the understanding of our maximum item limit, we are able to **avoid** collisions. In other words, we can use the item itself as the index into the table. The resulting data structure is called a **direct access table** (also known as an array). This is the most fundamental version of a hash table.

The downside of this approach is that it requires **large** amounts of space, thus it is not suitable in most real-world scenarios. 

## Why Hashing?

In most scenarios, given the maximum size of $U$, our table will rarely actually reach that size. Due to this, we purpose the idea of a smaller table. However, smaller tables open up the possibility of **collisions**. Through the *pigeonhole principle*, it is easy to see why this occurs. We say that two items $x$ and $y$ *collide* if their hash values are equal: $h(x) = h(y)$. Collisions can be reduced with a selection of a *good hash function*, but, there is no 100% way to avoid them. There are many *different* ways to handle collisions. Below we go over a select few.

### Collision Resolution Techniques

1) **Separate Chaining** - collisions can be resolved by creating a list of keys that map to the same value.
   + This method uses an array of linked lists, thus each slot is actually a linked list.
   + Whenever an item is mapped onto the table, it is simply added to the end of the linked list at the slot.
   + However, a good hash function is needed or else it is possible to have $O(n)$ search and updates.

2) **Linear Probing** - With a fixed table of size $n$, we find the next available slot by going down the table.
   + On **inserts** we compute $h(x) \text{ mod } n$. If it is full, we find the next *sequential* slot via $h(x) + 1$, $h(x) + 2$, ...
   + On **searches** we compute $h(x) \text{ mod } n$. However, if the slot doesn't match, we go down the table.
   + **Note**: This introduces another problem known as **clustering**.

3) **Quadratic Probing** - Similar to linear probing, but examines only certain slots away from the original.
   + This collision policy defines multiple hash functions $h_0(x)$, $h_1(x)$, $h_2(x)$, ...
      + Where $h_i(k) = h(k) + i^2 \text{ mod } n$.
   + This method requires that the table be **less than half full** or else it may not find a vacant slot.

## Simple Implementation

The **HashNode** class represents each *bucket node* in the table. It has a `key()` and `value()` accessor function for each corresponding pair elements.

```c++
template <typename K, typename V>
class HashNode
{
public:
    HashNode(const K &key, const V &value) : key(key), value(value) { }
    
    K getKey() const
    {
        return key;
    }
    
    V getValue() const
    {
        return value;
    }
    
private:
    K key;
    V value;
};
```

Now we implement the actual Hash Map. In this example we use a simple hash function, $h(x) = x \text{ mod } n$ where $n$ is the table size.

```c++
template <typename K, typename V>
class HashMap
{
public:
    HashMap()
    {
        table = new HashNode<K, V> *[TABLE_SIZE]();
    }
    
    ~HashMap()
    {
        // Destroy all the buckets one-by-one.
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            HashNode<K, V> *entry = table[i];
            if (entry != NULL)
            {
                delete entry;
            }
            table[i] = NULL;
        }
        
        // Destroy the hash table.
        delete [] table;
    }
    
    // The hash function.
    unsigned long hash(const K &key)
    {
        return static_cast<unsigned long>(key) % TABLE_SIZE;
    }
    
    void insert(const K &key, const V &value)
    {
        unsigned long hashValue = hash(key);
        HashNode<K, V> *entry = table[hashValue];
        
        if (entry == NULL)
        {
            // No previous entry found, insert it in.
            entry = new HashNode<K, V>(key, value);
            table[hashValue] = entry;
        }
        else
        {
            throw "Hash collision detected!";
        }
    }
    
    void remove(const K &key)
    {
        unsigned long hashValue = hash(key);
        HashNode<K, V> *entry = table[hashValue];
        
        if (entry == NULL)
        {
            throw "Key not found!";
        }
        else
        {
            delete entry;
            table[hashValue] = NULL;
        }
    }
    
    HashNode<K, V>* find(const K &key)
    {
        unsigned long hashValue = hash(key);
        HashNode<K, V> *entry = table[hashValue];
        
        if (entry == NULL)
        {
            throw "Key not found!";
        }
        else
        {
            return entry;
        }
    }
    
private:
    HashNode<K, V> **table;
    const int TABLE_SIZE = 200;
};
```

#### Example Program

```c++
#include <iostream>

using namespace std;

int main() {
    HashMap<int, string> map;
    
    map.insert(1, "Value 1");
    map.insert(2, "Value 2");
    map.insert(3, "Value 3");
    
    auto node1 = map.find(1);
    auto node2 = map.find(2);
    auto node3 = map.find(3);
    
    cout << "Value at key " << node1->getKey() << " is " << node1->getValue() << endl;
    cout << "Value at key " << node2->getKey() << " is " << node2->getValue() << endl;
    cout << "Value at key " << node3->getKey() << " is " << node3->getValue() << endl;
    
    map.remove(2);
    
    try
    {
        node2 = map.find(2);
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
    
    return 0;
}
```

The above program gives the following output:
```
Value at key 1 is Value 1
Value at key 2 is Value 2
Value at key 3 is Value 3
Key not found!
```

## References

- [University of Illinois CS](https://jeffe.cs.illinois.edu/teaching/algorithms/notes/05-hashing.pdf)
- [Carnegie Mellon University CS](http://www.cs.cmu.edu/~ab/15-121N11/lectures/lecture16.pdf)
- [Programming Guide](https://programming.guide/hash-tables-complexity.html)
- [cooervo](https://github.com/cooervo/Algorithms-DataStructures-BigONotation)
- [aozturk](https://aozturk.medium.com/simple-hash-map-hash-table-implementation-in-c-931965904250)
- [CTCI](https://www.crackingthecodinginterview.com/)
- [TutorialsPoint](https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables)