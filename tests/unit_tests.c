#include <lib/Unity/src/unity.h>
#include <include/engine.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void setUp(void)
{
    srand(time(NULL)); 
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test1()
{
    game_struct* game = generate_game();

    // test that default values are set

    TEST_ASSERT(game->cut_index == 2);

}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test1);

    return UNITY_END();
}