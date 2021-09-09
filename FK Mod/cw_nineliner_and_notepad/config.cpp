
class CfgPatches {

	class CW_9LINERS_AND_NOTEPAD {
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.000000;
		requiredAddons[] = {"CBA_Extended_EventHandlers", "CBA_MAIN"};
		author = "Chief Wiggum";
	};
};

class cw_noteblock_text {
	access = 0;
	type = 0;
	idc = -1;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {1, 1, 1, 0.700000};
	text = "";
	fixedWidth = 0;
	x = 0;
	y = 0;
	h = 0.037000;
	w = 0.300000;
	style = 0;
	shadow = 0;
	font = "puristaMedium";
	SizeEx = 0.039210;
};

class cw_noteblock_button {
	access = 0;
	type = 1;
	text = "";
	colorText[] = {1, 1, 1, 1};
	colorDisabled[] = {0, 0, 0, 0};
	colorBackground[] = {0, 0, 0, 0};
	colorBackgroundDisabled[] = {0, 0, 0, 0};
	colorBackgroundActive[] = {0, 0, 0, 0};
	colorFocused[] = {0, 0, 0, 0};
	colorShadow[] = {0, 0, 0, 0};
	colorBorder[] = {0, 0, 0, 0};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter", 0.090000, 1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush", 0.090000, 1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick", 0.090000, 1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape", 0.090000, 1};
	style = 2;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	shadow = 0;
	font = "puristaMedium";
	sizeEx = 0.039210;
	offsetX = 0.003000;
	offsetY = 0.003000;
	offsetPressedX = 0.002000;
	offsetPressedY = 0.002000;
	borderSize = 0;
};

class cw_noteblock_edit {
	access = 0;
	type = 2;
	style = 528;
	x = 0;
	y = 0;
	h = 0.040000;
	w = 0.200000;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {0, 0, 0, 1};
	colorSelection[] = {1, 1, 1, 0.250000};
	colorDisabled[] = {1, 1, 1, 0.500000};
	font = "TahomaB";
	sizeEx = 0.040000;
	autocomplete = "";
	text = "";
	size = 0.200000;
	shadow = 1;
};

class cw_noteblock_picture {
	access = 0;
	type = 0;
	idc = -1;
	style = 48;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {1, 1, 1, 1};
	font = "TahomaB";
	sizeEx = 0;
	lineSpacing = 0;
	text = "";
	fixedWidth = 0;
	shadow = 0;
	x = 0;
	y = 0;
	w = 0.200000;
	h = 0.150000;
};

class CW_NOTEBLOCK {
	idd = 8888;
	movingenable = "true";
	onUnload = "CW_NOTEPAD_OPEN = false;";

	class Controls {

		class cw_noteblock_background: cw_noteblock_picture {
			idc = 1200;
			text = "\cw_nineliner_and_notepad\Data\CW_Noteblock\Images\noteblock.paa";
			x = "-0.0557292 * safezoneW + safezoneX";
			y = "0.26909 * safezoneH + safezoneY";
			w = "0.48125 * safezoneW";
			h = "0.747708 * safezoneH";
			moving = 1;
		};

		class cw_noteblock_edit: cw_noteblock_edit {
			idc = 1400;
			x = "0.0416667 * safezoneW + safezoneX";
			y = "0.307 * safezoneH + safezoneY";
			w = "0.303646 * safezoneW";
			h = "0.637751 * safezoneH";
			moving = 1;
		};

		class cw_noteblock_bttn_nextPage: cw_noteblock_button {
			idc = 1600;
			x = "0.310937 * safezoneW + safezoneX";
			y = "0.291081 * safezoneH + safezoneY";
			w = "0.034375 * safezoneW";
			h = "0.0219914 * safezoneH";
			//action = "call cw_noteblock_fnc_nextPage;";
		};

		class cw_noteblock_bttn_previousPage: cw_noteblock_button {
			idc = 1601;
			x = "0.0416667 * safezoneW + safezoneX";
			y = "0.291081 * safezoneH + safezoneY";
			w = "0.034375 * safezoneW";
			h = "0.0219914 * safezoneH";
			//action = "call cw_noteblock_fnc_previousPage;";
		};

		class cw_noteblock_bttn_save: cw_noteblock_button {
			idc = 1602;
			x = "0.3479 * safezoneW + safezoneX";
			y = "0.373 * safezoneH + safezoneY";
			w = "0.019 * safezoneW";
			h = "0.047 * safezoneH";
			action = "uiNamespace setVariable['KFB_raidMessage', ctrlText 1400]; closeDialog 0;";
		};

		class cw_noteblock_bttn_clearpage: cw_noteblock_button {
			idc = 1603;
			x = "0.3479 * safezoneW + safezoneX";
			y = "0.65 * safezoneH + safezoneY";
			w = "0.0155 * safezoneW";
			h = "0.054 * safezoneH";
			//action = "call cw_noteblock_fnc_clearPage;";
		};

