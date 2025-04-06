# 1 "data/maps/Route120/scripts.pory"

# 2 "data/maps/Route120/scripts.pory"
.set LOCALID_BRIDGE_KECLEON, 29
# 3 "data/maps/Route120/scripts.pory"
.set LOCALID_STEVEN, 30
# 4 "data/maps/Route120/scripts.pory"
.set LOCALID_BRIDGE_KECLEON_SHADOW, 35  @ They use a second object which is identical to Kecleon but has a reflection palette tag for the bridge shadow
# 5 "data/maps/Route120/scripts.pory"
.set LOCALID_CHIP, 24
# 6 "data/maps/Route120/scripts.pory"
.set LOCALID_JEFFREY, 15
# 7 "data/maps/Route120/scripts.pory"
.set LOCALID_KEIGO, 33
# 8 "data/maps/Route120/scripts.pory"
.set LOCALID_RILEY, 34
# 9 "data/maps/Route120/scripts.pory"
.set LOCALID_LORENZO, 13
# 10 "data/maps/Route120/scripts.pory"
.set LOCALID_JENNA, 14
# 11 "data/maps/Route120/scripts.pory"
.set LOCALID_CALLIE, 41
# 12 "data/maps/Route120/scripts.pory"
.set LOCALID_JENNIFER, 23
# 13 "data/maps/Route120/scripts.pory"
.set LOCALID_ROBERT, 12
# 14 "data/maps/Route120/scripts.pory"
.set LOCALID_CLARISSA, 25
# 15 "data/maps/Route120/scripts.pory"
.set LOCALID_ANGELICA, 26
# 16 "data/maps/Route120/scripts.pory"
.set LOCALID_COLIN, 42
# 17 "data/maps/Route120/scripts.pory"

# 18 "data/maps/Route120/scripts.pory"
Route120_MapScripts::
# 19 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route120_OnResume
# 20 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_OnTransition
# 21 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route120_OnLoad
# 22 "data/maps/Route120/scripts.pory"
	.byte 0
# 23 "data/maps/Route120/scripts.pory"

# 24 "data/maps/Route120/scripts.pory"
Route120_OnResume:
# 25 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_ABNORMAL_WEATHER_SUN, Common_EventScript_SetWeatherIntenseSun
# 26 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route120_EventScript_RemoveKecleonObject
# 27 "data/maps/Route120/scripts.pory"
	end
# 28 "data/maps/Route120/scripts.pory"

# 29 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleonObject::
# 30 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 0, Route120_EventScript_RemoveBridgeKecleon
# 31 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 1, Route120_EventScript_RemoveKecleon
# 32 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 2, Route120_EventScript_RemoveKecleon
# 33 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 3, Route120_EventScript_RemoveKecleon
# 34 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 4, Route120_EventScript_RemoveKecleon
# 35 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 5, Route120_EventScript_RemoveKecleon
# 36 "data/maps/Route120/scripts.pory"
	return
# 37 "data/maps/Route120/scripts.pory"

# 38 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleon::
# 39 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 40 "data/maps/Route120/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 41 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON
# 42 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
# 43 "data/maps/Route120/scripts.pory"
	return
# 44 "data/maps/Route120/scripts.pory"

# 45 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleon::
# 46 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 47 "data/maps/Route120/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 48 "data/maps/Route120/scripts.pory"
	removeobject VAR_LAST_TALKED
# 49 "data/maps/Route120/scripts.pory"
	return
# 50 "data/maps/Route120/scripts.pory"

# 51 "data/maps/Route120/scripts.pory"
Route120_OnLoad:
# 52 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_ABNORMAL_WEATHER_SUN, Common_EventScript_SetWeatherIntenseSun
# 53 "data/maps/Route120/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route120_EventScript_CloseAncientTomb
# 54 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeClearMetatiles
# 55 "data/maps/Route120/scripts.pory"
	call_if_unset FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeKecleonMovement
# 56 "data/maps/Route120/scripts.pory"
	end
# 57 "data/maps/Route120/scripts.pory"

# 58 "data/maps/Route120/scripts.pory"
Route120_EventScript_CloseAncientTomb::
# 59 "data/maps/Route120/scripts.pory"
	setmetatile 7, 54, METATILE_General_RockWall_RockBase, TRUE
# 60 "data/maps/Route120/scripts.pory"
	setmetatile 7, 55, METATILE_General_RockWall_SandBase, TRUE
# 61 "data/maps/Route120/scripts.pory"
	return
# 62 "data/maps/Route120/scripts.pory"

# 63 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeClearMetatiles::
# 64 "data/maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
# 65 "data/maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
# 66 "data/maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
# 67 "data/maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
# 68 "data/maps/Route120/scripts.pory"
	return
# 69 "data/maps/Route120/scripts.pory"

# 70 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeKecleonMovement::
# 71 "data/maps/Route120/scripts.pory"
	setobjectmovementtype LOCALID_BRIDGE_KECLEON_SHADOW, MOVEMENT_TYPE_FACE_RIGHT
