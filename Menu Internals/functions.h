void PlayMenuSound (const char* Sound)
{
	PLAY_SOUND_FRONTEND(-1, Sound, "HUD_FRONTEND_DEFAULT_SOUNDSET", true);
}

void NotifyMSG(const char* Title, char* MSG) 
{
	_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	_SET_NOTIFICATION_FLASH_COLOR(RGBA(BannerR, BannerG, BannerB, 125));
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(MSG); // Message
	_SET_NOTIFICATION_MESSAGE("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 7, strcatGlobal("~bold~", Title), "");
	_DRAW_NOTIFICATION(false, false);
}

bool IsControlPressed(int button)
{
	bool buttonPress = false;
	if (IS_DISABLED_CONTROL_JUST_PRESSED(0, button))
	{
		buttonPress = true;
	}
	else if (IS_DISABLED_CONTROL_PRESSED(0, button))
	{
		ScrollTimer++;
		if (!(ScrollTimer <= 4))
		{
			buttonPress = true;
			ScrollTimer = 1;
		}
	}
	else if (IS_DISABLED_CONTROL_JUST_RELEASED(0, button))
	{
		ScrollTimer = 0;
	}
	return buttonPress;
}

bool WasXJustPressed(int button)
{
	bool buttonPress = false;
	if (CurrentOption == OptionCount)
	{
		if (!(IS_DISABLED_CONTROL_PRESSED(0, 202) || IS_DISABLED_CONTROL_PRESSED(0, 203)))
		{
			if (IS_DISABLED_CONTROL_JUST_PRESSED(0, button))
			{
				PlayMenuSound("SELECT");
				buttonPress = true;
			}
		}
	}
	return buttonPress;
}

void AddInstructionalButton(int Button, const char* Text)
{
	if (!DrawInstructions)
	{
		InstructionalButtonCount = -1;
		InstructionalButtonsHandle = REQUEST_SCALEFORM_MOVIE("INSTRUCTIONAL_BUTTONS");
		if (HAS_SCALEFORM_MOVIE_LOADED(InstructionalButtonsHandle))
		{
			DRAW_SCALEFORM_MOVIE_FULLSCREEN(InstructionalButtonsHandle, RGBA(255, 255, 255, 255), 0);
			_PUSH_SCALEFORM_MOVIE_FUNCTION(InstructionalButtonsHandle, "CLEAR_ALL");
			_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
			_PUSH_SCALEFORM_MOVIE_FUNCTION(InstructionalButtonsHandle, "SET_CLEAR_SPACE");
			_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(200);
			_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
			DrawInstructions = true;
		}
	}
	if (HAS_SCALEFORM_MOVIE_LOADED(InstructionalButtonsHandle))
	{
		InstructionalButtonCount++;
		_PUSH_SCALEFORM_MOVIE_FUNCTION(InstructionalButtonsHandle, "SET_DATA_SLOT");
		_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(InstructionalButtonCount);
		_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(Button);
		BEGIN_TEXT_COMMAND_SCALEFORM_STRING("STRING");
		ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Text);
		END_TEXT_COMMAND_SCALEFORM_STRING();
		_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	}
}

void StringBase(int font, int r, int g, int b, bool outline)
{
	SET_TEXT_FONT(font);
	SET_TEXT_SCALE(0.0f, 0.5f);
	SET_TEXT_COLOUR(RGBA(r, g, b, 255));
	SET_TEXT_WRAP(0.0f, MenuXCoord2);
	SET_TEXT_CENTRE(0);
	if (outline)
	{
		SET_TEXT_OUTLINE();
	}
}

void MaybeLoadTexture(const char* TextureDict)
{
	if (!HAS_STREAMED_TEXTURE_DICT_LOADED(TextureDict))
	{
		REQUEST_STREAMED_TEXTURE_DICT(TextureDict, true);
	}
}



float GetSafezoneSizeHalfed()
{
	float safezoneSize = GET_SAFE_ZONE_SIZE();
	return safezoneSize / 2;
}

void SetMenuPosition(bool LeftSided)
{
	if (LeftSided)
	{
		MenuXCoord1 = 0.081f;
		MenuXCoord2 = 0.29f;
		MenuXCoord3 = 0.19f;
	}
	else
	{
		MenuXCoord1 = 0.74f;
		MenuXCoord2 = 0.94f;
		MenuXCoord3 = 0.85f;
	}
}	
	



float SmoothScroll(float destinationCoord, float currentCoord)
{
	float newCoord = destinationCoord;
	if (!(currentCoord == 0.0f))
	{
		if (destinationCoord < currentCoord)
		{
			if (!(currentCoord - destinationCoord <= 0.007f))
			{
				newCoord = currentCoord - (currentCoord - destinationCoord) / 1.7f;
			}
		}
		if (destinationCoord > currentCoord)
		{
			if (!(destinationCoord - currentCoord <= 0.007f))
			{
				newCoord = currentCoord + (destinationCoord - currentCoord) / 1.7f;
			}
		}
	}
	return newCoord;
}

void AddTitle(const char* Title)
{
	if (base == 3)
	{
		StringBase(0, 255, 0, 0, true);
		SET_TEXT_CENTRE(true);
		SET_TEXT_SCALE(0.0f, 0.6f);
		BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Title);
		END_TEXT_COMMAND_DISPLAY_TEXT(vector2(MenuXCoord3, 0.07f));
		OptionCount = 0;
	}
	else
	{
		StringBase(TitleFont, TitleR, TitleG, TitleB, TextOutlineTitle);
		SET_TEXT_CENTRE(true);
		SET_TEXT_SCALE(0.0f, 0.7f);
		BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Title);
		END_TEXT_COMMAND_DISPLAY_TEXT(vector2(MenuXCoord3, (0.522f - GetSafezoneSizeHalfed())));
		OptionCount = 0;
	}
}

