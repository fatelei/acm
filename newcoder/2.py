# -*- coding: utf8 -*-
"""
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
"""


class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        tmp = s.replace(" ", "%20")
        return tmp


if __name__ == "__main__":
    s = Solution()
    s.replaceSpace("We Are Happy")
