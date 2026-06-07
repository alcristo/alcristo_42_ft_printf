/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristo <alcristo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:59:19 by alcristo          #+#    #+#             */
/*   Updated: 2026/06/07 13:44:10 by alcristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

/*
Para el bonus: tiene que gestionar las flags '-0.' y el ancho minimo.
También debe gestionar las flags "# +".

Formato: %[flags][width][.precision]q

FLAGS:

	· -: Output left-justified: espacios de padding a la derecha.
		- tiene prioridad sobre el 0.
	· 0: Padea numeros con ceros a la izquierda.
	· .: Precision: Da un minimo de digitos que aparecen para decs y hexadecs.
		Si precision < digitos pone todo digitos
	· #: Representacion alternativa.
		- En numeros hexadecimales se añade un 0x o 0X a la izquierda.
		- En numeros de coma flotante fuerza decimales.
		- En el resto de especificaciones tiene comportamiento indefinido.
	· _: ES UN ESPACIO. Los números positivos estarán prefijados por un espacio.
		Si se pone con '-' pone un espacio a la izquierda y el resto a la derecha.
	· +: Los numeros decimales positivos estarán prefijados por un '+'.
		+ tiene prioridad sobre el espacio.

ANCHURA MINIMA (field minimum width):
	Especifica el número minimo de caracteres que debe ocupar la salida.
	Añade espacios a la izquierda (derecha si -) si es necesario.
	Sera necesario usar malloc.
	Si se especifica una anchura y flag 0, sustituye espacios por ceros.
	Si se especifica anchura y flags 0_ añade un cero y rellena con espacios.
	En hexadecimal si existe la flag # los caracteres 0x cuentan como dos.
	El signo cuenta para la  anchura, pero no para la precision.
	Si anchura > precision rellena con espacios.
	Si anchura < precision rellena con ceros.
*/

#include <string.h>
int	main(void)
{
/*	char	*f = "%3.7s%7.3s\n";
//	char	*x = "-";
	int	x = 0;
//	int *x = (int *)-1;*/
	int	n;
	printf("Prueba con funcion original:\n");
	n = printf(NULL);
	printf("\nCaracteres imprimidos: %d\n", n);
	ft_printf("Prueba con mi funcion:\n");
	n = ft_printf(NULL,1);
	ft_printf("\nCaracteres imprimidos: %d\n", n);
	return (0);
}
