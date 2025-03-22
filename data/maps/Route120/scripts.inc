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
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route120_EventScript_RemoveKecleonObject
# 26 "data/maps/Route120/scripts.pory"
	end
# 27 "data/maps/Route120/scripts.pory"

# 28 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleonObject::
# 29 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 0, Route120_EventScript_RemoveBridgeKecleon
# 30 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 1, Route120_EventScript_RemoveKecleon
# 31 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 2, Route120_EventScript_RemoveKecleon
# 32 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 3, Route120_EventScript_RemoveKecleon
# 33 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 4, Route120_EventScript_RemoveKecleon
# 34 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_0x8009, 5, Route120_EventScript_RemoveKecleon
# 35 "data/maps/Route120/scripts.pory"
	return
# 36 "data/maps/Route120/scripts.pory"

# 37 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleon::
# 38 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 39 "data/maps/Route120/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 40 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON
# 41 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
# 42 "data/maps/Route120/scripts.pory"
	return
# 43 "data/maps/Route120/scripts.pory"

# 44 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveKecleon::
# 45 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 46 "data/maps/Route120/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 47 "data/maps/Route120/scripts.pory"
	removeobject VAR_LAST_TALKED
# 48 "data/maps/Route120/scripts.pory"
	return
# 49 "data/maps/Route120/scripts.pory"

# 50 "data/maps/Route120/scripts.pory"
Route120_OnLoad:
# 51 "data/maps/Route120/scripts.pory"
	call_if_unset FLAG_REGI_DOORS_OPENED, Route120_EventScript_CloseAncientTomb
# 52 "data/maps/Route120/scripts.pory"
	call_if_set FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeClearMetatiles
# 53 "data/maps/Route120/scripts.pory"
	call_if_unset FLAG_RECEIVED_DEVON_SCOPE, Route120_EventScript_SetBridgeKecleonMovement
# 54 "data/maps/Route120/scripts.pory"
	end
# 55 "data/maps/Route120/scripts.pory"

# 56 "data/maps/Route120/scripts.pory"
Route120_EventScript_CloseAncientTomb::
# 57 "data/maps/Route120/scripts.pory"
	setmetatile 7, 54, METATILE_General_RockWall_RockBase, TRUE
# 58 "data/maps/Route120/scripts.pory"
	setmetatile 7, 55, METATILE_General_RockWall_SandBase, TRUE
# 59 "data/maps/Route120/scripts.pory"
	return
# 60 "data/maps/Route120/scripts.pory"

# 61 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeClearMetatiles::
# 62 "data/maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
# 63 "data/maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
# 64 "data/maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
# 65 "data/maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
# 66 "data/maps/Route120/scripts.pory"
	return
# 67 "data/maps/Route120/scripts.pory"

# 68 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetBridgeKecleonMovement::
# 69 "data/maps/Route120/scripts.pory"
	setobjectmovementtype LOCALID_BRIDGE_KECLEON_SHADOW, MOVEMENT_TYPE_FACE_RIGHT
# 70 "data/maps/Route120/scripts.pory"
	return
# 71 "data/maps/Route120/scripts.pory"

# 72 "data/maps/Route120/scripts.pory"
Route120_OnTransition:
# 73 "data/maps/Route120/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 74 "data/maps/Route120/scripts.pory"
	call Route120_EventScript_SetWeather
# 75 "data/maps/Route120/scripts.pory"
	end
# 76 "data/maps/Route120/scripts.pory"

# 77 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetWeather::
# 78 "data/maps/Route120/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 79 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_1, 14, Route120_EventScript_SetSunnyWeather
# 80 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_1, 60, Route120_EventScript_TrySetRainyWeather
# 81 "data/maps/Route120/scripts.pory"
	goto_if_ge VAR_TEMP_1, 61, Route120_EventScript_SetCloudyWeather
# 82 "data/maps/Route120/scripts.pory"
	return
# 83 "data/maps/Route120/scripts.pory"

# 84 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetCloudyWeather::
# 85 "data/maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY_CLOUDS
# 86 "data/maps/Route120/scripts.pory"
	return
# 87 "data/maps/Route120/scripts.pory"

# 88 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetSunnyWeather::
# 89 "data/maps/Route120/scripts.pory"
	setweather WEATHER_SUNNY
# 90 "data/maps/Route120/scripts.pory"
	return
# 91 "data/maps/Route120/scripts.pory"

# 92 "data/maps/Route120/scripts.pory"
Route120_EventScript_TrySetRainyWeather::
# 93 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_0, 7, Route120_EventScript_SetRainyWeather
# 94 "data/maps/Route120/scripts.pory"
	goto_if_le VAR_TEMP_0, 19, Route120_EventScript_SetSunnyWeather
# 95 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_SetRainyWeather
# 96 "data/maps/Route120/scripts.pory"
	end
# 97 "data/maps/Route120/scripts.pory"

# 98 "data/maps/Route120/scripts.pory"
Route120_EventScript_SetRainyWeather::
# 99 "data/maps/Route120/scripts.pory"
	setweather WEATHER_RAIN
