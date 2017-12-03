#include "Cheat.h"

PaintTraverseFn oPaintTraverse;

void __stdcall Hooks::PaintTraverse(unsigned int panel, bool forceRepaint, bool allowForce)
{
	oPaintTraverse(panel, forceRepaint, allowForce);

	//g_pRenderSurface->AddFont("FONT_ESP", "Courier New", 12, FW_NORMAL, 0, 0, SDK::FONTFLAG_OUTLINE);

	static unsigned int drawPanel;
	if (!drawPanel)
	{
		const char* panelname = I::VPanel->GetName(panel);

		if (panelname[0] == 'M' && panelname[2] == 't')
			drawPanel = panel;
	}

	if (panel != drawPanel)
		return;

	// dumb fix so we can have no visuals but still see the menu
	D::DrawPixel(1, 1, Color(0, 0, 0));
	D::DrawString(F::Watermark, 5, 5, Color(255, 255, 255), 0, "z factor");

	//E::Visuals->Run(); // Here u can run ur visuals
}
