#include <pebble.h>
#include "main.h"

/**
* For this exercise, you will be filling in the following method. A bitmap will be drawn
* on-screen in both it's original and new color schemes. Your job is to use FOR loops to
* iterate through every pixel in the image, detect if the pixel matches the old color,
* and if it does, replace it with the new color.
* 
* You have been provided with two new methods to use:
* - GColor get_pixel_color(int x, int y)
* - void set_pixel_color(int x, int y, GColor color)
*
* Additionally, you may wish to use the Pebble-provided method:
* - bool gcolor_equals(GColor first, GColor second)
*
* Method parameters are defined as:
* - pixel_width: the width of the image in pixels
* - pixel_height: the height of the image in pixels
* - old_color: the color you are attempting to detect
* - new_color: the color you are replacing old_color with
*/
void replace_colors(int pixel_width, int pixel_height, GColor old_color, GColor new_color){
	
}

int main(void) {handle_init();}