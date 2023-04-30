from cs50 import get_string

# promt user for text
text = get_string("Text: ")

words = 1
sentences = 0
letters = 0

# check each character
for char in text:
    if char.isalpha():
        letters += 1
    if char.isspace():
        words += 1
    if char in ['?','!','.']:
        sentences += 1

# calculate letters and sentences over 100 words
av_letters = (letters * 100.0) / words
av_s = (sentences * 100.0) / words

# apply the index
index = int((0.0588 * av_letters - 0.296 * av_s - 15.8) + 0.5)

# print grade level
if index <1:
    print("Before Grade 1")

elif index >= 16:
    print("Grade 16+")

else:
    print(f"Grade {index}")

