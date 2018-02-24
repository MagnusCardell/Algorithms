Homework 7   Due Saturday, 2-24-18
A. Background
Designing algorithms is an art, one that benefits from an understanding of time complexity. Some of the algorithms we have seen can be described elegantly-- in just a few English sentences, without any mention of C++ or any other programming language. We would like to have a similarly elegant way to describe the costs of running an algorithm, without having to resort to C++ or assembly or any other programming language. But how would that be possible?

If we want to measure the running time of a pure algorithm, then we can't measure in microseconds, or in clock cycles, or in any similar units, since those quantities will depend on the specifics of a particular implementation on a particular machine. We instead need something more flexible, one where the unit of time (or memory) is not fixed in advance.

Let us consider three C++ functions A, B and C whose time complexities are 500n + 500, 10n2 + 50n + 4, and 2n2 + 1000 respectively.

    1.[C] Which function (A, B, or C) will run fastest for small input sizes? Explain

B will run fastest because of the small overhead costs. A and C both add on large starting point cycles. 

    2.[C] Which function (A, B, or C) will run fastest for large input sizes? Explain

A will run fastest for large input sizes because it is linear, as opposed to B and  C which both are exponential. As input size grow, A(n) will grow linearly, B(n) and C(n) will grow n^2

    3.[C] Suppose these functions all produce the same result, but they are versions of different underlying algorithms. Which of the three algorithms would you prefer to have available, in general? Why?

In general, I would prefer A because of its linear growth in consumption. It is more predictable. 

    4.[C] Suppose these three algorithms were re-implemented in another language, in the context of a different operating system running on different hardware. Would you guess that the running times in the new context would be related to the old running times? If so, how? If not, what assumptions would be needed in order to make a connection?

In general, you could assume that the re-implementation can fulfill the criteria. Because every language compiles to byte code which more or less use the same instructions. In specificity you would have to assume that both implementations use instructions and data structures present in both environments. In principality, these changes should not change how the algorithm runs. 

B. Reading
We would like to have a precise way of comparing the running times of algorithms without having to worry about the exact constants. For example, we might want to be able to say that 500 n + 500 and n are pretty similar (the graph in each case is a straight line) and to say that 10 n2 + 50 n + 4 is not so similar to n (the graph of the former is curved, not straight.) Luckily, there is a mathematically sound way to do this.

Carefully read Chapter 0 of our textbook (Dasgupta, Papadimitriou, and Vazirani) up to section 0.3

    1.[C] After reading about the different ways of computing the fibonacci sequence and giving it some thought can you come up with an idea for a more efficient algorithm than fib2 on Pg.13?

Fib2 stores its values and runs in linear time. Its hard to beat. My only idea that is faster is to have a lookup register or file of all fibonacci values premade. The algorithm would then only perform an array lookup which would result in O(1) since its one constant value who's cost depend on the machine. Drawbacks would be the impossibility of implementation since its an infinite sequence and inifinite memory doesn't exist yet.  

Now carefully read section 0.3, make sure you understand the definitions! We will be using this extensively.

    2.[C] Prove that 500n + 500 is O(n). Be thorough but don't spend a ton of time on this.

Defitinion of Big O says that there exists positive constants c such that f(n) <= c * g(n) for all n. In this case, I want to show that f(n) = 500n + 500 is in the set O(n). 
- 500n+ 500 < 500n + 500n = 1000n. 
- So 500n + 500 = O(n) [c = 1000] for all n>1.


    3.[C] Prove that 2n2 + 1000 is not O(n). That is, show that, no matter what specific value for c is tried, the precise inequality will not be true.

I will prove that there is no constant positive integer c such that 2n^2 + 1000 < c * n. 
- Solving for c gives me: (2n^2 0 1000)/n < c. 
- This equality does not hold since n grows infinitely. C is a constant and therefore the inequality is proven.


    4.[C] What is a question you have about this reading?

Is there a solution key for the problems at the end of the chapters available for students? Would love to check my work. Specificially about the reading, I would like to know why fib2 is classified as running in polynomial time. It seem to me that it should run in linear time since the function runs through every object of the list of length n. Would this not be equal to saying O(n). I can't find the reason it should be O(n^k).
1
C. More essential definitions
The definition above is for upper bounds, but the section briefly introduced two more definitions. Here is the corresponding definition for lower bounds, as follows: the statement that f(n) is Omega(g(n)) means that f(n) is always greater than a scaled version of g(n), for some fixed scaling factor. More precisely,

there exists some scaling factor c, such that for any (positive) value of n, f(n) > c*g(n).

Another way of looking at this definition is that f(n) is O(g(n)) means the same thing as g(n) is Omega(f(n)).

    1.[C] Prove that 500n + 500 is Omega(n+1). That is, provide a specific value for the scaling constant c, and then show that, with this value for c, the relevant inequality is true.

