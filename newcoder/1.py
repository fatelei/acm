# -*- coding: utf8 -*-
"""
在一个二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，
输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
"""


class Solution:
    # array 二维列表
    def Find(self, array, target):
        # write code here
        if len(array) == 1 and len(array[0]) == 0:
            return False

        # First find row.
        if target < array[0][0] or target > array[-1][-1]:
            return False

        length = len(array)
        row = -1
        for i in xrange(length):
            if target in array[i]:
                return True

        return False


if __name__ == "__main__":
    s = Solution()
    array = [[]]
    print s.Find(array, 7)
