#include QMK_KEYBOARD_H
#include "layout.h"
#include "version.h"
#include "i18n.h"
#include "features/achordion.h"
#include "features/custom_shift_keys.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  M_UPDIR,
  M_LAPSW,
  M_DESKSW,
  UKC_CAPS_WORD,
};

enum tap_dance_codes {
  D_PSCR,
};

enum layers {
  BASE,
  GAME,
  SYM,
  NUM,
  NAV,
  FUN,
};

#define HOME_GRAVE LT(FUN,KC_GRAVE)
#define HOME_ESC LT(NAV,KC_ESCAPE)
#define THUMB_ENTER LT(NAV,KC_ENTER)
#define THUMB_TAB LT(NUM,KC_TAB)
#define HOME_A LT(SYM, KC_A)
#define HOME_O MT(MOD_LALT, KC_O)
#define HOME_E MT(MOD_LCTL, KC_E)
#define HOME_U MT(MOD_LSFT, KC_U)
#define WIN_COLN MT(MOD_LGUI, KC_F24)  //F24 gets rewritten as colon
#define HOME_H MT(MOD_RSFT, KC_H)
#define HOME_T MT(MOD_RCTL, KC_T)
#define HOME_N MT(MOD_RALT, KC_N)
#define HOME_S LT(SYM, KC_S)
#define WIN_Z MT(MOD_RGUI, KC_Z)

const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOT , KC_QUES}, // Shift . is ?
  {KC_COMM, KC_EXLM}, // Shift , is !
  {KC_SLASH, KC_BSLS },
  {WIN_COLN, KC_SCLN}, // Shift : is ;
  // These sometimes shift when they shouldn't. Stop that.
  {KC_EQUAL, KC_EQUAL},
  //{KC_MINUS, KC_MINUS},
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_LR(
    HOME_GRAVE,KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  KC_5,
    KC_EQUAL,  KC_QUOTE,  KC_COMMA,  KC_DOT,    KC_P,      KC_Y,
    HOME_ESC,  HOME_A,    HOME_O,    HOME_E,    HOME_U,    KC_I,
    QK_LEAD,   WIN_COLN,  KC_Q,      KC_J,      KC_K,      KC_X,
                                                THUMB_ENTER,  THUMB_TAB,

               KC_6,      KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  TD(D_PSCR),
               KC_F,      KC_G,      KC_C,      KC_R,      KC_L,      KC_SLASH,
               KC_D,      HOME_H,    HOME_T,    HOME_N,    HOME_S,    KC_MINUS,
               KC_B,      KC_M,      KC_W,      KC_V,      WIN_Z,     KC_UNDS,
    KC_BSPC,   KC_SPACE
  ),
  // gaming
  [GAME] = LAYOUT_LR(
    _______,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,
    _______,   _______,   _______,   _______,   _______,   _______,
    KC_ESC,    KC_A,      KC_O,      KC_E,      KC_U,      _______,
    KC_W,      KC_LSFT,   CTL_T(KC_Q),ALT_T(KC_J),_______, _______,
                                                           KC_ENTER,  KC_TAB,

               KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      _______,
               _______,   _______,   _______,   _______,   _______,   _______,
               _______,   KC_H,      KC_T,      KC_N,      KC_S,      _______,
               _______,   _______,   _______,   _______,   KC_Z,      KC_RSFT,
    _______,   _______
  ),
  // symbol
  [SYM] = LAYOUT_LR(
    _______,   _______,   _______,   _______,   _______,   _______,
    _______,   KC_DQUO,   KC_LABK,   KC_RABK,   KC_GRAVE,  KC_DOT,
    _______,   KC_EXLM,   KC_PMNS,   KC_PPLS,   KC_EQUAL,  KC_HASH,
    _______,   _______,   KC_SLASH,  KC_PAST,   KC_BSLS,   M_UPDIR,
                                                           _______,   _______,

               _______,   _______,   _______,   _______,   _______,   _______,
               KC_AMPR,   KC_RBRC,   KC_LBRC,   KC_CIRC,   _______,   KC_QUES,
               KC_PIPE,   KC_RPRN,   KC_LPRN,   KC_AT,     KC_PERC,   KC_UNDS,
               KC_TILD,   KC_RCBR,   KC_LCBR,   KC_DLR,    _______,   _______,
    _______,   _______
  ),
  // num
  [NUM] = LAYOUT_LR(
    _______,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,
    _______,   _______,   _______,   _______,   KC_0,      _______,
    QK_LLCK,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,
                                                           _______,   QK_LLCK,

               KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    QK_LLCK,
               _______,   KC_7,      KC_8,      KC_9,      KC_PAST,   KC_KP_SLASH,
               KC_0,      KC_4,      KC_5,      KC_6,      KC_0,      KC_KP_MINUS,
               KC_0,      KC_1,      KC_2,      KC_3,      KC_KP_PLUS,KC_EQUAL,
    _______,   _______
  ),
  // nav
  [NAV] = LAYOUT_LR(
    _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   KC_VOLD,   KC_MPLY,   KC_VOLU,   _______,
    QK_LLCK,   KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   _______,
    _______,   _______,   KC_PC_CUT, KC_COPY,   KC_PASTE,  _______,
                                                           _______,   _______,

               _______,   _______,   _______,   _______,   _______,   QK_LLCK,
               _______,   KC_HOME,   KC_PGDN,   KC_PAGE_UP,KC_END,    _______,
               KC_DELETE, KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  _______,
               _______,   A(KC_LEFT),RCS(KC_TAB),C(KC_TAB),A(KC_RIGHT),_______,
    _______,   _______
  ),
  // fn
  [FUN] = LAYOUT_LR(
    _______,   TO(BASE),  TO(GAME),  _______,   M_LAPSW,   M_DESKSW,
    _______,   _______,   _______,   _______,   KC_PSCR,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,
                                                           _______,   _______,

               _______,   KC_F10,    KC_F11,    KC_F12,    RGB_HUI,   RGB_MODE_FORWARD,
               _______,   KC_F7,     KC_F8,     KC_F9,     RGB_HUD,   RGB_SPI,
               _______,   KC_F4,     KC_F5,     KC_F6,     RGB_VAI,   RGB_SPD,
               _______,   KC_F1,     KC_F2,     KC_F3,     RGB_VAD,   RGB_TOG,
    _______,   _______
  ),
};

