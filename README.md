Parallel Primes Project

This is the first project for my operating systems course

This program counts the number of prime numbers in a specified range.

Some useful information. For a C to vs code install guide go here https://www.freecodecamp.org/news/how-to-write-and-run-c-cpp-code-on-visual-studio-code/ 

To run code do gcc -o filename filename.c
After this on windows type filename 
On linux type ./filename

Keep in mind file name means the filename without the .c extension

What Does This Project Do?
  This program counts the number of prime numbers in a given range.
  
  What makes this program unique is that it takes a file, countprimes which when really large ranges are given runs very slow.
  With countprimes the addition of the countmaster file into the program allows large ranges without running slow.
  
  This is achieved by using parallel programming in countmaster. countmaster takes the range divides it into pieces and calls
  countprimes on each piece and finally tallying up the results, this allows for a streamlined and effecient program that 
  allows you to see the number of prime numbers in very large ranges. 

