#include <iostream>
#include <Windows.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "Space.h"

int main() {
	al_init();
	al_install_keyboard();
	al_init_image_addon();

	int comp, altu;

	ALLEGRO_BITMAP* bmp = NULL;
	ALLEGRO_DISPLAY* display = al_create_display(800, 600);

	bmp = al_load_bitmap("objects/images/blocks.bmp");
	comp = al_get_bitmap_width(bmp);
	altu = al_get_bitmap_height(bmp);

	al_draw_bitmap(bmp, 800-comp, 600-altu, 0);
	al_draw_scaled_bitmap(bmp, 25, 75, 25, 25, 0, 0, 50, 50, 0);
	al_draw_scaled_bitmap(bmp, 25, 75, 25, 25, 50, 0, 50, 50, 0);

	al_flip_display();
	al_rest(30.0);
	al_destroy_bitmap(bmp);
	al_destroy_display(display);
}