# 72 "data/maps/Route120/scripts.pory"
	return
# 73 "data/maps/Route120/scripts.pory"

# 74 "data/maps/Route120/scripts.pory"
Route120_OnTransition:
# 75 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_ABNORMAL_WEATHER_SUN, Common_EventScript_SetWeatherIntenseSun
# 76 "data/maps/Route120/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 77 "data/maps/Route120/scripts.pory"
	call Route120_EventScript_SetWeather
# 78 "data/maps/Route120/scripts.pory"
	end
# 79 "data/maps/Route120/scripts.pory"

# 80 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetWeather::
# 81 "data/maps/Route120/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 82 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_1, 14, Route120_EventScript_SetSunnyWeather
# 83 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_1, 60, Route120_EventScript_TrySetRainyWeather
# 84 "data/maps/Route120/scripts.pory"
	goto_if_ge VAR_TEMP_1, 61, Route120_EventScript_SetCloudyWeather
# 85 "data/maps/Route120/scripts.pory"
	return
# 86 "data/maps/Route120/scripts.pory"

# 87 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetCloudyWeather::
# 88 "data/maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 89 "data/maps/Route120/scripts.pory"
	return
# 90 "data/maps/Route120/scripts.pory"

# 91 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetSunnyWeather::
# 92 "data/maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY
# 93 "data/maps/Route120/scripts.pory"
	return
# 94 "data/maps/Route120/scripts.pory"

# 95 "data/maps/Route120/scripts.pory"
Route120_EventScript_TrySetRainyWeather::
# 96 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_0, 7, Route120_EventScript_SetRainyWeather
# 97 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_0, 19, Route120_EventScript_SetSunnyWeather
# 98 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_SetRainyWeather
# 99 "data/maps/Route120/scripts.pory"
	end
# 100 "data/maps/Route120/scripts.pory"

# 101 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetRainyWeather::
# 102 "data/maps/Route120/scripts.pory"
	setweather WEATHER_RAIN
# 103 "data/maps/Route120/scripts.pory"
	return
# 104 "data/maps/Route120/scripts.pory"

# 105 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryBeauty::
# 106 "data/maps/Route120/scripts.pory"
	lock
# 107 "data/maps/Route120/scripts.pory"
	faceplayer
# 108 "data/maps/Route120/scripts.pory"
	dotimebasedevents
# 109 "data/maps/Route120/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_120_RECEIVED_BERRY, Route120_EventScript_ReceivedBerry
# 110 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_BerriesExpressionOfLoveIsntIt, MSGBOX_YESNO
# 111 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route120_EventScript_BerryLove
# 112 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route120_EventScript_BerryNotLove
# 113 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
# 114 "data/maps/Route120/scripts.pory"
	switch VAR_RESULT
# 115 "data/maps/Route120/scripts.pory"
	case 0, Route120_EventScript_GiveFigyBerry
# 116 "data/maps/Route120/scripts.pory"
	case 5, Route120_EventScript_GiveFigyBerry
# 117 "data/maps/Route120/scripts.pory"
	case 1, Route120_EventScript_GiveWikiBerry
# 118 "data/maps/Route120/scripts.pory"
	case 6, Route120_EventScript_GiveWikiBerry
# 119 "data/maps/Route120/scripts.pory"
	case 2, Route120_EventScript_GiveMagoBerry
# 120 "data/maps/Route120/scripts.pory"
	case 7, Route120_EventScript_GiveMagoBerry
# 121 "data/maps/Route120/scripts.pory"
	case 3, Route120_EventScript_GiveAguavBerry
# 122 "data/maps/Route120/scripts.pory"
	case 8, Route120_EventScript_GiveAguavBerry
# 123 "data/maps/Route120/scripts.pory"
	case 4, Route120_EventScript_GiveIapapaBerry
# 124 "data/maps/Route120/scripts.pory"
	case 9, Route120_EventScript_GiveIapapaBerry
# 125 "data/maps/Route120/scripts.pory"
	end
# 126 "data/maps/Route120/scripts.pory"

# 127 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveFigyBerry::
# 128 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_FIGY_BERRY
# 129 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 130 "data/maps/Route120/scripts.pory"
	end
# 131 "data/maps/Route120/scripts.pory"

# 132 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveWikiBerry::
# 133 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_WIKI_BERRY
# 134 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 135 "data/maps/Route120/scripts.pory"
	end
# 136 "data/maps/Route120/scripts.pory"

# 137 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveMagoBerry::
# 138 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_MAGO_BERRY
# 139 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 140 "data/maps/Route120/scripts.pory"
	end
# 141 "data/maps/Route120/scripts.pory"

# 142 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveAguavBerry::
# 143 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_AGUAV_BERRY
# 144 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 145 "data/maps/Route120/scripts.pory"
	end
# 146 "data/maps/Route120/scripts.pory"

