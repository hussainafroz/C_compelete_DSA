/*
LAB_PROGRAM_2 : Design,Develop and Impliment a
program in C for the following operations on
strings.
a) Read a main string(STR), a pattern string(PAT)
and a Replace string(REP)
b) Perform pattern matching operation: Find and
replace all occurances of PAT in STR with REP.
if PAT exists in STR. Report suitable messages in
case PAT does not exists in STR.
Support the program with functions for each of the
above operations. Don't use built in functions !!.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

int string_match(char [], char[],char[],char[]);

int main()
{
    char src[MAX],pat[MAX],rep[MAX],final[MAX];
    int found;

    printf("Enter source string\n");
    gets(src);
    printf("Enter pattern string\n");
    gets(pat);
    printf("Enter replace string\n");
    gets(rep);

    found = string_match(src,pat,rep,final);
    if (found == 1)
    {
        printf("The final string >\n");
        puts(final);
    }
    else
    printf("search string NOT found\n");

    return 0;
}


/* Function to search and replace the
pattern string with replace string*/

int string_match(char src[], char pat[], char rep[], char final[])
{
    int i,j,k,m,t; // i > src_counter , j > pattern_counter , k > replace_counter , t > final_counter
    int found = 0;
    j=m=i=t=0;
    for(;src[i] != '\0';)
    {
        if (src[m++] == pat[j++]) // check for matching
        {

            if (pat [j] == '\0') // pattern found
            {
                // copy replace string in final string
                for (k=0; rep[k] != '\0';)
                {
                final[t++] = rep[k++];
                j=0;
                i=m;
                found = 1;
               }
            }
        }
        else // mismatch
        {
            final[t++] = src[i++];
            m=i;
            j=0;
        }
    }
    final[t]='\0';
    return found;
}
