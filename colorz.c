#ifndef COLORZ_C
#define COLORZ_C

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef COLORZCDEF
#define COLORZCDEF static inline
#endif

#ifndef COLORZ_AA_RES
#define COLORZ_AA_RES 2
#endif

#define COLORZ_SWAP(T, a, b) do { T t = a; a = b; b = t; } while (0)
#define COLORZ_SIGN(T, x) ((T)((x) > 0) - (T)((x) < 0))
#define COLORZ_ABS(T, x) (COLORZ_SIGN(T, x)*(x))

typedef struct {
    size_t width, height;
    const char *glyphs;
} Colorz_Font;

#define COLORZ_DEFAULT_FONT_HEIGHT 6
#define COLORZ_DEFAULT_FONT_WIDTH 6

static char colorz_default_glyphs[128][COLORZ_DEFAULT_FONT_HEIGHT][COLORZ_DEFAULT_FONT_WIDTH] = {
    ['a'] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
    },
    ['b'] = {
        {1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 0, 0},
    },
    ['c'] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
    },
    ['d'] = {
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
    },
    ['e'] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
    },
    ['f'] = {
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
    },
    ['g'] = {0},
    ['h'] = {
        {1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
    },
    ['i'] = {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
    },
    ['j'] = {0},
    ['k'] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0},
    },
    ['l'] = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
    },
    ['m'] = {0},
    ['n'] = {0},
    ['o'] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
    },
    ['p'] = {
        {1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
    },
    ['q'] = {0},
    ['r'] = {
        {0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
    },
    ['s'] = {0},
    ['t'] = {0},
    ['u'] = {0},
    ['v'] = {0},
    ['w'] = {
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 1},
    },
    ['x'] = {0},
    ['y'] = {0},
    ['z'] = {0},

    ['A'] = {0},
    ['B'] = {0},
    ['C'] = {0},
    ['D'] = {0},
    ['E'] = {0},
    ['F'] = {0},
    ['G'] = {0},
    ['H'] = {0},
    ['I'] = {0},
    ['J'] = {0},
    ['K'] = {0},
    ['L'] = {0},
    ['M'] = {0},
    ['N'] = {0},
    ['O'] = {0},
    ['P'] = {0},
    ['Q'] = {0},
    ['R'] = {0},
    ['S'] = {0},
    ['T'] = {0},
    ['U'] = {0},
    ['V'] = {0},
    ['W'] = {0},
    ['X'] = {0},
    ['Y'] = {0},
    ['Z'] = {0},

    ['0'] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
    },
    ['1'] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
    },
    ['2'] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
    },
    ['3'] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
    },
    ['4'] = {
        {0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
    },
    ['5'] = {
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
    },
    ['6'] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
    },
    ['7'] = {
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
    },
    ['8'] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},

    },
    ['9'] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
    },

    [','] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
    },

    ['.'] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
    },
    ['-'] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    },
};

static Colorz_Font colorz_default_font = {
    .glyphs = &colorz_default_glyphs[0][0][0],
    .width = COLORZ_DEFAULT_FONT_WIDTH,
    .height = COLORZ_DEFAULT_FONT_HEIGHT,
};

typedef struct {
    uint32_t *pixels;
    size_t width;
    size_t height;
    size_t stride;
} Colorz_Canvas;

#define COLORZ_CANVAS_NULL ((Colorz_Canvas) {0})
#define COLORZ_PIXEL(oc, x, y) (oc).pixels[(y)*(oc).stride + (x)]

COLORZCDEF Colorz_Canvas colorz_canvas(uint32_t *pixels, size_t width, size_t height, size_t stride);
COLORZCDEF Colorz_Canvas colorz_subcanvas(Colorz_Canvas oc, int x, int y, int w, int h);
COLORZCDEF bool colorz_in_bounds(Colorz_Canvas oc, int x, int y);
COLORZCDEF void colorz_blend_color(uint32_t *c1, uint32_t c2);
COLORZCDEF void colorz_fill(Colorz_Canvas oc, uint32_t color);
COLORZCDEF void colorz_rect(Colorz_Canvas oc, int x, int y, int w, int h, uint32_t color);
COLORZCDEF void colorz_frame(Colorz_Canvas oc, int x, int y, int w, int h, size_t thiccness, uint32_t color);
COLORZCDEF void colorz_circle(Colorz_Canvas oc, int cx, int cy, int r, uint32_t color);
COLORZCDEF void colorz_ellipse(Colorz_Canvas oc, int cx, int cy, int rx, int ry, uint32_t color);

