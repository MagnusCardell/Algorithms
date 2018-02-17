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

    2.[C] 

	
```
for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < n/2; ++j ) {
    x = sin(.32);
  }
}
```
	34984

    3.[C] 

	
```
for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < i; ++j ) {
    x = 32*sin(.32);
  }
}
```
	52016

    4.[C] 

	
```
for ( int i = 0; i < n; ++i ) {
  for ( int j = i; j < n; ++j ) {
    x = 38 + 29*(348*tan(.328));
  }
}
```
	36376

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
```
C. Actual Timing for a Recursive Function

    1.[C] Now choose one of the recursive snippets from part B at random and actually time it (by making an appropriate C++ program). Please submit your code via git (if you do not have a repository for this class please let us know), and write down a comment about whether the result was high or low, and why you think that might be on your homework page. (With everyone choosing a problem at random, I'm hoping that all or almost all of the problems will have been checked by somebody.)