void DrawBackground(int NumberOfOptions)
{
	float OptionCountFloat;
	float ScrollbarCoordStartingPoint;
	float ScrollbarDestinationCoord;
	SetMenuPosition(LeftSided);
	SubmenuOptionCount = NumberOfOptions;
	if (NumberOfOptions > 13)
	{
		OptionCountFloat = 13.0f;
	}
	else
	{
		OptionCountFloat = NumberOfOptions;
	}
	if (base == 1)
	{
		BackgroundCoord = (OptionCountFloat * 0.035f / 2.0f) + (0.6046f - GetSafezoneSizeHalfed());
		BackgroundLength = OptionCountFloat * 0.035f;
		if (bgimage)
		{
			MaybeLoadTexture("BoxugaBackground");
			if (HAS_STREAMED_TEXTURE_DICT_LOADED("BoxugaBackground"))
			{
				DRAW_SPRITE("BoxugaBackground", BackgroundImage, vector2(MenuXCoord3, BackgroundCoord), Size(0.2250f, BackgroundLength), 0.0f, RGBA(255, 255, 255, 200));
			}
		}
		else
		{
			DRAW_RECT(vector2(MenuXCoord3, BackgroundCoord), Size(0.2250f, BackgroundLength), RGBA(BackgroundR, BackgroundG, BackgroundB, BackgroundA));
		}
        DRAW_RECT(vector2(MenuXCoord3, (0.5596f - GetSafezoneSizeHalfed())), Size(0.2250f, 0.09f), RGBA(BannerR, BannerG, BannerB, BannerA));
		BottomBarCoord = ((OptionCountFloat + 1.0f) * 0.035f) + (0.5871f - GetSafezoneSizeHalfed());
		if (OptionCountDisplay)
		{
			StringBase(OptionCountFont, OptionCountR, OptionCountG, OptionCountB, TextOutlineOptionCount);
			SET_TEXT_RIGHT_JUSTIFY(true);
			BEGIN_TEXT_COMMAND_DISPLAY_TEXT("CM_ITEM_COUNT");
			ADD_TEXT_COMPONENT_INTEGER(CurrentOption);
			ADD_TEXT_COMPONENT_INTEGER(SubmenuOptionCount);
			if (LeftSided)
			{
				END_TEXT_COMMAND_DISPLAY_TEXT(vector2(0.077f, (0.515f - GetSafezoneSizeHalfed())));
			}
			if (!LeftSided)
			{
				END_TEXT_COMMAND_DISPLAY_TEXT(vector2(0.736f, (0.515f - GetSafezoneSizeHalfed())));
			}
		}
	}
	if (base == 2)
	{
		bgimage = false;
		DRAW_RECT(vector2(MenuXCoord3, 0.5f), Size(0.2250f, 1.0f), RGBA(BackgroundR, BackgroundG, BackgroundB, BackgroundA));
	}
	if ((CurrentOption < 7) || (SubmenuOptionCount <= 13))
	{
		ScrollbarCoordStartingPoint = CurrentOption;
	}
	else if ((SubmenuOptionCount - CurrentOption) < 6)
	{
		ScrollbarCoordStartingPoint = 13 - (SubmenuOptionCount - CurrentOption);
	}
	else 
	{
		ScrollbarCoordStartingPoint = 7;
	}
	ScrollbarDestinationCoord = (ScrollbarCoordStartingPoint * 0.035f) + (0.5871f - GetSafezoneSizeHalfed());
	ScrollArrowsCoord = ScrollbarDestinationCoord;
    if (SmoothScrolling)
	{
		ScrollbarCoord = SmoothScroll(ScrollbarDestinationCoord, ScrollbarCoord);
	}
	else
	{
		ScrollbarCoord = ScrollbarDestinationCoord;
	}
	DRAW_RECT(vector2(MenuXCoord3, ScrollbarCoord), Size(0.2250f, 0.035f), RGBA(ScrollbarR, ScrollbarG, ScrollbarB, ScrollbarA));
}	

void DisableControls()
{
	if (DisableSpecialAbility)
	{
		if (IS_SPECIAL_ABILITY_ACTIVE(PLAYER_ID()))
		{
			SPECIAL_ABILITY_DEACTIVATE_FAST(PLAYER_ID());
		}
	}
	if (GET_PED_STEALTH_MOVEMENT(PLAYER_PED_ID()))
	{
		SET_PED_STEALTH_MOVEMENT(PLAYER_PED_ID(), 0, 0);
	}
	setGlobalAtIndex(10434 + 1, 0);
	setGlobalAtIndex(13245 + 4621, GET_GAME_TIMER());
	SET_CINEMATIC_MODE_ACTIVE(0);
	HIDE_HELP_TEXT_THIS_FRAME();
	HIDE_HUD_COMPONENT_THIS_FRAME(6);
	HIDE_HUD_COMPONENT_THIS_FRAME(7);
	HIDE_HUD_COMPONENT_THIS_FRAME(8);
	HIDE_HUD_COMPONENT_THIS_FRAME(9);
	SET_INPUT_EXCLUSIVE(0, 166);
	SET_INPUT_EXCLUSIVE(0, 167);
	SET_INPUT_EXCLUSIVE(0, 177);
	SET_INPUT_EXCLUSIVE(0, 178);
	SET_INPUT_EXCLUSIVE(0, 179);
	SET_INPUT_EXCLUSIVE(0, 202);
	SET_INPUT_EXCLUSIVE(0, 203);
}

RGB GetSpriteColour(bool On)
{
	if (!(On == false))
	{
		return RGB(SpriteOnR, SpriteOnG, SpriteOnB);
	}
	else
	{
		return RGB(SpriteOffR, SpriteOffG, SpriteOffB);
	}
}

RGB GetOptionColour()
{
	if (CurrentOption == OptionCount)
	{
		return RGB(SelectedTextR, SelectedTextG, SelectedTextB);
	}
	else
	{
		return RGB(UnselectedTextR, UnselectedTextG, UnselectedTextB);
	}
}

