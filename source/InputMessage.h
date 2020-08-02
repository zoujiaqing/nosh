/* COPYING ******************************************************************
For copyright and licensing terms, see the file named COPYING.
// **************************************************************************
*/

#if !defined(INCLUDE_INPUTMESSAGE_H)
#define INCLUDE_INPUTMESSAGE_H

#include <stdint.h>

enum {
	INPUT_MSG_MASK		= 0xFF000000,
	INPUT_MSG_UCS3		= 0x01000000,
	INPUT_MSG_SKEY		= 0x02000000,
	// Don't clash with 0x03000000 being modifiers in keyboard maps.
	INPUT_MSG_XPOS		= 0x04000000,
	INPUT_MSG_YPOS		= 0x05000000,
	INPUT_MSG_WHEEL		= 0x06000000,
	INPUT_MSG_BUTTON	= 0x07000000,
	INPUT_MSG_PUCS3		= 0x09000000,
	INPUT_MSG_SESSION	= 0x0A000000,
	INPUT_MSG_CKEY		= 0x0C000000,
	INPUT_MSG_EKEY		= 0x0E000000,
	INPUT_MSG_FKEY		= 0x0F000000,
	INPUT_MSG_AUCS3		= 0x11000000,
	// Don't clash with 0x1E000000 being unshifted extended keys in keyboard maps.
	// Don't clash with 0x1F000000 being unmodifiable function keys in keyboard maps.
};

// modifiers as encoded in DEC VT control sequences (plus 1)
// These are expressed in terms of the ISO 9995 levels and groups.
enum {
	INPUT_MODIFIER_LEVEL2	= (1U << 0U),
	INPUT_MODIFIER_LEVEL3	= (1U << 1U),
	INPUT_MODIFIER_CONTROL	= (1U << 2U),
	INPUT_MODIFIER_GROUP2	= (1U << 3U),
	INPUT_MODIFIER_SUPER	= (1U << 4U),	///< Windows, Apple/Command, Meta (Sun), or GUI (USB)
};

// These values are intentionally the same as USB keyboard HID codes, General Desktop page.
enum {
	SYSTEM_KEY_POWER		= 0x0081,
	SYSTEM_KEY_HALT			= 0x0F81,	// non-USB
	SYSTEM_KEY_SLEEP		= 0x0082,
	SYSTEM_KEY_WAKE			= 0x0083,
	SYSTEM_KEY_COLD_RESTART		= 0x008E,
	SYSTEM_KEY_WARM_RESTART		= 0x008F,
	SYSTEM_KEY_DEBUG		= 0x00A4,
	SYSTEM_KEY_ABEND		= 0x0FA4,	// non-USB
	SYSTEM_KEY_HIBERNATE		= 0x00A8,
};

// These values are intentionally the same as USB keyboard HID codes, Keyboard page.
// However, clearly there are a lot more editing and application keys in the termcap model than in the USB model.
enum {
	// Main keypad keys that emulations might make switchable.
 	EXTENDED_KEY_RETURN_OR_ENTER	= 0x0028,
 	EXTENDED_KEY_BACKSPACE		= 0x002A,
 	EXTENDED_KEY_ALTERNATE_ERASE	= 0x0099,

	// CJK keypad
	//
	// 0x0087, USB HID usage for the International1 key on the 104/107-key and 106/109-key PC keyboards, is not an extended key message
 	EXTENDED_KEY_KATAKANA_HIRAGANA	= 0x0088,
 	EXTENDED_KEY_ROMAJI		= 0x0E88,	// non-USB
	// 0x0089, USB HID usage for the International3 key on the 106/109-key PC keyboard, is not an extended key message
 	EXTENDED_KEY_HENKAN		= 0x008A,
 	EXTENDED_KEY_MUHENKAN		= 0x008B,
	// 0x008C, USB HID usage for the JP . key, is not an extended key message
 	EXTENDED_KEY_HAN_YEONG		= 0x0090,
 	EXTENDED_KEY_HANGEUL		= 0x0E90,	// non-USB
 	EXTENDED_KEY_HANJA		= 0x0091,
 	EXTENDED_KEY_KATAKANA		= 0x0092,
 	EXTENDED_KEY_HIRAGANA		= 0x0093,
 	EXTENDED_KEY_ZENKAKU_HANKAKU	= 0x0094,
 	EXTENDED_KEY_IM_TOGGLE		= 0x0E94,	// non-USB

