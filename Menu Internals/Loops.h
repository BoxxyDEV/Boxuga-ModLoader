void OptionLoops()
{
	if (GodMode) // this states that if the boolean it should set the value to TRUE
	{
		SET_PLAYER_INVINCIBLE(PLAYER_ID(), true);
	}
	if (!GodMode)
	{
		SET_PLAYER_INVINCIBLE(PLAYER_ID(), false);
	}

	if (NeverWanted)
	{
		CLEAR_PLAYER_WANTED_LEVEL(PLAYER_ID());
	}

	if (FreezeTime)
	{
		PAUSE_CLOCK(true);
	}
	if (!FreezeTime)
	{
		PAUSE_CLOCK(false);
	}

	if (SuperJump)
	{
		SET_SUPER_JUMP_THIS_FRAME(PLAYER_ID());
	}

	if (DoNotRagdoll)
	{
		SET_PED_CAN_RAGDOLL(PLAYER_PED_ID(), false);
	}
	if (!DoNotRagdoll)
	{
		SET_PED_CAN_RAGDOLL(PLAYER_PED_ID(), true); // player should ragdoll when option is off
	}

	if (VehicleRepair)
	{
		int coolvehicle = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SET_VEHICLE_FIXED(coolvehicle);
	}

	if (NightVision)
	{
		if (ThermalVision)
		{
			NotifyMSG("Warning", "Thermal Gun Has Been Turned Off to make sure it will not break the game with both on");
			ThermalVision = false;
		}
		SET_NIGHTVISION(true);
	}
	if (!NightVision)
	{
		SET_NIGHTVISION(false);
	}

	if (ThermalVision)
	{
		if (NightVision)
		{
			NotifyMSG("Warning", "Night Vision Gun Has Been Turned Off to make sure it will not break the game with both on");
			NightVision = false;
		}

		SET_SEETHROUGH(true);
	}
	if (!ThermalVision)
	{
		SET_SEETHROUGH(false);
	}

	if (Dismap)
	{
		DISPLAY_RADAR(false);
	}
	if (!Dismap)
	{
		DISPLAY_RADAR(true);
	}


	if (MobileRadio)
	{
		SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
	}
	if (!MobileRadio)
	{
		SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);
	}

	if (InfinityAmmo)
	{
		SET_PED_INFINITE_AMMO_CLIP(PLAYER_PED_ID(), true);
	}
	if (!InfinityAmmo)
	{
		SET_PED_INFINITE_AMMO_CLIP(PLAYER_PED_ID(), false);
	}

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
}
