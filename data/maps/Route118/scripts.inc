# 1 "data/maps/Route118/scripts.pory"

# 2 "data/maps/Route118/scripts.pory"
.set LOCALID_STEVEN, 13
# 3 "data/maps/Route118/scripts.pory"
.set LOCALID_BARNY, 11
# 4 "data/maps/Route118/scripts.pory"
.set LOCALID_WADE, 9
# 5 "data/maps/Route118/scripts.pory"
.set LOCALID_ROSE, 8
# 6 "data/maps/Route118/scripts.pory"
.set LOCALID_DEANDRE, 15
# 7 "data/maps/Route118/scripts.pory"
.set LOCALID_CHESTER, 10
# 8 "data/maps/Route118/scripts.pory"
.set LOCALID_DALTON, 12
# 9 "data/maps/Route118/scripts.pory"

# 10 "data/maps/Route118/scripts.pory"
Route118_MapScripts::
# 11 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
# 12 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
# 13 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
# 14 "data/maps/Route118/scripts.pory"
	.byte 0
# 15 "data/maps/Route118/scripts.pory"

# 16 "data/maps/Route118/scripts.pory"
Route118_OnTransition:
# 17 "data/maps/Route118/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 18 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 19 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_StartGroudonWeather
# 20 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_StartGroudonWeather
# 21 "data/maps/Route118/scripts.pory"
	end
# 22 "data/maps/Route118/scripts.pory"

# 23 "data/maps/Route118/scripts.pory"
Route118_OnLoad:
# 24 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_EventScript_PlaceTilesRoute118East
# 25 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_EventScript_PlaceTilesRoute118West
# 26 "data/maps/Route118/scripts.pory"
	end
# 27 "data/maps/Route118/scripts.pory"

# 28 "data/maps/Route118/scripts.pory"
Route118_OnFrame:
# 29 "data/maps/Route118/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 30 "data/maps/Route118/scripts.pory"
	.2byte 0
# 31 "data/maps/Route118/scripts.pory"

# 32 "data/maps/Route118/scripts.pory"
Route118_EventScript_GoodRodFisherman::
# 33 "data/maps/Route118/scripts.pory"
	lock
# 34 "data/maps/Route118/scripts.pory"
	faceplayer
# 35 "data/maps/Route118/scripts.pory"
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
# 36 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
# 37 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route118_EventScript_ReceiveGoodRod
# 38 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route118_EventScript_DeclineGoodRod
# 39 "data/maps/Route118/scripts.pory"
	end
# 40 "data/maps/Route118/scripts.pory"

# 41 "data/maps/Route118/scripts.pory"
Route118_EventScript_ReceiveGoodRod::
# 42 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
# 43 "data/maps/Route118/scripts.pory"
	giveitem ITEM_GOOD_ROD
# 44 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 45 "data/maps/Route118/scripts.pory"
	setflag FLAG_RECEIVED_GOOD_ROD
# 46 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
# 47 "data/maps/Route118/scripts.pory"
	release
# 48 "data/maps/Route118/scripts.pory"
	end
# 49 "data/maps/Route118/scripts.pory"

# 50 "data/maps/Route118/scripts.pory"
Route118_EventScript_DeclineGoodRod::
# 51 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
# 52 "data/maps/Route118/scripts.pory"
	release
# 53 "data/maps/Route118/scripts.pory"
	end
# 54 "data/maps/Route118/scripts.pory"

# 55 "data/maps/Route118/scripts.pory"
Route118_EventScript_ReceivedGoodRod::
# 56 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
# 57 "data/maps/Route118/scripts.pory"
	release
# 58 "data/maps/Route118/scripts.pory"
	end
# 59 "data/maps/Route118/scripts.pory"

# 60 "data/maps/Route118/scripts.pory"
Route118_EventScript_Girl::
# 61 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
# 62 "data/maps/Route118/scripts.pory"
	end
# 63 "data/maps/Route118/scripts.pory"

