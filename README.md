# So Long - 2D Game Project

## Description
A small 2D game where the player collects items and reaches the exit. This project demonstrates the use of textures, sprites, and basic gameplay elements using the MiniLibX graphics library.

## Features

### Sprite Animation (Bonus)
The game includes animated sprites for a more dynamic visual experience:

- **Player Animation**: The player character cycles through 3 animation frames
- **Collectible Animation**: Collectibles cycle through 3 animation frames
- **Timing**: Animation updates every 200ms (200,000 microseconds) using `gettimeofday()`

#### Implementation Details
- Animation frames are stored in arrays within the `t_mlx_img` structure
- Frame cycling is handled by `animate_sprites()` function called via `mlx_loop_hook()`
- Separate frame counters for player and collectibles allow independent animation
- Time-based animation ensures consistent speed regardless of frame rate

#### Sprite Files
Animation frames are loaded from:
- Player: `P.xpm`, `P_1.xpm`, `P_2.xpm`
- Collectibles: `C.xpm`, `C_1.xpm`, `C_2.xpm`

## Building

```bash
make
```

## Running

```bash
./so_long maps_so_long/maps_valid/ok.ber
```

## Controls
- W/↑: Move up
- A/←: Move left
- S/↓: Move down
- D/→: Move right
- ESC: Exit game

## Compliance
This project follows La Norme (42 coding standard) and passes norminette validation.
