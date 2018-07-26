#ifndef		MAIN_HEADER_H
#define 	MAIN_HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

enum {YES, NO};

typedef struct		s_offensive
{
	char			name[15];
	int				atk;
	int				min_range;
	int				max_range;
	int				crit_chance;
	int				can_attack_twice;
}					t_offensive;

typedef struct		s_defensive
{
	char			name[15];
	int				def;
	int				movement_malus;
}					t_defensive;

typedef struct		s_characters
{
	char			name[8];
	int				hp;
	t_offensive		weapon;
	t_defensive		shield;
	t_defensive		armor;
	int				dodge_next_attack;
	int				bonus_next_attack;
	int				movement_malus_roll;
}					t_characters;

//				structures_init.c
t_offensive		*offensive_init(char *name, int atk, int min_range, int max_range, int crit_chance, int can_attack_twice);
t_defensive		*defensive_init(char *name, int def, int movement_malus);
t_characters	*characters_init(char *name);

//				select_stuff.c
void			ft_stuff_steps(int *range, int *current_step, t_characters *player, t_characters *enemy, t_offensive *sword, t_offensive *axe, t_offensive *spear, t_offensive *bow, t_offensive *daggers, t_defensive *small_shield, t_defensive *large_shield, t_defensive *light_armor, t_defensive *heavy_armor, t_defensive *no_protection);
void			ft_step1_stuff(int *current_step, t_characters *player, t_characters *enemy, t_offensive *sword, t_offensive *axe, t_offensive *spear, t_offensive *bow, t_offensive *daggers);
void			ft_step2_stuff(int *current_step, t_characters *player, t_characters *enemy, t_defensive *small_shield, t_defensive *large_shield, t_defensive *light_armor, t_defensive *heavy_armor, t_defensive *no_protection);
void			ft_step3_stuff(int *current_step, t_characters *player, t_characters *enemy, t_defensive *small_shield, t_defensive *large_shield, t_defensive *light_armor, t_defensive *heavy_armor, t_defensive *no_protection);
void			ft_select_offensive(char choice, t_characters *character, t_offensive *sword, t_offensive *axe, t_offensive *spear, t_offensive *bow, t_offensive *daggers);
void			ft_select_defensive(char choice, int step, t_characters *character, t_defensive *small_shield, t_defensive *large_shield, t_defensive *light_armor, t_defensive *heavy_armor, t_defensive *no_protection);

//				print_stuff.c
void			ft_print_offensive(t_offensive weapon);
void			ft_print_defensive(t_defensive protection);
void			ft_print_stuff(int *range, t_characters *player, t_characters *enemy);

//				turns.c
void			ft_turns_manager(int *range, t_characters *player, t_characters *enemy);
void			ft_player_turn(int *range, t_characters *player, t_characters *enemy);
void			ft_enemy_turn(int *range, t_characters *player, t_characters *enemy);
void			ft_endgame(t_characters *player, t_characters *enemy);

//				actions.c
int				ft_attack(int daggers, t_characters *attacker, t_characters *defender);
int				ft_dodge(t_characters *character);
int				ft_move(int *range, t_characters *character);

#endif