# 64 "data/maps/Route118/scripts.pory"
Route118_EventScript_RouteSignMauville::
# 65 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
# 66 "data/maps/Route118/scripts.pory"
	end
# 67 "data/maps/Route118/scripts.pory"

# 68 "data/maps/Route118/scripts.pory"
Route118_EventScript_RouteSign119::
# 69 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
# 70 "data/maps/Route118/scripts.pory"
	end
# 71 "data/maps/Route118/scripts.pory"

# 72 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger0::
# 73 "data/maps/Route118/scripts.pory"
	lockall
# 74 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 0
# 75 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 76 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 77 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenApproachLedge0
# 78 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 79 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 80 "data/maps/Route118/scripts.pory"
	end
# 81 "data/maps/Route118/scripts.pory"

# 82 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger1::
# 83 "data/maps/Route118/scripts.pory"
	lockall
# 84 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 1
# 85 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 86 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 87 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 88 "data/maps/Route118/scripts.pory"
	end
# 89 "data/maps/Route118/scripts.pory"

# 90 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger2::
# 91 "data/maps/Route118/scripts.pory"
	lockall
# 92 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 2
# 93 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 94 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 95 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 96 "data/maps/Route118/scripts.pory"
	end
# 97 "data/maps/Route118/scripts.pory"

# 98 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger::
# 99 "data/maps/Route118/scripts.pory"
	playse SE_LEDGE
# 100 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenJumpLedge
# 101 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 102 "data/maps/Route118/scripts.pory"
	delay 30
# 103 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
# 104 "data/maps/Route118/scripts.pory"
	closemessage
# 105 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route118_EventScript_StevenExit0
# 106 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route118_EventScript_StevenExit1
# 107 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route118_EventScript_StevenExit2
# 108 "data/maps/Route118/scripts.pory"
	addvar VAR_ROUTE118_STATE, 1
# 109 "data/maps/Route118/scripts.pory"
	removeobject LOCALID_STEVEN
# 110 "data/maps/Route118/scripts.pory"
	releaseall
# 111 "data/maps/Route118/scripts.pory"
	end
# 112 "data/maps/Route118/scripts.pory"

# 113 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit0::
# 114 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 115 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit0
# 116 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 117 "data/maps/Route118/scripts.pory"
	return
# 118 "data/maps/Route118/scripts.pory"

# 119 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit1::
# 120 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 121 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit1
# 122 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 123 "data/maps/Route118/scripts.pory"
	return
# 124 "data/maps/Route118/scripts.pory"

# 125 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit2::
# 126 "data/maps/Route118/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 127 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_STEVEN, Route118_Movement_StevenExit2
# 128 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 129 "data/maps/Route118/scripts.pory"
	return
# 130 "data/maps/Route118/scripts.pory"

# 131 "data/maps/Route118/scripts.pory"
Route118_Movement_PlayerWatchStevenExit:
# 132 "data/maps/Route118/scripts.pory"
	delay_16
# 133 "data/maps/Route118/scripts.pory"
	walk_in_place_faster_right
# 134 "data/maps/Route118/scripts.pory"
	step_end
# 135 "data/maps/Route118/scripts.pory"

# 136 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenApproachLedge0:
# 137 "data/maps/Route118/scripts.pory"
	walk_left
# 138 "data/maps/Route118/scripts.pory"
	step_end
# 139 "data/maps/Route118/scripts.pory"

# 140 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenApproachLedge2:
# 141 "data/maps/Route118/scripts.pory"
	walk_right
# 142 "data/maps/Route118/scripts.pory"
	step_end
# 143 "data/maps/Route118/scripts.pory"

# 144 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenJumpLedge:
# 145 "data/maps/Route118/scripts.pory"
	jump_2_down
# 146 "data/maps/Route118/scripts.pory"
	delay_16
# 147 "data/maps/Route118/scripts.pory"
	walk_down
# 148 "data/maps/Route118/scripts.pory"
	step_end
