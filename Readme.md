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

#### *Largeur de champ* :

Un nombre optionnel ne commençant pas par un zéro, peut indiquer une **largeur minimale
de champ**. Si la valeur convertie occupe moins de caractères que cette largeur, 
elle sera complétée par des **espaces à gauche** (**ou à droite si l'attribut d'alignement 
à gauche a été fourni**). À la place de la chaîne représentant le nombre décimal, 
on peut écrire « * » ou « \*m$ » (m étant entier) **pour indiquer que la largeur 
du champ est fournie dans l'argument suivant, ou dans le m-ième argument, 
respectivement**. L'argument fournissant **la largeur doit être de type int**. 
**Une largeur négative est considéré comme l'attribut « - »** vu plus haut suivi 
d'une largeur positive. **En aucun cas une largeur trop petite ne provoque la 
troncature du champ**. Si le résultat de **la conversion est plus grand que la largeur** 
indiquée, **le champ est élargi pour contenir le résultat**.

#### *Précision* :

Une précision éventuelle, **sous la forme d'un point (« . ») suivi par un nombre**.
À la place de la chaîne représentant le nombre décimal, on peut écrire « * » ou « \*m$ » 
(m étant entier) **pour indiquer que la précision est fournie dans l'argument suivant, 
ou dans le m-ième argument, respectivement**. **L'argument fournissant la précision 
doit être de type int**. **Si la précision ne contient que le caractère « . », ou une 
valeur négative, elle est considérée comme nulle**. Cette précision indique **un nombre 
minimum de chiffres à faire apparaître lors des conversions d, i, o, u, x, et X**, 
**le nombre maximum de caractères à imprimer depuis une chaîne pour les conversions s et S**.

#### *Modificateur de longueur* :

Ici, une conversion entière correspond à **d, i, o, u, x ou X**.

* **hh**
	* La conversion entière suivante correspond à un signed char ou unsigned char, 
	ou la conversion n suivante correspond à un argument pointeur sur un signed char.
* **h**
	* La conversion entière suivante correspond à un short int ou unsigned short int, 
	ou la conversion n suivante correspond à un argument pointeur sur un short int.
* **l**
	* La conversion entière suivante correspond à un long int ou unsigned long int, 
	ou la conversion n suivante correspond à un pointeur sur un long int, ou la 
	conversion c suivante correspond à un argument wint_t, ou encore la conversion s 
	suivante correspond à un pointeur sur un wchar_t.
* **ll**
	* La conversion entière suivante correspond à un long long int, ou unsigned long long int, 
	ou la conversion n suivante correspond à un pointeur sur un long long int.
* **j**
	* La conversion entière suivante correspond à un argument intmax_t ou uintmax_t.
* **z**
	* La conversion entière suivante correspond à un argument size_t ou ssize_t. 

#### *Indicateur de conversion* :

Un caractère indique le type de conversion à apporter. Les indicateurs de conversion, 
et leurs significations sont :

* **d, i**
L'argument int est converti en un chiffre décimal signé. **La précision, si elle est mentionnée, 
correspond au nombre minimal de chiffres qui doivent apparaître**. **Si la conversion fournit 
moins de chiffres, le résultat est rempli à gauche avec des zéros**. **Par défaut la précision vaut 1**. 
Lorsque 0 est converti avec une précision valant 0, la sortie est vide.

* **o, u, x, X**
L'argument unsigned int est converti en un chiffre octal non signé (o), un chiffre 
décimal non signé (u), un chiffre hexadécimal non signé (x et X). Les lettres abcdef 
sont utilisées pour les conversions avec x, les lettres ABCDEF sont utilisées pour 
les conversions avec X. **La précision, si elle est indiquée, donne un nombre minimal 
de chiffres à faire apparaître**. **Si la valeur convertie nécessite moins de chiffres, 
elle est complétée à gauche avec des zéros**. **La précision par défaut vaut 1**. 
Lorsque 0 est converti avec une précision valant 0, la sortie est vide.

