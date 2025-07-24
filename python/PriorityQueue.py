# https://neetcode.io/problems/kth-largest-element-in-an-array?list=neetcode150
# Code to find kth largest element in an unsorted array. 
# PriorityQueue by default is a min heap. 
# To make maxheap, insert (-key, value)
import queue
def findKthLargest(nums: List[int], k: int) -> int:
    pq = queue.PriorityQueue(maxsize = len(nums))
    for n in nums: 
        pq.put((-n, n))
    sol = list()
    for i in range(0, k):
        sol.append(pq.get()[1])
    return min(sol)
