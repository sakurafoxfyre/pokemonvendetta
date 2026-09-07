#ifndef GUARD_MYSTERY_GIFT_MENU_H
#define GUARD_MYSTERY_GIFT_MENU_H

extern bool8 gGiftIsFromEReader;

void PrintMysteryGiftOrEReaderHeader(bool8 isEReader, bool32 useCancel);
void MG_DrawCheckerboardPattern(u32 bg);
void MainCB_FreeAllBuffersAndReturnToInitTitleScreen(void);
s8 DoMysteryGiftYesNo(u8 *textState, u16 *windowId, bool8 yesNoBoxPlacement, const u8 *str);

#endif //GUARD_MYSTERY_GIFT_MENU_H