COLORZCDEF void colorz_line(Colorz_Canvas oc, int x1, int y1, int x2, int y2, uint32_t color);
COLORZCDEF bool colorz_normalize_triangle(size_t width, size_t height, int x1, int y1, int x2, int y2, int x3, int y3, int *lx, int *hx, int *ly, int *hy);
COLORZCDEF bool colorz_barycentric(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int *u1, int *u2, int *det);
COLORZCDEF void colorz_triangle(Colorz_Canvas oc, int x1, int y1, int x2, int y2, int x3, int y3, uint32_t color);
COLORZCDEF void colorz_triangle3c(Colorz_Canvas oc, int x1, int y1, int x2, int y2, int x3, int y3, uint32_t c1, uint32_t c2, uint32_t c3);
COLORZCDEF void colorz_triangle3z(Colorz_Canvas oc, int x1, int y1, int x2, int y2, int x3, int y3, float z1, float z2, float z3);
COLORZCDEF void colorz_triangle3uv(Colorz_Canvas oc, int x1, int y1, int x2, int y2, int x3, int y3, float tx1, float ty1, float tx2, float ty2, float tx3, float ty3, float z1, float z2, float z3, Colorz_Canvas texture);
COLORZCDEF void colorz_triangle3uv_bilinear(Colorz_Canvas oc, int x1, int y1, int x2, int y2, int x3, int y3, float tx1, float ty1, float tx2, float ty2, float tx3, float ty3, float z1, float z2, float z3, Colorz_Canvas texture);
COLORZCDEF void colorz_text(Colorz_Canvas oc, const char *text, int x, int y, Colorz_Font font, size_t size, uint32_t color);
COLORZCDEF void colorz_sprite_blend(Colorz_Canvas oc, int x, int y, int w, int h, Colorz_Canvas sprite);
COLORZCDEF void colorz_sprite_copy(Colorz_Canvas oc, int x, int y, int w, int h, Colorz_Canvas sprite);
COLORZCDEF void colorz_sprite_copy_bilinear(Colorz_Canvas oc, int x, int y, int w, int h, Colorz_Canvas sprite);
COLORZCDEF uint32_t colorz_pixel_bilinear(Colorz_Canvas sprite, int nx, int ny, int w, int h);

typedef struct {
    // Safe ranges to iterate over.
    int x1, x2;
    int y1, y2;

    // Original uncut ranges some parts of which may be outside of the canvas boundaries.
    int ox1, ox2;
    int oy1, oy2;
} Colorz_Normalized_Rect;


COLORZCDEF bool colorz_normalize_rect(int x, int y, int w, int h,
                                     size_t canvas_width, size_t canvas_height,
                                     Colorz_Normalized_Rect *nr);

#endif // COLORZ_C

#ifdef COLORZ_IMPLEMENTATION

COLORZCDEF Colorz_Canvas colorz_canvas(uint32_t *pixels, size_t width, size_t height, size_t stride)
{
    Colorz_Canvas oc = {
        .pixels = pixels,
        .width  = width,
        .height = height,
        .stride = stride,
    };
    return oc;
}