# 149 "data/maps/Route118/scripts.pory"

# 150 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit0:
# 151 "data/maps/Route118/scripts.pory"
	walk_right
# 152 "data/maps/Route118/scripts.pory"
	walk_right
# 153 "data/maps/Route118/scripts.pory"
	walk_right
# 154 "data/maps/Route118/scripts.pory"
	walk_right
# 155 "data/maps/Route118/scripts.pory"
	walk_right
# 156 "data/maps/Route118/scripts.pory"
	walk_right
# 157 "data/maps/Route118/scripts.pory"
	walk_right
# 158 "data/maps/Route118/scripts.pory"
	walk_right
# 159 "data/maps/Route118/scripts.pory"
	walk_right
# 160 "data/maps/Route118/scripts.pory"
	walk_right
# 161 "data/maps/Route118/scripts.pory"
	step_end
# 162 "data/maps/Route118/scripts.pory"

# 163 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit1:
# 164 "data/maps/Route118/scripts.pory"
	walk_right
# 165 "data/maps/Route118/scripts.pory"
	walk_right
# 166 "data/maps/Route118/scripts.pory"
	walk_right
# 167 "data/maps/Route118/scripts.pory"
	walk_right
# 168 "data/maps/Route118/scripts.pory"
	walk_right
# 169 "data/maps/Route118/scripts.pory"
	walk_right
# 170 "data/maps/Route118/scripts.pory"
	walk_right
# 171 "data/maps/Route118/scripts.pory"
	walk_right
# 172 "data/maps/Route118/scripts.pory"
	walk_right
# 173 "data/maps/Route118/scripts.pory"
	step_end
# 174 "data/maps/Route118/scripts.pory"

# 175 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit2:
# 176 "data/maps/Route118/scripts.pory"
	walk_right
# 177 "data/maps/Route118/scripts.pory"
	walk_right
# 178 "data/maps/Route118/scripts.pory"
	walk_right
# 179 "data/maps/Route118/scripts.pory"
	walk_right
# 180 "data/maps/Route118/scripts.pory"
	walk_right
# 181 "data/maps/Route118/scripts.pory"
	walk_right
# 182 "data/maps/Route118/scripts.pory"
	walk_right
# 183 "data/maps/Route118/scripts.pory"
	walk_right
# 184 "data/maps/Route118/scripts.pory"
	step_end
# 185 "data/maps/Route118/scripts.pory"

# 186 "data/maps/Route118/scripts.pory"
Route118_EventScript_Rose::
# 187 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
# 188 "data/maps/Route118/scripts.pory"
	release
# 189 "data/maps/Route118/scripts.pory"
	end
# 190 "data/maps/Route118/scripts.pory"

# 191 "data/maps/Route118/scripts.pory"
Route118_EventScript_RegisterRose::
# 192 "data/maps/Route118/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 193 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 194 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
# 195 "data/maps/Route118/scripts.pory"
	register_matchcall TRAINER_ROSE_1
# 196 "data/maps/Route118/scripts.pory"
	release
# 197 "data/maps/Route118/scripts.pory"
	end
# 198 "data/maps/Route118/scripts.pory"

# 199 "data/maps/Route118/scripts.pory"
Route118_EventScript_RematchRose::
# 200 "data/maps/Route118/scripts.pory"
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_RoseRematchIntro, Route118_Text_RoseRematchDefeat
# 201 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RosePostRematch, MSGBOX_AUTOCLOSE
# 202 "data/maps/Route118/scripts.pory"
	end
# 203 "data/maps/Route118/scripts.pory"

# 204 "data/maps/Route118/scripts.pory"
Route118_EventScript_Barny::
# 205 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
# 206 "data/maps/Route118/scripts.pory"
	end
# 207 "data/maps/Route118/scripts.pory"

# 208 "data/maps/Route118/scripts.pory"
Route118_EventScript_Wade::
# 209 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
# 210 "data/maps/Route118/scripts.pory"
	end
