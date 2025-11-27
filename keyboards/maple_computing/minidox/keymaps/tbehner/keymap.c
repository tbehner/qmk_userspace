#include QMK_KEYBOARD_H

#include "common/sway_layer_defs.h"
#include "common/common_keys.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _SYMB,
    _NUMB,
    _NAV,
    _SWAY
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  SYMB,
  NUMB,
  NAV,
  SWAY,
  CW_LEFT,
  CW_RIGHT,
  CW_UP,
  CW_DOWN,
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

/// new home row modifiers
///
#define TB_Q KC_Q, WMT
#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

#include "common/combos.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | Ctrl | LOWER|      |    |      | RAISE| Shift|
 *                  `-------------| Space|    |BckSpc|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */

[_BASE] = LAYOUT_wrapper(
        BASE_LEFT_UPPER,                        BASE_RIGHT_UPPER,
        BASE_LEFT_MID  ,                        BASE_RIGHT_MID  ,
        BASE_LEFT_LOWER,                        BASE_RIGHT_LOWER,
        QK_LEAD, GTSYM ,  NTAB,         SSSFT,    SSYM,    QK_LEAD
),

[_SYMB] = LAYOUT_wrapper(
  // left hand
        SYMBOL_LEFT_UPPER,                                        SYMBOL_RIGHT_UPPER,
        SYMBOL_LEFT_MID,                                          SYMBOL_RIGHT_MID,
        SYMBOL_LEFT_LOWER,                                        SYMBOL_RIGHT_LOWER,
        STNUM  , STNAV  , GTDEF  ,                    KC_BSPC, GTNAV,   KC_TRNS
),

[_NAV] = LAYOUT_wrapper(
  // left hand
                      NAVIGATION_LEFT_UPPER,                     NAVIGATION_RIGHT_UPPER,
                      NAVIGATION_LEFT_MID,                       NAVIGATION_RIGHT_MID,
                      NAVIGATION_LEFT_LOWER,                     NAVIGATION_RIGHT_LOWER,
                    KC_TRNS, GTNUM  , GTDEF  ,                    KC_DEL , KC_ENT, KC_TRNS
),

[_NUMB] = LAYOUT_wrapper(
  // left hand
                NUMBER_LEFT_UPPER,                            NUMBER_RIGHT_UPPER,
                NUMBER_LEFT_MID  ,                            NUMBER_RIGHT_MID  ,
                NUMBER_LEFT_LOWER,                            NUMBER_RIGHT_LOWER,
                   KC_TRNS,  GTSYM,   GTDEF  ,           KC_TRNS, GTDEF,   KC_TRNS
),

/*
 *   ,----------------------------------.           ,----------------------------------.
 *   | WS1  | WS2  | WS3  | WS4  | WS5  |           | WS6  | WS6  | WS7  | WS8  | WS9  |
 *   |------+------+------+------+------|           |------+------+------+------+------|
 *   | MvWR | MvWD | MvWU | MvWL |      |           | FoWL | FoWU | FoWD | FoWR |      |
 *   |------+------+------+------+------|           |------+------+------+------+------|
 *   |Horizo|Vertic|Tabbed|Stack |TglVH |           |FParen| Full |      |      |      |
 *   `----------------------------------'           `----------------------------------'
 *
 *
 * */

[_SWAY] = LAYOUT_split_3x5_3(
  // left hand
  MWS1 ,  MWS2,     MWS3,    MWS4,    MWS5,            MWS6,   MWS7,  MWS8,  MWS9,    MWS10,
  MWLEFT, MWDOWN,   MWUP,    MWRIGHT, KC_NO,           FLEFT,  FDOWN, FUP,   FRIGHT,  KC_NO,
  SSHOR,  SSVER,   SSTAB,    SSSTA,   SSTSP,           SPARE,  SSFUL, KC_NO, KC_NO,   KC_NO,
                   KC_TRNS,  GTDEF,   GTDEF,           SSSFT,  MSLEFT, MSRIGHT

),
};

/* void persistant_default_layer_set(uint16_t default_layer) { */
/*   eeconfig_update_default_layer(default_layer); */
/*   default_layer_set(default_layer); */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(record->event.pressed){
    switch (keycode) {
    case CW_LEFT:
      SEND_STRING(SS_DOWN(X_LCTL) "w" SS_UP(X_LCTL) "h");
      return false;
    case CW_RIGHT:
      SEND_STRING(SS_DOWN(X_LCTL) "w" SS_UP(X_LCTL) "l");
      return false;
    case CW_DOWN:
      SEND_STRING(SS_DOWN(X_LCTL) "w" SS_UP(X_LCTL) "j");
      return false;
    case CW_UP:
      SEND_STRING(SS_DOWN(X_LCTL) "w" SS_UP(X_LCTL) "k");
      return false;
    }
  }
  return true;
}

