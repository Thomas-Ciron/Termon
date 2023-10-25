#ifndef POKEMON_H
#define POKEMON_H

#include "binaries.h"

struct Pokemon {
    char name[16];
    int base_hp;
    int base_attack[2];
    int base_defense[2];
    int base_speed;
    int ev_yield[6];
    int type[2];
    int catch_rate;
    int growth_curve;
    int experience_yield;
    int ability[3];
    int held_item[2];
    int egg_group[2];
    int hatch_steps;
    int gender;
    int can_learn_tm[128];
    int learn_set[32];
    int learn_set_level[32];
};

struct Pokemon init_pokemon(const int pokemon_id, const char* pokemon_name);

#endif