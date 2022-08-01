#include "types.h"
#include "constants.h"
#include "intrinsics.h"
#include "natives.h"
#include "common.h"
#include "Menu Internals/enums.h"
#include "Configuration/vars.h" // contains all settings edit this if you want permanent options
#include "languages/English.h" // Edit This file to change all the language you can even make your own language packs
#include "Menu Internals/functions.h" // contains all functions
#include "Menu Internals/Loops.h" // this option will loop all
#include "submenus/VehicleSpawner.h" // contains all submenus of the Vehicle Spawner
#include "submenus/submenus.h" // contains all submenus

#define INTEGRATED_INJECTOR true
#define DEFAULT_INJECTOR_STACKSIZE 2024

void ModLoader()
{
	DrawBackground(2);
	AddTitle("ModLoader");
	if (IS_XBOX360_VERSION()) // this is too link to the xbox version of the pages
	{
		AddSubmenuOption(ModMenus_lang, ModMenus_MSG_lang, (ModMenus));
		AddSubmenuOption(Misc_Scripts_lang, Misc_Scripts_MSG_lang, (Misc));
	}
	if (IS_PS3_VERSION()) // this is too link to the ps3 version of the pages
	{
		AddSubmenuOption(ModMenus_lang, ModMenus_MSG_lang, (ModMenusPS));
		AddSubmenuOption(Misc_Scripts_lang, Misc_Scripts_MSG_lang, (MiscPS));
	}
}
int month;
int day;
int year;
int hour;
int minute;
int second;
void MainMenu()
{
	DrawBackground(8 + CustomScriptCount + AddCustomScript);
	AddTitle("Hedgehog");
	if (TimedSubText)
	{
		GET_LOCAL_TIME(&year, &month, &day, &hour, &minute, &second);
		TimedSubText = false;
	}
	if (month == 12) 
	{
		AddSubtext("Merry Christmas");
	}
	if ((month == 10) && (day == 31))
	{
		AddSubtext("Happy Halloween");
	}
	if ((month == 4) && (day == 17))
	{
		AddSubtext("Happy Easter");
	}
	if ((month == 2) && (day == 18))
	{
		AddSubtext("Say Happy Birthday to Boxuga");
	}
	if ((month == 1) && (day == 26))
	{
		AddSubtext("Grab a Timtam and Happy Australia Day");
	}
	if (!(((month == 10) && (day == 31)) || (month == 12) || ((month == 4) && (day == 17)) || ((month == 2) && (day == 18)) || ((month == 1) && (day == 26))))
	{
		AddSubtext(strcatGlobal(Welcome_lang, GET_PLAYER_NAME(PLAYER_ID())));
	}
	
	AddSubmenuOption(Self_lang, Self_MSG_lang, (SelfOptions));
	AddSubmenuOption(Weapon_lang, Weapon_MSG_lang, (weaponoptions));
	AddSubmenuOption(Vehicle_Options_lang, Vehicle_Options_MSG_lang, (VehicleOptions));
	AddSubmenuOption(TP_lang, TP_MSG_lang, (TeleportMenu));
	AddSubmenuOption(Misc_lang, Misc_MSG_lang, (miscgame));
	AddSubmenuOption(ModLoader_lang, ModLoader_MSG_lang, (ModLoader));
	AddSubmenuOption(Settings_lang, Settings_MSG_lang, (Setx));
	AddSubmenuOption(Credits_lang, Credits_MSG_lang, (cred));
	AddScriptOptionNoBinds(CustomScript1, &CustomScript1StackSize);
	AddScriptOptionNoBinds(CustomScript2, &CustomScript2StackSize);
	AddScriptOptionNoBinds(CustomScript3, &CustomScript3StackSize);
	AddScriptOptionNoBinds(CustomScript4, &CustomScript4StackSize);
	AddScriptOptionNoBinds(CustomScript5, &CustomScript5StackSize);
	AddScriptOptionNoBinds(CustomScript6, &CustomScript6StackSize);
	AddScriptOptionNoBinds(CustomScript7, &CustomScript7StackSize);
	AddScriptOptionNoBinds(CustomScript8, &CustomScript8StackSize);
	AddScriptOptionNoBinds(CustomScript9, &CustomScript9StackSize);
	AddScriptOptionNoBinds(CustomScript10, &CustomScript10StackSize);
	if (AddCustomScript)
	{
		AddCustomScriptOption();
	}
	if (DrawInstructions)
	{
		DrawInstructionalButtons();
	}

}



#pragma region Menu States
void MenuClosed()
{
	if (BindHint)
	{
		BEGIN_TEXT_COMMAND_DISPLAY_HELP("STRING");
		ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(HintMSG_lang);
		END_TEXT_COMMAND_DISPLAY_HELP(0, 0, 0, -1);
	}
	if (IS_DISABLED_CONTROL_PRESSED(0, Bind1) && IS_DISABLED_CONTROL_JUST_PRESSED(0, Bind2))
	{
		NotifyMSG("Hedgehog Menu", OpenMSG);
		CurrentSubmenu = (MainMenu);
		CurrentOption = 1;
		ScrollbarCoord = 0.0f;
		BindHint = false;
	}
}

