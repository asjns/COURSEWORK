
# seq_len = input()

# seq = input()
# seq = seq.split()
# seq = [int(x) for x in seq]

import random

seq = random.sample(range(0,1000000000),100000)

num_changes = 0

while len(seq) > 0:
    # remove leading zeroes
    while len(seq) > 0 and seq[0] == 0:
        seq.remove(0)
    
    if len(seq) == 0:
        break
    
    startIndex = 0
    try:
        endIndex = seq.index(0)
    except:
        # No zeroes, segment is whole sequence
        endIndex = len(seq)

    minv = min(seq[startIndex:endIndex])
    
    # If the subset contains only unique integers, it requires as many changes as its length
    subset_len = len(seq[startIndex:endIndex])
    if len(set(seq[startIndex:endIndex])) == subset_len:
        num_changes += subset_len
        seq[startIndex:endIndex] = [0 for x in seq[startIndex:endIndex]]
    else:
        seq[startIndex:endIndex] = [x - minv for x in seq[startIndex:endIndex]]
        num_changes += 1

print(num_changes)