# 100 "data/maps/Route120/scripts.pory"
	return
# 101 "data/maps/Route120/scripts.pory"

# 102 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryBeauty::
# 103 "data/maps/Route120/scripts.pory"
	lock
# 104 "data/maps/Route120/scripts.pory"
	faceplayer
# 105 "data/maps/Route120/scripts.pory"
	dotimebasedevents
# 106 "data/maps/Route120/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_120_RECEIVED_BERRY, Route120_EventScript_ReceivedBerry
# 107 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_BerriesExpressionOfLoveIsntIt, MSGBOX_YESNO
# 108 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route120_EventScript_BerryLove
# 109 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route120_EventScript_BerryNotLove
# 110 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
# 111 "data/maps/Route120/scripts.pory"
	switch VAR_RESULT
# 112 "data/maps/Route120/scripts.pory"
	case 0, Route120_EventScript_GiveFigyBerry
# 113 "data/maps/Route120/scripts.pory"
	case 5, Route120_EventScript_GiveFigyBerry
# 114 "data/maps/Route120/scripts.pory"
	case 1, Route120_EventScript_GiveWikiBerry
# 115 "data/maps/Route120/scripts.pory"
	case 6, Route120_EventScript_GiveWikiBerry
# 116 "data/maps/Route120/scripts.pory"
	case 2, Route120_EventScript_GiveMagoBerry
# 117 "data/maps/Route120/scripts.pory"
	case 7, Route120_EventScript_GiveMagoBerry
# 118 "data/maps/Route120/scripts.pory"
	case 3, Route120_EventScript_GiveAguavBerry
# 119 "data/maps/Route120/scripts.pory"
	case 8, Route120_EventScript_GiveAguavBerry
# 120 "data/maps/Route120/scripts.pory"
	case 4, Route120_EventScript_GiveIapapaBerry
# 121 "data/maps/Route120/scripts.pory"
	case 9, Route120_EventScript_GiveIapapaBerry
# 122 "data/maps/Route120/scripts.pory"
	end
# 123 "data/maps/Route120/scripts.pory"

# 124 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveFigyBerry::
# 125 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_FIGY_BERRY
# 126 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 127 "data/maps/Route120/scripts.pory"
	end
# 128 "data/maps/Route120/scripts.pory"

# 129 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveWikiBerry::
# 130 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_WIKI_BERRY
# 131 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 132 "data/maps/Route120/scripts.pory"
	end
# 133 "data/maps/Route120/scripts.pory"

# 134 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveMagoBerry::
# 135 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_MAGO_BERRY
# 136 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 137 "data/maps/Route120/scripts.pory"
	end
# 138 "data/maps/Route120/scripts.pory"

# 139 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveAguavBerry::
# 140 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_AGUAV_BERRY
# 141 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 142 "data/maps/Route120/scripts.pory"
	end
# 143 "data/maps/Route120/scripts.pory"

# 144 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveIapapaBerry::
# 145 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8004, ITEM_IAPAPA_BERRY
# 146 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_GiveBerry
# 147 "data/maps/Route120/scripts.pory"
	end
# 148 "data/maps/Route120/scripts.pory"

# 149 "data/maps/Route120/scripts.pory"
Route120_EventScript_GiveBerry::
# 150 "data/maps/Route120/scripts.pory"
	giveitem VAR_0x8004
# 151 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 152 "data/maps/Route120/scripts.pory"
	setflag FLAG_DAILY_ROUTE_120_RECEIVED_BERRY
# 153 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_BerryIsRareRaiseItWithCare, MSGBOX_DEFAULT
# 154 "data/maps/Route120/scripts.pory"
	release
# 155 "data/maps/Route120/scripts.pory"
	end
# 156 "data/maps/Route120/scripts.pory"

# 157 "data/maps/Route120/scripts.pory"
Route120_EventScript_ReceivedBerry::
# 158 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_IllGetMoreBerriesFromBerryMaster, MSGBOX_DEFAULT
# 159 "data/maps/Route120/scripts.pory"
	release
# 160 "data/maps/Route120/scripts.pory"
	end
# 161 "data/maps/Route120/scripts.pory"

# 162 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryLove::
# 163 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_YesYouUnderstand, MSGBOX_DEFAULT
# 164 "data/maps/Route120/scripts.pory"
	return
# 165 "data/maps/Route120/scripts.pory"

# 166 "data/maps/Route120/scripts.pory"
Route120_EventScript_BerryNotLove::
# 167 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_MakeYourOwnImpressions, MSGBOX_DEFAULT
# 168 "data/maps/Route120/scripts.pory"
	return
# 169 "data/maps/Route120/scripts.pory"

# 170 "data/maps/Route120/scripts.pory"
Route120_EventScript_Steven::
# 171 "data/maps/Route120/scripts.pory"
	lock
# 172 "data/maps/Route120/scripts.pory"
	faceplayer
# 173 "data/maps/Route120/scripts.pory"
	goto_if_set FLAG_NOT_READY_FOR_BATTLE_ROUTE_120, Route120_EventScript_StevenAskReadyForBattle
