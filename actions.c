#include "includes/main_header.h"

int				ft_attack(int daggers, t_characters *attacker, t_characters *defender)
{
	int		random;
	int		critical;
	int		damage;

	critical = 0;
	random = rand() % 60 + attacker->weapon.crit_chance;	
	if (random <= 24)
	{
		printf("%s : Attack has failed !\n", attacker->name);
		critical = -100;
	}
	else if (random >= 25 && random <= 49)
	{
		printf("%s : Attack is a success !\n", attacker->name);
		if (defender->dodge_next_attack)
		{
			printf("%s : Defender dodged the attack !\n", defender->name);
			critical = -100;
		}
	}
	else if (random >= 50)
	{
		printf("%s : Attack is a critical success, bonus damage for the attack !\n", attacker->name);
		critical += 10;
	}
	damage = attacker->weapon.atk + critical - (defender->shield.def + defender->armor.def);
	if (attacker->bonus_next_attack)
		damage += 10;
	if (damage < 0)
		damage = 0;
	printf("%s Inflicted %d to %s !\n", attacker->name, damage, defender->name);
	defender->hp -= damage;
	defender->dodge_next_attack = 0;
	if (strstr(attacker->weapon.name, "daggers") && !daggers)
		ft_attack(1, attacker, defender);
	attacker->bonus_next_attack = 0;
	return (1);
}

int				ft_dodge(t_characters *character)
{
	int		random;

	random = rand() % 50 - (character->shield.movement_malus + character->armor.movement_malus);
	if (random <= 14)
		printf("%s : Dodge has failed !\n", character->name);
	else if (random >= 15 && random <= 39)
	{
		character->dodge_next_attack = 1;
		printf("%s : Dodge is a success !\n", character->name);
	}
	else if (random >= 40)
	{
		character->dodge_next_attack = 1;
		character->bonus_next_attack = 1;
		printf("%s : Dodge is a huge success, bonus damage for the next attack !\n", character->name);
	}
	return (1);
}

int				ft_move(int *range, t_characters *character)
{
	int		i;
	int		random;
	int		former_range;
	char	order[5];

	random = rand() % 45 - (character->shield.movement_malus + character->armor.movement_malus);
	if (random <= 14)
	{
		printf("%s : Movement has failed !\n", character->name);
		return (1);
	}
	else if (random >= 15)
		printf("%s : Movement is a success !\n", character->name);
	if (strstr(character->name, "Player"))
	{
		if (*range > 1)
		{
			i = 0;
			printf("NARRATOR : 1 to go forward, 2 to go backward\n");
			while (!i)
			{
				scanf("%s", order);
				if (strstr(order, "1"))
				{
					(*range)--;
					i++;
				}
				else if (strstr(order, "2"))
				{
					(*range)++;
					i++;
				}
				else
					printf("INFOS : Not a valid number !\n");
			}
		}
		else
			(*range)++;
	}
	else
	{
		former_range = *range;
		if (character->weapon.min_range > *range)
			(*range)++;
		else if (character->weapon.max_range < *range)
			(*range)--;
		else
		{
			if (*range == 1)
				(*range)++;
			else
			{
				random = rand() % 2;
				if (random == 0)
					(*range)--;
				else
					(*range)++;
			}
		}
		if (former_range - *range == 1)
			printf("INFOS : Your enemy is now closer to you !\n");
		else
			printf("INFOS : Your enemy is now farther to you !\n");
	}
	return (1);
}
