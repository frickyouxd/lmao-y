#include "Cheat.h"
DrawModelExecuteFn oDrawModelExecute;

void ForceMaterial( IMaterial* material, Color color )
{
	if( material != NULL )
	{
		I::RenderView->SetColorModulation( color.Base() );
		I::ModelRender->ForcedMaterialOverride( material );
	}
}

void __stdcall Hooks::DrawModelExecute( void* context, void* state, const ModelRenderInfo_t& info, matrix3x4_t* pCustomBoneToWorld )
{
	H::ModelRender->UnHook();

	if( I::Engine->IsInGame() && G::LocalPlayer )
	{
		if (info.pModel)
		{
		}
	}
	I::ModelRender->DrawModelExecute( context, state, info, pCustomBoneToWorld );
	I::ModelRender->ForcedMaterialOverride( NULL );
	H::ModelRender->ReHook();
}
