disableSerialization;
params["_flag"];

if (isNull _flag) exitWith {};


private _raidMessage = _flag getVariable["ExileRaidMessage", ''];

if (_raidMessage isEqualTo '') exitWith { systemChat "No raid message to display!"; };

call cw_noteblock_fnc_open;
ctrlSetText [1400, _raidMessage];

waitUntil { sleep 0.05; isNull (findDisplay 1400) || !alive player };
//closeDialog 8888;

uiNamespace setVariable['KFB_raidMessage', ''];
