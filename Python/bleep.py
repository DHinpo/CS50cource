from sys import argv


def main():
	if len(argv) != 2:
		print('Usage: python bleep.py dictionary')
		exit(1)

	text1 = input('What message would you like to censor?\n')
	words = text1.split(" ")
	for word in words:
		with open(argv[1],'r') as f:
			test_word = word.lower()
			lenght = len(word)
			if test_word in f.read():
				print(lenght*'*', end = " ")
			else:
				print(word, end = " ")
	print()


if __name__ == "__main__":
    main()