void MenuOpen()
{
	DisableControls();
	if (!IS_PLAYER_PLAYING(PLAYER_ID())) // if menu is open then it will close the menu on player death
	{
		CurrentSubmenu = (MenuClosed);
	}
	if (IS_DISABLED_CONTROL_JUST_PRESSED(0, 178))
	{
		PlayMenuSound("BACK");
		if (CurrentSubmenu == (MainMenu))
		{
			CurrentSubmenu = (MenuClosed);
			DisableCinematicCameraTimer = GET_GAME_TIMER() + 750;
			if (HAS_SCALEFORM_MOVIE_LOADED(GlareHandle))
			{
				SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&GlareHandle);
			}
			if (HAS_SCALEFORM_MOVIE_LOADED(InstructionalButtonsHandle))
			{
				SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&InstructionalButtonsHandle);
			}
		}
		else
		{
			SubmenuLevel--;
			CurrentSubmenu = LastSubmenu[SubmenuLevel];
			CurrentOption = LastOption[SubmenuLevel];
		}
	}
	else if (IsControlPressed(202))
	{
		PlayMenuSound("NAV_UP_DOWN");
		if (CurrentOption == 1)
		{
			CurrentOption = SubmenuOptionCount;
		}
		else
		{
			CurrentOption--;
		}
	}
	else if (IsControlPressed(203))
	{
		PlayMenuSound("NAV_UP_DOWN");
		if (CurrentOption == SubmenuOptionCount)
		{
			CurrentOption = 1;
		}
		else
		{
			CurrentOption++;
		}
	}
}

void OtherLoops()
{
	if (CurrentSubmenu == (MenuClosed) && DisableCinematicCameraTimer > GET_GAME_TIMER())
	{
		setGlobalAtIndex(13245 + 4621, GET_GAME_TIMER());
		SET_INPUT_EXCLUSIVE(0, 178);
	}
	Hash StatHash = GET_HASH_KEY("MPPLY_NO_MORE_TUTORIALS");
	bool stat;
	bool StatGetStatus = STAT_GET_BOOL(StatHash, &stat, 0);
	if (!(StatGetStatus == 0))
	{
		if (!(stat == 1))
		{
			STAT_SET_BOOL(StatHash, 1, 0);
		}
	}
	if (!(AllowCustomScripts == 0))
	{
		if (CustomScriptCount < 10)
		{
			AddCustomScript = true;
		}
		else
		{
			AddCustomScript = false;
		}
	}
	if (!(ScriptToLoad == false))
	{
		if (AlreadyRequested == 0)
		{
			REQUEST_SCRIPT(ScriptToLoad), AlreadyRequested = true;
		}
		if (HAS_SCRIPT_LOADED(ScriptToLoad))
		{
			START_NEW_SCRIPT(ScriptToLoad, ScriptToLoadStackSize);
			SET_SCRIPT_AS_NO_LONGER_NEEDED(ScriptToLoad);
			ScriptToLoad = false;
			AlreadyRequested = false;
		}
	}
	if (KeyboardMonitoring)
	{
		if (!(UPDATE_ONSCREEN_KEYBOARD() == 0))
		{
			const char* KeyboardResult = GET_ONSCREEN_KEYBOARD_RESULT();
			if (!(IS_STRING_NULL_OR_EMPTY(KeyboardResult)))
			{
				SetKeyboardResultIntoOption(KeyboardResult);
				UpdateCustomScriptCount();
				UpdateCurrentOption();
				KeyboardMonitoring = false;
			}
		}
	}

	if (KeyboardNumPlate) // if is option 1 then is used this should function - 25/06/22 yes im also confused what i meant okay
	{
		if (!(UPDATE_ONSCREEN_KEYBOARD() == 0))
		{
			int currentvehicle = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()); // should grab vehile hash
			const char* KeyResult = GET_ONSCREEN_KEYBOARD_RESULT(); // get hash
			if (!(IS_STRING_NULL_OR_EMPTY(KeyResult))) // check if string is empty
			{
				SET_VEHICLE_NUMBER_PLATE_TEXT(currentvehicle, KeyResult); // gets keyboard result then sets the vehicle number plate
				KeyboardNumPlate = false;
			}
		}
	}
}

void main()
{
	if (_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(GET_THIS_SCRIPT_NAME())) == 1)
	{
		CurrentSubmenu = (MenuClosed);
		MaybeLoadTexture("commonmenu");
		MaybeLoadTexture("BoxugaOnOff");
		MaybeLoadTexture("erootiik");
		while (true)
		{
			OptionLoops();
			OtherLoops();
			if (!(IS_WARNING_MESSAGE_ACTIVE() || IS_PAUSE_MENU_ACTIVE()))
			{
				void (*function)() = CurrentSubmenu;
				function();
				if (!(CurrentSubmenu == (MenuClosed)))
				{
					MenuOpen();
				}
			}
			WAIT(0);
		}
	}
}
#pragma endregion
