class Solution:
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        groups = {}
        
        for r,row in enumerate(matrix):
            for c,val in enumerate(row):
                groups.setdefault(r-c,val)
                if val != groups[r-c]:
                    return False
        
        return True