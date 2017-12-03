#include "Cheat.h"

// c&p from Mark_HC's source because it worked

PlaySoundFn oPlaySound;

void __stdcall Hooks::PlaySound_CSGO(const char* fileName)
{
	oPlaySound(fileName);
}
