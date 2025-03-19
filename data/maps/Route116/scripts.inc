# 1 "data/maps/Route116/scripts.pory"

# 2 "data/maps/Route116/scripts.pory"
.set LOCALID_BRINEY, 22
# 3 "data/maps/Route116/scripts.pory"
.set LOCALID_WANDAS_BF_OUTSIDE, 21
# 4 "data/maps/Route116/scripts.pory"
.set LOCALID_DEVAN, 20
# 5 "data/maps/Route116/scripts.pory"
.set LOCALID_CLARK, 9
# 6 "data/maps/Route116/scripts.pory"
.set LOCALID_SARAH, 16
# 7 "data/maps/Route116/scripts.pory"
.set LOCALID_DAWSON, 17
# 8 "data/maps/Route116/scripts.pory"
.set LOCALID_JERRY, 13
# 9 "data/maps/Route116/scripts.pory"
.set LOCALID_JANICE, 11
# 10 "data/maps/Route116/scripts.pory"
.set LOCALID_JOSE, 4
# 11 "data/maps/Route116/scripts.pory"
.set LOCALID_JOEY, 3
# 12 "data/maps/Route116/scripts.pory"
.set LOCALID_JOHNSON, 19
# 13 "data/maps/Route116/scripts.pory"
.set LOCALID_KAREN, 12
# 14 "data/maps/Route116/scripts.pory"

# 15 "data/maps/Route116/scripts.pory"
Route116_MapScripts::
# 16 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
# 17 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
# 18 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
# 19 "data/maps/Route116/scripts.pory"
	.byte 0
# 20 "data/maps/Route116/scripts.pory"

# 21 "data/maps/Route116/scripts.pory"
Route116_OnTransition:
# 22 "data/maps/Route116/scripts.pory"
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
# 23 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 24 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_StartGroudonWeather
# 25 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_StartGroudonWeather
# 26 "data/maps/Route116/scripts.pory"
	end
# 27 "data/maps/Route116/scripts.pory"

# 28 "data/maps/Route116/scripts.pory"
Route116_EventScript_SetWandasBoyfriendPos::
# 29 "data/maps/Route116/scripts.pory"
	setobjectxyperm LOCALID_WANDAS_BF_OUTSIDE, 38, 10
# 30 "data/maps/Route116/scripts.pory"
	return
# 31 "data/maps/Route116/scripts.pory"

# 32 "data/maps/Route116/scripts.pory"
Route116_OnLoad:
# 33 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute116North
# 34 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute116South
# 35 "data/maps/Route116/scripts.pory"
	end
# 36 "data/maps/Route116/scripts.pory"

# 37 "data/maps/Route116/scripts.pory"
Route116_OnFrame:
# 38 "data/maps/Route116/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 39 "data/maps/Route116/scripts.pory"
	.2byte 0
# 40 "data/maps/Route116/scripts.pory"

# 41 "data/maps/Route116/scripts.pory"
Route116_EventScript_WandasBoyfriend::
# 42 "data/maps/Route116/scripts.pory"
	lock
# 43 "data/maps/Route116/scripts.pory"
	faceplayer
# 44 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
# 45 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
# 46 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
# 47 "data/maps/Route116/scripts.pory"
	release
# 48 "data/maps/Route116/scripts.pory"
	end
# 49 "data/maps/Route116/scripts.pory"

# 50 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntLeftTunnel::
# 51 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
# 52 "data/maps/Route116/scripts.pory"
	release
# 53 "data/maps/Route116/scripts.pory"
	end
# 54 "data/maps/Route116/scripts.pory"

# 55 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntInTunnel::
# 56 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
# 57 "data/maps/Route116/scripts.pory"
	release
# 58 "data/maps/Route116/scripts.pory"
	end
# 59 "data/maps/Route116/scripts.pory"

# 60 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployee::
# 61 "data/maps/Route116/scripts.pory"
	lock
# 62 "data/maps/Route116/scripts.pory"
	faceplayer
# 63 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
# 64 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
# 65 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 66 "data/maps/Route116/scripts.pory"
	end
# 67 "data/maps/Route116/scripts.pory"

# 68 "data/maps/Route116/scripts.pory"
Route116_EventScript_GiveRepeatBall::
# 69 "data/maps/Route116/scripts.pory"
	setflag FLAG_MET_DEVON_EMPLOYEE
# 70 "data/maps/Route116/scripts.pory"
	giveitem ITEM_REPEAT_BALL
# 71 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
# 72 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
# 73 "data/maps/Route116/scripts.pory"
	closemessage
# 74 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
# 75 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
# 76 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
# 77 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
# 78 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 79 "data/maps/Route116/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 80 "data/maps/Route116/scripts.pory"
	setflag FLAG_RECEIVED_REPEAT_BALL
# 81 "data/maps/Route116/scripts.pory"
	release
# 82 "data/maps/Route116/scripts.pory"
	end
# 83 "data/maps/Route116/scripts.pory"

# 84 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExit::
# 85 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
# 86 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 87 "data/maps/Route116/scripts.pory"
	return
# 88 "data/maps/Route116/scripts.pory"

# 89 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExitEast::
# 90 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
# 91 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 92 "data/maps/Route116/scripts.pory"
	return
