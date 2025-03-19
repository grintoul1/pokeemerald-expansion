# 1 "data/maps/Route114/scripts.pory"

# 2 "data/maps/Route114/scripts.pory"
.set LOCALID_GRUNT_ROUTE_114_1, 17
# 3 "data/maps/Route114/scripts.pory"
.set LOCALID_GRUNT_ROUTE_114_2, 4
# 4 "data/maps/Route114/scripts.pory"
.set LOCALID_GRUNT_ROUTE_114_3, 3
# 5 "data/maps/Route114/scripts.pory"
.set LOCALID_GRUNT_ROUTE_114_4, 25
# 6 "data/maps/Route114/scripts.pory"
.set LOCALID_GRUNT_ROUTE_114_5, 6
# 7 "data/maps/Route114/scripts.pory"
.set LOCALID_GRUNT_ROUTE_114_6, 5
# 8 "data/maps/Route114/scripts.pory"
.set LOCALID_IVY, 22
# 9 "data/maps/Route114/scripts.pory"
.set LOCALID_TYRA, 23
# 10 "data/maps/Route114/scripts.pory"
.set LOCALID_KAI, 27
# 11 "data/maps/Route114/scripts.pory"
.set LOCALID_CLAUDE, 16
# 12 "data/maps/Route114/scripts.pory"
.set LOCALID_STEVE, 7
# 13 "data/maps/Route114/scripts.pory"
.set LOCALID_CHARLOTTE, 24
# 14 "data/maps/Route114/scripts.pory"

# 15 "data/maps/Route114/scripts.pory"
Route114_MapScripts::
# 16 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_OnTransition
# 17 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route114_OnLoad
# 18 "data/maps/Route114/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route114_OnFrame
# 19 "data/maps/Route114/scripts.pory"
	.byte 0
# 20 "data/maps/Route114/scripts.pory"

# 21 "data/maps/Route114/scripts.pory"
Route114_OnTransition:
# 22 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 23 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, AbnormalWeather_StartGroudonWeather
# 24 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, AbnormalWeather_StartGroudonWeather
# 25 "data/maps/Route114/scripts.pory"
	end
# 26 "data/maps/Route114/scripts.pory"

# 27 "data/maps/Route114/scripts.pory"
Route114_OnLoad:
# 28 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute114North
# 29 "data/maps/Route114/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_114_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute114South
# 30 "data/maps/Route114/scripts.pory"
	end
# 31 "data/maps/Route114/scripts.pory"

# 32 "data/maps/Route114/scripts.pory"
Route114_OnFrame:
# 33 "data/maps/Route114/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 34 "data/maps/Route114/scripts.pory"
	.2byte 0
# 35 "data/maps/Route114/scripts.pory"

# 36 "data/maps/Route114/scripts.pory"
Route114_EventScript_Man::
# 37 "data/maps/Route114/scripts.pory"
	lock
# 38 "data/maps/Route114/scripts.pory"
	faceplayer
# 39 "data/maps/Route114/scripts.pory"
	dotimebasedevents
# 40 "data/maps/Route114/scripts.pory"
	goto_if_set FLAG_DAILY_ROUTE_114_RECEIVED_BERRY, Route114_EventScript_ReceivedBerry
# 41 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LoveUsingBerryCrushShareBerry, MSGBOX_DEFAULT
# 42 "data/maps/Route114/scripts.pory"
	random NUM_ROUTE_114_MAN_BERRIES
# 43 "data/maps/Route114/scripts.pory"
	addvar VAR_RESULT, NUM_ROUTE_114_MAN_BERRIES_SKIPPED
# 44 "data/maps/Route114/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 45 "data/maps/Route114/scripts.pory"
	giveitem VAR_RESULT
# 46 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 47 "data/maps/Route114/scripts.pory"
	setflag FLAG_DAILY_ROUTE_114_RECEIVED_BERRY
# 48 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_TryBerryCrushWithFriends, MSGBOX_DEFAULT
# 49 "data/maps/Route114/scripts.pory"
	release
# 50 "data/maps/Route114/scripts.pory"
	end
# 51 "data/maps/Route114/scripts.pory"

