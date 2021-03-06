#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define FN 2 // functions
#define QWERTY 3 // QWERTY


#define JA_CLON KC_QUOT  // : and +
#define JA_AT   KC_LBRC  // @ and `
#define JA_HAT  KC_EQL   // ^ and ~
#define JA_ENUN KC_RO    // \ and _ (EN mark and UNder score)
#define JA_ENVL KC_JYEN  // \ and | (EN mark and Vertical Line)
#define JA_LBRC KC_RBRC  // [ and {
#define JA_RBRC KC_BSLS  // ] and }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ^    |   1  |   2  |   3  |   4  |   5  |   |  |           | F11 |   6  |   7  |   8  |   9  |   0  |    -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   _    |   :  |   ,  |   .  |   P  |   Y  | Del  |           | BkSp |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  | Enter  |
 * |--------+------+------+------+------+------| BkSp |           | Enter|------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |~L3 | LAlt | LGui | alflt  | ~L2    |                                       |  ~L1  |  @ |   [  |   ]  | EISUU  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | clpbd| ESC  |       | UP   |  DOWN |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | next|        | RIGHT|       |      |
 *                                 | Space| Tab  |------|       |------|  RGUI  | KANA |
 *                                 |      |      | prev |       | LEFT |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        JA_HAT,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   JA_ENVL,
        JA_ENUN,         JA_CLON,        KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_DELT,
        KC_LCTL,        KC_A,           KC_O,    KC_E,   KC_U,   KC_I,
        KC_LSFT,        CTL_T(KC_SCLN), KC_Q,    KC_J,   KC_K,   KC_X,   KC_BSPC,
        KC_FN3,KC_LALT,      KC_LGUI,  LCTL(KC_SPC),KC_FN2,
                                              LGUI(LSFT(KC_Z)),  KC_ESC,
                                                              LCTL(KC_TAB),
                                               KC_SPC,KC_TAB,LCTL(LSFT(KC_TAB)),
        // right hand
             KC_F11,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             KC_BSPC,       KC_F,   KC_G,   KC_C,   KC_R,   KC_L,             KC_SLSH,
                          KC_D,   KC_H,   KC_T,   KC_N,   KC_S,             KC_ENT,
             KC_ENT ,KC_B,   KC_M,   KC_W,   KC_V,   CTL_T(KC_Z),      KC_RSFT,
                                  KC_FN1,  JA_AT,JA_LBRC,JA_RBRC,          KC_LANG2,
             KC_UP,        KC_DOWN,
             KC_RIGHT,
             KC_LEFT,KC_RGUI, KC_LANG1
    ),
/* Keymap 1: Symbol & Media Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |    -   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Prev | Next |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PgUp |       |VolUp |      |      |
 *                                 |      |      |------|       |------| Mute |      |
 *                                 |      |      | PgDn |       |VolDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,JA_AT,JA_LBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_MPRV,KC_MNXT,
                                       KC_TRNS,KC_TRNS,
                                               KC_PGUP,
                               KC_TRNS,KC_TRNS,KC_PGDN,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    JA_RBRC, KC_MINS,
                         KC_TRNS,KC_DOT,  KC_0,    JA_HAT,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_VOLU,
       KC_VOLD, KC_MUTE, KC_TRNS
),
/* Keymap 2: Functions
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | MsUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | cmd+a| cmd+s|      |      |      |------|           |------|      |MsLeft|MsDown|MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | cmd+z| cmd+x| cmd+c| cmd+v|      |      |           |      |      | LEFT |  UP  | RIGHT|      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      | DOWN |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PgUp |       |      |      |      |
 *                                 |      |      |------|       |------| Rclk | Lclk |
 *                                 |      |      | PgDn |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// FUNCTIONS
[FN] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,LGUI(KC_A),LGUI(KC_S), KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,LGUI(KC_Z),LGUI(KC_X),LGUI(KC_C),LGUI(KC_V),KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_PGUP,
                               KC_TRNS,KC_TRNS,KC_PGDN,
       // right hand
       KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_TRNS,   KC_MS_U,    KC_TRNS,    KC_TRNS, KC_TRNS,
                KC_TRNS, KC_MS_L,   KC_MS_D,    KC_MS_R,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LEFT,   KC_UP,    KC_RIGHT,    KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_DOWN,  KC_TRNS,    KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BTN2, KC_BTN1
),
/* Keymap 3: QWERTY Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// QWERTY
[QWERTY] = KEYMAP(  // layer 2 : QWERTY
        // left hand
        KC_TRNS,        KC_TRNS,      KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,        KC_Q,         KC_W,      KC_E,   KC_R,   KC_T,   KC_TRNS,
        KC_TRNS,        KC_A,         KC_S,      KC_D,   KC_F,   KC_G,
        KC_TRNS,        CTL_T(KC_Z),  KC_X,      KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_TRNS,        KC_TRNS,      KC_TRNS,   KC_TRNS,KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,          KC_TRNS,
        KC_TRNS,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_TRNS,
                     KC_H,   KC_J,   KC_K,   KC_L,   LT(QWERTY, KC_SCLN),KC_TRNS,
        KC_TRNS,     KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_TRNS,
                             KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),            // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(FN),              // FN2 - Momentary Layer 2 (FUNCTIONS)
    [3] = ACTION_LAYER_TAP_TOGGLE(QWERTY)                // FN3 - Momentary Layer 2 (QWERTY)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
