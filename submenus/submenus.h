#pragma region SettingsPages
void titlemenu()
{
	// title
	DrawBackground(8, false, "", "");
	AddTitle("Title");
	AddSubtext("Title");
	AddSubtext("Banner is what this text is on");
	AddIntOptionSettings("R", &TitleR, 0, 255);
	AddIntOptionSettings("G", &TitleG, 0, 255);
	AddIntOptionSettings("B", &TitleB, 0, 255);
	ColorChanger("White - Default", "Changes the color to White", 1, 255, 255, 255);
	ColorChanger("Black", "Changes the color to Black", 1, 0, 0, 0);
	ColorChanger("Purple", "Changes the color to ~p~Purple~r~", 1, 161, 0, 214);
	ColorChanger("Green", "Changes the color to ~g~Green~g~", 1, 0, 255, 72);
	ColorChanger("Red", "Changes the color to ~r~Red~r~", 1, 255, 71, 71);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void bannermenu()
{ // banner
	DrawBackground(8, false, "", "");
	AddTitle("Banner");
	AddSubtext("Banner is what this text is on");
	AddIntOptionSettings("R", &BannerR, 0, 255);
	AddIntOptionSettings("G", &BannerG, 0, 255);
	AddIntOptionSettings("B", &BannerB, 0, 255);
	ColorChanger("Purple - Default", "Changes the color to ~p~Purple~p~", 3, 161, 0, 214);
	ColorChanger("White", "Changes the color to White", 3, 255, 255, 255);
	ColorChanger("Black", "Changes the color to Black", 3, 0, 0, 0);
	ColorChanger("Green", "Changes the color to ~g~Green~g~", 3, 0, 255, 72);
	ColorChanger("Red", "Changes the color to ~r~Red~r~", 3, 255, 71, 71);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void backgroundmenu()
{ // background
	DrawBackground(8, false, "", "");
	AddTitle("Background");
	AddSubtext("Background is what the options are on");
	AddIntOptionSettings("R", &BackgroundR, 0, 255);
	AddIntOptionSettings("G", &BackgroundG, 0, 255);
	AddIntOptionSettings("B", &BackgroundB, 0, 255);
	ColorChanger("Black - Default", "Changes the color to Black", 2, 0, 0, 0);
	ColorChanger("Purple", "Changes the color to ~p~Purple~p~", 2, 161, 0, 214);
	ColorChanger("White", "Changes the color to White", 2, 255, 255, 255);
	ColorChanger("Green", "Changes the color to ~g~Green~g~", 2, 0, 255, 72);
	ColorChanger("Red", "Changes the color to ~r~Red~r~", 2, 255, 71, 71);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void selectedtextmenu()
{ // selected text
	DrawBackground(8, false, "", "");
	AddTitle("Selected Text");
	AddSubtext("Text that is selected");
	AddIntOptionSettings("R", &SelectedTextR, 0, 255);
	AddIntOptionSettings("G", &SelectedTextG, 0, 255);
	AddIntOptionSettings("B", &SelectedTextB, 0, 255);
	ColorChanger("White - Default", "Changes the color to White", 4, 255, 255, 255);
	ColorChanger("Purple", "Changes the color to ~p~Purple~p~", 4, 161, 0, 214);
	ColorChanger("Black", "Changes the color to Black", 4, 0, 0, 0);
	ColorChanger("Green", "Changes the color to ~g~Green~g~", 4, 0, 255, 72);
	ColorChanger("Red", "Changes the color to ~r~Red~r~", 4, 255, 71, 71);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void unselectedtextmenu()
{ // unselected text
	DrawBackground(8, false, "", "");
	AddTitle("Unselected Text");
	AddSubtext("Text that isnt selected by the cursor");
	AddIntOptionSettings("R", &UnselectedTextR, 0, 255);
	AddIntOptionSettings("G", &UnselectedTextG, 0, 255);
	AddIntOptionSettings("B", &UnselectedTextB, 0, 255);
	ColorChanger("White - Default", "Changes the color to White", 5, 255, 255, 255);
	ColorChanger("Black", "Changes the color to Black", 5, 0, 0, 0);
	ColorChanger("Purple", "Changes the color to ~p~Purple~p~", 5, 161, 0, 214);
	ColorChanger("Green", "Changes the color to ~g~Green~g~", 5, 0, 255, 72);
	ColorChanger("Red", "Changes the color to ~r~Red~r~", 5, 255, 71, 71);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void ScrollBarRGB()
{
	DrawBackground(4, false, "", "");
	AddTitle("Scroll Bar");
	AddIntOptionSettings("R", &ScrollbarR, 0, 255);
	AddIntOptionSettings("G", &ScrollbarG, 0, 255);
	AddIntOptionSettings("B", &ScrollbarB, 0, 255);
	AddIntOptionSettings("Alpha", &ScrollbarA, 0, 255);
}

void colr()
{ // color changer menu //
	DrawBackground(6, false, "", "");
	AddTitle("Colors");
	AddSubtext("Brighten up your world");
	AddSubmenuOption("Title", "Modify The Color of The Title", (titlemenu));
	AddSubmenuOption("Banner", "Modify The Color of the Banner", (bannermenu));
	AddSubmenuOption("Background", "Modify the background (Note Requires Background image to be off)", (backgroundmenu));
	AddSubmenuOption("Selected Text", "Modify the color of the selected text", (selectedtextmenu));
	AddSubmenuOption("Unselected Text", "Modify The Color of the unselected text", (unselectedtextmenu));
	AddSubmenuOption("Scroll Bar", "Modify the scroller", (ScrollBarRGB));
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void funer()
{
	DrawBackground(4, false, "", "");
	AddTitle("Friends");
	AddSubtext("Good Friends");
	NotifyOption("FazeModz", "FazeModz", "Faze Modz is a good place to learn");
	NotifyOption("Lush Modz", "Lush Modz", "Thank you to lush modz for being a good friend");
	NotifyOption("James Reborn", "James Reborn", "Thanks for being there and still being friends with me after all my stupid ideas");
	NotifyOption("TheRouletteBoi", "TheRouletteboi", "Thanks for being there and talking to me");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void cred()
{
	DrawBackground(4, false, "", "");
	AddTitle("Credits");
	AddSubmenuOption("Friends", "All my friends they all be very good", (funer));
	NotifyOption("Louay / for settings", "Louay", "Thanks for making such good mods");
	NotifyOption("NotYourDope / Base", "NotYourDope", "NotYourDope is a beast");
	NotifyOption("JakeModz89 / Video Tutorials", "JakeModz", "youtube.com/jakemodz89");
}
#pragma endregion

#pragma region Ingameoptions
void TimeOptions()
{
	DrawBackground(6, false, "", "");
	AddTitle("Time");
	AddSubtext("Modify Time and not space");
	AddBoolOption("Freeze Time", &FreezeTime);
	ChangeTime("Morning", 7, 0, 0);
	ChangeTime("Midday", 12, 0, 0);
	ChangeTime("Afternoon", 15, 0, 0);
	ChangeTime("Night", 20, 0, 0);
	ChangeTime("Midnight", 0, 0, 0);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void WeatherOptions()
{
	DrawBackground(12, false, "", "");
	AddTitle("Weather");
	AddSubtext("Your a Bloody God");
	ChangeWeather("Sunny", "EXTRASUNNY");
	ChangeWeather("Clear", "CLEAR");
	ChangeWeather("Cloudy", "CLOUDS");
	ChangeWeather("Fog", "FOGGY");
	ChangeWeather("Christmas - Online Only", "XMAS");
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

void TelportationMenu()
{
	DrawBackground(9, false, "", "");
	AddTitle("Teleportation");
	TeleportOption("Mount Chiliad", 494, 5589, 795);
	TeleportOption("Los Santos Airport", -989, -2905, 14);
	TeleportOption("Maze Bank", -72, -820, 327);
	TeleportOption("Michael's House", -824, 177, 72);
	TeleportOption("Franklin's New House", 12, 548, 177);
	TeleportOption("Franklin's Old House", -16, -1448, 31);
	TeleportOption("Trevor's House", 1985, 3813, 33);
	TeleportOption("Trevor's Airfield", 1721, 3259, 41);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void SelfOptions()
{
	if (CurrentOption == 7)
	{
		SET_PLAYER_WANTED_LEVEL(PLAYER_ID(), wantedlvl, true);
		SET_PLAYER_WANTED_LEVEL_NOW(PLAYER_ID(), true);
	}
	DrawBackground(9 + EnabledDropdownOptionsSelf, false, "", "");
	AddTitle(SelfTitle_lang);
	AddSubtext(SelfTitle_Sub_lang);
	AddBoolOption(GodMode_lang, &GodMode); // gives player god mode
	AddBoolOption(NoRagdoll_lang, &DoNotRagdoll); // toggles no ragdoll
	AddBoolOption(SuperJump_lang, &SuperJump); // allows player to jump very high
	AddBoolOption(MobileRadio_lang, &MobileRadio); // toggle for Mobile Radio
	AddBoolOption(Unlimited_Special_Ability_lang, &UnlimitedSpecialAbility);
	AddBoolOption(NeverWanted_lang, &NeverWanted); // No wanted level 
	AddIntOptionSettings(WantedLevel_lang, &wantedlvl, 0, 5); // allows the user to change there wanted level
	AddDropDownBool(MoneyDrop_lang, 1, &Moneydrop);
	if (Moneydrop)
	{
		AddIntOptionSettings("Money Drop Objects", &MoneyBagType, 1, 2);
	}
	Suidcide(Suicide_lang);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void SpawnCarOptions()
{
	DrawBackground(3, false, "", "");
	AddTitle("Spawn Options");
	AddSubtext("spawn options u can edit");
	AddBoolOption("Spawn in car", &Spawnincar);
	AddBoolOption("Delete Old Vehicle", &DeleteOldVehicle);
	AddBoolOption("Spawn Notification", &CarSpawnNotification);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}


void spawner()
{
	DrawBackground(5, true, "shopui_title_carmod", "shopui_title_carmod");
	AddSubmenuOption("Spawn Options", "Change up the way the car spawns", (SpawnCarOptions));
	AddSubmenuOption("Super", "Displays all cars that you can spawn from the super class", (SuperCarSpawner));
	AddSubmenuOption("Sports", "Displays all cars that you can spawn from the sports class", (SportsCarSpawner));
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void VehicleOptions()
{
	DrawBackground(5, true, "shopui_title_carmod", "shopui_title_carmod");
	AddTitle("Vehicle Options");
	AddSubmenuOption("Vehicle Spawner", "Spawn some new cars", (spawner));
	AddSubtext("pimp ur vehicle");
	AddBoolOption("Vehicle GodMode", &VehicleRepair);
	carfix("Fix Vehicle");
	killvehicle("Destroy Vehicle", 1);
	killvehicle("Destroy Engine", 2);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void weaponoptions()
{
	DrawBackground(5, false, "", "");
	AddTitle(WeaponTitle_lang);
	AddSubtext(WeaponTitle_Sub_lang);
	GiveAllWeapons(GiveAllWeapons_lang);
	RemoveWeapons(RemoveAllWeapons_lang);
	AddBoolOption(InfiniteAmmo_lang, &InfinityAmmo);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void miscgame()
{
	DrawBackground(7, false, "", "");
	AddTitle("Game Modifcations");
	AddSubmenuOption("Time", "Change the time", (TimeOptions));
	AddSubmenuOption("Weather", "Be like god and change the weather", (WeatherOptions));
	AddBoolOption("Disable MiniMap", &Dismap);
	AddBoolOption("Thermal Vision", &ThermalVision);
	AddBoolOption("Night Vision", &NightVision);
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}
#pragma endregion


void ModMenus()
{
	DrawBackground(2, false, "", "");
	AddTitle("Menus");
	AddSubtext("Mod Me Up");
	AddScriptOption("AP ii Intense", "rock_menu2", 2024, R1, Square, "Ap ii Intense Loaded", "AP ii Intense Deactivated");
	AddScriptOption("Inimitable", "Inimitable", 1024, R1, DpadDown, "Inimitable Loaded", "Inimitable Deactivated");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}

void Misc()
{
	// need to add a misc menu
	DrawBackground(5, false, "", "");
	AddTitle("Misc.");
	AddSubtext("All sorts mate");
	AddScriptOption("Meteor Shower", "Meteor_Shower", 1024, Nothing, Nothing, "Meteors Incoming Coming to hit THE SAN ANDREAS AREA", "Meteor Shower has finished");
	AddScriptOption("James Reborn", "JRrecovery", 2552, DpadRight, R3Press, "James Reborn Recovery Loaded", "James Reborn Recovery Deactivated");
	AddScriptOption("Danii X Modz", "Recoveryv2", 2024, L1, Circle, "Danii X Modz Loaded", "Danii X Modz Deactivated");
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}


void Setx()
{
	DrawBackground(12, false, "", "");
	AddTitle("Settings");
	AddSubtext(vername);
	if (CurrentOption == 4)
	{
		BackgroundChanger();
	}
	AddSubmenuOption("Colors", "Modify the colors of the menu", (colr));
	AddStringOption("Base", &base, 1, 2, "NotYourDope", "LTS", "", "", "", "");
	AddStringOption("Toggle Buttons", &ToggleButtons, 1, 6, "Boxuga", "CheckBox", "Caution", "Weed", "Flags", "Thumbs Up/Down");
	AddIntOptionSettings("Background", &background, 1, 10);
	AddBoolOption("Outline Title", &TextOutlineTitle);
	AddBoolOption("Outline Options", &TextOutlineOptions);
	AddBoolOption("Outline Options Count", &TextOutlineOptionCount);
	AddBoolOption("Smooth Scroll", &SmoothScrolling);
	AddBoolOption("Left Sided", &LeftSided);
	AddBoolOption("Background Image", &bgimage);
	AddCustomScriptOption();
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}
}