	// Cursor+Editing keypad
 	EXTENDED_KEY_INSERT		= 0x0049,	// insert/replace toggle
 	EXTENDED_KEY_INS_CHAR		= 0x0E49,	// non-USB
 	EXTENDED_KEY_INS_LINE		= 0x0F49,	// non-USB
 	EXTENDED_KEY_HOME		= 0x004A,
 	EXTENDED_KEY_PAGE_UP		= 0x004B,
 	EXTENDED_KEY_DELETE		= 0x004C,
 	EXTENDED_KEY_DEL_CHAR		= 0x0E4C,	// non-USB
 	EXTENDED_KEY_DEL_LINE		= 0x0F4C,	// non-USB
 	EXTENDED_KEY_END		= 0x004D,
 	EXTENDED_KEY_PAGE_DOWN		= 0x004E,
 	EXTENDED_KEY_RIGHT_ARROW	= 0x004F,
 	EXTENDED_KEY_LEFT_ARROW		= 0x0050,
 	EXTENDED_KEY_DOWN_ARROW		= 0x0051,
 	EXTENDED_KEY_UP_ARROW		= 0x0052,
 	EXTENDED_KEY_CENTRE		= 0x0F5D,	// non-USB
 	EXTENDED_KEY_LL_ARROW		= 0x0F59,	// non-USB
	EXTENDED_KEY_CLR_SCR		= 0x0F50,	// non-USB
	EXTENDED_KEY_CLR_EOS		= 0x0F51,	// non-USB
	EXTENDED_KEY_CLR_EOL		= 0x0F52,	// non-USB
	EXTENDED_KEY_SCROLL_UP		= 0x0F53,	// non-USB
	EXTENDED_KEY_SCROLL_DOWN	= 0x0F54,	// non-USB
	EXTENDED_KEY_SET_TAB		= 0x0F55,	// non-USB
	EXTENDED_KEY_CLEAR_TAB		= 0x0F56,	// non-USB
	EXTENDED_KEY_CLEAR_TABS		= 0x0F57,	// non-USB
 	EXTENDED_KEY_BACKTAB		= 0x0F2B,	// non-USB

