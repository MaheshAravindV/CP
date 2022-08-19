import time
for n in range(7,8):
    while True:
        # if n == n + n%10:
        #     break
        print(n)
        n = n+n%10
        time.sleep(1)