void AddOption(const char* OptionText)
{
	OptionCoordStartingPoint = 0.0f;
	RGB optionColour;
	OptionCount++;
	if ((CurrentOption < 7) || (SubmenuOptionCount <= 13))
	{
		if (!(OptionCount > 13))
		{
		    OptionCoordStartingPoint = OptionCount;
		}
	}
	else if ((SubmenuOptionCount - CurrentOption) < 6)
	{
		if (!(OptionCount <= (SubmenuOptionCount - 13)))
		{
			OptionCoordStartingPoint = OptionCount - (SubmenuOptionCount - 13);
		}
	}
	else if (!((OptionCount < (CurrentOption - 6)) || (OptionCount > (CurrentOption + 6))))
	{
		OptionCoordStartingPoint = OptionCount - (CurrentOption - 7);
	}
	if (!(OptionCoordStartingPoint == 0.0f))
	{
		OptionCoord = (OptionCoordStartingPoint * 0.035f) + (0.5691f - GetSafezoneSizeHalfed());
		optionColour = GetOptionColour();
		StringBase(OptionFont, optionColour.r, optionColour.g, optionColour.b, TextOutlineOptions);
		BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(OptionText);
		END_TEXT_COMMAND_DISPLAY_TEXT(vector2(MenuXCoord1, OptionCoord));
	}
}

void AddOnOffOption(bool On)
{
	if (OptionCoordStartingPoint != 0.0f)
	{
		SpriteCoord = (OptionCoordStartingPoint * 0.035f) + (0.5871f - GetSafezoneSizeHalfed());
		if (ToggleButtons == 1)
		{
			if (HAS_STREAMED_TEXTURE_DICT_LOADED("BoxugaOnOff"))
			{
				if (On)
				{
					if (SpriteOutline)
					{
						DRAW_SPRITE("BoxugaOnOff", "globe_bg", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.03f, 0.0494f), 0.0f, RGBA(SpriteOutlineR, SpriteOutlineG, SpriteOutlineB, 255));
					}
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("BoxugaOnOff", "globe_bg", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.025f, 0.0444f), 0.0f, RGBA(spriteColour.r, spriteColour.g, spriteColour.b, 255));
				}
				if (!On)
				{
					if (SpriteOutline)
					{
						DRAW_SPRITE("BoxugaOnOff", "globe", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.03f, 0.0494f), 0.0f, RGBA(SpriteOutlineR, SpriteOutlineG, SpriteOutlineB, 255));
					}
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("BoxugaOnOff", "globe", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.025f, 0.0444f), 0.0f, RGBA(spriteColour.r, spriteColour.g, spriteColour.b, 255));
				}
			}
		}
		if (ToggleButtons == 2)
		{
			MaybeLoadTexture("commonmenu");
			if (HAS_STREAMED_TEXTURE_DICT_LOADED("commonmenu"))
			{
				if (On)
				{
					if (SpriteOutline)
					{
						DRAW_SPRITE("commonmenu", "shop_box_tick", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.03f, 0.0494f), 0.0f, RGBA(SpriteOutlineR, SpriteOutlineG, SpriteOutlineB, 255));
					}
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("commonmenu", "shop_box_tick", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.025f, 0.0444f), 0.0f, RGBA(spriteColour.r, spriteColour.g, spriteColour.b, 255));
				}
				if (!On)
				{
					if (SpriteOutline)
					{
						DRAW_SPRITE("commonmenu", "shop_box_cross", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.03f, 0.0494f), 0.0f, RGBA(SpriteOutlineR, SpriteOutlineG, SpriteOutlineB, 255));
					}
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("commonmenu", "shop_box_cross", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.025f, 0.0444f), 0.0f, RGBA(spriteColour.r, spriteColour.g, spriteColour.b, 255));
				}
			}
		}
		if (ToggleButtons == 3)
		{
			MaybeLoadTexture("commonmenu");
			if (HAS_STREAMED_TEXTURE_DICT_LOADED("commonmenu"))
			{
				if (On)
				{
					if (SpriteOutline)
					{
						DRAW_SPRITE("commonmenu", "mp_alerttriangle", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.03f, 0.0494f), 0.0f, RGBA(SpriteOutlineR, SpriteOutlineG, SpriteOutlineB, 255));
					}
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("commonmenu", "mp_alerttriangle", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.025f, 0.0444f), 0.0f, RGBA(0, 255, 0, 255));
				}
				if (!On)
				{
					if (SpriteOutline)
					{
						DRAW_SPRITE("commonmenu", "mp_alerttriangle", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.03f, 0.0494f), 0.0f, RGBA(SpriteOutlineR, SpriteOutlineG, SpriteOutlineB, 255));
					}
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("commonmenu", "mp_alerttriangle", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.025f, 0.0444f), 0.0f, RGBA(255, 0, 0, 255));
				}
			}
		}
		if (ToggleButtons == 4)
		{
			MaybeLoadTexture("commonmenu");
			if (HAS_STREAMED_TEXTURE_DICT_LOADED("commonmenu"))
			{
				if (On)
				{
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("commonmenu", "mp_specitem_weed", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.018f, 0.031f), 0.0f, RGBA(0, 255, 0, 255));
				}
				if (!On)
				{
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("commonmenu", "mp_specitem_weed", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.018f, 0.031f), 0.0f, RGBA(255, 0, 0, 255));
				}
			}
		}
		if (ToggleButtons == 5)
		{
			MaybeLoadTexture("commonmenutu");
			if (HAS_STREAMED_TEXTURE_DICT_LOADED("commonmenutu"))
			{
				if (On)
				{
                    DRAW_SPRITE("commonmenutu", "race", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.03f, 0.0494f), 0.0f, RGBA(SpriteOutlineR, SpriteOutlineG, SpriteOutlineB, 255));
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("commonmenutu", "race", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.025f, 0.0444f), 0.0f, RGBA(0, 255, 0, 255));
				}
				if (!On)
				{
					DRAW_SPRITE("commonmenutu", "race", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.03f, 0.0494f), 0.0f, RGBA(SpriteOutlineR, SpriteOutlineG, SpriteOutlineB, 255));
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("commonmenutu", "race", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.025f, 0.0444f), 0.0f, RGBA(255, 0, 0, 255));
				}
			}
		}
		if (ToggleButtons == 6)
		{
			MaybeLoadTexture("mphud");
			if (HAS_STREAMED_TEXTURE_DICT_LOADED("mphud"))
			{
				if (On)
				{
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("mphud", "thumb_up_white", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.019f, 0.026f), 0.0f, RGBA(255, 255, 255, 255));
				}
				if (!On)
				{
					RGB spriteColour = GetSpriteColour(On);
					DRAW_SPRITE("mphud", "thumb_down_white", vector2((MenuXCoord2 - 0.018f), SpriteCoord), Size(0.019f, 0.026f), 0.0f, RGBA(255, 255, 255, 255));
				}
			}
		}	
		if (ToggleButtons == 7)
		{
			StringBase(2, SelectedTextR, SelectedTextG, SelectedTextB, true); // sets up the command
			SET_TEXT_SCALE(0.0f, 0.361f); // sets the scale of the text
			BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING"); // begins the the command to display text set as STRING type
		    if (On)
			{
				ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("ON"); // if on will display ON
			}
			if (!On)
			{
				ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("OFF"); // if off will display OFF
			}
			END_TEXT_COMMAND_DISPLAY_TEXT(vector2((MenuXCoord2 - 0.019f), OptionCoord)); // ends the commands and sets coords
		}

	}
}