# 147 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveIapapaBerry::
# 148 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_IAPAPA_BERRY
# 149 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 150 "data/maps/Route120/scripts.pory"
	end
# 151 "data/maps/Route120/scripts.pory"

# 152 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveBerry::
# 153 "data/maps/Route120/scripts.pory"
	giveitem VAR_0x8004
# 154 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 155 "data/maps/Route120/scripts.pory"
	setflag FLAG_DAILY_ROUTE_120_RECEIVED_BERRY
# 156 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_BerryIsRareRaiseItWithCare, MSGBOX_DEFAULT
# 157 "data/maps/Route120/scripts.pory"
	release
# 158 "data/maps/Route120/scripts.pory"
	end
# 159 "data/maps/Route120/scripts.pory"

# 160 "data/maps/Route120/scripts.pory"
Route120_EventScript_ReceivedBerry::
# 161 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_IllGetMoreBerriesFromBerryMaster, MSGBOX_DEFAULT
# 162 "data/maps/Route120/scripts.pory"
	release
# 163 "data/maps/Route120/scripts.pory"
	end
# 164 "data/maps/Route120/scripts.pory"

# 165 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryLove::
# 166 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_YesYouUnderstand, MSGBOX_DEFAULT
# 167 "data/maps/Route120/scripts.pory"
	return
# 168 "data/maps/Route120/scripts.pory"

# 169 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryNotLove::
# 170 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_MakeYourOwnImpressions, MSGBOX_DEFAULT
# 171 "data/maps/Route120/scripts.pory"
	return
# 172 "data/maps/Route120/scripts.pory"

# 173 "data/maps/Route120/scripts.pory"
Route120_EventScript_Steven::
# 174 "data/maps/Route120/scripts.pory"
	lock
# 175 "data/maps/Route120/scripts.pory"
	faceplayer
# 176 "data/maps/Route120/scripts.pory"
	goto_if_set FLAG_NOT_READY_FOR_BATTLE_ROUTE_120, Route120_EventScript_StevenAskReadyForBattle
# 177 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGreeting, MSGBOX_YESNO
# 178 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
# 179 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 180 "data/maps/Route120/scripts.pory"
	end
# 181 "data/maps/Route120/scripts.pory"

# 182 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenNotReady::
# 183 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenIllWaitHere, MSGBOX_DEFAULT
# 184 "data/maps/Route120/scripts.pory"
	setflag FLAG_NOT_READY_FOR_BATTLE_ROUTE_120
# 185 "data/maps/Route120/scripts.pory"
	release
# 186 "data/maps/Route120/scripts.pory"
	end
# 187 "data/maps/Route120/scripts.pory"

# 188 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenAskReadyForBattle::
# 189 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenReadyForBattle, MSGBOX_YESNO
# 190 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
# 191 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 192 "data/maps/Route120/scripts.pory"
	end
# 193 "data/maps/Route120/scripts.pory"

# 194 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenBattleKecleon::
# 195 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenShowMeYourPower, MSGBOX_DEFAULT
# 196 "data/maps/Route120/scripts.pory"
	closemessage
# 197 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route120_EventScript_PlayerApproachKecleonEast
# 198 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterLeft
# 199 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 200 "data/maps/Route120/scripts.pory"
	delay 20
# 201 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenUsedDevonScope, MSGBOX_DEFAULT
# 202 "data/maps/Route120/scripts.pory"
	closemessage
# 203 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_BRIDGE_KECLEON, Common_Movement_WalkInPlaceFasterUp
# 204 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 205 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_BRIDGE_KECLEON, Movement_KecleonAppears
# 206 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 207 "data/maps/Route120/scripts.pory"
	waitse
# 208 "data/maps/Route120/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
# 209 "data/maps/Route120/scripts.pory"
	delay 40
# 210 "data/maps/Route120/scripts.pory"
	waitmoncry
# 211 "data/maps/Route120/scripts.pory"
	setwildbattle SPECIES_KECLEON, 30
# 212 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8009, 0
# 213 "data/maps/Route120/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 214 "data/maps/Route120/scripts.pory"
	dowildbattle
# 215 "data/maps/Route120/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 216 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 217 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 218 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 219 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 220 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 221 "data/maps/Route120/scripts.pory"
	end
# 222 "data/maps/Route120/scripts.pory"

# 223 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleonPostBattle::
# 224 "data/maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 225 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON
# 226 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
# 227 "data/maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 228 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 229 "data/maps/Route120/scripts.pory"
	end
# 230 "data/maps/Route120/scripts.pory"

# 231 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenGiveDeconScope::
# 232 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterLeft
# 233 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 234 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 235 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGiveDevonScope, MSGBOX_DEFAULT
# 236 "data/maps/Route120/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 237 "data/maps/Route120/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 238 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGoodbye, MSGBOX_DEFAULT
# 239 "data/maps/Route120/scripts.pory"
	closemessage
# 240 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
# 241 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 242 "data/maps/Route120/scripts.pory"
	delay 50
