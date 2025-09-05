# push_swap

// Notions apprises

- Listes chaînées : 
    représentation efficace des piles a et b. 
- Opérations atomiques : 
    sa/sb/ss, pa/pb, ra/rb/rr, rra/rrb/rrr. 
- Indexation : 
    associer un rang (index) à chaque valeur pour simplifier les comparaisons. 
- Rotation optimisée : 
    combiner les moves (rr, rrr) pour réduire le nombre d’instructions. 
- Complexité : minimiser les coups (~700 max pour 100 valeurs, ~5500 max pour 500 valeurs).

// Stratégie

Index inversé : 
- Plus petit élément = plus grand index. 
- Plus grand élément = plus petit index. → Simplifie les comparaisons pour le tri. 

Division initiale : 
- On pousse la moitié des éléments de a vers b (via médiane / chunks). 
- Objectif : réduire le problème en morceaux plus petits. 

Calcul de coût pour chaque élément de b : 
  - cost_a = rotations nécessaires pour placer l’élément dans a. 
  - cost_b = rotations nécessaires pour amener l’élément en haut de b. 
  - total_cost = |cost_a| + |cost_b|. 

Choix du cheapest move :   
  - Sélection de l’élément de b avec le total_cost le plus faible. 
  - Rotations combinées si cost_a et cost_b ont le même signe. 

Retour progressif de b → a : 
  - On replace les éléments un par un dans l’ordre correct. 
  - Ajustement final de a pour ramener le minimum en haut.
