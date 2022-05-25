#include <stdio.h>
#include <string.h>
#include <HangmanLib/HangmanLib.h>

int main()
{
    FILE *file;
    char word[20];
    char buffer[400];
    int diff;
    int len;
    greetings();
    printf("Enter 1, 2 or 3 to select difficulty\n");
    scanf("%d", &diff);
    switch (diff)
    {
    case 1:
        file = fopen("src/Dictionaries/level-1.txt", "r");
        break;
    case 2:
        file = fopen("src/Dictionaries/level-2.txt", "r");
        break;
    case 3:
        file = fopen("src/Dictionaries/level-3.txt", "r");
        break;
    default:
        printf("Invalid character entered! Please enter 1, 2 or 3!\n");
        return 0;
    }
    int rand = getrand();
    fgets(buffer, 400, file);
    len = rand_word(buffer, word, rand);
    word_guess(word, len);
    fclose(file);
    return 0;
}
