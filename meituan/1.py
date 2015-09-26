# -*- coding:utf-8 -*-


class LongestDistance:

    def getDis(self, A, n):
        # write code here
        max_gap = 0
        for i in xrange(len(A)):
            for j in xrange(len(A)):
                if j >= i:
                    tmp = A[j] - A[i]
                    if tmp > max_gap:
                        max_gap = tmp
        return max_gap

if __name__ == "__main__":
    l = LongestDistance()
    print l.getDis([10, 5], 2)
    print l.getDis([10, 1, 4], 3)
    print l.getDis([5890, 12599, 9872, 6013, 9204, 6573, 11220, 1588], 8)
