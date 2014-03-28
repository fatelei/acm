#!/usr/bin/python
#-*-coding: utf8-*-


class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        num.sort()

        max_lcs = -1
        length = len(num)

        if length == 1:
            return 1

        i = 0

        #import pdb;pdb.set_trace()
        while i != length - 1:
            tmp = 1
            j = 0

            for j in xrange(i, length - 1):
                #print num[j+1], num[j]
                if num[j + 1] == num[j]:
                    continue
                if num[j + 1] - num[j] == 1:
                    tmp += 1
                else:
                    break

            if max_lcs < tmp:
                max_lcs = tmp

            
            i = j + 1

        return max_lcs



if __name__ == "__main__":
    s = Solution()
    s.longestConsecutive([1, 2, 0, 1])