	// Calculator keypad
 	EXTENDED_KEY_PAD_SLASH		= 0x0054,
 	EXTENDED_KEY_PAD_ASTERISK	= 0x0055,
 	EXTENDED_KEY_PAD_MINUS		= 0x0056,
 	EXTENDED_KEY_PAD_PLUS		= 0x0057,
 	EXTENDED_KEY_PAD_ENTER		= 0x0058,
 	EXTENDED_KEY_PAD_END		= 0x0059,
 	EXTENDED_KEY_PAD_DOWN		= 0x005A,
 	EXTENDED_KEY_PAD_PAGE_DOWN	= 0x005B,
 	EXTENDED_KEY_PAD_LEFT		= 0x005C,
 	EXTENDED_KEY_PAD_CENTRE		= 0x005D,
 	EXTENDED_KEY_PAD_RIGHT		= 0x005E,
 	EXTENDED_KEY_PAD_HOME		= 0x005F,
 	EXTENDED_KEY_PAD_UP		= 0x0060,
 	EXTENDED_KEY_PAD_PAGE_UP	= 0x0061,
 	EXTENDED_KEY_PAD_INSERT		= 0x0062,
 	EXTENDED_KEY_PAD_DELETE		= 0x0063,
 	EXTENDED_KEY_PAD_EQUALS		= 0x0067,
 	EXTENDED_KEY_PAD_COMMA		= 0x0085,
 	EXTENDED_KEY_PAD_EQUALS_AS400	= 0x0086,
 	EXTENDED_KEY_PAD_00		= 0x00B0,
 	EXTENDED_KEY_PAD_000		= 0x00B1,
 	EXTENDED_KEY_PAD_THOUSANDS_SEP	= 0x00B2,
 	EXTENDED_KEY_PAD_DECIMAL_SEP	= 0x00B3,
 	EXTENDED_KEY_PAD_CURRENCY_UNIT	= 0x00B4,
 	EXTENDED_KEY_PAD_CURRENCY_SUB	= 0x00B5,
 	EXTENDED_KEY_PAD_OPEN_BRACKET	= 0x00B6,
 	EXTENDED_KEY_PAD_CLOSE_BRACKET	= 0x00B7,
 	EXTENDED_KEY_PAD_OPEN_BRACE	= 0x00B8,
 	EXTENDED_KEY_PAD_CLOSE_BRACE	= 0x00B9,
 	EXTENDED_KEY_PAD_TAB		= 0x00BA,
 	EXTENDED_KEY_PAD_BACKSPACE	= 0x00BB,
 	EXTENDED_KEY_PAD_A		= 0x00BC,
 	EXTENDED_KEY_PAD_B		= 0x00BD,
 	EXTENDED_KEY_PAD_C		= 0x00BE,
 	EXTENDED_KEY_PAD_D		= 0x00BF,
 	EXTENDED_KEY_PAD_E		= 0x00C0,
 	EXTENDED_KEY_PAD_F		= 0x00C1,
 	EXTENDED_KEY_PAD_XOR		= 0x00C2,
 	EXTENDED_KEY_PAD_CARET		= 0x00C3,
 	EXTENDED_KEY_PAD_PERCENT	= 0x00C4,
 	EXTENDED_KEY_PAD_LESS		= 0x00C5,
 	EXTENDED_KEY_PAD_GREATER	= 0x00C6,
 	EXTENDED_KEY_PAD_AND		= 0x00C7,
 	EXTENDED_KEY_PAD_ANDAND		= 0x00C8,
 	EXTENDED_KEY_PAD_OR		= 0x00C9,
 	EXTENDED_KEY_PAD_OROR		= 0x00CA,
 	EXTENDED_KEY_PAD_COLON		= 0x00CB,
 	EXTENDED_KEY_PAD_HASH		= 0x00CC,
 	EXTENDED_KEY_PAD_SPACE		= 0x00CD,
 	EXTENDED_KEY_PAD_AT		= 0x00CE,
 	EXTENDED_KEY_PAD_EXCLAMATION	= 0x00CF,
 	EXTENDED_KEY_PAD_MSTR		= 0x00D0,
 	EXTENDED_KEY_PAD_MRCL		= 0x00D1,
 	EXTENDED_KEY_PAD_MCLR		= 0x00D2,
 	EXTENDED_KEY_PAD_MADD		= 0x00D3,
 	EXTENDED_KEY_PAD_MSUB		= 0x00D4,
 	EXTENDED_KEY_PAD_MMUL		= 0x00D5,
 	EXTENDED_KEY_PAD_MDIV		= 0x00D6,
 	EXTENDED_KEY_PAD_SIGN		= 0x00D7,
 	EXTENDED_KEY_PAD_CLEAR		= 0x00D8,
 	EXTENDED_KEY_PAD_CLEAR_ENTRY	= 0x00D9,
 	EXTENDED_KEY_PAD_BINARY		= 0x00DA,
 	EXTENDED_KEY_PAD_OCTAL		= 0x00DB,
 	EXTENDED_KEY_PAD_DECIMAL	= 0x00DC,
 	EXTENDED_KEY_PAD_HEXADECIMAL	= 0x00DD,
 	EXTENDED_KEY_PAD_F1		= 0x0F01,	// non-USB
 	EXTENDED_KEY_PAD_F2		= 0x0F02,	// non-USB
 	EXTENDED_KEY_PAD_F3		= 0x0F03,	// non-USB
 	EXTENDED_KEY_PAD_F4		= 0x0F04,	// non-USB
 	EXTENDED_KEY_PAD_F5		= 0x0F05,	// non-USB