# 93 "data/maps/Route116/scripts.pory"

# 94 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryGiveRepeatBallAgain::
# 95 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
# 96 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 97 "data/maps/Route116/scripts.pory"
	end
# 98 "data/maps/Route116/scripts.pory"

# 99 "data/maps/Route116/scripts.pory"
Route116_EventScript_NoRoomForRepeatBall::
# 100 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
# 101 "data/maps/Route116/scripts.pory"
	release
# 102 "data/maps/Route116/scripts.pory"
	end
# 103 "data/maps/Route116/scripts.pory"

# 104 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExit:
# 105 "data/maps/Route116/scripts.pory"
	walk_left
# 106 "data/maps/Route116/scripts.pory"
	walk_left
# 107 "data/maps/Route116/scripts.pory"
	walk_left
# 108 "data/maps/Route116/scripts.pory"
	walk_left
# 109 "data/maps/Route116/scripts.pory"
	walk_left
# 110 "data/maps/Route116/scripts.pory"
	walk_left
# 111 "data/maps/Route116/scripts.pory"
	walk_left
# 112 "data/maps/Route116/scripts.pory"
	walk_left
# 113 "data/maps/Route116/scripts.pory"
	step_end
# 114 "data/maps/Route116/scripts.pory"

# 115 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExitEast:
# 116 "data/maps/Route116/scripts.pory"
	walk_down
# 117 "data/maps/Route116/scripts.pory"
	walk_left
# 118 "data/maps/Route116/scripts.pory"
	walk_left
# 119 "data/maps/Route116/scripts.pory"
	walk_left
# 120 "data/maps/Route116/scripts.pory"
	walk_left
# 121 "data/maps/Route116/scripts.pory"
	walk_left
# 122 "data/maps/Route116/scripts.pory"
	walk_left
# 123 "data/maps/Route116/scripts.pory"
	walk_left
# 124 "data/maps/Route116/scripts.pory"
	walk_left
# 125 "data/maps/Route116/scripts.pory"
	walk_left
# 126 "data/maps/Route116/scripts.pory"
	step_end
# 127 "data/maps/Route116/scripts.pory"

# 128 "data/maps/Route116/scripts.pory"
Route116_EventScript_RouteSignRustboro::
# 129 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
# 130 "data/maps/Route116/scripts.pory"
	end
# 131 "data/maps/Route116/scripts.pory"

# 132 "data/maps/Route116/scripts.pory"
Route116_EventScript_RusturfTunnelSign::
# 133 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
# 134 "data/maps/Route116/scripts.pory"
	end
# 135 "data/maps/Route116/scripts.pory"

# 136 "data/maps/Route116/scripts.pory"
Route116_EventScript_TunnelersRestHouseSign::
# 137 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
# 138 "data/maps/Route116/scripts.pory"
	end
# 139 "data/maps/Route116/scripts.pory"

# 140 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBToStopEvolution::
# 141 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
# 142 "data/maps/Route116/scripts.pory"
	end
# 143 "data/maps/Route116/scripts.pory"

# 144 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBagHasPockets::
# 145 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
# 146 "data/maps/Route116/scripts.pory"
	end
# 147 "data/maps/Route116/scripts.pory"

# 148 "data/maps/Route116/scripts.pory"
Route116_EventScript_Briney::
# 149 "data/maps/Route116/scripts.pory"
	lock
# 150 "data/maps/Route116/scripts.pory"
	faceplayer
# 151 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 152 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 153 "data/maps/Route116/scripts.pory"
	release
# 154 "data/maps/Route116/scripts.pory"
	end
# 155 "data/maps/Route116/scripts.pory"

# 156 "data/maps/Route116/scripts.pory"
Route116_EventScript_BrineyTrigger::
# 157 "data/maps/Route116/scripts.pory"
	lockall
# 158 "data/maps/Route116/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterRight
# 159 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 160 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 161 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 162 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 163 "data/maps/Route116/scripts.pory"
	releaseall
# 164 "data/maps/Route116/scripts.pory"
	end
# 165 "data/maps/Route116/scripts.pory"

# 166 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesMan::
# 167 "data/maps/Route116/scripts.pory"
	lock
# 168 "data/maps/Route116/scripts.pory"
	faceplayer
# 169 "data/maps/Route116/scripts.pory"
	checkitem ITEM_BLACK_GLASSES
# 170 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
# 171 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 172 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
# 173 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 174 "data/maps/Route116/scripts.pory"
	release
# 175 "data/maps/Route116/scripts.pory"
	end
# 176 "data/maps/Route116/scripts.pory"

# 177 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesNotOnPlayer::
# 178 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
# 179 "data/maps/Route116/scripts.pory"
	closemessage
# 180 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 181 "data/maps/Route116/scripts.pory"
	end
# 182 "data/maps/Route116/scripts.pory"

# 183 "data/maps/Route116/scripts.pory"
Route116_EventScript_PlayerHasGlasses::
# 184 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 185 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
# 186 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 187 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
# 188 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
# 189 "data/maps/Route116/scripts.pory"
	release
# 190 "data/maps/Route116/scripts.pory"
	end
# 191 "data/maps/Route116/scripts.pory"