COLORZCDEF bool colorz_normalize_rect(int x, int y, int w, int h,
                                     size_t canvas_width, size_t canvas_height,
                                     Colorz_Normalized_Rect *nr)
{
    // No need to render empty rectangle
    if (w == 0) return false;
    if (h == 0) return false;

    nr->ox1 = x;
    nr->oy1 = y;

    // Convert the rectangle to 2-points representation
    nr->ox2 = nr->ox1 + COLORZ_SIGN(int, w)*(COLORZ_ABS(int, w) - 1);
    if (nr->ox1 > nr->ox2) COLORZ_SWAP(int, nr->ox1, nr->ox2);
    nr->oy2 = nr->oy1 + COLORZ_SIGN(int, h)*(COLORZ_ABS(int, h) - 1);
    if (nr->oy1 > nr->oy2) COLORZ_SWAP(int, nr->oy1, nr->oy2);

    // Cull out invisible rectangle
    if (nr->ox1 >= (int) canvas_width) return false;
    if (nr->ox2 < 0) return false;
    if (nr->oy1 >= (int) canvas_height) return false;
    if (nr->oy2 < 0) return false;

    nr->x1 = nr->ox1;
    nr->y1 = nr->oy1;
    nr->x2 = nr->ox2;
    nr->y2 = nr->oy2;

    // Clamp the rectangle to the boundaries
    if (nr->x1 < 0) nr->x1 = 0;
    if (nr->x2 >= (int) canvas_width) nr->x2 = (int) canvas_width - 1;
    if (nr->y1 < 0) nr->y1 = 0;
    if (nr->y2 >= (int) canvas_height) nr->y2 = (int) canvas_height - 1;

    return true;
}

COLORZCDEF Colorz_Canvas colorz_subcanvas(Colorz_Canvas oc, int x, int y, int w, int h)
{
    Colorz_Normalized_Rect nr = {0};
    if (!colorz_normalize_rect(x, y, w, h, oc.width, oc.height, &nr)) return COLORZ_CANVAS_NULL;
    oc.pixels = &COLORZ_PIXEL(oc, nr.x1, nr.y1);
    oc.width = nr.x2 - nr.x1 + 1;
    oc.height = nr.y2 - nr.y1 + 1;
    return oc;
}


#define COLORZ_RED(color)   (((color)&0x000000FF)>>(8*0))
#define COLORZ_GREEN(color) (((color)&0x0000FF00)>>(8*1))
#define COLORZ_BLUE(color)  (((color)&0x00FF0000)>>(8*2))
#define COLORZ_ALPHA(color) (((color)&0xFF000000)>>(8*3))
#define COLORZ_RGBA(r, g, b, a) ((((r)&0xFF)<<(8*0)) | (((g)&0xFF)<<(8*1)) | (((b)&0xFF)<<(8*2)) | (((a)&0xFF)<<(8*3)))

COLORZCDEF void colorz_blend_color(uint32_t *c1, uint32_t c2)
{
    uint32_t r1 = COLORZ_RED(*c1);
    uint32_t g1 = COLORZ_GREEN(*c1);
    uint32_t b1 = COLORZ_BLUE(*c1);
    uint32_t a1 = COLORZ_ALPHA(*c1);

    uint32_t r2 = COLORZ_RED(c2);
    uint32_t g2 = COLORZ_GREEN(c2);
    uint32_t b2 = COLORZ_BLUE(c2);
    uint32_t a2 = COLORZ_ALPHA(c2);

    r1 = (r1*(255 - a2) + r2*a2)/255; if (r1 > 255) r1 = 255;
    g1 = (g1*(255 - a2) + g2*a2)/255; if (g1 > 255) g1 = 255;
    b1 = (b1*(255 - a2) + b2*a2)/255; if (b1 > 255) b1 = 255;

    *c1 = COLORZ_RGBA(r1, g1, b1, a1);
}

COLORZCDEF void colorz_fill(Colorz_Canvas oc, uint32_t color)
{
    for (size_t y = 0; y < oc.height; ++y) {
        for (size_t x = 0; x < oc.width; ++x) {
            COLORZ_PIXEL(oc, x, y) = color;
        }
    }
}

COLORZCDEF void colorz_rect(Colorz_Canvas oc, int x, int y, int w, int h, uint32_t color)
{
    Colorz_Normalized_Rect nr = {0};
    if (!colorz_normalize_rect(x, y, w, h, oc.width, oc.height, &nr)) return;
    for (int x = nr.x1; x <= nr.x2; ++x) {
        for (int y = nr.y1; y <= nr.y2; ++y) {
            colorz_blend_color(&COLORZ_PIXEL(oc, x, y), color);
        }
    }
}

