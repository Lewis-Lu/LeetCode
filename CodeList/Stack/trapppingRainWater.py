'''
no. 42
'''
def trap(height) -> int:
    '''
    Input: [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    '''
    # return this value correctly
    vol = 0
    
    # init stacks
    stack = []
    
    i = 0
    while i < len(height):
        while len(stack) != 0 and height[i] > height[stack[-1]]:
            top = stack.pop()
            if len(stack) == 0: break
            bar = min(height[i], height[stack[-1]]) - height[top]
            dis = i-top-1
            vol += bar*dis
        stack.append(i)
        i += 1
    return vol

def trap1(height) -> int:
    '''
    brutal force method
    Input: [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    '''
    # return this value correctly
    vol = 0

    i = 0
    while i < len(height):
        l_max = 0
        r_max = 0

        if i == 0: 
            l_max = height[0]
            r_max = max(height[i: len(height)])
        elif i == len(height)-1:
            l_max = max(height[0: i+1])
            r_max = height[i]
        else:
            l_max = max(height[0:i+1])
            r_max = max(height[i: len(height)])

        bar = min(l_max, r_max)
        vol += bar - height[i]
        i += 1
    return vol

if __name__ == "__main__":
    print(trap1([4,2,0,3,2,5]))