# 192 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesOnPlayer::
# 193 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
# 194 "data/maps/Route116/scripts.pory"
	closemessage
# 195 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 196 "data/maps/Route116/scripts.pory"
	end
# 197 "data/maps/Route116/scripts.pory"

# 198 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExit::
# 199 "data/maps/Route116/scripts.pory"
	delay 20
# 200 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
# 201 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
# 202 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
# 203 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
# 204 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 205 "data/maps/Route116/scripts.pory"
	release
# 206 "data/maps/Route116/scripts.pory"
	end
# 207 "data/maps/Route116/scripts.pory"

# 208 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitNormal::
# 209 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
# 210 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 211 "data/maps/Route116/scripts.pory"
	return
# 212 "data/maps/Route116/scripts.pory"

# 213 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitEast::
# 214 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
# 215 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 216 "data/maps/Route116/scripts.pory"
	return
# 217 "data/maps/Route116/scripts.pory"

# 218 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExit:
# 219 "data/maps/Route116/scripts.pory"
	walk_left
# 220 "data/maps/Route116/scripts.pory"
	walk_left
# 221 "data/maps/Route116/scripts.pory"
	walk_left
# 222 "data/maps/Route116/scripts.pory"
	walk_left
# 223 "data/maps/Route116/scripts.pory"
	walk_left
# 224 "data/maps/Route116/scripts.pory"
	walk_left
# 225 "data/maps/Route116/scripts.pory"
	walk_left
# 226 "data/maps/Route116/scripts.pory"
	walk_left
# 227 "data/maps/Route116/scripts.pory"
	walk_left
# 228 "data/maps/Route116/scripts.pory"
	step_end
# 229 "data/maps/Route116/scripts.pory"

# 230 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExitEast:
# 231 "data/maps/Route116/scripts.pory"
	walk_up
# 232 "data/maps/Route116/scripts.pory"
	walk_left
# 233 "data/maps/Route116/scripts.pory"
	walk_left
# 234 "data/maps/Route116/scripts.pory"
	walk_left
# 235 "data/maps/Route116/scripts.pory"
	walk_left
# 236 "data/maps/Route116/scripts.pory"
	walk_left
# 237 "data/maps/Route116/scripts.pory"
	walk_left
# 238 "data/maps/Route116/scripts.pory"
	walk_left
# 239 "data/maps/Route116/scripts.pory"
	walk_left
# 240 "data/maps/Route116/scripts.pory"
	walk_left
# 241 "data/maps/Route116/scripts.pory"
	step_end
# 242 "data/maps/Route116/scripts.pory"

# 243 "data/maps/Route116/scripts.pory"
Route116_EventScript_Joey::
# 244 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
# 245 "data/maps/Route116/scripts.pory"
	end
# 246 "data/maps/Route116/scripts.pory"

# 247 "data/maps/Route116/scripts.pory"
Route116_EventScript_JoseJoey::
# 248 "data/maps/Route116/scripts.pory"
lockall
# 249 "data/maps/Route116/scripts.pory"
setvar VAR_0x8008, LOCALID_JOSE
# 250 "data/maps/Route116/scripts.pory"
playse SE_PIN
# 251 "data/maps/Route116/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 252 "data/maps/Route116/scripts.pory"
waitmovement 0
# 253 "data/maps/Route116/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 254 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 255 "data/maps/Route116/scripts.pory"
waitmovement 0
# 256 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_JoseIntro MSGBOX_AUTOCLOSE
# 257 "data/maps/Route116/scripts.pory"
setvar VAR_0x8008, LOCALID_JOEY
# 258 "data/maps/Route116/scripts.pory"
playse SE_PIN
# 259 "data/maps/Route116/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 260 "data/maps/Route116/scripts.pory"
waitmovement 0
# 261 "data/maps/Route116/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 262 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 263 "data/maps/Route116/scripts.pory"
waitmovement 0
# 264 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_JoeyIntro MSGBOX_AUTOCLOSE
# 265 "data/maps/Route116/scripts.pory"
goto Route116_EventScript_JoseJoeyDoMultiBattle
# 266 "data/maps/Route116/scripts.pory"
releaseall
# 267 "data/maps/Route116/scripts.pory"
end
# 268 "data/maps/Route116/scripts.pory"

# 269 "data/maps/Route116/scripts.pory"
Route116_EventScript_JoseJoeyDoMultiBattle::
# 270 "data/maps/Route116/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 271 "data/maps/Route116/scripts.pory"
multi_2p_vs_2 TRAINER_JOSE, Route116_Text_JoseDefeat, TRAINER_JOEY, Route116_Text_JoeyDefeat, PARTNER_EMMIE
# 272 "data/maps/Route116/scripts.pory"
switch VAR_RESULT
# 273 "data/maps/Route116/scripts.pory"
case 1, Route116_EventScript_JoseJoeyVictory
# 274 "data/maps/Route116/scripts.pory"
fadescreen FADE_TO_BLACK
# 275 "data/maps/Route116/scripts.pory"
special SetCB2WhiteOut
# 276 "data/maps/Route116/scripts.pory"
waitstate
# 277 "data/maps/Route116/scripts.pory"

