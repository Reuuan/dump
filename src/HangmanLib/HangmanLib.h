#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void greetings();
int getrand();
int rand_word(char *array, char *word, int rand);
void print_hangman(int mistakes);
void word_guess(char *word, int len);
