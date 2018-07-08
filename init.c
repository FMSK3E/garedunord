#include "includes/main_header.h"

void		Init(void)
{
	strcpy(sword.name, "sword");
	sword.atk = 15;
	sword.weapon_min_range = 1;
	sword.weapon_max_range = 1;
	sword.crit_chance = 15;
	sword.can_attack_twice = NO;

	strcpy(axe.name, "axe");
	axe.atk = 20;
	axe.weapon_min_range = 1;
	axe.weapon_max_range = 1;
	axe.crit_chance = 10;
	axe.can_attack_twice = NO;

	strcpy(spear.name, "spear");
	spear.atk = 15;
	spear.weapon_min_range = 1;
	spear.weapon_max_range = 2;
	spear.crit_chance = 10;
	spear.can_attack_twice = NO;

	strcpy(bow.name, "bow");
	bow.atk = 15;
	bow.weapon_min_range = 2;
	bow.weapon_max_range = 4;
	bow.crit_chance = 5;
	bow.can_attack_twice = NO;

	strcpy(daggers.name, "daggers");
	daggers.atk = 10;
	daggers.weapon_min_range = 1;
	daggers.weapon_max_range = 1;
	daggers.crit_chance = 15;
	daggers.can_attack_twice = YES;

	strcpy(small_shield.name, "small shield");
	small_shield.def = 10;
	small_shield.movement_malus = 3;
	
	strcpy(large_shield.name, "large shield");
	large_shield.def = 15;
	large_shield.movement_malus = 6;

	strcpy(light_armor.name, "light armor");
	light_armor.def = 10;
	light_armor.movement_malus = 3;

	strcpy(heavy_armor.name, "heavy armor");
	heavy_armor.def = 15;
	heavy_armor.movement_malus = 6;
}