# 278 "data/maps/Route116/scripts.pory"
Route116_EventScript_JoseJoeyVictory::
# 279 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 280 "data/maps/Route116/scripts.pory"
waitmovement 0
# 281 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
# 282 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 283 "data/maps/Route116/scripts.pory"
waitmovement 0
# 284 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
# 285 "data/maps/Route116/scripts.pory"
addvar VAR_ROUTE116_STATE, 1
# 286 "data/maps/Route116/scripts.pory"
end
# 287 "data/maps/Route116/scripts.pory"

# 288 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jose::
# 289 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
# 290 "data/maps/Route116/scripts.pory"
	end
# 291 "data/maps/Route116/scripts.pory"

# 292 "data/maps/Route116/scripts.pory"
Route116_EventScript_JerryJanice::
# 293 "data/maps/Route116/scripts.pory"
lockall
# 294 "data/maps/Route116/scripts.pory"
setvar VAR_0x8008, LOCALID_JERRY
# 295 "data/maps/Route116/scripts.pory"
playse SE_PIN
# 296 "data/maps/Route116/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 297 "data/maps/Route116/scripts.pory"
waitmovement 0
# 298 "data/maps/Route116/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 299 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 300 "data/maps/Route116/scripts.pory"
waitmovement 0
# 301 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_JerryIntro MSGBOX_AUTOCLOSE
# 302 "data/maps/Route116/scripts.pory"
setvar VAR_0x8008, LOCALID_JANICE
# 303 "data/maps/Route116/scripts.pory"
playse SE_PIN
# 304 "data/maps/Route116/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 305 "data/maps/Route116/scripts.pory"
waitmovement 0
# 306 "data/maps/Route116/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 307 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 308 "data/maps/Route116/scripts.pory"
waitmovement 0
# 309 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_JaniceIntro MSGBOX_AUTOCLOSE
# 310 "data/maps/Route116/scripts.pory"
goto Route116_EventScript_JerryJaniceDoMultiBattle
# 311 "data/maps/Route116/scripts.pory"
releaseall
# 312 "data/maps/Route116/scripts.pory"
end
# 313 "data/maps/Route116/scripts.pory"

# 314 "data/maps/Route116/scripts.pory"
Route116_EventScript_JerryJaniceDoMultiBattle::
# 315 "data/maps/Route116/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 316 "data/maps/Route116/scripts.pory"
multi_2p_vs_2 TRAINER_JERRY_1, Route116_Text_JerryDefeat, TRAINER_JANICE, Route116_Text_JaniceDefeat, PARTNER_EMMIE
# 317 "data/maps/Route116/scripts.pory"
switch VAR_RESULT
# 318 "data/maps/Route116/scripts.pory"
case 1, Route116_EventScript_JerryJaniceVictory
# 319 "data/maps/Route116/scripts.pory"
fadescreen FADE_TO_BLACK
# 320 "data/maps/Route116/scripts.pory"
special SetCB2WhiteOut
# 321 "data/maps/Route116/scripts.pory"
waitstate
# 322 "data/maps/Route116/scripts.pory"

# 323 "data/maps/Route116/scripts.pory"
Route116_EventScript_JerryJaniceVictory::
# 324 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 325 "data/maps/Route116/scripts.pory"
waitmovement 0
# 326 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
# 327 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 328 "data/maps/Route116/scripts.pory"
waitmovement 0
# 329 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
# 330 "data/maps/Route116/scripts.pory"
addvar VAR_ROUTE116_STATE, 1
# 331 "data/maps/Route116/scripts.pory"
end
# 332 "data/maps/Route116/scripts.pory"

# 333 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jerry::
# 334 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 335 "data/maps/Route116/scripts.pory"
	release
# 336 "data/maps/Route116/scripts.pory"
	end
# 337 "data/maps/Route116/scripts.pory"

# 338 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerryAfterBattle::
# 339 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
# 340 "data/maps/Route116/scripts.pory"
	release
# 341 "data/maps/Route116/scripts.pory"
	end
# 342 "data/maps/Route116/scripts.pory"

# 343 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerryAfterBattle::
# 344 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 345 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 346 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
# 347 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 348 "data/maps/Route116/scripts.pory"
	release
# 349 "data/maps/Route116/scripts.pory"
	end
# 350 "data/maps/Route116/scripts.pory"

# 351 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerry::
# 352 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
# 353 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 354 "data/maps/Route116/scripts.pory"
	release
# 355 "data/maps/Route116/scripts.pory"
	end
# 356 "data/maps/Route116/scripts.pory"

# 357 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerry::
# 358 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
# 359 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 360 "data/maps/Route116/scripts.pory"
	release
# 361 "data/maps/Route116/scripts.pory"
	end
# 362 "data/maps/Route116/scripts.pory"

# 363 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchJerry::
# 364 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
# 365 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
# 366 "data/maps/Route116/scripts.pory"
	end
# 367 "data/maps/Route116/scripts.pory"

# 368 "data/maps/Route116/scripts.pory"
Route116_EventScript_Clark::
# 369 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
# 370 "data/maps/Route116/scripts.pory"
	end
# 371 "data/maps/Route116/scripts.pory"

# 372 "data/maps/Route116/scripts.pory"
Route116_EventScript_Janice::
# 373 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
# 374 "data/maps/Route116/scripts.pory"
	end
