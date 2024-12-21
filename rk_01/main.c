#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

#define SUCCESS 0
#define FAIL 1



#define MAX_STR_LEN 256 

int read_file(char *path, word_and_count_t *words)
{
    FILE *fr = fopen(path, "r");
    int n = 0;
    char str[MAX_STR_LEN];

    while(fscanf(fr, "%s", str) == 1)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
            if (strncmp(words[i].word, str, strlen(words[i].word) > strlen(str) ? strlen(str) : strlen(words[i].word)) == 0)
                words[i].count += 1, flag = 1;

        if (!flag)
        {
            void *tmp_p = realloc(words, sizeof(word_and_count_t) * (n + 1));
            if (tmp_p == NULL)
            {    
                return FAIL;
            }
            words = tmp_p;

            char *tmp_s = malloc(strlen(str));
            if (tmp_s == NULL)
            {
                return FAIL;
            }
            strncpy(tmp_s, str, strlen(str));
            words[n].count = 1;

            words[n].word = tmp_s;
            // puts(words[n].word);
            n++;
        }
    }

    FILE *fw = fopen("out.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%s: %d\n", words[i].word, words[i].count);
}
    return n;
}


// void write_file(char *path, word_and_count_t *words, int n)
// {
//     for (int i = 0; i < n; i++)
//         printf("%s: %d\n", words[i].word, words[i].count);
// }

int main(void)
{
    int rt = SUCCESS;

    word_and_count_t *words = NULL;

    int n = read_file("in.txt", words);

    if (words != NULL)
        for (int i = 0; i < n; i++)
            free(words+i);
    // write_file("out.txt", words, n);

    return rt;
}