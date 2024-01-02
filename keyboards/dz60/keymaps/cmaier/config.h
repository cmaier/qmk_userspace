#ifndef CONFIG_KEYMAP_H
#define CONFIG_KEYMAP_H

//#include "../../config.h"
// #include "../../dz60-ansi-kc.h"

// Fix KC_GESC conflict with Cmd+Alt+Esc on macos
#define GRAVE_ESC_GUI_OVERRIDE

// Turn off RGB when computer goes to sleep
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP
#endif

// Disable all animations
#ifdef RGBLIGHT_ANIMATIONS
  #undef RGBLIGHT_ANIMATIONS
#endif

#define RGBLIGH_EFFECT_STATIC_GRADIENT

#endif