# 211 "data/maps/Route118/scripts.pory"

# 212 "data/maps/Route118/scripts.pory"
Route118_EventScript_BarnyWade::
# 213 "data/maps/Route118/scripts.pory"
lockall
# 214 "data/maps/Route118/scripts.pory"
setvar VAR_0x8008, LOCALID_BARNY
# 215 "data/maps/Route118/scripts.pory"
playse SE_PIN
# 216 "data/maps/Route118/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 217 "data/maps/Route118/scripts.pory"
waitmovement 0
# 218 "data/maps/Route118/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 219 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 220 "data/maps/Route118/scripts.pory"
waitmovement 0
# 221 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_BarnyIntro MSGBOX_AUTOCLOSE
# 222 "data/maps/Route118/scripts.pory"
setvar VAR_0x8008, LOCALID_WADE
# 223 "data/maps/Route118/scripts.pory"
playse SE_PIN
# 224 "data/maps/Route118/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 225 "data/maps/Route118/scripts.pory"
waitmovement 0
# 226 "data/maps/Route118/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 227 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 228 "data/maps/Route118/scripts.pory"
waitmovement 0
# 229 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_WadeIntro MSGBOX_AUTOCLOSE
# 230 "data/maps/Route118/scripts.pory"
goto Route118_EventScript_BarnyWadeDoMultiBattle
# 231 "data/maps/Route118/scripts.pory"
releaseall
# 232 "data/maps/Route118/scripts.pory"
end
# 233 "data/maps/Route118/scripts.pory"

# 234 "data/maps/Route118/scripts.pory"
Route118_EventScript_BarnyWadeDoMultiBattle::
# 235 "data/maps/Route118/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 236 "data/maps/Route118/scripts.pory"
multi_2p_vs_2 TRAINER_BARNY, Route118_Text_BarnyDefeat, TRAINER_WADE, Route118_Text_WadeDefeat, PARTNER_EMMIE
# 237 "data/maps/Route118/scripts.pory"
switch VAR_RESULT
# 238 "data/maps/Route118/scripts.pory"
case 1, Route118_EventScript_BarnyWadeVictory
# 239 "data/maps/Route118/scripts.pory"
fadescreen FADE_TO_BLACK
# 240 "data/maps/Route118/scripts.pory"
special SetCB2WhiteOut
# 241 "data/maps/Route118/scripts.pory"
waitstate
# 242 "data/maps/Route118/scripts.pory"

# 243 "data/maps/Route118/scripts.pory"
Route118_EventScript_BarnyWadeVictory::
# 244 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 245 "data/maps/Route118/scripts.pory"
waitmovement 0
# 246 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
# 247 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 248 "data/maps/Route118/scripts.pory"
waitmovement 0
# 249 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
# 250 "data/maps/Route118/scripts.pory"
addvar VAR_ROUTE118_STATE, 1
# 251 "data/maps/Route118/scripts.pory"
end
# 252 "data/maps/Route118/scripts.pory"

# 253 "data/maps/Route118/scripts.pory"
Route118_EventScript_ChesterDalton::
# 254 "data/maps/Route118/scripts.pory"
lockall
# 255 "data/maps/Route118/scripts.pory"
setvar VAR_0x8008, LOCALID_CHESTER
# 256 "data/maps/Route118/scripts.pory"
playse SE_PIN
# 257 "data/maps/Route118/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 258 "data/maps/Route118/scripts.pory"
waitmovement 0
# 259 "data/maps/Route118/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 260 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 261 "data/maps/Route118/scripts.pory"
waitmovement 0
# 262 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_ChesterIntro MSGBOX_AUTOCLOSE
# 263 "data/maps/Route118/scripts.pory"
setvar VAR_0x8008, LOCALID_DALTON
# 264 "data/maps/Route118/scripts.pory"
playse SE_PIN
# 265 "data/maps/Route118/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 266 "data/maps/Route118/scripts.pory"
waitmovement 0
# 267 "data/maps/Route118/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 268 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 269 "data/maps/Route118/scripts.pory"
waitmovement 0
# 270 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_DaltonIntro MSGBOX_AUTOCLOSE
# 271 "data/maps/Route118/scripts.pory"
goto Route118_EventScript_ChesterDaltonDoMultiBattle
# 272 "data/maps/Route118/scripts.pory"
releaseall
# 273 "data/maps/Route118/scripts.pory"
end
# 274 "data/maps/Route118/scripts.pory"

