#include QMK_KEYBOARD_H

enum layers {
    DVORAK,
    QWERTY,
    PROCREATE,
    NUMPAD,
    NUM_SYM,
    UTILITIES
};

enum combo_events {
    DVORAK_CUT,
    DVORAK_COPY,
    DVORAK_PASTE,
    QWERTY_CUT,
    QWERTY_COPY,
    QWERTY_PASTE,

    DVORAK_TAB,
    DVORAK_CTRL_BSPC,
    QWERTY_TAB,
    QWERTY_CTRL_BSPC,

    DVORAK_CTRL_Z,
    QWERTY_CTRL_Z,
    DVORAK_CTRL_Y,
    QWERTY_CTRL_Y,
};

// Define combos for cut, copy, and paste
const uint16_t PROGMEM dvorak_cut_combo[] = {KC_SCLN, KC_Q, COMBO_END};
const uint16_t PROGMEM dvorak_copy_combo[] = {KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM dvorak_paste_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM qwerty_cut_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM qwerty_copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM qwerty_paste_combo[] = {KC_C, KC_V, COMBO_END};

// Define combos for tab and ctrl+backspace
const uint16_t PROGMEM dvorak_tab_combo[] = {KC_ESC, KC_QUOT, COMBO_END};
const uint16_t PROGMEM dvorak_ctrl_bspc_combo[] = {KC_P, KC_BSPC, COMBO_END};
const uint16_t PROGMEM qwerty_tab_combo[] = {KC_ESC, KC_Q, COMBO_END};
const uint16_t PROGMEM qwerty_ctrl_bspc_combo[] = {KC_L, KC_BSPC, COMBO_END};

// Define the combos for undo and redo
const uint16_t PROGMEM dvorak_ctrl_z_combo[] = {KC_QUOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM qwerty_ctrl_z_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM dvorak_ctrl_y_combo[] = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM qwerty_ctrl_y_combo[] = {KC_E, KC_R, COMBO_END};

combo_t key_combos[VIAL_COMBO_ENTRIES] = {
    [DVORAK_CUT] = COMBO_ACTION(dvorak_cut_combo),
    [DVORAK_COPY] = COMBO_ACTION(dvorak_copy_combo),
    [DVORAK_PASTE] = COMBO_ACTION(dvorak_paste_combo),
    [QWERTY_CUT] = COMBO_ACTION(qwerty_cut_combo),
    [QWERTY_COPY] = COMBO_ACTION(qwerty_copy_combo),
    [QWERTY_PASTE] = COMBO_ACTION(qwerty_paste_combo),
    [DVORAK_TAB] = COMBO_ACTION(dvorak_tab_combo),
    [DVORAK_CTRL_BSPC] = COMBO_ACTION(dvorak_ctrl_bspc_combo),
    [QWERTY_TAB] = COMBO_ACTION(qwerty_tab_combo),
    [QWERTY_CTRL_BSPC] = COMBO_ACTION(qwerty_ctrl_bspc_combo),
    [DVORAK_CTRL_Z] = COMBO_ACTION(dvorak_ctrl_z_combo),
    [QWERTY_CTRL_Z] = COMBO_ACTION(qwerty_ctrl_z_combo),
    [DVORAK_CTRL_Y] = COMBO_ACTION(dvorak_ctrl_y_combo),
    [QWERTY_CTRL_Y] = COMBO_ACTION(qwerty_ctrl_y_combo),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Layer 0: Dvorak base layer
[0] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        KC_ESC,  KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,   TO(0),      TO(1),    KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_A,    KC_E,    KC_I,    KC_O,    KC_U,   TO(2),      TO(3),    KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RCTL,
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                            KC_LALT,  KC_ENT,   MO(4),      MO(5),  KC_SPC,  KC_RGUI
                                        //`--------------------------'  `--------------------------'
),

// Layer 1: QWERTY base layer
[1] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   TO(0),      TO(1),    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   TO(2),      TO(3),    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                            KC_LALT,  KC_ENT,   MO(4),      MO(5),  KC_SPC,  KC_RGUI
                                        //`--------------------------'  `--------------------------'
),

// Layer 2: Procreate shortcut layer
[2] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        KC_LGUI, XXXXXXX, KC_LBRC,    KC_V, KC_RBRC, XXXXXXX,   TO(0),      TO(1), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT, LGUI(KC_Z), KC_E, KC_S, KC_B, LGUI(LSFT(KC_Z)), TO(2),     TO(3), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, KC_L, LGUI(KC_U),    KC_C, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX,  KC_SPC, KC_LALT,    XXXXXXX, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
),

