# push_swap

// But du projet

Créer un programme graphique interactif qui affiche des fractales (Mandelbrot, Julia, etc.) en
utilisant MiniLibX. Objectifs : 
- Comprendre la récursivité et les ensembles fractals. 
- Manipuler les pixels, couleurs, zooms, déplacements. 
- Gérer les événements clavier/souris.

// Notions mathématiques

Ensemble de Mandelbrot : 

  z(0) = 0 z(n+1) = z(n)^2 + c 
  
      c = point du plan complexe associé au pixel.
      Si |z(n)| > 2 → le point diverge (n’appartient pas à l’ensemble). 
      Le nombre d’itérations avant divergence détermine la couleur. 

Ensemble de Julia : 

  Même formule mais : z(0) = pixel 
  
      c = constante fixée par l’utilisateur. 
      Conversion coordonnées écran → plan complexe : 
      - re = min_re + x *(max_re - min_re) / width im = max_im - y * (max_im - min_im) / height 
      - width, height = dimensions de la fenêtre 
      - min_re, max_re, min_im, max_im = bornes du plan complexe 
      - re = partie réelle, im = partie imaginaire

// MiniLibX (MLX)

Initialisation : 

    mlx = mlx_init(); 
    win = mlx_new_window(mlx, width, height, "fract-ol"); 
    Images : img = mlx_new_image(mlx, width, height); 
    addr = mlx_get_data_addr(img, &bpp;, &line;_len, &endian;);

Événements : mlx_hook(win, event, mask, func, param); mlx_mouse_hook(win, func, param);
mlx_key_hook(win, func, param); mlx_loop(mlx);
Contrôles usuels
- Flèches ←↑→↓ : déplacer la vue. - + / - ou scroll souris : zoom/dézoom. - Clic souris : zoom
centré. - ESC : quitter le programme.
Gestion des couleurs
Basée sur le nombre d’itérations avant divergence. Exemple : color = (iter * 255 / max_iter) << 16; //
dégradé rouge Possibilités : palettes, cycles de couleurs, interpolation.
Structure type
1. Init MLX (fenêtre + image). 2. Définir paramètres fractale (min_re, max_re, etc.). 3. Boucler sur
chaque pixel → calcul fractale → couleur → écrire dans image. 4. mlx_put_image_to_window pour
afficher. 5. Gestion événements clavier/souris → redessiner si nécessaire.
Astuces et pièges
- Redessiner seulement après un zoom/déplacement (pas en boucle infinie). - Conversion pixel →
complexe : bien gérer bornes. - Fermer proprement (mlx_destroy_window, mlx_destroy_image). -
Vérifier malloc/free (structures, palettes). - Utiliser double pour la précision des calculs.
