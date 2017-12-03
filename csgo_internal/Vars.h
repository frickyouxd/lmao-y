#pragma once

struct Variables
{
	Variables()
	{ }

	struct
	{
		bool Opened = false;
		bool Unload = false;
	} Menu;

	struct
	{
		bool Bhop = false;
	} Misc;
};

extern Variables Vars;
