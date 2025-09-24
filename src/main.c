#include <stdio.h>
#include <include/engine.h>
#include <include/gen_and_manip.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <include/engine.h>



void print_array(uint8_t* array,  size_t size)
{
    printf("---\n");
    for (int i = 0; i < size; i++)
    {
        printf("%hu, ", *(array + i));
    }
    printf("\n---\n");
}


card_suits determine_suite(uint8_t card)
{
    // use integer division to get suit
    return card / 20;
}

uint8_t determine_value();

void draw_cards(game_struct game) 
{

}


int main()
{
    srand(time(NULL)); // causing me issues and i dont know why 
    game_struct* game = generate_game();

    return 0;
}
