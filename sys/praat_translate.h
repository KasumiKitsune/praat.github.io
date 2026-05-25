#ifndef _praat_translate_h_
#define _praat_translate_h_

using char32 = char32_t;

extern int g_language_choice;
const char32* praat_translate (const char32* text);
const char32* praat_translate_manual (const char32* text);

#endif