# 243 "data/maps/Route120/scripts.pory"
	setfieldeffectargument 0, 1
# 244 "data/maps/Route120/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 245 "data/maps/Route120/scripts.pory"
	delay 15
# 246 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_STEVEN
# 247 "data/maps/Route120/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 248 "data/maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
# 249 "data/maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
# 250 "data/maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
# 251 "data/maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
# 252 "data/maps/Route120/scripts.pory"
	special DrawWholeMapView
# 253 "data/maps/Route120/scripts.pory"
	release
# 254 "data/maps/Route120/scripts.pory"
	end
# 255 "data/maps/Route120/scripts.pory"

# 256 "data/maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonNorth::
# 257 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 258 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 259 "data/maps/Route120/scripts.pory"
	return
# 260 "data/maps/Route120/scripts.pory"

# 261 "data/maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonEast::
# 262 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route120_Movement_ApproachKecleonEast
# 263 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 264 "data/maps/Route120/scripts.pory"
	return
# 265 "data/maps/Route120/scripts.pory"

# 266 "data/maps/Route120/scripts.pory"
Route120_Movement_ApproachKecleonEast:
# 267 "data/maps/Route120/scripts.pory"
	face_down
# 268 "data/maps/Route120/scripts.pory"
	step_end
# 269 "data/maps/Route120/scripts.pory"

# 270 "data/maps/Route120/scripts.pory"
Route120_EventScript_BridgeKecleon::
# 271 "data/maps/Route120/scripts.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_NPC
# 272 "data/maps/Route120/scripts.pory"
	end
# 273 "data/maps/Route120/scripts.pory"

# 274 "data/maps/Route120/scripts.pory"
Route120_EventScript_RouteSignFortree::
# 275 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSignFortree, MSGBOX_SIGN
# 276 "data/maps/Route120/scripts.pory"
	end
# 277 "data/maps/Route120/scripts.pory"

# 278 "data/maps/Route120/scripts.pory"
Route120_EventScript_RouteSign121::
# 279 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSign121, MSGBOX_SIGN
# 280 "data/maps/Route120/scripts.pory"
	end
# 281 "data/maps/Route120/scripts.pory"

# 282 "data/maps/Route120/scripts.pory"
Route120_EventScript_ColinAngelica::
# 283 "data/maps/Route120/scripts.pory"
lockall
# 284 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_COLIN
# 285 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 286 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 287 "data/maps/Route120/scripts.pory"
waitmovement 0
# 288 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 289 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 290 "data/maps/Route120/scripts.pory"
waitmovement 0
# 291 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ColinIntro MSGBOX_AUTOCLOSE
# 292 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_ANGELICA
# 293 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 294 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 295 "data/maps/Route120/scripts.pory"
waitmovement 0
# 296 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 297 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 298 "data/maps/Route120/scripts.pory"
waitmovement 0
# 299 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_AngelicaIntro MSGBOX_AUTOCLOSE
# 300 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_ColinAngelicaDoMultiBattle
# 301 "data/maps/Route120/scripts.pory"
releaseall
# 302 "data/maps/Route120/scripts.pory"
end
# 303 "data/maps/Route120/scripts.pory"

# 304 "data/maps/Route120/scripts.pory"
Route120_EventScript_ColinAngelicaDoMultiBattle::
# 305 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 306 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_COLIN, Route120_Text_ColinDefeat, TRAINER_ANGELICA, Route120_Text_AngelicaDefeat, PARTNER_EMMIE
# 307 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 308 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_ColinAngelicaVictory
# 309 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 310 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 311 "data/maps/Route120/scripts.pory"
waitstate
# 312 "data/maps/Route120/scripts.pory"

# 313 "data/maps/Route120/scripts.pory"
Route120_EventScript_ColinAngelicaVictory::
# 314 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 315 "data/maps/Route120/scripts.pory"
waitmovement 0
# 316 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
# 317 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 318 "data/maps/Route120/scripts.pory"
waitmovement 0
# 319 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
# 320 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 321 "data/maps/Route120/scripts.pory"
end
# 322 "data/maps/Route120/scripts.pory"

# 323 "data/maps/Route120/scripts.pory"
Route120_EventScript_Colin::
# 324 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
# 325 "data/maps/Route120/scripts.pory"
	end
# 326 "data/maps/Route120/scripts.pory"

# 327 "data/maps/Route120/scripts.pory"
Route120_EventScript_ClarissaRobert::
# 328 "data/maps/Route120/scripts.pory"
lockall
# 329 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_CLARISSA
# 330 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 331 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 332 "data/maps/Route120/scripts.pory"
waitmovement 0
# 333 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 334 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 335 "data/maps/Route120/scripts.pory"
waitmovement 0
# 336 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ClarissaIntro MSGBOX_AUTOCLOSE
# 337 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_ROBERT
# 338 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 339 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 340 "data/maps/Route120/scripts.pory"
waitmovement 0
# 341 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 342 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 343 "data/maps/Route120/scripts.pory"
waitmovement 0
# 344 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_RobertIntro MSGBOX_AUTOCLOSE
# 345 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_ClarissaRobertDoMultiBattle
# 346 "data/maps/Route120/scripts.pory"
releaseall
# 347 "data/maps/Route120/scripts.pory"
end
# 348 "data/maps/Route120/scripts.pory"