const uint16_t PROGMEM combo1[] = { MT(MOD_LSFT, KC_U), MT(MOD_RSFT, KC_H), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo1, CW_TOGG),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_O:
        case HOME_U:
        case HOME_E:
            // Left side mods are shorter so that eager mods for mouse are faster.
            return 180;
        case HOME_H:
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  debug_enable=false;
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [4] = { {0,0,0}, {87,218,204}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,219,201}, {139,219,201}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {216,211,192}, {139,219,201}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {139,219,201}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,116}, {139,219,201}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  if (!process_achordion(keycode, record)) { return false; }
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  switch (keycode) {
    case M_UPDIR:
      if (record->event.pressed) {
        SEND_STRING("../");
      }
      break;
    case M_LAPSW:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_1))) SS_DELAY(100) SS_LALT(SS_LCTL(SS_TAP(X_F1))));
      }
      break;
    case M_DESKSW:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_2))) SS_DELAY(100) SS_LALT(SS_LCTL(SS_TAP(X_F2))));
      }
      break;
    case UKC_CAPS_WORD:
      caps_word_toggle();
      return true;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case WIN_COLN:
      if (record->event.pressed && record->tap.count == 1) {
        SEND_STRING(":");
		return false;
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case THUMB_ENTER:
    case THUMB_TAB:
    case HOME_ESC:
      return 0;  // Bypass Achordion for these keys.
  }
  return 800;
}

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;  // Disable streak detection on layer-tap keys.
  }

  // mod-enter should be allowed in streaks (for alt-enter after web address)
  if (next_keycode == THUMB_ENTER) return 0;

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  // ctrl-v should be allowed in streaks
  if (mod & MOD_MASK_CTRL && next_keycode == KC_V) return 0;
  if ((mod & MOD_MASK_SHIFT) != 0) {
    return 0;  // A shorter streak timeout for Shift mod-tap keys.
  } else {
    return 330;  // A longer timeout otherwise.
  }
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Allow same hand holds with the left column and left thumb cluster
  // whethere they are the hold or tap key
  //left thumb cluster
  if (other_record->event.key.row == 5) { return true; }
  //first column on left half
  if (other_record->event.key.col == 1 && other_record->event.key.row < 4) { return true; }
  if (tap_hold_record->event.key.row == 5) { return true; }
  if (tap_hold_record->event.key.col == 1 && tap_hold_record->event.key.row < 4) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_LCTL:
    case MOD_LALT:
      return true;  // Eagerly apply left mods for use with mouse.

    default:
      return false;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  // If thumb cluster or left column initiate a multi key press, it's definitely a hold
  if (record->event.key.row == 5) { return true; }
  if (record->event.key.col == 1 && record->event.key.row < 4) { return true; }
  return false;
}

tap_dance_action_t tap_dance_actions[] = {
  [D_PSCR] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PSCR),
};

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_E, KC_H)) {
        // Leader, e, h => Home email
        SEND_STRING("chase.sterling@gmail.com");
    } else if (leader_sequence_two_keys(KC_E, KC_W)) {
        // Leader, e, w => Work email
        SEND_STRING("chase.sterling@h5datacenters.com");
    } else if (leader_sequence_two_keys(KC_E, KC_S)) {
        // Leader, e, s => Shared email
        SEND_STRING("chase.and.rachel.sterling@gmail.com");
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