# 275 "data/maps/Route118/scripts.pory"
Route118_EventScript_ChesterDaltonDoMultiBattle::
# 276 "data/maps/Route118/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 277 "data/maps/Route118/scripts.pory"
multi_2p_vs_2 TRAINER_CHESTER, Route118_Text_ChesterDefeat, TRAINER_DALTON_1, Route118_Text_DaltonDefeat, PARTNER_EMMIE
# 278 "data/maps/Route118/scripts.pory"
switch VAR_RESULT
# 279 "data/maps/Route118/scripts.pory"
case 1, Route118_EventScript_ChesterDaltonVictory
# 280 "data/maps/Route118/scripts.pory"
fadescreen FADE_TO_BLACK
# 281 "data/maps/Route118/scripts.pory"
special SetCB2WhiteOut
# 282 "data/maps/Route118/scripts.pory"
waitstate
# 283 "data/maps/Route118/scripts.pory"

# 284 "data/maps/Route118/scripts.pory"
Route118_EventScript_ChesterDaltonVictory::
# 285 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 286 "data/maps/Route118/scripts.pory"
waitmovement 0
# 287 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
# 288 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 289 "data/maps/Route118/scripts.pory"
waitmovement 0
# 290 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_DaltonPostBattle, MSGBOX_AUTOCLOSE
# 291 "data/maps/Route118/scripts.pory"
addvar VAR_ROUTE118_STATE, 1
# 292 "data/maps/Route118/scripts.pory"
end
# 293 "data/maps/Route118/scripts.pory"

# 294 "data/maps/Route118/scripts.pory"
Route118_EventScript_Dalton::
# 295 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
# 296 "data/maps/Route118/scripts.pory"
	release
# 297 "data/maps/Route118/scripts.pory"
	end
# 298 "data/maps/Route118/scripts.pory"

# 299 "data/maps/Route118/scripts.pory"
Route118_EventScript_RegisterDalton::
# 300 "data/maps/Route118/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 301 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 302 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
# 303 "data/maps/Route118/scripts.pory"
	register_matchcall TRAINER_DALTON_1
# 304 "data/maps/Route118/scripts.pory"
	release
# 305 "data/maps/Route118/scripts.pory"
	end
# 306 "data/maps/Route118/scripts.pory"

# 307 "data/maps/Route118/scripts.pory"
Route118_EventScript_RematchDalton::
# 308 "data/maps/Route118/scripts.pory"
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
# 309 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
# 310 "data/maps/Route118/scripts.pory"
	end
# 311 "data/maps/Route118/scripts.pory"

# 312 "data/maps/Route118/scripts.pory"
Route118_EventScript_Perry::
# 313 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
# 314 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
# 315 "data/maps/Route118/scripts.pory"
	end
# 316 "data/maps/Route118/scripts.pory"

# 317 "data/maps/Route118/scripts.pory"
Route118_EventScript_Chester::
# 318 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
# 319 "data/maps/Route118/scripts.pory"
	end
# 320 "data/maps/Route118/scripts.pory"