* **c**
	* **S'il n'y a pas de modificateur l**, l'argument entier, de type int, est converti 
	en un unsigned char, et le caractère correspondant est affiché. 
	* **Si un modificateur l est présent**, l'argument de type wint_t (caractère large) est 
	converti en séquence multi-octet, avec un état de conversion débutant dans l'état initial. 
	La chaîne multi-octet résultante est écrite.

* **s**
	* **S'il n'y a pas de modificateur l**, l'argument de type const char * est 
	supposé être un pointeur sur un tableau de caractères (pointeur sur une chaîne). 
	Les caractères du tableau sont écrits jusqu'à l'octet nul « \0 » final, non compris. 
	Si une précision est indiquée, seul ce nombre de caractères sont écrits. Si une 
	précision est fournie, il n'y a pas besoin d'octet nul. Si la précision n'est 
	pas donnée, ou si elle est supérieure à la longueur de la chaîne, l'octet nul 
	final est nécessaire.
	* **Si un modificateur l est présent**, l'argument de type const wchar_t * 
	est supposé être un pointeur sur un tableau de caractères larges. Les 
	caractères larges du tableau sont convertis en une séquence de caractères 
	multi-octets (chacun par un appel de wcrtomb(3), avec un état de conversion 
	dans l'état initial avant le premier caractère large), ceci jusqu'au caractère 
	large nul final compris. Les caractères multi-octets résultants sont écris 
	jusqu'à l'octet nul final (non compris). Si une précision est fournie, 
	il n'y a pas plus d'octets écrits que la précision indiquée, mais aucun 
	caractère multi-octet n'est écrit partiellement. Remarquez que la précision 
	concerne le nombre d'octets écrits, et non pas le nombre de caractères larges 
	ou de positions d'écrans. La chaîne doit contenir un caractère large nul final, 
	sauf si une précision est indiquée, suffisamment petite pour que le nombre 
	d'octets écrits la remplisse avant la fin de la chaîne.

* **C**
Synonyme de lc.

* **S**
Synonyme de ls.

* **p**
L'argument pointeur, du type void * est affiché en hexadécimal, comme avec %#x ou %#lx.

* **b**
Converti un argument de type int en binaire.

* **%**
Un caractère « % » est écrit. Il n'y a pas de conversion. L'indicateur complet est « %% ».

#### *Indicateur de couleurs de sortie* :

* **{green}** : toute la sortie sera en **vert** sauf si il est terminer dans 
	**la chaine format** par l'indicateur **{EOC}**.
* **{red}** : toute la sortie sera en **rouge** sauf si il est terminer dans 
	**la chaine format** par l'indicateur **{EOC}**.
* **{blue}** : toute la sortie sera en **bleu** sauf si il est terminer dans 
	**la chaine format** par l'indicateur **{EOC}**.
* **{pink}** : toute la sortie sera en **rose** sauf si il est terminer dans 
	**la chaine format** par l'indicateur **{EOC}**.
* **{cyan}** : toute la sortie sera en **cyan** sauf si il est terminer dans 
	**la chaine format** par l'indicateur **{EOC}**.
* **{EOC}** : Stoppe la sortie d'une couleur defini par un indicateur de couleur 
	dans **la chaine format** ou est ignoré, si il n'y pas d'indicateur de couleurs
	précédemment.

#### *Liens* :

* **printf**
	* http://manpagesfr.free.fr/man/man3/printf.3.html
	* http://alain.dancel.free.fr/c/c60_10.htm
	* https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_72/rtref/printf.htm

* **wchar**
	* https://en.wikibooks.org/wiki/C_Programming/C_Reference/wchar.h
	* http://stackoverflow.com/questions/15528359/printing-utf-8-strings-with-printf-wide-vs-multibyte-string-literals
	* https://en.wikipedia.org/wiki/UTF-8
	* http://stackoverflow.com/questions/12996062/how-to-initialize-a-wchar-t-variable
	* http://unicode-table.com/fr/blocks/
	* http://stackoverflow.com/questions/2241348/what-is-unicode-utf-8-utf-16
	* http://www.cprogramming.com/tutorial/unicode.html

* **va_args**
	* https://msdn.microsoft.com/fr-fr/library/kb57fad8.aspx
	* http://alain.dancel.free.fr/c/c70_140.htm
		



