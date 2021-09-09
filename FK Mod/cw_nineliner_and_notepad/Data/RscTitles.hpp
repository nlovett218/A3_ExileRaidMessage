//#include "CW_Noteblock\Dialog\dia_include.hpp"

class RscTitles
{
	titles[]={"CW_NOTEBLOCK_RESOURCE"};

	
	class CW_NOTEBLOCK_RESOURCE
	{
		idd = -1;
		onUnload = "uiNamespace setVariable ['cw_noteblock_resource', nil];";
		duration=0.1;  
		fadein=0;    
		name="CW_NOTEBLOCK_RESOURCE";
		onLoad = "uiNamespace setVariable ['cw_noteblock_resource', _this select 0];";

		class Controls
		{
			class cw_noteblock_background: cw_noteblock_picture
			{
				idc = 1200;
				text = "\cw_nineliner_and_notepad\Data\CW_Noteblock\Images\noteblock.paa";
				x = -0.0557292 * safezoneW + safezoneX;
				y = 0.26909 * safezoneH + safezoneY;
				w = 0.48125 * safezoneW;
				h = 0.747708 * safezoneH;
				moving = 1;
			};
			class cw_noteblock_edit: cw_noteblock_edit
			{
				idc = 1400;
				x = 0.0416667 * safezoneW + safezoneX;
				y = 0.307 * safezoneH + safezoneY;
				w = 0.303646 * safezoneW;
				h = 0.637751 * safezoneH;
			};
		};
	};
	
};
