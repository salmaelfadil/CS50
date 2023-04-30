from cs50 import get_string, get_int

# promt user for input
while True:
    cc_number = get_string("credit card number: ")
    if int(cc_number) > 0:
        break

pos = 0
length =len(cc_number)
sum1 = 0
sum2 = 0
sum3 = 0 

for i in range(-2 , (-length -1) , -2):
    temp = int(cc_number[i]) *2
    if temp > 9:
       sum1 += temp - 9
    else:
        sum1 += temp

for i in range( -1, (-length -1) , -2):
    temp2 = int (cc_number[i])
    sum2 += temp2
        
print (sum1)
print (sum2)
sum3 = sum1 + sum2
print(sum3)

if (sum3 % 10 != 0):
    print("INVALID")

elif (sum3 % 10 == 0 and length == 15 and int(cc_number[0]) == 3 and int(cc_number[1]) == 4 or int(cc_number[1])== 7):
    print ("AMEX")

elif (sum3 %10 ==0 and length== 16 and int(cc_number[0]) == 4):
    print("VISA")
    
elif (sum3 %10 ==0 and length== 13 and int(cc_number[0]) == 5 and int(cc_number[1]) == 1 or 2 or 3 or 4 or 5):
    print("MASTERCARD")

