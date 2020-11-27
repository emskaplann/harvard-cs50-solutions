from cs50 import get_string

text = get_string("Text: ")
word_count = 1.0
letter_count = 0.0
sentence_count = 0.0

for i in range(len(text)):
    if text[i].isalpha():
        letter_count += 1.0
    elif text[i] == " ":
        word_count += 1
    elif text[i] in [".", "!", "?"]:
        sentence_count += 1.0

average_num_of_letters_per_100_words = letter_count * (100.0 / word_count)
average_num_of_sentences_per_100_words = sentence_count * (100.0 / word_count)
grade_index = round(0.0588 * average_num_of_letters_per_100_words - 0.296 * average_num_of_sentences_per_100_words - 15.8)

if grade_index >= 16:
    print("Grade 16+")
elif grade_index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade_index}")