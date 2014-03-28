#!/usr/bin/python
#-*-coding: utf8-*-


class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = collections.OrderedDict()

    # @return an integer
    def get(self, key):
        if key in self.cache:
            value = self.cache[key]
            del self.cache[key]
            self.cache[key] = value
            return value
        else:
            return -1

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        if key in self.cache:
            del self.cache[key]
            self.cache[key] = value
        else:
            if self.capacity <= 0:
                self.cache.popitem(last=False)
            else:
                self.capacity -= 1

            self.cache[key] = value
