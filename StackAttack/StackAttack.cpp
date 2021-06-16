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
	// Game variables
	const int length_display = 800;
	const int high_display = 600;
	bool stop = false;
	bool teclas[] = { false, false, false, false };
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_BITMAP* backgound = NULL;

	space gamespace;


	// Allegro display and initialization
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

	// Devices and addons initialization
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	// Event queue and source registers
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	while (!stop)
	{
		ALLEGRO_EVENT event;

		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				stop = true;
			}

			// Logical game space
		}

		else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			stop = true;
		}

		// Game flowability

		// Game drawing
		al_flip_display();
	}

	// Free memory and game stoping
	al_destroy_event_queue(event_queue);
	al_destroy_bitmap(backgound);
	al_destroy_display(display);
}