# 174 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGreeting, MSGBOX_YESNO
# 175 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
# 176 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 177 "data/maps/Route120/scripts.pory"
	end
# 178 "data/maps/Route120/scripts.pory"

# 179 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenNotReady::
# 180 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenIllWaitHere, MSGBOX_DEFAULT
# 181 "data/maps/Route120/scripts.pory"
	setflag FLAG_NOT_READY_FOR_BATTLE_ROUTE_120
# 182 "data/maps/Route120/scripts.pory"
	release
# 183 "data/maps/Route120/scripts.pory"
	end
# 184 "data/maps/Route120/scripts.pory"

# 185 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenAskReadyForBattle::
# 186 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenReadyForBattle, MSGBOX_YESNO
# 187 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route120_EventScript_StevenNotReady
# 188 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenBattleKecleon
# 189 "data/maps/Route120/scripts.pory"
	end
# 190 "data/maps/Route120/scripts.pory"

# 191 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenBattleKecleon::
# 192 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenShowMeYourPower, MSGBOX_DEFAULT
# 193 "data/maps/Route120/scripts.pory"
	closemessage
# 194 "data/maps/Route120/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route120_EventScript_PlayerApproachKecleonEast
# 195 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterLeft
# 196 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 197 "data/maps/Route120/scripts.pory"
	delay 20
# 198 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenUsedDevonScope, MSGBOX_DEFAULT
# 199 "data/maps/Route120/scripts.pory"
	closemessage
# 200 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_BRIDGE_KECLEON, Common_Movement_WalkInPlaceFasterUp
# 201 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 202 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_BRIDGE_KECLEON, Movement_KecleonAppears
# 203 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 204 "data/maps/Route120/scripts.pory"
	waitse
# 205 "data/maps/Route120/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
# 206 "data/maps/Route120/scripts.pory"
	delay 40
# 207 "data/maps/Route120/scripts.pory"
	waitmoncry
# 208 "data/maps/Route120/scripts.pory"
	setwildbattle SPECIES_KECLEON, 30
# 209 "data/maps/Route120/scripts.pory"
	setvar VAR_0x8009, 0
# 210 "data/maps/Route120/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 211 "data/maps/Route120/scripts.pory"
	dowildbattle
# 212 "data/maps/Route120/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 213 "data/maps/Route120/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 214 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 215 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 216 "data/maps/Route120/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route120_EventScript_RemoveBridgeKecleonPostBattle
# 217 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 218 "data/maps/Route120/scripts.pory"
	end
# 219 "data/maps/Route120/scripts.pory"

# 220 "data/maps/Route120/scripts.pory"
Route120_EventScript_RemoveBridgeKecleonPostBattle::
# 221 "data/maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 222 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON
# 223 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_BRIDGE_KECLEON_SHADOW
# 224 "data/maps/Route120/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 225 "data/maps/Route120/scripts.pory"
	goto Route120_EventScript_StevenGiveDeconScope
# 226 "data/maps/Route120/scripts.pory"
	end
# 227 "data/maps/Route120/scripts.pory"

# 228 "data/maps/Route120/scripts.pory"
Route120_EventScript_StevenGiveDeconScope::
# 229 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
# 230 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 231 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 232 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGiveDevonScope, MSGBOX_DEFAULT
# 233 "data/maps/Route120/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 234 "data/maps/Route120/scripts.pory"
	setflag FLAG_RECEIVED_DEVON_SCOPE
# 235 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_StevenGoodbye, MSGBOX_DEFAULT
# 236 "data/maps/Route120/scripts.pory"
	closemessage
# 237 "data/maps/Route120/scripts.pory"
	applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
# 238 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 239 "data/maps/Route120/scripts.pory"
	delay 50
# 240 "data/maps/Route120/scripts.pory"
	setfieldeffectargument 0, 1
# 241 "data/maps/Route120/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 242 "data/maps/Route120/scripts.pory"
	delay 15
# 243 "data/maps/Route120/scripts.pory"
	removeobject LOCALID_STEVEN
# 244 "data/maps/Route120/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 245 "data/maps/Route120/scripts.pory"
	setmetatile 13, 15, METATILE_Fortree_WoodBridge1_Top, FALSE
# 246 "data/maps/Route120/scripts.pory"
	setmetatile 12, 16, METATILE_Fortree_WoodBridge1_Bottom, FALSE
# 247 "data/maps/Route120/scripts.pory"
	setmetatile 12, 17, METATILE_General_ReflectiveWater, FALSE
# 248 "data/maps/Route120/scripts.pory"
	setmetatile 13, 17, METATILE_General_ReflectiveWater, FALSE
# 249 "data/maps/Route120/scripts.pory"
	special DrawWholeMapView
# 250 "data/maps/Route120/scripts.pory"
	release
# 251 "data/maps/Route120/scripts.pory"
	end
# 252 "data/maps/Route120/scripts.pory"

# 253 "data/maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonNorth::
# 254 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 255 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 256 "data/maps/Route120/scripts.pory"
	return
# 257 "data/maps/Route120/scripts.pory"