# 52 "data/maps/Route114/scripts.pory"
Route114_EventScript_ReceivedBerry::
# 53 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_FunToThinkAboutBerries, MSGBOX_DEFAULT
# 54 "data/maps/Route114/scripts.pory"
	release
# 55 "data/maps/Route114/scripts.pory"
	end
# 56 "data/maps/Route114/scripts.pory"

# 57 "data/maps/Route114/scripts.pory"
Route114_EventScript_RoarGentleman::
# 58 "data/maps/Route114/scripts.pory"
	lock
# 59 "data/maps/Route114/scripts.pory"
	faceplayer
# 60 "data/maps/Route114/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_ROAR, Route114_EventScript_ReceivedRoar
# 61 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_AllMyMonDoesIsRoarTakeThis, MSGBOX_DEFAULT
# 62 "data/maps/Route114/scripts.pory"
	giveitem ITEM_TM_ROAR
# 63 "data/maps/Route114/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 64 "data/maps/Route114/scripts.pory"
	setflag FLAG_RECEIVED_TM_ROAR
# 65 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
# 66 "data/maps/Route114/scripts.pory"
	release
# 67 "data/maps/Route114/scripts.pory"
	end
# 68 "data/maps/Route114/scripts.pory"

# 69 "data/maps/Route114/scripts.pory"
Route114_EventScript_ReceivedRoar::
# 70 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ExplainRoar, MSGBOX_DEFAULT
# 71 "data/maps/Route114/scripts.pory"
	release
# 72 "data/maps/Route114/scripts.pory"
	end
# 73 "data/maps/Route114/scripts.pory"

# 74 "data/maps/Route114/scripts.pory"
Route114_EventScript_Poochyena::
# 75 "data/maps/Route114/scripts.pory"
	lock
# 76 "data/maps/Route114/scripts.pory"
	faceplayer
# 77 "data/maps/Route114/scripts.pory"
	waitse
# 78 "data/maps/Route114/scripts.pory"
	playmoncry SPECIES_POOCHYENA, CRY_MODE_ENCOUNTER
# 79 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_Poochyena, MSGBOX_DEFAULT
# 80 "data/maps/Route114/scripts.pory"
	waitmoncry
# 81 "data/maps/Route114/scripts.pory"
	release
# 82 "data/maps/Route114/scripts.pory"
	end
# 83 "data/maps/Route114/scripts.pory"

# 84 "data/maps/Route114/scripts.pory"
Route114_EventScript_MeteorFallsSign::
# 85 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_MeteorFallsSign, MSGBOX_SIGN
# 86 "data/maps/Route114/scripts.pory"
	end
# 87 "data/maps/Route114/scripts.pory"

# 88 "data/maps/Route114/scripts.pory"
Route114_EventScript_FossilManiacsHouseSign::
# 89 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_FossilManiacsHouseSign, MSGBOX_SIGN
# 90 "data/maps/Route114/scripts.pory"
	end
# 91 "data/maps/Route114/scripts.pory"

# 92 "data/maps/Route114/scripts.pory"
Route114_EventScript_LanettesHouseSign::
# 93 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LanettesHouse, MSGBOX_SIGN
# 94 "data/maps/Route114/scripts.pory"
	end
# 95 "data/maps/Route114/scripts.pory"

# 96 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_3Grunt_Route_114_4::
# 97 "data/maps/Route114/scripts.pory"
lockall
# 98 "data/maps/Route114/scripts.pory"
setvar VAR_0x8008, LOCALID_GRUNT_ROUTE_114_3
# 99 "data/maps/Route114/scripts.pory"
playse SE_PIN
# 100 "data/maps/Route114/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 101 "data/maps/Route114/scripts.pory"
waitmovement 0
# 102 "data/maps/Route114/scripts.pory"
playbgm MUS_ENCOUNTER_MAGMA, TRUE
# 103 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 104 "data/maps/Route114/scripts.pory"
waitmovement 0
# 105 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_3Intro MSGBOX_AUTOCLOSE
# 106 "data/maps/Route114/scripts.pory"
setvar VAR_0x8008, LOCALID_GRUNT_ROUTE_114_4
# 107 "data/maps/Route114/scripts.pory"
playse SE_PIN
# 108 "data/maps/Route114/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 109 "data/maps/Route114/scripts.pory"
waitmovement 0
# 110 "data/maps/Route114/scripts.pory"
playbgm MUS_ENCOUNTER_MAGMA, TRUE
# 111 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 112 "data/maps/Route114/scripts.pory"
waitmovement 0
# 113 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_4Intro MSGBOX_AUTOCLOSE
# 114 "data/maps/Route114/scripts.pory"
goto Route114_EventScript_Grunt_Route_114_3Grunt_Route_114_4DoMultiBattle
# 115 "data/maps/Route114/scripts.pory"
releaseall
# 116 "data/maps/Route114/scripts.pory"
end
# 117 "data/maps/Route114/scripts.pory"

