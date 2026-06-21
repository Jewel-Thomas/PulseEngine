#pragma once


// Taken from glfw.h

/* The unknown key */
#define PLS_KEY_UNKNOWN            -1

/* Printable keys */
#define PLS_KEY_SPACE              32
#define PLS_KEY_APOSTROPHE         39  /* ' */
#define PLS_KEY_COMMA              44  /* , */
#define PLS_KEY_MINUS              45  /* - */
#define PLS_KEY_PERIOD             46  /* . */
#define PLS_KEY_SLASH              47  /* / */
#define PLS_KEY_0                  48
#define PLS_KEY_1                  49
#define PLS_KEY_2                  50
#define PLS_KEY_3                  51
#define PLS_KEY_4                  52
#define PLS_KEY_5                  53
#define PLS_KEY_6                  54
#define PLS_KEY_7                  55
#define PLS_KEY_8                  56
#define PLS_KEY_9                  57
#define PLS_KEY_SEMICOLON          59  /* ; */
#define PLS_KEY_EQUAL              61  /* = */
#define PLS_KEY_A                  65
#define PLS_KEY_B                  66
#define PLS_KEY_C                  67
#define PLS_KEY_D                  68
#define PLS_KEY_E                  69
#define PLS_KEY_F                  70
#define PLS_KEY_G                  71
#define PLS_KEY_H                  72
#define PLS_KEY_I                  73
#define PLS_KEY_J                  74
#define PLS_KEY_K                  75
#define PLS_KEY_L                  76
#define PLS_KEY_M                  77
#define PLS_KEY_N                  78
#define PLS_KEY_O                  79
#define PLS_KEY_P                  80
#define PLS_KEY_Q                  81
#define PLS_KEY_R                  82
#define PLS_KEY_S                  83
#define PLS_KEY_T                  84
#define PLS_KEY_U                  85
#define PLS_KEY_V                  86
#define PLS_KEY_W                  87
#define PLS_KEY_X                  88
#define PLS_KEY_Y                  89
#define PLS_KEY_Z                  90
#define PLS_KEY_LEFT_BRACKET       91  /* [ */
#define PLS_KEY_BACKSLASH          92  /* \ */
#define PLS_KEY_RIGHT_BRACKET      93  /* ] */
#define PLS_KEY_GRAVE_ACCENT       96  /* ` */
#define PLS_KEY_WORLD_1            161 /* non-US #1 */
#define PLS_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define PLS_KEY_ESCAPE             256
#define PLS_KEY_ENTER              257
#define PLS_KEY_TAB                258
#define PLS_KEY_BACKSPACE          259
#define PLS_KEY_INSERT             260
#define PLS_KEY_DELETE             261
#define PLS_KEY_RIGHT              262
#define PLS_KEY_LEFT               263
#define PLS_KEY_DOWN               264
#define PLS_KEY_UP                 265
#define PLS_KEY_PAGE_UP            266
#define PLS_KEY_PAGE_DOWN          267
#define PLS_KEY_HOME               268
#define PLS_KEY_END                269
#define PLS_KEY_CAPS_LOCK          280
#define PLS_KEY_SCROLL_LOCK        281
#define PLS_KEY_NUM_LOCK           282
#define PLS_KEY_PRINT_SCREEN       283
#define PLS_KEY_PAUSE              284
#define PLS_KEY_F1                 290
#define PLS_KEY_F2                 291
#define PLS_KEY_F3                 292
#define PLS_KEY_F4                 293
#define PLS_KEY_F5                 294
#define PLS_KEY_F6                 295
#define PLS_KEY_F7                 296
#define PLS_KEY_F8                 297
#define PLS_KEY_F9                 298
#define PLS_KEY_F10                299
#define PLS_KEY_F11                300
#define PLS_KEY_F12                301
#define PLS_KEY_F13                302
#define PLS_KEY_F14                303
#define PLS_KEY_F15                304
#define PLS_KEY_F16                305
#define PLS_KEY_F17                306
#define PLS_KEY_F18                307
#define PLS_KEY_F19                308
#define PLS_KEY_F20                309
#define PLS_KEY_F21                310
#define PLS_KEY_F22                311
#define PLS_KEY_F23                312
#define PLS_KEY_F24                313
#define PLS_KEY_F25                314
#define PLS_KEY_KP_0               320
#define PLS_KEY_KP_1               321
#define PLS_KEY_KP_2               322
#define PLS_KEY_KP_3               323
#define PLS_KEY_KP_4               324
#define PLS_KEY_KP_5               325
#define PLS_KEY_KP_6               326
#define PLS_KEY_KP_7               327
#define PLS_KEY_KP_8               328
#define PLS_KEY_KP_9               329
#define PLS_KEY_KP_DECIMAL         330
#define PLS_KEY_KP_DIVIDE          331
#define PLS_KEY_KP_MULTIPLY        332
#define PLS_KEY_KP_SUBTRACT        333
#define PLS_KEY_KP_ADD             334
#define PLS_KEY_KP_ENTER           335
#define PLS_KEY_KP_EQUAL           336
#define PLS_KEY_LEFT_SHIFT         340
#define PLS_KEY_LEFT_CONTROL       341
#define PLS_KEY_LEFT_ALT           342
#define PLS_KEY_LEFT_SUPER         343
#define PLS_KEY_RIGHT_SHIFT        344
#define PLS_KEY_RIGHT_CONTROL      345
#define PLS_KEY_RIGHT_ALT          346
#define PLS_KEY_RIGHT_SUPER        347
#define PLS_KEY_MENU               348

#define PLS_KEY_LAST               PLS_KEY_MENU
