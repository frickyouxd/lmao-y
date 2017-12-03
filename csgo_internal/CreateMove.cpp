#include "Cheat.h"

CreateMoveFn oCreateMove;

bool __stdcall Hooks::CreateMove( float flInputSampleTime, CUserCmd* cmd )
{
	G::LocalPlayer = U::GetLocalPlayer();
	G::UserCmd = cmd;

	if( cmd->command_number == 0 )
		return false;

	DWORD* framePointer;
	__asm mov framePointer, ebp;
	*( bool* )( *framePointer - 0x1C ) = G::SendPacket;

	return false;
}