# 321 "data/maps/Route118/scripts.pory"
Route118_EventScript_DeandreRose::
# 322 "data/maps/Route118/scripts.pory"
lockall
# 323 "data/maps/Route118/scripts.pory"
setvar VAR_0x8008, LOCALID_DEANDRE
# 324 "data/maps/Route118/scripts.pory"
playse SE_PIN
# 325 "data/maps/Route118/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 326 "data/maps/Route118/scripts.pory"
waitmovement 0
# 327 "data/maps/Route118/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 328 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 329 "data/maps/Route118/scripts.pory"
waitmovement 0
# 330 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_DeandreIntro MSGBOX_AUTOCLOSE
# 331 "data/maps/Route118/scripts.pory"
setvar VAR_0x8008, LOCALID_ROSE
# 332 "data/maps/Route118/scripts.pory"
playse SE_PIN
# 333 "data/maps/Route118/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 334 "data/maps/Route118/scripts.pory"
waitmovement 0
# 335 "data/maps/Route118/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 336 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 337 "data/maps/Route118/scripts.pory"
waitmovement 0
# 338 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_RoseIntro MSGBOX_AUTOCLOSE
# 339 "data/maps/Route118/scripts.pory"
goto Route118_EventScript_DeandreRoseDoMultiBattle
# 340 "data/maps/Route118/scripts.pory"
releaseall
# 341 "data/maps/Route118/scripts.pory"
end
# 342 "data/maps/Route118/scripts.pory"

# 343 "data/maps/Route118/scripts.pory"
Route118_EventScript_DeandreRoseDoMultiBattle::
# 344 "data/maps/Route118/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 345 "data/maps/Route118/scripts.pory"
multi_2p_vs_2 TRAINER_DEANDRE, Route118_Text_DeandreDefeat, TRAINER_ROSE_1, Route118_Text_RoseDefeat, PARTNER_EMMIE
# 346 "data/maps/Route118/scripts.pory"
switch VAR_RESULT
# 347 "data/maps/Route118/scripts.pory"
case 1, Route118_EventScript_DeandreRoseVictory
# 348 "data/maps/Route118/scripts.pory"
fadescreen FADE_TO_BLACK
# 349 "data/maps/Route118/scripts.pory"
special SetCB2WhiteOut
# 350 "data/maps/Route118/scripts.pory"
waitstate
# 351 "data/maps/Route118/scripts.pory"

# 352 "data/maps/Route118/scripts.pory"
Route118_EventScript_DeandreRoseVictory::
# 353 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 354 "data/maps/Route118/scripts.pory"
waitmovement 0
# 355 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
# 356 "data/maps/Route118/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 357 "data/maps/Route118/scripts.pory"
waitmovement 0
# 358 "data/maps/Route118/scripts.pory"
msgbox Route118_Text_RosePostBattle, MSGBOX_AUTOCLOSE
# 359 "data/maps/Route118/scripts.pory"
addvar VAR_ROUTE118_STATE, 1
# 360 "data/maps/Route118/scripts.pory"
end
# 361 "data/maps/Route118/scripts.pory"

# 362 "data/maps/Route118/scripts.pory"
Route118_EventScript_Deandre::
# 363 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
# 364 "data/maps/Route118/scripts.pory"
	end
# 365 "data/maps/Route118/scripts.pory"

# 366 "data/maps/Route118/scripts.pory"
Route118_Text_StevenQuestions:
# 367 "data/maps/Route118/scripts.pory"
	.string "STEVEN: Hi, {PLAYER}{KUN}!\p"
# 368 "data/maps/Route118/scripts.pory"
	.string "It's me, STEVEN!\n"
# 369 "data/maps/Route118/scripts.pory"
	.string "We met in the cave near DEWFORD.\p"
# 370 "data/maps/Route118/scripts.pory"
	.string "Have you met many kinds of POKéMON\n"
# 371 "data/maps/Route118/scripts.pory"
	.string "since I last saw you?\p"
# 372 "data/maps/Route118/scripts.pory"
	.string "There are many, many kinds of POKéMON\n"
# 373 "data/maps/Route118/scripts.pory"
	.string "in this wide world of ours.\p"
# 374 "data/maps/Route118/scripts.pory"
	.string "If you wanted to raise only your\n"
