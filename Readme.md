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

#### Chaîne de format :

* Le format de conversion est *indiqué* par **une chaîne de caractères**, commençant et
se terminant dans son état de décalage initial.
* **La chaîne de format** est composée d'**indicateurs** :
	* les caractères ordinaires (différents de %), qui sont copiés sans modification sur la sortie.
	* **les spécifications de conversion**, qui sont mises en correspondance avec les arguments suivants.
* Les spécifications de conversion sont introduites par le caractère **%**, et se terminent par un **indicateur
de conversion**.
* *Entre eux peuvent se trouver (dans l'ordre)* :
	* **zéro ou plusieurs attributs**.
	* **une valeur optionnelle de largeur minimal de champ**.
	* **une valeur optionnelle de précision**.
	* **un éventuel modificateur de longueur**.