void GetTextWrap()
{
	if (CurrentOption == OptionCount)
	{
		SET_TEXT_WRAP(0.0f, (MenuXCoord2 - 0.0324f));
	}
	else
	{
		SET_TEXT_WRAP(0.0f, (MenuXCoord2 - 0.0159f));
	}
}

int GetStackSizeFromValue(int value)
{
	int StackSize;
	switch(value)
	{
		case 0: {StackSize = 128; break;}
		case 1: {StackSize = 512; break;}
		case 2: {StackSize = 1024; break;}
		case 3: {StackSize = 1820; break;}
		case 4: {StackSize = 1828; break;}
		case 5: {StackSize = 2024; break;}
		case 6: {StackSize = 2552; break;}
		case 7: {StackSize = 2556; break;}
		case 8: {StackSize = 2800; break;}
		case 9: {StackSize = 3076; break;}
		case 10: {StackSize = 3150; break;}
		case 11: {StackSize = 3584; break;}
		case 12: {StackSize = 4592; break;}
		case 13: {StackSize = 4600; break;}
		case 14: {StackSize = 5000; break;}
		case 15: {StackSize = 6304; break;}
		case 16: {StackSize = 8032; break;}
		case 17: {StackSize = 9300; break;}
		case 18: {StackSize = 15000; break;}
		case 19: {StackSize = 21000; break;}
	}
	return StackSize;
}

void AddLeftRightOption()
{
	MaybeLoadTexture("commonmenu");
	if (HAS_STREAMED_TEXTURE_DICT_LOADED("commonmenu"))
	{
		DRAW_SPRITE("commonmenu", "shop_arrows_upanddown", vector2((MenuXCoord2 - 0.0235f), ScrollArrowsCoord), Size(0.025f, 0.0444f), 90.0f, RGBA(SelectedTextR, SelectedTextG, SelectedTextB, 255));
	}
}

void AddIntOption(int* DisplayNumber, int minValue, int maxValue)
{
	RGB optionColour;
	if (CurrentOption == OptionCount)
	{
		if (IsControlPressed(166))
		{
			PlayMenuSound("NAV_LEFT_RIGHT");
			if (*DisplayNumber == minValue)
			{
				*DisplayNumber = maxValue;
			}
			else
			{
				*DisplayNumber = *DisplayNumber - 1;
			}
		}
		else if (IsControlPressed(167))
		{
			PlayMenuSound("NAV_LEFT_RIGHT");
			if (*DisplayNumber == maxValue)
			{
				*DisplayNumber = minValue;
			}
			else
			{
				*DisplayNumber = *DisplayNumber + 1;
			}
		}
	}
	if (!(OptionCoordStartingPoint == 0.0f))
	{
		optionColour = GetOptionColour();
		StringBase(OptionFont, optionColour.r, optionColour.g, optionColour.b, TextOutlineOptions);
		SET_TEXT_RIGHT_JUSTIFY(true);
		BEGIN_TEXT_COMMAND_DISPLAY_TEXT("NUMBER");
		ADD_TEXT_COMPONENT_INTEGER(GetStackSizeFromValue(*DisplayNumber));
		END_TEXT_COMMAND_DISPLAY_TEXT(vector2((MenuXCoord2 - 0.015f), OptionCoord));
	}
}

void AddStringOption(const char* OptionText, int* DisplayNumber, int minValue, int maxValue, char* change1, char* change2, char* change3, char* change4, char* change5, char* change6, char* change7)
{
	AddOption(OptionText);
	RGB optionColour;
	if (CurrentOption == OptionCount)
	{
		if (IsControlPressed(166))
		{
			PlayMenuSound("NAV_LEFT_RIGHT");
			if (*DisplayNumber == minValue)
			{
				*DisplayNumber = maxValue;
			}
			else
			{
				*DisplayNumber = *DisplayNumber - 1;
			}
		}
		else if (IsControlPressed(167))
		{
			PlayMenuSound("NAV_LEFT_RIGHT");
			if (*DisplayNumber == maxValue)
			{
				*DisplayNumber = minValue;
			}
			else
			{
				*DisplayNumber = *DisplayNumber + 1;
			}
		}
	}
	if (!(OptionCoordStartingPoint == 0.0f))
	{
		optionColour = GetOptionColour();
		StringBase(OptionFont, optionColour.r, optionColour.g, optionColour.b, TextOutlineOptions);
		SET_TEXT_RIGHT_JUSTIFY(true);
		BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		if (*DisplayNumber == 1)
		{
			ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(change1);
		}		
		if (*DisplayNumber == 2)
		{
			ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(change2);
		}
		if (*DisplayNumber == 3)
		{
			ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(change3);
		}
		if (*DisplayNumber == 4)
		{
			ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(change4);
		}
		if (*DisplayNumber == 5)
		{
			ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(change5);
		}
		if (*DisplayNumber == 6)
		{
			ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(change6);
		}		
		if (*DisplayNumber == 7)
		{
			ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(change7);
		}
        END_TEXT_COMMAND_DISPLAY_TEXT(vector2((MenuXCoord2 - 0.066f), OptionCoord));
	}
}

