#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Space.h"

#define laranja 25, 0, 25, 25
#define azul 25, 25, 25, 25
#define roxo 25, 50, 25, 25
#define vermelho 25, 75, 25, 25
#define amarelo 25, 100, 25, 25
#define verde 25, 125, 25, 25


bool draw_blocks(space game, ALLEGRO_BITMAP* texture)
{
	for (int i = 0; i < 10; i++)
	{
		column currentcolumn = game.bloquinhogetline(i);
		for (int u = 0; u < 5; u++)
		{
			block currentblock = currentcolumn.getblock(u);

			cout << "\ncoluna: " << i << endl;
			cout << "linha   : " << u << endl;
			cout << "cor     : " << currentblock.getcolor() << endl;

			if (currentblock.getcolor() != 0)
			{
				switch (currentblock.getcolor())
				{
				case 1:
					al_draw_scaled_bitmap(texture, laranja, 150 + (currentblock.getcolumn() * 50), (HIGH_DISPLAY - 50) - (currentblock.getline() * 50), 50, 50, NULL);
					break;
				case 2:
					al_draw_scaled_bitmap(texture, azul, 150 + (currentblock.getcolumn() * 50), (HIGH_DISPLAY - 50) - (currentblock.getline() * 50), 50, 50, NULL);
					break;
				case 3:
					al_draw_scaled_bitmap(texture, roxo, 150 + (currentblock.getcolumn() * 50), (HIGH_DISPLAY - 50) - (currentblock.getline() * 50), 50, 50, NULL);
					break;
				case 4:
					al_draw_scaled_bitmap(texture, vermelho, 150 + (currentblock.getcolumn() * 50), (HIGH_DISPLAY - 50) - (currentblock.getline() * 50), 50, 50, NULL);
					break;
				case 5:
					al_draw_scaled_bitmap(texture, amarelo, 150 + (currentblock.getcolumn() * 50), (HIGH_DISPLAY - 50) - (currentblock.getline() * 50), 50, 50, NULL);
					break;
				case 6:
					al_draw_scaled_bitmap(texture, verde, 150 + (currentblock.getcolumn() * 50), (HIGH_DISPLAY - 50) - (currentblock.getline() * 50), 50, 50, NULL);
					break;
				default:
					al_draw_scaled_bitmap(texture, verde, 150 + (currentblock.getcolumn() * 50), (HIGH_DISPLAY - 50) - (currentblock.getline() * 50), 50, 50, NULL);
					break;
				}
			}
		}
	}
	return true;
}

int main()
{
	/* Game variables and constants */
	int contador = 0;
	bool stop = false;
	ALLEGRO_FONT* font = NULL;
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_BITMAP* backgound = NULL;
	ALLEGRO_BITMAP* hominho = NULL;
	ALLEGRO_BITMAP* blockimg = NULL;
	space gamespace;

	/* Allegro display creation and initialization */
	if (!al_init())
	{
		al_show_native_message_box(NULL, "Error", "Critical Error", "Unable to initialize Allegro",NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	display = al_create_display(LENGHT_DISPLAY, HIGH_DISPLAY);
	if (!display)
	{
		al_show_native_message_box(NULL, "Error", "Critical Error", "Unable create display", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	timer = al_create_timer(1.0);

	/* Devicesand addons initialization */
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	/* Textures, fonts, videos and sounds loalding */
	hominho = al_load_bitmap("objects/images/psicopattack.png");
	blockimg = al_load_bitmap("objects/images/blocks.bmp");
	if ((hominho == NULL) || (blockimg == NULL))
	{
		al_show_native_message_box(NULL, "Error", "Critical Error", "Unable load textures", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	
	font = al_load_font("objects/fonts/tnr.ttf", 20, NULL);
	if (font == NULL)
	{
		al_show_native_message_box(NULL, "Error", "Critical Error", "Unable load font", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	/* Event queueand source registers */
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	block newblock;
	newblock.setcolor(2);
	gamespace.insertblock(newblock,3,2);

	while (!stop)
	{
		ALLEGRO_EVENT event;		
		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {};
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				stop = true;
			}

			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_RIGHT:
				gamespace.hominhomovright();
				gamespace.fall();
				break;
			case ALLEGRO_KEY_LEFT:
				gamespace.hominhomovleft();
				gamespace.fall();
				break;
			case ALLEGRO_KEY_UP:
				gamespace.hominhojump();
				break;
			}
		}
		if (event.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				gamespace.fall();
				break;
			}
		}


		// Logical game space
		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			stop = true;
		}


		/* Game drawing and drawing controller */
		/* Game frame update */
		al_draw_bitmap(hominho, 150 + (gamespace.getcolumn()*50), (HIGH_DISPLAY-100)-(gamespace.getline()*50), NULL);
		draw_blocks(gamespace,blockimg);
		//al_draw_scaled_bitmap(blockimg, azul, 150 + (gamespace.bloquinhogetline(3).getblock(1).getcolumn() * 50), (high_display - 50) - (gamespace.bloquinhogetline(1).getblock(10).getline() * 50), 50, 50, NULL);
		al_draw_textf(font, al_map_rgb(255, 255, 255), LENGHT_DISPLAY / 2, HIGH_DISPLAY / 2, ALLEGRO_ALIGN_CENTRE, "Contador: %d", al_get_timer_count(timer));
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	// Free memory and game stoping
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_font(font);
	al_destroy_bitmap(backgound);
	al_destroy_bitmap(hominho);
	al_destroy_bitmap(blockimg);
	al_destroy_display(display);
}