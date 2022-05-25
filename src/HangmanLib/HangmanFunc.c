#include "HangmanLib.h"

void greetings()
{
    printf("Hello!\n");
    printf("Be careful, you may be hanged!\n");
    printf("Rules: \n");
    printf(" - You can make 8 mistakes.\n");
    printf(" - You can enter Latin characters in any case.\n");
}

int getrand()
{
    int r;
    srand(time(NULL));
    r = rand();
    return r % 20;
}

int rand_word(char *array, char *word, int rand)
{
    int i = 0, counter = 0;
    for (; counter != rand; i++)
    {
        if (array[i] == ' ')
        {
            counter++;
        }
    }
    int lw = 0;
    for (; array[i] != ' '; i++)
    {
        word[lw] = array[i];
        lw++;
    }
    word[lw] = '\0';
    return strlen(word);
}

void print_hangman(int mistakes)
{
    switch (mistakes)
    {
    case 1:
        printf("      |\n      |\n      |\n      |\n      |\n______|\n \n");
        break;
    case 2:
        printf(" _____\n |    |\n      |\n      |\n      |\n      |\n______|\n \n");
        break;
    case 3:
        printf(" _____\n |    |\n o    |\n      |\n      |\n      |\n______|\n \n");
        break;
    case 4:
        printf(" _____\n |    |\n o    |\n |    |\n ^    |\n      |\n______|\n \n");
        break;
    case 5:
        printf(" _____\n |    |\n o    |\n/|    |\n ^    |\n      |\n______|\n \n");
        break;
    case 6:
        printf(" _____\n |    |\n o    |\n/|\\   |\n ^    |\n      |\n______|\n \n");
        break;
    case 7:
        printf(" _____\n |    |\n o    |\n/|\\   |\n ^    |\n/     |\n______|\n \n");
        break;
    case 8:
        printf(" _____\n |    |\n o    |\n/|\\   |\n ^    |\n/ \\   |\n______|\n \n");
        break;
    }
}

void word_guess(char *word, int len)
{
    char letter[1];
    bool flag = 0;
    int mistakes = 0;
    char cells[len];
    char used_letters[len + 20];
    int ul = 0;
    bool letter_repeat = 0;
    for (int i = 0; i < len; i++)
    {
        cells[i] = '_';
    }
    cells[len] = '\0';
    printf("%s\n", cells);
    while (strcmp(word, cells) != 0)
    {
        printf("Enter a letter\n");
        scanf("%s", letter);
        letter[0] = tolower(letter[0]);
        if ((letter[0] < 'a') || (letter[0] > 'z'))
        {
            printf("Invalid character! Enter a letter!\n");
            continue;
        }
        letter_repeat = 0;
        for (int i = 0; i < ul; i++)
        {
            if (letter[0] == used_letters[i])
            {
                letter_repeat = 1;
            }
        }
        if (letter_repeat == 1)
        {
            printf("You have already entered this letter! Please enter another letter!\n");
            continue;
        }
        else
        {
            used_letters[ul] = letter[0];
            ul++;
        }
        for (int i = 0; i <= len; i++)
        {
            if (word[i] == letter[0])
            {
                cells[i] = letter[0];
                flag = 1;
            }
        }
        if (flag == 0)
        {
            mistakes++;
            printf("Mistake!\n");
            print_hangman(mistakes);
        }
        printf("%d\n", mistakes);
        if (mistakes == 8)
        {
            printf("You were hanged!\n");
            printf("Hidden word:");
            printf("%s\n", word);
            break;
        }
        flag = 0;
        printf("%s\n", cells);
    }
    if (strcmp(word, cells) == 0)
    {
        printf("Congratulations, you won!\n");
    }
}
