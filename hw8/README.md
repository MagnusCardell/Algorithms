Alg Euclid's algorithm homework
Homework 8   Due Tuesday, 2-27-18
A. Asymptotic complexity

    1.[C] Prove or disprove: 18 n^3 = Omega(500 n^2)

I will prove that 18n^3 > 500 n^2 and therefore that f(n) = Omega(g(n)). In this case, f(n) = 18n^3 and g(n) = 500 n^2. The definition of Big-Omega says that f(n) = Omega(g(n)) iff constants c and k ecists such that for all n>k, f(n) > c*g(n). So we want to solve the equality 18n^3 > c * 500 n^2. 
Solving for c, gives em 18/500 * n^3 /n^2. > c.
Because this leaves n unbounded, it will be larger than constant c for all n > k. Thus, the above statement is proven.

    2.[C] Prove or disprove: 2n * log n = O(n).



    3.[C] Prove or disprove: if f(n) = O(g(n)), then 2*f(n) = O(g(n)).

    4.[C] Prove or disprove: if f(n) = O(g(n)), then g(n) = O(f(n)).

B. Reading

    1. Please read chapter 1 up to the end of section 1.2.3 (Euclid's algorithm for greatest common divisor)

C. Exercises
For the following exercises, please do not write too much detail: a short, concise explanation is best!

    1.[C] Exercise 1.1, page 38.

    2.[C] Exercise 1.3.

    3.[C] Exercise 1.4.

    4.[C] Exercise 1.6, page 39.

    5.[C] Exercise 1.8.

    6.[C] Exercise 1.9.

    7.[C] Exercise 1.11.

    8.[C] Exercise 1.13.

    9.[C] Exercise 1.17, page 40.

    10.[C] Exercise 1.18.