# 375 "data/maps/Route116/scripts.pory"

# 376 "data/maps/Route116/scripts.pory"
Route116_EventScript_Karen::
# 377 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 378 "data/maps/Route116/scripts.pory"
	release
# 379 "data/maps/Route116/scripts.pory"
	end
# 380 "data/maps/Route116/scripts.pory"

# 381 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKarenAfterBattle::
# 382 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
# 383 "data/maps/Route116/scripts.pory"
	release
# 384 "data/maps/Route116/scripts.pory"
	end
# 385 "data/maps/Route116/scripts.pory"

# 386 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKarenAfterBattle::
# 387 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 388 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 389 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
# 390 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 391 "data/maps/Route116/scripts.pory"
	release
# 392 "data/maps/Route116/scripts.pory"
	end
# 393 "data/maps/Route116/scripts.pory"

# 394 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKaren::
# 395 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
# 396 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 397 "data/maps/Route116/scripts.pory"
	release
# 398 "data/maps/Route116/scripts.pory"
	end
# 399 "data/maps/Route116/scripts.pory"

# 400 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKaren::
# 401 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
# 402 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 403 "data/maps/Route116/scripts.pory"
	release
# 404 "data/maps/Route116/scripts.pory"
	end
# 405 "data/maps/Route116/scripts.pory"

# 406 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchKaren::
# 407 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
# 408 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
# 409 "data/maps/Route116/scripts.pory"
	end
# 410 "data/maps/Route116/scripts.pory"

# 411 "data/maps/Route116/scripts.pory"
Route116_EventScript_Sarah::
# 412 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
# 413 "data/maps/Route116/scripts.pory"
	end
# 414 "data/maps/Route116/scripts.pory"

# 415 "data/maps/Route116/scripts.pory"
Route116_EventScript_DawsonSarah::
# 416 "data/maps/Route116/scripts.pory"
lockall
# 417 "data/maps/Route116/scripts.pory"
setvar VAR_0x8008, LOCALID_DAWSON
# 418 "data/maps/Route116/scripts.pory"
playse SE_PIN
# 419 "data/maps/Route116/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 420 "data/maps/Route116/scripts.pory"
waitmovement 0
# 421 "data/maps/Route116/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 422 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 423 "data/maps/Route116/scripts.pory"
waitmovement 0
# 424 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_DawsonIntro MSGBOX_AUTOCLOSE
# 425 "data/maps/Route116/scripts.pory"
setvar VAR_0x8008, LOCALID_SARAH
# 426 "data/maps/Route116/scripts.pory"
playse SE_PIN
# 427 "data/maps/Route116/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 428 "data/maps/Route116/scripts.pory"
waitmovement 0
# 429 "data/maps/Route116/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 430 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 431 "data/maps/Route116/scripts.pory"
waitmovement 0
# 432 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_SarahIntro MSGBOX_AUTOCLOSE
# 433 "data/maps/Route116/scripts.pory"
goto Route116_EventScript_DawsonSarahDoMultiBattle
# 434 "data/maps/Route116/scripts.pory"
releaseall
# 435 "data/maps/Route116/scripts.pory"
end
# 436 "data/maps/Route116/scripts.pory"

# 437 "data/maps/Route116/scripts.pory"
Route116_EventScript_DawsonSarahDoMultiBattle::
# 438 "data/maps/Route116/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 439 "data/maps/Route116/scripts.pory"
multi_2p_vs_2 TRAINER_DAWSON, Route116_Text_DawsonDefeat, TRAINER_SARAH, Route116_Text_SarahDefeat, PARTNER_EMMIE
# 440 "data/maps/Route116/scripts.pory"
switch VAR_RESULT
# 441 "data/maps/Route116/scripts.pory"
case 1, Route116_EventScript_DawsonSarahVictory
# 442 "data/maps/Route116/scripts.pory"
fadescreen FADE_TO_BLACK
# 443 "data/maps/Route116/scripts.pory"
special SetCB2WhiteOut
# 444 "data/maps/Route116/scripts.pory"
waitstate
# 445 "data/maps/Route116/scripts.pory"

# 446 "data/maps/Route116/scripts.pory"
Route116_EventScript_DawsonSarahVictory::
# 447 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 448 "data/maps/Route116/scripts.pory"
waitmovement 0
# 449 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 450 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 451 "data/maps/Route116/scripts.pory"
waitmovement 0
# 452 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
# 453 "data/maps/Route116/scripts.pory"
addvar VAR_ROUTE116_STATE, 1
# 454 "data/maps/Route116/scripts.pory"
end
# 455 "data/maps/Route116/scripts.pory"

# 456 "data/maps/Route116/scripts.pory"
Route116_EventScript_Dawson::
# 457 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 458 "data/maps/Route116/scripts.pory"
	end
# 459 "data/maps/Route116/scripts.pory"