COLORZCDEF void colorz_frame(Colorz_Canvas oc, int x, int y, int w, int h, size_t t, uint32_t color)
{
    if (t == 0) return; // Nothing to render

    // Convert the rectangle to 2-points representation
    int x1 = x;
    int y1 = y;
    int x2 = x1 + COLORZ_SIGN(int, w)*(COLORZ_ABS(int, w) - 1);
    if (x1 > x2) COLORZ_SWAP(int, x1, x2);
    int y2 = y1 + COLORZ_SIGN(int, h)*(COLORZ_ABS(int, h) - 1);
    if (y1 > y2) COLORZ_SWAP(int, y1, y2);

    colorz_rect(oc, x1 - t/2, y1 - t/2, (x2 - x1 + 1) + t/2*2, t, color);  // Top
    colorz_rect(oc, x1 - t/2, y1 - t/2, t, (y2 - y1 + 1) + t/2*2, color);  // Left
    colorz_rect(oc, x1 - t/2, y2 + t/2, (x2 - x1 + 1) + t/2*2, -t, color); // Bottom
    colorz_rect(oc, x2 + t/2, y1 - t/2, -t, (y2 - y1 + 1) + t/2*2, color); // Right
}

COLORZCDEF void colorz_ellipse(Colorz_Canvas oc, int cx, int cy, int rx, int ry, uint32_t color)
{
    Colorz_Normalized_Rect nr = {0};
    int rx1 = rx + COLORZ_SIGN(int, rx);
    int ry1 = ry + COLORZ_SIGN(int, ry);
    if (!colorz_normalize_rect(cx - rx1, cy - ry1, 2*rx1, 2*ry1, oc.width, oc.height, &nr)) return;

    for (int y = nr.y1; y <= nr.y2; ++y) {
        for (int x = nr.x1; x <= nr.x2; ++x) {
            float nx = (x + 0.5 - nr.x1)/(2.0f*rx1);
            float ny = (y + 0.5 - nr.y1)/(2.0f*ry1);
            float dx = nx - 0.5;
            float dy = ny - 0.5;
            if (dx*dx + dy*dy <= 0.5*0.5) {
                COLORZ_PIXEL(oc, x, y) = color;
            }
        }
    }
}

COLORZCDEF void colorz_circle(Colorz_Canvas oc, int cx, int cy, int r, uint32_t color)
{
    Colorz_Normalized_Rect nr = {0};
    int r1 = r + COLORZ_SIGN(int, r);
    if (!colorz_normalize_rect(cx - r1, cy - r1, 2*r1, 2*r1, oc.width, oc.height, &nr)) return;

    for (int y = nr.y1; y <= nr.y2; ++y) {
        for (int x = nr.x1; x <= nr.x2; ++x) {
            int count = 0;
            for (int sox = 0; sox < COLORZ_AA_RES; ++sox) {
                for (int soy = 0; soy < COLORZ_AA_RES; ++soy) {
                    int res1 = (COLORZ_AA_RES + 1);
                    int dx = (x*res1*2 + 2 + sox*2 - res1*cx*2 - res1);
                    int dy = (y*res1*2 + 2 + soy*2 - res1*cy*2 - res1);
                    if (dx*dx + dy*dy <= res1*res1*r*r*2*2) count += 1;
                }
            }
            uint32_t alpha = ((color&0xFF000000)>>(3*8))*count/COLORZ_AA_RES/COLORZ_AA_RES;
            uint32_t updated_color = (color&0x00FFFFFF)|(alpha<<(3*8));
            colorz_blend_color(&COLORZ_PIXEL(oc, x, y), updated_color);
        }
    }
}

COLORZCDEF bool colorz_in_bounds(Colorz_Canvas oc, int x, int y)
{
    return 0 <= x && x < (int) oc.width && 0 <= y && y < (int) oc.height;
}


