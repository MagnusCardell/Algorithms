Alg Euclid's algorithm homework
Homework 8   Due Tuesday, 2-27-18
A. Asymptotic complexity

    1.[C] Prove or disprove: 18 n^3 = Omega(500 n^2)
I will prove that 18n^3 > 500 n^2 and therefore that f(n) = Omega(g(n)). In this case, f(n) = 18n^3 and g(n) = 500 n^2. The definition of Big-Omega says that f(n) = Omega(g(n)) iff constants c and k ecists such that for all n>k, f(n) > c*g(n). So we want to solve the equality 18n^3 > c * 500 n^2. 
Solving for c, gives em 18/500 * n^3 /n^2. > c.
Because this leaves n unbounded, it will be larger than constant c for all n > k. Thus, the above statement is proven.

    2.[C] Prove or disprove: 2n * log n = O(n).

The definition of Big O says that f(n) = O(g(n)) iff constants c and k excists such that f(n) <= c*(g(n)) where n>k. In this case f(n) = 2n * logn and g(n) = n. 
Solving for c gives me: 2n * logn/n < c = n * logn < c. This leaves n unbounded which disproves the equality. Therefore, f(n) != O(g(n)) 

    3.[C] Prove or disprove: if f(n) = O(g(n)), then 2*f(n) = O(g(n)).

Assuming that f(n) = O(g(n)), then f(n) <= c * g(n) where c is a positive constant integer. This shows that f(n) will be bounded by c *n so if one side is multiplied by 2, the constant can do the same and preserve the equality. Therefore, this statement is true and proven by the definition of big O. 

    4.[C] Prove or disprove: if f(n) = O(g(n)), then g(n) = O(f(n)).

Assuming that f(n) = O(g(n)), then f(n) <= c * g(n). This means that 0<= f(n) <= c* g(n)<= for all n greater than k where k is a positive integer. This means that c will be a constant only if f(n) = g(n) so that f(n) / g(n) <= c.  where f(n) / g(n) = 1. This is because f(n) cant be bigger than g(n) by our initial assumption and so can't produce anything larger than 1. Therefore the statement is true iff f(n) = Theta(g(n)). 


B. Reading

    1. Please read chapter 1 up to the end of section 1.2.3 (Euclid's algorithm for greatest common divisor)

C. Exercises
For the following exercises, please do not write too much detail: a short, concise explanation is best!

    1.[C] Exercise 1.1, page 38.

Show that in any base >= 2, the sum of any three single-digit numbers is at most two digits long. 
Given that any base b has b-1 digits, the sum of three digits of base b will be 3(b-1) = 3b - 3. 

Our upper bound for these cases, are that the sum of three single digit numbers should not be greater than the sum of two double-digit numbers. Becuase the sum of two double-digit numbers in base b are at most b*b-1, we have the following inequality:
3b-3 <= b^2 -1
3b - 3 - b^2 +1 = (b+1)(b+2) = (b-1)(b-2) which is greater than 0 when b >=2. Thus the statement is proven.


    2.[C] Exercise 1.3.

Assuming that a d-aru tree with n nodes, must have a depth h of Omega(logn/logd) we have the following relationship:

logn/logd <= h
n / d <= d^h
n <= d^(h+1)
which shows that the total number of leaves n, is smaller or equal to the number of leaf-nodes at depth h+1.

To get the minimum depth this tree could have, we want to calculate h. Usually to calculate the depth of a tree we take the log of total nodes, so we get h = log(n) (base d). Therefore h, is the minimum amount of depth of a d-ary tree

    3.[C] Exercise 1.4.

To show that log(n!) = Theta(n logn) I will prove first that the upper bound (Big O) holds, then that the lower bound (Omega) holds. 

First I will show that log(n!) = O(n log n). 
n! = 1 + 2 + 3 + ... + n < n^n
log(n) = log(1) + log(2) + ... + log(n) < log(n^n) = n log n. 
Therefore by the definition of logs and factorials, log(n!) = O(n log n)

Now, I will show that log(n!) = Omega(n log n).
n! > n/2^(n/2)
n! > n/2 + ... + n/2
n! > n/2 + ... + n-1 +  n
log(n!) > log(n/2 + ... + n-1 +  n)
log(n!) > log( n/2^(n/2))
log(n!) > (n/2)log( n/2)
log(n!) > n log n. 
Therefore by the definition of Omega, log(n! = Omega(n log n)

Because both Big O and Omega are proven we can now conlude that log(n!) = Theta(n log n)


    4.[C] Exercise 1.6, page 39.

To prove this algorithm, I want to show that two numbers a and k, when multiplied with the grade school method in base 2, always gets the right answer. 
Multiplication in binary is done by shifting number a, b steps to the left, creating b number of intermediary results that are added together.

a * b = a + a + a + ... a ( b times). 
Because this is equal to how regular multiplication works, this is proven. 


    5.[C] Exercise 1.8.

Just like the multiplication algorithm, a total of n nodes are created (until x is 0), then each node is returning to the previous node which means that every node (excpet of the leaf-node) will be touched two times. The total number of nodes is therefore n^2, even if the nodes are the same. 

    6.[C] Exercise 1.9.

We have that 
x \equiv x' mod N 
y \equiv y' mod N

lets call
x mod N = a
y mod N = b
Because of the above equivalences we have
x' mod N = a
y' mod N = b
Therefore combining the numbers around a and b,
x mod N = a = x' mod N 
y mod N = b = y' mod N
which gives us the following addition
a + b = x mod N + y mod N \equiv x' mod N + y' mod N 
a + b = x + y \equiv x' + y'

For multiplication, we get the following relation
x mod N = a = x' mod N 
y mod N = b = y' mod N
a * b = a * y modN \equiv x' * y' modN

Thuus the relation is justified.

    7.[C] Exercise 1.11.

See photo, yes they are divisible. 

    8.[C] Exercise 1.13.

Finding a mod31 difference between the two bases first, then dividing each power by the result produces a result where the remainder is 0 (after taking the difference)

    9.[C] Exercise 1.17, page 40.

Taking the first, iterative into account first.
To sum it up, it takes a n-bit long number, and a power p. The output is the n-bit number to the p'th power. Using gradeschool multiplication, this algorithm will multiply input n p times. 
***
for(int i=0; i<p; ++i{ 
    temp *=x
}
return temp
***
So this algoritm will run O(p)
The second algorithm, using recursion takes the same n-bit number and a power, and divides the power by 2 until it hits 0, it then returns to the previous node, doubling x every time. 
***
rec_expo(x,y){
    if (y==0) return 1;
    z = rec_expo(x, y/2)
    if (y is even) return 2*z
    else return x*z*z
}
***
So it will touch every node twice, therebey coming to the time complexity O(n^2)

    10.[C] Exercise 1.18.
Computing gcd(210, 588) with factorization:
210 = 2 * 105 = 2 * 3 * 35 = 2 * 3 * 5 * 7
588 = 2 * 294 = 2 * 2 * 147 = 2 * 2 * 3 * 49 = 2 * 2 * 3 * 7 * 3
7*4 = 42
gcd is 42

Computing gcd(210, 588) with Euclid's algorithm
gcd(210, 588) = gcd(210, 588-(210*2)) = gcd(168, 210) = gcd(42, 168) = gcd(1,42) = 42    