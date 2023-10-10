#include "colorz.c"
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 600
#define COLS (8*2)
#define ROWS (6*2)
#define CELL_WIDTH  (WIDTH/COLS)
#define CELL_HEIGHT (HEIGHT/ROWS)
#define BACKGROUND_COLOR 0xFF202020
#define FOREGROUND_COLOR 0xFF2020FF

#define returnDefer(val) do {res = (val); goto defer;} while(0)


static uint32_t pixels[WIDTH*HEIGHT];

typedef int Errno;

Errno colorz_saveToPPM(uint32_t* pixels, size_t w, size_t h, const char* filePath){

    int res = 0;
    FILE* file = NULL;

    {
        file = fopen(filePath, "wb");
        if(file == NULL){
            returnDefer(errno);
        }

        fprintf(file, "P6\n%zu %zu 255\n", w, h);
        if(ferror(file)) {
            returnDefer(errno);;
        }

        for(size_t i =0; i < w*h; ++i){
          uint32_t pixel = pixels[i];
            uint8_t bytes[3] = {
                (pixel>>(8*0))&0xFF,
                (pixel>>(8*1))&0xFF,
                (pixel>>(8*2))&0xFF,
            };
            fwrite(bytes, sizeof(bytes), 1, file);
            if (ferror(file)) returnDefer(errno);
        }
    }

defer:
    if(file) fclose(file);
    return res;
    
}

void colorz_fill(uint32_t* pixels, size_t w, size_t h, uint32_t color){

    for(size_t i = 0 ; i < w*h ; ++i){
       pixels[i] = color;
    }
}

void colorz_fillRect(uint32_t *pixels, size_t pixelsWidth, size_t pixelsHeight,
                      int x0, int y0, size_t w, size_t h,
                      uint32_t color)
{
    //Loop through the entire canvas and if its within our rect bounds assign the pixel a color
    for (int dy = 0; dy < (int) h; ++dy) {
        int y = y0 + dy;
        if (0 <= y && y < (int) pixelsHeight) {
            for (int dx = 0; dx < (int) w; ++dx) {
                int x = x0 + dx;
                if (0 <= x && x < (int) pixelsWidth) {
                    pixels[y*pixelsWidth + x] = color;
                }
            }
        }
    }
}

bool checkerBoard(void)
{
    //fill the whole canvas with bg color
    colorz_fill(pixels, WIDTH, HEIGHT, BACKGROUND_COLOR);

    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLS; ++x) {
            uint32_t color = BACKGROUND_COLOR;
            //if we are in an even numbered cell change the color 
            if ((x + y)%2 == 0) {
                color = 0xFF2020FF;
            }
            //fill the cells with the alternating colors 
            colorz_fillRect(pixels, WIDTH, HEIGHT,
            x*CELL_WIDTH, y*CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, color);
        }
    }

    const char *filePath = "checker.ppm";
    Errno err = colorz_saveToPPM(pixels, WIDTH, HEIGHT, filePath);

    if (err) {
        return false;
    }

    return true;
}

void colorz_fillCircle(uint32_t *pixels, size_t pixelsWidth, size_t pixelsHeight,
                        int cx, int cy, int r,
                        uint32_t color)
{
    int x1 = cx - r;
    int y1 = cy - r;
    int x2 = cx + r;
    int y2 = cy + r;
    for (int y = y1; y <= y2; ++y) {
        if (0 <= y && y < (int) pixelsHeight) {
            for (int x = x1; x <= x2; ++x) {
                if (0 <= x && x < (int) pixelsWidth) {
                    int dx = x - cx;
                    int dy = y - cy;
                    if (dx*dx + dy*dy <= r*r) {
                        pixels[y*pixelsWidth + x] = color;
                    }
                }
            }
        }
    }
}

float lerpf(float a, float b, float t)
{
    return a + (b - a)*t;
}

int main(){

    //colorz_fill(pixels, WDITH, HEIGHT, 0xFF00FFFF); //BGR
    //colorz_fillRect(pixels,WIDTH, HEIGHT, 25,25,75,75,0xE66B3D);
    //checkerBoard();
    colorz_fillCircle(pixels, WIDTH, HEIGHT, WIDTH/2, HEIGHT/2, 10, 0xE66B3D);
    const char* filePath = "out.ppm";
    Errno err = colorz_saveToPPM(pixels, WIDTH, HEIGHT, filePath);
    if(err) {
        fprintf(stderr, "could not save file %s\n", filePath );
    }
    return 0;
}
