A. Estimating Total Cycles for Loops
For each of the code snippets below, the number of cycles for n = 100 is given. Given both the code and this first timing result, estimate the number of cycles for n = 1000. Don't actually time it-- just think through, on paper, what would happen. Then on your homework page, write down your estimate, and say briefly (in about a sentence) why you came to the conclusion you did. Please provide an estimate for each of the eight snippets below.
exercise 	code 	cycles for n = 100

    1.[C] 

```
for ( int i = 0; i < n; ++i ) {
  x = 2+3;
}
```

976 
Since the loop has a fixed number of cycles per loop, the total will grow linearly. 
If n=1000, cycles will be 9760

    2.[C] 

	
```
for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < n/2; ++j ) {
    x = sin(.32);
  }
}
```
34984
Compiling the code into a formula, the total cost simplified can be expressed 1.5n + 2.5(n)^2
n(100) = 25.150 and n(1000)=2.501.500 cycles. The growth is exponential

    3.[C] 

	
```
for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < i; ++j ) {
    x = 32*sin(.32);
  }
}
```
52016
Total cost can be estimated simplified to about 4(n)^2
n(100) = 40.000
n(1000) = 4.000.000, or using the provided estimate: 5.201.600 cycles

    4.[C] 

	
```
for ( int i = 0; i < n; ++i ) {
  for ( int j = i; j < n; ++j ) {
    x = 38 + 29*(348*tan(.328));
  }
}
```
36376
Simplifying the code into an estimated formula where the inner body is iterated n^2 times so about 4n^2
n(100)= 40.000
n(1000) = 4.000.000, or using the provided estimate: 3.637.600
    
    5.[C] 

	
```
for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < i/2; ++j ) {
    x = 2398 * 2948 + 3498 * 3948 + 39843 * atan2(32,49);
  }
  i = i + 2;
}
```
9088
Simplifying the inner body to iterate about 0.25n^2 times, and the inner-most cycle to add another .5(n)

body to be worth about 4 cycles, totalling in n^2 cycles.
n(100) = 10.000
n(1000) = 1.000.000 cycles or using the provided estimate: 908.800 cycles

    6.[C] 

	
```
for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < n/2; ++j ) {
    for ( int k = 0; k < n; ++k ) {
      x = 5*x - 4;
    }
  }
}
```
7107660
The three loops can be estimated to iterate n(0.5n(n)) times, which is 1.5n^3. With a body worth about 4 cycles then:
n(100) = 6.000.000 cycles
n(1000) = 6 * 10^9 cycles

    7.[C] 
	
```
for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < i; ++j ) {
    for ( int k = 0; k < j; ++k ) {
      x = x + 5;
    }
  }
}
```
1552300
Using the formula for the area of a tetrahydral plane, (n(n+1)(n+2))/6, the inner-most loop will iterate a total of n^3+3n^2+2n times.
With a body cycle value of 1, and only taking the cubic parameter into account:
n(100) = 1.000.000
n(1000) = 10^9 cycles or using the provided estimate, 1,5523 *10^9 cycles

    8.[C] 
	
```
for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < i/2; ++j ) {
    for ( int k = 0; k < j; ++k ) {
      x = x + 5;
    }
  }
}
```
529056
Considering that this algorithm runs in n^3, an estimate would be that n(1000)= 0.529056* 10^9.

B. Estimating Total Cycles for Recursive Functions
For each of the code snippets below, assume the function is called with n = 100, and predict the number of clock cycles you would get from timing it. Don't actually time it yet-- just think through, on paper, what would happen. Then on your homework page, write down your estimate, and say briefly (in about a sentence) why you came to the conclusion you did. Please provide an estimate for each of the seven snippets below.

    1.[C]
```
    void recursion(int n)
    {
      double x = 2 * 3;
      x = x * 3;
     
      if (n > 0)
        recursion(n - 1);
    }
```
The recursion will be called 100 times, each with a heap stack value of 20 cycles. Total estimate is then 20* 100 = 2000 cycles.

    2.[C]
```
    void recursion(int n)
    {
      double x = 2 * 3;
      x = x * 3;
     
      if (n > 0)
        recursion(n/2);
    }
```
Every stack heap divide n by 2. When n = 100, it can be divided 7 times before its 1. With a node value of 20 cycels, the number of cycles can be estimated to 20*7 = 140 cycles.

    3.[C]
```
    void recursion(int n)
    {
      double x = 2 * 3;
      x = x * 3;
     
      if (n > 0)
        recursion(n/3);
    }
```
With n=100, the hight of the recursive tree willl be 5, so with every node wort 20 cycles, an estimated total is 20*5 = 100 cycles. 

    4.[C]
```
    void recursion(int n)
    {
      double x = 2 * 3;
      for ( int i = 0; i < n; ++i ) {
        x = 2+3;
      }
     
      if (n > 0)
        recursion(n/2);
    }
```
First, the number of nodes are 7. Each loop performs iterations according to the value of n. Estimating a generalized node value of n=12, each node is then worth ~32 cycles, coming to a total of 32*7 = 224 cycles 

    5.[C]
```
    void recursion(int n)
    {
      double x = 2 * 3;
      for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < i; ++j ) {
          x = 32*sin(.32);
        }
      }
     
      if (n > 0)
        recursion(n/2);
    }
```
With the same generalization as before, I estimate n = 12, each node is now worth ~92 cycles with a total estimate of 92*7 = 644 cycles

    6.[C]
```
    void recursion(int n)
    {
      double x = 2 * 3;
      for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n/2; ++j ) {
          for ( int k = 0; k < n; ++k ) {
            x = 5*x - 4;
          }
        }
      }
     
      if (n > 0)
        recursion(n/3);
    }
```
With the same generalization as before, I estimate n = 12, each node is now worth 436 cycles, coming to a total of 426*5 = 2130 cycles

    7.[C]
```
    void recursion(int n)
    {
      double x = 2 * 3;
      x = x * 3;
     
      if (n > 0) {
        recursion(n/2);
        recursion(n/2);
      }
    }
This binary tree will be of maximum size, where the number of nodes can be calculated with 2^(n+1)-1. Here n=7 due to the amount 100 can be divided. So number of nodes are 255, each node is worth about 20 cycles. Total cycles is then 20 *255 = 5100 cycles

```
C. Actual Timing for a Recursive Function

    1.[C] Now choose one of the recursive snippets from part B at random and actually time it (by making an appropriate C++ program). Please submit your code via git (if you do not have a repository for this class please let us know), and write down a comment about whether the result was high or low, and why you think that might be on your homework page. (With everyone choosing a problem at random, I'm hoping that all or almost all of the problems will have been checked by somebody.)

I chose no3, which timed to 392 cycles. My estimate was 100cycles which was low. I think I am missing some cycles that gather up at the return statment after the last node. I also see a lot of fluctuation in the timer, a second run gives me 640 and a third 424 so it may be that the number of cycles is dependent on the tasks the processor is doing in parallel. 