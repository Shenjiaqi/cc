import psyco
psyco.full()
T = input()
m = 1000000
s = [ 0 for x in xrange(m) ]
tag = [ 0 for x in xrange(m) ]
for i in xrange(T):
    n, a, b, c, d = map( int, raw_input().split() )
    for j in xrange(n):
        if tag[d] == i:
            s[d] += 1
        else:
            s[d] = 1
            tag[d] = i
        d = ( a * d * d + b * d + c ) % m
    ans = 0
    ansi = 0
    for j in xrange( m - 1, 0, -1 ):
        if tag[j] == i and s[j] > 0 and s[j] % 2 == 1:
            if ansi == 1:
                ans -= j
                ansi = 0
            else:
                ans += j
                ansi = 1
    print abs( ans ) 