#include "leader_functions/functions.c"
--- Startup times for process: Primary (or UI client) ---

times in msec
 clock   self+sourced   self:  sourced script
 clock   elapsed:              other lines

000.003  000.003: --- NVIM STARTING ---
000.202  000.198: event init
000.335  000.133: early init
000.440  000.106: locale set
000.519  000.078: init first window
001.222  000.704: inits 1
001.245  000.022: window checked
001.250  000.005: parsing arguments
002.012  000.064  000.064: require('vim.shared')
002.156  000.060  000.060: require('vim.inspect')
002.232  000.062  000.062: require('vim._options')
002.235  000.219  000.097: require('vim._editor')
002.237  000.316  000.034: require('vim._init_packages')
002.240  000.674: init lua interpreter
003.946  001.706: nvim_ui_attach
004.375  000.429: nvim_set_client_info
004.379  000.003: --- NVIM STARTED ---

--- Startup times for process: Embedded ---

times in msec
 clock   self+sourced   self:  sourced script
 clock   elapsed:              other lines

000.003  000.003: --- NVIM STARTING ---
000.155  000.152: event init
000.261  000.106: early init
000.355  000.094: locale set
000.415  000.060: init first window
000.956  000.541: inits 1
000.975  000.018: window checked
000.978  000.003: parsing arguments
001.734  000.065  000.065: require('vim.shared')
001.885  000.060  000.060: require('vim.inspect')
001.964  000.064  000.064: require('vim._options')
001.968  000.229  000.105: require('vim._editor')
001.970  000.331  000.038: require('vim._init_packages')
001.973  000.663: init lua interpreter
002.049  000.076: expanding arguments
002.074  000.026: inits 2
002.513  000.439: init highlight
002.515  000.001: waiting for UI
002.762  000.248: done waiting for UI
002.791  000.029: clear screen
003.000  000.016  000.016: require('vim.keymap')
004.197  000.194  000.194: sourcing nvim_exec2()
004.394  001.599  001.389: require('vim._defaults')
004.396  000.006: init default mappings & autocommands
004.494  000.098: --cmd commands
005.663  000.058  000.058: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/ftplugin.vim
005.734  000.032  000.032: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/indent.vim
007.668  001.247  001.247: require('lazy')
007.714  000.016  000.016: require('ffi')
007.780  000.036  000.036: require('vim.fs')
007.925  000.141  000.141: require('vim.uri')
007.945  000.226  000.050: require('vim.loader')
008.089  000.124  000.124: require('lazy.stats')
008.248  000.135  000.135: require('lazy.core.util')
008.376  000.126  000.126: require('lazy.core.config')
008.549  000.068  000.068: require('lazy.core.handler')
008.920  000.100  000.100: require('lazy.pkg')
008.927  000.279  000.179: require('lazy.core.meta')
008.938  000.387  000.109: require('lazy.core.plugin')
008.952  000.574  000.119: require('lazy.core.loader')
009.251  000.091  000.091: require('lazy.core.fragments')
012.429  000.052  000.052: require('lazy.core.handler.event')
012.475  000.041  000.041: require('lazy.core.handler.cmd')
012.518  000.039  000.039: require('lazy.core.handler.keys')
012.543  000.024  000.024: require('lazy.core.handler.ft')
013.358  000.006  000.006: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
013.371  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
013.482  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
013.544  000.009  000.009: sourcing /home/tbehner/.local/share/nvim/lazy/d2-vim/ftdetect/d2.vim
013.547  000.027  000.019: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
013.550  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
013.569  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
013.577  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
013.784  000.085  000.085: sourcing nvim_exec2() called at /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/filetype.lua:0
013.786  000.143  000.057: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/filetype.lua
013.788  000.158  000.015: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
014.095  000.053  000.053: sourcing /home/tbehner/.local/share/nvim/lazy/solarized.nvim/plugin/solarized.lua
014.097  000.067  000.014: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
014.101  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
014.108  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
014.519  000.050  000.050: require('solarized.config')
014.522  000.369  000.319: require('solarized')
014.554  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
014.559  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
014.633  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
014.638  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
015.172  000.509  000.509: require('gruvbox')
015.629  000.065  000.065: sourcing /home/tbehner/.local/share/nvim/lazy/nvim-dap/plugin/dap.lua
015.632  000.081  000.015: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
015.637  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
015.641  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
015.976  000.082  000.082: require('dap.utils')
016.023  000.379  000.297: require('dap')
016.066  000.004  000.004: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
016.071  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
016.470  000.397  000.397: require('mini.align')
016.635  000.113  000.113: require('mini.operators')
017.253  000.030  000.030: require('nvim-treesitter.utils')
017.710  000.044  000.044: require('vim.treesitter.language')
017.742  000.029  000.029: require('vim.func')
017.787  000.041  000.041: require('vim.func._memoize')
017.809  000.222  000.109: require('vim.treesitter.query')
017.850  000.040  000.040: require('vim.treesitter._range')
017.864  000.368  000.106: require('vim.treesitter.languagetree')
017.870  000.423  000.055: require('vim.treesitter')
018.309  001.054  000.631: require('nvim-treesitter.parsers')
018.563  000.038  000.038: require('nvim-treesitter.compat')
018.675  000.063  000.063: require('nvim-treesitter.ts_utils')
018.679  000.115  000.052: require('nvim-treesitter.tsrange')
018.710  000.030  000.030: require('nvim-treesitter.caching')
018.719  000.258  000.075: require('nvim-treesitter.query')
018.735  000.357  000.099: require('nvim-treesitter.configs')
018.738  000.427  000.070: require('nvim-treesitter.info')
018.815  000.076  000.076: require('nvim-treesitter.shell_command_selectors')
018.838  001.668  000.081: require('nvim-treesitter.install')
018.868  000.028  000.028: require('nvim-treesitter.statusline')
018.908  000.039  000.039: require('nvim-treesitter.query_predicates')
018.909  001.884  000.149: require('nvim-treesitter')
019.139  000.225  000.225: require('vim.iter')
019.655  002.655  000.546: sourcing /home/tbehner/.local/share/nvim/lazy/nvim-treesitter/plugin/nvim-treesitter.lua
019.659  002.673  000.018: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
019.668  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
019.677  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
019.982  000.170  000.170: require('gitsigns')
020.153  000.148  000.148: require('gitsigns.highlight')
020.200  000.038  000.038: require('gitsigns.debug.log')
020.259  000.057  000.057: require('gitsigns.config')
020.632  000.031  000.031: require('gitsigns.debounce')
020.640  000.862  000.419: sourcing /home/tbehner/.local/share/nvim/lazy/gitsigns.nvim/plugin/gitsigns.lua
020.643  000.884  000.022: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
020.650  000.003  000.003: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
020.657  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
021.027  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
021.032  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
021.157  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
021.162  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
021.361  000.052  000.052: require('vim.lsp.log')
021.664  000.300  000.300: require('vim.lsp.protocol')
021.794  000.128  000.128: require('vim.lsp.util')
021.858  000.026  000.026: require('vim.lsp.sync')
021.883  000.086  000.060: require('vim.lsp._changetracking')
021.955  000.031  000.031: require('vim.lsp._transport')
021.971  000.086  000.054: require('vim.lsp.rpc')
022.037  000.814  000.163: require('vim.lsp')
022.509  000.470  000.470: require('blink.cmp')
022.587  000.031  000.031: require('blink.cmp.lib.async')
022.637  000.019  000.019: require('blink.cmp.config.utils')
022.659  000.020  000.020: require('blink.cmp.config.keymap')
022.702  000.019  000.019: require('blink.cmp.config.completion.keyword')
022.724  000.021  000.021: require('blink.cmp.config.completion.trigger')
022.751  000.026  000.026: require('blink.cmp.config.completion.list')
022.786  000.035  000.035: require('blink.cmp.config.completion.accept')
022.834  000.046  000.046: require('blink.cmp.config.completion.menu')
022.872  000.037  000.037: require('blink.cmp.config.completion.documentation')
022.896  000.024  000.024: require('blink.cmp.config.completion.ghost_text')
022.897  000.238  000.031: require('blink.cmp.config.completion')
022.936  000.037  000.037: require('blink.cmp.config.fuzzy')
022.986  000.049  000.049: require('blink.cmp.config.sources')
023.016  000.029  000.029: require('blink.cmp.config.signature')
023.049  000.032  000.032: require('blink.cmp.config.snippets')
023.081  000.031  000.031: require('blink.cmp.config.appearance')
023.105  000.023  000.023: require('blink.cmp.config.modes.cmdline')
023.127  000.022  000.022: require('blink.cmp.config.modes.term')
023.129  000.540  000.040: require('blink.cmp.config')
023.165  000.035  000.035: require('blink.cmp.lib.utils')
023.188  000.022  000.022: require('blink.cmp.lib.event_emitter')
023.193  000.681  000.053: require('blink.cmp.sources.lib')
023.219  002.027  000.063: sourcing /home/tbehner/.local/share/nvim/lazy/blink.cmp/plugin/blink-cmp.lua
023.223  002.046  000.019: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
023.231  000.003  000.003: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
023.237  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
023.320  000.023  000.023: require('blink-cmp')
024.165  000.039  000.039: require('blink.cmp.config.modes.types')
024.524  000.050  000.050: require('blink.cmp.fuzzy.download.system')
024.586  000.163  000.113: require('blink.cmp.fuzzy.download.files')
024.589  000.205  000.042: require('blink.cmp.fuzzy.download.git')
024.592  000.268  000.063: require('blink.cmp.fuzzy.download')
024.705  000.088  000.088: require('vim._system')
027.135  000.266  000.266: require('lspconfig.util')
027.178  000.446  000.180: sourcing /home/tbehner/.local/share/nvim/lazy/nvim-lspconfig/plugin/lspconfig.lua
027.182  000.477  000.031: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
027.188  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
027.206  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
027.350  000.054  000.054: require('lspconfig.async')
027.352  000.098  000.044: require('lspconfig.configs')
027.364  000.151  000.053: require('lspconfig')
028.861  001.196  001.196: require('vim.filetype')
029.471  000.062  000.062: require('luasnip.util.types')
029.478  000.162  000.099: require('luasnip.util.ext_opts')
029.786  000.115  000.115: require('luasnip.util.lazy_table')
029.876  000.088  000.088: require('luasnip.extras.filetype_functions')
029.952  000.403  000.200: require('luasnip.default_config')
029.955  000.475  000.072: require('luasnip.session')
029.958  000.990  000.353: require('luasnip.config')
030.207  000.030  000.030: require('vim.version')
030.987  000.830  000.800: require('luasnip.util.vimversion')
030.992  000.892  000.063: require('luasnip.util.util')
031.107  000.020  000.020: require('luasnip.nodes.key_indexer')
031.129  000.021  000.021: require('luasnip.util.feedkeys')
031.131  000.138  000.098: require('luasnip.nodes.util')
031.177  000.019  000.019: require('luasnip.session.snippet_collection.source')
031.194  000.015  000.015: require('luasnip.util.table')
031.211  000.016  000.016: require('luasnip.util.auto_table')
031.215  000.082  000.032: require('luasnip.session.snippet_collection')
031.276  000.019  000.019: require('luasnip.util.select')
031.291  000.015  000.015: require('luasnip.util.time')
031.545  000.311  000.278: require('luasnip.util._builtin_vars')
031.585  000.370  000.059: require('luasnip.util.environ')
031.610  000.024  000.024: require('luasnip.util.extend_decorator')
031.671  000.036  000.036: require('luasnip.util.path')
031.731  000.032  000.032: require('luasnip.util.log')
031.733  000.061  000.030: require('luasnip.loaders.util')
031.753  000.003  000.003: require('vim.F')
031.756  000.021  000.019: require('luasnip.loaders.data')
031.810  000.053  000.053: require('luasnip.loaders.fs_watchers')
031.812  000.201  000.029: require('luasnip.loaders')
031.824  001.862  000.155: require('luasnip')
031.838  004.220  000.171: sourcing /home/tbehner/.local/share/nvim/lazy/LuaSnip/plugin/luasnip.lua
031.841  004.236  000.016: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
031.880  000.021  000.021: sourcing /home/tbehner/.local/share/nvim/lazy/LuaSnip/plugin/luasnip.vim
031.882  000.035  000.015: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
031.886  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
031.891  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
032.107  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
032.112  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
032.136  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
032.140  000.000  000.000: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
032.412  000.043  000.043: require('hardtime.config')
032.498  000.085  000.085: require('hardtime.log')
032.542  000.191  000.063: require('hardtime.util')
032.549  000.371  000.179: require('hardtime')
032.845  000.019  000.019: require('Comment.config')
032.918  000.045  000.045: require('Comment.ft')
032.922  000.075  000.030: require('Comment.utils')
032.944  000.021  000.021: require('Comment.opfunc')
032.964  000.019  000.019: require('Comment.extra')
032.966  000.326  000.191: require('Comment.api')
032.998  000.376  000.051: sourcing /home/tbehner/.local/share/nvim/lazy/Comment.nvim/plugin/Comment.lua
033.001  000.391  000.015: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
033.006  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
033.020  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
033.053  000.018  000.018: require('Comment')
033.293  000.122  000.122: sourcing /home/tbehner/.local/share/nvim/lazy/vim-gutentags/plugin/gutentags.vim
033.295  000.136  000.014: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
033.299  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
033.304  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
033.690  000.047  000.047: require('treesitter-context.config')
033.698  000.239  000.191: require('treesitter-context')
033.742  000.304  000.065: sourcing /home/tbehner/.local/share/nvim/lazy/nvim-treesitter-context/plugin/treesitter-context.lua
033.744  000.317  000.013: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
033.749  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
033.754  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
034.274  000.154  000.154: require('render-markdown.settings')
034.279  000.349  000.195: require('render-markdown')
034.315  000.033  000.033: require('render-markdown.lib.presets')
034.410  000.028  000.028: require('render-markdown.lib.compat')
034.458  000.017  000.017: require('render-markdown.lib.list')
034.476  000.064  000.047: require('render-markdown.lib.env')
034.570  000.019  000.019: require('render-markdown.lib.interval')
034.592  000.021  000.021: require('render-markdown.lib.str')
034.594  000.064  000.025: require('render-markdown.lib.line')
034.614  000.019  000.019: require('render-markdown.lib.resolved')
034.632  000.018  000.018: require('render-markdown.lib.iter')
034.635  000.129  000.028: require('render-markdown.lib.config')
034.636  000.157  000.028: require('render-markdown.state')
034.660  000.022  000.022: require('render-markdown.core.ts')
034.714  000.022  000.022: require('render-markdown.request.context')
034.742  000.027  000.027: require('render-markdown.core.log')
034.746  000.085  000.035: require('render-markdown.core.ui')
034.782  000.034  000.034: require('render-markdown.core.colors')
034.878  000.025  000.025: require('render-markdown.api')
034.879  000.049  000.024: require('render-markdown.core.command')
034.925  000.031  000.031: require('render-markdown.core.manager')
034.950  001.038  000.187: sourcing /home/tbehner/.local/share/nvim/lazy/render-markdown.nvim/plugin/render-markdown.lua
034.952  001.052  000.014: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
034.958  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
034.964  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
035.032  000.038  000.038: sourcing /home/tbehner/.local/share/nvim/lazy/neovim-tips/plugin/neovim_tips.lua
035.034  000.052  000.013: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
035.036  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
035.040  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
035.146  000.030  000.030: require('neovim_tips.config')
035.655  000.463  000.463: require('neovim_tips.renderer')
035.660  000.490  000.027: require('neovim_tips.tips')
035.693  000.032  000.032: require('neovim_tips.utils')
035.723  000.029  000.029: require('neovim_tips.cache')
035.726  000.579  000.028: require('neovim_tips.loader')
035.814  000.024  000.024: require('neovim_tips.tips_picker.search_parser')
035.963  000.029  000.029: require('nui.object')
036.569  000.564  000.564: require('nui.utils')
036.578  000.595  000.031: require('nui.text')
036.582  000.618  000.023: require('nui.line')
036.627  000.739  000.092: require('nui.popup.border')
036.659  000.030  000.030: require('nui.utils.buf_storage')
036.769  000.109  000.109: require('nui.utils.autocmd')
036.796  000.026  000.026: require('nui.utils.keymap')
036.824  000.027  000.027: require('nui.layout.utils')
036.834  000.985  000.054: require('nui.popup')
036.837  001.022  000.037: require('neovim_tips.tips_picker.help_picker')
036.981  000.023  000.023: require('nui.split.utils')
036.988  000.066  000.043: require('nui.split')
037.016  000.027  000.027: require('nui.layout.float')
037.064  000.047  000.047: require('nui.layout.split')
037.074  000.198  000.058: require('nui.layout')
037.076  000.238  000.040: require('neovim_tips.tips_picker.tips_picker_layout')
037.122  000.045  000.045: require('neovim_tips.tips_picker.events')
037.126  001.382  000.053: require('neovim_tips.tips_picker.init')
037.127  001.400  000.018: require('neovim_tips.picker')
037.179  000.051  000.051: require('neovim_tips.daily_tip')
037.180  002.105  000.045: require('neovim_tips')
037.327  000.052  000.052: sourcing /home/tbehner/.local/share/nvim/lazy/conform.nvim/plugin/conform.lua
037.330  000.068  000.016: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
037.335  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
037.342  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
037.584  000.229  000.229: require('conform')
037.806  000.025  000.025: sourcing /home/tbehner/.local/share/nvim/lazy/nvim-web-devicons/plugin/nvim-web-devicons.vim
037.808  000.056  000.031: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
037.813  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
037.824  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
037.831  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
037.836  000.000  000.000: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
038.137  000.052  000.052: require('lualine_require')
038.376  000.528  000.477: require('lualine')
038.504  000.008  000.008: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
038.923  000.086  000.086: require('lualine.highlight')
039.300  000.010  000.010: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
039.757  000.007  000.007: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
039.812  000.003  000.003: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
039.833  000.003  000.003: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
039.855  000.003  000.003: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
039.874  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
039.899  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
039.923  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
039.952  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
039.984  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.005  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.023  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.042  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.060  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.139  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.158  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.177  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.195  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.215  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.234  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.252  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.270  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.280  000.007  000.007: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.770  000.052  000.052: require('lualine.utils.mode')
040.979  000.007  000.007: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
040.988  000.004  000.004: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.122  000.005  000.005: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.142  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.162  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.179  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.197  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.216  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.245  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.283  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.300  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.320  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.351  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.387  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.407  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.424  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.445  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.463  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.481  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.498  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.517  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.534  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.552  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.665  000.007  000.007: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.671  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.675  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
041.680  000.003  000.003: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.053  000.007  000.007: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.074  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.099  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.116  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.133  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.153  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.170  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.194  000.003  000.003: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.213  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.232  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.249  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.267  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.285  000.003  000.003: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.304  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.324  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.343  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.360  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.377  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.395  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.424  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.443  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.462  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.497  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.516  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.533  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.550  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.568  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
042.585  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
043.415  000.009  000.009: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
043.449  000.005  000.005: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
043.463  000.011  000.011: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
043.470  000.004  000.004: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
043.475  000.003  000.003: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
043.516  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
043.523  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
043.653  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
043.659  000.000  000.000: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
043.808  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
043.813  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
044.108  000.019  000.019: sourcing /home/tbehner/.local/share/nvim/lazy/plenary.nvim/plugin/plenary.vim
044.110  000.034  000.015: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
044.113  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
044.118  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
044.288  000.146  000.146: sourcing /home/tbehner/.local/share/nvim/lazy/telescope.nvim/plugin/telescope.lua
044.290  000.157  000.011: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
044.293  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
044.298  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
044.713  000.410  000.410: require('telescope.builtin')
044.982  000.056  000.056: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/editorconfig.lua
044.985  000.073  000.017: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
045.114  000.113  000.113: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/gzip.vim
045.116  000.125  000.012: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
045.192  000.064  000.064: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/man.lua
045.194  000.074  000.010: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
047.236  000.145  000.145: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/pack/dist/opt/matchit/plugin/matchit.vim
047.255  002.036  001.890: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/matchit.vim
047.258  002.048  000.013: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
047.401  000.082  000.082: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/matchparen.vim
047.402  000.095  000.012: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
047.858  000.168  000.168: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/pack/dist/opt/netrw/plugin/netrwPlugin.vim
047.869  000.399  000.230: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/netrwPlugin.vim
047.871  000.412  000.013: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
048.181  000.261  000.261: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/osc52.lua
048.182  000.277  000.016: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
048.270  000.003  000.003: sourcing /nix/store/lnwcb5mqhm1gmsbcajh8jx301in7lh60-neovim-0.11.5/rplugin.vim
048.341  000.123  000.119: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/rplugin.vim
048.342  000.138  000.015: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
048.404  000.034  000.034: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/shada.vim
048.406  000.048  000.014: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
048.449  000.008  000.008: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/spellfile.vim
048.450  000.023  000.015: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
048.527  000.053  000.053: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/tarPlugin.vim
048.528  000.066  000.013: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
048.671  000.126  000.126: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/tohtml.lua
048.672  000.142  000.015: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
048.700  000.009  000.009: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/tutor.vim
048.701  000.023  000.014: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
048.795  000.079  000.079: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/plugin/zipPlugin.vim
048.796  000.093  000.013: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
049.033  042.959  017.254: require('config.lazy')
049.281  000.112  000.112: require('config.utils')
049.367  000.332  000.221: require('config.mappings')
050.719  000.084  000.084: require('everforest.util')
050.839  000.118  000.118: require('everforest.colours')
051.373  000.038  000.038: require('everforest.colour_utility')
051.375  000.535  000.497: require('everforest.highlights')
051.377  000.894  000.157: require('everforest')
054.741  004.316  003.422: sourcing /home/tbehner/.local/share/nvim/lazy/everforest-nvim/colors/everforest.lua
054.988  000.011  000.011: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.292  000.003  000.003: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.295  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.298  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.300  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.301  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.303  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.305  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.307  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.308  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.310  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.311  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.313  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.315  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.316  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.318  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.320  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.321  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.323  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.324  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.326  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.328  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.329  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.331  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.332  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.334  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.336  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.337  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.339  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.341  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.342  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.344  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.345  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.347  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.348  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.350  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.352  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.353  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.355  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.356  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.358  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.360  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.361  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.363  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.365  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.366  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.368  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.370  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.371  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.373  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.375  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.376  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.378  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.380  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.381  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.383  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.401  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.403  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.405  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.406  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.408  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.409  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.411  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.421  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.423  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.425  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.426  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.428  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.430  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.431  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.433  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.434  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.466  000.004  000.004: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.475  000.002  000.002: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.480  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.484  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.489  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.493  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.497  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.501  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.505  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.509  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.514  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.517  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.521  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.525  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.529  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.532  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.537  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.541  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.544  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.554  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.558  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.562  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.570  000.007  000.007: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.602  000.004  000.004: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.607  000.002  000.002: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.654  000.007  000.007: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.659  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.663  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.667  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.670  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.674  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.678  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.684  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.687  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.690  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.694  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.698  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.702  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.706  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.711  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.715  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.718  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.722  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.725  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.751  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.756  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.762  000.004  000.004: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.772  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.774  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.779  000.003  000.003: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.851  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.855  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.858  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.862  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.865  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.869  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.872  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.878  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.881  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.885  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.888  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.891  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.895  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.899  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.904  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.907  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.910  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.914  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.917  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.921  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.932  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.937  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.942  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.946  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.949  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.952  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.955  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
055.959  000.001  000.001: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
056.113  000.010  000.010: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
056.124  000.003  000.003: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
056.137  000.010  000.010: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
056.144  000.005  000.005: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
056.148  000.003  000.003: sourcing nvim_exec2() called at ColorScheme Autocommands for "*":0
056.159  006.790  002.278: require('config.set')
056.723  000.564  000.564: require('config.treesitter')
057.270  000.021  000.021: require('diffview.lazy')
057.370  000.028  000.028: require('diffview.ffi')
057.396  000.025  000.025: require('diffview.oop')
057.405  000.095  000.041: require('diffview.async')
057.513  000.071  000.071: require('diffview.utils')
057.576  000.019  000.019: require('diffview.mock')
057.584  000.303  000.119: require('diffview.logger')
057.621  000.030  000.030: require('diffview.control')
057.666  000.037  000.037: require('diffview.events')
057.689  000.585  000.194: require('diffview.bootstrap')
057.701  000.622  000.038: sourcing /home/tbehner/.local/share/nvim/lazy/diffview.nvim/plugin/diffview.lua
057.704  000.647  000.025: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
057.710  000.002  000.002: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
057.716  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
057.784  000.032  000.032: sourcing /home/tbehner/.local/share/nvim/lazy/neogit/plugin/neogit.lua
057.786  000.053  000.021: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
057.789  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
057.792  000.001  000.001: sourcing nvim_exec2() called at /home/tbehner/.config/nvim/init.lua:0
057.840  000.031  000.031: require('neogit')
057.940  000.033  000.033: require('neogit.lib.util')
057.959  000.116  000.084: require('neogit.config')
057.976  000.015  000.015: require('neogit.lib.signs')
057.993  000.017  000.017: require('neogit.autocmds')
058.073  000.029  000.029: require('neogit.lib.color')
058.075  000.081  000.052: require('neogit.lib.hl')
058.152  000.059  000.059: require('neogit.logger')
058.217  000.020  000.020: require('plenary.bit')
058.235  000.017  000.017: require('plenary.functional')
058.252  000.099  000.062: require('plenary.path')
058.254  000.178  000.020: require('neogit.lib.state')
058.407  000.018  000.018: require('neogit.lib.ui.component')
058.432  000.024  000.024: require('neogit.lib.ui.renderer')
058.450  000.017  000.017: require('neogit.lib.collection')
058.456  000.106  000.046: require('neogit.lib.ui')
058.462  000.167  000.061: require('neogit.lib.buffer')
058.550  000.015  000.015: require('neogit.lib.git')
058.555  000.049  000.034: require('neogit.buffers.common')
058.637  000.015  000.015: require('plenary.tbl')
058.639  000.033  000.018: require('plenary.vararg.rotate')
058.639  000.049  000.017: require('plenary.vararg')
058.655  000.015  000.015: require('plenary.errors')
058.658  000.085  000.021: require('plenary.async.async')
058.727  000.017  000.017: require('plenary.async.structs')
058.730  000.041  000.024: require('plenary.async.control')
058.734  000.061  000.020: require('plenary.async.util')
058.735  000.076  000.015: require('plenary.async.tests')
058.736  000.181  000.019: require('plenary.async')
058.741  000.278  000.049: require('neogit.buffers.status.ui')
058.791  000.049  000.049: require('neogit.popups')
058.813  000.021  000.021: require('neogit.watcher')
058.829  000.016  000.016: require('neogit.lib.event')
058.833  000.577  000.046: require('neogit.buffers.status')
058.945  000.022  000.022: require('neogit.lib.notification')
058.948  000.049  000.027: require('neogit.lib.popup.builder')
058.966  000.017  000.017: require('neogit.lib.input')
059.028  000.043  000.043: require('neogit.lib.finder')
059.029  000.062  000.020: require('neogit.buffers.fuzzy_finder')
059.062  000.031  000.031: require('neogit.lib.popup.ui')
059.065  000.215  000.055: require('neogit.lib.popup')
059.066  000.231  000.015: require('neogit.lib')
059.222  000.026  000.026: require('neogit.buffers.process')
059.243  000.020  000.020: require('neogit.spinner')
059.254  000.092  000.046: require('neogit.process')
059.278  000.024  000.024: require('neogit.runner')
059.303  000.236  000.120: require('neogit.lib.git.cli')
060.519  003.794  001.607: require('neogit')
060.526  054.498  000.059: sourcing /home/tbehner/.config/nvim/init.lua
060.530  001.448: sourcing vimrc file(s)
060.672  000.026  000.026: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/filetype.lua
060.843  000.045  000.045: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/syntax/synload.vim
060.894  000.180  000.135: sourcing /nix/store/jx332jllgyrqbnzi8svnk8xbygc9nbmp-neovim-unwrapped-0.11.5/share/nvim/runtime/syntax/syntax.vim
060.898  000.162: inits 3
062.662  001.764: reading ShaDa
063.132  000.075  000.075: require('luasnip.util.directed_graph')
063.189  000.051  000.051: require('luasnip.session.enqueueable_operations')
063.198  000.256  000.129: require('luasnip.loaders.from_lua')
063.698  000.040  000.040: require('luasnip.util.events')
063.713  000.140  000.099: require('luasnip.nodes.node')
063.842  000.127  000.127: require('luasnip.nodes.insertNode')
063.916  000.071  000.071: require('luasnip.nodes.textNode')
063.981  000.062  000.062: require('luasnip.util.mark')
064.032  000.049  000.049: require('luasnip.util.pattern_tokenizer')
064.078  000.044  000.044: require('luasnip.util.dict')
064.400  000.008  000.008: require('jsregexp.core')
064.408  000.092  000.083: require('luasnip-jsregexp')
064.418  000.285  000.194: require('luasnip.util.jsregexp')
064.429  000.347  000.062: require('luasnip.nodes.util.trig_engines')
064.522  001.101  000.263: require('luasnip.nodes.snippet')
064.526  001.154  000.052: require('luasnip.nodes.duplicate')
064.528  001.228  000.074: require('luasnip.loaders.snippet_cache')
064.537  001.335  000.107: require('luasnip.loaders.from_snipmate')
065.053  000.077  000.077: require('luasnip.util.parser.neovim_ast')
065.133  000.077  000.077: require('luasnip.util.str')
065.144  000.250  000.096: require('luasnip.util.parser.ast_utils')
065.258  000.112  000.112: require('luasnip.nodes.functionNode')
065.408  000.148  000.148: require('luasnip.nodes.choiceNode')
065.533  000.122  000.122: require('luasnip.nodes.dynamicNode')
065.594  000.058  000.058: require('luasnip.util.functions')
065.604  000.811  000.121: require('luasnip.util.parser.ast_parser')
065.847  000.241  000.241: require('luasnip.util.parser.neovim_parser')
065.855  001.177  000.124: require('luasnip.util.parser')
065.923  000.066  000.066: require('luasnip.nodes.snippetProxy')
066.085  000.160  000.160: require('luasnip.util.jsonc')
066.095  001.555  000.152: require('luasnip.loaders.from_vscode')
066.123  000.316: opening buffers
066.187  000.064: BufEnter autocommands
066.188  000.002: editing files in windows
066.479  000.215  000.215: sourcing /home/tbehner/.local/share/nvim/lazy/vim-gutentags/autoload/gutentags.vim
066.543  000.140: VimEnter autocommands
066.633  000.052  000.052: require('vim.termcap')
066.682  000.041  000.041: require('vim.text')
066.698  000.063: UIEnter autocommands
066.699  000.001: before starting main loop
066.935  000.236: first screen update
066.936  000.001: --- NVIM STARTED ---

