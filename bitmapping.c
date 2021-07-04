/* FILE: A3_solutions.c is where you will code your answers for Assignment 3.
 * 
 * Each of the functions below can be considered a start for you. They have 
 * the correct specification and are set up correctly with the header file to
 * be run by the tester programs.  
 *
 * You should leave all of the code as is, especially making sure not to change
 * any return types, function name, or argument lists, as this will break
 * the automated testing. 
 *
 * Your code should only go within the sections surrounded by
 * comments like "REPLACE EVERTHING FROM HERE... TO HERE.
 *
 * The assignment document and the header A3_solutions.h should help
 * to find out how to complete and test the functions. Good luck!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "A3_provided_functions.h"

unsigned char*
bmp_open( char* bmp_filename,        unsigned int *width, 
          unsigned int *height,      unsigned int *bits_per_pixel, 
          unsigned int *padding,     unsigned int *data_size, 
          unsigned int *data_offset                                  )
{
  unsigned char *img_data=NULL;
  // REPLACE EVERYTHING FROM HERE
  
FILE *bmpfile = fopen(bmp_filename, "rb" );

fread(data_size, 1, sizeof(unsigned int), bmpfile);

rewind(bmpfile);

img_data = (unsigned char*) malloc(*data_size);

fread(img_data, 1, *data_size, bmpfile);

*width = *(unsigned int*)(img_data+18);

*height = *(unsigned int*)(img_data+22);

*bits_per_pixel = *(unsigned short*)(img_data+28);

*data_offset = *(unsigned int*)(img_data+10);

*padding = *width%4;

  // TO HERE!  
  return img_data;  
}

void 
bmp_close( unsigned char **img_data )
{
  // REPLACE EVERYTHING FROM HERE
 
	free(*img_data);
	*img_data = NULL;

  // TO HERE!  
}

unsigned char***  
bmp_scale( unsigned char*** pixel_array, unsigned char* header_data, unsigned int header_size,
           unsigned int* width, unsigned int* height, unsigned int num_colors,
           float scale )
{
  unsigned char*** new_pixel_array = NULL; 
  // REPLACE EVERYTHING FROM HERE

*height = (unsigned int) (*height*scale);
*width = (unsigned int) (*width*scale);
unsigned int padding = (4-(*width*num_colors)%4)%4;

new_pixel_array = (unsigned char***) malloc(sizeof(unsigned char**) * (*height));
for(int row=0; row<*height; row++){
	new_pixel_array[row] = (unsigned char**) malloc(sizeof(unsigned char*)*(*width)); 
		for( int col=0; col<*width; col++){
			new_pixel_array[row][col] = (unsigned char*) malloc(sizeof(unsigned char)*(num_colors));
	}
}

for (int row = 0; row < *height; row++)
	for (int col = 0; col < *width ; col++)
		for (int color = 0; color < num_colors; color++)
			new_pixel_array[row][col][color]= pixel_array[(int) (row/scale)][(int) (col/scale)][color];

*(unsigned int*) (header_data+18) = *width;
*(unsigned int*) (header_data+22) = *height;
*(unsigned int*) (header_data+2) = header_size + ((unsigned int) (4*(*width+padding)**height*num_colors));

  // TO HERE! 
  return new_pixel_array;
}         

int 
bmp_collage( char* background_image_filename,     char* foreground_image_filename, 
             char* output_collage_image_filename, int row_offset,                  
             int col_offset,                      float scale )
{
  // REPLACE EVERYTHING FROM HERE
  
/* FILE *bmpfileB = fopen(background_image_filename, "rb" );
fread(data_sizeB, 1, sizeof(unsigned int), bmpfileB);
rewind(bmpfileB);
img_dataB = (unsigned char*) malloc(*data_sizeB);
fread(img_dataB, 1, *data_sizeB, bmpfileB);
*widthB = *(unsigned int*)(img_dataB+18);
*heightB = *(unsigned int*)(img_dataB+22);
*bits_per_pixelB = *(unsigned short*)(img_dataB+28);
*data_offsetB = *(unsigned int*)(img_dataB+10);
*paddingB = *widthB%4;

FILE *bmpfileR = fopen(foreground_image_filename, "rb" );
fread(data_sizeR, 1, sizeof(unsigned int), bmpfileR);
rewind(bmpfileR);
img_dataR = (unsigned char*) malloc(*data_sizeR);
fread(img_dataR, 1, *data_sizeR, bmpfileR);
*widthR = *(unsigned int*)(img_dataR+18);
*heightR = *(unsigned int*)(img_dataR+22);
*bits_per_pixelR = *(unsigned short*)(img_dataR+28);
*data_offsetR = *(unsigned int*)(img_dataR+10);
*paddingR = *widthR%4; */


  // TO HERE! 
  return 0;
}              

