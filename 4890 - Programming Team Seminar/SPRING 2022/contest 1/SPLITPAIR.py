T = int(input())

for _ in range(T):
    N = int(input())
    D = [int(x) for x in str(N)]
    EVENS = len(list(filter(lambda x: (x % 2 == 0), D)))
    ODDS = len(list(filter(lambda x: (x % 2 == 1), D)))
    if N >= 100:
        if (N%10)%2 == 0:
            if EVENS > 1:
                print("YES")
            else:
                print("NO")
        elif ODDS > 1:
            print("YES")
        else:
            print("NO")
    elif (sum(list(map(int,str(N)))) % 2 == 0):
        print("YES")
    else:
        print("NO")