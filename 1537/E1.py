n, k = map(int, input().split())
s = input()
for i in range(1, len(s)):
    if s[i] > s[0]:
        s = s[:i]
        break

res = s*(k//len(s)) + s[:k % len(s)]
print(res)
