#include <ctest.h>
#include <HangmanLib/HangmanLib.h>
#include <stdlib.h>

CTEST(random, getrand)
{
    const int exp1 = 0;
    const int exp2 = 19;
    const int real = getrand();

    ASSERT_INTERVAL(exp1, exp2, real);
}
CTEST(word, rand_word)
{
    const char array[22] = "key fish apple wizard";
    char word[7];
    const int rand = 2;
    const int exp = 6;
    const int real = rand_word(array, word, rand);
    ASSERT_EQUAL(exp, real);

}

