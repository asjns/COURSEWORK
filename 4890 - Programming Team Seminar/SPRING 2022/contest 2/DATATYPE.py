T = int(input())
for _ in range(T):
    N, X = [int(x) for x in input().split()]
    print(X%(N+1))