# 460 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevanClark::
# 461 "data/maps/Route116/scripts.pory"
lockall
# 462 "data/maps/Route116/scripts.pory"
setvar VAR_0x8008, LOCALID_DEVAN
# 463 "data/maps/Route116/scripts.pory"
playse SE_PIN
# 464 "data/maps/Route116/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 465 "data/maps/Route116/scripts.pory"
waitmovement 0
# 466 "data/maps/Route116/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 467 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 468 "data/maps/Route116/scripts.pory"
waitmovement 0
# 469 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_DevanIntro MSGBOX_AUTOCLOSE
# 470 "data/maps/Route116/scripts.pory"
setvar VAR_0x8008, LOCALID_CLARK
# 471 "data/maps/Route116/scripts.pory"
playse SE_PIN
# 472 "data/maps/Route116/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 473 "data/maps/Route116/scripts.pory"
waitmovement 0
# 474 "data/maps/Route116/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 475 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 476 "data/maps/Route116/scripts.pory"
waitmovement 0
# 477 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_ClarkIntro MSGBOX_AUTOCLOSE
# 478 "data/maps/Route116/scripts.pory"
goto Route116_EventScript_DevanClarkDoMultiBattle
# 479 "data/maps/Route116/scripts.pory"
releaseall
# 480 "data/maps/Route116/scripts.pory"
end
# 481 "data/maps/Route116/scripts.pory"

# 482 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevanClarkDoMultiBattle::
# 483 "data/maps/Route116/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 484 "data/maps/Route116/scripts.pory"
multi_2p_vs_2 TRAINER_DEVAN, Route116_Text_DevanDefeat, TRAINER_CLARK, Route116_Text_ClarkDefeat, PARTNER_EMMIE
# 485 "data/maps/Route116/scripts.pory"
switch VAR_RESULT
# 486 "data/maps/Route116/scripts.pory"
case 1, Route116_EventScript_DevanClarkVictory
# 487 "data/maps/Route116/scripts.pory"
fadescreen FADE_TO_BLACK
# 488 "data/maps/Route116/scripts.pory"
special SetCB2WhiteOut
# 489 "data/maps/Route116/scripts.pory"
waitstate
# 490 "data/maps/Route116/scripts.pory"

# 491 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevanClarkVictory::
# 492 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 493 "data/maps/Route116/scripts.pory"
waitmovement 0
# 494 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
# 495 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 496 "data/maps/Route116/scripts.pory"
waitmovement 0
# 497 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
# 498 "data/maps/Route116/scripts.pory"
addvar VAR_ROUTE116_STATE, 1
# 499 "data/maps/Route116/scripts.pory"
end
# 500 "data/maps/Route116/scripts.pory"

# 501 "data/maps/Route116/scripts.pory"
Route116_EventScript_Devan::
# 502 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
# 503 "data/maps/Route116/scripts.pory"
	end
# 504 "data/maps/Route116/scripts.pory"

# 505 "data/maps/Route116/scripts.pory"
Route116_EventScript_JohnsonKaren::
# 506 "data/maps/Route116/scripts.pory"
lockall
# 507 "data/maps/Route116/scripts.pory"
setvar VAR_0x8008, LOCALID_JOHNSON
# 508 "data/maps/Route116/scripts.pory"
playse SE_PIN
# 509 "data/maps/Route116/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 510 "data/maps/Route116/scripts.pory"
waitmovement 0
# 511 "data/maps/Route116/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 512 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 513 "data/maps/Route116/scripts.pory"
waitmovement 0
# 514 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_JohnsonIntro MSGBOX_AUTOCLOSE
# 515 "data/maps/Route116/scripts.pory"
setvar VAR_0x8008, LOCALID_KAREN
# 516 "data/maps/Route116/scripts.pory"
playse SE_PIN
# 517 "data/maps/Route116/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 518 "data/maps/Route116/scripts.pory"
waitmovement 0
# 519 "data/maps/Route116/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 520 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 521 "data/maps/Route116/scripts.pory"
waitmovement 0
# 522 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_KarenIntro MSGBOX_AUTOCLOSE
# 523 "data/maps/Route116/scripts.pory"
goto Route116_EventScript_JohnsonKarenDoMultiBattle
# 524 "data/maps/Route116/scripts.pory"
releaseall
# 525 "data/maps/Route116/scripts.pory"
end
# 526 "data/maps/Route116/scripts.pory"

# 527 "data/maps/Route116/scripts.pory"
Route116_EventScript_JohnsonKarenDoMultiBattle::
# 528 "data/maps/Route116/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 529 "data/maps/Route116/scripts.pory"
multi_2p_vs_2 TRAINER_JOHNSON, Route116_Text_JohnsonDefeat, TRAINER_KAREN_1, Route116_Text_KarenDefeat, PARTNER_EMMIE
# 530 "data/maps/Route116/scripts.pory"
switch VAR_RESULT
# 531 "data/maps/Route116/scripts.pory"
case 1, Route116_EventScript_JohnsonKarenVictory
# 532 "data/maps/Route116/scripts.pory"
fadescreen FADE_TO_BLACK
# 533 "data/maps/Route116/scripts.pory"
special SetCB2WhiteOut
# 534 "data/maps/Route116/scripts.pory"
waitstate
# 535 "data/maps/Route116/scripts.pory"