COLORZCDEF void colorz_line(Colorz_Canvas oc, int x1, int y1, int x2, int y2, uint32_t color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    // If both of the differences are 0 there will be a division by 0 below.
    if (dx == 0 && dy == 0) {
        if (colorz_in_bounds(oc, x1, y1)) {
            colorz_blend_color(&COLORZ_PIXEL(oc, x1, y1), color);
        }
        return;
    }

    if (COLORZ_ABS(int, dx) > COLORZ_ABS(int, dy)) {
        if (x1 > x2) {
            COLORZ_SWAP(int, x1, x2);
            COLORZ_SWAP(int, y1, y2);
        }

        for (int x = x1; x <= x2; ++x) {
            int y = dy*(x - x1)/dx + y1;

            if (colorz_in_bounds(oc, x, y)) {
                colorz_blend_color(&COLORZ_PIXEL(oc, x, y), color);
            }
        }
    } else {
        if (y1 > y2) {
            COLORZ_SWAP(int, x1, x2);
            COLORZ_SWAP(int, y1, y2);
        }

        for (int y = y1; y <= y2; ++y) {
            int x = dx*(y - y1)/dy + x1;

            if (colorz_in_bounds(oc, x, y)) {
                colorz_blend_color(&COLORZ_PIXEL(oc, x, y), color);
            }
        }
    }
}

COLORZCDEF uint32_t mix_colors2(uint32_t c1, uint32_t c2, int u1, int det)
{

    int64_t r1 = COLORZ_RED(c1);
    int64_t g1 = COLORZ_GREEN(c1);
    int64_t b1 = COLORZ_BLUE(c1);
    int64_t a1 = COLORZ_ALPHA(c1);

    int64_t r2 = COLORZ_RED(c2);
    int64_t g2 = COLORZ_GREEN(c2);
    int64_t b2 = COLORZ_BLUE(c2);
    int64_t a2 = COLORZ_ALPHA(c2);

    if (det != 0) {
        int u2 = det - u1;
        int64_t r4 = (r1*u2 + r2*u1)/det;
        int64_t g4 = (g1*u2 + g2*u1)/det;
        int64_t b4 = (b1*u2 + b2*u1)/det;
        int64_t a4 = (a1*u2 + a2*u1)/det;

        return COLORZ_RGBA(r4, g4, b4, a4);
    }

    return 0;
}

COLORZCDEF uint32_t mix_colors3(uint32_t c1, uint32_t c2, uint32_t c3, int u1, int u2, int det)
{

    int64_t r1 = COLORZ_RED(c1);
    int64_t g1 = COLORZ_GREEN(c1);
    int64_t b1 = COLORZ_BLUE(c1);
    int64_t a1 = COLORZ_ALPHA(c1);

    int64_t r2 = COLORZ_RED(c2);
    int64_t g2 = COLORZ_GREEN(c2);
    int64_t b2 = COLORZ_BLUE(c2);
    int64_t a2 = COLORZ_ALPHA(c2);

    int64_t r3 = COLORZ_RED(c3);
    int64_t g3 = COLORZ_GREEN(c3);
    int64_t b3 = COLORZ_BLUE(c3);
    int64_t a3 = COLORZ_ALPHA(c3);

    if (det != 0) {
        int u3 = det - u1 - u2;
        int64_t r4 = (r1*u1 + r2*u2 + r3*u3)/det;
        int64_t g4 = (g1*u1 + g2*u2 + g3*u3)/det;
        int64_t b4 = (b1*u1 + b2*u2 + b3*u3)/det;
        int64_t a4 = (a1*u1 + a2*u2 + a3*u3)/det;

        return COLORZ_RGBA(r4, g4, b4, a4);
    }

    return 0;
}