	// Application functions keypad
 	EXTENDED_KEY_APPLICATION	= 0x0065,
 	EXTENDED_KEY_EXECUTE		= 0x0074,
 	EXTENDED_KEY_HELP		= 0x0075,
 	EXTENDED_KEY_MENU		= 0x0076,
 	EXTENDED_KEY_SELECT		= 0x0077,
 	EXTENDED_KEY_STOP		= 0x0078,
 	EXTENDED_KEY_AGAIN		= 0x0079,
 	EXTENDED_KEY_UNDO		= 0x007A,
 	EXTENDED_KEY_CUT		= 0x007B,
 	EXTENDED_KEY_COPY		= 0x007C,
 	EXTENDED_KEY_PASTE		= 0x007D,
 	EXTENDED_KEY_FIND		= 0x007E,
 	EXTENDED_KEY_CANCEL		= 0x009B,
 	EXTENDED_KEY_CLEAR		= 0x009C,
 	EXTENDED_KEY_PRIOR		= 0x009D,
 	EXTENDED_KEY_RETURN		= 0x009E,
 	EXTENDED_KEY_SEPARATOR		= 0x009F,
 	EXTENDED_KEY_OUT		= 0x00A0,
 	EXTENDED_KEY_OPER		= 0x00A1,
 	EXTENDED_KEY_CLEAR_OR_AGAIN	= 0x00A2,
 	EXTENDED_KEY_PROPERTIES		= 0x00A3,	// a.k.a. "cr sel"
 	EXTENDED_KEY_EX_SEL		= 0x00A4,
	EXTENDED_KEY_NEXT		= 0x0F60,	// non-USB
	EXTENDED_KEY_PREVIOUS		= 0x0F61,	// non-USB
	EXTENDED_KEY_PRINT		= 0x0F62,	// non-USB
	EXTENDED_KEY_BEGIN		= 0x0F63,	// non-USB
	EXTENDED_KEY_CLOSE		= 0x0F64,	// non-USB
	EXTENDED_KEY_COMMAND		= 0x0F65,	// non-USB
	EXTENDED_KEY_CREATE		= 0x0F66,	// non-USB
	EXTENDED_KEY_EXIT		= 0x0F67,	// non-USB
	EXTENDED_KEY_MARK		= 0x0F68,	// non-USB
	EXTENDED_KEY_MESSAGE		= 0x0F69,	// non-USB
	EXTENDED_KEY_MOVE		= 0x0F6A,	// non-USB
	EXTENDED_KEY_OPEN		= 0x0F6B,	// non-USB
	EXTENDED_KEY_OPTIONS		= 0x0F6C,	// non-USB
	EXTENDED_KEY_REDO		= 0x0F6D,	// non-USB
	EXTENDED_KEY_REFERENCE		= 0x0F6E,	// non-USB
	EXTENDED_KEY_REFRESH		= 0x0F6F,	// non-USB
	EXTENDED_KEY_REPLACE		= 0x0F70,	// non-USB
	EXTENDED_KEY_RESTART		= 0x0F71,	// non-USB
	EXTENDED_KEY_RESUME		= 0x0F72,	// non-USB
	EXTENDED_KEY_SAVE		= 0x0F73,	// non-USB
	EXTENDED_KEY_SUSPEND		= 0x0F74,	// non-USB

	// System functions keypad
 	EXTENDED_KEY_ATTENTION		= 0x009A,	// a.k.a. "system request"
 	EXTENDED_KEY_PRINT_SCREEN	= 0x0046,
 	EXTENDED_KEY_PAUSE		= 0x0048,
 	EXTENDED_KEY_BREAK		= 0x0F48,	// non-USB

	// Multimedia keypad
 	EXTENDED_KEY_MUTE		= 0x007F,
 	EXTENDED_KEY_VOLUME_UP		= 0x0080,
 	EXTENDED_KEY_VOLUME_DOWN	= 0x0081,
};

