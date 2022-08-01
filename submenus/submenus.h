#pragma region SettingsPages
void titlemenu()
{
	// title
	if (CurrentOption == 4)
	{
		ColorChanger();
	}
	DrawBackground(4);
	AddTitle(TitleColors_lang);
	AddIntOptionSettings(Red_lang, &TitleR, 0, 255, false);
	AddIntOptionSettings(Green_lang, &TitleG, 0, 255, false);
	AddIntOptionSettings(Blue_lang, &TitleB, 0, 255, false);
	AddStringOption(PremadeColors_lang, ColorSelect_lang, &TitleColor, 1, 5, Title_Default_lang, Black_lang, Purple_lang, Green_lang, Red_lang, "", "", "", "", "");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void bannermenu()
{ // banner
	if (CurrentOption == 5)
	{
		ColorChanger();
	}
	DrawBackground(5);
	AddTitle(BannerColors_lang);
	AddIntOptionSettings(Red_lang, &BannerR, 0, 255, false);
	AddIntOptionSettings(Green_lang, &BannerG, 0, 255, false);
	AddIntOptionSettings(Blue_lang, &BannerB, 0, 255, false);
	AddIntOptionSettings(Alpha_lang, &BannerA, 0, 255, false);
	AddStringOption(PremadeColors_lang, ColorSelect_lang, &BannerColor, 1, 5, Banner_Default_lang, White_lang, Black_lang, Green_lang, Red_lang, "", "", "", "", "");
	{
		DrawInstructionalButtons();
	}
}

void backgroundmenu()
{ // background
	if (CurrentOption == 5)
	{
		ColorChanger();
	}
	DrawBackground(5);
	AddTitle(BannerColors_lang);
	AddIntOptionSettings(Red_lang, &BackgroundR, 0, 255, false);
	AddIntOptionSettings(Green_lang, &BackgroundG, 0, 255, false);
	AddIntOptionSettings(Blue_lang, &BackgroundB, 0, 255, false);
	AddIntOptionSettings(Alpha_lang, &BackgroundA, 0, 255, false);
	AddStringOption(PremadeColors_lang, ColorSelect_lang, &BackgroundColor, 1, 5, Background_Default_lang, Purple_lang, White_lang, Green_lang, Red_lang, "", "", "", "", "");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void selectedtextmenu()
{ // selected text
	if (CurrentOption == 4)
	{
		ColorChanger();
	}
	DrawBackground(4);
	AddTitle(SelectedTextColors_lang);
	AddIntOptionSettings(Red_lang, &SelectedTextR, 0, 255, false);
	AddIntOptionSettings(Green_lang, &SelectedTextG, 0, 255, false);
	AddIntOptionSettings(Blue_lang, &SelectedTextB, 0, 255, false);
	AddStringOption(PremadeColors_lang, ColorSelect_lang, &SelectedTextColor, 1, 5, Selected_Text_Default_lang, Purple_lang, Black_lang, Green_lang, Red_lang, "", "", "", "", "");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void unselectedtextmenu()
{ // unselected text
	if (CurrentOption == 4)
	{
		ColorChanger();
	}
	DrawBackground(4);
	AddTitle(UnselectedTextColors_lang);
	AddIntOptionSettings(Red_lang, &UnselectedTextR, 0, 255, false);
	AddIntOptionSettings(Green_lang, &UnselectedTextG, 0, 255, false);
	AddIntOptionSettings(Blue_lang, &UnselectedTextB, 0, 255, false);
	AddStringOption(PremadeColors_lang, ColorSelect_lang, &UnselectedTextColor, 1, 5, Unselected_Text_Default_lang, Purple_lang, Black_lang, Green_lang, Red_lang, "", "", "", "", "");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void ScrollBarRGB()
{
	if (CurrentOption == 5)
	{
		ColorChanger();
	}
	DrawBackground(5);
	AddTitle(ScrollBar_lang);
	AddIntOptionSettings(Red_lang, &ScrollbarR, 0, 255, false);
	AddIntOptionSettings(Green_lang, &ScrollbarG, 0, 255, false);
	AddIntOptionSettings(Blue_lang, &ScrollbarB, 0, 255, false);
	AddIntOptionSettings(Alpha_lang, &ScrollbarA, 0, 255, false);
	AddStringOption(PremadeColors_lang, ColorSelect_lang, &ScrollbarColor, 1, 5, ScrollBar_Default_lang, Purple_lang, Black_lang, Green_lang, Red_lang, "", "", "", "", "");
}

void colr()
{ // color changer menu //
	DrawBackground(8);
	AddTitle("Colors");
	AddSubtext("Brighten up your world");
	AddSubmenuOption(TitleColors_lang, TitleColors_MSG_lang, (titlemenu));
	AddSubmenuOption(BannerColors_lang, BannerColors_MSG_lang, (bannermenu));
	AddSubmenuOption(BackgroundColors_lang, BackgroundColors_MSG_lang, (backgroundmenu));
	AddSubmenuOption(SelectedTextColors_lang, SelectedTextColors_MSG_lang, (selectedtextmenu));
	AddSubmenuOption(UnselectedTextColors_lang, UnselectedTextColors_MSG_lang, (unselectedtextmenu));
	AddSubmenuOption(ScrollBar_lang, ScrollBar_MSG_lang, (ScrollBarRGB));
	AddBoolOption(JRHUDCOLORS_lang, &UseJamesRebornModLoaderEditorFile, "Use values from a modified HudColor.dat created by James");
	ResetColors(ResetColors_lang);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void funer()
{
	DrawBackground(4);
	AddTitle("Friends");
	AddSubtext("Good Friends");
	NotifyOption("FazeModz", "FazeModz", "Faze Modz is a good place to learn");
	NotifyOption("Lush Modz", "Lush Modz", "Thank you to lush modz for being a good friend");
	NotifyOption("James Reborn", "James Reborn", "Thank you for being friends even with my stupid ideas");
	NotifyOption("TheRouletteBoi", "TheRouletteboi", "Thanks for being there and talking to me");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void cred()
{
	DrawBackground(4);
	AddTitle(Credits_lang);
	AddSubmenuOption("Friends", "All my friends they all be very good", (funer));
	NotifyOption("Louay / for settings", "Louay", "Thanks for making such good mods");
	NotifyOption("NotYourDope / Base", "NotYourDope", "NotYourDope is a beast");
	NotifyOption("JakeModz89 / Video Tutorials", "JakeModz", "youtube.com/jakemodz89");
}
#pragma endregion

#pragma region Ingameoptions
void TimeOptions()
{
	if (CurrentOption == 1)
	{
		if (FreezeTime)
		{
			if (FreezeTime)
			{
				PAUSE_CLOCK(true);
			}
			if (!FreezeTime)
			{
				PAUSE_CLOCK(false);
			}
		}
	}
	DrawBackground(9);
	AddTitle(Time_lang);
	AddBoolOption(FreezeTime_lang, &FreezeTime, "Makes time stop");
	AddBoolOption(SyncTime_lang, &SyncTime, "Make time sync with the system");
	ChangeTime(Morning_lang, 7, 0, 0, 1);
	ChangeTime(Midday_lang, 12, 0, 0, 1);
	ChangeTime(Afternoon_lang, 15, 0, 0, 1);
	ChangeTime(Night_lang, 20, 0, 0, 1);
	ChangeTime(Midnight_lang, 0, 0, 0, 1);
	ChangeTime(PlusHour_lang, 1, 0, 0, 2);
	ChangeTime(NegativeHour_lang, -1, 0, 0, 2);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void WeatherOptions()
{
	DrawBackground(11);
	AddTitle(Weather_lang);
	AddSubtext("Your a Bloody God");
	ChangeWeather("Sunny", "EXTRASUNNY");
	ChangeWeather("Clear", "CLEAR");
	ChangeWeather("Cloudy", "CLOUDS");
	ChangeWeather("Fog", "FOGGY");
	ChangeWeather("Rainy", "RAIN");
	ChangeWeather("Smoggy", "SMOG");
	ChangeWeather("Blizzard", "BLIZZARD");
	ChangeWeather("Clearing", "CLEARING");
	ChangeWeather("Thunder", "THUNDER");
	ChangeWeather("Light Snow", "SNOWLIGHT");
	ChangeWeather("Overcast", "OVERCAST");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}



void SelfOptions()
{
	if (CurrentOption == 1)
	{
		if (GodMode) // this states that if the boolean it should set the value to TRUE
		{
			SET_PLAYER_INVINCIBLE(PLAYER_ID(), true);
		}
		if (!GodMode)
		{
			SET_PLAYER_INVINCIBLE(PLAYER_ID(), false);
		}
	}
	if (CurrentOption == 2)
	{
		if (Vanish)
		{
			SET_ENTITY_VISIBLE(PLAYER_PED_ID(), false, false);
		}
		if (!Vanish)
		{
			SET_ENTITY_VISIBLE(PLAYER_PED_ID(), true, false);
		}
	}
	if (CurrentOption == 3)
	{
		if (DoNotRagdoll)
		{
			SET_PED_CAN_RAGDOLL(PLAYER_PED_ID(), false);
		}
		if (!DoNotRagdoll)
		{
			SET_PED_CAN_RAGDOLL(PLAYER_PED_ID(), true); // player should ragdoll when option is off
		}
	}
	if (CurrentOption == 5)
	{
		if (MobileRadio)
		{
			SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
		}
		if (!MobileRadio)
		{
			SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);
		}
	}
	if (CurrentOption == 12)
	{
		if (WasXJustPressed(177))
		{
			SET_ENTITY_HEALTH(PLAYER_PED_ID(), 200);
			SET_PED_ARMOUR(PLAYER_PED_ID(), 100);
		}
		infoboxText(GiveMaxHealthAndArmor_info_lang);
	}
	DrawBackground(12);
	AddTitle(SelfTitle_lang);
	AddSubtext(SelfTitle_Sub_lang);
	AddBoolOption(GodMode_lang, &GodMode, GodMode_Info_lang); // gives player god mode
	AddBoolOption(Vanish_lang, &Vanish, Vanish_info_lang); // toggles invisable
	AddBoolOption(NoRagdoll_lang, &DoNotRagdoll, NoRagdoll_info_lang); // toggles no ragdoll
	AddBoolOption(SuperJump_lang, &SuperJump, SuperJump_info_lang); // allows player to jump very high
	AddBoolOption(MobileRadio_lang, &MobileRadio, MobileRadio_info_lang); // toggle for Mobile Radio
	AddBoolOption(Unlimited_Special_Ability_lang, &UnlimitedSpecialAbility, Unlimited_Speical_Ability_info_lang);
	AddBoolOption(NeverWanted_lang, &NeverWanted, NeverWanted_info_lang); // No wanted level 
	AddBoolOption(ShakeMode_lang, &ShakeMode, ShakeMode_info_lang); // pretty much shake
	WantedLVL(WantedLevel_lang, WantedLevel_info_lang); // allows the user to change there wanted level
	AddBoolOption(MoneyDrop_lang, &Moneydrop, MoneyDrop_info_lang);
	Suidcide(Suicide_lang, Suicide_info_lang);
	AddOption(GiveMaxHealthAndArmor_lang);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void SpawnCarOptions()
{
	DrawBackground(3);
	AddTitle(SpawnOptions_lang);
	AddBoolOption(SpawnInCar_lang, &Spawnincar, SpawninCar_info_lang);
	AddBoolOption(DeleteOldVehicle_lang, &DeleteOldVehicle, DeleteOldVehicle_info_lang);
	AddBoolOption(SpawnNotification_lang, &CarSpawnNotification, SpawnNotification_info_lang);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}


void spawner()
{
	DrawBackground(22);
	AddTitle(VehicleSpawner_lang);
	AddSubmenuOption(SpawnOptions_lang, SpawnNotification_info_lang, (SpawnCarOptions));
	AddSubmenuOption("Super", "Displays all cars that you can spawn from the super class", (SuperCarSpawner));
	AddSubmenuOption("Sports", "Displays all cars that you can spawn from the sports class", (SportsCarSpawner));
	AddSubmenuOption("Coupes", "Displays all cars that you can spawn from the coupes class", (CoupesSpawner));
	AddSubmenuOption("Compacts", "Displays all cars that you can spawn from the Compacts class", (CompactsSpawner));
	AddSubmenuOption("Sedans", "Displays all cars that you can spawn from the Sedans class", (SedansSpawner));
	AddSubmenuOption("Sports Classics", "Displays all cars that you can spawn from the Sports Classics class", (SportsClassicsSpawner));
	AddSubmenuOption("Mussle", "Displays all cars that you can spawn from the Mussle class", (MussleSpawnner));
	AddSubmenuOption("SUVs", "Displays all cars that you can spawn from the SUVs class", (SUVsSpawner));
	AddSubmenuOption("Vans", "Displays all cars that you can spawn from the Vans class", (VansSpawner));
	AddSubmenuOption("Off-Road", "Displays all cars that you can spawn from the OffRoad class", (OffRoadSpawner));
	AddSubmenuOption("Commercial", "Displays all cars that you can spawn from the Commercial class", (CommercialSpawner));
	AddSubmenuOption("Service", "Displays all cars that you can spawn from the Service class", (ServiceSpawner));
	AddSubmenuOption("Utility", "Displays all cars that you can spawn from the Utility class", (UtilitySpawner));
	AddSubmenuOption("Industrial", "Displays all cars that you can spawn from the Industrial class", (IndustrialSpawner));
	AddSubmenuOption("Emergency", "Displays all cars that you can spawn from the Emergency class", (EmergencySpawner));
	AddSubmenuOption("Military", "Displays all cars that you can spawn from the Military class", (MilitarySpawner));
	AddSubmenuOption("Motorbikes", "Displays all cars that you can spawn from the Motorbikes class", (MotorbikesSpawner));
	AddSubmenuOption("Bikes", "Displays all cars that you can spawn from the bike class", (bikespawner));
	AddSubmenuOption("Planes", "Displays all cars that you can spawn from the Plane class", (PlanesSpawner));
	AddSubmenuOption("Helicopters", "Displays all cars that you can spawn from the Plane class", (HelicoptersSpawner));
	AddSubmenuOption("Boat", "Displays all cars that you can spawn from the Boat class", (BoatSpawner));
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void VehicleOptions()
{ // set up set vehicle number plate SET_VEHICLE_NUMBER_PLATE_TEXT

	DrawBackground(5);
	AddTitle(Vehicle_Options_lang);
	AddSubtext(Vehicle_Options_lang);
	AddSubmenuOption(VehicleSpawner_lang, VehicleSpawner_MSG_lang, (spawner));
	AddBoolOption(VehicleGodMode_lang, &VehicleRepair, VehicleGodMode_info_lang);
	carfix(VehicleFix_lang);
	killvehicle(VehicleDestroy_lang);
	VehOpt(CustomNumberPlate_lang, 1); // fix and test
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void weaponoptions()
{
	if (CurrentOption == 3)
	{
		if (InfinityAmmo)
		{
			SET_PED_INFINITE_AMMO_CLIP(PLAYER_PED_ID(), true);
		}
		if (!InfinityAmmo)
		{
			SET_PED_INFINITE_AMMO_CLIP(PLAYER_PED_ID(), false);
		}
	}
	DrawBackground(6);
	AddTitle(WeaponTitle_lang);
	AddSubtext(WeaponTitle_Sub_lang);
	GiveAllWeapons(GiveAllWeapons_lang);
	RemoveWeapons(RemoveAllWeapons_lang);
	AddBoolOption(InfiniteAmmo_lang, &InfinityAmmo, InfiniteAmmo_info_lang);
	AddBoolOption(TeleportGun_lang, &TPGun, TeleportGun_info_lang);
	AddBoolOption(ExplosiveAmmo_lang, &ExplosiveAmmo, ExplosiveAmmo_info_lang);
	AddBoolOption(SuperPunch_lang, &SuperPunch, SuperPunch_info_lang);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void miscgame()
{
	if (CurrentOption == 3)
	{
		if (Dismap)
		{
			DISPLAY_RADAR(false);
		}
		if (!Dismap)
		{
			DISPLAY_RADAR(true);
		}
	}
	if (CurrentOption == 4)
	{
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
	}
	if (CurrentOption == 5)
	{
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
	}
	DrawBackground(5);
	AddTitle(Misc_lang);
	AddSubmenuOption(Time_lang, Time_MSG_lang, (TimeOptions));
	AddSubmenuOption(Weather_lang, Weather_MSG_lang, (WeatherOptions));
	AddBoolOption(DisableMap_lang, &Dismap, DisableMap_info_lang);
	AddBoolOption(ThermalVision_lang, &ThermalVision, NULL);
	AddBoolOption(NightVision_lang, &NightVision, NULL);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}
#pragma endregion


void ModMenus()
{
	DrawBackground(6);
	AddTitle("Menus");
	AddSubtext("Mod Me Up");
	AddScriptOption("AP ii Intense", "rock_menu2", 2024, R1, Square, "Ap ii Intense Loaded", "AP ii Intense Deactivated");
	AddScriptOption("Inimitable", "Inimitable", 1024, R1, DpadDown, "Inimitable Loaded", "Inimitable Deactivated");
	AddScriptOption("Ultimate Teleport", "Tgsaudoiz", 1820, R1, Circle, "Ultimate Teleport Loaded", "Ultimate Teleport Deactivated");
	AddScriptOption("ProjectCL", "ProjectCL", 1820, DpadRight, Square, "ProjectCL Loaded", "ProjectCL Deactivated");
	AddScriptOption("Project Unknown", "Unknown", 1024, L1, Square, "Project Unknown Loaded", "Project Unknown Deactivated");
	AddScriptOption("iLLuminate", "iLLuminate", 1024, DpadRight, Cross, "iLLuminate Loaded", "iLLuminate Deactivated");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void Misc()
{
	// need to add a misc menu
	DrawBackground(4);
	AddTitle(Misc_Scripts_lang);
	AddScriptOption("Meteor Shower", "Meteor_Shower", 1024, Nothing, Nothing, "Meteors Incoming Coming to hit THE SAN ANDREAS AREA", "Meteor Shower has finished");
	AddScriptOption("Funny Car Spawner", "App7e", 1820, R1, Square, "Loaded Funny Car Spawner", "Unloaded Funny Car Spawner");
	AddScriptOption("James Reborn", "JRrecovery", 2552, DpadRight, R3Press, "James Reborn Recovery Loaded", "James Reborn Recovery Deactivated");
	AddScriptOption("Danii X Modz", "Recoveryv2", 1820, L1, Circle, "Danii X Modz Loaded", "Danii X Modz Deactivated");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}


void Setx()
{
	DrawBackground(12);
	AddTitle(Settings_lang);
	if (CurrentOption == 4)
	{
		BackgroundChanger();
	}
	AddSubmenuOption(Colors_lang, Colors_MSG_lang, (colr));
	AddStringOption(Base_lang, Base_info_lang, &base, 1, 2, "NotYourDope", "LTS", "", "", "", "", "", "", "", "");
	AddStringOption(ToggleButtons_lang, ToggleButtons_info_lang, &ToggleButtons, 1, 7, "Boxuga", "CheckBox", "Caution", "Weed", "Flags", "Thumbs Up/Down", "Text", "", "", "");
	AddIntOptionSettings(Background_lang, &background, 1, 10, false);
	AddBoolOption(TitleOutline_lang, &TextOutlineTitle, "");
	AddBoolOption(OptionsOutline_lang, &TextOutlineOptions, "");
	AddBoolOption(OptionCountOutline_lang, &TextOutlineOptionCount, "");
	AddBoolOption(SmoothScroll_lang, &SmoothScrolling, "");
	AddBoolOption(LeftSided_lang, &LeftSided, "");
	AddBoolOption(BackgroundImage_lang, &bgimage, "");
	AddBoolOption(InfoBox_lang, &InfoBox, InfoBox_info_lang);
	AddCustomScriptOption();
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void ModMenusPS()
{
	DrawBackground(6);
	AddTitle(ModMenus_lang);
	AddScriptOption("AP ii Intense", "rock_menu2", 2024, R1, Square, "Ap ii Intense Loaded", "AP ii Intense Deactivated");
	AddScriptOption("Inimitable", "Inimitable", 1024, R1, DpadDown, "Inimitable Loaded", "Inimitable Deactivated");
	AddScriptOption("Ultimate Teleport", "Tgsaudoiz", 1820, R1, Circle, "Ultimate Teleport Loaded", "Ultimate Teleport Deactivated");
	AddScriptOption("ProjectCL", "ProjectCL", 1820, DpadRight, Square, "ProjectCL Loaded", "ProjectCL Deactivated");
	AddScriptOption("Project Unknown", "Unknown", 1024, L1, Square, "Project Unknown Loaded", "Project Unknown Deactivated");
	AddScriptOption("iLLuminate", "iLLuminate", 1024, DpadRight, Cross, "iLLuminate Loaded", "iLLuminate Deactivated");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void MiscPS()
{
	// need to add a misc menu
	DrawBackground(4);
	AddTitle(Misc_lang);
	AddScriptOption("Meteor Shower", "Meteor_Shower", 1024, Nothing, Nothing, "Meteors Incoming Coming to hit THE SAN ANDREAS AREA", "Meteor Shower has finished");
	AddScriptOption("Funny Car Spawner", "App7e", 1820, R1, Square, "Loaded Funny Car Spawner", "Unloaded Funny Car Spawner");
	AddScriptOption("James Reborn", "JRrecovery", 2552, DpadRight, R3Press, "James Reborn Recovery Loaded", "James Reborn Recovery Deactivated");
	AddScriptOption("Danii X Modz", "Recoveryv2", 2024, L1, Circle, "Danii X Modz Loaded", "Danii X Modz Deactivated");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void Stores()
{
	DrawBackground(27);
	AddTitle("Shops");
	TeleportOption("Vanilla Unicorn", vector3(106, -1331, 29));
	TeleportOption("Ammunation - Sandy Shores", vector3(1707, 3743, 33));
	TeleportOption("Ammunation - Hawick", vector3(240, -46, 69)); // 69 ha nice
	TeleportOption("Ammunation - La Mesa", vector3(843, -1021, 27));
	TeleportOption("Ammunation - Paleto Bay", vector3(-321, 6073, 31));
	TeleportOption("Ammunation - Little Seoul", vector3(-1317, -389, 36));
	TeleportOption("Ammunation - Great Chaparral", vector3(-1109, 2685, 18));
	TeleportOption("Ammunation - Chumash", vector3(-3156, 1083, 20));
	TeleportOption("Ammunation - Tataviam Mountains", vector3(2570, 307, 108));
	TeleportOption("Discount Store - Stawberry", vector3(84, -1393, 29));
	TeleportOption("Discount Store - Grand Senora Desert", vector3(1193, 2694, 37));
	TeleportOption("Discount Store - Grapeseed", vector3(1679, 4820, 41));
	TeleportOption("Discount Store - Great Chaparral", vector3(-1090, 2700, 19));
	TeleportOption("Discount Store - Paleto Bay", vector3(-2, 6521, 31));
	TeleportOption("Binco - Vespucci Canals", vector3(84, -1393, 29));
	TeleportOption("Binco - Textile City", vector3(413, -812, 29));
	TeleportOption("Ponsonbys - Rockford Hills", vector3(-719, -160, 37));
	TeleportOption("Ponsonbys - Morningwood", vector3(-1458, -230, 49));
	TeleportOption("Ponsonbys - Burton", vector3(-150, -304, 39));
	TeleportOption("Suburban - Del Perro", vector3(-1210, -784, 17));
	TeleportOption("Suburban - Harmony", vector3(620, 2744, 42));
	TeleportOption("Suburban - Hawick", vector3(132, -201, 54));
	TeleportOption("Suburban - Chumash", vector3(-3163, 1065, 20));
	TeleportOption("LS Customs - Airport", vector3(-1130, -1987, 13));
	TeleportOption("LS Customs - La Mesa", vector3(715, -1089, 22));
	TeleportOption("LS Customs - Burton", vector3(-366, -132, 38));
	TeleportOption("LS Customs - Grand Senora Desert", vector3(1177, 2659, 38));
	TeleportOption("Beeker's Garage", vector3(123, 6610, 31));
}

void TeleportMenu()
{
	DrawBackground(16);
	AddTitle(TP_lang);
	AddSubmenuOption(Shops_lang, TP_Shops_MSG_lang, (Stores));
	TeleportOption("Mount Chilliad", vector3(494, 5589, 795));
	TeleportOption("Los Santos International Airport", vector3(-989, -2905, 14));
	TeleportOption("Maze Bank", vector3(-72, -820, 327));
	TeleportOption("Michael's Place", vector3(-824, 177, 72));
	TeleportOption("Franklin's New Place", vector3(12, 548, 177));
	TeleportOption("Franklin's Old Place", vector3(-16, -1448, 31));
	TeleportOption("Trevor's Caravan", vector3(1985, 3813, 33));
	TeleportOption("Sandy Shores Airstrip", vector3(1721, 3259, 41));
	TeleportOption("Sandy Shores Medical Center", vector3(1842, 3670, 33));
	TeleportOption("Prison", vector3(1854, 2610, 45));
	TeleportOption("Rebel Radio", vector3(1854, 2610, 45));
	TeleportOption("Radio Towers", vector3(810, 1275, 360));
	TeleportOption("Vinewood Sign", vector3(704, 1206, 325));
	TeleportOption("Casino", vector3(909, 64, 79));
	TeleportOption("LS Pier", vector3(-1650, -1092, 13));
}

