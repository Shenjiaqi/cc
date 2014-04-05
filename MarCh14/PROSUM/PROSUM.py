T = input()
for i in xrange(T):
    N = input()
    ai = map( int, raw_input().split() )
    cnt0 = 0
    cnt1 = 0
    cnt2 = 0
    for j in ai:
        if j == 0:
            cnt0 += 1
        elif j == 1:
            cnt1 += 1
        elif j == 2:
            cnt2 += 1
    ans = N * ( N - 1 ) / 2
    ans -= cnt0 * ( cnt0 - 1 ) / 2 + cnt0 * ( N - cnt0 )
    ans -= cnt1 * ( cnt1 - 1 ) / 2 + cnt1 * ( N - cnt0 - cnt1 )
    ans -= cnt2 * ( cnt2 - 1 ) / 2
    print ans

