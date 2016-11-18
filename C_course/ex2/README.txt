Theoretical Questions 

Answers:

1. Output: 
26
26

2. The problem is with: char *str = “Hellp world”;
   when we define a pointer to a sequence of chars and assigning a string literal to it
   the string is stored in read-only memory (like .rodata). So when doing str[4] = ‘o’;
   we’re trying to overwrite read-only value which is undefined and will throw a ‘bus  error 10’.
   
   Changing the first declaration to: char str[] = “Hellp world”; , will fix the problem. 