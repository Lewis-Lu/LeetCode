
class Solution:
    def __init__(self, grid):
        self.grid_map = grid

    def dfs(self, x0, y0, i, j, cache):
        rows = len(self.grid_map)
        cols = len(self.grid_map[0])
        
        if i < 0 or i >= rows or j < 0 or j >= cols or self.grid_map[i][j] == 0:
            return

        # cell if visited
        self.grid_map[i][j] = 0

        cache.append([i - x0, j - y0])

        # dfs in all four directions
        self.dfs(x0, y0, i - 1, j, cache)
        self.dfs(x0, y0, i + 1, j, cache)
        self.dfs(x0, y0, i, j - 1, cache)
        self.dfs(x0, y0, i, j + 1, cache)


    def distinct_island(self):
        ans = []
        
        if len(self.grid_map) == 0 or len(self.grid_map[0]) == 0:
                return 0
        
        rows = len(self.grid_map)
        cols = len(self.grid_map[0])

        for i in range(rows):
            for j in range(cols):
                
                if not self.grid_map[i][j]: continue

                v = []
                self.dfs(i, j, i, j, v)
                ans.append(v)

        return len(ans)


if __name__ == "__main__":
    
    grid = [ 1, 1, 0, 1, 1 ]
    
    s = Solution(grid)
    ans = s.distinct_island()
    print(ans)