void AddIntOptionSettings(const char* OptionText, int* DisplayNumber, int minValue, int maxValue)
{
	AddOption(OptionText);
	if (CurrentOption == OptionCount)
	{
		if (IsControlPressed(166)) // if control pressed
		{
			PlayMenuSound("NAV_LEFT_RIGHT"); // plays audio
			if (*DisplayNumber == minValue) // if the number is below the min value it will go to the maximum value
			{
				*DisplayNumber = maxValue;
			}
			else
			{
				*DisplayNumber = *DisplayNumber - 1; // if pressing left on the dpad it will take one off the current number
			}
		}
		else if (IsControlPressed(167)) // is right pressed
		{
			PlayMenuSound("NAV_LEFT_RIGHT"); // plays audio
			if (*DisplayNumber == maxValue) // if scrolls over max value it will loop back to min value
			{
				*DisplayNumber = minValue;
			}
			else
			{
				*DisplayNumber = *DisplayNumber + 1; // if the value is pressed on right it will add one to the current ammount
			}
		}
	}
	if (OptionCoordStartingPoint != 0.0f) //sees of OptionCoordStartingPoint is not equal to 0
	{
		StringBase(OptionFont, SelectedTextR, SelectedTextG, SelectedTextB, TextOutlineOptions);
		SET_TEXT_RIGHT_JUSTIFY(true);
		BEGIN_TEXT_COMMAND_DISPLAY_TEXT("NUMBER");
		ADD_TEXT_COMPONENT_INTEGER(*DisplayNumber);
		END_TEXT_COMMAND_DISPLAY_TEXT(vector2((MenuXCoord2 - 0.018f), OptionCoord));
	}
	if (CurrentOption == OptionCount)
	{
		AddInstructionalButton(DpadLeft, "-");
		AddInstructionalButton(DpadRight, "+");
	}
}

void Numberintoption(const char* Option, int* interger, int change)
{
	AddOption(Option);
	if (WasXJustPressed(177))
	{
		*interger = change;
	}
}

void DrawMenuOpeningBinds(int Button1, int Button2)
{
	float SpriteCoordStartingPoint = 0.0f;
    if ((CurrentOption < 7) || (SubmenuOptionCount <= 13))
	{
		if (!(OptionCount > 13))
		{
		    SpriteCoordStartingPoint = OptionCount;
		}
	}
	else if ((SubmenuOptionCount - CurrentOption) < 6)
	{
		if (!(OptionCount <= (SubmenuOptionCount - 13)))
		{
			SpriteCoordStartingPoint = OptionCount - (SubmenuOptionCount - 13);
		}
	}
	else if (!((OptionCount < (CurrentOption - 6)) || (OptionCount > (CurrentOption + 6))))
	{
		SpriteCoordStartingPoint = OptionCount - (CurrentOption - 7);
	}
	if (!(SpriteCoordStartingPoint == 0.0f))
	{
		SpriteCoord = (SpriteCoordStartingPoint * 0.035f) + (0.5871f - GetSafezoneSizeHalfed());
	    MaybeLoadTexture("erootiik");
	    if (HAS_STREAMED_TEXTURE_DICT_LOADED("erootiik"))
		{
			if (!(Button1 == 0))
			{
				DRAW_SPRITE("erootiik", straddiGlobal("button_", Button1), vector2((MenuXCoord2 - 0.066f), SpriteCoord), Size(0.016f, 0.0289f), 0.0f, RGBA(255, 255, 255, 255));
				if (!(Button2 == 0))
				{
					StringBase(OptionFont, 255, 255, 255, true);
					BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
					ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("+");
					END_TEXT_COMMAND_DISPLAY_TEXT(vector2((MenuXCoord2 - 0.0555f), OptionCoord));
				}
		    }
			if (!(Button2 == 0))
			{
				DRAW_SPRITE("erootiik", straddiGlobal("button_", Button2), vector2((MenuXCoord2 - 0.036f), SpriteCoord), Size(0.016f, 0.0289f), 0.0f, RGBA(255, 255, 255, 255));
			}
		}
	}
}	
	
void AddScriptOption(const char* OptionText, char* ScriptName, int StackSize, int Button1, int Button2, char* AMSG, char* DMSG)
{
	char* ErrorMessage;
	if (!DOES_SCRIPT_EXIST(ScriptName))
	{
		if (IS_PS3_VERSION())
		{
			ErrorMessage = ".csc Not Found!";
		}
		else 
		{
			ErrorMessage = ".xsc Not Found!";
		}
		AddOption(strcatGlobal(ScriptName, ErrorMessage));
	}
	else
	{
		AddOption(OptionText);
		DrawMenuOpeningBinds(Button1, Button2);
		AddOnOffOption(_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(ScriptName)));
		if (WasXJustPressed(177))
		{
			if (_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(ScriptName)) == 0)
			{
				ScriptToLoad = ScriptName;
				ScriptToLoadStackSize = StackSize;
				NotifyMSG("Boxuga", AMSG);
			}
			else
			{
				TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(ScriptName);
				NotifyMSG("Boxuga", DMSG);
			}
		}
		if (_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(ScriptName)) == 0)
		{
			if (CurrentOption == OptionCount)
			{
				if (DOES_SCRIPT_EXIST(ScriptName))
				{
					AddInstructionalButton(Cross, strcatGlobal("Load ", OptionText));
				}
			}
		}
		if (_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(ScriptName)) != 0)
		{
			if (CurrentOption == OptionCount)
			{
				if (DOES_SCRIPT_EXIST(ScriptName))
				{
					AddInstructionalButton(Cross, strcatGlobal("Unload ", OptionText));
				}
			}
		}
	}
}