# 349 "data/maps/Route120/scripts.pory"
Route120_EventScript_ClarissaRobertDoMultiBattle::
# 350 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 351 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_CLARISSA, Route120_Text_ClarissaDefeat, TRAINER_ROBERT_1, Route120_Text_RobertDefeat, PARTNER_EMMIE
# 352 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 353 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_ClarissaRobertVictory
# 354 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 355 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 356 "data/maps/Route120/scripts.pory"
waitstate
# 357 "data/maps/Route120/scripts.pory"

# 358 "data/maps/Route120/scripts.pory"
Route120_EventScript_ClarissaRobertVictory::
# 359 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 360 "data/maps/Route120/scripts.pory"
waitmovement 0
# 361 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ClarissaPostBattle, MSGBOX_AUTOCLOSE
# 362 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 363 "data/maps/Route120/scripts.pory"
waitmovement 0
# 364 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_RobertPostBattle, MSGBOX_AUTOCLOSE
# 365 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 366 "data/maps/Route120/scripts.pory"
end
# 367 "data/maps/Route120/scripts.pory"

# 368 "data/maps/Route120/scripts.pory"
Route120_EventScript_Robert::
# 369 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostBattle, MSGBOX_DEFAULT
# 370 "data/maps/Route120/scripts.pory"
	release
# 371 "data/maps/Route120/scripts.pory"
	end
# 372 "data/maps/Route120/scripts.pory"

# 373 "data/maps/Route120/scripts.pory"
Route120_EventScript_RegisterRobert::
# 374 "data/maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 375 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 376 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertRegister, MSGBOX_DEFAULT
# 377 "data/maps/Route120/scripts.pory"
	register_matchcall TRAINER_ROBERT_1
# 378 "data/maps/Route120/scripts.pory"
	release
# 379 "data/maps/Route120/scripts.pory"
	end
# 380 "data/maps/Route120/scripts.pory"

# 381 "data/maps/Route120/scripts.pory"
Route120_EventScript_RematchRobert::
# 382 "data/maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_ROBERT_1, Route120_Text_RobertRematchIntro, Route120_Text_RobertRematchDefeat
# 383 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostRematch, MSGBOX_AUTOCLOSE
# 384 "data/maps/Route120/scripts.pory"
	end
# 385 "data/maps/Route120/scripts.pory"

# 386 "data/maps/Route120/scripts.pory"
Route120_EventScript_JennaLorenzo::
# 387 "data/maps/Route120/scripts.pory"
lockall
# 388 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_JENNA
# 389 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 390 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 391 "data/maps/Route120/scripts.pory"
waitmovement 0
# 392 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 393 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 394 "data/maps/Route120/scripts.pory"
waitmovement 0
# 395 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JennaIntro MSGBOX_AUTOCLOSE
# 396 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_LORENZO
# 397 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 398 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 399 "data/maps/Route120/scripts.pory"
waitmovement 0
# 400 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 401 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 402 "data/maps/Route120/scripts.pory"
waitmovement 0
# 403 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_LorenzoIntro MSGBOX_AUTOCLOSE
# 404 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_JennaLorenzoDoMultiBattle
# 405 "data/maps/Route120/scripts.pory"
releaseall
# 406 "data/maps/Route120/scripts.pory"
end
# 407 "data/maps/Route120/scripts.pory"

# 408 "data/maps/Route120/scripts.pory"
Route120_EventScript_JennaLorenzoDoMultiBattle::
# 409 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 410 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_JENNA, Route120_Text_JennaDefeat, TRAINER_LORENZO, Route120_Text_LorenzoDefeat, PARTNER_EMMIE
# 411 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 412 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_JennaLorenzoVictory
# 413 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 414 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 415 "data/maps/Route120/scripts.pory"
waitstate
# 416 "data/maps/Route120/scripts.pory"

# 417 "data/maps/Route120/scripts.pory"
Route120_EventScript_JennaLorenzoVictory::
# 418 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 419 "data/maps/Route120/scripts.pory"
waitmovement 0
# 420 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
# 421 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 422 "data/maps/Route120/scripts.pory"
waitmovement 0
# 423 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_LorenzoPostBattle, MSGBOX_AUTOCLOSE
# 424 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 425 "data/maps/Route120/scripts.pory"
end
# 426 "data/maps/Route120/scripts.pory"

# 427 "data/maps/Route120/scripts.pory"
Route120_EventScript_Lorenzo::
# 428 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LorenzoPostBattle, MSGBOX_AUTOCLOSE
# 429 "data/maps/Route120/scripts.pory"
	end
# 430 "data/maps/Route120/scripts.pory"

