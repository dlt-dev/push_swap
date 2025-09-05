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

Événements : 

    mlx_hook(win, event, mask, func, param); 
    mlx_mouse_hook(win, func, param);
    mlx_key_hook(win, func, param); 
    mlx_loop(mlx);
    
// Contrôles usuels

- Flèches ←↑→↓ : 
  déplacer la vue.

- + / - ou scroll souris : 
  zoom/dézoom. 

- ESC :
  quitter le programme.

- C :
  color shifting


// Gestion des couleurs

Les couleurs viennent du nombre d’itérations avant divergence : 
chaque pixel est itéré jusqu’à un maximum (max_iter).
Si le point diverge vite, il reçoit une couleur claire/vive ; 
s’il diverge lentement ou jamais, une autre couleur.
On applique ensuite une palette ou un dégradé en fonction de ce nombre d’itérations, ce qui révèle les formes fractales.