void DrawInstructionalButtons()
{
	_PUSH_SCALEFORM_MOVIE_FUNCTION(InstructionalButtonsHandle, "DRAW_INSTRUCTIONAL_BUTTONS");
	_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	_PUSH_SCALEFORM_MOVIE_FUNCTION(InstructionalButtonsHandle, "SET_BACKGROUND_COLOUR");
	_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
	_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
	_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(0);
	_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(80);
	_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
	DrawInstructions = false;
}
	
void AddScriptOptionNoBinds(char* ScriptName, int* StackSize)
{
	if(!(IS_STRING_NULL_OR_EMPTY(ScriptName)))
	{
		AddOption(ScriptName);
		if (CurrentOption == OptionCount)
		{
			AddInstructionalButton(32, "Remove");
			if (IS_DISABLED_CONTROL_JUST_PRESSED(0, 179))
			{
				strcpy(ScriptName, "", 30);
				*StackSize = 0;
				CustomScriptCount--;
			}
		}
		if (DOES_SCRIPT_EXIST(ScriptName))
		{
			AddOnOffOption(_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(ScriptName)));
			AddIntOption(StackSize, 0, 19);
			if (WasXJustPressed(177))
		    {
			    if (_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(ScriptName)) == 0)
			    {
				    ScriptToLoad = ScriptName;
				    ScriptToLoadStackSize = GetStackSizeFromValue(*StackSize);
			    }
			    else
			    {
				    TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(ScriptName);
			    }
		    }
		}
	}
}

void AddSubmenuOption(const char* OptionText, char* Help, void* submenuLoc)
{
	AddOption(OptionText);
	if (CurrentOption == OptionCount)
	{
		AddInstructionalButton(Cross, Enter_Submenu_lang);
		AddInstructionalButton(Square, Help_lang);
	}
	if (WasXJustPressed(177))
	{
		LastSubmenu[SubmenuLevel] = CurrentSubmenu;
		LastOption[SubmenuLevel] = CurrentOption;
		CurrentSubmenu = submenuLoc;
		CurrentOption = 1;
		SubmenuLevel++;
	}

	if (WasXJustPressed(179))
	{
		NotifyMSG("Boxuga", Help);
	}
}

void AddCustomScriptOption()
{
	AddOption(AddScript_lang);
	if (WasXJustPressed(177))
	{
		DISPLAY_ONSCREEN_KEYBOARD(0, "", "", "", "", "", "", 31);
		KeyboardMonitoring = true;
	}
}

void SetKeyboardResultIntoOption(const char* ScriptName)
{
	if (IS_STRING_NULL_OR_EMPTY(CustomScript1))
	{
		strcpy(CustomScript1, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript2))
	{
		strcpy(CustomScript2, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript3))
	{
		strcpy(CustomScript3, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript4))
	{
		strcpy(CustomScript4, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript5))
	{
		strcpy(CustomScript5, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript6))
	{
		strcpy(CustomScript6, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript7))
	{
		strcpy(CustomScript7, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript8))
	{
		strcpy(CustomScript8, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript9))
	{
		strcpy(CustomScript9, ScriptName, 30);
	}
	else if (IS_STRING_NULL_OR_EMPTY(CustomScript10))
	{
		strcpy(CustomScript10, ScriptName, 30);
	}
}
	
void UpdateCustomScriptCount()
{
	if (!(CustomScriptCount == 10))
	{
		CustomScriptCount++;
	}
}

void UpdateCurrentOption()
{
	if (!(CustomScriptCount == 10))
	{
		CurrentOption++;
	}
}

void AddSubtext(const char* Subtitle)
{
	StringBase(TitleFont, 255, 255, 255, TextOutlineTitle);
	SET_TEXT_CENTRE(true);
	SET_TEXT_SCALE(0.0f, 0.3f);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Subtitle);
	END_TEXT_COMMAND_DISPLAY_TEXT(vector2(MenuXCoord3, (0.575f - GetSafezoneSizeHalfed()))); 
	OptionCount = 0;
}

void AddBoolOption(const char* OptionText, bool* toggle)
{
	AddOption(OptionText);
	AddOnOffOption(*toggle);
	if (WasXJustPressed(177))
	{
		*toggle = !*toggle;
	}

	if (CurrentOption == OptionCount)
	{
		AddInstructionalButton(Cross, strcatGlobal("Toggle ", OptionText));
	}
}

void AddBoolOptionNoOnOff(const char* OptionText, bool* toggle)
{
	AddOption(OptionText);
	if (WasXJustPressed(177))
	{
		*toggle = !*toggle;
	}
}




void NotifyOption(const char* OptionText, char* NotificationTitle, char* NotificationMSG)
{
	AddOption(OptionText); // displayed as an option
	if (WasXJustPressed(177)) // if the option was pressed
	{
		NotifyMSG(NotificationTitle, NotificationMSG);
	}
}