# 258 "data/maps/Route120/scripts.pory"
Route120_EventScript_PlayerApproachKecleonEast::
# 259 "data/maps/Route120/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route120_Movement_ApproachKecleonEast
# 260 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 261 "data/maps/Route120/scripts.pory"
	return
# 262 "data/maps/Route120/scripts.pory"

# 263 "data/maps/Route120/scripts.pory"
Route120_Movement_ApproachKecleonEast:
# 264 "data/maps/Route120/scripts.pory"
	face_down
# 265 "data/maps/Route120/scripts.pory"
	step_end
# 266 "data/maps/Route120/scripts.pory"

# 267 "data/maps/Route120/scripts.pory"
Route120_EventScript_BridgeKecleon::
# 268 "data/maps/Route120/scripts.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_NPC
# 269 "data/maps/Route120/scripts.pory"
	end
# 270 "data/maps/Route120/scripts.pory"

# 271 "data/maps/Route120/scripts.pory"
Route120_EventScript_RouteSignFortree::
# 272 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSignFortree, MSGBOX_SIGN
# 273 "data/maps/Route120/scripts.pory"
	end
# 274 "data/maps/Route120/scripts.pory"

# 275 "data/maps/Route120/scripts.pory"
Route120_EventScript_RouteSign121::
# 276 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSign121, MSGBOX_SIGN
# 277 "data/maps/Route120/scripts.pory"
	end
# 278 "data/maps/Route120/scripts.pory"

# 279 "data/maps/Route120/scripts.pory"
Route120_EventScript_ColinAngelica::
# 280 "data/maps/Route120/scripts.pory"
lockall
# 281 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_COLIN
# 282 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 283 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 284 "data/maps/Route120/scripts.pory"
waitmovement 0
# 285 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 286 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 287 "data/maps/Route120/scripts.pory"
waitmovement 0
# 288 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ColinIntro MSGBOX_AUTOCLOSE
# 289 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_ANGELICA
# 290 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 291 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 292 "data/maps/Route120/scripts.pory"
waitmovement 0
# 293 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 294 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 295 "data/maps/Route120/scripts.pory"
waitmovement 0
# 296 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_AngelicaIntro MSGBOX_AUTOCLOSE
# 297 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_ColinAngelicaDoMultiBattle
# 298 "data/maps/Route120/scripts.pory"
releaseall
# 299 "data/maps/Route120/scripts.pory"
end
# 300 "data/maps/Route120/scripts.pory"

# 301 "data/maps/Route120/scripts.pory"
Route120_EventScript_ColinAngelicaDoMultiBattle::
# 302 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 303 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_COLIN, Route120_Text_ColinDefeat, TRAINER_ANGELICA, Route120_Text_AngelicaDefeat, PARTNER_EMMIE
# 304 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 305 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_ColinAngelicaVictory
# 306 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 307 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 308 "data/maps/Route120/scripts.pory"
waitstate
# 309 "data/maps/Route120/scripts.pory"

# 310 "data/maps/Route120/scripts.pory"
Route120_EventScript_ColinAngelicaVictory::
# 311 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 312 "data/maps/Route120/scripts.pory"
waitmovement 0
# 313 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
# 314 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 315 "data/maps/Route120/scripts.pory"
waitmovement 0
# 316 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
# 317 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 318 "data/maps/Route120/scripts.pory"
end
# 319 "data/maps/Route120/scripts.pory"

# 320 "data/maps/Route120/scripts.pory"
Route120_EventScript_Colin::
# 321 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
# 322 "data/maps/Route120/scripts.pory"
	end
# 323 "data/maps/Route120/scripts.pory"

# 324 "data/maps/Route120/scripts.pory"
Route120_EventScript_ClarissaRobert::
# 325 "data/maps/Route120/scripts.pory"
lockall
# 326 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_CLARISSA
# 327 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 328 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 329 "data/maps/Route120/scripts.pory"
waitmovement 0
# 330 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 331 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 332 "data/maps/Route120/scripts.pory"
waitmovement 0
# 333 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ClarissaIntro MSGBOX_AUTOCLOSE
# 334 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_ROBERT
# 335 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 336 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 337 "data/maps/Route120/scripts.pory"
waitmovement 0
# 338 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 339 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 340 "data/maps/Route120/scripts.pory"
waitmovement 0
# 341 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_RobertIntro MSGBOX_AUTOCLOSE
# 342 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_ClarissaRobertDoMultiBattle
# 343 "data/maps/Route120/scripts.pory"
releaseall
# 344 "data/maps/Route120/scripts.pory"
end
# 345 "data/maps/Route120/scripts.pory"

# 346 "data/maps/Route120/scripts.pory"
Route120_EventScript_ClarissaRobertDoMultiBattle::
# 347 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 348 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_CLARISSA, Route120_Text_ClarissaDefeat, TRAINER_ROBERT_1, Route120_Text_RobertDefeat, PARTNER_EMMIE
# 349 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 350 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_ClarissaRobertVictory
# 351 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 352 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 353 "data/maps/Route120/scripts.pory"
waitstate
# 354 "data/maps/Route120/scripts.pory"

