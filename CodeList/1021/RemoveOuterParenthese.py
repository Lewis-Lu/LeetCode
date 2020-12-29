class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        nleft = nright = 0
        front = rear = 0
        ans = ""
        if not S: return None
        for i in range(len(S)):
            if S[i] == '(':
                nleft += 1
            else:
                nright += 1
            if nleft == nright:
                rear = i+1
                ans += S[front+1:rear-1]
                front = i + 1
        return ans


if __name__ == "__main__":
    s = Solution()
    print(s.removeOuterParentheses("()()"))
