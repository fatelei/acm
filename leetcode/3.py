#!/usr/bin/python
#-*-coding: utf8-*-


# Definition for a point
class Point:

    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b


class Solution:
    # @param points, a list of Points
    # @return an integer

    def maxPoints(self, points):
        length = len(points)
        if length < 3:
            return length
        else:
            cur_max = -1

            for i in xrange(length):
                slop = {"inf": 0}
                same = 1

                for j in xrange(length):

                    if i == j:
                        continue

                    if points[i].x == points[j].x and points[i].y != points[j].y:
                        slop["inf"] += 1
                    elif points[i].x != points[j].x:
                        k = (1.0 * (points[j].y - points[i].y)) / (points[j].x - points[i].x)

                        slop[k] = 1 if k not in slop else slop[k] + 1
                    elif points[i].x == points[j].x and points[i].y == points[j].y:
                        same += 1

                cur_max = max(cur_max, max(slop.values()) + same)

            return cur_max


if __name__ == "__main__":
    s = Solution()
    points = [(0, 0), (1, 1)]
    s.maxPoints(points)
