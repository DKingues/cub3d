/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:47:04 by rmota-ma          #+#    #+#             */
/*   Updated: 2025/10/20 20:06:57 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	if (ac < 2)
		return (printf("Insert a map name.\n"), 1);
	if (ac > 2)
		return (printf("Too many arguments.\n"), 1);
	if (parsing(av))
		return (1);
	init();
	gameplay();
    return (0);
}
/* 
	DIKINGUI
	{
		Fazer os sprites.
			- Paredes, Portas
			- Menu(lettering and buttons)
			- Timer(lettering and drawing)
			- Barra de stamina
			-Fogo/glitch/void/leaks/alguma coisa

		Interagir com Objectos (Portas)
		
		Tratar de cores chao/teto
	}
	Renato
	{
		Menu pausa, inicial
			- Play / Resume
			- Options
			- Quit Game / Exit to menu

		Minimap redondo talvez

		Fogo/glitch/void/leaks/alguma coisa a consumir o mapa e dificuldades(tempo de jogo e tempo de consumo de mapa)
	}
	Juntos
	{
		Fazer o 3D
	}
*/