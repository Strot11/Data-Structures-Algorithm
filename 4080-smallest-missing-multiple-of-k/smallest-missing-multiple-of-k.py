class Solution(object):
    def missingMultiple(self, nums, k):
        nums.sort()
        smallest = k
        for num in nums:
            if(smallest == num):
                smallest += k
        return smallest
        