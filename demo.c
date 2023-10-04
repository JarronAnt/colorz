#include "colorz.c"
#include <stdio.h>
#include <stdint.h>
#include <errno.h>

#define WIDTH 800
#define HEIGHT 600

#define returnDefer(val) do {res = (val); goto defer;} while(0)


static uint32_t pixels[WIDTH*HEIGHT];

typedef int Errno;

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

int main(){

    //colorz_fill(pixels, WDITH, HEIGHT, 0xFF00FFFF); //R B G A
    colorz_fillRect(pixels,WIDTH, HEIGHT, 25,25,75,75,0x0BB066FF);
    colorz_saveToPPM(pixels, WIDTH, HEIGHT, "out.ppm");
    return 0;
}