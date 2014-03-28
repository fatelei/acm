#!/usr/bin/python
#-*-coding: utf8-*-


class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        s = s.split()
        s.reverse()
        return " ".join(s)
