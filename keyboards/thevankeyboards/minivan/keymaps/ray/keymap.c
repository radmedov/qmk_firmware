#include QMK_KEYBOARD_H

// extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _L1 1
#define _L2 2
#define _L3 3

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LIQUID,
  ARROWFN,
  ARROWSYM,
  HTMLBRC,
  SSHOT,
  VSSHOT,
  ONEPASS,
  VIMEXIT
};

#define LOWER MO(_L1)
#define RAISE MO(_L2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT_arrow_command( /* Qwerty */
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT, KC_UP,   KC_ENT,
    RAISE,KC_LCTL,KC_LALT, KC_LGUI,     MT(MOD_LSFT, KC_SPC), LOWER,        KC_SLSH,   KC_LEFT,KC_DOWN, KC_RGHT
  ),
  [_L1] = LAYOUT_arrow_command( /* LAYER 1 */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,   KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS,
    _______, KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_UNDS,  KC_PLUS,  KC_F12,  KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_VOLU,
    _______, _______, _______, _______, _______, _______, _______,                   KC_MNXT, KC_MPLY, KC_VOLD
  ),
  [_L2] = LAYOUT_arrow_command( /* LAYER 2 */
   VIMEXIT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR,  KC_LPRN,  KC_RPRN, KC_BSPC,
   KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_UNDS,  KC_PLUS,  ARROWSYM, ARROWFN,  KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   HTMLBRC,    _______,  LIQUID,  _______, KC_BSLS,
    _______, ONEPASS,  _______, _______, _______, _______, _______,                        SSHOT, VSSHOT, KC_MUTE
  ),
  [_L3] = LAYOUT_arrow_command( /* LAYER 3 */
    _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
    KC_ESC,  _______, _______, _______, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
    KC_LSFT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, KC_LSFT, KC_B, _______,              KC_SPC,  KC_C,            _______,  _______, _______, _______
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch(keycode) {
        case QWERTY:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QW);
          }
          return false;
        case LIQUID:
          if (record->event.pressed) {
              SEND_STRING("{%  %}");
          } else {
              SEND_STRING(SS_TAP(X_LEFT));
              SEND_STRING(SS_TAP(X_LEFT));
              SEND_STRING(SS_TAP(X_LEFT));
          }
          break;
        case ARROWFN:
          if (record->event.pressed) {
              SEND_STRING("() => {}");
          } else {
              SEND_STRING(SS_TAP(X_LEFT));
          }
          break;
        case ARROWSYM:
          if (record->event.pressed) {
              SEND_STRING("=>");
          }
          break;
        case HTMLBRC:
          if (record->event.pressed) {
              SEND_STRING("<></>");
          } else {
              SEND_STRING(SS_TAP(X_LEFT));
              SEND_STRING(SS_TAP(X_LEFT));
              SEND_STRING(SS_TAP(X_LEFT));
              SEND_STRING(SS_TAP(X_LEFT));
          }
          break;
        case SSHOT:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LGUI));
              SEND_STRING(SS_DOWN(X_LALT));
              SEND_STRING(SS_TAP(X_4));
          } else {
              SEND_STRING(SS_UP(X_LGUI));
              SEND_STRING(SS_UP(X_LALT));
          }
          break;
        case VSSHOT:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LGUI));
              SEND_STRING(SS_DOWN(X_LALT));
              SEND_STRING(SS_TAP(X_5));
          } else {
              SEND_STRING(SS_UP(X_LGUI));
              SEND_STRING(SS_UP(X_LALT));
          }
          break;
        case ONEPASS:
          if (record->event.pressed) {
              SEND_STRING(SS_DOWN(X_LGUI));
              SEND_STRING(SS_TAP(X_BSLASH));
          } else {
              SEND_STRING(SS_UP(X_LGUI));
          }
          break;
        case VIMEXIT:
          if (record->event.pressed) {
              SEND_STRING(SS_TAP(X_ESCAPE));
              SEND_STRING(SS_DOWN(X_LSHIFT));
              SEND_STRING(SS_TAP(X_SCOLON));
              SEND_STRING(SS_UP(X_LSHIFT));
              SEND_STRING(SS_TAP(X_W));
              SEND_STRING(SS_TAP(X_Q));
              SEND_STRING(SS_TAP(X_ENTER));
          }
          break;
        default:
          return true;
      }
    return true;
};
