
class Solution:
    def balancedString(self, s: str) -> int:   
        nleft = 0
        nright = 0 
        count = 0
        for c in s:
            if c == 'L': nleft += 1
            elif c == 'R': nright += 1
            
            if nleft == nright:
                nleft = nright = 0
                count += 1
        return count

if __name__ == "__main__":
    s = Solution()
    print(s.balancedString("LLLLRRRR"))
