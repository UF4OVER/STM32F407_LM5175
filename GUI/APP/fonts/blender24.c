/*******************************************************************************
 * Size: 24 px
 * Bpp: 1
 * Opts: --bpp 1 --size 24 --no-compress --stride 1 --align 1 --font blender-pro-bold.otf --symbols QWERTYUIOPLKJHGFDSAZXCVBNM1234567890qwertyuioplkjhgfdsazxcvbnm,.:% --range 32-127 --format lvgl -o blender24.c
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



#ifndef BLENDER24
#define BLENDER24 1
#endif

#if BLENDER24

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xdb, 0x6d, 0xb6, 0xdb, 0xf, 0xf8,

    /* U+0022 "\"" */
    0xcf, 0x3c, 0xf3,

    /* U+0023 "#" */
    0xd, 0x83, 0x30, 0x66, 0x3f, 0xf7, 0xfe, 0x36,
    0xe, 0xc7, 0xfe, 0xff, 0xc6, 0x60, 0xdc, 0x3b,
    0x0,

    /* U+0024 "$" */
    0x6, 0x0, 0xc0, 0xfe, 0x3f, 0xee, 0x6f, 0x8c,
    0x31, 0x87, 0xb0, 0xff, 0xf, 0xf8, 0x1f, 0x83,
    0x70, 0x66, 0xc, 0xf1, 0xbf, 0xfe, 0x3f, 0x80,
    0xc0, 0x18, 0x0,

    /* U+0025 "%" */
    0x7c, 0x18, 0x7f, 0x1c, 0x31, 0x8c, 0x18, 0xce,
    0xc, 0x66, 0x6, 0x37, 0x3, 0xfb, 0x0, 0xfb,
    0xbe, 0x1, 0xbf, 0x81, 0xd8, 0xc0, 0xcc, 0x60,
    0xe6, 0x30, 0x63, 0x18, 0x71, 0xfc, 0x30, 0x7c,

    /* U+0026 "&" */
    0x3f, 0xf, 0xf3, 0x7, 0x60, 0xc, 0x1, 0x80,
    0x3f, 0x83, 0xf0, 0xc0, 0xf8, 0x1f, 0x3, 0x60,
    0x6c, 0xc, 0xff, 0x8f, 0xe0,

    /* U+0027 "'" */
    0xff,

    /* U+0028 "(" */
    0x1, 0x9d, 0xcc, 0x63, 0x18, 0xc6, 0x31, 0x8c,
    0x63, 0x1c, 0xe3, 0x8c, 0x0,

    /* U+0029 ")" */
    0x3, 0x1c, 0x71, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x67, 0x33, 0x98, 0x0,

    /* U+002A "*" */
    0x18, 0x18, 0x7e, 0xff, 0x3c, 0x3c, 0x76, 0x4,

    /* U+002B "+" */
    0xc, 0x6, 0x3, 0x1f, 0xff, 0xf8, 0x60, 0x30,
    0x18, 0xc, 0x0,

    /* U+002C "," */
    0x47, 0x6e, 0xe0,

    /* U+002D "-" */
    0xff, 0xc0,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x0, 0xc0, 0x38, 0x6, 0x1, 0xc0, 0x30, 0xe,
    0x1, 0x80, 0x70, 0x1c, 0x3, 0x80, 0xe0, 0x1c,
    0x7, 0x0, 0xe0, 0x38, 0x0,

    /* U+0030 "0" */
    0x3f, 0x1f, 0xec, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xdf, 0xe3, 0xf0,

    /* U+0031 "1" */
    0xff, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x60,

    /* U+0032 "2" */
    0x3e, 0x3f, 0xb0, 0x60, 0x30, 0x18, 0x1c, 0x3e,
    0x7e, 0x7c, 0x78, 0x38, 0x18, 0xc, 0x7, 0xff,
    0xfe,

    /* U+0033 "3" */
    0x7e, 0x7f, 0xb8, 0x60, 0x30, 0x18, 0xc, 0x7e,
    0x3e, 0x1, 0x80, 0xc0, 0x60, 0x3e, 0x1f, 0xf9,
    0xf8,

    /* U+0034 "4" */
    0x3, 0x80, 0xf0, 0x3e, 0x7, 0xc1, 0xd8, 0x3b,
    0xe, 0x61, 0xcc, 0x71, 0x9c, 0x33, 0xff, 0xff,
    0xf0, 0x18, 0x3, 0x0, 0x60,

    /* U+0035 "5" */
    0x7f, 0x9f, 0xe6, 0x1, 0x80, 0x60, 0x18, 0x7,
    0xf1, 0xfe, 0x0, 0xc0, 0x30, 0xc, 0x3, 0xe0,
    0xdf, 0xe3, 0xf0,

    /* U+0036 "6" */
    0x3e, 0x3f, 0xb0, 0xf8, 0xc, 0x7, 0xf3, 0xfd,
    0xc3, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0xf9,
    0xf8,

    /* U+0037 "7" */
    0xff, 0xff, 0xf0, 0x1c, 0xe, 0x3, 0x81, 0xc0,
    0x70, 0x18, 0xe, 0x3, 0x81, 0xc0, 0x70, 0x38,
    0xe, 0x7, 0x0,

    /* U+0038 "8" */
    0x7f, 0x3f, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0xff,
    0xfe, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1b, 0xf8,
    0xf8,

    /* U+0039 "9" */
    0x7f, 0x7f, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0xe,
    0xff, 0x3f, 0x80, 0xc0, 0x60, 0x3e, 0x1b, 0xf8,
    0xfc,

    /* U+003A ":" */
    0xff, 0x80, 0x3f, 0xe0,

    /* U+003B ";" */
    0x77, 0x70, 0x0, 0x7, 0x76, 0xee,

    /* U+003C "<" */
    0x0, 0x0, 0xc1, 0xe3, 0xe7, 0xc7, 0xc3, 0xc0,
    0xf8, 0x1f, 0x7, 0xc0, 0xe0, 0x10,

    /* U+003D "=" */
    0xff, 0xff, 0xc0, 0x0, 0xf, 0xff, 0xfc,

    /* U+003E ">" */
    0x0, 0x60, 0x3c, 0xf, 0x81, 0xf0, 0x7c, 0x1e,
    0x3e, 0x7c, 0x7c, 0x38, 0x10, 0x0,

    /* U+003F "?" */
    0x3f, 0x1f, 0xee, 0x1c, 0x3, 0x0, 0xc0, 0x70,
    0x7c, 0x3e, 0xe, 0x3, 0x0, 0xc0, 0x0, 0xc,
    0x3, 0x0, 0xc0,

    /* U+0040 "@" */
    0x3f, 0xe3, 0xff, 0xb8, 0xf, 0x80, 0x3c, 0x1f,
    0xe1, 0xff, 0x18, 0xf8, 0xc3, 0xc6, 0x1e, 0x30,
    0xf1, 0x87, 0x8c, 0x3c, 0x63, 0xe1, 0xff, 0x7,
    0xf8, 0x0, 0xe0, 0x3, 0x0, 0x0,

    /* U+0041 "A" */
    0x7, 0x0, 0x78, 0x3, 0xe0, 0x1f, 0x1, 0xd8,
    0xe, 0xe0, 0x77, 0x7, 0x18, 0x38, 0xe1, 0xc7,
    0x1f, 0xf8, 0xff, 0xe7, 0x7, 0x70, 0x1b, 0x80,
    0xe0,

    /* U+0042 "B" */
    0xff, 0x3f, 0xec, 0xf, 0x3, 0xc0, 0xf0, 0x3f,
    0xff, 0xfe, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xff, 0xef, 0xf0,

    /* U+0043 "C" */
    0x3f, 0x1f, 0xee, 0x1f, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xe1,
    0xdf, 0xe3, 0xf0,

    /* U+0044 "D" */
    0xff, 0x3f, 0xec, 0x1f, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc1,
    0xff, 0xef, 0xf0,

    /* U+0045 "E" */
    0xff, 0xff, 0xf0, 0x18, 0xc, 0x6, 0x3, 0x1,
    0xff, 0xff, 0xe0, 0x30, 0x18, 0xc, 0x7, 0xff,
    0xfe,

    /* U+0046 "F" */
    0xff, 0xff, 0xf0, 0x18, 0xc, 0x6, 0x3, 0x1,
    0xff, 0xff, 0xe0, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x0,

    /* U+0047 "G" */
    0x3f, 0x1f, 0xee, 0x1f, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x1f, 0xc7, 0xf0, 0x3c, 0xf, 0x3, 0xe1,
    0xdf, 0xf3, 0xfc,

    /* U+0048 "H" */
    0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0xff, 0xff, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xf0, 0x3c, 0xc,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xfc,

    /* U+004A "J" */
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3,
    0x3, 0x3, 0x3, 0x3, 0xe7, 0xfe, 0x7c,

    /* U+004B "K" */
    0xc1, 0xf0, 0xec, 0x73, 0x1c, 0xce, 0x37, 0xf,
    0x83, 0xe0, 0xdc, 0x33, 0x8c, 0xe3, 0x1c, 0xc3,
    0xb0, 0xec, 0x1c,

    /* U+004C "L" */
    0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3, 0x1,
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x7, 0xff,
    0xfe,

    /* U+004D "M" */
    0xe0, 0x7e, 0x7, 0xf0, 0xff, 0xf, 0xf8, 0xff,
    0x9f, 0xd9, 0xbd, 0xfb, 0xcf, 0x3c, 0xf3, 0xc6,
    0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x30,

    /* U+004E "N" */
    0xe0, 0xf8, 0x3f, 0xf, 0xc3, 0xf8, 0xfe, 0x3d,
    0xcf, 0x7b, 0xce, 0xf1, 0xfc, 0x7f, 0xf, 0xc3,
    0xf0, 0x7c, 0xc,

    /* U+004F "O" */
    0x3f, 0x8f, 0xfb, 0x83, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xf, 0x1, 0xe0,
    0x3e, 0xe, 0xff, 0x8f, 0xe0,

    /* U+0050 "P" */
    0xff, 0x3f, 0xec, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0xfe, 0xff, 0x30, 0xc, 0x3, 0x0, 0xc0,
    0x30, 0xc, 0x0,

    /* U+0051 "Q" */
    0x3f, 0x8f, 0xfb, 0x83, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xf, 0x1, 0xe0,
    0x3e, 0xee, 0xff, 0x8f, 0xe0, 0x3c, 0x3, 0x80,

    /* U+0052 "R" */
    0xff, 0x1f, 0xf3, 0x3, 0x60, 0x6c, 0xd, 0x81,
    0xb0, 0x37, 0xfc, 0xff, 0x98, 0xe3, 0xe, 0x61,
    0xcc, 0x1d, 0x83, 0xb0, 0x30,

    /* U+0053 "S" */
    0x3f, 0x8f, 0xfb, 0x83, 0xe0, 0xc, 0x1, 0xe0,
    0x3f, 0xc3, 0xfe, 0xf, 0xe0, 0x1c, 0x1, 0x80,
    0x3c, 0xf, 0xff, 0x8f, 0xe0,

    /* U+0054 "T" */
    0xff, 0xff, 0xf0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0,

    /* U+0055 "U" */
    0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xe1,
    0xdf, 0xe3, 0xf0,

    /* U+0056 "V" */
    0xe0, 0x36, 0x7, 0x70, 0x77, 0x6, 0x70, 0xe3,
    0xe, 0x38, 0xc3, 0x8c, 0x19, 0xc1, 0xd8, 0x1d,
    0x80, 0xf8, 0xf, 0x80, 0xf0, 0x7, 0x0,

    /* U+0057 "W" */
    0xe1, 0xc3, 0xf0, 0xe1, 0xd8, 0x78, 0xee, 0x3c,
    0x67, 0x3e, 0x33, 0x9b, 0x38, 0xcd, 0x9c, 0x66,
    0xec, 0x3f, 0x36, 0x1f, 0x9b, 0xf, 0x8f, 0x83,
    0xc7, 0xc1, 0xe3, 0xc0, 0xf0, 0xe0, 0x70, 0x70,

    /* U+0058 "X" */
    0x70, 0x77, 0xe, 0x38, 0xc3, 0x9c, 0x1f, 0x80,
    0xf8, 0xf, 0x0, 0x70, 0xf, 0x1, 0xf8, 0x1d,
    0xc3, 0x9c, 0x30, 0xe7, 0xe, 0xe0, 0x70,

    /* U+0059 "Y" */
    0x60, 0x67, 0xe, 0x30, 0xc3, 0x9c, 0x19, 0x81,
    0xf8, 0xf, 0x0, 0xf0, 0x6, 0x0, 0x60, 0x6,
    0x0, 0x60, 0x6, 0x0, 0x60, 0x6, 0x0,

    /* U+005A "Z" */
    0xff, 0xff, 0xc0, 0xe0, 0xe0, 0x70, 0x70, 0x30,
    0x38, 0x18, 0x1c, 0x1c, 0xe, 0xe, 0x7, 0xff,
    0xfe,

    /* U+005B "[" */
    0xff, 0xf1, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c,
    0x63, 0x18, 0xc7, 0xfe,

    /* U+005C "\\" */
    0x60, 0xe, 0x0, 0xc0, 0x1c, 0x1, 0xc0, 0x38,
    0x3, 0x80, 0x70, 0x7, 0x0, 0xe0, 0xe, 0x1,
    0xc0, 0x1c, 0x3, 0x80, 0x38,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x3f, 0xf0,

    /* U+005E "^" */
    0x18, 0x3c, 0x3c, 0x3c, 0x76, 0x66, 0x66, 0x67,

    /* U+005F "_" */
    0xff, 0xff, 0xc0,

    /* U+0060 "`" */
    0x63, 0x8c, 0x40,

    /* U+0061 "a" */
    0x3e, 0x3f, 0x88, 0x60, 0x33, 0xfb, 0xfd, 0x87,
    0xc3, 0x63, 0xbf, 0xcf, 0xe0,

    /* U+0062 "b" */
    0xc0, 0x60, 0x30, 0x18, 0xf, 0xe7, 0xfb, 0x87,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3e, 0x1f, 0xfb,
    0xf8,

    /* U+0063 "c" */
    0x3e, 0x3f, 0xb0, 0xd8, 0xc, 0x6, 0x3, 0x1,
    0x80, 0xc3, 0x3f, 0x8f, 0x80,

    /* U+0064 "d" */
    0x1, 0x80, 0xc0, 0x60, 0x33, 0xfb, 0xff, 0xf,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x3b, 0xfc,
    0xfe,

    /* U+0065 "e" */
    0x3e, 0x3f, 0xb0, 0x78, 0x3c, 0x1f, 0xff, 0xff,
    0x80, 0xc1, 0x3f, 0x8f, 0x80,

    /* U+0066 "f" */
    0x1e, 0x7c, 0xc1, 0x8f, 0xff, 0xcc, 0x18, 0x30,
    0x60, 0xc1, 0x83, 0x6, 0xc, 0x0,

    /* U+0067 "g" */
    0x3f, 0xbf, 0xf0, 0xf8, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc3, 0xbf, 0xcf, 0xe0, 0x36, 0x1b, 0xf8,
    0xf8,

    /* U+0068 "h" */
    0xc0, 0x60, 0x30, 0x18, 0xf, 0xe7, 0xfb, 0x87,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf,
    0x6,

    /* U+0069 "i" */
    0xf0, 0xff, 0xff, 0xfc,

    /* U+006A "j" */
    0x33, 0x0, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x3e, 0xe0,

    /* U+006B "k" */
    0xc0, 0x60, 0x30, 0x18, 0xc, 0x76, 0x73, 0x39,
    0xb8, 0xf8, 0x7c, 0x37, 0x1b, 0x8c, 0xe6, 0x3b,
    0x1c,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xfc,

    /* U+006D "m" */
    0xfe, 0xf3, 0xff, 0xee, 0x38, 0xf0, 0xc3, 0xc3,
    0xf, 0xc, 0x3c, 0x30, 0xf0, 0xc3, 0xc3, 0xf,
    0xc, 0x3c, 0x30, 0xc0,

    /* U+006E "n" */
    0xfe, 0x7f, 0xb8, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x60,

    /* U+006F "o" */
    0x3e, 0x3f, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xbf, 0x8f, 0x80,

    /* U+0070 "p" */
    0xfe, 0x7f, 0xb8, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xe1, 0xff, 0xbf, 0x98, 0xc, 0x6, 0x3,
    0x0,

    /* U+0071 "q" */
    0x3f, 0xbf, 0xf0, 0xf8, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc3, 0xbf, 0xcf, 0xe0, 0x30, 0x18, 0xc,
    0x6,

    /* U+0072 "r" */
    0xfe, 0xff, 0xe2, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0,

    /* U+0073 "s" */
    0x3e, 0x3f, 0xb8, 0xd8, 0xf, 0xe7, 0xfc, 0xfe,
    0x3, 0xc3, 0xff, 0x9f, 0x80,

    /* U+0074 "t" */
    0x30, 0x60, 0xc1, 0x8f, 0xff, 0xcc, 0x18, 0x30,
    0x60, 0xc1, 0x83, 0x3, 0xc3, 0x80,

    /* U+0075 "u" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc3, 0xbf, 0xcf, 0xe0,

    /* U+0076 "v" */
    0xe1, 0xf8, 0x76, 0x19, 0xce, 0x33, 0x8c, 0xc3,
    0xf0, 0x78, 0x1e, 0x7, 0x80, 0xc0,

    /* U+0077 "w" */
    0xe3, 0x87, 0xc7, 0x1d, 0x8f, 0x33, 0x3e, 0x67,
    0x6d, 0xce, 0xdb, 0x8d, 0xbe, 0x1f, 0x3c, 0x3c,
    0x78, 0x38, 0xf0, 0x71, 0xc0,

    /* U+0078 "x" */
    0x71, 0xdc, 0xe3, 0xb0, 0x7c, 0x1e, 0x3, 0x81,
    0xe0, 0xfc, 0x3b, 0x9c, 0xe6, 0x1c,

    /* U+0079 "y" */
    0xe1, 0xf8, 0x76, 0x19, 0xce, 0x33, 0x8c, 0xc3,
    0xf0, 0x78, 0x1e, 0x7, 0x80, 0xc0, 0x30, 0x1c,
    0x6, 0x1, 0x80,

    /* U+007A "z" */
    0xff, 0xff, 0x7, 0xe, 0x1c, 0x1c, 0x38, 0x70,
    0x70, 0xff, 0xff,

    /* U+007B "{" */
    0x3d, 0xfe, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,
    0x30, 0xe1, 0xf3, 0xc0,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xfc,

    /* U+007D "}" */
    0xe7, 0x8e, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x33,
    0xfb, 0x80,

    /* U+007E "~" */
    0x39, 0x1f, 0xe7, 0xf8,

    /* U+007F "" */
    0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 90, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 96, .box_w = 3, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 7, .adv_w = 140, .box_w = 6, .box_h = 4, .ofs_x = 2, .ofs_y = 11},
    {.bitmap_index = 10, .adv_w = 204, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 27, .adv_w = 217, .box_w = 11, .box_h = 19, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 54, .adv_w = 301, .box_w = 17, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 209, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 83, .box_w = 2, .box_h = 4, .ofs_x = 2, .ofs_y = 11},
    {.bitmap_index = 108, .adv_w = 114, .box_w = 5, .box_h = 20, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 121, .adv_w = 114, .box_w = 5, .box_h = 20, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 134, .adv_w = 174, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 142, .adv_w = 192, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 153, .adv_w = 96, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 156, .adv_w = 118, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 158, .adv_w = 96, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 172, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 203, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 200, .adv_w = 151, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 190, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 198, .box_w = 9, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 244, .adv_w = 202, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 265, .adv_w = 192, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 196, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 180, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 320, .adv_w = 199, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 337, .adv_w = 196, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 98, .box_w = 3, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 96, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 364, .adv_w = 192, .box_w = 9, .box_h = 12, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 378, .adv_w = 192, .box_w = 9, .box_h = 6, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 385, .adv_w = 192, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 399, .adv_w = 181, .box_w = 10, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 252, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 448, .adv_w = 206, .box_w = 13, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 209, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 206, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 220, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 194, .box_w = 9, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 185, .box_w = 9, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 564, .adv_w = 223, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 583, .adv_w = 215, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 602, .adv_w = 91, .box_w = 2, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 175, .box_w = 8, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 202, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 180, .box_w = 9, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 657, .adv_w = 253, .box_w = 12, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 680, .adv_w = 213, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 699, .adv_w = 222, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 720, .adv_w = 202, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 739, .adv_w = 222, .box_w = 11, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 763, .adv_w = 212, .box_w = 11, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 784, .adv_w = 217, .box_w = 11, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 805, .adv_w = 191, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 824, .adv_w = 215, .box_w = 10, .box_h = 15, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 843, .adv_w = 200, .box_w = 12, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 866, .adv_w = 277, .box_w = 17, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 898, .adv_w = 197, .box_w = 12, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 921, .adv_w = 194, .box_w = 12, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 944, .adv_w = 184, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 961, .adv_w = 108, .box_w = 5, .box_h = 19, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 973, .adv_w = 163, .box_w = 11, .box_h = 15, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 994, .adv_w = 108, .box_w = 4, .box_h = 19, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1004, .adv_w = 133, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 1012, .adv_w = 172, .box_w = 9, .box_h = 2, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1015, .adv_w = 110, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 12},
    {.bitmap_index = 1018, .adv_w = 179, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1031, .adv_w = 187, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1048, .adv_w = 176, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1061, .adv_w = 187, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1078, .adv_w = 183, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1091, .adv_w = 124, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1105, .adv_w = 187, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1122, .adv_w = 186, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1139, .adv_w = 83, .box_w = 2, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1143, .adv_w = 86, .box_w = 4, .box_h = 19, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 1153, .adv_w = 169, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1170, .adv_w = 84, .box_w = 2, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1174, .adv_w = 273, .box_w = 14, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1194, .adv_w = 187, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1207, .adv_w = 183, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1220, .adv_w = 187, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1237, .adv_w = 187, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1254, .adv_w = 162, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1265, .adv_w = 177, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1278, .adv_w = 130, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1292, .adv_w = 187, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1305, .adv_w = 160, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1319, .adv_w = 243, .box_w = 15, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1340, .adv_w = 167, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1354, .adv_w = 160, .box_w = 10, .box_h = 15, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1373, .adv_w = 166, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1384, .adv_w = 114, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1396, .adv_w = 79, .box_w = 2, .box_h = 19, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1401, .adv_w = 114, .box_w = 5, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1411, .adv_w = 192, .box_w = 10, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 1415, .adv_w = 192, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0}
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
    -3, -3, -3, -12, -35, -35, 19, -12,
    -35, -35, 19, -38, -3, -3, -3, -12,
    -3, -3, -3, -12, -3, -3, -3, -12,
    -3, -3, -3, -12, -19, -3, -3, -3,
    -12, -3, -3, -3, -12, 19, 19, -3,
    15, -3, -3, -3, -3, -3, -3, 10,
    -3, -3, -3, -3, -3, -25, -3, -19,
    -12, 8, -25, -6, -4, -6, -3, -3,
    -12, -3, -12, -3, -3, -3, -12, -8,
    -8, -8, -15, -23, -12, -17, -3, -8,
    -8, -8, -8, -8, -8, -8, -8, -8,
    -8, -8, 2, 2, 2, -8, -27, -27,
    -20, -27, -12, -12, -12, -3, -3, -3,
    -12, -27, -27, -18, -31, -3, -3, -3,
    -12, -8, -8, -6, -3, -30, -12, -30,
    -25, -35, -4, -12, -23, -23, -23, -23,
    -15, -8, -8, -21, -21, -23, -21, -23,
    -21, -23, -15, -10, -10, -15, -10, -8,
    -3, -3, -31, -31, -3, -3, -3, -3,
    -3, -3, -19, -3, -3, -23, -3, -3,
    -3, 6, 6, 2, 6, -15, -12, -12,
    -12, -12, -6, -6, -6, -6, -12, -6,
    -12, -6, -12, -6, -3, -3, -23, -23,
    -3, -3, -3, -3, -3, -3, -12, -3,
    -3, -8, -3, -3, 6, 6, 2, 6,
    -6, -4, -4, -4, -4, -4, -4, -3,
    8, 2, 2, 2, -12, -12, -12, -12,
    -31, -31, -12, -12, -12, -12, -12, -12,
    -25, -12, -12, -27, -12, -12, 6, 6,
    2, 8, -20, -15, -15, -15, -15, -8,
    -8, -8, -8, -15, -8, -15, -8, -19,
    -15, -12, -12, -23, -23, -31, -4, -4,
    -4, -12, -15, -19, -15, -15, -27, -27,
    -15, -23, -15, -15, -12, -8, -12, -15,
    -19, -12, -15, -19, -27, -27, -15, 6,
    6, 6, 6, -23, -15, -15, -19, -15,
    -23, -19, -19, -2, -19, 8, 8, 8,
    -19, -19, -2, -19, 8, 8, 8, -19,
    -19, -2, -19, 8, 8, 8, -19, -3,
    -3, -3, -12
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
const lv_font_t blender24 = {
#else
lv_font_t blender24 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 21,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if BLENDER24*/
