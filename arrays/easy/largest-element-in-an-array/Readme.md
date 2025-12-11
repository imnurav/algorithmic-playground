🧩 Largest Element in an Array — Easy Solution
📘 Problem Statement

Given an array of integers, find and print the largest element in the array.

🔢 Input Format

First line: Integer n → size of array

Next line: n space-separated integers

📤 Output Format

Print the message:
"Largest Element In Array is X"
where X is the maximum value.

📝 Example
Input
5
1 3 9 2 7

Output
Largest Element In Array is 9

🧠 Approach

Read n

Read array of size n

Initialize largest = arr[0]

Traverse array:

If arr[i] > largest, update largest

Print the result

⏱️ Complexity
Type	Complexity
Time Complexity	O(n) — single loop through array
Space Complexity	O(n) — storing array (auxiliary space O(1))