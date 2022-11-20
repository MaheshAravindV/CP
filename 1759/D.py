t = int(input())
while t > 0:
    n, m = map(int, input().split())
    bf2, bf5 = 1, 1
    while n % (bf2*2) == 0:
        bf2 *= 2
    while n % (bf5*5) == 0:
        bf5 *= 5

    g2, g5, ans = 1, 1, 0

    while True:
        temp = max(int(g2/bf2), 1) * max(int(g5/bf5), 1)
        if temp > m:
            break
        ans = temp
        g2 *= 2
        g5 *= 5

    if ans == 0:
        print(n*m)
    else:
        print(n*ans*int(m/ans))
    t -= 1
