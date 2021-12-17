import sys

input = [row.strip() for row in sys.stdin][0]

def to_bin(c):
    if c == "0": return "0000"
    if c == "1": return "0001"
    if c == "2": return "0010"
    if c == "3": return "0011"
    if c == "4": return "0100"
    if c == "5": return "0101"
    if c == "6": return "0110"
    if c == "7": return "0111"
    if c == "8": return "1000"
    if c == "9": return "1001"
    if c == "A": return "1010"
    if c == "B": return "1011"
    if c == "C": return "1100"
    if c == "D": return "1101"
    if c == "E": return "1110"
    if c == "F": return "1111"

binary = ''.join([to_bin(c) for c in input])

decimal = lambda x: int(x,2)
version_sum = 0
index = 0

def read(length):
    global index
    res = binary[index:index+length]
    index += length
    return res

def decode():
    global version_sum, index
    version = decimal(read(3))
    version_sum += version
    message_type = decimal(read(3))
    if message_type == 4: #literal value
        while decimal(read(1)) == 1:
            read(4)
        read(4)
    else: # operator
        length_type_id = decimal(read(1))
        if length_type_id == 0:
            subpackets_length = decimal(read(15))
            read_to = index + subpackets_length
            while(index < read_to):
                decode()
        if length_type_id == 1:
            subpackets_count = decimal(read(11))
            for _ in range(subpackets_count):
                decode()
        
decode()
print(version_sum)