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
	if (bmp == NULL) {
		cout << "erro" << endl;
	}
	comp = al_get_bitmap_width(bmp);
	altu = al_get_bitmap_height(bmp);

	al_draw_bitmap(bmp, comp/2, altu/2, 0);
	al_flip_display();
	al_rest(10.0);
	al_destroy_bitmap(bmp);
	al_destroy_display(display);
}