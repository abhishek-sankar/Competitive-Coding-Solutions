/*
Write a program that does what the following program does:

                                     >,<>>,>,<[->-               
                                  >+<><<]+->>[-<<+>>]            
                                <+-><><<<[-+->-<+-<+>]<          
                               [->+<]><>>>>>><>++->>+->>         
                              >>>+[>><>>>[-]<[-<>-+]<<>[-        
                             +-]-++-+-<         [-]<><<>[+       
                            ---+]<><<             <<+-<<<<>      
                           -+<><<<>                 <+-<<[->     
                          >>>>>>+                     >>>>>-+    
                         >+<<<><            <          <><<<<<   
                        <<<<]>[           ->>           >>><><>  
                       ><>>+>>          >>>>+            <<<<<>< 
                      <<<<+-<           <<<]>             [->>>>>
                                        >><>+                    
                                        >>>>-                    
                                        +><>>                    
                                        +<<<<                    
                                        <<+-<                    
         <<<><<<<        -+><]     >>-++-+>+-+[<-]      <[->>    
      <>++-<<<]>>>>      [-<<<     +--+<<<<+>><>>>      >>>]>    
     [-<<-+<<<<<+<>>     +->>>     >>>]>[-<<<<><<<      ><<+>    
    >>>>>>]>>>>>><>>+    [-<<<     <+--+<><+-<<<<<      <[->>    
   +>>+<<<<]+->[->>+>>   +-+<<     <<]>[-<<+>>]>[-      <<+>>    
  ]+[[<>-]-++>[<-]<+-[   +--><     >><>-<<<]>>-+->      >>+>[    
 <-]<+-[-       >+>[-    <-]<[          >>[-<           <-+->    
 ]-<<[->         ><-     >+->-          +-<<<           <]]<]    
 >>-<<<           <      <+>[>          <<-]<           [>+->    
[-+<<-                   >]<<[          <]]>-           +-]>>    
>>><>>                   >><>+          ]-<<<           >+-<<    
<>+>-                    ++[<-          ]<[-+           >>+[<    
<<>->                    -+]<<          [>>>+           [<-+<    
<->>]                    <<<[<          ]]]>-           ]>>>>    
[-]<<                    <<<<<          -+<><           <<<<<    
<[-]>                    >+>+[          <-]<[           ->>+<    
><<<]                    >+>[<          -]<[>           >[<<-    
>]<<[                    <]]>-          [+>>>           >>>><    
++-++                    +++++          ++<<<           <<<+>    
+-[<<>                   -]<[>          >[<<-           >]<<[    
<]]>-[                   ++>[<          -]<[-           >>-<<    
 <]>>->           >      +>>+>          -[<-]           <[<<[    
 ->>>+<<         ><<     ]+->>          >>>+>           +[<><    
 -]<><[->       >+<<<    ]<<-<          ]<<<<           +>[<-    
  ]<[>>[<<->]<<[<]]>-]   >>+++          +++++[   ->     +++++    
   +<]>[-<<<<+>>>>]>>>   >>+><          >-+[<-]<[>>     [<<->    
    ]<<[<]]>-[++>[<-]    <[->>          -<<<]>>-<<<     <<<<<    
     +>+[<-]<[->>+<<     <]>>>          >>>>>+>[<-      ]<[>>    
      [<<->]<<[<]]>      -]<<[           -]<<<<<+>      [<-]<    
         [>>[<<->        ]<<[<            ]]>-]<<       [.<]!    





Hint: I gave no one real evidence. Furin is not dielectric; and not a great random acoustic magnet; oxidized filovirus; towards human enzyme; this is to lure enigma.


Standard input
The first line contains an integer TT, the number of test cases.

The next TT lines each contain a string of three printable ASCII characters representing one test case.

Standard output
For each test case, print the output of the given program on a single line.


Constraints and notes
1 \leq T \leq 101≤T≤10
A printable ASCII character has an unsigned 88-bit integer value between 3333 and 126126.

Input	Output
4
xxx
XXX
***
<=>
12
90
44
4
2
0>?
dkx
264
884
*/

#include <bits/stdc++.h>

#define fastio() \
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

const int N = int(1e3);
unsigned char cells[N];

