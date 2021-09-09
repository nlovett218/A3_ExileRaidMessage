cw_noteblock_fnc_open = 
{
	If !(isNil {cw_9liners_and_notepad_currentResource} OR cw_9liners_and_notepad_currentResource == "")exitWith {hint "You have to close the current sheed first!"; diag_log "Notepad: Other Menu Open"; };
	closeDialog 0;
	createDialog "CW_NOTEBLOCK";
	CW_NOTEPAD_OPEN = true;
	//_lastpage = call cw_noteblock_fnc_GetLastPage;
	//_pagetext = [_lastpage] call cw_noteblock_fnc_GetPageText;
	//cw_noteblock_currentPage = _lastpage;
	ctrlSetText [1400, ""];
	//ctrlSetText [1000, cw_noteblock_currentPage];
	//profileNamespace setVariable ["cw_noteblock_lastPage", cw_noteblock_currentPage];
	//hint format ["PAGE %1/50", cw_noteblock_currentPage];
	diag_log "Notepad opened";
};