# 118 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_3Grunt_Route_114_4DoMultiBattle::
# 119 "data/maps/Route114/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 120 "data/maps/Route114/scripts.pory"
multi_2p_vs_2 TRAINER_GRUNT_ROUTE_114_3, Route114_Text_Grunt_Route_114_3Defeat, TRAINER_GRUNT_ROUTE_114_4, Route114_Text_Grunt_Route_114_4Defeat, PARTNER_EMMIE
# 121 "data/maps/Route114/scripts.pory"
switch VAR_RESULT
# 122 "data/maps/Route114/scripts.pory"
case 1, Route114_EventScript_Grunt_Route_114_3Grunt_Route_114_4Victory
# 123 "data/maps/Route114/scripts.pory"
fadescreen FADE_TO_BLACK
# 124 "data/maps/Route114/scripts.pory"
special SetCB2WhiteOut
# 125 "data/maps/Route114/scripts.pory"
waitstate
# 126 "data/maps/Route114/scripts.pory"

# 127 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_3Grunt_Route_114_4Victory::
# 128 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 129 "data/maps/Route114/scripts.pory"
waitmovement 0
# 130 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_3PostBattle, MSGBOX_AUTOCLOSE
# 131 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 132 "data/maps/Route114/scripts.pory"
waitmovement 0
# 133 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_4PostBattle, MSGBOX_AUTOCLOSE
# 134 "data/maps/Route114/scripts.pory"
addvar VAR_ROUTE114_STATE, 1
# 135 "data/maps/Route114/scripts.pory"
end
# 136 "data/maps/Route114/scripts.pory"

# 137 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_3::
# 138 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_Grunt_Route_114_3PostBattle, MSGBOX_AUTOCLOSE
# 139 "data/maps/Route114/scripts.pory"
	end
# 140 "data/maps/Route114/scripts.pory"

# 141 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_2::
# 142 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_Grunt_Route_114_2PostBattle, MSGBOX_AUTOCLOSE
# 143 "data/maps/Route114/scripts.pory"
	end
# 144 "data/maps/Route114/scripts.pory"

# 145 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_6::
# 146 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_Grunt_Route_114_6PostBattle, MSGBOX_AUTOCLOSE
# 147 "data/maps/Route114/scripts.pory"
	end
# 148 "data/maps/Route114/scripts.pory"

# 149 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_5Grunt_Route_114_6::
# 150 "data/maps/Route114/scripts.pory"
lockall
# 151 "data/maps/Route114/scripts.pory"
setvar VAR_0x8008, LOCALID_GRUNT_ROUTE_114_5
# 152 "data/maps/Route114/scripts.pory"
playse SE_PIN
# 153 "data/maps/Route114/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 154 "data/maps/Route114/scripts.pory"
waitmovement 0
# 155 "data/maps/Route114/scripts.pory"
playbgm MUS_ENCOUNTER_MAGMA, TRUE
# 156 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 157 "data/maps/Route114/scripts.pory"
waitmovement 0
# 158 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_5Intro MSGBOX_AUTOCLOSE
# 159 "data/maps/Route114/scripts.pory"
setvar VAR_0x8008, LOCALID_GRUNT_ROUTE_114_6
# 160 "data/maps/Route114/scripts.pory"
playse SE_PIN
# 161 "data/maps/Route114/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 162 "data/maps/Route114/scripts.pory"
waitmovement 0
# 163 "data/maps/Route114/scripts.pory"
playbgm MUS_ENCOUNTER_MAGMA, TRUE
# 164 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 165 "data/maps/Route114/scripts.pory"
waitmovement 0
# 166 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_6Intro MSGBOX_AUTOCLOSE
# 167 "data/maps/Route114/scripts.pory"
goto Route114_EventScript_Grunt_Route_114_5Grunt_Route_114_6DoMultiBattle
# 168 "data/maps/Route114/scripts.pory"
releaseall
# 169 "data/maps/Route114/scripts.pory"
end
# 170 "data/maps/Route114/scripts.pory"

