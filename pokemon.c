#include "pokemon.h"

struct Pokemon init_pokemon(const int pokemon_id, const char* pokemon_name) {
    struct Pokemon pkm;
    pkm.name = copy(pokemon_name);
    char file_name[100];
    sprintf(file_name, "binaries/pokemons/%d.bin", pokemon_id);

    pkm.base_hp = read_integer(file_name, 0, 8);
    pkm.base_attack[0] = read_integer(file_name, 8, 8);
    pkm.base_defense[0] = read_integer(file_name, 16, 8);
    pkm.base_attack[1] = read_integer(file_name, 24, 8);
    pkm.base_defense[1] = read_integer(file_name, 32, 8);
    pkm.base_speed = read_integer(file_name, 40, 8); 

    for(int i = 0; i < 6; ++i) {
        pkm.ev_yield[i] = read_integer(file_name, 48 + 2*i, 2);
    }

    pkm.type[0] = read_integer(file_name, 52, 5);
    pkm.type[1] = read_integer(file_name, 57, 5);

    pkm.catch_rate = read_integer(file_name, 62, 8);

    pkm.growth_curve = read_integer(file_name, 70, 3);

    pkm.experience_yield = read_integer(file_name, 73, 10);

    for(int i = 0; i < 3; ++i) {
        pkm.ability[i] = read_integer(file_name, 83 + 9*i,9);
    }

    pkm.held_item[0] = read_integer(file_name, 101, 12);
    pkm.held_item[1] = read_integer(file_name, 113, 12);

    pkm.egg_group[0] = read_integer(file_name, 125, 4);
    pkm.egg_group[1] = read_integer(file_name, 129, 4);

    pkm.hatch_steps = read_integer(file_name, 133, 7);

    pkm.gender = read_integer(file_name, 140, 3);

    for(int i = 0; i < 128; ++i) {
        pkm.can_learn_tm[i] = read_integer(file_name, 143, 1);
    }

    for(int i = 0; i < 32;++i) {
        pkm.learn_set[i] = read_integer(file_name, 144 + 18*i, 10);
        pkm.learn_set_level[i] =  read_integer(file_name, 154 + 18*i, 8);
    }

    return pkm;
}