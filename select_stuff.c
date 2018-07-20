#include "includes/main_header.h"

void		ft_stuff_steps(int *current_step, t_characters *player, t_characters *enemy, t_offensive *sword, t_offensive *axe, t_offensive *spear, t_offensive *bow, t_offensive *daggers, t_defensive *small_shield, t_defensive *large_shield, t_defensive *light_armor, t_defensive *heavy_armor, t_defensive *no_protection)
{	
	int weapon_is_bow;

	ft_step1_stuff(current_step, player, enemy, sword, axe, spear, bow, daggers);
	(*current_step)++;
	ft_step2_stuff(current_step, player, enemy, small_shield, large_shield, light_armor, heavy_armor, no_protection);
	(*current_step)++;
	ft_step3_stuff(current_step, player, enemy, small_shield, large_shield, light_armor, heavy_armor, no_protection);
	(*current_step)++;
	ft_print_stuff(player, enemy);
}

void		ft_step1_stuff(int *current_step, t_characters *player, t_characters *enemy, t_offensive *sword, t_offensive *axe, t_offensive *spear, t_offensive *bow, t_offensive *daggers)
{
	char stuff_choice;
	int next_step;
	
	next_step = 0;
	while (!next_step)
	{
		printf("NARRATOR : Firstly you have to pick a weapon : 1 for the sword, 2 for the axe, 3 for the spear, 4 for the bow, 5 for the daggers, 0 for infos about the weapons !\n");
		scanf("%c", &stuff_choice);
		if (stuff_choice >= '0' && stuff_choice <= '5')
		{
			ft_select_offensive(stuff_choice, player, sword, axe, spear, bow, daggers);
			if (stuff_choice != '0')
				next_step++;
		}
		else
			printf("NARRATOR : Pick a valid number, dumbfuck !\n");
	}
	stuff_choice = (rand() % 4 + 1) + '0';
	ft_select_offensive(stuff_choice, enemy, sword, axe, spear, bow, daggers);
}

void		ft_step2_stuff(int *current_step, t_characters *player, t_characters *enemy, t_defensive *small_shield, t_defensive *large_shield, t_defensive *light_armor, t_defensive *heavy_armor, t_defensive *no_protection)
{
	char stuff_choice;
	int next_step;

	next_step = 0;
	if (strstr(player->weapon.name, "bow"))
	{
		ft_select_defensive('3', *current_step, player, small_shield, large_shield, light_armor, heavy_armor, no_protection);
		next_step++;
	}
	else
	{
		while (!next_step)
		{	
			printf("NARRATOR : Do you want to take a shield ? 1 for a small shield, 2 for a large shield, 3 for nothing, 0 for infos about the two shields !\n");
			scanf("%c", &stuff_choice);
			if (stuff_choice >= '0' && stuff_choice <= '3')
			{
				ft_select_defensive(stuff_choice, *current_step, player, small_shield, large_shield, light_armor, heavy_armor, no_protection);
				if (stuff_choice != '0')
				next_step++;
			}
			else
				printf("NARRATOR : Pick a valid number, dumbfuck !\n");
		}
	}
	if (strstr(enemy->weapon.name, "bow"))
	{
		ft_select_defensive('3', *current_step, enemy, small_shield, large_shield, light_armor, heavy_armor, no_protection);
		next_step++;
	}
	else
	{
		stuff_choice = (rand() % 2 + 1) + '0';
		ft_select_defensive(stuff_choice, *current_step, enemy, small_shield, large_shield, light_armor, heavy_armor, no_protection);
	}
}

void		ft_step3_stuff(int *current_step, t_characters *player, t_characters *enemy, t_defensive *small_shield, t_defensive *large_shield, t_defensive *light_armor, t_defensive *heavy_armor, t_defensive *no_protection)
{
	char stuff_choice;
	int next_step;

	next_step = 0;
	while (!next_step)
	{
		printf("NARRATOR : Do you want to wear an armor ? 1 for a light armor, 2 for a heavy armor, 3 for nothing, 0 for infos about the two armors !\n");
		scanf("%c", &stuff_choice);
		if (stuff_choice >= '0' && stuff_choice <= '3')
		{
			ft_select_defensive(stuff_choice, *current_step, player, small_shield, large_shield, light_armor, heavy_armor, no_protection);
			if (stuff_choice != '0')
				next_step++;
		}
		else
			printf("NARRATOR : Pick a valid number, dumbfuck !\n");
	}
	stuff_choice = (rand() % 2 + 1) + '0';
	ft_select_defensive(stuff_choice, *current_step, enemy, small_shield, large_shield, light_armor, heavy_armor, no_protection);
}

void		ft_select_offensive(char choice, t_characters *character, t_offensive *sword, t_offensive *axe, t_offensive *spear, t_offensive *bow, t_offensive *daggers)
{
		if (choice == '0')
		{
			ft_print_offensive(*sword);
			ft_print_offensive(*axe);
			ft_print_offensive(*spear);
			ft_print_offensive(*bow);
			ft_print_offensive(*daggers);
		}
		else if (choice == '1')
			character->weapon = *sword;
		else if (choice == '2')
			character->weapon = *axe;
		else if (choice == '3')
			character->weapon = *spear;
		else if (choice == '4')
			character->weapon = *bow;
		else if (choice == '5')
			character->weapon = *daggers;
}

void		ft_select_defensive(char choice, int step, t_characters *character, t_defensive *small_shield, t_defensive *large_shield, t_defensive *light_armor, t_defensive *heavy_armor, t_defensive *no_protection)
{
		if (step == 2)
		{
			if (choice == '0')
			{
				ft_print_defensive(*small_shield);
				ft_print_defensive(*large_shield);
			}
			else if (choice == '1')
				character->shield = *small_shield;
			else if (choice == '2')
				character->shield = *large_shield;
			else if (choice == '3')
				character->shield = *no_protection;
		}
		else if (step == 3)
		{
			if (choice == '0')
			{
				ft_print_defensive(*light_armor);	
				ft_print_defensive(*heavy_armor);
			}
			else if (choice == '1')
				character->armor = *light_armor;
			else if (choice == '2')
				character->armor = *heavy_armor;
			else if (choice == '3')
			{
				character->armor = *no_protection;
			}
		}
}
