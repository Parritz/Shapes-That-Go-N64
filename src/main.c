#include <stdio.h>
#include <libdragon.h>
#define GRAVITY 0.5

int main() {
    static display_context_t display;
    display_init(RESOLUTION_512x240, DEPTH_16_BPP, 3, GAMMA_NONE, FILTERS_RESAMPLE);

    int levelBottomY = 208;
    float playerCurrentY = 100;
    float playerVelocityY = 0.0;

    while (1) {
        // Wait for display to be unlocked then lock it for the next frame
        while (!(display = display_lock())); 

        graphics_fill_screen(display, graphics_make_color(255, 255, 255, 1));
        graphics_draw_box(display, 100, playerCurrentY, 48, 32, graphics_make_color(255, 0, 0, 1));
        if (playerCurrentY < levelBottomY) {
            playerVelocityY += GRAVITY;
            playerCurrentY += playerVelocityY;

            if (playerCurrentY >= levelBottomY) {
                playerCurrentY = levelBottomY;
                playerVelocityY = 0.0;
            }
        }

        // Display frame and unlock it
        display_show(display);
    }
}