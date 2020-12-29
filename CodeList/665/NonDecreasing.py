
# treat this problem as triplet problem

class Solution:
    def checkPossibility(self, nums) -> bool:
        modifiedCnt = 0
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                modifiedCnt += 1
                if i == 1 or nums[i-2] <= nums[i]:
                    nums[i-1] = nums[i]
                else:
                    nums[i] = nums[i-1]
        return modifiedCnt <= 1


if __name__ == "__main__":
    s = Solution()
    print(s.checkPossibility([4,2,1]))
            