# 355 "data/maps/Route120/scripts.pory"
Route120_EventScript_ClarissaRobertVictory::
# 356 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 357 "data/maps/Route120/scripts.pory"
waitmovement 0
# 358 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ClarissaPostBattle, MSGBOX_AUTOCLOSE
# 359 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 360 "data/maps/Route120/scripts.pory"
waitmovement 0
# 361 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_RobertPostBattle, MSGBOX_AUTOCLOSE
# 362 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 363 "data/maps/Route120/scripts.pory"
end
# 364 "data/maps/Route120/scripts.pory"

# 365 "data/maps/Route120/scripts.pory"
Route120_EventScript_Robert::
# 366 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostBattle, MSGBOX_DEFAULT
# 367 "data/maps/Route120/scripts.pory"
	release
# 368 "data/maps/Route120/scripts.pory"
	end
# 369 "data/maps/Route120/scripts.pory"

# 370 "data/maps/Route120/scripts.pory"
Route120_EventScript_RegisterRobert::
# 371 "data/maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 372 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 373 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertRegister, MSGBOX_DEFAULT
# 374 "data/maps/Route120/scripts.pory"
	register_matchcall TRAINER_ROBERT_1
# 375 "data/maps/Route120/scripts.pory"
	release
# 376 "data/maps/Route120/scripts.pory"
	end
# 377 "data/maps/Route120/scripts.pory"

# 378 "data/maps/Route120/scripts.pory"
Route120_EventScript_RematchRobert::
# 379 "data/maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_ROBERT_1, Route120_Text_RobertRematchIntro, Route120_Text_RobertRematchDefeat
# 380 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostRematch, MSGBOX_AUTOCLOSE
# 381 "data/maps/Route120/scripts.pory"
	end
# 382 "data/maps/Route120/scripts.pory"

# 383 "data/maps/Route120/scripts.pory"
Route120_EventScript_JennaLorenzo::
# 384 "data/maps/Route120/scripts.pory"
lockall
# 385 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_JENNA
# 386 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 387 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 388 "data/maps/Route120/scripts.pory"
waitmovement 0
# 389 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 390 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 391 "data/maps/Route120/scripts.pory"
waitmovement 0
# 392 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JennaIntro MSGBOX_AUTOCLOSE
# 393 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_LORENZO
# 394 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 395 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 396 "data/maps/Route120/scripts.pory"
waitmovement 0
# 397 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 398 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 399 "data/maps/Route120/scripts.pory"
waitmovement 0
# 400 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_LorenzoIntro MSGBOX_AUTOCLOSE
# 401 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_JennaLorenzoDoMultiBattle
# 402 "data/maps/Route120/scripts.pory"
releaseall
# 403 "data/maps/Route120/scripts.pory"
end
# 404 "data/maps/Route120/scripts.pory"

# 405 "data/maps/Route120/scripts.pory"
Route120_EventScript_JennaLorenzoDoMultiBattle::
# 406 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 407 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_JENNA, Route120_Text_JennaDefeat, TRAINER_LORENZO, Route120_Text_LorenzoDefeat, PARTNER_EMMIE
# 408 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 409 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_JennaLorenzoVictory
# 410 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 411 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 412 "data/maps/Route120/scripts.pory"
waitstate
# 413 "data/maps/Route120/scripts.pory"

# 414 "data/maps/Route120/scripts.pory"
Route120_EventScript_JennaLorenzoVictory::
# 415 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 416 "data/maps/Route120/scripts.pory"
waitmovement 0
# 417 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
# 418 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 419 "data/maps/Route120/scripts.pory"
waitmovement 0
# 420 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_LorenzoPostBattle, MSGBOX_AUTOCLOSE
# 421 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 422 "data/maps/Route120/scripts.pory"
end
# 423 "data/maps/Route120/scripts.pory"

# 424 "data/maps/Route120/scripts.pory"
Route120_EventScript_Lorenzo::
# 425 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LorenzoPostBattle, MSGBOX_AUTOCLOSE
# 426 "data/maps/Route120/scripts.pory"
	end
# 427 "data/maps/Route120/scripts.pory"

# 428 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jenna::
# 429 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
# 430 "data/maps/Route120/scripts.pory"
	end
# 431 "data/maps/Route120/scripts.pory"

# 432 "data/maps/Route120/scripts.pory"
Route120_EventScript_ChipJeffrey::
# 433 "data/maps/Route120/scripts.pory"
lockall
# 434 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_CHIP
# 435 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 436 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 437 "data/maps/Route120/scripts.pory"
waitmovement 0
# 438 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 439 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 440 "data/maps/Route120/scripts.pory"
waitmovement 0
# 441 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ChipIntro MSGBOX_AUTOCLOSE
# 442 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_JEFFREY
# 443 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 444 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 445 "data/maps/Route120/scripts.pory"
waitmovement 0
# 446 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 447 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 448 "data/maps/Route120/scripts.pory"
waitmovement 0
# 449 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JeffreyIntro MSGBOX_AUTOCLOSE
# 450 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_ChipJeffreyDoMultiBattle
# 451 "data/maps/Route120/scripts.pory"
releaseall
# 452 "data/maps/Route120/scripts.pory"
end
# 453 "data/maps/Route120/scripts.pory"

