class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
       # //set banunga
       st=set()
       for x in nums:
        if(x<k): return -1
        elif(x>k):
            st.add(x)
       return len(st)
