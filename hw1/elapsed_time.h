#ifndef _ELAPSED_TIME_
#define _ELAPSED_TIME_
 
#include<iostream>
#include<stdlib.h>
using std::cerr;
using std::endl;
 
u_int64_t start_time;  // might have to use uint64_t
 
inline                                                                          
u_int64_t read_TSC()                                                                  
{                                                                               
    register u_int64_t rax asm("rax");                                            
    register u_int64_t rdx asm("rdx");                                            
    asm volatile ("rdtsc"                                                       
                  : "=r" (rax), "=r" (rdx));                                    
    rax |= rdx << 32;                                                           
    return rax;                                                                 
}
 
inline
void start_timer()
{
  start_time = read_TSC();
}
 
inline
double elapsed_time()
{
  u_int64_t curr_time = read_TSC();
  double elapsed = curr_time - start_time;
  return elapsed;
}
#endif