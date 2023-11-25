"""
A girl is walking along an apple orchard with a bag in each hand. 
She likes to pick apples from each tree as she goes along, but is meticulous about not putting different kinds of apples in the same bag.

Given an input describing the types of apples she will pass on her path, 
in order, determine the length of the longest portion of her path that consists of just two types of apple trees.

For example, given the input [2, 1, 2, 3, 3, 1, 3, 5], the longest portion will involve types 1 and 3, with a length of four.
"""
from typing import List
def pick_apples(trees: List[int]) -> int:

    bags = set()
    streak = 0
    p1 = 0
    p2 = 0
    for p2 in range(len(trees)):
        apple = trees[p2]
        
        bags.add(apple)
        while(len())
        if len(bags) <= 2:
            bags[]
        if tree not in bags 
    return 0

assert pick_apples([2, 1, 2, 3, 3, 1, 3, 5]) == 4