void ColorChanger()
{
	if (TitleColor == 1)
	{
		TitleR = 255;
		TitleG = 255;
		TitleB = 255;
	}
	if (TitleColor == 2)
	{
		TitleR = 0;
		TitleG = 0;
		TitleB = 0;
	}
	if (TitleColor == 3)
	{
		TitleR = 161;
		TitleG = 0;
		TitleB = 214;
	}
	if (TitleColor == 4)
	{
		TitleR = 0;
		TitleG = 255;
		TitleB = 72;
	}
	if (TitleColor == 5)
	{
		TitleR = 255;
		TitleG = 71;
		TitleB = 71;
	}
	if (BannerColor == 1)
	{
		BannerR = 161;
		BannerG = 0;
		BannerB = 214;
	}
	if (BannerColor == 2)
	{
		BannerR = 255;
		BannerG = 255;
		BannerB = 255;
	}
	if (BannerColor == 3)
	{
		BannerR = 0;
		BannerG = 0;
		BannerB = 0;
	}
	if (BannerColor == 4)
	{
		BannerR = 0;
		BannerG = 255;
		BannerB = 72;
	}
	if (BannerColor == 5)
	{
		BannerR = 255;
		BannerG = 71;
		BannerB = 71;
	}
	if (BackgroundColor == 1)
	{
		BackgroundR = 0;
		BackgroundG = 0;
		BackgroundB = 0;
	}
	if (BackgroundColor == 2)
	{
		BackgroundR = 161;
		BackgroundG = 0;
		BackgroundB = 214;
	}
	if (BackgroundColor == 3)
	{
		BackgroundR = 255;
		BackgroundG = 255;
		BackgroundB = 255;
	}
	if (BackgroundColor == 4)
	{
		BackgroundR = 0;
		BackgroundG = 255;
		BackgroundB = 72;
	}
	if (BackgroundColor == 5)
	{
		BackgroundR = 255;
		BackgroundG = 71;
		BackgroundB = 71;
	}
	if (SelectedTextColor == 1)
	{
		SelectedTextR = 255;
		SelectedTextG = 255;
		SelectedTextB = 255;
	}
	if (SelectedTextColor == 2)
	{
		SelectedTextR = 161;
		SelectedTextG = 0;
		SelectedTextB = 214;
	}	
	if (SelectedTextColor == 3)
	{
		SelectedTextR = 0;
		SelectedTextG = 0;
		SelectedTextB = 0;
	}	
	if (SelectedTextColor == 4)
	{
		SelectedTextR = 0;
		SelectedTextG = 255;
		SelectedTextB = 72;
	}	
	if (SelectedTextColor == 5)
	{
		SelectedTextR = 255;
		SelectedTextG = 71;
		SelectedTextB = 71;
	}
	if (UnselectedTextColor == 1)
	{
		UnselectedTextR = 255;
		UnselectedTextG = 255;
		UnselectedTextB = 255;
	}
	if (UnselectedTextColor == 2)
	{
		UnselectedTextR = 161;
		UnselectedTextG = 0;
		UnselectedTextB = 214;
	}
	if (UnselectedTextColor == 3)
	{
		UnselectedTextR = 0;
		UnselectedTextG = 0;
		UnselectedTextB = 0;
	}
	if (UnselectedTextColor == 4)
	{
		UnselectedTextR = 0;
		UnselectedTextG = 255;
		UnselectedTextB = 72;
	}
	if (UnselectedTextColor == 5)
	{
		UnselectedTextR = 255;
		UnselectedTextG = 71;
		UnselectedTextB = 71;
	}
	if (ScrollbarColor == 1)
	{
		ScrollbarR = 255;
	    ScrollbarG = 255;
		ScrollbarB = 255;
	}
	if (ScrollbarColor == 2)
	{
		ScrollbarR = 161;
		ScrollbarG = 0;
		ScrollbarB = 214;
	}
	if (ScrollbarColor == 3)
	{
		ScrollbarR = 0;
		ScrollbarG = 0;
		ScrollbarB = 0;
	}
	if (ScrollbarColor == 4)
	{
		ScrollbarR = 0;
		ScrollbarG = 255;
		ScrollbarB = 72;
	}
	if (ScrollbarColor == 5)
	{
		ScrollbarR = 255;
		ScrollbarG = 71;
		ScrollbarB = 71;
	}
}






void ChangeTime(const char* OptionText, int Hour, int Min, int Sec, int Type) 
{
	AddOption(OptionText);
	if (WasXJustPressed(177))
	{
		if (Type == 1)
		{
			SET_CLOCK_TIME(Hour, Min, Sec);
		}
		if (Type == 2)
		{
			ADD_TO_CLOCK_TIME(Hour, Min, Sec);
		}
	}
}

void AddDropDownBool(const char* OptionTXT, int AddedOptions, bool* BoolName)
{
	AddOption(OptionTXT);
	AddOnOffOption(*BoolName);
	if (WasXJustPressed(177))
	{
		EnabledDropdownOptionsSelf = AddedOptions;
		*BoolName = !*BoolName;
	}
	if (!*BoolName)
	{
		EnabledDropdownOptionsSelf = 0;
	}
}


void ChangeWeather(const char* OptionText, char* Weather)
{
	AddOption(OptionText);
	if (WasXJustPressed(177))
	{
		SET_WEATHER_TYPE_NOW(Weather);
	}
} // adds an option to change

void EvadePoliceEnforcement(const char* OptionTEXT)
{
	AddOption(OptionTEXT);
	if (WasXJustPressed(177))
	{
		CLEAR_PLAYER_WANTED_LEVEL(PLAYER_ID());
	}
}

void VehicleSpawner(const char* OptionText, int VHash)
{
	AddOption(OptionText);
	if (WasXJustPressed(177))
	{
		if (DeleteOldVehicle) // if the boolean is set to true then this will mean it will use this if statement
		{
			int currentvehicle = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID()); // makes a interger that acts as getting the current vehicle id
			SET_ENTITY_AS_MISSION_ENTITY(currentvehicle, true, true); // sets vehicle as a mission car
			DELETE_VEHICLE(&currentvehicle); // deletes the current vehicle
		}
		REQUEST_MODEL(VHash); // requsts to load the model in to memory
		while (!HAS_MODEL_LOADED(VHash)) // this means while the model has not loaded it will draw a notification and wait
		{ 
			if (CarSpawnNotification)
			{
				_SET_NOTIFICATION_TEXT_ENTRY("STRING");
				ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(strcatGlobal("Spawned your new ~g~", OptionText)); // This says your car spawned as a notification
				_SET_NOTIFICATION_MESSAGE("CHAR_MP_MECHANIC", "CHAR_MP_MECHANIC", 1, 7, strcatGlobal("~bold~", "Mechanic"), "");
				_DRAW_NOTIFICATION(false, false);
			}
			WAIT(0);
		} // this lets people know that the vehicle is going to be spawned soon
		float Enthead = GET_ENTITY_HEADING(PLAYER_PED_ID()); // sets EntHead to the value of what direction that player is looking at
		vector3 location = GET_ENTITY_COORDS(PLAYER_PED_ID(), false); // gets value of xyz and sets it as location
		int fuckedcar = CREATE_VEHICLE(VHash, vector3(location.x, location.y, location.z), Enthead, true, true); // spawns car
		if (Spawnincar)
		{
			SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), fuckedcar, -1); // spawns player in car
		}
	}
}

