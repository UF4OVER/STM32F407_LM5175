/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --no-compress --stride 1 --align 1 --font blender-pro-bold.otf --symbols QWERTYUIOPLKJHGFDSAZXCVBNM1234567890qwertyuioplkjhgfdsazxcvbnm,.:% --range 32-127 --format lvgl -o blender16.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef BLENDER16
#define BLENDER16 1
#endif

#if BLENDER16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xfc, 0x30,

    /* U+0022 "\"" */
    0xff, 0xf0,

    /* U+0023 "#" */
    0x2c, 0x5b, 0xfb, 0x4f, 0xcb, 0x16, 0x0,

    /* U+0024 "$" */
    0x10, 0xfb, 0x56, 0x8f, 0x1f, 0x8f, 0x8b, 0x17,
    0xad, 0xf0, 0x80,

    /* U+0025 "%" */
    0x71, 0x8d, 0xb0, 0xdb, 0xd, 0xe0, 0x76, 0x0,
    0x5e, 0xf, 0x30, 0xb3, 0x1b, 0x31, 0x1e,

    /* U+0026 "&" */
    0x79, 0x9b, 0x6, 0xc, 0xe, 0x31, 0xe3, 0xc4,
    0xf8,

    /* U+0027 "'" */
    0xfc,

    /* U+0028 "(" */
    0x27, 0xec, 0xcc, 0xcc, 0xcc, 0xe7, 0x20,

    /* U+0029 ")" */
    0x4e, 0x73, 0x33, 0x33, 0x33, 0x7e, 0x40,

    /* U+002A "*" */
    0x33, 0xf7, 0x9e, 0x48,

    /* U+002B "+" */
    0x30, 0xc3, 0x3f, 0x30, 0xc0,

    /* U+002C "," */
    0xfc,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x6, 0x18, 0x30, 0xc1, 0x86, 0xc, 0x30, 0x61,
    0x80,

    /* U+0030 "0" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,
    0xf8,

    /* U+0031 "1" */
    0xf3, 0x33, 0x33, 0x33, 0x33,

    /* U+0032 "2" */
    0x7b, 0x30, 0xc7, 0x3d, 0xee, 0x30, 0xc3, 0xf0,

    /* U+0033 "3" */
    0x7d, 0x8c, 0x18, 0x30, 0x67, 0x81, 0x83, 0xc6,
    0xf8,

    /* U+0034 "4" */
    0x1c, 0x38, 0xf1, 0x66, 0xcd, 0xb3, 0x7f, 0xc,
    0x18,

    /* U+0035 "5" */
    0xfb, 0xc, 0x30, 0xf8, 0x30, 0xc3, 0xcf, 0xe0,

    /* U+0036 "6" */
    0x7d, 0x8f, 0x6, 0xf, 0xd8, 0xf1, 0xe3, 0xc6,
    0xf8,

    /* U+0037 "7" */
    0xfc, 0x30, 0x86, 0x18, 0xc3, 0x8, 0x61, 0x80,

    /* U+0038 "8" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x6f, 0xb1, 0xe3, 0xc6,
    0xf8,

    /* U+0039 "9" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x6f, 0xc1, 0x83, 0xc6,
    0xf8,

    /* U+003A ":" */
    0xc0, 0x30,

    /* U+003B ";" */
    0x60, 0x26, 0xf0,

    /* U+003C "<" */
    0x4, 0x77, 0x38, 0x70, 0xf0, 0xc0,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0x83, 0x83, 0x87, 0x3b, 0xcc, 0x0,

    /* U+003F "?" */
    0xfb, 0x30, 0xc3, 0x1c, 0xe3, 0xc, 0x0, 0xc0,

    /* U+0040 "@" */
    0x7f, 0x60, 0xf0, 0x79, 0xfd, 0x9e, 0xcf, 0x67,
    0xb3, 0xd9, 0xe7, 0xf0, 0x8, 0x0,

    /* U+0041 "A" */
    0x18, 0xe, 0xf, 0x6, 0x83, 0x63, 0x31, 0x98,
    0xfe, 0xc3, 0x60, 0x80,

    /* U+0042 "B" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x7f, 0xb1, 0xe3, 0xc7,
    0xf8,

    /* U+0043 "C" */
    0x7d, 0x8f, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc6,
    0xf8,

    /* U+0044 "D" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0xf8,

    /* U+0045 "E" */
    0xff, 0xc, 0x30, 0xc3, 0xfc, 0x30, 0xc3, 0xf0,

    /* U+0046 "F" */
    0xff, 0xc, 0x30, 0xc3, 0xfc, 0x30, 0xc3, 0x0,

    /* U+0047 "G" */
    0x7d, 0x8f, 0x6, 0xc, 0x1b, 0xf1, 0xe3, 0xc6,
    0xfc,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x7f, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+0049 "I" */
    0xff, 0xff, 0xf0,

    /* U+004A "J" */
    0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xcd, 0xe0,

    /* U+004B "K" */
    0xc6, 0xc6, 0xcc, 0xd8, 0xd8, 0xf0, 0xd8, 0xcc,
    0xcc, 0xc6,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xf0,

    /* U+004D "M" */
    0xc1, 0xf1, 0xf8, 0xfe, 0xfd, 0x5e, 0xef, 0x77,
    0x83, 0xc1, 0xe0, 0xc0,

    /* U+004E "N" */
    0xc7, 0xcf, 0x9f, 0xbf, 0x7a, 0xf7, 0xe7, 0xcf,
    0x8c,

    /* U+004F "O" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,
    0xf8,

    /* U+0050 "P" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x7f, 0xb0, 0x60, 0xc1,
    0x80,

    /* U+0051 "Q" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xd6,
    0xf8, 0x60, 0x40,

    /* U+0052 "R" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x7f, 0xb3, 0x66, 0xc7,
    0x8c,

    /* U+0053 "S" */
    0x3e, 0x43, 0x40, 0xf0, 0x7e, 0x3f, 0x7, 0x3,
    0xc3, 0x7e,

    /* U+0054 "T" */
    0xfe, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x60,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,
    0xf8,

    /* U+0056 "V" */
    0xc3, 0xc3, 0x63, 0x66, 0x66, 0x36, 0x34, 0x3c,
    0x1c, 0x18,

    /* U+0057 "W" */
    0xc6, 0x38, 0xcd, 0x39, 0xb7, 0x36, 0xb4, 0xd6,
    0x8e, 0x71, 0xce, 0x39, 0xc6, 0x30,

    /* U+0058 "X" */
    0x43, 0x66, 0x34, 0x3c, 0x18, 0x18, 0x3c, 0x26,
    0x66, 0xc3,

    /* U+0059 "Y" */
    0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0xfc, 0x31, 0x86, 0x30, 0xc6, 0x18, 0xc3, 0xf0,

    /* U+005B "[" */
    0xfb, 0x6d, 0xb6, 0xdb, 0x70,

    /* U+005C "\\" */
    0xc1, 0x81, 0x83, 0x3, 0x6, 0x6, 0x4, 0xc,
    0x8,

    /* U+005D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x3f,

    /* U+005E "^" */
    0x33, 0x9c, 0xbc, 0x80,

    /* U+005F "_" */
    0xfc,

    /* U+0060 "`" */
    0xcc,

    /* U+0061 "a" */
    0x79, 0x30, 0xdf, 0xcf, 0x37, 0xc0,

    /* U+0062 "b" */
    0xc3, 0xc, 0x3e, 0xcf, 0x3c, 0xf3, 0xcf, 0xe0,

    /* U+0063 "c" */
    0x7f, 0x1c, 0x30, 0xc3, 0x17, 0xc0,

    /* U+0064 "d" */
    0xc, 0x30, 0xdf, 0xcf, 0x3c, 0xf3, 0xcd, 0xf0,

    /* U+0065 "e" */
    0x7b, 0x3c, 0xff, 0xc3, 0x37, 0x80,

    /* U+0066 "f" */
    0x3b, 0x19, 0xe6, 0x31, 0x8c, 0x63, 0x0,

    /* U+0067 "g" */
    0x7f, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0x4d, 0xe0,

    /* U+0068 "h" */
    0xc3, 0xc, 0x3e, 0xcf, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+0069 "i" */
    0xc3, 0xff, 0xf0,

    /* U+006A "j" */
    0x30, 0x3, 0x33, 0x33, 0x33, 0x33, 0xe0,

    /* U+006B "k" */
    0xc1, 0x83, 0x6, 0x6d, 0x9a, 0x3c, 0x6c, 0xd9,
    0x98,

    /* U+006C "l" */
    0xff, 0xff, 0xf0,

    /* U+006D "m" */
    0xff, 0xb3, 0x3c, 0xcf, 0x33, 0xcc, 0xf3, 0x3c,
    0xcc,

    /* U+006E "n" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3c, 0xc0,

    /* U+006F "o" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x37, 0x80,

    /* U+0070 "p" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3f, 0xb0, 0xc3, 0x0,

    /* U+0071 "q" */
    0x7f, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0xc, 0x30,

    /* U+0072 "r" */
    0xfb, 0x3c, 0x30, 0xc3, 0xc, 0x0,

    /* U+0073 "s" */
    0x7b, 0x2f, 0x3f, 0x1c, 0x3f, 0x80,

    /* U+0074 "t" */
    0x63, 0x19, 0xf6, 0x31, 0x8c, 0x61, 0xc0,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x37, 0xc0,

    /* U+0076 "v" */
    0xc6, 0x99, 0xb3, 0x43, 0x87, 0xc, 0x0,

    /* U+0077 "w" */
    0xcc, 0xf3, 0x35, 0xe9, 0xfe, 0x73, 0x8c, 0xe3,
    0x30,

    /* U+0078 "x" */
    0x4c, 0xd8, 0xe1, 0xc3, 0x8d, 0xb1, 0x80,

    /* U+0079 "y" */
    0xc6, 0x99, 0xb3, 0x63, 0x87, 0xc, 0x18, 0x30,
    0x40,

    /* U+007A "z" */
    0xf8, 0xcc, 0x66, 0x63, 0xe0,

    /* U+007B "{" */
    0x7c, 0xcc, 0xcc, 0xcc, 0xc7,

    /* U+007C "|" */
    0xff, 0xff, 0xff,

    /* U+007D "}" */
    0xe3, 0x33, 0x33, 0x33, 0x3e,

    /* U+007E "~" */
    0x7f, 0xe0,

    /* U+007F "" */
    0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 60, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 64, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 93, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 6, .adv_w = 136, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 13, .adv_w = 145, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 24, .adv_w = 201, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 140, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 55, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 49, .adv_w = 76, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 56, .adv_w = 76, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 63, .adv_w = 116, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 67, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 72, .adv_w = 64, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 73, .adv_w = 78, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 74, .adv_w = 64, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 115, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 135, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 101, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 98, .adv_w = 126, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 132, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 135, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 131, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 120, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 132, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 131, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 65, .box_w = 2, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 64, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 172, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 178, .adv_w = 128, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 181, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 187, .adv_w = 121, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 168, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 209, .adv_w = 137, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 221, .adv_w = 139, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 230, .adv_w = 137, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 146, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 129, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 256, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 264, .adv_w = 149, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 143, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 61, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 117, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 135, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 120, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 311, .adv_w = 169, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 142, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 148, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 148, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 361, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 145, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 380, .adv_w = 127, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 389, .adv_w = 143, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 398, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 408, .adv_w = 185, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 132, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 129, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 442, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 450, .adv_w = 72, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 455, .adv_w = 109, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 464, .adv_w = 72, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 470, .adv_w = 89, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 474, .adv_w = 115, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 475, .adv_w = 73, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 476, .adv_w = 120, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 490, .adv_w = 118, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 496, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 504, .adv_w = 122, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 83, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 525, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 533, .adv_w = 55, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 58, .box_w = 4, .box_h = 13, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 543, .adv_w = 113, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 552, .adv_w = 56, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 182, .box_w = 10, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 564, .adv_w = 125, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 570, .adv_w = 122, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 125, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 584, .adv_w = 124, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 592, .adv_w = 108, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 598, .adv_w = 118, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 87, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 611, .adv_w = 125, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 617, .adv_w = 107, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 624, .adv_w = 162, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 633, .adv_w = 111, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 107, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 649, .adv_w = 111, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 654, .adv_w = 76, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 659, .adv_w = 53, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 662, .adv_w = 76, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 667, .adv_w = 128, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 669, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 96, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    10, 34,
    10, 55,
    10, 56,
    10, 58,
    13, 3,
    13, 8,
    13, 16,
    14, 53,
    15, 3,
    15, 8,
    15, 16,
    16, 16,
    17, 34,
    17, 55,
    17, 56,
    17, 58,
    20, 34,
    20, 55,
    20, 56,
    20, 58,
    22, 34,
    22, 55,
    22, 56,
    22, 58,
    23, 34,
    23, 55,
    23, 56,
    23, 58,
    24, 21,
    25, 34,
    25, 55,
    25, 56,
    25, 58,
    26, 34,
    26, 55,
    26, 56,
    26, 58,
    27, 16,
    28, 16,
    34, 9,
    34, 16,
    34, 17,
    34, 20,
    34, 22,
    34, 23,
    34, 25,
    34, 26,
    34, 34,
    34, 36,
    34, 40,
    34, 43,
    34, 48,
    34, 50,
    34, 53,
    34, 54,
    34, 55,
    34, 56,
    34, 57,
    34, 58,
    34, 87,
    34, 88,
    34, 90,
    34, 92,
    35, 34,
    35, 58,
    36, 34,
    36, 58,
    37, 34,
    37, 55,
    37, 56,
    37, 58,
    38, 87,
    38, 88,
    38, 90,
    39, 34,
    39, 43,
    40, 55,
    40, 58,
    43, 34,
    44, 9,
    44, 17,
    44, 20,
    44, 22,
    44, 23,
    44, 25,
    44, 26,
    44, 36,
    44, 40,
    44, 48,
    44, 50,
    44, 55,
    44, 56,
    44, 58,
    44, 92,
    45, 53,
    45, 55,
    45, 56,
    45, 58,
    45, 87,
    45, 88,
    45, 90,
    48, 34,
    48, 55,
    48, 56,
    48, 58,
    49, 13,
    49, 15,
    49, 34,
    49, 43,
    50, 34,
    50, 55,
    50, 56,
    50, 58,
    51, 53,
    51, 58,
    52, 53,
    52, 55,
    53, 13,
    53, 14,
    53, 15,
    53, 34,
    53, 43,
    53, 52,
    53, 64,
    53, 66,
    53, 68,
    53, 69,
    53, 70,
    53, 72,
    53, 74,
    53, 75,
    53, 78,
    53, 79,
    53, 80,
    53, 81,
    53, 82,
    53, 83,
    53, 84,
    53, 86,
    53, 87,
    53, 88,
    53, 89,
    53, 90,
    53, 91,
    54, 34,
    55, 9,
    55, 13,
    55, 15,
    55, 17,
    55, 20,
    55, 22,
    55, 23,
    55, 25,
    55, 26,
    55, 34,
    55, 36,
    55, 40,
    55, 43,
    55, 48,
    55, 50,
    55, 52,
    55, 55,
    55, 56,
    55, 57,
    55, 58,
    55, 66,
    55, 68,
    55, 69,
    55, 70,
    55, 72,
    55, 74,
    55, 75,
    55, 78,
    55, 79,
    55, 80,
    55, 81,
    55, 82,
    55, 83,
    55, 84,
    55, 86,
    55, 92,
    56, 9,
    56, 13,
    56, 15,
    56, 17,
    56, 20,
    56, 22,
    56, 23,
    56, 25,
    56, 26,
    56, 34,
    56, 36,
    56, 40,
    56, 43,
    56, 48,
    56, 50,
    56, 55,
    56, 56,
    56, 57,
    56, 58,
    56, 66,
    56, 68,
    56, 69,
    56, 70,
    56, 80,
    56, 82,
    56, 84,
    56, 92,
    57, 34,
    57, 55,
    57, 56,
    57, 58,
    57, 87,
    57, 88,
    57, 90,
    58, 9,
    58, 13,
    58, 15,
    58, 17,
    58, 20,
    58, 22,
    58, 23,
    58, 25,
    58, 26,
    58, 34,
    58, 36,
    58, 40,
    58, 43,
    58, 48,
    58, 50,
    58, 55,
    58, 56,
    58, 57,
    58, 58,
    58, 66,
    58, 68,
    58, 69,
    58, 70,
    58, 72,
    58, 74,
    58, 75,
    58, 78,
    58, 79,
    58, 80,
    58, 81,
    58, 82,
    58, 83,
    58, 84,
    58, 86,
    58, 92,
    64, 53,
    66, 53,
    66, 56,
    66, 58,
    66, 87,
    66, 88,
    66, 90,
    67, 53,
    67, 56,
    67, 58,
    68, 53,
    68, 56,
    68, 58,
    70, 53,
    70, 56,
    70, 58,
    71, 13,
    71, 15,
    72, 53,
    72, 58,
    80, 53,
    80, 56,
    80, 58,
    81, 53,
    81, 56,
    81, 58,
    83, 13,
    83, 15,
    83, 58,
    83, 85,
    83, 87,
    83, 88,
    83, 90,
    84, 53,
    84, 56,
    84, 58,
    86, 53,
    86, 56,
    86, 58,
    87, 13,
    87, 15,
    87, 34,
    87, 53,
    87, 87,
    87, 88,
    87, 90,
    88, 13,
    88, 15,
    88, 34,
    88, 53,
    88, 87,
    88, 88,
    88, 90,
    90, 13,
    90, 15,
    90, 34,
    90, 53,
    90, 87,
    90, 88,
    90, 90,
    91, 53,
    94, 34,
    94, 55,
    94, 56,
    94, 58
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -2, -2, -2, -8, -23, -23, 13, -8,
    -23, -23, 13, -26, -2, -2, -2, -8,
    -2, -2, -2, -8, -2, -2, -2, -8,
    -2, -2, -2, -8, -13, -2, -2, -2,
    -8, -2, -2, -2, -8, 13, 13, -2,
    10, -2, -2, -2, -2, -2, -2, 6,
    -2, -2, -2, -2, -2, -17, -2, -13,
    -8, 5, -17, -4, -3, -4, -2, -2,
    -8, -2, -8, -2, -2, -2, -8, -5,
    -5, -5, -10, -15, -8, -12, -2, -5,
    -5, -5, -5, -5, -5, -5, -5, -5,
    -5, -5, 1, 1, 1, -5, -18, -18,
    -13, -18, -8, -8, -8, -2, -2, -2,
    -8, -18, -18, -12, -20, -2, -2, -2,
    -8, -5, -5, -4, -2, -20, -8, -20,
    -17, -23, -3, -8, -15, -15, -15, -15,
    -10, -5, -5, -14, -14, -15, -14, -15,
    -14, -15, -10, -6, -6, -10, -6, -5,
    -2, -2, -20, -20, -2, -2, -2, -2,
    -2, -2, -13, -2, -2, -15, -2, -2,
    -2, 4, 4, 1, 4, -10, -8, -8,
    -8, -8, -4, -4, -4, -4, -8, -4,
    -8, -4, -8, -4, -2, -2, -15, -15,
    -2, -2, -2, -2, -2, -2, -8, -2,
    -2, -5, -2, -2, 4, 4, 1, 4,
    -4, -3, -3, -3, -3, -3, -3, -2,
    5, 1, 1, 1, -8, -8, -8, -8,
    -20, -20, -8, -8, -8, -8, -8, -8,
    -17, -8, -8, -18, -8, -8, 4, 4,
    1, 5, -13, -10, -10, -10, -10, -5,
    -5, -5, -5, -10, -5, -10, -5, -13,
    -10, -8, -8, -15, -15, -20, -3, -3,
    -3, -8, -10, -13, -10, -10, -18, -18,
    -10, -15, -10, -10, -8, -5, -8, -10,
    -13, -8, -10, -13, -18, -18, -10, 4,
    4, 4, 4, -15, -10, -10, -13, -10,
    -15, -13, -13, -1, -13, 5, 5, 5,
    -13, -13, -1, -13, 5, 5, 5, -13,
    -13, -1, -13, 5, 5, 5, -13, -2,
    -2, -2, -8
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 315,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t blender = {
#else
        lv_font_t blender = {
#endif
        .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
        .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
        .line_height = 14,          /*The maximum line height required by the font*/
        .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
        .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
        .underline_position = -1,
        .underline_thickness = 1,
#endif
#if LVGL_VERSION_MAJOR >= 8
        .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
        .fallback = NULL,
        .user_data = NULL,
#else
        .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#endif
};



#endif /*#if BLENDER16*/
