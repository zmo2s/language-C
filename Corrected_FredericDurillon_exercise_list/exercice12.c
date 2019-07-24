
/*
$ cat ../dat/captnjack.txt
This is a tale
Of Captain Jack Sparrow
A Pirate So Brave
On the Seven Seas.
Test Use

$ ./bin/llwordcount ../dat/captnjack.txt dat/llout.txt
Output File

$ cat dat/llout.txt
this 1
is 1
a 2
tale 1
of 1
captain 1
jack 1
sparrow 1
pirate 1
so 1
brave 1
on 1
the 1
seven 1
seas 1
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct s_words {
    char *str;                  //word
    int count;                  //number of times word occurs
    struct s_words *next;       //pointer to next word
} words;

words *create_words (char *word)
{
    //+allocate space for the structure
    printf ("%lu ", strlen (word));
    words *newWord = malloc (sizeof (words));
    if (NULL != newWord) {
        //+allocate space for storing the new word in "str"
        //+if str was array of fixed size, storage wud be wasted
        newWord->str = (char *) malloc ((strlen (word)) + 1);
        strcpy (newWord->str, word);    //+copy “word” into newWord->str
        newWord->str[strlen (word)] = '\0';
        printf (" Create: %s ", newWord->str);
        //+initialize count to 1;
        newWord->count = 1;
        //+initialize next;
        newWord->next = NULL;
    }
    return newWord;
}

words *add_word (words **wordList, char *word)
{
    if (!*wordList) {       /* handle EMPTY list */
        printf ("NEW LIST\n");
        return *wordList = create_words (word);
    }

    words *temp = *wordList;
    //+ search if word exists in the list; if so, make found=1
    while (temp->next != NULL) {    /* iterate while temp->next != NULL */

        if (strcmp (temp->str, word) == 0) {    //+use strcmp command
            temp->count = temp->count + 1;      //+increment count;
            return *wordList;
        }
        else
            temp = temp->next;  //+update temp
    }
    words *newWord = create_words (word);
    if (NULL != newWord) {  /* insert at TAIL of list */
        temp->next = newWord; 
        printf (" NEW WORD: %s\n ", newWord->str);
    }
    return newWord;
}

int main (int argc, char *argv[]) {

    words *mywords;             //+head of linked list containing words
    mywords = NULL;
    char *delim = ". ,:;\t\n";

    FILE *myFile;
    FILE *myOutput;

    char *filename = argv[1];
    char *outputfile = argv[2];

    if (argc != 3) {
        fprintf (stderr, "error: insufficient input. usage: %s ifile ofile\n",
                argv[0]);
        return 1;
    }

    myFile = fopen (filename, "r");     //+first parameter is input file
    if (myFile == 0) {
        printf ("file not opened\n");
        return 1;
    } else {
        printf ("file opened \n");
    }

    //+start reading file character by character;
    //+when word has been detected; call the add_word function

    int ch = 0, word = 1, k = 0;
    char thisword[100];
    while ((ch = fgetc (myFile)) != EOF) {  /* for each char    */
        if (strchr (delim, ch)) {           /* check if delim   */
            if (word == 1) {    /* if so, terminate word, reset */
                word = 0;
                thisword[k] = '\0';

                printf ("\nadd_word (mywords, %s)\n", thisword);
                /* do NOT overwrite list address each time,
                 * you must send ADDRESS of list to add_word
                 * to handle EMPTY list case.
                 */
                if (add_word (&mywords, thisword))
                    printf (" added: %s\n", mywords->str);
                else
                    fprintf (stderr, "error: add_word failed.\n");

                k = 0;
            }
        }
        else {  /* if not delim, add char to string, set word 1 */
            word = 1;
            thisword[k++] = tolower (ch);   /* make ch lowercase */
        }
    }
    if (word == 1) {    /* handle non-POSIX line-end */
        thisword[k] = '\0';
        //add thisword into the list
        printf ("\nadd_word (mywords, %s) (last)\n", thisword);
        if (add_word (&mywords, thisword))  /* same comment as above */
            printf (" added: %s\n", mywords->str);
        else
            fprintf (stderr, "error: add_word failed.\n");
    }

    words *currword;
    printf ("printing list\n");

    //+Traverse list and print each word and its count to outputfile
    //+output file is second parameter being passed

    myOutput = fopen (outputfile, "w+");        //+first parameter is input file
    if (myOutput == 0) {
        printf ("output file not opened \n");
        return 1;
    } else {
        printf ("output file opened \n");
    }

    currword = mywords;

    while (currword != NULL) {  /* just test currword here */
        //add word name then word count to file, then move to next
        fprintf (myOutput, "%s %d \n", currword->str, currword->count);
        printf ("%s ", currword->str);
        currword = currword->next;
    }

    putchar ('\n');
    return 0;
}