// Layer 3: Numpad layer
[3] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
         KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   TO(0),  TO(1), KC_KP_SLASH, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(2), TO(3), KC_KP_ASTERISK, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_KP_DOT,
    //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_EQUAL, KC_ENT,
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, KC_ENT, XXXXXXX,    XXXXXXX, KC_SPC, KC_RALT
                                        //`--------------------------'  `--------------------------'
),

// Layer 4: Symbol layer
[4] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,    XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,    XXXXXXX,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_BSLS, KC_SLSH, KC_MINS, KC_EQL,  KC_QUOT, _______,
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                            _______, KC_GRV,  _______,    _______, KC_F11,  KC_F12
                                        //`--------------------------'  `--------------------------'
),

// Layer 5: Utility layer
[5] = LAYOUT_split_3x6_3_ex2(
    //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
   LALT(KC_TAB), KC_MUTE, KC_VOLD,   KC_UP, KC_VOLU, XXXXXXX, XXXXXXX,    XXXXXXX,  KC_INS, LCTL(LSFT(KC_TAB)), KC_PGUP, LCTL(KC_TAB), KC_PSCR, KC_DEL,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, KC_MPRV, KC_LEFT, KC_DOWN, KC_RGHT, KC_MNXT, XXXXXXX,    XXXXXXX, KC_WBAK, KC_HOME, KC_PGDN,  KC_END, KC_WFWD, _______,
    //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
_______, XXXXXXX, LSFT(KC_LBRC), KC_LBRC, LSFT(KC_9), XXXXXXX,                     XXXXXXX, LSFT(KC_0), KC_RBRC, LSFT(KC_RBRC), XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                            _______, KC_MPLY, _______,    _______, KC_MPLY, _______
                                        //`--------------------------'  `--------------------------'
)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case DVORAK_CUT:
            if (pressed) {
                if (layer_state_is(DVORAK)) {
                    tap_code16(LCTL(KC_X));
                }
            }
            break;
        case DVORAK_COPY:
            if (pressed) {
                if (layer_state_is(DVORAK)) {
                    tap_code16(LCTL(KC_C));
                }
            }
            break;
        case DVORAK_PASTE:
            if (pressed) {
                if (layer_state_is(DVORAK)) {
                    tap_code16(LCTL(KC_V));
                }
            }
            break;
        case QWERTY_CUT:
            if (pressed) {
                if (layer_state_is(QWERTY)) {
                    tap_code16(LCTL(KC_X));
                }
            }
            break;
        case QWERTY_COPY:
            if (pressed) {
                if (layer_state_is(QWERTY)) {
                    tap_code16(LCTL(KC_C));
                }
            }
            break;
        case QWERTY_PASTE:
            if (pressed) {
                if (layer_state_is(QWERTY)) {
                    tap_code16(LCTL(KC_V));
                }
            }
            break;

        case DVORAK_TAB:
            if (pressed) {
                if (layer_state_is(DVORAK)) {
                    tap_code16(KC_TAB);
                }
            }
            break;
        case DVORAK_CTRL_BSPC:
            if (pressed) {
                if (layer_state_is(DVORAK)) {
                    tap_code16(LCTL(KC_BSPC));
                }
            }
            break;
        case QWERTY_TAB:
            if (pressed) {
                if (layer_state_is(QWERTY)) {
                    tap_code16(KC_TAB);
                }
            }
            break;
        case QWERTY_CTRL_BSPC:
            if (pressed) {
                if (layer_state_is(QWERTY)) {
                    tap_code16(LCTL(KC_BSPC));
                }
            }
            break;

        case DVORAK_CTRL_Z:
            if (pressed) {
                if (layer_state_is(DVORAK)) {
                    tap_code16(LCTL(KC_Z));
                }
            }
            break;
        case QWERTY_CTRL_Z:
            if (pressed) {
                if (layer_state_is(QWERTY)) {
                    tap_code16(LCTL(KC_Z));
                }
            }
            break;
        case DVORAK_CTRL_Y:
            if (pressed) {
                if (layer_state_is(DVORAK)) {
                    tap_code16(LCTL(KC_Y));
                }
            }
            break;
    }
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [1] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [2] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [3] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [4] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [5] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
};
#endif
