#include <stdio.h>
#include <include/functions.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void print_array(uint8_t* array,  size_t size)
{
    printf("---\n");
    for (int i = 0; i < size; i++)
    {
        printf("%hu, ", *(array + i));
    }
    printf("\n---\n");
}

void shuffle(uint8_t* shoe, size_t size)
{
    // Fisher-Yates shuffle algorithm utilized
    // Specifically the transport method
    // Algorithm copied from geeksforgeeks

    srand ( time(NULL) );

    for (size_t i = 0; i < size; i++)
    {
        uint8_t index = rand() % size;

        // swap
        uint8_t temp = *(shoe + i);
        *(shoe + i) = *(shoe + index);
        *(shoe + index) = temp;
    }
}

uint8_t* generate_deck()
{
    // The card suites in Blackjack don't really matter from a player's standpoint
    // However, it is important to identify these for any UI implementations

    // The deck will be represented by integers, then offset by twenty for each suit
    // 2-14 => Spades 2-A
    // 22-34 => Hearts 2-A
    // 42-54 => Diamonds 2-A
    // 62-54 => Clubs 2-A

    uint8_t* deck = (uint8_t*)malloc(52*sizeof(uint8_t));    
    uint8_t current_deck_position = 0;

    for (uint8_t i = 2; i <= 14; i++)
    {
        for (uint8_t j = 0; j < 4; j++)
        {
            *(deck + current_deck_position++) = i+(j*20);
        }
    }

    return deck;
}

uint8_t *generate_shoe(uint8_t decks)
{
    uint8_t* shoe = (uint8_t*)malloc(decks*52*sizeof(uint8_t));

    // loop through and add a new deck to the end of the shoe as prompted by paramaters
    for (size_t i = 0; i < decks; i++)
    {
        uint8_t* new_deck = generate_deck();

        for (uint8_t j = 0; j < 52; j++)
        {
            *(shoe + j + 52 * i) = *(new_deck + j);
        }

        free(new_deck);
    }

    shuffle(shoe, decks * 52);

    return shoe;
}



int main()
{
    uint8_t* shoe = generate_shoe(6);
    print_array(shoe, 52 * 6);
    return 0;
}