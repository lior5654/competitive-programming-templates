# Competitive Programming Templates

> Made By: ~lior5654 (FiveSixFiveFour)

## What is "Competitive Programming"?

---
Competitive Programming is a mind sport. Participants compete against each other in order to solve hard algorithmic problems efficiently.

Solving a good contest problems requires strong problem solving & research skills, creativity and deep knowledge of advanced algorithms & data structures, such as Lee-Chao Tree, FFT, Forture's Algorithm, Bellman-Ford, KMP, and much more.

As contests are limited by time & one's solution is only judged by it's ability to pass certain testcases within the given time & memory usage constraints of the problem, readability & design are not the focus of a competitive programming contest, but rather an efficient and short-to-write solution that solves the problem.

## What is this repository for?

---
As stated above, having short & efficient implementations is sometimes key for time managment during a contest. This repository contains templates of a vast variaty of algorithms & data strucutres used in contests implmented with the focus of reducing LoC (Lines of Code) & efficiency. If you wish to use some algorithm implemented in this repository for a project, consider redesigning the code to be slightly more readable and maintainable for the long run.

## Features

---
> Note: all algorithms & data structures are implemented in C++. No, I will not extend the repository to other languages.

* Data Structures (& Offline Query Algorithms)
  * Fenwick Tree - Done
  * Segment Tree - Done
    * Regular - Done
    * Lazy - Done
    * Persistent - Done
  * Treap - TODO
  * MO's Algorithm (Square Root Decomposition) - TODO
  * RMQ (Range Max/Min Query)
    * O(nlogn) pre-processing, O(1) query - TODO
    * O(n) pre-processing, O(1) query - TODO
  * DSU (Disjoint Set Union|Union Find) - Done

* Trees
  * DFS (Depth-First Traversal) - TODO
  * BFS (Breath-First Traversal) - TODO
  * Euler Track - TODO
  * LCA (Least Common Ancenstor) - TODO
    * O(nlogn) pre-processing, O(logn) query - TODO
    * O(nlogn) pre-processing, O(1) query - TODO
    * O(n) pre-processing, O(1) query - TODO
  * HLD (Heavy-Light Decomposition) - TODO
  * CD (Centroid Decomposition) - TODO

* Graphs
  * DFS (Depth-First Traversal) - TODO
  * BFS (Breath-First Traversal) - TODO
  * Shortest-Path Algorithms - TODO
    * Dijkstra's Algorithm - TODO
    * Bellman-Ford's Algorithm - TODO
    * Floyd-Warshal's Algorithm - TODO
  * MST (Min/Max Spanning Tree) - TODO
    * Kruskal's Algorithm - TODO
    * Prim's Algorithm - NO, I hate Prim
  * SCC (Strongly Connected Components) - TODO
    * Kosaraju's Algorithm - TODO
  * Find Bridges - Tarjan's Algorithm - TODO
  * Find Articulation Points - Done
  * MM (Maximum Bipartite Matching) - Done
  * Dynamic Connectivity - TODO
  * Minimum Vertex Cover - TODO
  * 2-SAT - TODO
  * Flows - Learn & TODO

* Dynamic Programming Optimizations:
  * D&C (Divide & Conquer) - TODO
  * Knuth - TODO
  * 1D-1D - TODO
  * Matrix Exponentiation - TODO

* String Algorithms
  * Hashing - Done
  * Z-string - Done
  * KMP (Knuth-Pratt-Morris) - TODO
  * Trie - TODO
  * Aho Corasic - TODO
  * Suffix Things - Learn & TODO
  * Manacher's Algorithm (All Sub-palindromes in O(n)) - TODO

* Geometry:
  * Sweep-Line - TODO
  * Point Class - Done
  * Segment Intersection - Done
  * Convex Hull in O(nlogn) - Done
  * Geometry Related Data Structures & Tricks:
    * Lee-Chao Tree - TODO
    * Convex-Hull Trick - TODO

* Algebra & Number Theory
  * Combinatorics (Choose, Permute etc..) - Done
  * Binary Exponentiation - Done
  * GCD&LCM - Greatest Common Divisor & Least Common Multiple - Done
  * Sieve of Eratosthenes - Done
  * Factoting
    * O(max*log(max)) - pre processing, O(sum of prime powers in prime factorization) == O(log(max)) query - Done
    * O(sqrt(num)) -  TODO
  * Extended GCD - Done
  * Chinese Remainder Theorem - TODO

* Game Theory
  * NIM - TODO
  * Sprague-Grundy Theorem - TODO
  * read https://cp-algorithms.com/game_theory/games_on_graphs.html then TODO

* Miscalleneous
  * Ternary Search - TODO
  * LIS (Longest Increasing Subsequence) in O(nlogn) - TODO
  * FFT (Fast Forier Transform) For O(nlogn) Polynomial Multiplication - TODO
