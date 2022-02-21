#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#include "Game.h"

int StackAttack();

template<int sizeOfTheStack, int numberOfStacks>
void draw_blocks(Game<sizeOfTheStack, numberOfStacks> game, ALLEGRO_BITMAP* texture);

#define NUMBER_OF_COLUMNS_ON_SPACE 10
#define NUMBER_OF_BLOCKS_IN_COLUMN 11
#define LENGHT_DISPLAY_GAME_WINDOW 800
#define HIGH_DISPLAY_GAME_WINDOW 600

#define ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_ORANGE 25, 0, 25, 25
#define ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_BLUE 25, 25, 25, 25
#define ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_PURPLE 25, 50, 25, 25
#define ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_RED 25, 75, 25, 25
#define ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_YELLOW 25, 100, 25, 25
#define ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_GREEN 25, 125, 25, 25

int main()
{
    std::cout << "Hello World!" << std::endl;
    //Game<NUMBER_OF_BLOCKS_IN_COLUMN, NUMBER_OF_COLUMNS_ON_SPACE> gamespace;
	do {

	} while (StackAttack());

    return 0;
}

int StackAttack()
{
	/* Game variables and constants */
	int contador = 0;
	int score = 0;
	bool stop = false;
	bool restart = false;
	ALLEGRO_FONT* fonttnr = NULL;
	ALLEGRO_FONT* fontshowg20 = NULL;
	ALLEGRO_FONT* fontshowg100 = NULL;
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_BITMAP* background = NULL;
	ALLEGRO_BITMAP* hominho = NULL;
	ALLEGRO_BITMAP* hominhomorto = NULL;
	ALLEGRO_BITMAP* blockimg = NULL;
	ALLEGRO_SAMPLE* backgroundmusic = NULL;
	ALLEGRO_SAMPLE_INSTANCE* backgroundmusicinstance = NULL;
	Game<NUMBER_OF_BLOCKS_IN_COLUMN, NUMBER_OF_COLUMNS_ON_SPACE> gamespace;


	/* Allegro display creation and initialization */
	if (!al_init())
	{
		al_show_native_message_box(NULL, "Error", "Critical Error", "Unable to initialize Allegro", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	display = al_create_display(LENGHT_DISPLAY_GAME_WINDOW, HIGH_DISPLAY_GAME_WINDOW);
	if (!display)
	{
		al_show_native_message_box(NULL, "Error", "Critical Error", "Unable create display", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	timer = al_create_timer(1.0 / 2);

	/* Devicesand addons initialization */
	al_install_keyboard();
	al_install_audio();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_init_acodec_addon();

	al_reserve_samples(1);

	/* Textures, fonts, videos and sounds loalding */
	hominho = al_load_bitmap("resources/images/psicopattack.png");
	hominhomorto = al_load_bitmap("resources/images/psicopattackmorto.png");
	blockimg = al_load_bitmap("resources/images/blocks.bmp");
	background = al_load_bitmap("resources/images/background.jpg");
	backgroundmusic = al_load_sample("resources/sounds/EricSkiffANightOfDizzySpells.mp3");
	if ((hominho == NULL) || (hominhomorto == NULL) || (blockimg == NULL) || (background == NULL) || (backgroundmusic == NULL))
	{
		al_show_native_message_box(NULL, "Error", "Critical Error", "Unable load textures and resources", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	/* Music configuration */
	backgroundmusicinstance = al_create_sample_instance(backgroundmusic);
	al_set_sample_instance_playmode(backgroundmusicinstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(backgroundmusicinstance, al_get_default_mixer());

	fonttnr = al_load_font("resources/fonts/times.ttf", 20, NULL);
	fontshowg20 = al_load_font("resources/fonts/SHOWG.TTF", 20, NULL);
	fontshowg100 = al_load_font("resources/fonts/SHOWG.TTF", 100, NULL);
	if ((fonttnr == NULL) || (fontshowg20 == NULL) || (fontshowg100 == NULL))
	{
		al_show_native_message_box(NULL, "Error", "Critical Error", "Unable load fonts", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	/* Event queueand source registers */
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);
	//al_play_sample_instance(backgroundmusicinstance);
	
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
			if (event.keyboard.keycode == ALLEGRO_KEY_SPACE)
			{
				// Space for restart game
				restart = true;
				stop = true;
			}

			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_RIGHT:
				gamespace.movePlayerRight();
				gamespace.playerFallForever();
				break;
			case ALLEGRO_KEY_LEFT:
				gamespace.movePlayerLeft();
				gamespace.playerFallForever();
				break;
			case ALLEGRO_KEY_UP:
				gamespace.playerJump();
				break;
			}
		}
		if (event.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				gamespace.playerFallForever();
				break;
			}
		}

		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			//gamespace.blockfall();
			//gamespace.sethominholife();
			if (al_get_timer_count(timer) % 2 == 0)
			{
				gamespace.callGravity();
				int newColorOfTheInsertedBlock = rand() % 7;
				int newColumnOfTheInsertedBlock = rand() % 10;
				if (newColorOfTheInsertedBlock != BLOCK_INACTIVE)
				{
					gamespace.insertBlockAtTheColumn(newColorOfTheInsertedBlock, newColumnOfTheInsertedBlock);
				}
			}
			if (gamespace.flushAllFirstElementsInEachColumn())
			{
				score = score + 100;
				gamespace.playerFallForever();
			}
		}

		// Logical game space
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			stop = true;
		}

		/* Game drawing and drawing controller */
		/* Game frame update */
		al_draw_scaled_bitmap(background, 0, 0, al_get_bitmap_width(background), al_get_bitmap_height(background), 0, 0, LENGHT_DISPLAY_GAME_WINDOW, HIGH_DISPLAY_GAME_WINDOW, NULL);
		al_draw_bitmap(hominho, 150 + (gamespace.getPlayerPositionColumn() * 50), (HIGH_DISPLAY_GAME_WINDOW - 100) - (gamespace.getPlayerPositionLine() * 50), NULL);
		draw_blocks(gamespace, blockimg);
		if (!gamespace.checkPlayerLife())
		{
			al_draw_bitmap(hominhomorto, 150 + (gamespace.getPlayerPositionColumn() * 50), (HIGH_DISPLAY_GAME_WINDOW - 100) - (gamespace.getPlayerPositionLine() * 50), NULL);
			al_draw_text(fontshowg100, al_map_rgb(255, 255, 255), LENGHT_DISPLAY_GAME_WINDOW / 2, (HIGH_DISPLAY_GAME_WINDOW / 2) - 50, ALLEGRO_ALIGN_CENTER, "GAME OVER");
			al_draw_text(fontshowg20, al_map_rgb(255, 255, 255), LENGHT_DISPLAY_GAME_WINDOW / 2, (HIGH_DISPLAY_GAME_WINDOW / 2) + 45, ALLEGRO_ALIGN_CENTER, "Press space to restart");
			al_stop_timer(timer);
		}
		al_draw_textf(fontshowg20, al_map_rgb(255, 255, 255), LENGHT_DISPLAY_GAME_WINDOW - 10, 10, ALLEGRO_ALIGN_RIGHT, "Timer: %i", al_get_timer_count(timer));
		al_draw_textf(fontshowg20, al_map_rgb(255, 255, 255), LENGHT_DISPLAY_GAME_WINDOW - 10, 30, ALLEGRO_ALIGN_RIGHT, "Life: %i", gamespace.checkPlayerLife());
		al_draw_textf(fontshowg20, al_map_rgb(255, 255, 255), LENGHT_DISPLAY_GAME_WINDOW - 10, 50, ALLEGRO_ALIGN_RIGHT, "Score: %i", score);
		al_draw_text(fontshowg20, al_map_rgb(255, 255, 255), 0, 10, ALLEGRO_ALIGN_LEFT, "Left: LEFT KEY");
		al_draw_text(fontshowg20, al_map_rgb(255, 255, 255), 0, 30, ALLEGRO_ALIGN_LEFT, "Right: RIGHT KEY");
		al_draw_text(fontshowg20, al_map_rgb(255, 255, 255), 0, 50, ALLEGRO_ALIGN_LEFT, "Jump: UP KEY");
		al_draw_text(fontshowg20, al_map_rgb(255, 255, 255), 0, 70, ALLEGRO_ALIGN_LEFT, "Close: ESC");
		al_draw_text(fontshowg20, al_map_rgb(255, 255, 255), 0, 90, ALLEGRO_ALIGN_LEFT, "Restart: Space");
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	// Free memory and game stoping
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_font(fonttnr);
	al_destroy_font(fontshowg20);
	al_destroy_font(fontshowg100);
	al_destroy_bitmap(background);
	al_destroy_bitmap(hominho);
	al_destroy_bitmap(hominhomorto);
	al_destroy_bitmap(blockimg);
	al_destroy_display(display);
	al_destroy_sample(backgroundmusic);
	al_destroy_sample_instance(backgroundmusicinstance);

	return restart;
}

template<int sizeOfTheStack, int numberOfStacks>
void draw_blocks(Game<sizeOfTheStack, numberOfStacks> game, ALLEGRO_BITMAP* texture)
{
	for (int l_currentColumn = 0; l_currentColumn < numberOfStacks; l_currentColumn++)
	{
		for (int l_currentLine = 0; l_currentLine < sizeOfTheStack; l_currentLine++)
		{
			switch (game.GetBlockColor(l_currentColumn, l_currentLine))
			{
			case 1:
				al_draw_scaled_bitmap(texture, ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_ORANGE, 150 + (l_currentColumn * 50), (HIGH_DISPLAY_GAME_WINDOW - 50) - (l_currentLine * 50), 50, 50, NULL);
				break;
			case 2:
				al_draw_scaled_bitmap(texture, ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_BLUE, 150 + (l_currentColumn * 50), (HIGH_DISPLAY_GAME_WINDOW - 50) - (l_currentLine * 50), 50, 50, NULL);
				break;
			case 3:
				al_draw_scaled_bitmap(texture, ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_PURPLE, 150 + (l_currentColumn * 50), (HIGH_DISPLAY_GAME_WINDOW - 50) - (l_currentLine * 50), 50, 50, NULL);
				break;
			case 4:
				al_draw_scaled_bitmap(texture, ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_RED, 150 + (l_currentColumn * 50), (HIGH_DISPLAY_GAME_WINDOW - 50) - (l_currentLine * 50), 50, 50, NULL);
				break;
			case 5:
				al_draw_scaled_bitmap(texture, ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_YELLOW, 150 + (l_currentColumn * 50), (HIGH_DISPLAY_GAME_WINDOW - 50) - (l_currentLine * 50), 50, 50, NULL);
				break;
			case 6:
				al_draw_scaled_bitmap(texture, ALLEGRO5_BLOCK_COLOR_FOR_DRAWING_GREEN, 150 + (l_currentColumn * 50), (HIGH_DISPLAY_GAME_WINDOW - 50) - (l_currentLine * 50), 50, 50, NULL);
				break;
			default:
				break;
			}
		}
	}
}