# 171 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_5Grunt_Route_114_6DoMultiBattle::
# 172 "data/maps/Route114/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 173 "data/maps/Route114/scripts.pory"
multi_2p_vs_2 TRAINER_GRUNT_ROUTE_114_5, Route114_Text_Grunt_Route_114_5Defeat, TRAINER_GRUNT_ROUTE_114_6, Route114_Text_Grunt_Route_114_6Defeat, PARTNER_EMMIE
# 174 "data/maps/Route114/scripts.pory"
switch VAR_RESULT
# 175 "data/maps/Route114/scripts.pory"
case 1, Route114_EventScript_Grunt_Route_114_5Grunt_Route_114_6Victory
# 176 "data/maps/Route114/scripts.pory"
fadescreen FADE_TO_BLACK
# 177 "data/maps/Route114/scripts.pory"
special SetCB2WhiteOut
# 178 "data/maps/Route114/scripts.pory"
waitstate
# 179 "data/maps/Route114/scripts.pory"

# 180 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_5Grunt_Route_114_6Victory::
# 181 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 182 "data/maps/Route114/scripts.pory"
waitmovement 0
# 183 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_5PostBattle, MSGBOX_AUTOCLOSE
# 184 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 185 "data/maps/Route114/scripts.pory"
waitmovement 0
# 186 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_6PostBattle, MSGBOX_AUTOCLOSE
# 187 "data/maps/Route114/scripts.pory"
addvar VAR_ROUTE114_STATE, 1
# 188 "data/maps/Route114/scripts.pory"
end
# 189 "data/maps/Route114/scripts.pory"

# 190 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_5::
# 191 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_Grunt_Route_114_5PostBattle, MSGBOX_AUTOCLOSE
# 192 "data/maps/Route114/scripts.pory"
	end
# 193 "data/maps/Route114/scripts.pory"

# 194 "data/maps/Route114/scripts.pory"
Route114_EventScript_SteveCharlotte::
# 195 "data/maps/Route114/scripts.pory"
lockall
# 196 "data/maps/Route114/scripts.pory"
setvar VAR_0x8008, LOCALID_STEVE
# 197 "data/maps/Route114/scripts.pory"
playse SE_PIN
# 198 "data/maps/Route114/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 199 "data/maps/Route114/scripts.pory"
waitmovement 0
# 200 "data/maps/Route114/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 201 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 202 "data/maps/Route114/scripts.pory"
waitmovement 0
# 203 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_SteveIntro MSGBOX_AUTOCLOSE
# 204 "data/maps/Route114/scripts.pory"
setvar VAR_0x8008, LOCALID_CHARLOTTE
# 205 "data/maps/Route114/scripts.pory"
playse SE_PIN
# 206 "data/maps/Route114/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 207 "data/maps/Route114/scripts.pory"
waitmovement 0
# 208 "data/maps/Route114/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 209 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 210 "data/maps/Route114/scripts.pory"
waitmovement 0
# 211 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_CharlotteIntro MSGBOX_AUTOCLOSE
# 212 "data/maps/Route114/scripts.pory"
goto Route114_EventScript_SteveCharlotteDoMultiBattle
# 213 "data/maps/Route114/scripts.pory"
releaseall
# 214 "data/maps/Route114/scripts.pory"
end
# 215 "data/maps/Route114/scripts.pory"