# 536 "data/maps/Route116/scripts.pory"
Route116_EventScript_JohnsonKarenVictory::
# 537 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 538 "data/maps/Route116/scripts.pory"
waitmovement 0
# 539 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
# 540 "data/maps/Route116/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 541 "data/maps/Route116/scripts.pory"
waitmovement 0
# 542 "data/maps/Route116/scripts.pory"
msgbox Route116_Text_KarenPostBattle, MSGBOX_AUTOCLOSE
# 543 "data/maps/Route116/scripts.pory"
addvar VAR_ROUTE116_STATE, 1
# 544 "data/maps/Route116/scripts.pory"
end
# 545 "data/maps/Route116/scripts.pory"

# 546 "data/maps/Route116/scripts.pory"
Route116_EventScript_Johnson::
# 547 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
# 548 "data/maps/Route116/scripts.pory"
	end
# 549 "data/maps/Route116/scripts.pory"

# 550 "data/maps/Route116/scripts.pory"
Route116_Text_ScoundrelMadeOffWithPeeko:
# 551 "data/maps/Route116/scripts.pory"
	.string "Ohhh, what am I to do?\p"
# 552 "data/maps/Route116/scripts.pory"
	.string "We were on our walk, PEEKO and I, when\n"
# 553 "data/maps/Route116/scripts.pory"
	.string "we were jumped by an odd thug…\p"
# 554 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
# 555 "data/maps/Route116/scripts.pory"
	.string "darling PEEKO!\p"
# 556 "data/maps/Route116/scripts.pory"
	.string "Wrrrooooooaaaar! PEEKO!$"
# 557 "data/maps/Route116/scripts.pory"

# 558 "data/maps/Route116/scripts.pory"
Route116_Text_WantToDigTunnel:
# 559 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 560 "data/maps/Route116/scripts.pory"
	.string "I want to dig that tunnel!$"
# 561 "data/maps/Route116/scripts.pory"

# 562 "data/maps/Route116/scripts.pory"
Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
# 563 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\n"
# 564 "data/maps/Route116/scripts.pory"
	.string "What's going on?\p"
# 565 "data/maps/Route116/scripts.pory"
	.string "I was digging the tunnel without any\n"
# 566 "data/maps/Route116/scripts.pory"
	.string "tools when some goon ordered me out!\p"
# 567 "data/maps/Route116/scripts.pory"
	.string "That tunnel's filled with POKéMON\n"
# 568 "data/maps/Route116/scripts.pory"
	.string "that react badly to loud noises.\l"
# 569 "data/maps/Route116/scripts.pory"
	.string "They could cause an uproar.\p"
# 570 "data/maps/Route116/scripts.pory"
	.string "That's why we stopped using heavy\n"
# 571 "data/maps/Route116/scripts.pory"
	.string "equipment for tunneling…\p"
# 572 "data/maps/Route116/scripts.pory"
	.string "I'm worried that the goon will do\n"
# 573 "data/maps/Route116/scripts.pory"
	.string "something stupid and startle the\l"
# 574 "data/maps/Route116/scripts.pory"
	.string "POKéMON into an uproar.$"
# 575 "data/maps/Route116/scripts.pory"

# 576 "data/maps/Route116/scripts.pory"
Route116_Text_GoonHightailedItOutOfTunnel:
# 577 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 578 "data/maps/Route116/scripts.pory"
	.string "That goofy goon hightailed it out of\n"
# 579 "data/maps/Route116/scripts.pory"
	.string "the tunnel! I can go back to digging!$"
# 580 "data/maps/Route116/scripts.pory"

# 581 "data/maps/Route116/scripts.pory"
Route116_Text_ThankYouTokenOfAppreciation:
# 582 "data/maps/Route116/scripts.pory"
	.string "Oh! It's you!\p"
# 583 "data/maps/Route116/scripts.pory"
	.string "You're that person who not only helped\n"
# 584 "data/maps/Route116/scripts.pory"
	.string "me in PETALBURG WOODS, but also got\l"
# 585 "data/maps/Route116/scripts.pory"
	.string "back my stolen package and then even\l"
# 586 "data/maps/Route116/scripts.pory"
	.string "graciously delivered it to SLATEPORT!\p"
# 587 "data/maps/Route116/scripts.pory"
	.string "CAPT. STERN informed us that the\n"
# 588 "data/maps/Route116/scripts.pory"
	.string "package arrived, too!\p"
# 589 "data/maps/Route116/scripts.pory"
	.string "I thank you very, very much!\p"
# 590 "data/maps/Route116/scripts.pory"
	.string "Why, if I were a rain cloud, I would\n"
# 591 "data/maps/Route116/scripts.pory"
	.string "shower you with gratitude and hail\l"
# 592 "data/maps/Route116/scripts.pory"
	.string "you as a hero!\p"
# 593 "data/maps/Route116/scripts.pory"
	.string "For you, the most wonderful TRAINER,\n"
# 594 "data/maps/Route116/scripts.pory"
	.string "I bear good news!\p"
# 595 "data/maps/Route116/scripts.pory"
	.string "Recently, our company developed\n"
# 596 "data/maps/Route116/scripts.pory"
	.string "a new kind of POKé BALL.\p"
# 597 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation, this\n"
# 598 "data/maps/Route116/scripts.pory"
	.string "is our gift to our wonderful TRAINER!$"
# 599 "data/maps/Route116/scripts.pory"

