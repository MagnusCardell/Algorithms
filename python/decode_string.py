import string

def decode_string(input: string) -> string:
    result = ""
    buffer = ""
    for x in input:
        # only support lower-case for now
        if( ord(x) >= 97 and ord(x) <= 123):
            iterations = int(buffer) if buffer != "" else 1
            result += x * iterations
            buffer = ""
        else:
            buffer += x
    print(input, result)
    return result

assert decode_string("") == "", "base"
assert decode_string("a") == "a", "a"
assert decode_string("2a") == "aa", "2a"
assert decode_string("ab") == "ab", "ab"
assert decode_string("a") == "a", "a"
assert decode_string("a2b10c") == "abbcccccccccc", "a2b10c"

print("all tests pass")