// These values are intentionally the same as USB keyboard HID codes, Consumer page.
enum {
	CONSUMER_KEY_PLAY		= 0x00B0,
	CONSUMER_KEY_PAUSE		= 0x00B1,
	CONSUMER_KEY_RECORD		= 0x00B2,
	CONSUMER_KEY_FAST_FORWARD	= 0x00B3,
	CONSUMER_KEY_REWIND		= 0x00B4,
	CONSUMER_KEY_NEXT_TRACK		= 0x00B5,
	CONSUMER_KEY_PREV_TRACK		= 0x00B6,
	CONSUMER_KEY_STOP_PLAYING	= 0x00B7,
	CONSUMER_KEY_EJECT		= 0x00B8,
	CONSUMER_KEY_RANDOM_PLAY	= 0x00B9,
	CONSUMER_KEY_REPEAT		= 0x00BC,
	CONSUMER_KEY_TRACK_NORMAL	= 0x00BE,
	CONSUMER_KEY_FRAME_FORWARD	= 0x00C0,
	CONSUMER_KEY_FRAME_BACK		= 0x00C1,
	CONSUMER_KEY_STOP_EJECT		= 0x00CC,
	CONSUMER_KEY_PLAY_PAUSE		= 0x00CD,
	CONSUMER_KEY_PLAY_SKIP		= 0x00CE,
	CONSUMER_KEY_MUTE_PLAYER	= 0x00E2,
	CONSUMER_KEY_BASS_BOOST		= 0x00E5,
	CONSUMER_KEY_LOUDNESS		= 0x00E7,
	CONSUMER_KEY_VOLUME_UP		= 0x00E9,
	CONSUMER_KEY_VOLUME_DOWN	= 0x00EA,
	CONSUMER_KEY_BALANCE_RIGHT	= 0x0150,
	CONSUMER_KEY_BALANCE_LEFT	= 0x0151,
	CONSUMER_KEY_BASS_UP		= 0x0152,
	CONSUMER_KEY_BASS_DOWN		= 0x0153,
	CONSUMER_KEY_TREBLE_UP		= 0x0154,
	CONSUMER_KEY_TREBLE_DOWN	= 0x0155,
	CONSUMER_KEY_WORDPROCESSOR	= 0x0184,
	CONSUMER_KEY_TEXT_EDITOR	= 0x0185,
	CONSUMER_KEY_SPREADSHEET	= 0x0186,
	CONSUMER_KEY_GRAPHICS_EDITOR	= 0x0187,
	CONSUMER_KEY_PRESENTATION_APP	= 0x0188,
	CONSUMER_KEY_DATABASE		= 0x0189,
	CONSUMER_KEY_MAIL		= 0x018A,
	CONSUMER_KEY_NEWS		= 0x018B,
	CONSUMER_KEY_VOICEMAIL		= 0x018C,
	CONSUMER_KEY_ADDRESS_BOOK	= 0x018D,
	CONSUMER_KEY_CALENDAR		= 0x018E,
	CONSUMER_KEY_PROJECT_MANAGER	= 0x018F,
	CONSUMER_KEY_TIMECARD		= 0x0190,
	CONSUMER_KEY_CHECKBOOK		= 0x0191,
	CONSUMER_KEY_CALCULATOR		= 0x0192,
	CONSUMER_KEY_COMPUTER		= 0x0194,
	CONSUMER_KEY_NETWORK		= 0x0195,
	CONSUMER_KEY_WWW		= 0x0196,
	CONSUMER_KEY_CONFERENCE		= 0x0198,
	CONSUMER_KEY_CHAT		= 0x0199,
	CONSUMER_KEY_DIALLER		= 0x019A,
	CONSUMER_KEY_LOGON		= 0x019B,
	CONSUMER_KEY_LOGOFF		= 0x019C,
	CONSUMER_KEY_LOCK		= 0x019E,
	CONSUMER_KEY_CONTROL_PANEL	= 0x019F,
	CONSUMER_KEY_CLI		= 0x01A0,
	CONSUMER_KEY_TASK_MANAGER	= 0x01A1,
	CONSUMER_KEY_SELECT_TASK	= 0x01A2,
	CONSUMER_KEY_NEXT_TASK		= 0x01A3,
	CONSUMER_KEY_PREVIOUS_TASK	= 0x01A4,
	CONSUMER_KEY_HALT_TASK		= 0x01A5,
	CONSUMER_KEY_HELP_CENTRE	= 0x01A6,
	CONSUMER_KEY_DOCUMENTS		= 0x01A7,
	CONSUMER_KEY_DESKTOP		= 0x01AA,
	CONSUMER_KEY_CLOCK		= 0x01B3,
	CONSUMER_KEY_FILE_MANAGER	= 0x01B4,
	CONSUMER_KEY_INSTANT_MESSAGING	= 0x01BC,
	CONSUMER_KEY_WWW_SHOPPING	= 0x01C1,
	CONSUMER_KEY_NEW		= 0x0201,
	CONSUMER_KEY_OPEN		= 0x0202,
	CONSUMER_KEY_CLOSE		= 0x0203,
	CONSUMER_KEY_EXIT		= 0x0204,
	CONSUMER_KEY_MAXIMIZE		= 0x0205,
	CONSUMER_KEY_MINIMIZE		= 0x0206,
	CONSUMER_KEY_SAVE		= 0x0207,
	CONSUMER_KEY_PRINT		= 0x0208,
	CONSUMER_KEY_PROPERTIES		= 0x0209,
	CONSUMER_KEY_UNDO		= 0x021A,
	CONSUMER_KEY_COPY		= 0x021B,
	CONSUMER_KEY_CUT		= 0x021C,
	CONSUMER_KEY_PASTE		= 0x021D,
	CONSUMER_KEY_SELECT_ALL		= 0x021E,
	CONSUMER_KEY_FIND		= 0x021F,
	CONSUMER_KEY_FIND_AND_REPLACE	= 0x0220,
	CONSUMER_KEY_SEARCH		= 0x0221,
	CONSUMER_KEY_HOME		= 0x0223,
	CONSUMER_KEY_BACK		= 0x0224,
	CONSUMER_KEY_FORWARD		= 0x0225,
	CONSUMER_KEY_STOP_LOADING	= 0x0226,
	CONSUMER_KEY_REFRESH		= 0x0227,
	CONSUMER_KEY_PREVIOUS_LINK	= 0x0228,
	CONSUMER_KEY_NEXT_LINK		= 0x0229,
	CONSUMER_KEY_BOOKMARKS		= 0x022A,
	CONSUMER_KEY_HISTORY		= 0x022B,
};

