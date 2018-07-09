#include "includes/main_header.h"

void		ft_current_steps_stuff(int *current_step, int *player)
{
	int stuff_choice;
	
	while (*current_step == 1)
	{	
		printf("NARRATOR : Firstly you have to pick a weapon : 1 for the sword, 2 for the axe, 3 for the spear, 4 for the bow, 5 for the daggers, 0 for infos about the weapons !\n");
		scanf("%d", &stuff_choice);
		if (stuff_choice >= 0 && stuff_choice <= 5)
		{		
			ft_stuff_selector(stuff_choice, *current_step, *player);	
			if (stuff_choice != 0)
			{	
				stuff_choice = rand() % 4 + 1;
				ft_stuff_selector(stuff_choice, *current_step, (*player) + 1);
				(*current_step)++;
			if (stuff_choice == 4)
				(*current_step)++;
			}
		}
		else
			printf("NARRATOR : Pick a valid number, dumbfuck !\n");
	}
	while (*current_step == 2)
	{	
		printf("NARRATOR : Do you want to take a shield ? 1 for a small shield, 2 for a large shield, 3 for nothing, 0 for infos about the two shields !\n");
		scanf("%d", &stuff_choice);
		if (stuff_choice >= 0 && stuff_choice <= 3)
		{		
			ft_stuff_selector(stuff_choice, *current_step, *player);	
			if (stuff_choice != 0)
			{	
				stuff_choice = rand() % 2 + 1;
				ft_stuff_selector(stuff_choice, *current_step, (*player) + 1);
				(*current_step)++;
			}
		}
		else
			printf("NARRATOR : Pick a valid number, dumbfuck !\n");
	}
	while (*current_step == 3)
	{	
		printf("NARRATOR : Do you want to wear an armor ? 1 for a light armor, 2 for a heavy armor, 3 for nothing, 0 for infos about the two armors !\n");
		scanf("%d", &stuff_choice);
		if (stuff_choice >= 0 && stuff_choice <= 3)
		{		
			ft_stuff_selector(stuff_choice, *current_step, *player);	
			if (stuff_choice != 0)
			{	
				stuff_choice = rand() % 2 + 1;
				ft_stuff_selector(stuff_choice, *current_step, (*player) + 1);
				(*current_step)++;
			}
			
		}
		else
			printf("NARRATOR : Pick a valid number, dumbfuck !\n");
	}
	printf("%s\t", players[*player].weapon.name);
	printf("%s\t", players[*player].shield.name);
	printf("%s\n", players[*player].armor.name);

	printf("%s\t", players[(*player) + 1].weapon.name);
	printf("%s\t", players[(*player) + 1].shield.name);
	printf("%s\n", players[(*player) + 1].armor.name);
}
