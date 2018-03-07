# Algorithms
Repository for my algorithms course


Big O definition:

Defitinion of Big O says that there exists positive constants c such that f(n) <= c * g(n) for all n.

Master theorem:

If T(n) = aT([n/b]) + O(n^d) for some constants a>0, b>1, and d>=0, then

T(n) = O(n^d) if d>logb a
T(n) = O(n^d logn) if d = logb a
T(n) = O(n^(logb a)) if if d < logb a