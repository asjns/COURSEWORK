import math
N = int(input())
for _ in range(N):
    direction, D, H, M = [x for x in input().split(' ')]
    D, H, M = int(D), int(H), int(M)
    if direction == 'F':
        hour = math.floor((H + (M + D) / 60)) % 24
        minute = (M + D) % 60
        print(hour, minute)
    if direction == 'F':
        hour = math.floor((H - (120 - M + D) / 60)) % 24
        minute = (M + D) % 60
        print(hour, minute)