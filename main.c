#include "includes/main_header.h"

int		main(void)
{
	srand(time(NULL));
	t_characters *player = characters_init();
	t_characters *enemy = characters_init();
	t_offensive *sword = offensive_init("sword", 15, 1, 1, 15, 0);
	t_offensive *axe = offensive_init("axe", 20, 1, 1, 10, 0);
	t_offensive *spear = offensive_init("spear", 15, 1, 2, 10, 0);
	t_offensive *bow = offensive_init("bow", 15, 2, 4, 5, 0);
	t_offensive *daggers = offensive_init("daggers", 10, 1, 1, 15, 1);
	t_defensive *small_shield = defensive_init("small shield", 10, 3);
	t_defensive *large_shield = defensive_init("large shield", 15, 6);
	t_defensive *light_armor = defensive_init("light armor", 10, 3);
	t_defensive *heavy_armor = defensive_init("heavy armor", 15, 6);
	t_defensive *no_protection = defensive_init("NULL", 0, 0);
	int current_step;

	current_step = 1;
	printf("\n\nNARRATOR : Welcome to Gare du Nord v2 !\n");
	ft_stuff_steps(&current_step, player, enemy, sword, axe, spear, bow, daggers, small_shield, large_shield, light_armor, heavy_armor, no_protection);
	printf("NARRATOR : Now that both of you have stuff, fight to death ! owo\n");
	turns(player, enemy);
	free(player);
	free(enemy);
	free(sword);
	free(axe);
	free(spear);
	free(bow);
	free(daggers);
	free(small_shield);
	free(large_shield);
	free(light_armor);
	free(heavy_armor);
	free(no_protection);
	return (0);
}
