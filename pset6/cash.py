from cs50 import get_float

# promt the user for change
while True:
    change = get_float("change: ")
    if change > 0:
        break

# reject a negative integer
if (change < 0):
    print("provide a positive value")

# keep track of number of coins
coins = 0
cents = round(change * 100)

while cents >= 25:
    coins += 1
    cents = cents - 25
while cents >= 10:
    coins += 1
    cents = cents - 10
while cents >= 5:
    coins += 1 
    cents = cents - 5 
while cents >= 1:
    coins += 1
    cents = cents - 1
print(coins)