# 454 "data/maps/Route120/scripts.pory"
Route120_EventScript_ChipJeffreyDoMultiBattle::
# 455 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 456 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_CHIP, Route120_Text_ChipDefeat, TRAINER_JEFFREY_1, Route120_Text_JeffreyDefeat, PARTNER_EMMIE
# 457 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 458 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_ChipJeffreyVictory
# 459 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 460 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 461 "data/maps/Route120/scripts.pory"
waitstate
# 462 "data/maps/Route120/scripts.pory"

# 463 "data/maps/Route120/scripts.pory"
Route120_EventScript_ChipJeffreyVictory::
# 464 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 465 "data/maps/Route120/scripts.pory"
waitmovement 0
# 466 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
# 467 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 468 "data/maps/Route120/scripts.pory"
waitmovement 0
# 469 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JeffreyPostBattle, MSGBOX_AUTOCLOSE
# 470 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 471 "data/maps/Route120/scripts.pory"
end
# 472 "data/maps/Route120/scripts.pory"

# 473 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jeffrey::
# 474 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostBattle, MSGBOX_DEFAULT
# 475 "data/maps/Route120/scripts.pory"
	release
# 476 "data/maps/Route120/scripts.pory"
	end
# 477 "data/maps/Route120/scripts.pory"

# 478 "data/maps/Route120/scripts.pory"
Route120_EventScript_RegisterJeffrey::
# 479 "data/maps/Route120/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 480 "data/maps/Route120/scripts.pory"
	waitmovement 0
# 481 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyRegister, MSGBOX_DEFAULT
# 482 "data/maps/Route120/scripts.pory"
	register_matchcall TRAINER_JEFFREY_1
# 483 "data/maps/Route120/scripts.pory"
	release
# 484 "data/maps/Route120/scripts.pory"
	end
# 485 "data/maps/Route120/scripts.pory"

# 486 "data/maps/Route120/scripts.pory"
Route120_EventScript_RematchJeffrey::
# 487 "data/maps/Route120/scripts.pory"
	trainerbattle_rematch TRAINER_JEFFREY_1, Route120_Text_JeffreyRematchIntro, Route120_Text_JeffreyRematchDefeat
# 488 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostRematch, MSGBOX_AUTOCLOSE
# 489 "data/maps/Route120/scripts.pory"
	end
# 490 "data/maps/Route120/scripts.pory"

# 491 "data/maps/Route120/scripts.pory"
Route120_EventScript_Jennifer::
# 492 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
# 493 "data/maps/Route120/scripts.pory"
	end
# 494 "data/maps/Route120/scripts.pory"

# 495 "data/maps/Route120/scripts.pory"
Route120_EventScript_Chip::
# 496 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
# 497 "data/maps/Route120/scripts.pory"
	end
# 498 "data/maps/Route120/scripts.pory"

# 499 "data/maps/Route120/scripts.pory"
Route120_EventScript_Clarissa::
# 500 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ClarissaPostBattle, MSGBOX_AUTOCLOSE
# 501 "data/maps/Route120/scripts.pory"
	end
# 502 "data/maps/Route120/scripts.pory"

# 503 "data/maps/Route120/scripts.pory"
Route120_EventScript_Angelica::
# 504 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
# 505 "data/maps/Route120/scripts.pory"
	end
# 506 "data/maps/Route120/scripts.pory"

# 507 "data/maps/Route120/scripts.pory"
Route120_EventScript_KeigoRiley::
# 508 "data/maps/Route120/scripts.pory"
lockall
# 509 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_KEIGO
# 510 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 511 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 512 "data/maps/Route120/scripts.pory"
waitmovement 0
# 513 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 514 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 515 "data/maps/Route120/scripts.pory"
waitmovement 0
# 516 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_KeigoIntro MSGBOX_AUTOCLOSE
# 517 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_RILEY
# 518 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 519 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 520 "data/maps/Route120/scripts.pory"
waitmovement 0
# 521 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 522 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 523 "data/maps/Route120/scripts.pory"
waitmovement 0
# 524 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_RileyIntro MSGBOX_AUTOCLOSE
# 525 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_KeigoRileyDoMultiBattle
# 526 "data/maps/Route120/scripts.pory"
releaseall
# 527 "data/maps/Route120/scripts.pory"
end
# 528 "data/maps/Route120/scripts.pory"

# 529 "data/maps/Route120/scripts.pory"
Route120_EventScript_KeigoRileyDoMultiBattle::
# 530 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 531 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_KEIGO, Route120_Text_KeigoDefeat, TRAINER_RILEY, Route120_Text_RileyDefeat, PARTNER_EMMIE
# 532 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 533 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_KeigoRileyVictory
# 534 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 535 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 536 "data/maps/Route120/scripts.pory"
waitstate
# 537 "data/maps/Route120/scripts.pory"

