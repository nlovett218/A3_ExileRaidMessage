/**
 * ExileClient_action_stealFlag_completed
 *
 * Exile Mod
 * www.exilemod.com
 * © 2015 Exile Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 */
disableSerialization;

private["_flagObject", "_raidMessage"];
_flagObject = _this;

//Do base raid notes
_result = ["Do you want to leave behind a raid message? This action cannot be performed after closing this dialog.", "Raid Message", "Hell yeah!", "Hell no!"] call BIS_fnc_guiMessage;
waitUntil {uiSleep 0.05; !isNil "_result" };

_raidMessage = "";

if (_result) then {

	private _raidMessagePrompt = createDialog "CW_NOTEBLOCK";
	//ctrlSetText [1400, ""];
	CW_NOTEPAD_OPEN = true;
	ctrlSetText [1400, "Enter your raid message here... Remember the rules..."];
	waitUntil {!CW_NOTEPAD_OPEN || !alive player };

	if (isNull (findDisplay 1400)) then {
		diag_log "RaidMessage: Display is null, continue";
	};

	if !(alive player) exitWith {
		diag_log "RaidMessage: Player not alive when attempted to steal flag!";
	};

	_raidMessage = uiNamespace getVariable['KFB_raidMessage', ''];
};

_flagObject setFlagOwner player;
["flagStolenRequest", [_flagObject, _raidMessage]] call ExileClient_system_network_send;