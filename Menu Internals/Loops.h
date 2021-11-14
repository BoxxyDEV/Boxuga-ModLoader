void OptionLoops()
{
	

	if (Moneydrop)
	{
		vector3 playerlocation = GET_ENTITY_COORDS(PLAYER_PED_ID(), true);
		if (MoneyBagType == 1)
		{
			CREATE_MONEY_PICKUPS(vector3(playerlocation.x, (playerlocation.y + 3), playerlocation.z), 40000, 1, PICKUP_MONEY_CASE);
		}
		if (MoneyBagType == 2)
		{
			CREATE_MONEY_PICKUPS(vector3(playerlocation.x, (playerlocation.y + 3), playerlocation.z), 40000, 1, PICKUP_MONEY_PAPER_BAG);
		}
	}


	if (UnlimitedSpecialAbility)
	{
		SPECIAL_ABILITY_FILL_METER(PLAYER_ID(), true);
	}

	if (UseJamesRebornModLoaderEditorFile)
	{
		GET_HUD_COLOUR(HUD_COLOUR_NET_PLAYER1_DARK, &BannerR, &BannerG, &BannerB, &BannerA); // sets the colors to whats found in the HudColor.dat
		GET_HUD_COLOUR(HUD_COLOUR_NET_PLAYER2_DARK, &BackgroundR, &BackgroundG, &BackgroundB, &BackgroundA);
		GET_HUD_COLOUR(HUD_COLOUR_NET_PLAYER3_DARK, &ScrollbarR, &ScrollbarG, &ScrollbarB, &ScrollbarA);
		GET_HUD_COLOUR(HUD_COLOUR_NET_PLAYER4_DARK, &TitleR, &TitleG, &TitleB, &Rando);
		GET_HUD_COLOUR(HUD_COLOUR_NET_PLAYER5_DARK, &UnselectedTextR, &UnselectedTextG, &UnselectedTextB, &Rando);
		GET_HUD_COLOUR(HUD_COLOUR_NET_PLAYER6_DARK, &SelectedTextR, &SelectedTextG, &SelectedTextB, &Rando);
	}
	if (SyncTime) // if sync time it will loop it
	{
		int y; // sets up local intergers 
		int m;
		int d;
		int hour;
		int minute;
		int secondd;
		GET_LOCAL_TIME(&y, &m, &d, &hour, &minute, &secondd); // gets the system time
		SET_CLOCK_TIME(hour, minute, secondd); // sets it to the system time
	}


	if (ShakeMode)
	{
		SHAKE_GAMEPLAY_CAM("LARGE_EXPLOSION_SHAKE", 1);
	}

	if (NeverWanted)
	{
		CLEAR_PLAYER_WANTED_LEVEL(PLAYER_ID());
	}
	if (SuperJump)
	{
		SET_SUPER_JUMP_THIS_FRAME(PLAYER_ID());
	}
	if (VehicleRepair)
	{
		int coolvehicle = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SET_VEHICLE_FIXED(coolvehicle);
	}
}























