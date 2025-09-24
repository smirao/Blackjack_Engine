#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <include/gen_and_manip.h>
#include <time.h>   // For time()
#include <stdbool.h>

typedef struct game_rules_and_setup 
{

    uint8_t number_of_decks; // default 8
    uint8_t max_number_of_splits; // default 4
    uint8_t number_of_players; // default 1

} game_rules_and_setup;


typedef struct player_struct
{
    uint8_t current_hand[12];

} player_struct;


typedef struct game_struct 
{
    uint8_t* shoe;
    uint8_t shoe_index_pointer;
    bool cut_card_found;
    uint16_t cut_index;

    player_struct** players;
    uint8_t number_of_players;
    uint8_t current_player;

    game_rules_and_setup* rules_and_setup;
} game_struct;


typedef const enum {SPADES, HEARTS, DIAMONDS, CLUBS} card_suits;
typedef const enum {HIT, STAND, SPLIT, SURRENDER} hand_moves;


// Getters 
uint8_t* get_shoe_pointer(game_struct* game) 
{
    return game->shoe;
}


game_rules_and_setup* generate_rules_and_setup(uint8_t number_of_decks, uint8_t max_number_of_splits, uint8_t number_of_players)
{
    game_rules_and_setup* new_rules = malloc(sizeof(game_rules_and_setup));

    new_rules->max_number_of_splits = max_number_of_splits;
    new_rules->number_of_decks = number_of_decks;
    new_rules->number_of_players = number_of_players;

    return new_rules;
}

game_struct* generate_game()
{
    // Select a random range for card split 1.5-2 deck cut off from 8 decks
    double random_value = (double)rand() / (double)RAND_MAX;
    random_value = (random_value * 6.25 + 18.75) * 0.01;

    // setting up game pointers
    game_struct* new_game = malloc(sizeof(game_struct));
    game_rules_and_setup* rules = generate_rules_and_setup(8, 4, 1);


    // load default values
    rules->number_of_decks = 8;
    rules->max_number_of_splits = 4;
    rules->number_of_players = 1;

    new_game->current_player = 0;
    new_game->number_of_players = rules->number_of_players;
    new_game->shoe = generate_shoe(rules->number_of_decks);
    new_game->cut_index = (int)(rules->number_of_decks * 52 * random_value); // for 8 ~ 1.5-2 decks to be cut off aka 18.75%-25.00%
    new_game->players = malloc(sizeof(player_struct) * rules->number_of_players);
    new_game->rules_and_setup = rules;
    
    for (int i = 0; i < rules->number_of_players; i++)
    {
        player_struct* new_player = malloc(sizeof(player_struct));
        new_game->players[i] = new_player;
    }

    return new_game;
}

