'''
No. 84
'''

# def largestRectangleArea(heights) -> int:
#     ''' brutal force
#     no extra storage cost
#     time complexity: O(n^2)
#     '''
#     ans = 0
#     i = 0
#     while i < len(heights):
#         cur_bar = heights[i]
#         lb = i # left bound
#         rb = i # right bound
#         while heights[lb] >= cur_bar: 
#             lb -= 1
#             if lb < 0: break
#         while heights[rb] >= cur_bar: 
#             rb += 1
#             if rb > len(heights)-1: break
        
#         ans = max(ans, (rb-lb-1)*cur_bar)
#         i += 1
    
#     return ans

def largestRectangleArea(heights) -> int:
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = list()
        res = 0
        heights.append(0)
        N = len(heights)

        for i in range(N):
            if not stack or heights[i] > heights[stack[-1]]:
                stack.append(i)
            else:
                while stack and heights[i] <= heights[stack[-1]]:
                    h = heights[stack[-1]]
                    stack.pop()
                    w = i if not stack else i - stack[-1] - 1
                    # print(h, w, stack, end='\n')
                    res = max(res, h * w)
                stack.append(i)
            # print(stack, end='\n')
        return res

        

if __name__ == "__main__":
    print(largestRectangleArea([1,2,3,4,5,6]))