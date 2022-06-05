register = ['?'] * 32

def CLEAR(args):
    i = int(args[1])
    register[i] = 0
    
def SET(args):
    i = int(args[1])
    register[i] = 1
    
def OR(args):
    i, j = int(args[1]), int(args[2])
    a, b = register[i], register[j]
    if a != '?' and b != '?':
        register[i] = a | b
    else:
        register[i] = '?'
        
def AND(args):
    i, j = int(args[1]), int(args[2])
    a, b = register[i], register[j]
    if a != '?' and b != '?':
        register[i] = a & b
    else:
        register[i] = '?'
    
func_dict = {   'CLEAR':CLEAR,
                'SET':SET,
                'OR':OR,
                'AND':AND }
                
n = int(input())

while n != 0:
    for _ in range(n):
        user_input = input()
        input_list = user_input.split()
        command = str(input_list[0])
        func_dict[command](input_list)
    n = int(input())
    output = ""
    for b in reversed(register):
        output += str(b)
    print(output)
    register = ['?'] * 32

