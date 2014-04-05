T = input()
for i in xrange(T):
    n = input()
    w = map( int, raw_input().split() )
    add = 0
    ans = 0
    for j in w:
        ans = max( ans, add + j )
        add += 1
    print(ans)

