#!/usr/bin/python
#-*-coding: utf8-*-

class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        operators = ["*", "/", "+", "-"]
        numbers = []

        for token in tokens:
            if token in operators:
                v1 = numbers.pop()
                v2 = numbers.pop()

                v3 = 0
                if token == "*":
                    v3 = v2 * v1
                elif token == "/":
                    if v2 * v1 < 0:
                        v3 = -(-v2/v1)
                    else:
                        v3 = v2 / v1
                elif token == "+":
                    v3 = v2 + v1
                elif token == "-":
                    v3 = v2 - v1

                numbers.append(v3)

            else:
                numbers.append(int(token))

        return numbers.pop()


if __name__ == "__main__":
    s = Solution()
    print s.evalRPN(["-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"])