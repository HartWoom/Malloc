SBRK renvoie la position de fin du programme précédent

Pour malloc : on alloue un block de taille multiple d'une page sous forme d'une liste chainée
     	      si un bloc est libre on l'utilise en attribuant la value à l'intérieur
	      (faire attention, si le nouveau pointeur est plus gros que l'ancien, on ne
	      peut pas reallouer dans l'ancien ptr)

Pour free : on récupère la position du bloc grâce à l'adresse du pointeur membre
     	    si le block est le dernier de la liste d'allocated, on libère la mémoire
	    sinon on le marque en tant que free et on le passe dans la list freed
	    

Pour realloc : si la size est de 0 ou que le void * est NULL => simple call to malloc
     	       sinon allouer un nouveau block de la nouvelle et memcpy l'ancien dans le
	       nouveau




BUT DU MARKDOWN (POUR HARTWIG) :

Utilise le langage markdown pour mettre en forme de manière stylé c'que j'ai écris plus haut, pourquoi pas détaillés plus histoire que ça ressemble à un man.
Si tu veux avoir un rendu de c'que ça donne j'pense tu peux trouver des lecteurs de markdown online
