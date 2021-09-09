/**
 * ExileServer_system_territory_network_flagStolenRequest
 *
 * Exile Mod
 * www.exilemod.com
 * © 2015 Exile Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 */
 
private["_sessionID","_parameters","_flag", "_raidmessage", "_filter", "_ownerID", "_playerObject","_databaseID","_level","_flagPosition","_spawnRadius","_weaponHolderPosition","_weaponHolder","_logging","_territoryLog"];
_sessionID = _this select 0;
_parameters = _this select 1;
_flag = _parameters select 0;

//Make sure to edit CfgNetworkMessages
///////
_raidmessage = _parameters select 1;
///////


try
{
	_playerObject = _sessionID call ExileServer_system_session_getPlayerObject;
	if (isNull _playerObject) then
	{
		throw "Player Object NULL";
	};
	if ((_flag getVariable ["ExileFlagStolen", 0]) isEqualTo 1) then 
	{
		throw "Flag already stolen!";
	};
	if ((_playerObject distance2D _flag) > getNumber(missionConfigFile >> "CfgTerritories" >> "flagStealMaxDistance")) then
	{
		throw "You are too far away!";
	};

	////////////
	_filter = getText (missionConfigFile >> "CfgClans" >> "allowedRaidMessageChar");
	_raidmessage = [_raidmessage, _filter] call BIS_fnc_filterString;
	////////////


	_databaseID = _flag getVariable ["ExileDatabaseID",0];
	_level = _flag getVariable ["ExileTerritoryLevel",0];
	_flagPosition = getPosATL _flag;
	_flagPosition set[2, 0];
	_spawnRadius = 3;
	_weaponHolderPosition = getPosATL _playerObject;
	_weaponHolder = createVehicle ["GroundWeaponHolder", _weaponHolderPosition, [], 0, "CAN_COLLIDE"];
	_weaponHolder setPosATL _weaponHolderPosition;
	_weaponHolder addMagazineCargoGlobal [format["Exile_Item_FlagStolen%1", _level], 1];
	_flag setVariable ["ExileFlagStolen", 1, true];

	///////////
	_flag setVariable ["ExileRaidMessage", _raidmessage, true];
	///////////

	_ownerID = _flag getVariable["ExileOwnerUID", ""];

	///////////
	if (_raidmessage != "") then {
		format["insertRaidMessageHistory:%1:%2:%3:%4",getPlayerUID _playerObject,_raidmessage,_databaseID,_ownerID] call ExileServer_system_database_query_fireAndForget;
	};
	///////////

	format["flagStolen:%1:%2:%3",getPlayerUID _playerObject,_raidmessage,_databaseID] call ExileServer_system_database_query_fireAndForget;
	_logging = getNumber(configFile >> "CfgSettings" >> "Logging" >> "territoryLogging");
	if (_logging isEqualTo 1) then
	{
		_territoryLog = format ["PLAYER ( %1 ) %2 STOLE A LEVEL %3 FLAG FROM TERRITORY #%4",getPlayerUID _playerObject,_playerObject,_level,_databaseID];
		"extDB3" callExtension format["1:TERRITORY:%1",_territoryLog];
	};
	_flag call ExileServer_system_xm8_sendFlagStolen;
}
catch
{
	[_sessionID, "toastRequest", ["ErrorTitleAndText", ["Failed to steal!", _exception]]] call ExileServer_system_network_send_to;
};
true
