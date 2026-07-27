#/bin/python3

class Solution:
    def canReach(self, start: list[int], target: list[int]) -> bool:
        # ©leetcode
        diff1 = abs(start[0] - target[0])
        diff2 = abs(start[1] - target[1])
        if diff1 % 2 != diff2 % 2:
            return False
        return True
    

if __name__ == "__main__":
    s = Solution()
    start = [4, 5]
    target = [6, 6]
    print(s.canReach(start, target))
