#/bin/python3

from typing import List

class Solution:
    def transformStr(self, s: str, strs: List[str]) -> List[bool]:
        #©leetcode
        ans = []
        cnt0_1 = cnt1_1 = 0
        for i in range(len(s)):
            if s[i] == '0':
                cnt0_1 += 1
            elif s[i] == '1':
                cnt1_1 += 1

        for i in range(len(strs)):
            cnt0_2 = cnt1_2 = 0
            for j in range(len(strs[i])):
                if strs[i][j] == '0':
                    cnt0_2 += 1
                elif strs[i][j] == '1':
                    cnt1_2 += 1
            if (cnt0_1 < cnt0_2) or (cnt1_1 < cnt1_2):
                ans.append(False)
            else:
                t=list(strs[i])
                s0_cnt = t0_cnt = 0
                tmp = True
                for j in range(len(t)):
                    if s[j] == '0':
                        s0_cnt += 1
                    if t[j] == '0':
                        t0_cnt += 1
                    if t[j] == '?':
                        if cnt0_1 > cnt0_2:
                            t[j] = '0'
                            t0_cnt += 1
                            cnt0_2 += 1
                        else:
                            t[j] = '1'
                            cnt1_2 += 1
                    if s0_cnt > t0_cnt:
                        tmp = False
                        break
                ans.append(tmp)

        return ans
    

if __name__ == "__main__":
    s = Solution()
    ss = "01"
    strs = ["?0"]
    print(s.transformStr(ss, strs))
