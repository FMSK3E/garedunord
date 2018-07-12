#ifndef		MAIN_HEADER_H
#define 	MAIN_HEADER_H 

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

enum {YES, NO};


typedef struct 		s_offensive
{
	char name[15];

	int atk;
	int weapon_min_range;
	int weapon_max_range;
	int crit_chance;

	int can_attack_twice;
}			t_offensive;

t_offensive sword;
t_offensive axe;
t_offensive spear;
t_offensive bow;
t_offensive daggers;


typedef struct 		s_defensive
{
	char name[15];

	int def;
	int movement_malus;
}			t_defensive;

t_defensive small_shield;
t_defensive large_shield;

t_defensive light_armor;
t_defensive heavy_armor;


typedef struct		s_characters
{
	int hp;
	
	struct s_offensive weapon;
	struct s_defensive shield;
	struct s_defensive armor;
	
	int dodge_next_attack;
	int movement_malus_roll;		
}			t_characters;

t_characters players[2];

void		Init(void);

void		ft_current_steps_stuff(int *current_step, int *player);
void		ft_step1_stuff(int *current_step, int *player);
void		ft_step2_stuff(int *current_step, int *player);
void		ft_step3_stuff(int *current_step, int *player);

void		ft_stuff_selector(char choice, int step, int player);
void		ft_step_offensive(char choice, int player);
void		ft_step_defensive(char choice, int step, int player);

void 		ft_print_offensive(t_offensive weapon);
void 		ft_print_defensive(t_defensive protection);

#endif
