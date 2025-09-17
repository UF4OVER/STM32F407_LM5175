/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --no-compress --stride 1 --align 1 --font blender-pro-bold.otf --symbols QWERTYUIOPLKJHGFDSAZXCVBNM1234567890qwertyuioplkjhgfdsazxcvbnm,.:% --range 32-127 --format lvgl -o blender20.c
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



#ifndef BLENDER20
#define BLENDER20 1
#endif

#if BLENDER20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xcf,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xb0,

    /* U+0023 "#" */
    0x1b, 0x19, 0x1f, 0xff, 0xf3, 0x67, 0xfb, 0xfc,
    0xc8, 0x6c, 0x36, 0x0,

    /* U+0024 "$" */
    0x8, 0x4, 0xf, 0x8f, 0xec, 0xbe, 0x43, 0xa0,
    0xfc, 0x1f, 0x85, 0xc2, 0x79, 0x3f, 0xf3, 0xf0,
    0x20,

    /* U+0025 "%" */
    0x78, 0x63, 0xf3, 0xc, 0xcc, 0x33, 0x60, 0xfd,
    0x81, 0xed, 0xe0, 0x3f, 0xc1, 0xb3, 0x6, 0xcc,
    0x33, 0x30, 0xcf, 0xc6, 0x1e,

    /* U+0026 "&" */
    0x7c, 0x7f, 0x30, 0xd8, 0xc, 0x3, 0xe3, 0xf7,
    0x83, 0xc1, 0x60, 0xbf, 0xcf, 0xc0,

    /* U+0027 "'" */
    0xff,

    /* U+0028 "(" */
    0x3, 0x7e, 0xcc, 0xcc, 0xcc, 0xcc, 0xce, 0x72,

    /* U+0029 ")" */
    0xc, 0xe7, 0x33, 0x33, 0x33, 0x33, 0x37, 0xe4,

    /* U+002A "*" */
    0x32, 0xdf, 0xde, 0x79, 0x20,

    /* U+002B "+" */
    0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18,

    /* U+002C "," */
    0x7f, 0x60,

    /* U+002D "-" */
    0xff,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x3, 0x81, 0x81, 0xc0, 0xc0, 0xc0, 0x60, 0x60,
    0x30, 0x30, 0x38, 0x18, 0x1c, 0x0,

    /* U+0030 "0" */
    0x7e, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xff, 0x7e,

    /* U+0031 "1" */
    0xff, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x30,

    /* U+0032 "2" */
    0x7e, 0xff, 0xc3, 0x3, 0x7, 0x1e, 0x7c, 0xf0,
    0xc0, 0xc0, 0xff, 0xff,

    /* U+0033 "3" */
    0x7e, 0xff, 0xc3, 0x3, 0x3, 0x3f, 0x3f, 0x3,
    0x3, 0xc3, 0xff, 0x7e,

    /* U+0034 "4" */
    0xe, 0xf, 0x7, 0x87, 0xc3, 0x63, 0xb1, 0x99,
    0xcc, 0xff, 0xff, 0xc1, 0x80, 0xc0,

    /* U+0035 "5" */
    0x7f, 0x3f, 0x98, 0xc, 0x7, 0xf3, 0xfc, 0x6,
    0x3, 0x1, 0xb0, 0xdf, 0xe7, 0xe0,

    /* U+0036 "6" */
    0x7c, 0xfe, 0xc2, 0xc0, 0xfe, 0xff, 0xc3, 0xc3,
    0xc3, 0xc3, 0xff, 0x7e,

    /* U+0037 "7" */
    0xff, 0xff, 0x7, 0x6, 0xe, 0xc, 0xc, 0x18,
    0x18, 0x30, 0x30, 0x70,

    /* U+0038 "8" */
    0x7e, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xff, 0xc3,
    0xc3, 0xc3, 0xff, 0x7e,

    /* U+0039 "9" */
    0x7e, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0x7f,
    0x3, 0x43, 0x7f, 0x3e,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0x6c, 0x0, 0xdb, 0xc0,

    /* U+003C "<" */
    0x3, 0xf, 0x3c, 0xf8, 0xe0, 0x78, 0x3e, 0xf,
    0x3,

    /* U+003D "=" */
    0xff, 0xff, 0x0, 0xff, 0xff,

    /* U+003E ">" */
    0xc0, 0xe0, 0x78, 0x1e, 0x7, 0x1e, 0x78, 0xe0,
    0x80,

    /* U+003F "?" */
    0x7e, 0x7f, 0xc3, 0x3, 0x3, 0xf, 0x1e, 0x18,
    0x18, 0x0, 0x18, 0x18,

    /* U+0040 "@" */
    0x3f, 0x8f, 0xfb, 0x1, 0xe3, 0xfc, 0xff, 0x99,
    0xf3, 0x1e, 0x63, 0xcc, 0x79, 0x9f, 0x3f, 0xe3,
    0xfc, 0x1, 0xc0, 0x10, 0x0,

    /* U+0041 "A" */
    0xe, 0x1, 0xc0, 0x78, 0xd, 0x81, 0xb0, 0x67,
    0xc, 0x61, 0xfc, 0x7f, 0xcc, 0x19, 0x83, 0x60,
    0x70,

    /* U+0042 "B" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xff, 0xc3,
    0xc3, 0xc3, 0xff, 0xfe,

    /* U+0043 "C" */
    0x3e, 0x3f, 0xb0, 0xd8, 0xc, 0x6, 0x3, 0x1,
    0x80, 0xc0, 0x61, 0x9f, 0xc7, 0xc0,

    /* U+0044 "D" */
    0xfe, 0x7f, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xff, 0xdf, 0xc0,

    /* U+0045 "E" */
    0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xfe, 0xfe, 0xc0,
    0xc0, 0xc0, 0xff, 0xff,

    /* U+0046 "F" */
    0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xfe, 0xfe, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0047 "G" */
    0x3e, 0x3f, 0xb0, 0x78, 0xc, 0x6, 0x7f, 0x3f,
    0x83, 0xc1, 0xe0, 0xdf, 0xe7, 0xf0,

    /* U+0048 "H" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1f, 0xff, 0xff,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x30,

    /* U+0049 "I" */
    0xff, 0xff, 0xff,

    /* U+004A "J" */
    0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x7,
    0x8f, 0xf3, 0xc0,

    /* U+004B "K" */
    0xc3, 0x63, 0xb3, 0x99, 0x8d, 0xc7, 0xc3, 0xe1,
    0xb8, 0xcc, 0x63, 0x31, 0xd8, 0x70,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xff, 0xff,

    /* U+004D "M" */
    0xe0, 0xfc, 0x1f, 0xc7, 0xf8, 0xff, 0xbf, 0xb6,
    0xf7, 0xde, 0x73, 0xce, 0x78, 0xf, 0x1, 0xe0,
    0x30,

    /* U+004E "N" */
    0xc3, 0xe3, 0xe3, 0xf3, 0xf3, 0xdb, 0xdb, 0xcf,
    0xcf, 0xc7, 0xc7, 0xc3,

    /* U+004F "O" */
    0x3e, 0x3f, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xdf, 0xc7, 0xc0,

    /* U+0050 "P" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xfe, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0051 "Q" */
    0x3e, 0x3f, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe4, 0xdf, 0xc7, 0xe0, 0xe0, 0x30,

    /* U+0052 "R" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xfe, 0xce,
    0xc6, 0xc6, 0xc3, 0xc3,

    /* U+0053 "S" */
    0x3e, 0x3f, 0xb0, 0xf8, 0xe, 0x3, 0xf0, 0x7e,
    0x3, 0x1, 0xe0, 0xff, 0xcf, 0xc0,

    /* U+0054 "T" */
    0xff, 0xff, 0xc6, 0x3, 0x1, 0x80, 0xc0, 0x60,
    0x30, 0x18, 0xc, 0x6, 0x3, 0x0,

    /* U+0055 "U" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xdf, 0xc7, 0xc0,

    /* U+0056 "V" */
    0xc0, 0xd8, 0x36, 0x1d, 0x86, 0x31, 0x8c, 0xe3,
    0x30, 0x6c, 0x1f, 0x7, 0x81, 0xe0, 0x38,

    /* U+0057 "W" */
    0xc3, 0xf, 0x8e, 0x36, 0x38, 0xd9, 0xe6, 0x67,
    0x99, 0xdb, 0x63, 0x6d, 0x8f, 0x3e, 0x3c, 0xf0,
    0xf1, 0xc1, 0xc7, 0x6, 0x1c,

    /* U+0058 "X" */
    0x61, 0xdc, 0x63, 0x30, 0xfc, 0x1e, 0x3, 0x81,
    0xe0, 0x78, 0x3b, 0xc, 0xe6, 0x1b, 0x87,

    /* U+0059 "Y" */
    0xe1, 0xd8, 0x67, 0x38, 0xcc, 0x1e, 0x7, 0x80,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30,

    /* U+005A "Z" */
    0xff, 0xff, 0x7, 0xe, 0xc, 0x1c, 0x38, 0x30,
    0x70, 0x60, 0xff, 0xff,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xff,

    /* U+005C "\\" */
    0xc0, 0xe0, 0x60, 0x70, 0x30, 0x38, 0x18, 0xc,
    0xc, 0x6, 0x7, 0x3,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0xff,

    /* U+005E "^" */
    0x30, 0x70, 0xe3, 0x46, 0xcd, 0xb1, 0x0,

    /* U+005F "_" */
    0xff, 0xff,

    /* U+0060 "`" */
    0xe6, 0x20,

    /* U+0061 "a" */
    0x3e, 0x7f, 0x3, 0x3f, 0x7f, 0x63, 0x63, 0x7f,
    0x3f,

    /* U+0062 "b" */
    0xc0, 0xc0, 0xc0, 0xfe, 0xff, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xff, 0xfe,

    /* U+0063 "c" */
    0x7c, 0xfe, 0xc6, 0xc0, 0xc0, 0xc0, 0xc6, 0xfe,
    0x7c,

    /* U+0064 "d" */
    0x3, 0x3, 0x3, 0x7f, 0xff, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xff, 0x7f,

    /* U+0065 "e" */
    0x7e, 0xff, 0xc3, 0xc3, 0xff, 0xff, 0xc0, 0xff,
    0x7e,

    /* U+0066 "f" */
    0x3d, 0xf6, 0x3e, 0xf9, 0x86, 0x18, 0x61, 0x86,
    0x18,

    /* U+0067 "g" */
    0x7f, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xff,
    0x7f, 0x3, 0x7f, 0x3e,

    /* U+0068 "h" */
    0xc1, 0x83, 0x7, 0xef, 0xf8, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x30,

    /* U+0069 "i" */
    0xf3, 0xff, 0xff,

    /* U+006A "j" */
    0x33, 0x3, 0x33, 0x33, 0x33, 0x33, 0x3f, 0xe0,

    /* U+006B "k" */
    0xc0, 0xc0, 0xc0, 0xc6, 0xcc, 0xd8, 0xf8, 0xf0,
    0xd8, 0xdc, 0xce, 0xc6,

    /* U+006C "l" */
    0xff, 0xff, 0xff,

    /* U+006D "m" */
    0xfd, 0xef, 0xff, 0xc6, 0x3c, 0x63, 0xc6, 0x3c,
    0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x30,

    /* U+006E "n" */
    0xfd, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,

    /* U+006F "o" */
    0x7e, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff,
    0x7e,

    /* U+0070 "p" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff,
    0xfe, 0xc0, 0xc0, 0xc0,

    /* U+0071 "q" */
    0x7f, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff,
    0x7f, 0x3, 0x3, 0x3,

    /* U+0072 "r" */
    0xfd, 0xff, 0x16, 0xc, 0x18, 0x30, 0x60, 0xc0,

    /* U+0073 "s" */
    0x7c, 0xfe, 0xc4, 0xe0, 0xfe, 0x6, 0x46, 0xfe,
    0x7c,

    /* U+0074 "t" */
    0x61, 0x86, 0x3f, 0xfd, 0x86, 0x18, 0x61, 0x87,
    0xcf,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff, 0x7e,

    /* U+0076 "v" */
    0xc3, 0xe3, 0x66, 0x66, 0x36, 0x3c, 0x3c, 0x1c,
    0x18,

    /* U+0077 "w" */
    0xc7, 0x3f, 0x39, 0x99, 0xcc, 0xde, 0x66, 0xde,
    0x1e, 0xf0, 0xe7, 0x87, 0x18, 0x38, 0xc0,

    /* U+0078 "x" */
    0x63, 0x3b, 0xf, 0x83, 0x81, 0xc1, 0xe0, 0xd8,
    0xee, 0xe3, 0x0,

    /* U+0079 "y" */
    0xc3, 0xe3, 0x66, 0x66, 0x36, 0x3c, 0x3c, 0x1c,
    0x18, 0x18, 0x18, 0x30,

    /* U+007A "z" */
    0xff, 0xfc, 0x30, 0xe3, 0x8e, 0x18, 0x7f, 0xfe,

    /* U+007B "{" */
    0x3b, 0xf1, 0x8c, 0x63, 0x18, 0xc6, 0x1e, 0x70,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xfc,

    /* U+007D "}" */
    0xe7, 0x86, 0x31, 0x8c, 0x63, 0x18, 0xfd, 0xc0,

    /* U+007E "~" */
    0x0, 0x7f, 0xfe,

    /* U+007F "" */
    0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 75, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 80, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 116, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 7, .adv_w = 170, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 19, .adv_w = 181, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 36, .adv_w = 251, .box_w = 14, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 174, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 69, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 72, .adv_w = 95, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 80, .adv_w = 95, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 88, .adv_w = 145, .box_w = 6, .box_h = 6, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 93, .adv_w = 160, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 100, .adv_w = 80, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 102, .adv_w = 98, .box_w = 4, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 103, .adv_w = 80, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 143, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 169, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 126, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 158, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 165, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 162, .adv_w = 169, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 176, .adv_w = 160, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 163, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 214, .adv_w = 165, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 163, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 81, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 80, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 244, .adv_w = 160, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 253, .adv_w = 160, .box_w = 8, .box_h = 5, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 258, .adv_w = 160, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 267, .adv_w = 151, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 210, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 300, .adv_w = 172, .box_w = 11, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 174, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 172, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 343, .adv_w = 183, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 161, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 155, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 186, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 395, .adv_w = 179, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 409, .adv_w = 76, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 169, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 150, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 211, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 466, .adv_w = 178, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 185, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 168, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 504, .adv_w = 185, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 520, .adv_w = 177, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 181, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 546, .adv_w = 159, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 560, .adv_w = 179, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 574, .adv_w = 167, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 231, .box_w = 14, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 164, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 625, .adv_w = 162, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 153, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 652, .adv_w = 90, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 660, .adv_w = 136, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 672, .adv_w = 90, .box_w = 4, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 680, .adv_w = 111, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 687, .adv_w = 144, .box_w = 8, .box_h = 2, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 689, .adv_w = 92, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 10},
    {.bitmap_index = 691, .adv_w = 149, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 700, .adv_w = 156, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 712, .adv_w = 147, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 721, .adv_w = 156, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 733, .adv_w = 152, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 742, .adv_w = 104, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 751, .adv_w = 156, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 763, .adv_w = 155, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 774, .adv_w = 69, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 777, .adv_w = 72, .box_w = 4, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 785, .adv_w = 141, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 797, .adv_w = 70, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 800, .adv_w = 227, .box_w = 12, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 814, .adv_w = 156, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 822, .adv_w = 153, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 831, .adv_w = 156, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 843, .adv_w = 156, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 855, .adv_w = 135, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 863, .adv_w = 148, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 872, .adv_w = 108, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 881, .adv_w = 156, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 889, .adv_w = 133, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 898, .adv_w = 202, .box_w = 13, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 913, .adv_w = 139, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 924, .adv_w = 133, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 936, .adv_w = 138, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 944, .adv_w = 95, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 952, .adv_w = 66, .box_w = 2, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 956, .adv_w = 95, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 964, .adv_w = 160, .box_w = 8, .box_h = 3, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 967, .adv_w = 160, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0}
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
    -2, -2, -2, -10, -29, -29, 16, -10,
    -29, -29, 16, -32, -2, -2, -2, -10,
    -2, -2, -2, -10, -2, -2, -2, -10,
    -2, -2, -2, -10, -16, -2, -2, -2,
    -10, -2, -2, -2, -10, 16, 16, -2,
    13, -2, -2, -2, -2, -2, -2, 8,
    -2, -2, -2, -2, -2, -21, -2, -16,
    -10, 6, -21, -5, -3, -5, -2, -2,
    -10, -2, -10, -2, -2, -2, -10, -6,
    -6, -6, -13, -19, -10, -14, -2, -6,
    -6, -6, -6, -6, -6, -6, -6, -6,
    -6, -6, 2, 2, 2, -6, -22, -22,
    -16, -22, -10, -10, -10, -2, -2, -2,
    -10, -23, -23, -15, -26, -2, -2, -2,
    -10, -6, -6, -5, -2, -25, -10, -25,
    -21, -29, -3, -10, -19, -19, -19, -19,
    -13, -6, -6, -17, -17, -19, -17, -19,
    -17, -19, -13, -8, -8, -13, -8, -6,
    -2, -2, -26, -26, -2, -2, -2, -2,
    -2, -2, -16, -2, -2, -19, -2, -2,
    -2, 5, 5, 2, 5, -13, -10, -10,
    -10, -10, -5, -5, -5, -5, -10, -5,
    -10, -5, -10, -5, -2, -2, -19, -19,
    -2, -2, -2, -2, -2, -2, -10, -2,
    -2, -6, -2, -2, 5, 5, 2, 5,
    -5, -3, -3, -3, -3, -3, -3, -2,
    6, 2, 2, 2, -10, -10, -10, -10,
    -26, -26, -10, -10, -10, -10, -10, -10,
    -21, -10, -10, -22, -10, -10, 5, 5,
    2, 6, -16, -13, -13, -13, -13, -6,
    -6, -6, -6, -13, -6, -13, -6, -16,
    -13, -10, -10, -19, -19, -26, -3, -3,
    -3, -10, -13, -16, -13, -13, -22, -22,
    -13, -19, -13, -13, -10, -6, -10, -13,
    -16, -10, -13, -16, -22, -22, -13, 5,
    5, 5, 5, -19, -13, -13, -16, -13,
    -19, -16, -16, -2, -16, 6, 6, 6,
    -16, -16, -2, -16, 6, 6, 6, -16,
    -16, -2, -16, 6, 6, 6, -16, -2,
    -2, -2, -10
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
const lv_font_t blender20 = {
#else
lv_font_t blender20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if BLENDER20*/
