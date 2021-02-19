var nb_semaine = 3 ;
var nb_groupe = 3 ;
var nb_joueur = operation ( nb_groupe * nb_semaine ) ;
var taille_groupe = nb_semaine ;
set all_joueur = nb_joueur ;
array dec ladder ( nb_semaine,nb_groupe ) all_joueur ;
constraint Forall ( i,nb_semaine ) ( Forall ( j,nb_groupe ) ( Equal ( nb_semaine,taille_groupe ) ) ) ;
constraint Forall ( i,nb_semaine ) ( Forall ( j,nb_groupe ) ( Equal ( Card ( ladder ( i,j ) ) , taille_groupe ) ) ) ;
constraint Forall ( i,nb_semaine ) ( Forall ( k,nb_groupe ) ( Forall ( l,nb_groupe ) ( Disjonction ( Equal ( k,l ) , Conjonction ( Different ( k,l ) , Equal ( Intersection ( ladder ( i,k ) , ladder ( i,l ) ) , 0 ) ) ) ) ) ) ;
