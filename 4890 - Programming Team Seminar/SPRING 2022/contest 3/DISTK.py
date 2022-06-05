for _ in range(int(input())):
    N,K = [int(x) for x in input().split()]
    good = N 
    A = [1]
    while (good < K):
        good += len(A)
        A.append(A[-1]+1)
    extra = good - K
    if (extra > 0):
        A[-1] -= A[-1-extra]
    while (len(A) < N):
        A.append(A[-1])
    print(*A)
