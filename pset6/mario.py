from cs50 import get_int

#promt the user
while True:
    height = get_int("height: ")
    if (height >= 1) and (height <= 8):
        break
    
for i in range(height):
    for space in range(height - i -1):
        print(" ", end = "")
    for hash in range(i + 1):
        print ("#" , end ="")
    print("\n", end = "")
