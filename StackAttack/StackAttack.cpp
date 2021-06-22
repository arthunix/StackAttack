#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Space.h"

enum TECLAS {UP, DOWN, RIGHT, LEFT};

int main()
{
	/* Game variables and constants */
	const int length_display = 800;
	const int high_display = 600;
	const int FPS = 60;
	bool teclas[] = { false, false, false, false };
	int contador = 0;
	bool stop = false;
	ALLEGRO_FONT* font = NULL;
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_BITMAP* backgound = NULL;
	ALLEGRO_BITMAP* hominho = NULL;
	space gamespace;

	/* Allegro display creation and initialization */
	if (!al_init())
	{
		al_show_native_message_box(NULL, "Error", "Critical Error", "Unable to initialize Allegro",NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	display = al_create_display(length_display, high_display);
	if (!display)
	{
		al_show_native_message_box(NULL, "Error", "Critical Error", "Unable create display", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);

	/* Devicesand addons initialization */
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	/* Textures, fonts, videos and sounds loalding */
	hominho = al_load_bitmap("objects/images/psicopattack.png");
	if (hominho == NULL)
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
				teclas[RIGHT] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				teclas[LEFT] = true;
				break;
			case ALLEGRO_KEY_UP:
				teclas[UP] = true;
				break;
			}
		}

		if (event.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_RIGHT:
				teclas[RIGHT] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				teclas[LEFT] = false;
				break;
			case ALLEGRO_KEY_UP:
				teclas[UP] = false;
				break;
			}
		}

		// Logical game space

		else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			stop = true;
		}
		/*
		// Game flowability
		gamespace.setposx(gamespace.getposx() + (teclas[RIGHT] * 3));
		gamespace.setposx(gamespace.getposx() - (teclas[LEFT] * 3));

		if (teclas[UP])
		{
			gamespace.setposy(gamespace.getposy() - (teclas[UP] * 50));
			teclas[UP] = false;
		}
		// Game drawing
		al_draw_bitmap(hominho, gamespace.getposx(), gamespace.getposy(), NULL);
		al_draw_textf(font, al_map_rgb(255, 255, 255), length_display / 2, high_display / 2, ALLEGRO_ALIGN_CENTRE, "Contador: %d", al_get_timer_count(timer));
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));*/




		/* Game drawing and drawing controller */

		/* Game frame update */

		al_draw_textf(font, al_map_rgb(255, 255, 255), length_display / 2, high_display / 2, ALLEGRO_ALIGN_CENTRE, "Contador: %d", al_get_timer_count(timer));
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	// Free memory and game stoping
	al_destroy_event_queue(event_queue);
	al_destroy_bitmap(hominho);
	al_destroy_timer(timer);
	al_destroy_font(font);
	al_destroy_bitmap(backgound);
	al_destroy_display(display);
}