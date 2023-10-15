
def calculate_employee_score(hierarchy: {int: [int]}, eid: int) -> int:
    sum = 0
    if( eid not in hierarchy):
        return 1
    else:
        for x in hierarchy[eid]:
            sum += calculate_employee_score(hierarchy, x)
    sum += 1
    print(eid, sum)
    return sum

assert calculate_employee_score({}, 1) == 1, "base"
assert calculate_employee_score({123: [234, 345], 234: [456, 789], 345:[], 456:[], 789:[]}, 123) == 5, "example"
assert calculate_employee_score({123: [234], 234: [123]}, 123) == 1, "cycle example"