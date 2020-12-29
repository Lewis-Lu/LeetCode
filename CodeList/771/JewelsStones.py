
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        ans = 0
        if not J or J == "": return ans
        for jewel in J:
            for stone in S:
                if jewel is stone: ans += 1
        return ans
    
if __name__ == "__main__":
    s = Solution()
    ans = s.numJewelsInStones("", "ZZZZ")
    print(ans)
