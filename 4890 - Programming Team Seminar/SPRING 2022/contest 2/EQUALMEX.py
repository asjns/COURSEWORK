T = int(input())
for _ in range(T):
    N = int(input())
    count = [0 for _ in range(N+1)]
    nums = [int(x) for x in input().split()]
    for n in nums:
        count[n] += 1
    answer = next((x for x in range(N) if count[x] < 2), None)
    if answer == None or count[answer] == 0:
        print("YES")
    else:
        print("NO")