// NOTE: we imply u3 = det - u1 - u2
COLORZCDEF bool colorz_barycentric(int x1, int y1, int x2, int y2, int x3, int y3, int xp, int yp, int *u1, int *u2, int *det)
{
    *det = ((x1 - x3)*(y2 - y3) - (x2 - x3)*(y1 - y3));
    *u1  = ((y2 - y3)*(xp - x3) + (x3 - x2)*(yp - y3));
    *u2  = ((y3 - y1)*(xp - x3) + (x1 - x3)*(yp - y3));
    int u3 = *det - *u1 - *u2;
    return (
               (COLORZ_SIGN(int, *u1) == COLORZ_SIGN(int, *det) || *u1 == 0) &&
               (COLORZ_SIGN(int, *u2) == COLORZ_SIGN(int, *det) || *u2 == 0) &&
               (COLORZ_SIGN(int, u3) == COLORZ_SIGN(int, *det) || u3 == 0)
           );
}

COLORZCDEF bool colorz_normalize_triangle(size_t width, size_t height, int x1, int y1, int x2, int y2, int x3, int y3, int *lx, int *hx, int *ly, int *hy)
{
    *lx = x1;
    *hx = x1;
    if (*lx > x2) *lx = x2;
    if (*lx > x3) *lx = x3;
    if (*hx < x2) *hx = x2;
    if (*hx < x3) *hx = x3;
    if (*lx < 0) *lx = 0;
    if ((size_t) *lx >= width) return false;;
    if (*hx < 0) return false;;
    if ((size_t) *hx >= width) *hx = width-1;

    *ly = y1;
    *hy = y1;
    if (*ly > y2) *ly = y2;
    if (*ly > y3) *ly = y3;
    if (*hy < y2) *hy = y2;
    if (*hy < y3) *hy = y3;
    if (*ly < 0) *ly = 0;
    if ((size_t) *ly >= height) return false;;
    if (*hy < 0) return false;;
    if ((size_t) *hy >= height) *hy = height-1;

    return true;
}

COLORZCDEF void colorz_triangle3c(Colorz_Canvas oc, int x1, int y1, int x2, int y2, int x3, int y3,
                                 uint32_t c1, uint32_t c2, uint32_t c3)
{
    int lx, hx, ly, hy;
    if (colorz_normalize_triangle(oc.width, oc.height, x1, y1, x2, y2, x3, y3, &lx, &hx, &ly, &hy)) {
        for (int y = ly; y <= hy; ++y) {
            for (int x = lx; x <= hx; ++x) {
                int u1, u2, det;
                if (colorz_barycentric(x1, y1, x2, y2, x3, y3, x, y, &u1, &u2, &det)) {
                    colorz_blend_color(&COLORZ_PIXEL(oc, x, y), mix_colors3(c1, c2, c3, u1, u2, det));
                }
            }
        }
    }
}

COLORZCDEF void colorz_triangle3z(Colorz_Canvas oc, int x1, int y1, int x2, int y2, int x3, int y3, float z1, float z2, float z3)
{
    int lx, hx, ly, hy;
    if (colorz_normalize_triangle(oc.width, oc.height, x1, y1, x2, y2, x3, y3, &lx, &hx, &ly, &hy)) {
        for (int y = ly; y <= hy; ++y) {
            for (int x = lx; x <= hx; ++x) {
                int u1, u2, det;
                if (colorz_barycentric(x1, y1, x2, y2, x3, y3, x, y, &u1, &u2, &det)) {
                    float z = z1*u1/det + z2*u2/det + z3*(det - u1 - u2)/det;
                    COLORZ_PIXEL(oc, x, y) = *(uint32_t*)&z;
                }
            }
        }
    }
}

