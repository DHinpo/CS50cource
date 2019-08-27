from nltk.tokenize import sent_tokenize

def lines(a, b):
    lines_1 = set(a.split("\n"))
    lines_2 = set(b.split("\n"))
    return lines_1 & lines_2


def sentences(a, b):
    sentences_1 = set(sent_tokenize(a))
    sentences_2 = set(sent_tokenize(b))
    return sentences_1 & sentences_2

def substring_tokenize(str, n):
	substrings = []
	for i in range(len(str) - n + 1):
		substrings.append(str[i:i + n])
	return substrings

def substrings(a, b, n):
    substrings_1 = set(substring_tokenize(a, n))
    substrings_2 = set(substring_tokenize(b, n))
    return substrings_1 & substrings_2 
