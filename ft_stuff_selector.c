#include "includes/main_header.h"

void		ft_stuff_selector(int choice, int step, int player)
{
	if (step == 1)
		ft_step_offensive(choice, player);
	else if (step == 2 || step == 3)
		ft_step_defensive(choice, step, player);
}

void		ft_step_offensive(int choice, int player)
{
		if (choice == 0)
		{	
			ft_print_offensive(sword);
			ft_print_offensive(axe);
			ft_print_offensive(spear);
			ft_print_offensive(bow);
			ft_print_offensive(daggers);
		}
		else if (choice == 1)
			players[player].weapon = sword;	
		else if (choice == 2)
			players[player].weapon = axe;	
		else if (choice == 3)
			players[player].weapon = spear;	
		else if (choice == 4)
			players[player].weapon = bow;	
		else if (choice == 5)
			players[player].weapon = daggers;	
}

void		ft_step_defensive(int choice, int step, int player)
{
		if (step == 2)
		{
			if (choice == 0)
			{
				ft_print_defensive(small_shield);
				ft_print_defensive(large_shield);
			}
			else if (choice == 1)
				players[player].shield = small_shield;	
			else if (choice == 2)
				players[player].shield = large_shield;
			else if (choice == 3)
			{
				strcpy(players[player].shield.name, "NULL");
				players[player].shield.def = 0;
				players[player].shield.movement_malus = 0;
			}
		}
		else if (step == 3)
		{
			if (choice == 0)
			{
				ft_print_defensive(light_armor);	
				ft_print_defensive(heavy_armor);
			}
			else if (choice == 1)
				players[player].armor = light_armor;	
			else if (choice == 2)
				players[player].armor = heavy_armor;	
			else if (choice == 3)	
			{
				strcpy(players[player].armor.name, "NULL");
				players[player].armor.def = 0;
				players[player].armor.movement_malus = 0;
			}
		}
}

void 		ft_print_offensive(t_offensive weapon)
{	
	printf("weapon's name : %s\n", weapon.name);
	printf("weapon's atk : %d\n", weapon.atk);
	printf("weapon's minimum range : %d\n", weapon.weapon_min_range);
	printf("weapon's maximum range : %d\n", weapon.weapon_max_range);
	printf("weapon's critical strike chance : %d\n", weapon.crit_chance);
	if (strstr(weapon.name, "daggers"))
		printf("The weapon attacks twice !\n\n");
	else if (strstr(weapon.name, "bow"))
		printf("You cannot have a shield if you take the bow !\n\n");
	else
		printf("\n");
}

void 		ft_print_defensive(t_defensive protection)
{
	printf("protection's name : %s\n", protection.name);
	printf("protection's def : %d\n", protection.def);
	printf("protection's movement malus during roll : %d\n\n", protection.movement_malus);
}
