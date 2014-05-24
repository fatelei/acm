#!/usr/bin/python
#-*-coding: utf8-*-

'''
priority queue
0/1背包问题。假设有4个物品，其重量分别为(4, 7, 5, 3)，价值分别为(40, 42, 25, 12)，背包容量W=10
'''

import heapq

global items
global nodes
global W
global N

items = []
W = 10
DOWN = 0
UP = 0
nodes = []
N = 4

class Node(object):

    def __init__(self, cv, cw, ub, cnt):
        self.cv = cv
        self.cw = cw
        self.ub = -ub
        self.cnt = cnt

    def __cmp__(self, other):
        return self.ub > other.ub


maxn = Node(0, 0, 0, 0)

def initialize():
    weight = [4, 7, 5, 3]
    value = [40, 42, 25, 12]
    MIN = 0x7fffff
    MAX = -1
    items.append({})
    for i in xrange(N):
        tmp = {}
        tmp['w'] = weight[i]
        tmp['v'] = value[i]
        tmp['p']= (1.0 * value[i]) / weight[i]
        tmp['num'] = i + 1
        MIN = min(MIN, tmp['p'])
        MAX = max(MAX, tmp['p'])
        items.append(tmp)

    global DOWN
    global UP
    DOWN = W * MIN
    UP = W * MAX


def calculate_ub(v, w, p):
    return v + (W - w) * p

def enqueue(cw, cv, ub, flag, num):

    if ub < UP and ub > DOWN and cw < W:
        node = Node(cv, cw, ub, num + 1)
        heapq.heappush(nodes, node)

def bfs():
    node = Node(0, 0, calculate_ub(0, 0, items[1]['p']), 1)
    heapq.heappush(nodes, node)

    while nodes:
        tmp = heapq.heappop(nodes)
        tmp.ub = -tmp.ub
        if tmp.ub == tmp.cv or tmp.cnt >= N:
            if maxn.cv < tmp.cv:
                maxn.cv = tmp.cv
            break

        tmp_cw = tmp.cw
        tmp_cv = tmp.cv

        for i in xrange(2):

            # i = 1, use the item
            # i = 0, don't use item

            index = tmp.cnt
            if i == 1:
                tmp_cw += items[index]['w']
                tmp_cv += items[index]['v']

            tmp_ub = calculate_ub(tmp_cv, tmp_cw, items[index+1]['p'])
            enqueue(tmp_cw, tmp_cv, tmp_ub, i, index)



if __name__ == '__main__':
    initialize()
    #import pdb;pdb.set_trace()
    items[1:].sort(key=lambda x: x['p'], reverse=True)
    bfs()
    print maxn.cv