void func(unsigned char *p) {
  unsigned char *cell = cells;
  unsigned char x;
//   ++cell;
//   *cell = p[0];
//   ++cell;
//   *cell = p[1];
//   ++cell;
//   *cell = p[2];
//   --cell;
//   x = *cell;
//   *cell = 0;
//   ++cell;
//   *cell -= x;
//   ++cell;
//   *cell += x;
//   x = *cell;
//   *cell = 0;
//   cell -= 2;
//   *cell += x;
//   --cell;
//   x = *cell;
//   *cell = 0;
//   ++cell;
//   *cell -= x;
//   cell -= 2;
//   *cell += x;
//   x = *cell;
//   ++cell;
//   *cell += x;
//   --cell;
//   *cell = 0;
//   cell += 6;
//   ++*cell;
//   cell += 7;
//   ++*cell;
  while (*cell) {
    cell += 4;
    *cell = 0;
    --cell;
    *cell = 0;
    --cell;
    *cell = 0;
    --cell;
    *cell = 0;
    --cell;
    *cell = 0;
    cell -= 12;
    x = *cell;
    *cell = 0;
    cell += 7;
    *cell += x;
    cell += 6;
    *cell += x;
    cell -= 12;
    x = *cell;
    *cell = 0;
    cell += 7;
    *cell += x;
    cell += 6;
    *cell += x;
    cell -= 12;
    x = *cell;
    *cell = 0;
    cell += 7;
    *cell += x;
    cell += 6;
    *cell += x;
    cell -= 11;
    ++*cell;
    ++cell;
    ++*cell;
    while (*cell) {
      --cell;
      --*cell;
    }
    --cell;
    while (*cell) {
      --*cell;
      cell += 2;
      ++*cell;
      cell -= 3;
    }
    cell += 4;
    x = *cell;
    *cell = 0;
    cell -= 7;
    *cell += x;
    cell += 8;
    x = *cell;
    *cell = 0;
    cell -= 7;
    *cell += x;
    cell += 8;
    x = *cell;
    *cell = 0;
    cell -= 7;
    *cell += x;
    cell += 14;
    ++*cell;
    while (*cell) {
      --*cell;
      cell -= 11;
      x = *cell;
      *cell = 0;
      cell += 2;
      *cell += x;
      cell += 2;
      *cell += x;
      cell -= 3;
      x = *cell;
      *cell = 0;
      cell += 2;
      *cell += x;
      cell += 2;
      *cell += x;
      cell -= 3;
      x = *cell;
      *cell = 0;
      cell -= 2;
      *cell += x;
      cell += 3;
      x = *cell;
      *cell = 0;
      cell -= 2;
      *cell += x;
      cell += 2;
      ++*cell;
      while (*cell) {
        *cell = 1;
        ++cell;
        while (*cell) {
          --cell;
          --*cell;
        }
        --cell;
        while (*cell) {
          --*cell;
          cell += 2;
          --*cell;
          cell -= 3;
        }
        cell += 2;
        --*cell;
        cell += 3;
        ++*cell;
        ++cell;
        while (*cell) {
          --cell;
          --*cell;
        }
        --cell;
        while (*cell) {
          --*cell;
          ++cell;
          ++*cell;
          ++cell;
          while (*cell) {
            --*cell;
            --cell;
            --*cell;
          }
          --cell;
          while (*cell) {
            cell += 2;
            while (*cell) {
              --*cell;
              cell -= 2;
              --*cell;
              ++cell;
            }
            --*cell;
            cell -= 2;
            while (*cell) {
              --*cell;
              ++cell;
              --*cell;
              cell += 2;
              --*cell;
              cell -= 4;
            }
          }
          --cell;
        }
        cell += 2;
        --*cell;
        cell -= 5;
        ++*cell;
        ++cell;
        while (*cell) {
          --cell;
          --*cell;
        }
        --cell;
        while (*cell) {
          cell += 2;
          while (*cell) {
            cell -= 2;
            --*cell;
            ++cell;
          }
          cell -= 2;
          while (*cell) {
            --cell;
          }
        }
        ++cell;
        --*cell;
      }
      cell += 8;
      ++*cell;
    }
    --*cell;
    cell -= 4;
    ++*cell;
    ++cell;
    ++*cell;
    while (*cell) {
      --cell;
      --*cell;
    }
    --cell;
    while (*cell) {
      cell += 2;
      ++*cell;
      while (*cell) {
        cell -= 2;
        --*cell;
        ++cell;
      }
      cell -= 2;
      while (*cell) {
        cell += 3;
        ++*cell;
        while (*cell) {
          cell -= 3;
          --*cell;
          cell += 2;
        }
        cell -= 3;
        while (*cell) {
          --cell;
        }
      }
    }
    ++cell;
    --*cell;
  }
  cell += 4;
  *cell = 0;
  cell -= 14;
  *cell = 0;
  cell += 2;
  ++*cell;
  ++cell;
  ++*cell;
  while (*cell) {
    --cell;
    --*cell;
  }
  --cell;
  while (*cell) {
    --*cell;
    cell += 2;
    ++*cell;
    cell -= 3;
  }
  ++cell;
  ++*cell;
  ++cell;
  while (*cell) {
    --cell;
    --*cell;
  }
  --cell;
  while (*cell) {
    cell += 2;
    while (*cell) {
      cell -= 2;
      --*cell;
      ++cell;
    }
    cell -= 2;
    while (*cell) {
      --cell;
    }
  }
  ++cell;
  --*cell;
  while (*cell) {
    ++*cell;
    cell += 6;
    *cell += 10;
    cell -= 6;
    ++*cell;
    ++cell;
    ++*cell;
    --*cell;
    while (*cell) {
      --cell;
      --*cell;
    }
    --cell;
    while (*cell) {
      cell += 2;
      while (*cell) {
        cell -= 2;
        --*cell;
        ++cell;
      }
      cell -= 2;
      while (*cell) {
        --cell;
      }
    }
    ++cell;
    --*cell;
    while (*cell) {
      *cell += 2;
      ++cell;
      while (*cell) {
        --cell;
        --*cell;
      }
      --cell;
      while (*cell) {
        --*cell;
        cell += 2;
        --*cell;
        cell -= 3;
      }
      cell += 2;
      --*cell;
      cell += 2;
      ++*cell;
      cell += 2;
      ++*cell;
      ++cell;
      --*cell;
      while (*cell) {
        --cell;
        --*cell;
      }
      --cell;
      while (*cell) {
        cell -= 2;
        x = *cell;
        *cell = 0;
        cell += 3;
        *cell += x;
        cell += 2;
        ++*cell;
        ++cell;
        ++*cell;
        while (*cell) {
          --cell;
          --*cell;
        }
        --cell;
        while (*cell) {
          --*cell;
          cell += 2;
          ++*cell;
          cell -= 3;
        }
        cell -= 2;
        --*cell;
        --cell;
      }
      cell -= 4;
      ++*cell;
      ++cell;
      while (*cell) {
        --cell;
        --*cell;
      }
      --cell;
      while (*cell) {
        cell += 2;
        while (*cell) {
          cell -= 2;
          --*cell;
          ++cell;
        }
        cell -= 2;
        while (*cell) {
          --cell;
        }
      }
      ++cell;
      --*cell;
    }
    cell += 2;
    *cell += 8;
    x = *cell;
    *cell = 0;
    ++cell;
    *cell += 6 * x;
    x = *cell;
    *cell = 0;
    cell -= 4;
    *cell += x;
    cell += 9;
    ++*cell;
    ++cell;
    while (*cell) {
      --cell;
      --*cell;
    }
    --cell;
    while (*cell) {
      cell += 2;
      while (*cell) {
        cell -= 2;
        --*cell;
        ++cell;
      }
      cell -= 2;
      while (*cell) {
        --cell;
      }
    }
    ++cell;
    --*cell;
    while (*cell) {
      *cell += 2;
      ++cell;
      while (*cell) {
        --cell;
        --*cell;
      }
      --cell;
      while (*cell) {
        --*cell;
        cell += 2;
        --*cell;
        cell -= 3;
      }
      cell += 2;
      --*cell;
      cell -= 8;
      ++*cell;
      ++cell;
      ++*cell;
      while (*cell) {
        --cell;
        --*cell;
      }
      --cell;
      while (*cell) {
        --*cell;
        cell += 2;
        ++*cell;
        cell -= 3;
      }
      cell += 8;
      ++*cell;
      ++cell;
      while (*cell) {
        --cell;
        --*cell;
      }
      --cell;
      while (*cell) {
        cell += 2;
        while (*cell) {
          cell -= 2;
          --*cell;
          ++cell;
        }
        cell -= 2;
        while (*cell) {
          --cell;
        }
      }
      ++cell;
      --*cell;
    }
    cell -= 2;
    while (*cell) {
      --*cell;
    }
    cell -= 5;
    ++*cell;
    ++cell;
    while (*cell) {
      --cell;
      --*cell;
    }
    --cell;
    while (*cell) {
      cell += 2;
      while (*cell) {
        cell -= 2;
        --*cell;
        ++cell;
      }
      cell -= 2;
      while (*cell) {
        --cell;
      }
    }
    ++cell;
    --*cell;
  }
  cell -= 2;
  while (*cell) {
    cout << *cell;
    --cell;
  }
}

int main() {
  fastio();
  int t;
  unsigned char p[4];
  cin >> t;
  while (t--) {
    cin >> p;
    memset(cells, 0, sizeof cells);
    func(p);
    cout << '\n';
  }
  return 0;
}
