l = [7, 2, 10]
for i in range(1, 8):
    mi = -1
    d = abs(l[-1] - i)
    if abs(l[0] - i) < d:
        mi = 0
        d = abs(l[0] - i)
    for j in range(len(l)-1):
        if abs(l[j]-i) + abs(l[j+1] - i) < d:
            mi = j
            d = abs(l[j]-i) + abs(l[j+1] - i)
    if mi == 0:
        l = [i] + l
    elif mi == -1:
        l = l + [i]
    else:
        l = l[:mi] + [i] + l[mi:]
    print(l)
