#include "includes/main_header.h"

void			ft_print_stuff(t_characters *player, t_characters *enemy)
{	
	printf("%d\t", player->hp);
	printf("%s\t", player->weapon.name);
	printf("%s\t", player->shield.name);
	printf("%s\n", player->armor.name);
	printf("%d\t", enemy->hp);
	printf("%s\t", enemy->weapon.name);
	printf("%s\t", enemy->shield.name);
	printf("%s\n\n", enemy->armor.name);
}

void			ft_print_offensive(t_offensive weapon)
{
	printf("weapon's name : %s\n", weapon.name);
	printf("weapon's atk : %d\n", weapon.atk);
	printf("weapon's minimum range : %d\n", weapon.min_range);
	printf("weapon's maximum range : %d\n", weapon.max_range);
	printf("weapon's critical strike chance : %d\n", weapon.crit_chance);
	if (strstr(weapon.name, "daggers"))
		printf("The weapon attacks twice !\n\n");
	else if (strstr(weapon.name, "bow"))
		printf("You cannot have a shield if you take the bow !\n\n");
	else
		printf("\n");
}

void			ft_print_defensive(t_defensive protection)
{
	printf("protection's name : %s\n", protection.name);
	printf("protection's def : %d\n", protection.def);
	printf("protection's movement malus during roll : %d\n\n", protection.movement_malus);
}