# 538 "data/maps/Route120/scripts.pory"
Route120_EventScript_KeigoRileyVictory::
# 539 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 540 "data/maps/Route120/scripts.pory"
waitmovement 0
# 541 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
# 542 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 543 "data/maps/Route120/scripts.pory"
waitmovement 0
# 544 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
# 545 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 546 "data/maps/Route120/scripts.pory"
end
# 547 "data/maps/Route120/scripts.pory"

# 548 "data/maps/Route120/scripts.pory"
Route120_EventScript_Keigo::
# 549 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
# 550 "data/maps/Route120/scripts.pory"
	end
# 551 "data/maps/Route120/scripts.pory"

# 552 "data/maps/Route120/scripts.pory"
Route120_EventScript_Riley::
# 553 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
# 554 "data/maps/Route120/scripts.pory"
	end
# 555 "data/maps/Route120/scripts.pory"

# 556 "data/maps/Route120/scripts.pory"
Route120_EventScript_Leonel::
# 557 "data/maps/Route120/scripts.pory"
	trainerbattle_single TRAINER_LEONEL, Route120_Text_LeonelIntro, Route120_Text_LeonelDefeat
# 558 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LeonelPostBattle, MSGBOX_AUTOCLOSE
# 559 "data/maps/Route120/scripts.pory"
	end
# 560 "data/maps/Route120/scripts.pory"

# 561 "data/maps/Route120/scripts.pory"
Route120_EventScript_JenniferCallie::
# 562 "data/maps/Route120/scripts.pory"
lockall
# 563 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_JENNIFER
# 564 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 565 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 566 "data/maps/Route120/scripts.pory"
waitmovement 0
# 567 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 568 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 569 "data/maps/Route120/scripts.pory"
waitmovement 0
# 570 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JenniferIntro MSGBOX_AUTOCLOSE
# 571 "data/maps/Route120/scripts.pory"
setvar VAR_0x8008, LOCALID_CALLIE
# 572 "data/maps/Route120/scripts.pory"
playse SE_PIN
# 573 "data/maps/Route120/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 574 "data/maps/Route120/scripts.pory"
waitmovement 0
# 575 "data/maps/Route120/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 576 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 577 "data/maps/Route120/scripts.pory"
waitmovement 0
# 578 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_CallieIntro MSGBOX_AUTOCLOSE
# 579 "data/maps/Route120/scripts.pory"
goto Route120_EventScript_JenniferCallieDoMultiBattle
# 580 "data/maps/Route120/scripts.pory"
releaseall
# 581 "data/maps/Route120/scripts.pory"
end
# 582 "data/maps/Route120/scripts.pory"

# 583 "data/maps/Route120/scripts.pory"
Route120_EventScript_JenniferCallieDoMultiBattle::
# 584 "data/maps/Route120/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 585 "data/maps/Route120/scripts.pory"
multi_2p_vs_2 TRAINER_JENNIFER, Route120_Text_JenniferDefeat, TRAINER_CALLIE, Route120_Text_CallieDefeat, PARTNER_EMMIE
# 586 "data/maps/Route120/scripts.pory"
switch VAR_RESULT
# 587 "data/maps/Route120/scripts.pory"
case 1, Route120_EventScript_JenniferCallieVictory
# 588 "data/maps/Route120/scripts.pory"
fadescreen FADE_TO_BLACK
# 589 "data/maps/Route120/scripts.pory"
special SetCB2WhiteOut
# 590 "data/maps/Route120/scripts.pory"
waitstate
# 591 "data/maps/Route120/scripts.pory"

# 592 "data/maps/Route120/scripts.pory"
Route120_EventScript_JenniferCallieVictory::
# 593 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 594 "data/maps/Route120/scripts.pory"
waitmovement 0
# 595 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
# 596 "data/maps/Route120/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 597 "data/maps/Route120/scripts.pory"
waitmovement 0
# 598 "data/maps/Route120/scripts.pory"
msgbox Route120_Text_CalliePostBattle, MSGBOX_AUTOCLOSE
# 599 "data/maps/Route120/scripts.pory"
addvar VAR_ROUTE120_STATE, 1
# 600 "data/maps/Route120/scripts.pory"
end
# 601 "data/maps/Route120/scripts.pory"

# 602 "data/maps/Route120/scripts.pory"
Route120_EventScript_Callie::
# 603 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_CalliePostBattle, MSGBOX_AUTOCLOSE
# 604 "data/maps/Route120/scripts.pory"
	end
# 605 "data/maps/Route120/scripts.pory"

# 606 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGreeting:
# 607 "data/maps/Route120/scripts.pory"
	.string "STEVEN: Hm? {PLAYER}{KUN}, hi.\n"
# 608 "data/maps/Route120/scripts.pory"
	.string "It's been a while.\p"
# 609 "data/maps/Route120/scripts.pory"
	.string "There's something here that you can't\n"
# 610 "data/maps/Route120/scripts.pory"
	.string "see, right?\p"
# 611 "data/maps/Route120/scripts.pory"
	.string "Now, if I were to use this device on\n"
