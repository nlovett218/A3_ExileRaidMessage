//initServerFile
private ['_code', '_function', '_file'];

if (!hasInterface && isServer) then 
{
	{
	    _code = '';
	    _function = _x select 0;
	    _file = _x select 1;

	    _code = compileFinal (preprocessFileLineNumbers _file);

	    missionNamespace setVariable [_function, _code];
	}
	forEach
	[
	];
};

if (hasInterface && !isServer) then 
{
	{
	    _code = '';
	    _function = _x select 0;
	    _file = _x select 1;

	    _code = compileFinal (preprocessFileLineNumbers _file);

	    missionNamespace setVariable [_function, _code];
	}
	forEach
	[
	    ['ExileClient_RaidMessage_network_showRaidMessage', 'custom\territory\ExileClient_RaidMessage_network_showRaidMessage.sqf']
	];
}