# 431 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jenna::
# 432 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
# 433 "data/maps/Route120/scripts.pory"
	end
# 434 "data/maps/Route120/scripts.pory"

# 435 "data/maps/Route120/scripts.pory"
Route120_EventScript_ChipJeffrey::
# 436 "data/maps/Route120/scripts.pory"
lockall
# 437 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_CHIP
# 438 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 439 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 440 "data/maps/Route120/scripts.pory"
waitmovement 0
# 441 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 442 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 443 "data/maps/Route120/scripts.pory"
waitmovement 0
# 444 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ChipIntro MSGBOX_AUTOCLOSE
# 445 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_JEFFREY
# 446 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 447 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 448 "data/maps/Route120/scripts.pory"
waitmovement 0
# 449 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 450 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 451 "data/maps/Route120/scripts.pory"
waitmovement 0
# 452 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JeffreyIntro MSGBOX_AUTOCLOSE
# 453 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_ChipJeffreyDoMultiBattle
# 454 "data/maps/Route120/scripts.pory"
releaseall
# 455 "data/maps/Route120/scripts.pory"
end
# 456 "data/maps/Route120/scripts.pory"

# 457 "data/maps/Route120/scripts.pory"
Route120_EventScript_ChipJeffreyDoMultiBattle::
# 458 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 459 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_CHIP, Route120_Text_ChipDefeat, TRAINER_JEFFREY_1, Route120_Text_JeffreyDefeat, PARTNER_EMMIE
# 460 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 461 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_ChipJeffreyVictory
# 462 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 463 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 464 "data/maps/Route120/scripts.pory"
waitstate
# 465 "data/maps/Route120/scripts.pory"

# 466 "data/maps/Route120/scripts.pory"
Route120_EventScript_ChipJeffreyVictory::
# 467 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 468 "data/maps/Route120/scripts.pory"
waitmovement 0
# 469 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
# 470 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 471 "data/maps/Route120/scripts.pory"
waitmovement 0
# 472 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JeffreyPostBattle, MSGBOX_AUTOCLOSE
# 473 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 474 "data/maps/Route120/scripts.pory"
end
# 475 "data/maps/Route120/scripts.pory"

# 476 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jeffrey::
# 477 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostBattle, MSGBOX_DEFAULT
# 478 "data/maps/Route120/scripts.pory"
	release
# 479 "data/maps/Route120/scripts.pory"
	end
# 480 "data/maps/Route120/scripts.pory"

# 481 "data/maps/Route120/scripts.pory"
Route120_EventScript_RegisterJeffrey::
# 482 "data/maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 483 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 484 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyRegister, MSGBOX_DEFAULT
# 485 "data/maps/Route120/scripts.pory"
	register_matchcall TRAINER_JEFFREY_1
# 486 "data/maps/Route120/scripts.pory"
	release
# 487 "data/maps/Route120/scripts.pory"
	end
# 488 "data/maps/Route120/scripts.pory"

# 489 "data/maps/Route120/scripts.pory"
Route120_EventScript_RematchJeffrey::
# 490 "data/maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_JEFFREY_1, Route120_Text_JeffreyRematchIntro, Route120_Text_JeffreyRematchDefeat
# 491 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostRematch, MSGBOX_AUTOCLOSE
# 492 "data/maps/Route120/scripts.pory"
	end
# 493 "data/maps/Route120/scripts.pory"

# 494 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jennifer::
# 495 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
# 496 "data/maps/Route120/scripts.pory"
	end
# 497 "data/maps/Route120/scripts.pory"

# 498 "data/maps/Route120/scripts.pory"
Route120_EventScript_Chip::
# 499 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
# 500 "data/maps/Route120/scripts.pory"
	end
# 501 "data/maps/Route120/scripts.pory"

# 502 "data/maps/Route120/scripts.pory"
Route120_EventScript_Clarissa::
# 503 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ClarissaPostBattle, MSGBOX_AUTOCLOSE
# 504 "data/maps/Route120/scripts.pory"
	end
# 505 "data/maps/Route120/scripts.pory"

# 506 "data/maps/Route120/scripts.pory"
Route120_EventScript_Angelica::
# 507 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
# 508 "data/maps/Route120/scripts.pory"
	end
# 509 "data/maps/Route120/scripts.pory"

# 510 "data/maps/Route120/scripts.pory"
Route120_EventScript_KeigoRiley::
# 511 "data/maps/Route120/scripts.pory"
lockall
# 512 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_KEIGO
# 513 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 514 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 515 "data/maps/Route120/scripts.pory"
waitmovement 0
# 516 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 517 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 518 "data/maps/Route120/scripts.pory"
waitmovement 0
# 519 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_KeigoIntro MSGBOX_AUTOCLOSE
# 520 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_RILEY
# 521 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 522 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 523 "data/maps/Route120/scripts.pory"
waitmovement 0
# 524 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 525 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 526 "data/maps/Route120/scripts.pory"
waitmovement 0
# 527 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_RileyIntro MSGBOX_AUTOCLOSE
# 528 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_KeigoRileyDoMultiBattle
# 529 "data/maps/Route120/scripts.pory"
releaseall
# 530 "data/maps/Route120/scripts.pory"
end
# 531 "data/maps/Route120/scripts.pory"

