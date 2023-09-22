#include <stdio.h>
#include <stdlib.h>

int main() {
    char* arguments[4];			//make an array that can hold up to 4 strings
    arguments[0]="./countprimes";	//the first string is the command name
    arguments[1]="10";			//the second and third strings are the start and end parameters
    arguments[2]="30";
    arguments[3]=NULL;			//the last argument must be a null terminator
    execvp("./countprimes",arguments);	//call the countprimes child program
}