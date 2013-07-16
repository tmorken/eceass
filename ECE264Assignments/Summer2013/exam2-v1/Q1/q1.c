/*
  PROBLEM: Write a program that reads data from two input files and
  writes the result to another file.

  INPUT: One of the two input files is text.  The other is binary.
  Both files contains some integers.  Your program needs to read the
  integers one by one and add them together.  In the binary file, the
  integers follow after each other.  In the text file, the integers
  may come alone on separate lines, or after each other on the same
  line.

  HINT: fscanf() ignores whitespace (end of line, space, etc).

  OUTPUT: The sum of these integers is written to a text file (write
  the number followed by a newline).

  TEST: run "make test" to test your output---the diff should exit
  with no errors.

  You do not know the numbers of integers in each input file.
  Therefore, your program must keep reading until all integers in the
  two files have been read.

  argv[1]: the name of the text input file
  argv[2]: the name of the binary input file
  argv[3]: the name of the text output file
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // FILL IN CODE HERE!
    
    return EXIT_SUCCESS;
}
