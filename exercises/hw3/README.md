Homework 3   Due Thursday, 2-15-18
A. Estimating Total Cycles
For each of the code snippets below, assume n = 100, and predict the number of clock cycles you would get from timing it. Don't actually time it yet-- just think through, on paper, what would happen. Then on your homework page, write down your estimate, and say briefly (in about a sentence) why you came to the conclusion you did. Please provide an estimate for each of the eleven snippets below.

    1.[C]

    for ( int i = 0; i < n; ++i ) {
      x = 2+3;
    }

    2.[C]

    for ( int i = 0; i > n; ++i ) {
      x = 2+3;
    }

    3.[C]

    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < n/2; ++j ) {
        x = sin(.32);
      }
    }

    4.[C]

    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i; ++j ) {
        x = 32*sin(.32);
      }
    }

    5.[C]

    for ( int i = 0; i < n; ++i ) {
      for ( int j = i; j < n; ++j ) {
        x = 38 + 29*(348*tan(.328));
      }
    }

    6.[C]

    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i/2; ++j ) {
        x = 2398 * 2948 + 3498 * 3948 + 39843 * atan2(32,49);
      }
      i = i + 2;
    }

    7.[C]

    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i/2; ++j ) {
        i = i + 1;
      }
    }

    8.[C]

    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i/2; ++j ) {
        i = i + 2;
      }
    }

    9.[C]

    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i; ++j ) {
        for ( int k = 0; k < j; ++k ) {
          x = x + 5;
        }
      }
    }

    10.[C]

    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i; ++j ) {
        for ( int k = 0; k < j; ++k ) {
          k = k*2;
        }
      }
    }

    11.[C]

    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i; ++j ) {
        for ( int k = 0; k < j; ++k ) {
          j += k;
        }
      }
    }

B. Actual timing

    1.[C] Now choose one of these snippets at random and actually time it (by making an appropriate C++ program). Paste your code, and the result of timing, into your homework page, along with a comment about whether the result was high or low, and why you think that might be. (With everyone choosing a problem at random, I'm hoping that all or almost all of the problems will have been checked by somebody.)