		class cw_noteblock_bttn_clearall: cw_noteblock_button {
			idc = 1604;
			x = "0.3479 * safezoneW + safezoneX";
			y = "0.788 * safezoneH + safezoneY";
			w = "0.015 * safezoneW";
			h = "0.043 * safezoneH";
			action = "call cw_noteblock_fnc_clearPage;";
		};

		class cw_noteblock_bttn_close: cw_noteblock_button {
			idc = 1605;
			x = "0.3479 * safezoneW + safezoneX";
			y = "0.931 * safezoneH + safezoneY";
			w = "0.016 * safezoneW";
			h = "0.045 * safezoneH";
			action = "ctrlSetText [1400, '']; uiNamespace setVariable['KFB_raidMessage', '']; closeDialog 0; CW_NOTEPAD_OPEN = false;";
		};

		class cw_noteblock_bttn_enableContros_1: cw_noteblock_button {
			idc = 1606;
			x = "0.365* safezoneW + safezoneX";
			y = "-5 * safezoneH + safezoneY";
			w = "10 * safezoneW";
			h = "10 * safezoneH";
			//onMouseButtonClick = "execVM ""\cw_nineliner_and_notepad\Data\CW_Noteblock\Scripts\createResource.sqf"";
			onMouseButtonDblClick = "closeDialog 0; CW_NOTEPAD_OPEN = false;";
			tooltip = "CLICK: ENABLE CONTROLS | DBL CLICK: CLOSE";
			tooltipColorText[] = {1, 0, 0, 1};
		};

		class cw_noteblock_bttn_enableContros_2: cw_noteblock_button {
			idc = 1607;
			x = "-10 * safezoneW + safezoneX";
			y = "-5 * safezoneH + safezoneY";
			w = "10 * safezoneW";
			h = "10 * safezoneH";
			//onMouseButtonClick = "execVM ""\cw_nineliner_and_notepad\Data\CW_Noteblock\Scripts\createResource.sqf"";
			onMouseButtonDblClick = "closeDialog 0; CW_NOTEPAD_OPEN = false;";
			tooltip = "CLICK: ENABLE CONTROLS | DBL CLICK: CLOSE";
			tooltipColorText[] = {1, 0, 0, 1};
		};

		class cw_noteblock_bttn_enableContros_3: cw_noteblock_button {
			idc = 1608;
			x = "-1.0557292 * safezoneW + safezoneX";
			y = "-9.715 * safezoneH + safezoneY";
			w = "10 * safezoneW";
			h = "10 * safezoneH";
			//onMouseButtonClick = "execVM ""\cw_nineliner_and_notepad\Data\CW_Noteblock\Scripts\createResource.sqf"";
			onMouseButtonDblClick = "closeDialog 0; CW_NOTEPAD_OPEN = false;";
			tooltip = "CLICK: ENABLE CONTROLS | DBL CLICK: CLOSE";
			tooltipColorText[] = {1, 0, 0, 1};
		};

		class cw_noteblock_bttn_enableContros_4: cw_noteblock_button {
			idc = 1609;
			x = "-0.0557292 * safezoneW + safezoneX";
			y = "0.995 * safezoneH + safezoneY";
			w = "10 * safezoneW";
			h = "10 * safezoneH";
			//onMouseButtonClick = "execVM ""\cw_nineliner_and_notepad\Data\CW_Noteblock\Scripts\createResource.sqf"";
			onMouseButtonDblClick = "closeDialog 0; CW_NOTEPAD_OPEN = false;";
			tooltip = "CLICK: ENABLE CONTROLS | DBL CLICK: CLOSE";
			tooltipColorText[] = {1, 0, 0, 1};
		};
	};
};


class RscTitles {
	titles[] = {"CW_NOTEBLOCK_RESOURCE"};


	class CW_NOTEBLOCK_RESOURCE {
		idd = -1;
		onUnload = "uiNamespace setVariable ['cw_noteblock_resource', nil];";
		duration = 0.100000;
		fadein = 0;
		name = "CW_NOTEBLOCK_RESOURCE";
		onLoad = "uiNamespace setVariable ['cw_noteblock_resource', _this select 0];";

		class Controls {

			class cw_noteblock_background: cw_noteblock_picture {
				idc = 1200;
				text = "\cw_nineliner_and_notepad\Data\CW_Noteblock\Images\noteblock.paa";
				x = "-0.0557292 * safezoneW + safezoneX";
				y = "0.26909 * safezoneH + safezoneY";
				w = "0.48125 * safezoneW";
				h = "0.747708 * safezoneH";
				moving = 1;
			};

			class cw_noteblock_edit: cw_noteblock_edit {
				idc = 1400;
				x = "0.0416667 * safezoneW + safezoneX";
				y = "0.307 * safezoneH + safezoneY";
				w = "0.303646 * safezoneW";
				h = "0.637751 * safezoneH";
			};
		};
	};
};

class Extended_PostInit_EventHandlers {
	CW_9LINERS_AND_NOTEPAD_PostInit = "call compile preprocessFile '\cw_nineliner_and_notepad\Data\init.sqf'";
};
