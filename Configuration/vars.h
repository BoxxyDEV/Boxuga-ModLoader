void* CurrentSubmenu;
int DisableCinematicCameraTimer, CustomScriptCount, ScriptToLoadStackSize,  CurrentOption, SubmenuOptionCount, GlareHandle, OptionCountFont = 4, OptionCountR = 255, OptionCountG = 255, OptionCountB = 255, ScrollArrowsR = 255, ScrollArrowsG = 255, ScrollArrowsB = 255,  OptionCount, SubmenuLevel, ScrollTimer, OptionFont = 4, SpriteOutlineR, SpriteOutlineG, SpriteOutlineB, InstructionalButtonCount, InstructionalButtonsHandle;
int* LastSubmenu[10], LastOption[10], CustomScript1StackSize, CustomScript2StackSize, CustomScript3StackSize, CustomScript4StackSize, CustomScript5StackSize, CustomScript6StackSize, CustomScript7StackSize, CustomScript8StackSize, CustomScript9StackSize, CustomScript10StackSize;
bool AllowCustomScripts = false, AddCustomScript, AlreadyRequested, ScrollArrows = true, ScrollArrowsAlways, KeyboardMonitoring;
char* ScriptToLoad;
float ScrollbarCoord, MenuXCoord1, MenuXCoord2, MenuXCoord3, BackgroundCoord, BackgroundLength, BottomBarCoord, ScrolbarCoord, ScrollArrowsCoord, OptionCoordStartingPoint, OptionCoord, SpriteCoord;
char CustomScript1[30], CustomScript2[30], CustomScript3[30], CustomScript4[30], CustomScript5[30], CustomScript6[30], CustomScript7[30], CustomScript8[30], CustomScript9[30], CustomScript10[30];
bool DisableSpecialAbility = true;
bool SpriteOutline = false;
bool TextOutlineOptions = true;
bool TextOutlineTitle = true;
bool TextOutlineOptionCount = true;
bool SmoothScrolling = true;
bool DrawInstructions = true; // sets if instructions should be displayed
bool functioninstruction; // this value should not be edited
bool bgimage = true; // change this if u want it to not show the background image
bool LeftSided; // set this to true if you want the menu to be on the left side of the screen
bool BindHint = true;
bool OptionCountDisplay = true;
bool GodMode = false; // if this is set to true it will do auto god mode
bool NeverWanted = false; // if enabled player should be never wanted by the cops
bool FreezeTime = false; // freezes times
bool SuperJump = false; // sets a boolean if this value is changed to true then it will start the game with super jump
bool SonicRun = false; // sets a boolean if this value is toggled it will allow the player to run at the speed of sound
bool DoNotRagdoll = false; // if this is set true player should never ragdoll
bool Spawnincar = true; // if you set this to true then when u spawn a car it will spawn u in a car
bool DeleteOldVehicle = true; // deletes the current vehicle on spawn when set to true
bool CarSpawnNotification = true; // sends notification and says what it spawned
bool VehicleRepair = false; // if this is set to true then the car should never die
bool NightVision = false; // if this is set to true then if aiming with a weapon it will be night vision
bool ThermalVision = false; // if this is set to true then if aiming a weapon it will be thermal vision
bool Dismap = false; // if this is true it will not render the mini map
bool MobileRadio = false; // if set to true then the radio will be avalible on foot
bool InfinityAmmo = false; // set if all weapons have unlimited ammo
bool Moneydrop = false; // if set to true this means the player will have a money drop that it is 40k
bool UnlimitedSpecialAbility = false; // unlimited special ability
bool Vanish = false; // makes you gone
int MoneyBagType = 1; // change what type of money bag 1 for classic and 2 for pc style
int TitleFont = 7;
int BannerR = 161, BannerG, BannerB = 214, BannerA = 235;
int SpriteOnR = 255, SpriteOnG = 255, SpriteOnB = 255, SpriteOffR = 255, SpriteOffG = 255, SpriteOffB = 255;
int Bind1 = 166, Bind2 = 179;
int BackgroundR, BackgroundG, BackgroundB, BackgroundA = 125;
int UnselectedTextR = 255, UnselectedTextG = 255, UnselectedTextB = 255;
int SelectedTextR = 255, SelectedTextG = 255, SelectedTextB = 255;
int TitleR = 255, TitleG = 255, TitleB = 255;
int wantedlvl;
int EnabledDropdownOptionsSelf;
int background = 1; // 1 to 10
int base = 1; // 1 = nyd 2 = LTS 3 = purge look a like
int ToggleButtons = 1; // 1 = custom textures 2 = checkboxs
int ScrollbarR = 255, ScrollbarG = 255, ScrollbarB = 255, ScrollbarA = 125;
char* Background_name = "boxuga"; // specifys default background and creates string
char* Start_MSG = "Welecome To Boxuga Loader to Open Press ~INPUT_SCRIPT_PAD_LEFT~ + ~INPUT_FRONTEND_X~";
char* vername = "Beta 0.1";
char* coolbannas;
char *BackgroundImage = "grime3"; 