# 532 "data/maps/Route120/scripts.pory"
Route120_EventScript_KeigoRileyDoMultiBattle::
# 533 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 534 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_KEIGO, Route120_Text_KeigoDefeat, TRAINER_RILEY, Route120_Text_RileyDefeat, PARTNER_EMMIE
# 535 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 536 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_KeigoRileyVictory
# 537 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 538 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 539 "data/maps/Route120/scripts.pory"
waitstate
# 540 "data/maps/Route120/scripts.pory"

# 541 "data/maps/Route120/scripts.pory"
Route120_EventScript_KeigoRileyVictory::
# 542 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 543 "data/maps/Route120/scripts.pory"
waitmovement 0
# 544 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
# 545 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 546 "data/maps/Route120/scripts.pory"
waitmovement 0
# 547 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
# 548 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 549 "data/maps/Route120/scripts.pory"
end
# 550 "data/maps/Route120/scripts.pory"

# 551 "data/maps/Route120/scripts.pory"
Route120_EventScript_Keigo::
# 552 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
# 553 "data/maps/Route120/scripts.pory"
	end
# 554 "data/maps/Route120/scripts.pory"

# 555 "data/maps/Route120/scripts.pory"
Route120_EventScript_Riley::
# 556 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
# 557 "data/maps/Route120/scripts.pory"
	end
# 558 "data/maps/Route120/scripts.pory"

# 559 "data/maps/Route120/scripts.pory"
Route120_EventScript_Leonel::
# 560 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_LEONEL, Route120_Text_LeonelIntro, Route120_Text_LeonelDefeat
# 561 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LeonelPostBattle, MSGBOX_AUTOCLOSE
# 562 "data/maps/Route120/scripts.pory"
	end
# 563 "data/maps/Route120/scripts.pory"

# 564 "data/maps/Route120/scripts.pory"
Route120_EventScript_JenniferCallie::
# 565 "data/maps/Route120/scripts.pory"
lockall
# 566 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_JENNIFER
# 567 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 568 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 569 "data/maps/Route120/scripts.pory"
waitmovement 0
# 570 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 571 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 572 "data/maps/Route120/scripts.pory"
waitmovement 0
# 573 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JenniferIntro MSGBOX_AUTOCLOSE
# 574 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_CALLIE
# 575 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 576 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 577 "data/maps/Route120/scripts.pory"
waitmovement 0
# 578 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 579 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 580 "data/maps/Route120/scripts.pory"
waitmovement 0
# 581 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_CallieIntro MSGBOX_AUTOCLOSE
# 582 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_JenniferCallieDoMultiBattle
# 583 "data/maps/Route120/scripts.pory"
releaseall
# 584 "data/maps/Route120/scripts.pory"
end
# 585 "data/maps/Route120/scripts.pory"

# 586 "data/maps/Route120/scripts.pory"
Route120_EventScript_JenniferCallieDoMultiBattle::
# 587 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 588 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_JENNIFER, Route120_Text_JenniferDefeat, TRAINER_CALLIE, Route120_Text_CallieDefeat, PARTNER_EMMIE
# 589 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 590 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_JenniferCallieVictory
# 591 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 592 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 593 "data/maps/Route120/scripts.pory"
waitstate
# 594 "data/maps/Route120/scripts.pory"

# 595 "data/maps/Route120/scripts.pory"
Route120_EventScript_JenniferCallieVictory::
# 596 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 597 "data/maps/Route120/scripts.pory"
waitmovement 0
# 598 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
# 599 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 600 "data/maps/Route120/scripts.pory"
waitmovement 0
# 601 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_CalliePostBattle, MSGBOX_AUTOCLOSE
# 602 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 603 "data/maps/Route120/scripts.pory"
end
# 604 "data/maps/Route120/scripts.pory"

# 605 "data/maps/Route120/scripts.pory"
Route120_EventScript_Callie::
# 606 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_CalliePostBattle, MSGBOX_AUTOCLOSE
# 607 "data/maps/Route120/scripts.pory"
	end
# 608 "data/maps/Route120/scripts.pory"

# 609 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGreeting:
# 610 "data/maps/Route120/scripts.pory"
	.string "STEVEN: Hm? {PLAYER}{KUN}, hi.\n"
# 611 "data/maps/Route120/scripts.pory"
	.string "It's been a while.\p"
# 612 "data/maps/Route120/scripts.pory"
	.string "There's something here that you can't\n"
# 613 "data/maps/Route120/scripts.pory"
	.string "see, right?\p"
# 614 "data/maps/Route120/scripts.pory"
	.string "Now, if I were to use this device on\n"
