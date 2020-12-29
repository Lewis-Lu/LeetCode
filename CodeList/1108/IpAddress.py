
class Solution:
    def defangIPaddress(self, address: str) -> str:
        additionItem = "[.]"
        ans = ""

        if not address:
            return None
        else:
            for c in address:
                if c == '.':
                    ans = ans + additionItem
                else:
                    ans = ans + c
        return ans

if __name__ == "__main__":
    s = Solution()
    ans = s.defangIPaddress("255.100.50.0")
    print(ans)