# 216 "data/maps/Route114/scripts.pory"
Route114_EventScript_SteveCharlotteDoMultiBattle::
# 217 "data/maps/Route114/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 218 "data/maps/Route114/scripts.pory"
multi_2p_vs_2 TRAINER_STEVE_1, Route114_Text_SteveDefeat, TRAINER_CHARLOTTE, Route114_Text_CharlotteDefeat, PARTNER_EMMIE
# 219 "data/maps/Route114/scripts.pory"
switch VAR_RESULT
# 220 "data/maps/Route114/scripts.pory"
case 1, Route114_EventScript_SteveCharlotteVictory
# 221 "data/maps/Route114/scripts.pory"
fadescreen FADE_TO_BLACK
# 222 "data/maps/Route114/scripts.pory"
special SetCB2WhiteOut
# 223 "data/maps/Route114/scripts.pory"
waitstate
# 224 "data/maps/Route114/scripts.pory"

# 225 "data/maps/Route114/scripts.pory"
Route114_EventScript_SteveCharlotteVictory::
# 226 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 227 "data/maps/Route114/scripts.pory"
waitmovement 0
# 228 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_StevePostBattle, MSGBOX_AUTOCLOSE
# 229 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 230 "data/maps/Route114/scripts.pory"
waitmovement 0
# 231 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_CharlottePostBattle, MSGBOX_AUTOCLOSE
# 232 "data/maps/Route114/scripts.pory"
addvar VAR_ROUTE114_STATE, 1
# 233 "data/maps/Route114/scripts.pory"
end
# 234 "data/maps/Route114/scripts.pory"

# 235 "data/maps/Route114/scripts.pory"
Route114_EventScript_Steve::
# 236 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_StevePostBattle, MSGBOX_DEFAULT
# 237 "data/maps/Route114/scripts.pory"
	release
# 238 "data/maps/Route114/scripts.pory"
	end
# 239 "data/maps/Route114/scripts.pory"

# 240 "data/maps/Route114/scripts.pory"
Route114_EventScript_RegisterSteve::
# 241 "data/maps/Route114/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 242 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 243 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_SteveRegister, MSGBOX_DEFAULT
# 244 "data/maps/Route114/scripts.pory"
	register_matchcall TRAINER_STEVE_1
# 245 "data/maps/Route114/scripts.pory"
	release
# 246 "data/maps/Route114/scripts.pory"
	end
# 247 "data/maps/Route114/scripts.pory"

# 248 "data/maps/Route114/scripts.pory"
Route114_EventScript_RematchSteve::
# 249 "data/maps/Route114/scripts.pory"
	trainerbattle_rematch TRAINER_STEVE_1, Route114_Text_SteveRematchIntro, Route114_Text_SteveRematchDefeat
# 250 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_StevePostRematch, MSGBOX_AUTOCLOSE
# 251 "data/maps/Route114/scripts.pory"
	end
# 252 "data/maps/Route114/scripts.pory"

# 253 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_1Grunt_Route_114_2::
# 254 "data/maps/Route114/scripts.pory"
lockall
# 255 "data/maps/Route114/scripts.pory"
setvar VAR_0x8008, LOCALID_GRUNT_ROUTE_114_1
# 256 "data/maps/Route114/scripts.pory"
playse SE_PIN
# 257 "data/maps/Route114/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 258 "data/maps/Route114/scripts.pory"
waitmovement 0
# 259 "data/maps/Route114/scripts.pory"
playbgm MUS_ENCOUNTER_MAGMA, TRUE
# 260 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 261 "data/maps/Route114/scripts.pory"
waitmovement 0
# 262 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_1Intro MSGBOX_AUTOCLOSE
# 263 "data/maps/Route114/scripts.pory"
setvar VAR_0x8008, LOCALID_GRUNT_ROUTE_114_2
# 264 "data/maps/Route114/scripts.pory"
playse SE_PIN
# 265 "data/maps/Route114/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 266 "data/maps/Route114/scripts.pory"
waitmovement 0
# 267 "data/maps/Route114/scripts.pory"
playbgm MUS_ENCOUNTER_MAGMA, TRUE
# 268 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 269 "data/maps/Route114/scripts.pory"
waitmovement 0
# 270 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_2Intro MSGBOX_AUTOCLOSE
# 271 "data/maps/Route114/scripts.pory"
goto Route114_EventScript_Grunt_Route_114_1Grunt_Route_114_2DoMultiBattle
# 272 "data/maps/Route114/scripts.pory"
releaseall
# 273 "data/maps/Route114/scripts.pory"
end
# 274 "data/maps/Route114/scripts.pory"

