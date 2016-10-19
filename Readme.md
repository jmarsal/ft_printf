# *ft_printf*

### SYNOPSYS :
``` c
	#include "ft_printf.h"

	int ft_printf(const char *format, ...);
```

### DESCRIPTION :

* La fonction ft_printf() produit une sortie en accord avec le **format**.
* La fonction ft_printf() écrit sa sortie sur **stdout**, le flux de sortie standard.
* Cette fonction crée sa sortie sous le contrôle d'une **chaîne de format** qui indique
**les conversions à apporter aux arguments** accessibles à travers les arguments
de taille variable de stdarg(3).

### VALEUR RENVOYÉE :

* Si elle réussit, la fonction renvoi le nombre de caractères imprimés,
sans compter l'octet nul « \0 » final dans les chaînes.
* Si une erreur de sortie s'est produite, une valeur négative est renvoyée.

#### *Chaîne de format* :

**Le format de conversion** est *indiqué* par **une chaîne de caractères**, 
commençant et se terminant dans son état de décalage initial.
* 1. **La chaîne de format** est composée d'**indicateurs** :
	* 1. **les caractères ordinaires** (différents de %), qui sont copiés sans
	modification sur la sortie.
	* 2. **les spécifications de conversion**, qui sont mises en correspondance 
	avec les arguments suivants.
	* 3. **les spécifications de couleurs**.
* 2. **Les spécifications de conversion** sont introduites par le 
caractère **%**, et se terminent par un **indicateur de conversion**. *Entre eux
peuvent se trouver (dans l'ordre)* :
	* 1. **zéro ou plusieurs attributs**.
	* 2. **une valeur optionnelle de largeur minimal de champ**.
	* 3. **une valeur optionnelle de précision**.
	* 4. **un éventuel modificateur de longueur**.
* 3. **Les spécificateurs de couleurs** sont introduites par le caractère **{** 
et se terminent par le carcatère **}**. Pour arreter à un endroit précis la mise
en couleurs de la sortie de la fonction, on y introduit un specificateur(optionnel) 
**{EOC}**.

#### *Caractère d'attribut* :

ft_printf prend en charge les atributs suivant : **#, 0, ' ' (space), +** et **-**.
Se référer au MAN 3 printf : http://manpagesfr.free.fr/man/man3/printf.3.html.



