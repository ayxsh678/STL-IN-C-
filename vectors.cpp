#include <bits/stdc++.h>
using namespace std;

int main() {

    // ─────────────────────────────────────────
    // 1. BASIC INITIALIZATION
    // ─────────────────────────────────────────

    vector<int> v1;                        // empty vector
    vector<int> v2(5, 0);                  // {0, 0, 0, 0, 0}
    vector<int> v3 = {1, 2, 3, 4, 5};     // initializer list
    vector<int> v4(v3);                    // copy of v3

    // ─────────────────────────────────────────
    // 2. INSERTION
    // ─────────────────────────────────────────

    v1.push_back(10);         // adds 10 at the end — O(1) amortized
    v1.emplace_back(20);      // constructs in-place — slightly faster than push_back

    v1.insert(v1.begin(), 5); // insert 5 at beginning — O(n), avoid for large vectors
    v1.insert(v1.begin() + 1, 3, 7); // insert three 7s at index 1

    // ─────────────────────────────────────────
    // 3. ACCESS
# STL in C++ 🚀

A structured reference repo covering the C++ Standard Template Library — with clean code examples and in-line explanations.

> Level: Intermediate → Advanced
> Author: Ayush Verma | [@ayxsh678](https://github.com/ayxsh678)

---

## 📁 Structure

```
STL-cpp/
├── vectors/
│   └── vectors.cpp          # vector tricks, 2D vectors, iterators
├── maps_sets/
│   └── maps_sets.cpp        # map, unordered_map, set, multiset
├── stacks_queues/
│   └── stacks_queues.cpp    # stack, queue, priority_queue, deque
├── strings/
│   └── strings.cpp          # string methods, parsing, manipulation
├── iterators_ranges/
│   └── iterators_ranges.cpp # iterators, begin/end, ranges, views
└── README.md
```

---

## 📚 Topics Covered

| Topic | File | Concepts |
|---|---|---|
| Vectors & Arrays | `vectors/vectors.cpp` | push_back, emplace_back, resize, 2D vectors, sorting |
| Maps & Sets | `maps_sets/maps_sets.cpp` | map, unordered_map, set, multiset, lower_bound |
| Stacks & Queues | `stacks_queues/stacks_queues.cpp` | stack, queue, priority_queue (min/max heap), deque |
| Strings | `strings/strings.cpp` | substr, find, replace, stringstream, parsing |
| Iterators & Ranges | `iterators_ranges/iterators_ranges.cpp` | iterators, advance, distance, C++20 ranges/views |

---

## ⚙️ How to Run

```bash
# Compile any file
g++ -std=c++20 -o out vectors/vectors.cpp && ./out
```

---

## 🗓️ Commit Log
Daily updates — one concept or example added per day.
    // ─────────────────────────────────────────

    cout << v3[0];         // no bounds check — fast
    cout << v3.at(0);      // bounds checked — throws std::out_of_range if invalid
    cout << v3.front();    // first element
    cout << v3.back();     // last element
    cout << *v3.data();    // raw pointer to underlying array

    // ─────────────────────────────────────────
    // 4. SIZE vs CAPACITY
    // ─────────────────────────────────────────

    // size()     = number of elements currently in vector
    // capacity() = allocated memory (always >= size)
    // When size == capacity, vector doubles its capacity on next push_back

    vector<int> v;
    v.reserve(100);   // pre-allocate for 100 elements — avoids repeated reallocations
    v.resize(10);     // sets size to 10, fills new slots with 0
    v.shrink_to_fit();// releases unused capacity back to OS

    cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << "\n";

    // ─────────────────────────────────────────
    // 5. DELETION
    // ─────────────────────────────────────────

    v3.pop_back();                    // removes last element — O(1)
    v3.erase(v3.begin());            // removes first element — O(n)
    v3.erase(v3.begin(), v3.begin() + 2); // removes range [0, 2)
    v3.clear();                       // removes all elements, size = 0

    // Erase-Remove idiom — remove all occurrences of a value efficiently
    vector<int> nums = {1, 3, 3, 5, 3, 7};
    nums.erase(remove(nums.begin(), nums.end(), 3), nums.end());
    // nums = {1, 5, 7}

    // ─────────────────────────────────────────
    // 6. SORTING & SEARCHING
    // ─────────────────────────────────────────

    vector<int> arr = {5, 2, 8, 1, 9};

    sort(arr.begin(), arr.end());                          // ascending
    sort(arr.begin(), arr.end(), greater<int>());          // descending
    sort(arr.begin(), arr.end(), [](int a, int b){         // custom comparator
        return a % 3 < b % 3;
    });

    // Binary search (vector must be sorted first!)
    sort(arr.begin(), arr.end());
    bool found = binary_search(arr.begin(), arr.end(), 5); // true/false

    auto lb = lower_bound(arr.begin(), arr.end(), 5); // first element >= 5
    auto ub = upper_bound(arr.begin(), arr.end(), 5); // first element >  5

    // ─────────────────────────────────────────
    // 7. 2D VECTORS
    // ─────────────────────────────────────────

    int rows = 3, cols = 4;
    vector<vector<int>> grid(rows, vector<int>(cols, 0)); // 3x4 grid of zeros

    grid[1][2] = 42;

    // Traverse 2D vector
    for (auto& row : grid) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    // ─────────────────────────────────────────
    // 8. USEFUL TRICKS
    // ─────────────────────────────────────────

    vector<int> a = {3, 1, 4, 1, 5};

    // max and min element
    cout << *max_element(a.begin(), a.end()); // 5
    cout << *min_element(a.begin(), a.end()); // 1

    // sum of all elements
    int total = accumulate(a.begin(), a.end(), 0); // 14

    // reverse a vector
    reverse(a.begin(), a.end());

    // count occurrences of a value
    int cnt = count(a.begin(), a.end(), 1); // 2

    // check if any element satisfies a condition
    bool anyEven = any_of(a.begin(), a.end(), [](int x){ return x % 2 == 0; });

    // remove duplicates (must be sorted first)
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    return 0;
}