# 275 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_1Grunt_Route_114_2DoMultiBattle::
# 276 "data/maps/Route114/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 277 "data/maps/Route114/scripts.pory"
multi_2p_vs_2 TRAINER_GRUNT_ROUTE_114_1, Route114_Text_Grunt_Route_114_1Defeat, TRAINER_GRUNT_ROUTE_114_2, Route114_Text_Grunt_Route_114_2Defeat, PARTNER_EMMIE
# 278 "data/maps/Route114/scripts.pory"
switch VAR_RESULT
# 279 "data/maps/Route114/scripts.pory"
case 1, Route114_EventScript_Grunt_Route_114_1Grunt_Route_114_2Victory
# 280 "data/maps/Route114/scripts.pory"
fadescreen FADE_TO_BLACK
# 281 "data/maps/Route114/scripts.pory"
special SetCB2WhiteOut
# 282 "data/maps/Route114/scripts.pory"
waitstate
# 283 "data/maps/Route114/scripts.pory"

# 284 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_1Grunt_Route_114_2Victory::
# 285 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 286 "data/maps/Route114/scripts.pory"
waitmovement 0
# 287 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_1PostBattle, MSGBOX_AUTOCLOSE
# 288 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 289 "data/maps/Route114/scripts.pory"
waitmovement 0
# 290 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_Grunt_Route_114_2PostBattle, MSGBOX_AUTOCLOSE
# 291 "data/maps/Route114/scripts.pory"
addvar VAR_ROUTE114_STATE, 1
# 292 "data/maps/Route114/scripts.pory"
end
# 293 "data/maps/Route114/scripts.pory"

# 294 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_1::
# 295 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_Grunt_Route_114_1PostBattle, MSGBOX_DEFAULT
# 296 "data/maps/Route114/scripts.pory"
	release
# 297 "data/maps/Route114/scripts.pory"
	end
# 298 "data/maps/Route114/scripts.pory"

# 299 "data/maps/Route114/scripts.pory"
Route114_EventScript_RegisterBernie::
# 300 "data/maps/Route114/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 301 "data/maps/Route114/scripts.pory"
	waitmovement 0
# 302 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BernieRegister, MSGBOX_DEFAULT
# 303 "data/maps/Route114/scripts.pory"
	register_matchcall TRAINER_BERNIE_2
# 304 "data/maps/Route114/scripts.pory"
	release
# 305 "data/maps/Route114/scripts.pory"
	end
# 306 "data/maps/Route114/scripts.pory"

# 307 "data/maps/Route114/scripts.pory"
Route114_EventScript_RematchBernie::
# 308 "data/maps/Route114/scripts.pory"
	trainerbattle_rematch TRAINER_BERNIE_2, Route114_Text_BernieRematchIntro, Route114_Text_BernieRematchDefeat
# 309 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BerniePostRematch, MSGBOX_AUTOCLOSE
# 310 "data/maps/Route114/scripts.pory"
	end
# 311 "data/maps/Route114/scripts.pory"

# 312 "data/maps/Route114/scripts.pory"
Route114_EventScript_Claude::
# 313 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
# 314 "data/maps/Route114/scripts.pory"
	end
# 315 "data/maps/Route114/scripts.pory"

# 316 "data/maps/Route114/scripts.pory"
Route114_EventScript_Nolan::
# 317 "data/maps/Route114/scripts.pory"
	trainerbattle_single TRAINER_NOLAN, Route114_Text_NolanIntro, Route114_Text_NolanDefeat
# 318 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
# 319 "data/maps/Route114/scripts.pory"
	end
# 320 "data/maps/Route114/scripts.pory"

# 321 "data/maps/Route114/scripts.pory"
Route114_EventScript_IvyTyra::
# 322 "data/maps/Route114/scripts.pory"
lockall
# 323 "data/maps/Route114/scripts.pory"
setvar VAR_0x8008, LOCALID_IVY
# 324 "data/maps/Route114/scripts.pory"
playse SE_PIN
# 325 "data/maps/Route114/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 326 "data/maps/Route114/scripts.pory"
waitmovement 0
# 327 "data/maps/Route114/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 328 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 329 "data/maps/Route114/scripts.pory"
waitmovement 0
# 330 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_IvyIntro MSGBOX_AUTOCLOSE
# 331 "data/maps/Route114/scripts.pory"
goto Route114_EventScript_IvyTyraDoMultiBattle
# 332 "data/maps/Route114/scripts.pory"
releaseall
# 333 "data/maps/Route114/scripts.pory"
end
# 334 "data/maps/Route114/scripts.pory"

