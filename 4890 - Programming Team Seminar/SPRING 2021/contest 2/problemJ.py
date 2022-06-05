n = input()

speed = 0
prev_t = 0
prev_d = 0

for i in range(int(n)):
    dt = input()
    dt = dt.split(' ')
    t = int(dt[0])
    d = int(dt[1])
    temp_t = t
    temp_d = d
    t -= prev_t
    d -= prev_d
    prev_t = temp_t
    prev_d = temp_d

    if d != 0 and speed < d/t:
        speed = d/t

print(int(speed))
        
