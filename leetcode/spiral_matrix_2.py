#!/usr/bin/python
#-*-coding: utf8-*-


class Solution:
    # @return a list of lists of integer
    def generateMatrix(self, n):
        matrix = []

        for i in xrange(n):
            matrix.append([])
            for j in xrange(n):
                matrix[i].append(0)

        i = 0
        j = n - 1
        k = 0
        incr = 1

        while i < j:
            for k in xrange(i, j + 1):
                matrix[i][k] = incr
                incr += 1

            for k in xrange(i+1, j):
                matrix[k][j] = incr
                incr += 1

            k = j
            while k >= i:
                matrix[j][k] = incr
                incr += 1
                k -= 1

            k = j - 1

            while k > i:
                matrix[k][i] = incr
                incr += 1
                k -= 1

            i += 1
            j -= 1

        if i == j:
            matrix[i][j] = incr

        return matrix

if __name__ == "__main__":
    s = Solution()
    s.generateMatrix(4)