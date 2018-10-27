class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        res = []
        
        for nums in range(left, right+1):
            if self.self_dividing(nums):
                res += [nums]
        
        return res


    def self_dividing(self, num):
        
        for d in str(num):
            if '0' == d or num % int(d) > 0:
                return False
            
        return True