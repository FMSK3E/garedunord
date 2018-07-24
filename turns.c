#include "includes/main_header.h"

void			ft_turns_manager(int *range, t_characters *player, t_characters *enemy)
{
	int	turn;
	int game_over;

	turn = 0;
	game_over = 0;
	while (!game_over)
	{
		if (turn == 0)
		{
			player_turn(range, player, enemy);
			turn++;
		}
		else
		{
			enemy_turn(range, player, enemy);
			turn--;
		}
		if (player->hp <= 0 || enemy->hp <= 0)
			game_over = 1;
	}
	endgame(player, enemy);
}

void			player_turn(int *range, t_characters *player, t_characters *enemy)
{
	char order[5];
	int turn_ok;

	turn_ok = 0;
	printf("\n--------------------------------------------------\nNARRATOR : It's your turn, what do you want to do ? 0 for infos about both players, 1 to attack, 2 dodge, 3 to move\n");
	while (!turn_ok)
	{
		scanf("%s", order);
		if (strstr("0", order))
			ft_print_stuff(range, player, enemy);
		else if (strstr("1", order))
			if (player->weapon.min_range <= *range && player->weapon.max_range >= *range)
				turn_ok = ft_attack(player, enemy);
			else 
				printf("INFOS : You are too far away to attack !\n");
		else if (strstr("2", order))
			if (enemy->weapon.min_range <= *range && enemy->weapon.max_range >= *range)
				turn_ok = ft_dodge(player);
			else
				printf("INFOS : Enemy player is too far away, he cannot attack !\n");
		else if (strstr("3", order))
			turn_ok = ft_move(range, player);
		else
			printf("INFOS : Not a valid number !\n");
	}
}
void			enemy_turn(int *range, t_characters *player, t_characters *enemy)
{
	int random;

	random = rand() % 55;
	if (random <= 29)
	{
		if (enemy->weapon.min_range <= *range && enemy->weapon.max_range >= *range)
			ft_attack(enemy, player);
		else
			ft_move(range, enemy);
	}
	else if (random >= 29 && random <= 44)
	{
		if (player->weapon.min_range <= *range && player->weapon.max_range >= *range)
			ft_dodge(enemy);
		else if (enemy->weapon.min_range <= *range && enemy->weapon.max_range >= *range)
			ft_attack(enemy, player);
		else
			ft_move(range, enemy);
	}
	else
		ft_move(range, enemy);
}

void			endgame(t_characters *player, t_characters *enemy)
{
	printf("NARRATOR : The game is over !\n");
	if (player->hp > 0)
		printf("NARRATOR : You won, congratulations !\n\n");
	else
		printf("NARRATOR : You lost lol, so bad xd\n\n");
}
