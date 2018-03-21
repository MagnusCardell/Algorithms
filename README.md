# Algorithms
Repository for my algorithms course


Big O definition:
Let f(n) and g(n) be functions from positive integers to positive reals. We can say that f = O(g) if there is a constant c > 0 such that f <= c * g(n). 

Master theorem:

If T(n) = aT([n/b]) + O(n^d) for some constants a>0, b>1, and d>=0, then

T(n) = O(n^d) if d>logb a
T(n) = O(n^d logn) if d = logb a
T(n) = O(n^(logb a)) if if d < logb a