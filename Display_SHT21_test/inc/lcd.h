#ifndef LCD_H_
#define LCD_H_

extern u8g_t u8g;

extern uint8_t draw_state;



void u8g_prepare(void);
void u8g_box_frame(uint8_t a);
void u8g_string(uint8_t a);
void u8g_line(uint8_t a);
void u8g_ascii_1(void);
void u8g_ascii_2(void);
void draw(void);
void temperature_screen(void);
void draw_thermometer(void);


struct lcd_object {
	bool object_active;
	char *object_address;
	uint8_t pos_x;
	uint8_t pos_y;
	uint8_t height;
	uint8_t width;
	uint8_t font_size;
	u8g_fntpgm_uint8_t font;
};

struct lcd_screen {
	lcd_object *screen_objects;
	bool screen_active;
};

//struct lcd_screen lcd_screens[2];

//uint8_t active_screen; // set the enumeration of shown screen

enum {
	HOMESCREEN,
	MENU
};



struct lcd_home_screen {
	bool show_window_state;
	bool show_ventialtion_state;
	bool external_set_temp_active; //true if actual set-temperature is from external

};









//struct lcd_page


#endif
