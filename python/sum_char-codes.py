import string


def sum_char_codes(input: string) -> int:
    sum = 0
    for c in input:
        sum += ord(c)
    return sum

#print(sum_char_codes("aa"))

assert sum_char_codes("") == 0, "base case"
assert sum_char_codes("a") == 97, "single a"
assert sum_char_codes("aa") == 194, "double a"
print("all passed")