#include <pebble.h>

Layer *layer;
Window *window;
GBitmap *old_image, *image;

uint8_t *bitmap_data;
int bytes_per_row;

int HEIGHT = PBL_IF_RECT_ELSE(168,180);
int WIDTH = PBL_IF_RECT_ELSE(144,180);

void draw(Layer *layer, GContext *ctx){
	graphics_context_set_compositing_mode(ctx, GCompOpSet);
	graphics_draw_bitmap_in_rect(ctx, old_image, GRect((WIDTH-28)/2, 30, 28, 38));
	graphics_draw_bitmap_in_rect(ctx, image, GRect((WIDTH-28)/2, HEIGHT-30-38, 28, 38));
}

GColor get_pixel_color(int x, int y){
	return (GColor){ .argb = bitmap_data[y*bytes_per_row + x] };
}

void set_pixel_color(int x, int y, GColor color){
	bitmap_data[y*bytes_per_row + x] = color.argb;
}

void replace_colors(int num_rows, int num_columns, GColor8 current_color, GColor8 new_color);

void handle_init(){
	window = window_create();
	layer = layer_create(layer_get_bounds(window_get_root_layer(window)));
	layer_set_update_proc(layer, draw);
	layer_add_child(window_get_root_layer(window), layer);
	
	image = gbitmap_create_with_resource(RESOURCE_ID_IMAGE);
	old_image = gbitmap_create_with_resource(RESOURCE_ID_IMAGE);
	
	bitmap_data = gbitmap_get_data(image);
	bytes_per_row = gbitmap_get_bytes_per_row(image);
	
	replace_colors(28, 38, GColorRed, GColorBlue);
	replace_colors(28, 38, GColorDarkCandyAppleRed, GColorOxfordBlue);
	
	window_stack_push(window, true);
	
	//light_enable(true);
	
	app_event_loop();
}

/*
// A functionally-correct answer
void replace_colors(int num_columns, int num_rows, GColor old_color, GColor new_color){
	int max_y = num_rows;
	int max_x = num_columns;
	
	for(int y = 0; y < max_y; y++){
		for(int x = 0; x < max_x; x++){
			GColor pixel_color = get_pixel_color(x,y);
			if(gcolor_equal(pixel_color, old_color)){
			  set_pixel_color(x, y, new_color);
			}
		}
	}
}
*/