# 335 "data/maps/Route114/scripts.pory"
Route114_EventScript_IvyTyraDoMultiBattle::
# 336 "data/maps/Route114/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 337 "data/maps/Route114/scripts.pory"
multi_2p_vs_1 TRAINER_TYRA_AND_IVY, Route114_Text_IvyDefeat, PARTNER_EMMIE
# 338 "data/maps/Route114/scripts.pory"
switch VAR_RESULT
# 339 "data/maps/Route114/scripts.pory"
case 1, Route114_EventScript_IvyTyraVictory
# 340 "data/maps/Route114/scripts.pory"
fadescreen FADE_TO_BLACK
# 341 "data/maps/Route114/scripts.pory"
special SetCB2WhiteOut
# 342 "data/maps/Route114/scripts.pory"
waitstate
# 343 "data/maps/Route114/scripts.pory"

# 344 "data/maps/Route114/scripts.pory"
Route114_EventScript_IvyTyraVictory::
# 345 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 346 "data/maps/Route114/scripts.pory"
waitmovement 0
# 347 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_IvyPostBattle, MSGBOX_AUTOCLOSE
# 348 "data/maps/Route114/scripts.pory"
addvar VAR_ROUTE114_STATE, 1
# 349 "data/maps/Route114/scripts.pory"
end
# 350 "data/maps/Route114/scripts.pory"

# 351 "data/maps/Route114/scripts.pory"
Route114_EventScript_Tyra::
# 352 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
# 353 "data/maps/Route114/scripts.pory"
	end
# 354 "data/maps/Route114/scripts.pory"

# 355 "data/maps/Route114/scripts.pory"
Route114_EventScript_Ivy::
# 356 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_IvyPostBattle, MSGBOX_AUTOCLOSE
# 357 "data/maps/Route114/scripts.pory"
	end
# 358 "data/maps/Route114/scripts.pory"

# 359 "data/maps/Route114/scripts.pory"
Route114_EventScript_Grunt_Route_114_4::
# 360 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_Grunt_Route_114_4PostBattle, MSGBOX_AUTOCLOSE
# 361 "data/maps/Route114/scripts.pory"
	end
# 362 "data/maps/Route114/scripts.pory"

# 363 "data/maps/Route114/scripts.pory"
Route114_EventScript_Charlotte::
# 364 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_CharlottePostBattle, MSGBOX_AUTOCLOSE
# 365 "data/maps/Route114/scripts.pory"
	end
# 366 "data/maps/Route114/scripts.pory"

# 367 "data/maps/Route114/scripts.pory"
Route114_EventScript_KaiClaude::
# 368 "data/maps/Route114/scripts.pory"
lockall
# 369 "data/maps/Route114/scripts.pory"
setvar VAR_0x8008, LOCALID_KAI
# 370 "data/maps/Route114/scripts.pory"
playse SE_PIN
# 371 "data/maps/Route114/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 372 "data/maps/Route114/scripts.pory"
waitmovement 0
# 373 "data/maps/Route114/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 374 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 375 "data/maps/Route114/scripts.pory"
waitmovement 0
# 376 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_KaiIntro MSGBOX_AUTOCLOSE
# 377 "data/maps/Route114/scripts.pory"
setvar VAR_0x8008, LOCALID_CLAUDE
# 378 "data/maps/Route114/scripts.pory"
playse SE_PIN
# 379 "data/maps/Route114/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 380 "data/maps/Route114/scripts.pory"
waitmovement 0
# 381 "data/maps/Route114/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 382 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 383 "data/maps/Route114/scripts.pory"
waitmovement 0
# 384 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_ClaudeIntro MSGBOX_AUTOCLOSE
# 385 "data/maps/Route114/scripts.pory"
goto Route114_EventScript_KaiClaudeDoMultiBattle
# 386 "data/maps/Route114/scripts.pory"
releaseall
# 387 "data/maps/Route114/scripts.pory"
end
# 388 "data/maps/Route114/scripts.pory"