COLORZCDEF void colorz_triangle3uv(Colorz_Canvas oc, int x1, int y1, int x2, int y2, int x3, int y3, float tx1, float ty1, float tx2, float ty2, float tx3, float ty3, float z1, float z2, float z3, Colorz_Canvas texture)
{
    int lx, hx, ly, hy;
    if (colorz_normalize_triangle(oc.width, oc.height, x1, y1, x2, y2, x3, y3, &lx, &hx, &ly, &hy)) {
        for (int y = ly; y <= hy; ++y) {
            for (int x = lx; x <= hx; ++x) {
                int u1, u2, det;
                if (colorz_barycentric(x1, y1, x2, y2, x3, y3, x, y, &u1, &u2, &det)) {
                    int u3 = det - u1 - u2;
                    float z = z1*u1/det + z2*u2/det + z3*(det - u1 - u2)/det;
                    float tx = tx1*u1/det + tx2*u2/det + tx3*u3/det;
                    float ty = ty1*u1/det + ty2*u2/det + ty3*u3/det;

                    int texture_x = tx/z*texture.width;
                    if (texture_x < 0) texture_x = 0;
                    if ((size_t) texture_x >= texture.width) texture_x = texture.width - 1;

                    int texture_y = ty/z*texture.height;
                    if (texture_y < 0) texture_y = 0;
                    if ((size_t) texture_y >= texture.height) texture_y = texture.height - 1;
                    COLORZ_PIXEL(oc, x, y) = COLORZ_PIXEL(texture, (int)texture_x, (int)texture_y);
                }
            }
        }
    }
}

COLORZCDEF void colorz_triangle3uv_bilinear(Colorz_Canvas oc, int x1, int y1, int x2, int y2, int x3, int y3, float tx1, float ty1, float tx2, float ty2, float tx3, float ty3, float z1, float z2, float z3, Colorz_Canvas texture)
{
    int lx, hx, ly, hy;
    if (colorz_normalize_triangle(oc.width, oc.height, x1, y1, x2, y2, x3, y3, &lx, &hx, &ly, &hy)) {
        for (int y = ly; y <= hy; ++y) {
            for (int x = lx; x <= hx; ++x) {
                int u1, u2, det;
                if (colorz_barycentric(x1, y1, x2, y2, x3, y3, x, y, &u1, &u2, &det)) {
                    int u3 = det - u1 - u2;
                    float z = z1*u1/det + z2*u2/det + z3*(det - u1 - u2)/det;
                    float tx = tx1*u1/det + tx2*u2/det + tx3*u3/det;
                    float ty = ty1*u1/det + ty2*u2/det + ty3*u3/det;

                    float texture_x = tx/z*texture.width;
                    if (texture_x < 0) texture_x = 0;
                    if (texture_x >= (float) texture.width) texture_x = texture.width - 1;

                    float texture_y = ty/z*texture.height;
                    if (texture_y < 0) texture_y = 0;
                    if (texture_y >= (float) texture.height) texture_y = texture.height - 1;

                    int precision = 100;
                    COLORZ_PIXEL(oc, x, y) = colorz_pixel_bilinear(
                                                 texture,
                                                 texture_x*precision, texture_y*precision,
                                                 precision, precision);
                }
            }
        }
    }
}

COLORZCDEF void colorz_triangle(Colorz_Canvas oc, int x1, int y1, int x2, int y2, int x3, int y3, uint32_t color)
{
    int lx, hx, ly, hy;
    if (colorz_normalize_triangle(oc.width, oc.height, x1, y1, x2, y2, x3, y3, &lx, &hx, &ly, &hy)) {
        for (int y = ly; y <= hy; ++y) {
            for (int x = lx; x <= hx; ++x) {
                int u1, u2, det;
                if (colorz_barycentric(x1, y1, x2, y2, x3, y3, x, y, &u1, &u2, &det)) {
                    colorz_blend_color(&COLORZ_PIXEL(oc, x, y), color);
                }
            }
        }
    }
}

COLORZCDEF void colorz_text(Colorz_Canvas oc, const char *text, int tx, int ty, Colorz_Font font, size_t glyph_size, uint32_t color)
{
    for (size_t i = 0; *text; ++i, ++text) {
        int gx = tx + i*font.width*glyph_size;
        int gy = ty;
        const char *glyph = &font.glyphs[(*text)*sizeof(char)*font.width*font.height];
        for (int dy = 0; (size_t) dy < font.height; ++dy) {
            for (int dx = 0; (size_t) dx < font.width; ++dx) {
                int px = gx + dx*glyph_size;
                int py = gy + dy*glyph_size;
                if (0 <= px && px < (int) oc.width && 0 <= py && py < (int) oc.height) {
                    if (glyph[dy*font.width + dx]) {
                        colorz_rect(oc, px, py, glyph_size, glyph_size, color);
                    }
                }
            }
        }
    }
}