# 600 "data/maps/Route116/scripts.pory"
Route116_Text_NewBallAvailableAtMart:
# 601 "data/maps/Route116/scripts.pory"
	.string "Our new POKé BALL will be available\n"
# 602 "data/maps/Route116/scripts.pory"
	.string "at the POKéMON MART in RUSTBORO.\p"
# 603 "data/maps/Route116/scripts.pory"
	.string "Please do try it out!\n"
# 604 "data/maps/Route116/scripts.pory"
	.string "Thank you and bye-bye!$"
# 605 "data/maps/Route116/scripts.pory"

# 606 "data/maps/Route116/scripts.pory"
Route116_Text_BagIsJamPacked:
# 607 "data/maps/Route116/scripts.pory"
	.string "Your BAG is jam-packed.\n"
# 608 "data/maps/Route116/scripts.pory"
	.string "I can't give you this REPEAT BALL.$"
# 609 "data/maps/Route116/scripts.pory"

# 610 "data/maps/Route116/scripts.pory"
Route116_Text_TokenOfAppreciation:
# 611 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation for\n"
# 612 "data/maps/Route116/scripts.pory"
	.string "your delivering our package, I have\l"
# 613 "data/maps/Route116/scripts.pory"
	.string "a gift of a new kind of POKé BALL\l"
# 614 "data/maps/Route116/scripts.pory"
	.string "for our most wonderful TRAINER!$"
# 615 "data/maps/Route116/scripts.pory"

# 616 "data/maps/Route116/scripts.pory"
Route116_Text_CanYouHelpMeFindGlasses:
# 617 "data/maps/Route116/scripts.pory"
	.string "I dropped my glasses…\n"
# 618 "data/maps/Route116/scripts.pory"
	.string "Can you help me find them?$"
# 619 "data/maps/Route116/scripts.pory"

# 620 "data/maps/Route116/scripts.pory"
Route116_Text_MayISeeThoseGlasses:
# 621 "data/maps/Route116/scripts.pory"
	.string "Those glasses!\n"
# 622 "data/maps/Route116/scripts.pory"
	.string "May I see them for a second?$"
# 623 "data/maps/Route116/scripts.pory"

# 624 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
# 625 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 626 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 627 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…\p"
# 628 "data/maps/Route116/scripts.pory"
	.string "Maybe my glasses aren't around\n"
# 629 "data/maps/Route116/scripts.pory"
	.string "here…$"
# 630 "data/maps/Route116/scripts.pory"

# 631 "data/maps/Route116/scripts.pory"
Route116_Text_CantFindGlassesNotHere:
# 632 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 633 "data/maps/Route116/scripts.pory"
	.string "I can't find my glasses anywhere…\l"
# 634 "data/maps/Route116/scripts.pory"
	.string "Maybe they're not around here…$"
# 635 "data/maps/Route116/scripts.pory"

# 636 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingFor:
# 637 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 638 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 639 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…$"
# 640 "data/maps/Route116/scripts.pory"

# 641 "data/maps/Route116/scripts.pory"
Route116_Text_RouteSignRustboro:
# 642 "data/maps/Route116/scripts.pory"
	.string "ROUTE 116\n"
# 643 "data/maps/Route116/scripts.pory"
	.string "{LEFT_ARROW} RUSTBORO CITY$"
# 644 "data/maps/Route116/scripts.pory"

# 645 "data/maps/Route116/scripts.pory"
Route116_Text_RusturfTunnelSign:
# 646 "data/maps/Route116/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 647 "data/maps/Route116/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 648 "data/maps/Route116/scripts.pory"
	.string "“The tunnel project has been\n"
# 649 "data/maps/Route116/scripts.pory"
	.string "canceled.”$"
# 650 "data/maps/Route116/scripts.pory"

# 651 "data/maps/Route116/scripts.pory"
Route116_Text_TunnelersRestHouse:
# 652 "data/maps/Route116/scripts.pory"
	.string "TUNNELER'S REST HOUSE$"
# 653 "data/maps/Route116/scripts.pory"

# 654 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBToStopEvolution:
# 655 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 656 "data/maps/Route116/scripts.pory"
	.string "If you want to stop a POKéMON from\n"
# 657 "data/maps/Route116/scripts.pory"
	.string "evolving, press the B Button while it\l"
# 658 "data/maps/Route116/scripts.pory"
	.string "is trying to evolve.\l"
# 659 "data/maps/Route116/scripts.pory"
	.string "The startled POKéMON will stop.\p"
# 660 "data/maps/Route116/scripts.pory"
	.string "This is called an evolution cancel.$"
# 661 "data/maps/Route116/scripts.pory"

# 662 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBagHasPockets:
# 663 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 664 "data/maps/Route116/scripts.pory"
	.string "Your BAG has several POCKETS.\p"
# 665 "data/maps/Route116/scripts.pory"
	.string "Items you obtain are automatically\n"
# 666 "data/maps/Route116/scripts.pory"
	.string "placed in the appropriate POCKETS.\p"
# 667 "data/maps/Route116/scripts.pory"
	.string "No TRAINER can afford to be without\n"
# 668 "data/maps/Route116/scripts.pory"
	.string "a BAG of their own.$"
