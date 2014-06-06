from random import *

T = 3
S = 100000
D = 100000

print T
for t in xrange( 0, T):
    n = 30000#randint( 1, 10000)
    q = 30000#randint( 1, 10000)
    p1 = 262237# 10247
    p2 = 262133#45281
    r = p1 + 1#randint(1, 10000000)
    print n, q, r, p1, p2
    for i in xrange( 0, n):
        print randint( 0, 100000), 
    print 
    for i in xrange( 0, q):
        type = randint( 0, 2)
        if type == 0 :
            s = randint( 1, S)
            d = randint( 1, D)
            x = randint( 1, n)
            y = randint( x, n)
            print 0, s, d, x, y
        elif type == 1 :
            x = randint( 1, n)
            g = 1000
            print 1, x, g
        else:
            x = randint( 1, n)
            y = randint( x, n)
            print 2, x, y