The definition of Omega(n) is that f(n) = Omega(g(n)) if c exists such that and f(n) > c*g(n), where c is a positive integer.
- f(n) = 500n + 500 and g(n) = n+1
- I want to show that 500n + 500 > c * (n+1)
- Solving for c, results in: 500n + 500 / (n+1) > c. 
- Since the function will grow within finity, there exists a constant c that will be smaller than the relationship.
- For example if n = 1, we get (1000 / 2) > c. One example for c is then c = 1. 

    2.[C] Prove that 500n+500 is not Omega(n2). That is, show that, no matter what specific value for c is tried, the relevant inequality will not be true.

Using the definition of Omega(n) where f(n) = 500n + 500 and g(n) = n^2, I want to show that f(n) is not Omega(g(n)) if there is no positive constant c such that 500n + 500 > c * n^2. 
- Solving for c, gives us an unbound function where the function will grow faster than any constant c. Thus the inequality is not true. 

Our final definition, the one we want to use as much as possible, is the combination of O and Omega: the statement that f(n) is Theta(g(n)) means that f(n) is O(g(n)) and f(n) is Omega(g(n)), at the same time.

    3.[C] Prove that 500n + 500 is Theta(n). (This should be easy, you have already done the work!)

First, I will show that 500n + 500 is O(n). From B2 I copy-paste my proof
Defitinion of Big O says that there exists positive constants c such that f(n) <= c * g(n) for all n. In this case, I want to show that f(n) = 500n + 500 is in the set O(n). 
- 500n+ 500 < 500n + 500n = 1000n. 
- So 500n + 500 = O(n) [c = 1000] for all n>1.

Then, I want to show that 500n + 500 is Omega(n) From C1 I copy paste my proof with some modification on g(n)
The definition of Omega(n) is that f(n) = Omega(g(n)) if c exists such that and f(n) > c*g(n), where c is a positive integer.
- f(n) = 500n + 500 and g(n) = n
- I want to show that 500n + 500 > c * (n)
- Solving for c, results in: 500n + 500 / (n) > c. 
- Since the function will grow within finity, there exists a constant c that will be smaller than the relationship.
- For example if n = 1, we get (1000 / 1) > c. One example for c is then c = 1. 

Thus, f(n) = O(n) and Omega(n) which show that f(n) = Theta(n)

    4.[C] Prove that 2n2 + 1000 is not Theta(n).

I will use Big O to disprove that 2n^2 + 1000 is not Theta(n)
- By definition of Big O I want to show that there exists a positive integer c such that 2n^2 + 1000 < c*n.
- However, given n = 3 and c= 1, we get 1118 < 4 which is not true. 
- Thus the relation is not true.

    5.[C] Exercise 0.2, page 9.

g(n) is expressing the geometric formula g(n) c^(n+1) -1 / (c-1)

a)
- If c<1, then the lower bound is when n=0: c-1 / c-1 = 1. The upper bound is when n goes to infinity (Take limit): -1 / c-1 (Because a number less than 1 to the power infinity is 0.). Both of these expressions bind the g(n), we can conclude that g(n) = Theta(1). 

b)
- If c = 1, each term of the geometric series would evaluate to 1. The sum would be n. Therefore g(n) = Theta(n)

c)
- If c > 1, then the lower bound is when n=0: c-1/c-1 The upper bound is when n goes to infinity (take limit): c^n. Both of these expression bind g(n) so we can conclude that g(n) = Theta(c^n).

D. Recursive Functions
Consider the following recursive function: (You have seen something similar in a previous homework!)


void recursion(int n)
{

  for(int i=0;i<100;i++)
  {
    int x = sin(0.8+0.234);
  }

  if (n > 0) {
    recursion(n/2);
    recursion(n/2);
  }
} 

    1.[C] In general, what is the running time of the code in terms of n if we were to run it on the lab computers

Evalutating the inner loop to be a constant cost of 5 cycles per loop, with 100 loops.

In general it will be exponential time: 2^n * 500. 


    2.[C] Lets call your previous answer f. Now define a function g such that g is O(f), but not Omega(f).

g(n) = O(f) but not g(n) = Omega(f) 

If g(n) = n^2, then g(n) <= f(n) while g(n) !> f(n) so it is not Omega(f)

    3.[C] Now define a function g such that g is Omega(f), but not O(f).

if g(n) = 3^n, then g(n) > f(n), while g(n) !< f(n) so it is not Big O(f)

    4.[C] Now define a function g that is Theta(f) in simplest terms. (For example, if your function was 20n + 7 then g would be n )

g(n) = 2^n then g(n) = Theta(f). Where g(n) is in its most simple terms. 