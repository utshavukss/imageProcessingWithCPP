# Two Pointers
Two pointers is a technique in array manipulation where the values of any array are accessed from both ends. The problems discussed in this document are derived from **leetcode** and are associated with the use of Two Pointers.
## Valid Palindrome
A palindrome is any set of characters which remains the same after reversing that set. Identification of a palindrome string can be achieved with the help of two pointers.

Given the problem description, we first had to convert given string into lower case. Then, we start the iteration by pointing to first and last positions of the string at the same time. If a non alphanumeric character is encountered, we simply skip the iteration by incrementing the pointer to left or decrementing the pointer to right. The values at first and last are compared. The iteration is repeated until the pointer at left is greater than or equal to the pointer at right. If any pair is not found to be equal, the string cannot be considered as palindrome.
## Two Sums
This problem deals with integer arrays where the positions of any two numbers in the array that add up to a particular target value are returned as an array.

The basic logic is to sort the array in ascending order, point to the first and last values in the array initially, and check the sum of these two numbers. If the sum is greater than the target value, the pointer at right is decremented. Similarly, if the sum is found to be less than target value, the pointer to the left is incremented. The iteration runs until the pointer at left is equal to or greater than pointer at right. If the sum of any pair is equal to target, the indices of the values in that pair are returned as an array.

In the code implementation, however, i chose to use the approach of hash maps since it seemed more optimal solution. In the hash map approach, each element of the input array is associated with another array storing the indices of the respective values via std::map structure. 

Afterwards, we iterate over each element in the array and subtract the element from target. If the difference exists in the array (determined by map.find(key)), we return the positions of the element and the thus determined key as an array.

## Three Sums
It is another problem that can be solved using two pointers. Given an array of numbers, the task is to find all unique triplets within the array that add up to a given target sum.

It can be achieved by fixing an element as target, then performing two sums operaiton on the remaining array. 