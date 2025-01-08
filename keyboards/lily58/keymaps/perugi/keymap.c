#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _SLO,
};

enum unicode_names { sh, SH, ch, CH, cch, CCH, zh, ZH, EUR };

const uint32_t PROGMEM unicode_map[] = {
    [sh]  = 0x161, // š
    [SH]  = 0x160, // Š
    [ch]  = 0x10D, // č
    [CH]  = 0x10C, // Č
    [cch] = 0x107, // ć
    [CCH] = 0x106, // Ć
    [zh]  = 0x17E, // ž
    [ZH]  = 0x17D, // Ž
    [EUR] = 0x20AC  // €
};

// Tap Dance declarations
enum {
    TD_END_HOME,
    TD_COMMA_LOWER,
    TD_PERIOD_LOWER,
    TD_COLON_LOWER,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for End, twice for Home
    [TD_END_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_HOME),

    // Tap once for *, twice for ,
    [TD_COMMA_LOWER] = ACTION_TAP_DANCE_DOUBLE(S(KC_8), KC_COMM),

    // Tap once for (, twice for .
    [TD_PERIOD_LOWER] = ACTION_TAP_DANCE_DOUBLE(S(KC_9), KC_DOT),
};

        // How long (in milliseconds) to wait between animation steps for each of the "Swirling rainbow" animations
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |E/LCTL|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  -   |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| SLO  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_QWERTY] = LAYOUT(
        KC_GRV,               KC_1,    KC_2,       KC_3,    KC_4,    KC_5,                         KC_6,       KC_7,    KC_8,    KC_9,   KC_0,    KC_EQL,
        KC_TAB,               KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,                         KC_Y,       KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
        MT(MOD_LCTL, KC_ESC), KC_A,    KC_S,       KC_D,    KC_F,    KC_G,                         KC_H,       KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT,              KC_Z,    KC_X,       KC_C,    KC_V,    KC_B,       KC_LBRC, KC_RBRC, KC_N,       KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
                                                   KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,  KC_ENT,  MO(_RAISE), KC_BSPC, OSL(_SLO)
        ),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |E/LCTL|   1  |   2  |   3  |   4  |   5  |-------.    ,-------|   6  |   7  |   8  |   9  |   0  |   =  |
     * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
     * |LShift|   !  |   @  |   #  |   $  |   %  |-------|    |-------|   ^  |   &  | * / ,| ( / .|   )  |   +  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LGUI | LAlt |LOWER | /  DEL  /       \Enter \  |RAISE |BackSP| SLO  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_LOWER] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_LCBR, KC_RCBR, S(KC_6), S(KC_7), TD(TD_COMMA_LOWER), TD(TD_PERIOD_LOWER), S(KC_0), S(KC_EQL),
                                   _______, _______, _______, KC_DEL,  _______, _______, _______, _______
        ),

    /* RAISE
     * System command layer with VIM-inspired assignments and alternate locations for some hard-to-reach keys.
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      | END  | Redo |      |                    |      | Undo |      |      |PrntSc|      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |E/LCTL|   !  |   ~  | PGDN | PGUP | E/H  |-------.    ,-------| Left | Down |  Up  |Right |      |      |
     * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
     * |LShift|      |  DEL |      |      | BEG  |-------|    |-------|      |      |      |      |Search|      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| SLO  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_RAISE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,     XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,   C(KC_RIGHT), C(KC_Y), XXXXXXX,                           XXXXXXX, C(KC_Z), XXXXXXX, XXXXXXX, KC_PRINT_SCREEN, XXXXXXX,
        _______, S(KC_1), S(KC_GRV), KC_PGDN,     KC_PGUP, TD(TD_END_HOME),                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,         XXXXXXX,
        _______, XXXXXXX, KC_DEL,    XXXXXXX,     XXXXXXX, C(KC_LEFT),      KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(KC_F),         XXXXXXX,
                                     _______,     _______, _______,         _______, _______, _______, _______, _______
        ),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | POff |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |Unicde|      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------| Prev |Vol D |Vol U | Next |      |      |
     * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------| Play | Mute |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| SLO  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_ADJUST] = LAYOUT(
        KC_PWR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, UG_TOGG,                   XXXXXXX, UC_NEXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, UG_HUED, UG_SATD, UG_VALD, UG_SPDD, XXXXXXX,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_PREV, UG_NEXT, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, _______, _______
        ),

    /* SLO
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |E/LCTL|      |   š  |      |      |      |-------.    ,-------|      |      |      |      |      |   ć  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   ž  |      |   č  |   €  |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| SLO  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_SLO] = LAYOUT(
        XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX,    UP(0, 1), XXXXXXX,    XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UP(cch, CCH),
        _______, UP(zh, ZH), XXXXXXX,    UP(ch, CH), UM(EUR),  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                         _______,    _______, _______, _______, _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
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
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
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