COLORZCDEF void colorz_sprite_blend(Colorz_Canvas oc, int x, int y, int w, int h, Colorz_Canvas sprite)
{
    if (sprite.width == 0) return;
    if (sprite.height == 0) return;

    Colorz_Normalized_Rect nr = {0};
    if (!colorz_normalize_rect(x, y, w, h, oc.width, oc.height, &nr)) return;

    int xa = nr.ox1;
    if (w < 0) xa = nr.ox2;
    int ya = nr.oy1;
    if (h < 0) ya = nr.oy2;
    for (int y = nr.y1; y <= nr.y2; ++y) {
        for (int x = nr.x1; x <= nr.x2; ++x) {
            size_t nx = (x - xa)*((int) sprite.width)/w;
            size_t ny = (y - ya)*((int) sprite.height)/h;
            colorz_blend_color(&COLORZ_PIXEL(oc, x, y), COLORZ_PIXEL(sprite, nx, ny));
        }
    }
}

COLORZCDEF void colorz_sprite_copy(Colorz_Canvas oc, int x, int y, int w, int h, Colorz_Canvas sprite)
{
    if (sprite.width == 0) return;
    if (sprite.height == 0) return;

    Colorz_Normalized_Rect nr = {0};
    if (!colorz_normalize_rect(x, y, w, h, oc.width, oc.height, &nr)) return;

    int xa = nr.ox1;
    if (w < 0) xa = nr.ox2;
    int ya = nr.oy1;
    if (h < 0) ya = nr.oy2;
    for (int y = nr.y1; y <= nr.y2; ++y) {
        for (int x = nr.x1; x <= nr.x2; ++x) {
            size_t nx = (x - xa)*((int) sprite.width)/w;
            size_t ny = (y - ya)*((int) sprite.height)/h;
            COLORZ_PIXEL(oc, x, y) = COLORZ_PIXEL(sprite, nx, ny);
        }
    }
}


COLORZCDEF uint32_t colorz_pixel_bilinear(Colorz_Canvas sprite, int nx, int ny, int w, int h)
{
    int px = nx%w;
    int py = ny%h;

    int x1 = nx/w, x2 = nx/w;
    int y1 = ny/h, y2 = ny/h;
    if (px < w/2) {
        // left
        px += w/2;
        x1 -= 1;
        if (x1 < 0) x1 = 0;
    } else {
        // right
        px -= w/2;
        x2 += 1;
        if ((size_t) x2 >= sprite.width) x2 = sprite.width - 1;
    }

    if (py < h/2) {
        // top
        py += h/2;
        y1 -= 1;
        if (y1 < 0) y1 = 0;
    } else {
        // bottom
        py -= h/2;
        y2 += 1;
        if ((size_t) y2 >= sprite.height) y2 = sprite.height - 1;
    }

    return mix_colors2(mix_colors2(COLORZ_PIXEL(sprite, x1, y1),
                                   COLORZ_PIXEL(sprite, x2, y1),
                                   px, w),
                       mix_colors2(COLORZ_PIXEL(sprite, x1, y2),
                                   COLORZ_PIXEL(sprite, x2, y2),
                                   px, w),
                       py, h);
}

COLORZCDEF void colorz_sprite_copy_bilinear(Colorz_Canvas oc, int x, int y, int w, int h, Colorz_Canvas sprite)
{
    if (w <= 0) return;
    if (h <= 0) return;

    Colorz_Normalized_Rect nr = {0};
    if (!colorz_normalize_rect(x, y, w, h, oc.width, oc.height, &nr)) return;

    for (int y = nr.y1; y <= nr.y2; ++y) {
        for (int x = nr.x1; x <= nr.x2; ++x) {
            size_t nx = (x - nr.ox1)*sprite.width;
            size_t ny = (y - nr.oy1)*sprite.height;
            COLORZ_PIXEL(oc, x, y) = colorz_pixel_bilinear(sprite, nx, ny, w, h);
        }
    }
}

#endif