extern inline uint32_t MessageForUCS3(uint32_t c) { return INPUT_MSG_UCS3 | (c & ~INPUT_MSG_MASK); }
extern inline uint32_t MessageForAcceleratorKey(uint32_t c) { return INPUT_MSG_AUCS3 | (c & ~INPUT_MSG_MASK); }
extern inline uint32_t MessageForSystemKey(uint16_t k, uint8_t m) { return INPUT_MSG_SKEY | (uint32_t(k & 0xFFFF) << 8U) | uint32_t(m & 0xFF); }
extern inline uint32_t MessageForConsumerKey(uint16_t k, uint8_t m) { return INPUT_MSG_CKEY | (uint32_t(k & 0xFFFF) << 8U) | uint32_t(m & 0xFF); }
extern inline uint32_t MessageForExtendedKey(uint16_t k, uint8_t m) { return INPUT_MSG_EKEY | (uint32_t(k & 0xFFFF) << 8U) | uint32_t(m & 0xFF); }
extern inline uint32_t MessageForFunctionKey(uint8_t k, uint8_t m) { return INPUT_MSG_FKEY | (uint32_t(k & 0xFFFF) << 8U) | uint32_t(m & 0xFF); }
extern inline uint32_t MessageForSession(uint16_t n, uint8_t m) { return INPUT_MSG_SESSION | (uint32_t(n & 0xFFFF) << 8U) | uint32_t(m & 0xFF); }
extern inline uint32_t MessageForMouseColumn(uint16_t n, uint8_t m) { return INPUT_MSG_XPOS | (uint32_t(n & 0xFFFF) << 8U) | uint32_t(m & 0xFF); }
extern inline uint32_t MessageForMouseRow(uint16_t n, uint8_t m) { return INPUT_MSG_YPOS | (uint32_t(n & 0xFFFF) << 8U) | uint32_t(m & 0xFF); }
extern inline uint32_t MessageForMouseWheel(uint8_t n, uint8_t v, uint8_t m) { return INPUT_MSG_WHEEL | (uint32_t(n & 0xFF) << 16U) | (uint32_t(v & 0xFF) << 8U) | uint32_t(m & 0xFF); }
extern inline uint32_t MessageForMouseButton(uint8_t n, uint8_t v, uint8_t m) { return INPUT_MSG_BUTTON | (uint32_t(n & 0xFF) << 16U) | (uint32_t(v & 0xFF) << 8U) | uint32_t(m & 0xFF); }

#endif
