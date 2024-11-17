#include "minimap.h"
#include <printf.h>

int showMinimap = 1;

void toggleMinimap()
{
    showMinimap = !showMinimap;
}

void drawMinimap(int mapW[], int mapX, int mapY, float px, float py, float pdx, float pdy, sprite sp[], int spriteCount)
{
    if (!showMinimap)
    {
        return;
    }

    // Reset projection and model view
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 960, 640, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    int x, y;

    // Draw map tiles
    for (y = 0; y < mapY; y++)
    {
        for (x = 0; x < mapX; x++)
        {
            if (mapW[y * mapX + x] > 0)
                glColor3f(1.0f, 0.0f, 0.0f); // Walls - Red
            else
                glColor3f(0.0f, 1.0f, 0.0f); // Floors - Green

            float x0 = MINIMAP_X + x * MINIMAP_TILE_SIZE;
            float y0 = MINIMAP_Y + y * MINIMAP_TILE_SIZE;
            float x1 = x0 + MINIMAP_TILE_SIZE;
            float y1 = y0 + MINIMAP_TILE_SIZE;

            glBegin(GL_QUADS);
            glVertex2f(x0, y0);
            glVertex2f(x1, y0);
            glVertex2f(x1, y1);
            glVertex2f(x0, y1);
            glEnd();
        }
    }

    // Draw sprites
    for (int i = 0; i < spriteCount; i++)
    {
        if (sp[i].state == 1)
        {
            glColor3f(0.0f, 0.0f, 1.0f); // Sprites - Blue
            float sx_minimap = MINIMAP_X + (sp[i].x / mapS) * MINIMAP_TILE_SIZE;
            float sy_minimap = MINIMAP_Y + (sp[i].y / mapS) * MINIMAP_TILE_SIZE;
            float sprite_size = MINIMAP_TILE_SIZE / 3.0f;

            glBegin(GL_QUADS);
            glVertex2f(sx_minimap - sprite_size / 2, sy_minimap - sprite_size / 2);
            glVertex2f(sx_minimap + sprite_size / 2, sy_minimap - sprite_size / 2);
            glVertex2f(sx_minimap + sprite_size / 2, sy_minimap + sprite_size / 2);
            glVertex2f(sx_minimap - sprite_size / 2, sy_minimap + sprite_size / 2);
            glEnd();
        }
    }

    // Draw player
    glColor3f(1.0f, 1.0f, 0.0f); // Player - Yellow
    float px_minimap = MINIMAP_X + (px / mapS) * MINIMAP_TILE_SIZE;
    float py_minimap = MINIMAP_Y + (py / mapS) * MINIMAP_TILE_SIZE;
    float player_size = MINIMAP_TILE_SIZE / 3.0f;

    glBegin(GL_QUADS);
    glVertex2f(px_minimap - player_size, py_minimap - player_size);
    glVertex2f(px_minimap + player_size, py_minimap - player_size);
    glVertex2f(px_minimap + player_size, py_minimap + player_size);
    glVertex2f(px_minimap - player_size, py_minimap + player_size);
    glEnd();

    // Draw player direction
    glColor3f(1.0f, 0.5f, 0.0f); // Direction - Orange
    glBegin(GL_LINES);
    glVertex2f(px_minimap, py_minimap);
    glVertex2f(px_minimap + pdx * 20 * MINIMAP_SCALE, py_minimap + pdy * 20 * MINIMAP_SCALE);
    glEnd();
}
