#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SLO,
};

enum unicode_names {
    sh,
    SH,
    ch,
    CH,
    cch,
    CCH,
    zh,
    ZH,
    EUR
};

const uint32_t PROGMEM unicode_map[] = {
    [sh]  = 0x0161,  // š
    [SH] = 0x0160,  // Š
    [ch] = 0x010D,  // č
    [CH] = 0x010C,  // Č
    [cch] = 0x0107,  // ć
    [CCH] = 0x0106,  // Ć
    [zh] = 0x017E,  // ž
    [ZH] = 0x017D,  // Ž
    [EUR] = 0x20AC  // €
};

// Tap Dance declarations
enum {
    TD_HOME_END,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_HOME_END] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   -  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |E/LCTL|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| SLO  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_MINS,              KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,               KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  MT(MOD_LCTL, KC_ESC), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,              KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,       KC_LBRC,  KC_RBRC,  KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                                         KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,   KC_ENT,   MO(_RAISE), KC_BSPC, OSL(_SLO)
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   -  |   1  |   2  |   3  |   4  |   5  |-------.    ,-------|   6  |   7  |   8  |   9  |   0  |   =  |
 * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
 * |   _  |   !  |   @  |   #  |   $  |   %  |-------|    |-------|   ^  |   &  |   *  |   (  |   )  |   +  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Backsp\  |RAISE |BackSP| SLO  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_MINS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  S(KC_MINS), S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_LCBR, KC_RCBR, S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_EQL),
                                _______, _______, _______, _______, KC_BSPC, _______, _______, _______
),

/* RAISE
 * System command layer with VIM-inspired assignments and alternate locations for some hard-to-reach keys.
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |      |      | END  | Redo |      |                    |      | Undo |      |      |PrntSc|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   _  |      |      | PGDN | PGUP | H/E  |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
 * |      |      |  DEL |      |      | BEG  |-------|    |-------|      |      |      |      |Search|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /  DEL  /       \Enter \  |RAISE |BackSP| SLO  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_GRV,     XXXXXXX, XXXXXXX, C(KC_RIGHT), C(KC_Y), XXXXXXX,                           XXXXXXX, C(KC_Z), XXXXXXX, XXXXXXX, KC_PRINT_SCREEN, XXXXXXX,
  S(KC_MINS), XXXXXXX, XXXXXXX, KC_PGDN,     KC_PGUP, TD(TD_HOME_END),                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  XXXXXXX,    XXXXXXX, KC_DEL,  XXXXXXX,     XXXXXXX, C(KC_LEFT),      KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(KC_F), XXXXXXX,
                                _______,     _______, _______,         KC_DEL,  _______, _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |Unicde|      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |Vol U |Vol D |      |      |      |
 * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | Mute |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| SLO  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX,           XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, UC_MOD,            XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, KC_KB_MUTE,        XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),

/* SLO
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   š  |      |      |      |-------.    ,-------|      |      |      |      |      |   ć  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   ž  |      |   č  |   €  |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| SLO  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SLO] = LAYOUT(
  XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,    XP(sh, SH), XXXXXXX,    XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XP(cch, CCH),
  XXXXXXX, XP(zh, ZH), XXXXXXX,    XP(ch, CH), X(EUR),  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
