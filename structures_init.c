#include "includes/main_header.h"

t_characters	*characters_init(void)
{
	t_characters	*character;

	character = malloc(sizeof(t_characters));
	character->hp = 100;
	character->dodge_next_attack = 0;
	character->movement_malus_roll = 0;
	return (character);
}

t_offensive		*offensive_init(char *name, int atk, int min_range, int max_range, int crit_chance, int can_attack_twice)
{
	t_offensive		*weapon;

	weapon = malloc(sizeof(t_offensive));
	strcpy(weapon->name, name);
	weapon->atk = atk;
	weapon->weapon_min_range = min_range;
	weapon->weapon_max_range = max_range;
	weapon->crit_chance = crit_chance;
	weapon->can_attack_twice = can_attack_twice;
	return (weapon);
}

t_defensive		*defensive_init(char *name, int def, int movement_malus)
{
	t_defensive		*protection;

	protection = malloc(sizeof(t_defensive));
	strcpy(protection->name, name);
	protection->def = def;
	protection->movement_malus = movement_malus;
	return (protection);
}
