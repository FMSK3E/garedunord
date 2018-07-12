#include "includes/main_header.h"

void		ft_current_steps_stuff(int *current_step, int *player)
{	
	int weapon_is_bow;

	ft_step1_stuff(current_step, player);
	(*current_step)++;	
	ft_step2_stuff(current_step, player);
	(*current_step)++;	
	ft_step3_stuff(current_step, player);
	(*current_step)++;	

	printf("%s\t", players[*player].weapon.name);
	printf("%s\t", players[*player].shield.name);
	printf("%s\n", players[*player].armor.name);

	printf("%s\t", players[(*player) + 1].weapon.name);
	printf("%s\t", players[(*player) + 1].shield.name);
	printf("%s\n", players[(*player) + 1].armor.name);
}

void		ft_step1_stuff(int *current_step, int *player)
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
			ft_stuff_selector(stuff_choice, *current_step, *player);
			if (stuff_choice != '0')
				next_step++;
		}
		else
			printf("NARRATOR : Pick a valid number, dumbfuck !\n");
	}
	stuff_choice = (rand() % 4 + 1) + '0';
	ft_stuff_selector(stuff_choice, *current_step, (*player) + 1);
}

void		ft_step2_stuff(int *current_step, int *player)
{
	char stuff_choice;
	int next_step;

	next_step = 0;
	if (strstr(players[*player].weapon.name, "bow"))
	{
		ft_stuff_selector('3', *current_step, *player);
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
				ft_stuff_selector(stuff_choice, *current_step, *player);	
				if (stuff_choice != '0')
				next_step++;
			}
			else
				printf("NARRATOR : Pick a valid number, dumbfuck !\n");
		}
	}
	if (strstr(players[(*player) + 1].weapon.name, "bow"))
	{
		ft_stuff_selector('3', *current_step, (*player) + 1);
		next_step++;
	}
	else
	{
		stuff_choice = (rand() % 2 + 1) + '0';
		ft_stuff_selector(stuff_choice, *current_step, (*player) + 1);
	}
}

void		ft_step3_stuff(int *current_step, int *player)
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
			ft_stuff_selector(stuff_choice, *current_step, *player);	
			if (stuff_choice != '0')
				next_step++;
		}
		else
			printf("NARRATOR : Pick a valid number, dumbfuck !\n");
	}
	stuff_choice = (rand() % 2 + 1) + '0';
	ft_stuff_selector(stuff_choice, *current_step, (*player) + 1);
}
