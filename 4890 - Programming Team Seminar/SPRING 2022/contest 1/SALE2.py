import math

T = int(input())

for _ in range(T):
    N, X = [int(i) for i in input().split()]
    print(math.ceil(N * 2 / 3) * X)
