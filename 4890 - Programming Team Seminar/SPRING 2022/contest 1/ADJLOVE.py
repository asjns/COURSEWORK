T = int(input())

for _ in range(T):
    N = int(input())
    evens = []
    odds = []
    for A in input().split():
        if int(A)%2 == 0:
            evens.append(A)
        else:
            odds.append(A)
    if len(odds) == 0:
        print(-1)
    elif len(odds) % 2 == 0:
        print(' '.join(evens + odds))
    elif len(evens) > 0 and len(odds) > 1:
        last = odds.pop()
        evens = [last, *evens]
        print(' '.join(evens + odds))
    else:
        print(-1)