# 612 "data/maps/Route120/scripts.pory"
	.string "the invisible obstacle…\p"
# 613 "data/maps/Route120/scripts.pory"
	.string "No, no. Rather than describing it,\n"
# 614 "data/maps/Route120/scripts.pory"
	.string "I should just show you.\l"
# 615 "data/maps/Route120/scripts.pory"
	.string "That would be more fun.\p"
# 616 "data/maps/Route120/scripts.pory"
	.string "{PLAYER}{KUN}, are your POKéMON ready for\n"
# 617 "data/maps/Route120/scripts.pory"
	.string "battle?$"
# 618 "data/maps/Route120/scripts.pory"

# 619 "data/maps/Route120/scripts.pory"
Route120_Text_StevenIllWaitHere:
# 620 "data/maps/Route120/scripts.pory"
	.string "STEVEN: No?\p"
# 621 "data/maps/Route120/scripts.pory"
	.string "I'll wait here, so you can get ready.$"
# 622 "data/maps/Route120/scripts.pory"

# 623 "data/maps/Route120/scripts.pory"
Route120_Text_StevenReadyForBattle:
# 624 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, are your POKéMON\n"
# 625 "data/maps/Route120/scripts.pory"
	.string "ready for battle?$"
# 626 "data/maps/Route120/scripts.pory"

# 627 "data/maps/Route120/scripts.pory"
Route120_Text_StevenShowMeYourPower:
# 628 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, show me your true\n"
# 629 "data/maps/Route120/scripts.pory"
	.string "power as a TRAINER!$"
# 630 "data/maps/Route120/scripts.pory"

# 631 "data/maps/Route120/scripts.pory"
Route120_Text_StevenUsedDevonScope:
# 632 "data/maps/Route120/scripts.pory"
	.string "STEVEN used the DEVON SCOPE.\p"
# 633 "data/maps/Route120/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 634 "data/maps/Route120/scripts.pory"
	.string "visible!\p"
# 635 "data/maps/Route120/scripts.pory"
	.string "The startled POKéMON attacked!$"
# 636 "data/maps/Route120/scripts.pory"

# 637 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGiveDevonScope:
# 638 "data/maps/Route120/scripts.pory"
	.string "STEVEN: I see…\n"
# 639 "data/maps/Route120/scripts.pory"
	.string "Your battle style is intriguing.\p"
# 640 "data/maps/Route120/scripts.pory"
	.string "Your POKéMON have obviously grown\n"
# 641 "data/maps/Route120/scripts.pory"
	.string "since I first met you in DEWFORD.\p"
# 642 "data/maps/Route120/scripts.pory"
	.string "I'd like you to have this\n"
# 643 "data/maps/Route120/scripts.pory"
	.string "DEVON SCOPE.\p"
# 644 "data/maps/Route120/scripts.pory"
	.string "Who knows, there may be other\n"
# 645 "data/maps/Route120/scripts.pory"
	.string "concealed POKéMON.$"
# 646 "data/maps/Route120/scripts.pory"

# 647 "data/maps/Route120/scripts.pory"
Route120_Text_StevenGoodbye:
# 648 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}.\p"
# 649 "data/maps/Route120/scripts.pory"
	.string "I enjoy seeing POKéMON and TRAINERS\n"
# 650 "data/maps/Route120/scripts.pory"
	.string "who strive together.\p"
# 651 "data/maps/Route120/scripts.pory"
	.string "I think you're doing great.\p"
# 652 "data/maps/Route120/scripts.pory"
	.string "Well, let's meet again somewhere.$"
# 653 "data/maps/Route120/scripts.pory"

# 654 "data/maps/Route120/scripts.pory"
Kecleon_Text_SomethingUnseeable:
# 655 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.$"
# 656 "data/maps/Route120/scripts.pory"

# 657 "data/maps/Route120/scripts.pory"
Kecleon_Text_WantToUseDevonScope:
# 658 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.\p"
# 659 "data/maps/Route120/scripts.pory"
	.string "Want to use the DEVON SCOPE?$"
# 660 "data/maps/Route120/scripts.pory"

# 661 "data/maps/Route120/scripts.pory"
Kecleon_Text_UseDevonScopeMonAttacked:
# 662 "data/maps/Route120/scripts.pory"
	.string "{PLAYER} used the DEVON SCOPE.\p"
# 663 "data/maps/Route120/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 664 "data/maps/Route120/scripts.pory"
	.string "visible!\p"
# 665 "data/maps/Route120/scripts.pory"
	.string "The startled POKéMON attacked!$"
# 666 "data/maps/Route120/scripts.pory"

# 667 "data/maps/Route120/scripts.pory"
Route120_Text_RouteSignFortree:
# 668 "data/maps/Route120/scripts.pory"
	.string "ROUTE 120\n"
# 669 "data/maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} FORTREE CITY$"
# 670 "data/maps/Route120/scripts.pory"

# 671 "data/maps/Route120/scripts.pory"
Route120_Text_RouteSign121:
# 672 "data/maps/Route120/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 121\n"
# 673 "data/maps/Route120/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 120$"