# 389 "data/maps/Route114/scripts.pory"
Route114_EventScript_KaiClaudeDoMultiBattle::
# 390 "data/maps/Route114/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 391 "data/maps/Route114/scripts.pory"
multi_2p_vs_2 TRAINER_KAI, Route114_Text_KaiDefeat, TRAINER_CLAUDE, Route114_Text_ClaudeDefeat, PARTNER_EMMIE
# 392 "data/maps/Route114/scripts.pory"
switch VAR_RESULT
# 393 "data/maps/Route114/scripts.pory"
case 1, Route114_EventScript_KaiClaudeVictory
# 394 "data/maps/Route114/scripts.pory"
fadescreen FADE_TO_BLACK
# 395 "data/maps/Route114/scripts.pory"
special SetCB2WhiteOut
# 396 "data/maps/Route114/scripts.pory"
waitstate
# 397 "data/maps/Route114/scripts.pory"

# 398 "data/maps/Route114/scripts.pory"
Route114_EventScript_KaiClaudeVictory::
# 399 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 400 "data/maps/Route114/scripts.pory"
waitmovement 0
# 401 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_KaiPostBattle, MSGBOX_AUTOCLOSE
# 402 "data/maps/Route114/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 403 "data/maps/Route114/scripts.pory"
waitmovement 0
# 404 "data/maps/Route114/scripts.pory"
msgbox Route114_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
# 405 "data/maps/Route114/scripts.pory"
addvar VAR_ROUTE114_STATE, 1
# 406 "data/maps/Route114/scripts.pory"
end
# 407 "data/maps/Route114/scripts.pory"

# 408 "data/maps/Route114/scripts.pory"
Route114_EventScript_Kai::
# 409 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_KaiPostBattle, MSGBOX_AUTOCLOSE
# 410 "data/maps/Route114/scripts.pory"
	end
# 411 "data/maps/Route114/scripts.pory"

# 412 "data/maps/Route114/scripts.pory"
Route114_Text_AllMyMonDoesIsRoarTakeThis:
# 413 "data/maps/Route114/scripts.pory"
	.string "All my POKéMON does is ROAR…\n"
# 414 "data/maps/Route114/scripts.pory"
	.string "No one dares to come near me…\p"
# 415 "data/maps/Route114/scripts.pory"
	.string "Sigh… If you would, please take\n"
# 416 "data/maps/Route114/scripts.pory"
	.string "this TM away…$"
# 417 "data/maps/Route114/scripts.pory"

# 418 "data/maps/Route114/scripts.pory"
Route114_Text_ExplainRoar:
# 419 "data/maps/Route114/scripts.pory"
	.string "TM05 contains ROAR.\n"
# 420 "data/maps/Route114/scripts.pory"
	.string "A ROAR sends POKéMON scurrying.$"
# 421 "data/maps/Route114/scripts.pory"

# 422 "data/maps/Route114/scripts.pory"
Route114_Text_Poochyena:
# 423 "data/maps/Route114/scripts.pory"
	.string "Bow! Bowwow!$"
# 424 "data/maps/Route114/scripts.pory"

# 425 "data/maps/Route114/scripts.pory"
Route114_Text_MeteorFallsSign:
# 426 "data/maps/Route114/scripts.pory"
	.string "METEOR FALLS\n"
# 427 "data/maps/Route114/scripts.pory"
	.string "RUSTBORO CITY THROUGH HERE$"
# 428 "data/maps/Route114/scripts.pory"

# 429 "data/maps/Route114/scripts.pory"
Route114_Text_FossilManiacsHouseSign:
# 430 "data/maps/Route114/scripts.pory"
	.string "FOSSIL MANIAC'S HOUSE\n"
# 431 "data/maps/Route114/scripts.pory"
	.string "“Fossils gratefully accepted!”$"
# 432 "data/maps/Route114/scripts.pory"

# 433 "data/maps/Route114/scripts.pory"
Route114_Text_LanettesHouse:
# 434 "data/maps/Route114/scripts.pory"
	.string "LANETTE'S HOUSE$"
