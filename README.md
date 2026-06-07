<i>Este proyecto ha sido creado  como parte del currículo de 42 por \<alcristo\>[Álvaro Cistóbal Olalla]</i>

# ft_printf

## Descripción

Este proyecto trata de imitar la función "printf" de C con el fin de imprimir caracteres de  forma eficiente. Sin embargo, únicamente soporta caracteres, cadenas de carcteres, punteros y direcciones de memoria, y números enteros, enteros sin signo y hexadecimales. No se ha añadido la función de escribir números de punto flotante, así como números en formato <i>long</i> y de tamaño superior en formato decimal.

Esta función es variádica. Esto significa que toma como variables de entrada una cadena de caracteres, al la que denominaremos <i>format</i> y un número indeterminado de variables (argumentos) en múltiples formatos. El tipo de formato es determinado por el caracter '%' en <i>format</i> seguido de uno de los caracteres "cspdiuxX%".

La función imprime la cadena <i>format</i> junto con los argumentos en el orden establecido. Además, devuelve como valor de salida el número de caracteres que ha imprimido. Si detecta un problema, devuelve como valor -1.
Es posible variar el formato con <i>flags</i>, así como una anchura mínima y una precisión.

## Instrucciones

### Compliación

Para compilar la librería únicamente es necesario escribir make en la raíz del directorio en el que se encuentre el Makefile. Dicho Makefile posee las reglas all, clean, fclean y re. El resultado final será una librería denominada <i>libft.a</i>.

### Ejecución

Para ejecutar un programa .c con la función ft_printf es necesario incluir la cabecera "ft_printf.h" al principio de dicho programa. Para que compile únicamente será necesario escribir en el terminal

```bash
cc [*.c] ft_printf.a
```

### Funcionamiento

Para usar ft_printf es necesario seguir el formato

```vim
ft_printf(char *format, ...)
```

Para escribir un argumento se debe escribir en el formato un caracter '%' seguido de un identificador. Estos pueden ser:
- %c: escribe un caracter.
- %s: escribe una cadena de caracteres.
- %p: escribe un puntero en formato hexadecimal.
- %d y %i: escriben un número entero (formato <i>int</i>). No existe ninguna diferencia entre ambos.
- %u: escribe un número entero  sin signo.
- %x y %X: escriben un número hexadecimal desde su forma decimal. Ponen los dígitos abcdef en minúscula y mayúscula respectivamente.
- %%: escribe simplemente un símbolo de porcentaje. No requiere argumento.

Alternativamente se pueden usar flags y definir la anchura mínima y la precisión. Para ello se debe indicar tras el '%' y antes del identificador. Siempre deben tener el siguiente orden:
```vim
ft_printf("%[flags][anchura].[precisión]a", ...)
```
- Flags: cambian el formato del argumento. La función ft_printf tiene cinco flags:
  - -: En vez de añadir espacios a la izquierda los añade a la derecha. Tiene prioridad sobre la flag '0'.
  - 0: Sustituye los espacios por ceros. No funciona si la precisión está definida.
  - #: Imprime una versión alternativa. Sólo funciona con los identificadores %x y %X, añadiendo los caracteres "0x" y "0X" respectivamente.
  - +: Funciona con los identificadores %d, %i y %p. Añade un símbolo '+' a los números positivos con el fin de justificarlos con los negativos. Tiene prioridad sobre la flag ' '.
  - Espacio: Lo mismo que '+', pero añade un espacio.
- Anchura mínima: se define como el número mínimo de caracteres que deben imprimirse. Si no existen flags añade espacios a la izquierda. Para el identificador %% siempre será igual a 1.
- Precisión: al imprimir números indica el número de dígitos que se han de escribir. Debe empezar antes de un punto. Si es mayor que las cifras del número añadirá ceros a la izquierda.

## Algoritmo

El algoritmo utilizado fue el siguiente:

Empieza protegiendo la función contra formato nulo. Luego va iterando sobre el formato escribiéndolo. Si detecta un % buscará flags. Si no las detecta hará un algoritmo de impresión simple para no reservar memoria para las flags. Si ve que el número de caracteres imprimidos es en algún momento -1, deja de iterar y devuelve -1. Si no, va sumando el número de caracteres mientras los imprime.

Si en algún momento detecta una flag pasa a n algoritmo de impresión más complejo. Empieza reservando memoria para una estructura de 7 números enteros: 5 para cada flag, una para a  anchura mínima y otra para la precisión. Primero asigna un cero a cada flag y les va asignando 1 a medida que las encuentra. Después asigna la anchura mínima y la precisión, siendo 0 y -1 respectivamente en caso de que no las encuentre. Esta precisión negativa será importante porque si es cero y la flag '0' está activada no se imprimirán ceros, sino espacios. Cuando ha terminado, aplica el algoritmo de impresión complejo. Finalmente, libera la memoria de la estructura.

En el algoritmo complejo, primero cuenta el número de caracteres que normalmente imprimiría el simple. Luego añade espacios a la izquierda si no está marcada la flag '-'. Este proceso normalmente tiene su función. Después añade el argumento. Finalmente, si se marca la flag '-' resta el número de caracteres imprimidos durante el proceso a la anchura y añade espacios hasta que la anchura sea cero.

La impresión a la izquierda requiere comparar la precisión y la anchura. Si la primera es mayor que la segunda imprime el signo si lo hay y los ceros. Si no lo es se mira si la bandera '-' está marcada. Si lo está imprime los ceros y el signo. Si no, mira si la precisión es negativa y la bandera '0' está marcada. Si ambas se cumplen imprime el signo y los ceros. De lo contrario imprime un número de espacios hasta anchura llega al número de caracteres a imprimir más el signo.

Antes de imprimir los ceros imprime primero el signo, ya sea +, -, espacio o 0x. Luego mira si la condición del párrafo anterior. Si se cumple añade ceros hasta que la anchura pasa a ser el número de caracteres a imprimir. Si no, hace lo mismo pero cn la precisión.

## Recursos

La página web https://es.cppreference.com/c/variadic me ayudó a comprender qué era una función variádica.

Para entender sobre el funcionamiento de la función printf se ha investigado su apartado en W3Schools (https://www.w3schools.com/c/ref_stdio_printf.php).

Para realizar pruebas se usó la francinette (https://github.com/WaRtr0/francinette-image).

No se ha utilizado inteligencia artficial para este proyecto.
