#include "includes/main_header.h"

int		main(void)
{	
	srand(time(NULL));
	int current_step;
	int player;
	
	Init();
	player = 0;
	current_step = 1;
	printf("\n\nNARRATOR : Welcome to Gare du Nord v2 !\n");
	ft_current_steps_stuff(&current_step, &player);

	return (0);
}
