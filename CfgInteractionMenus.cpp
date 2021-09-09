
	class Flag
	{
		targetType = 2;
		target = "Exile_Construction_Flag_Static";

		class Actions
		{
			class ReadMessage: ExileAbstractAction
			{
				title = "Read Raid Message";
				condition = "((ExileClientInteractionObject getvariable ['ExileFlagStolen',0]) isEqualTo 1 && (player call ExileClient_util_world_isInOwnTerritory))";
				action = "_this spawn ExileClient_RaidMessage_network_showRaidMessage";
			};
		};
	};

	