# 375 "data/maps/Route118/scripts.pory"
	.string "favorites, that's fine.\p"
# 376 "data/maps/Route118/scripts.pory"
	.string "Perhaps you find it more fun to raise\n"
# 377 "data/maps/Route118/scripts.pory"
	.string "all sorts of POKéMON.\p"
# 378 "data/maps/Route118/scripts.pory"
	.string "As a TRAINER of POKéMON,\n"
# 379 "data/maps/Route118/scripts.pory"
	.string "what do you think?\p"
# 380 "data/maps/Route118/scripts.pory"
	.string "Of course, it's not any of my business.\p"
# 381 "data/maps/Route118/scripts.pory"
	.string "It would be nice if we were to meet\n"
# 382 "data/maps/Route118/scripts.pory"
	.string "again somewhere.$"
# 383 "data/maps/Route118/scripts.pory"

# 384 "data/maps/Route118/scripts.pory"
Route118_Text_YouAgreeGoodRodIsGood:
# 385 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 386 "data/maps/Route118/scripts.pory"
	.string "A GOOD ROD is really good!\p"
# 387 "data/maps/Route118/scripts.pory"
	.string "Wouldn't you agree?$"
# 388 "data/maps/Route118/scripts.pory"

# 389 "data/maps/Route118/scripts.pory"
Route118_Text_IdenticalMindsTakeThis:
# 390 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 391 "data/maps/Route118/scripts.pory"
	.string "We're of identical minds!\p"
# 392 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 393 "data/maps/Route118/scripts.pory"
	.string "Take this GOOD ROD!$"
# 394 "data/maps/Route118/scripts.pory"

# 395 "data/maps/Route118/scripts.pory"
Route118_Text_TryYourLuckFishing:
# 396 "data/maps/Route118/scripts.pory"
	.string "Wherever there's water, try your luck\n"
# 397 "data/maps/Route118/scripts.pory"
	.string "at fishing.$"
# 398 "data/maps/Route118/scripts.pory"

# 399 "data/maps/Route118/scripts.pory"
Route118_Text_DontYouLikeToFish:
# 400 "data/maps/Route118/scripts.pory"
	.string "Don't you like to fish?$"
# 401 "data/maps/Route118/scripts.pory"

# 402 "data/maps/Route118/scripts.pory"
Route118_Text_TryCatchingMonWithGoodRod:
# 403 "data/maps/Route118/scripts.pory"
	.string "Try catching all sorts of POKéMON\n"
# 404 "data/maps/Route118/scripts.pory"
	.string "with your GOOD ROD.$"
# 405 "data/maps/Route118/scripts.pory"

# 406 "data/maps/Route118/scripts.pory"
Route118_Text_CanCrossRiversWithSurf:
# 407 "data/maps/Route118/scripts.pory"
	.string "Even if there isn't a boat, you can\n"
# 408 "data/maps/Route118/scripts.pory"
	.string "cross rivers and the sea if you have\l"
# 409 "data/maps/Route118/scripts.pory"
	.string "a POKéMON that knows SURF.\p"
# 410 "data/maps/Route118/scripts.pory"
	.string "POKéMON can be counted on to do so\n"
# 411 "data/maps/Route118/scripts.pory"
	.string "much!$"
# 412 "data/maps/Route118/scripts.pory"

# 413 "data/maps/Route118/scripts.pory"
Route118_Text_RouteSignMauville:
# 414 "data/maps/Route118/scripts.pory"
	.string "ROUTE 118\n"
# 415 "data/maps/Route118/scripts.pory"
	.string "{LEFT_ARROW} MAUVILLE CITY$"
# 416 "data/maps/Route118/scripts.pory"

# 417 "data/maps/Route118/scripts.pory"
Route118_Text_RouteSign119:
# 418 "data/maps/Route118/scripts.pory"
	.string "ROUTE 118\n"
# 419 "data/maps/Route118/scripts.pory"
	.string "{UP_ARROW} ROUTE 119$"
