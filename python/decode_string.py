import string

def decode_string(input: string) -> string:
    buffer = ""
    stack = [{"count": 1, "value": ""}]

    for x in input:
        if(x.isdigit()):
            buffer += x
        elif( x == "["):
            stack.append({"count": buffer, "value": ""})
            buffer = ""
        elif(x == "]"):
            last = stack.pop()
            stack[-1]["value"] += last["value"] * int(last["count"]) if last["count"] != "" else 1
        else:
            stack[-1]["value"] += x
        
    print(input, stack[-1]["value"])
    return stack[-1]["value"]

assert decode_string("") == "", "base"
assert decode_string("a") == "a", "a"
assert decode_string("ab") == "ab", "ab"
assert decode_string("2[a]") == "aa", "2[a]"
assert decode_string("b2[a]") == "baa", "b2[a]"
assert decode_string("2[2[2[a]]]") == "aaaaaaaa", "2[2[2[a]]]"

print("all tests pass")