# 615 "data/maps/Route120/scripts.pory"
	.string "the invisible obstacle…\p"
# 616 "data/maps/Route120/scripts.pory"
	.string "No, no. Rather than describing it,\n"
# 617 "data/maps/Route120/scripts.pory"
	.string "I should just show you.\l"
# 618 "data/maps/Route120/scripts.pory"
	.string "That would be more fun.\p"
# 619 "data/maps/Route120/scripts.pory"
	.string "{PLAYER}{KUN}, are your POKéMON ready for\n"
# 620 "data/maps/Route120/scripts.pory"
	.string "battle?$"
# 621 "data/maps/Route120/scripts.pory"

# 622 "data/maps/Route120/scripts.pory"
Route120_Text_StevenIllWaitHere:
# 623 "data/maps/Route120/scripts.pory"
	.string "STEVEN: No?\p"
# 624 "data/maps/Route120/scripts.pory"
	.string "I'll wait here, so you can get ready.$"
# 625 "data/maps/Route120/scripts.pory"

# 626 "data/maps/Route120/scripts.pory"
Route120_Text_StevenReadyForBattle:
# 627 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, are your POKéMON\n"
# 628 "data/maps/Route120/scripts.pory"
	.string "ready for battle?$"
# 629 "data/maps/Route120/scripts.pory"

# 630 "data/maps/Route120/scripts.pory"
Route120_Text_StevenShowMeYourPower:
# 631 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, show me your true\n"
# 632 "data/maps/Route120/scripts.pory"
	.string "power as a TRAINER!$"
# 633 "data/maps/Route120/scripts.pory"

# 634 "data/maps/Route120/scripts.pory"
Route120_Text_StevenUsedDevonScope:
# 635 "data/maps/Route120/scripts.pory"
	.string "STEVEN used the DEVON SCOPE.\p"
# 636 "data/maps/Route120/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 637 "data/maps/Route120/scripts.pory"
	.string "visible!\p"
# 638 "data/maps/Route120/scripts.pory"
	.string "The startled POKéMON attacked!$"
# 639 "data/maps/Route120/scripts.pory"

# 640 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGiveDevonScope:
# 641 "data/maps/Route120/scripts.pory"
	.string "STEVEN: I see…\n"
# 642 "data/maps/Route120/scripts.pory"
	.string "Your battle style is intriguing.\p"
# 643 "data/maps/Route120/scripts.pory"
	.string "Your POKéMON have obviously grown\n"
# 644 "data/maps/Route120/scripts.pory"
	.string "since I first met you in DEWFORD.\p"
# 645 "data/maps/Route120/scripts.pory"
	.string "I'd like you to have this\n"
# 646 "data/maps/Route120/scripts.pory"
	.string "DEVON SCOPE.\p"
# 647 "data/maps/Route120/scripts.pory"
	.string "Who knows, there may be other\n"
# 648 "data/maps/Route120/scripts.pory"
	.string "concealed POKéMON.$"
# 649 "data/maps/Route120/scripts.pory"

# 650 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGoodbye:
# 651 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}.\p"
# 652 "data/maps/Route120/scripts.pory"
	.string "I enjoy seeing POKéMON and TRAINERS\n"
# 653 "data/maps/Route120/scripts.pory"
	.string "who strive together.\p"
# 654 "data/maps/Route120/scripts.pory"
	.string "I think you're doing great.\p"
# 655 "data/maps/Route120/scripts.pory"
	.string "Well, let's meet again somewhere.$"
# 656 "data/maps/Route120/scripts.pory"

# 657 "data/maps/Route120/scripts.pory"
Kecleon_Text_SomethingUnseeable:
# 658 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.$"
# 659 "data/maps/Route120/scripts.pory"

# 660 "data/maps/Route120/scripts.pory"
Kecleon_Text_WantToUseDevonScope:
# 661 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.\p"
# 662 "data/maps/Route120/scripts.pory"
	.string "Want to use the DEVON SCOPE?$"
# 663 "data/maps/Route120/scripts.pory"

# 664 "data/maps/Route120/scripts.pory"
Kecleon_Text_UseDevonScopeMonAttacked:
# 665 "data/maps/Route120/scripts.pory"
	.string "{PLAYER} used the DEVON SCOPE.\p"
# 666 "data/maps/Route120/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 667 "data/maps/Route120/scripts.pory"
	.string "visible!\p"
# 668 "data/maps/Route120/scripts.pory"
	.string "The startled POKéMON attacked!$"
# 669 "data/maps/Route120/scripts.pory"

# 670 "data/maps/Route120/scripts.pory"
Route120_Text_RouteSignFortree:
# 671 "data/maps/Route120/scripts.pory"
	.string "ROUTE 120\n"
# 672 "data/maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} FORTREE CITY$"
# 673 "data/maps/Route120/scripts.pory"

# 674 "data/maps/Route120/scripts.pory"
Route120_Text_RouteSign121:
# 675 "data/maps/Route120/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 121\n"
# 676 "data/maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 120$"
