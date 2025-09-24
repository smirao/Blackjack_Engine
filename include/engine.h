#ifndef ENGINE_H_   
#define ENGINE_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct game_rules_and_setup 
{

    uint8_t number_of_decks; // default 8
    uint8_t number_of_splits; // default 4
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
typedef const enum {HIT, STAND, DOUBLE, SPLIT, SURRENDER} hand_moves;


game_struct* generate_game();

#endif 