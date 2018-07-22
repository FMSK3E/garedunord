#include "includes/main_header.h"

void			turns(t_characters *player, t_characters *enemy)
{
	int turn;
	int game_over;
	int range;

	turn = 0;
	game_over = 0;
	range = 5;
	while (!game_over)
	{
		if (turn == 0)
		{
			player_turn(&range, player, enemy);
			turn++;
		}
		else
		{
			enemy_turn(&range, player, enemy);
			turn--;
		}
		if (player->hp <= 0 || enemy->hp <= 0)
			game_over = 1;
	}
	endgame(player, enemy);
}

void			player_turn(int *range, t_characters *player, t_characters *enemy)
{
	char order[10];
	int turn_ok;

	turn_ok = 0;
	printf("It's your turn, what do you want to do ? 0 for infos about both players, 1 to attack, 2 dodge, 3 to go forward, 4 to go backward\n");
	while (!turn_ok)
	{
		scanf("%s", &order);
		if (strstr("0", order))
			ft_print_stuff(player, enemy);
		else if (strstr("1", order))
			//attaque
		else if (strstr("2", order))
			//esquive
		else if (strstr("3", order) || strstr("4", order))
			//bouge
		else
			printf("Not a valid number !\n");
	}
}
void			enemy_turn(int *range, t_characters *player, t_characters *enemy)
{
	int random;

	random = rand() % 55;
	if (random <= 29)
	{
		if (enemy->weapon.min_range >= *range && enemy->weapon.max_range <= *range)
			//attaque
		else
			//bouge
	}
	else if (random >= 29 && random <= 44)
	{
		if (player->weapon.min_range >= *range && player->weapon.max_range <= *range)
			//esquive
		else if (enemy->weapon.min_range >= *range && enemy->weapon.max_range <= *range)
			//attaque
		else
			//bouge
	}
	else
		//bouge
}

void			endgame(t_characters *player, t_characters *enemy)
{
	printf("The game is over !\n");
	if (player->hp > 0)
		printf("You won, congratulations !\n\n");
	else
		printf("You lost lol, so bad xd\n\n");
}
