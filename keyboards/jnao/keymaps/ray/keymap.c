#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  LIQUID,
  ARROWFN,
  ARROWSYM,
  HTMLBRC,
  SSHOT,
  VSSHOT,
  ONEPASS,
  VIMEXIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BL/Shift|Ctrl| Alt  | CMD  |Lower |Sp/Sh |Sp/Sh|Raise|   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    MO(_FUNCTION), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_ENT ,
    BACKLIT, KC_LCTL,KC_LALT,KC_LGUI,LOWER,MT(MOD_LSFT, KC_SPC),MT(MOD_LSFT, KC_SPC),RAISE,KC_SLSH,KC_LEFT,KC_DOWN,KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |VIMEXIT| F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  _  |  +  |ARROWSYM|ARROWFN|  |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7 |  F8  |  F9  |  F10 |  F11 |  F12 |HTMLBRC|      |LIQUID|      |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ONEPASS|     |      |      | LWR  |             |      |      | SSHOT|VSSHOT| Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR,  KC_LPRN,  KC_RPRN, KC_BSPC,
  VIMEXIT,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,  KC_PLUS,  ARROWSYM, ARROWFN, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  HTMLBRC,    _______,  LIQUID,  _______, KC_BSLS,
  ONEPASS, _______, _______, _______, _______, _______, _______, _______,     _______,  SSHOT, VSSHOT, KC_MUTE
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Back |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   {  |   }  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   <  |   >  |   [  |   ]  | Vol+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |  RSE |      | Next | Play | Vol- |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, KC_VOLU,
    _______, _______, _______, _______, _______, _______, _______, _______,   _______, KC_MNXT, KC_MPLY, KC_VOLD
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Qwerty|      |      |      | LWR  |             | RSE  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    QWERTY, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
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
  }
  return true;
}
