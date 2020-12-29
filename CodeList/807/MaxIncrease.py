# min-max problem
# value should be min(max(top-bottom), max(left-right))

import numpy as np

class Solution:
    
    def maxIncreaseKeepingSkyline(self, grid) -> int: # grid: List[List[int]]
        
        if not grid: return 0

        # TopBottom = LeftRight = []
        # such declaration is implicit, in python, it means same array 
        # from the same addr

        TopBottom = [] 
        LeftRight = []
        nrow = len(grid)
        ncol = len(grid[0]) 
        grid = np.array(grid)
        gridTranpos = np.transpose(grid)

        for i in range(ncol):
            TopBottom.append(max(gridTranpos[i,:]))
        for i in range(nrow):
            LeftRight.append(max(grid[i,:]))
        
        ans = 0
        # cross validation
        for i in range(len(LeftRight)):
            for j in range(len(TopBottom)):
               ans += (min(LeftRight[i], TopBottom[j]) - grid[i][j])
        
        return ans

if __name__ == "__main__":
    s = Solution()
    grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
    ans = s.maxIncreaseKeepingSkyline(grid)
    print(ans)
    