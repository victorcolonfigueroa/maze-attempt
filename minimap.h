#ifndef MINIMAP_H
#define MINIMAP_H

#include <GL/glut.h>
#include "sprite.h"

// Constants
#define mapS 64
#define MINIMAP_SCALE 0.2
#define MINIMAP_X 10
#define MINIMAP_Y 10
#define MINIMAP_TILE_SIZE (mapS * MINIMAP_SCALE)
extern int showMinimap;

// Function declarations
void drawMinimap(int mapW[], int mapX, int mapY, float px, float py, float pdx, float pdy, sprite sp[], int spriteCount);
void toggleMinimap();

#endif