void carfix(const char* Optiontext)
{
	AddOption(Optiontext);
	if (WasXJustPressed(177))
	{
		int currentvehicle = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		SET_VEHICLE_FIXED(currentvehicle);
	}
}

void killvehicle(const char* OptionText, int type)
{
	AddOption(OptionText);
	if (WasXJustPressed(177))
	{
		int killfalcon = GET_VEHICLE_PED_IS_USING(PLAYER_PED_ID());
		if (type == 1)
		{
			SET_ENTITY_AS_MISSION_ENTITY(killfalcon, true, true);
			DELETE_VEHICLE(&killfalcon);
		}
		if (type == 2)
		{
			SET_VEHICLE_ENGINE_HEALTH(killfalcon, 0);
		}
	}
}

void TeleportOption(const char* OText, int x, int y, int z)
{
	AddOption(OText);
	if (WasXJustPressed(177))
	{
		NotifyMSG("Boxuga", "Please wait all textures need to load");
		START_PLAYER_TELEPORT(PLAYER_ID(), vector3(x, y, z), GET_ENTITY_HEADING(PLAYER_PED_ID()), true, true, true);
	}
}

void GiveAllWeapons(const char* Option)
{
	AddOption(Option);
	if (WasXJustPressed(177))
	{
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_PISTOL, 100000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_COMBATPISTOL, 100000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_PISTOL50, 100000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_SNSPISTOL, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_HEAVYPISTOL, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_VINTAGEPISTOL, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_MARKSMANPISTOL, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_APPISTOL, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_STUNGUN, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_FLAREGUN, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_MICROSMG, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_SMG, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_ASSAULTSMG, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_COMBATPDW, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_MG, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_COMBATMG, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_GUSENBERG, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_ASSAULTRIFLE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_CARBINERIFLE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_ADVANCEDRIFLE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_SPECIALCARBINE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_BULLPUPRIFLE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_SNIPERRIFLE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_HEAVYSNIPER, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_MARKSMANRIFLE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_KNIFE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_NIGHTSTICK, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_HAMMER, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_BAT, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_CROWBAR, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_GOLFCLUB, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_BOTTLE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_DAGGER, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_KNUCKLE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_PUMPSHOTGUN, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_SAWNOFFSHOTGUN, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_BULLPUPSHOTGUN, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_ASSAULTSHOTGUN, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_MUSKET, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_HEAVYSHOTGUN, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_GRENADELAUNCHER, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_RPG, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_MINIGUN, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_FIREWORK, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_HOMINGLAUNCHER, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_GRENADE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_STICKYBOMB, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_PROXMINE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_SMOKEGRENADE, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_BZGAS, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_MOLOTOV, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_FIREEXTINGUISHER, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_PETROLCAN, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_BALL, 10000, false, false);
		GIVE_WEAPON_TO_PED(PLAYER_PED_ID(), WEAPON_SNOWBALL, 10000, false, false);
	}
}

void RemoveWeapons(const char* Option)
{
	AddOption(Option);
	if (WasXJustPressed(177))
	{
		REMOVE_ALL_PED_WEAPONS(PLAYER_PED_ID(), false);
	}
}

void GiveMoneyOption(const char* OptionText, int AddedMoney)
{
	AddOption(OptionText);
	if (WasXJustPressed(177))
	{
		SET_PED_MONEY(PLAYER_PED_ID(), (GET_PED_MONEY(PLAYER_PED_ID()) + AddedMoney));
	}
}

void Suidcide(const char* Option)
{
	AddOption(Option);
	if (WasXJustPressed(177))
	{
		SET_ENTITY_HEALTH(PLAYER_PED_ID(), 0);
	}
}


void BackgroundChanger()
{
	if (background == 1)
	{
		BackgroundImage = "grime3"; // this is the default option
	}
	if (background == 2)
	{
		BackgroundImage = "grime4";
	}
	if (background == 3)
	{
		BackgroundImage = "filmreel";
	}
	if (background == 4)
	{
		BackgroundImage = "grime6";
	}
	if (background == 5)
	{
		BackgroundImage = "grime7";
	}
	if (background == 6)
	{
		BackgroundImage = "grime10";
	}
	if (background == 7)
	{
		BackgroundImage = "diana";
	}
	if (background == 8)
	{
		BackgroundImage = "grime1";
	}
	if (background == 9)
	{
		BackgroundImage = "grime2";
	}
	if (background == 10)
	{
		BackgroundImage = "grime8";
	}
}


void ResetColors(const char* Option)
{
	AddOption(Option);
	if (WasXJustPressed(177))
	{
		TitleR = 255;
		TitleG = 255;
		TitleB = 255;
		BackgroundR = 0;
	    BackgroundG = 0;
	    BackgroundB = 0;
		BackgroundA = 125;
		UnselectedTextR = 255; 
		UnselectedTextG = 255; 
		UnselectedTextB = 255;
		SelectedTextR = 255; 
		SelectedTextG = 255; 
		SelectedTextB = 255;
		BannerR = 161; 
		BannerG = 0; 
		BannerB = 214;
		BannerA = 235;
		SpriteOnR = 255; 
		SpriteOnG = 255; 
		SpriteOnB = 255; 
		SpriteOffR = 255; 
		SpriteOffG = 255; 
		SpriteOffB = 255;
		ScrollbarR = 255;
		ScrollbarG = 255;
		ScrollbarB = 255;
		ScrollbarA = 125;
		bgimage = true;
		base = 1;
	}
}
