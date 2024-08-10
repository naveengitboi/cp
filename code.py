#!/bin/python3

import sys
import itertools

def initialize(s):
    # This function is called once before all queries.
    pass
    
def check_palin(s,l):
    count_max = 0
    cmax = 0
    for i in range(2,l+1):
        a = itertools.permutations(s,i)
        a = set(a)
        for j in a:
            if j == j[::-1]:
                if (i>cmax):
                    count_max=1
                    cmax = i
                else:
                    count_max+=1
    return (count_max)
    
def answerQuery(l, r, st):
    # Return the answer for this query modulo 1000000007.
    m = 1000000007
    s=''
    for i in range(l-1, r):
        s+=st[i]
    ans = check_palin(s, r-l+1)   
    return (ans % m)

if __name__ == "__main__":
    s = input().strip()
    #initialize(s)
    q = int(input().strip())
    for a0 in range(q):
        l, r = input().strip().split(' ')
        l, r = [int(l), int(r)]
        result = answerQuery(l, r, s)
        print(result)

