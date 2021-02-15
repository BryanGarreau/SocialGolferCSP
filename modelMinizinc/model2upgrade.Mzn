var nb_semaine=3;
var nb_groupe=3;
var nb_joueur=nb_groupe * nb_semaine;
var talle_groupe=nb_semaine;
set all_joueur=range(nb_joueur);
array [range(nb_semaine),range(nb_groupe)] all_joueur ladder;
