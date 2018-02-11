**SBRK** renvoie la position de fin du programme précédent.

* **malloc** : On alloue un bloc de taille multiple d'une page sous forme d'une liste chainée.
    Si un bloc est libre, on l'utilise en attribuant la valeur à l'intérieur.
    (****Attention***, si le nouveau pointeur que l'on viens d'allouer est plus gros que l'ancien, on ne peut pas le reallouer dans l'ancien pointeur*)

* **free** : On récupère la position du bloc grâce à l'adresse du pointeur membre.
    Si le bloc est le dernier de la liste *allocated_list*, on libère la mémoire.
    Si le bloc n'est pas le dernier, on le marque en tant que *free* et on le passe dans la liste *freed*.

* **realloc** : Si la taille du block est de 0, ou que le **void** * est NULL, on fait un simple appel de notre fonction malloc.
    Sinon, on alloue un nouveau bloc de la taille de l'ancien et de la taille et on copie l'ancien bloc dans le nouveau.
