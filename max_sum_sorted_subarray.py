'''
Given an array of N positive integers. Write a program to find the maximum sum
subsequence
of the given array such that the integers in the subsequence are sorted in
increasing order.
For example:
    If input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1
                                                                      + 2 + 3 + 100)
    If the input array is {3, 4, 5, 10}, then output should be 22 (3
                                                                   + 4 + 5 + 10)
    If the input array is {10, 5, 4, 3}, then output should be 10.
'''

def max_sub_sum(A):
    max_sums = [i for i in A]
    for i in range(len(A)):
        for j in range(i):
            current_sum = max_sums[j] + A[i]
            if A[j] < A[i] and max_sums[i] < current_sum:
                max_sums[i] = current_sum

    return max(max_sums)


if __name__ == "__main__":
    test_cases = [([1, 101, 2, 3, 100, 4, 5], 106), ([3, 4, 5, 10], 22), ([10, 5, 4,
                                                                   3], 10)]
    for tc, er in test_cases:
        res = max_sub_sum(tc)
        try:
            assert  res == er
            print(f"[PASSED] {res} == {er}")
        except AssertionError:
            print(f"[FAILED] {res} != {er}")
