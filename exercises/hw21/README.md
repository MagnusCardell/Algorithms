Homework 22   Due Tuesday, 4-10-18
A. Reading

    1. Please finish reading section 5.1, skimming the part about disjoint set data structures.

    2. Please read section 5.2.

B. Exercises

    1.[C] Exercise 5.1c, page 148.

c) When the edges are added, they are already sorted by weight value in increasing order. This is the resulting adding 

(node A, node B, weight)
(A, E, 1)
(E, F, 6)
(B, E, 2)
(F, G, 3)
(G, H, 3) 
(C, G, 4)
(D, F, 5)

    2.[C] Exercise 5.3.

The brute force attempt would be to remove every edge, one at a time, and run DFS search to see if the graph is still connected.
The time complexity would be O(e(e(e+v))) where e= edges and v = nodes. 

To improve on this, we can instead use only one DFS search. If the search encounters a back-edge, that means that it contains a cycle, and thus that we can remove that edge. 
Time complexity goes down to O(e+v).

    3.[C] Exercise 5.6.

Given that all weights are distinct, and the order of adding edges to the tree in a greedy algorithm always picks the optimal without creating a cycle. There is therefore only one way to add its edges. Assuming you picked another edge at any point instead of the optimal tree, by the definition of a minimum spanning tree, it would no longer be a minimum spanning tree that guarantees no cycles. 

    4.[C] Exercise 5.13.

If A-21% C-20%, G-9%, T-40% their weights are simply A:0.21, B:0.2, G:0.09, T:0.4

Take the smallest two probabilities/frequencies (G and C), to use as child-nodes to an internal node
node(0.29)
    node(0,20) 'C'
    node(0.09) 'G'

Repeat. So now we take the (0,29) and A

node(0.50)
    node(0.21) 'A'
    node(0.29)
        node(0,20) 'C'
        node(0.09) 'G'

Now the last node

node(0.90)
    node(0.40) 'T'
    node(0.50)
        node(0.21) 'A'
        node(0.29)
            node(0.09) 'G'
            node(0,20) 'C'
            

The resulting encoding:
A: 10
T: 10
G: 110
C: 111

    5.[C] Exercise 5.14.

a - 0.5
b - 0.25
c - 0.125
d - 0.0625
e - 0.0625

a)
node(1)
    node(0.5) 'a'
    node(0.5)
        node(0.25) 'b'
        noed(0.25)
            node(0.125) 'c'
            node(0.125) 
                node(0.0625) 'd'
                node(0.0625) 'e'
a = 0
b = 10
c = 110
d = 1110
e = 1111

b) Each bit is length 4. So a file with 100,000 characters would need 400,000 bits to encode

C. Project

    1. In your team of two or three, implement the Huffman encoding algorithm shown on page 142. Please submit your code through git.

    2. Build an encoder that takes a file of ASCII characters, and encodes them as a long sequence of bits, using a prescribed association between characters and bit sequences. Here is an example of one way to handle input and output of bit sequences, and here is an example of reading a text file, one byte at a time. Please submit your code through git.

    3. Build a decoder that works with your encoder.

    4.[C] Demonstrate an example of using your encoder/decoder. What compression rate do you achieve, when you divide by eight? (Note that the bitset is output using a whole byte for each bit.)