# 1 "data/maps/Route115/scripts.pory"

# 2 "data/maps/Route115/scripts.pory"
.set LOCALID_ALIX, 20
# 3 "data/maps/Route115/scripts.pory"
.set LOCALID_NOB, 3
# 4 "data/maps/Route115/scripts.pory"
.set LOCALID_HECTOR, 9
# 5 "data/maps/Route115/scripts.pory"
.set LOCALID_MARLENE, 21
# 6 "data/maps/Route115/scripts.pory"
.set LOCALID_CYNDY, 7
# 7 "data/maps/Route115/scripts.pory"
.set LOCALID_HELENE, 19
# 8 "data/maps/Route115/scripts.pory"
.set LOCALID_JAIDEN, 18
# 9 "data/maps/Route115/scripts.pory"
.set LOCALID_KYRA, 17
# 10 "data/maps/Route115/scripts.pory"
.set LOCALID_KOICHI, 8
# 11 "data/maps/Route115/scripts.pory"
.set LOCALID_TIMOTHY, 2
# 12 "data/maps/Route115/scripts.pory"

# 13 "data/maps/Route115/scripts.pory"
Route115_MapScripts::
# 14 "data/maps/Route115/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
# 15 "data/maps/Route115/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
# 16 "data/maps/Route115/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
# 17 "data/maps/Route115/scripts.pory"
	.byte 0
# 18 "data/maps/Route115/scripts.pory"

# 19 "data/maps/Route115/scripts.pory"
Route115_OnLoad:
# 20 "data/maps/Route115/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_EventScript_PlaceTilesRoute115West
# 21 "data/maps/Route115/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_EventScript_PlaceTilesRoute115East
# 22 "data/maps/Route115/scripts.pory"
	end
# 23 "data/maps/Route115/scripts.pory"

# 24 "data/maps/Route115/scripts.pory"
Route115_OnTransition:
# 25 "data/maps/Route115/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 26 "data/maps/Route115/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_StartGroudonWeather
# 27 "data/maps/Route115/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_StartGroudonWeather
# 28 "data/maps/Route115/scripts.pory"
	end
# 29 "data/maps/Route115/scripts.pory"

# 30 "data/maps/Route115/scripts.pory"
Route115_OnFrame:
# 31 "data/maps/Route115/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 32 "data/maps/Route115/scripts.pory"
	.2byte 0
# 33 "data/maps/Route115/scripts.pory"

# 34 "data/maps/Route115/scripts.pory"
Route115_EventScript_Woman::
# 35 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
# 36 "data/maps/Route115/scripts.pory"
	end
# 37 "data/maps/Route115/scripts.pory"

# 38 "data/maps/Route115/scripts.pory"
Route115_EventScript_RouteSignRustboro::
# 39 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
# 40 "data/maps/Route115/scripts.pory"
	end
# 41 "data/maps/Route115/scripts.pory"

# 42 "data/maps/Route115/scripts.pory"
Route115_EventScript_MeteorFallsSign::
# 43 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
# 44 "data/maps/Route115/scripts.pory"
	end
# 45 "data/maps/Route115/scripts.pory"

# 46 "data/maps/Route115/scripts.pory"
Route115_EventScript_Timothy::
# 47 "data/maps/Route115/scripts.pory"
	trainerbattle_single TRAINER_TIMOTHY_1, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat, Route115_EventScript_RegisterTimothy
# 48 "data/maps/Route115/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 49 "data/maps/Route115/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchTimothy
# 50 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
# 51 "data/maps/Route115/scripts.pory"
	release
# 52 "data/maps/Route115/scripts.pory"
	end
# 53 "data/maps/Route115/scripts.pory"

# 54 "data/maps/Route115/scripts.pory"
Route115_EventScript_RegisterTimothy::
# 55 "data/maps/Route115/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 56 "data/maps/Route115/scripts.pory"
	waitmovement 0
# 57 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_TimothyRegister, MSGBOX_DEFAULT
# 58 "data/maps/Route115/scripts.pory"
	register_matchcall TRAINER_TIMOTHY_1
# 59 "data/maps/Route115/scripts.pory"
	release
# 60 "data/maps/Route115/scripts.pory"
	end
# 61 "data/maps/Route115/scripts.pory"

# 62 "data/maps/Route115/scripts.pory"
Route115_EventScript_RematchTimothy::
# 63 "data/maps/Route115/scripts.pory"
	trainerbattle_rematch TRAINER_TIMOTHY_1, Route115_Text_TimothyRematchIntro, Route115_Text_TimothyRematchDefeat
# 64 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_TimothyPostRematch, MSGBOX_AUTOCLOSE
# 65 "data/maps/Route115/scripts.pory"
	end
# 66 "data/maps/Route115/scripts.pory"

# 67 "data/maps/Route115/scripts.pory"
Route115_EventScript_Koichi::
# 68 "data/maps/Route115/scripts.pory"
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat
# 69 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
# 70 "data/maps/Route115/scripts.pory"
	end
# 71 "data/maps/Route115/scripts.pory"

# 72 "data/maps/Route115/scripts.pory"
Route115_EventScript_Nob::
# 73 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
# 74 "data/maps/Route115/scripts.pory"
	release
# 75 "data/maps/Route115/scripts.pory"
	end
# 76 "data/maps/Route115/scripts.pory"

# 77 "data/maps/Route115/scripts.pory"
Route115_EventScript_RegisterNob::
# 78 "data/maps/Route115/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 79 "data/maps/Route115/scripts.pory"
	waitmovement 0
# 80 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_NobRegister, MSGBOX_DEFAULT
# 81 "data/maps/Route115/scripts.pory"
	register_matchcall TRAINER_NOB_1
# 82 "data/maps/Route115/scripts.pory"
	release
# 83 "data/maps/Route115/scripts.pory"
	end
# 84 "data/maps/Route115/scripts.pory"

# 85 "data/maps/Route115/scripts.pory"
Route115_EventScript_RematchNob::
# 86 "data/maps/Route115/scripts.pory"
	trainerbattle_rematch TRAINER_NOB_1, Route115_Text_NobRematchIntro, Route115_Text_NobRematchDefeat
# 87 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_NobPostRematch, MSGBOX_AUTOCLOSE
# 88 "data/maps/Route115/scripts.pory"
	end
# 89 "data/maps/Route115/scripts.pory"

# 90 "data/maps/Route115/scripts.pory"
Route115_EventScript_Cyndy::
# 91 "data/maps/Route115/scripts.pory"
	trainerbattle_single TRAINER_CYNDY_1, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat, Route115_EventScript_RegisterCyndy
# 92 "data/maps/Route115/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 93 "data/maps/Route115/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchCyndy
# 94 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
# 95 "data/maps/Route115/scripts.pory"
	release
# 96 "data/maps/Route115/scripts.pory"
	end
# 97 "data/maps/Route115/scripts.pory"

# 98 "data/maps/Route115/scripts.pory"
Route115_EventScript_RegisterCyndy::
# 99 "data/maps/Route115/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 100 "data/maps/Route115/scripts.pory"
	waitmovement 0
# 101 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_CyndyRegister, MSGBOX_DEFAULT
# 102 "data/maps/Route115/scripts.pory"
	register_matchcall TRAINER_CYNDY_1
# 103 "data/maps/Route115/scripts.pory"
	release
# 104 "data/maps/Route115/scripts.pory"
	end
# 105 "data/maps/Route115/scripts.pory"

# 106 "data/maps/Route115/scripts.pory"
Route115_EventScript_RematchCyndy::
# 107 "data/maps/Route115/scripts.pory"
	trainerbattle_rematch TRAINER_CYNDY_1, Route115_Text_CyndyRematchIntro, Route115_Text_CyndyRematchDefeat
# 108 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_CyndyPostRematch, MSGBOX_AUTOCLOSE
# 109 "data/maps/Route115/scripts.pory"
	end
# 110 "data/maps/Route115/scripts.pory"

# 111 "data/maps/Route115/scripts.pory"
Route115_EventScript_HectorMarlene::
# 112 "data/maps/Route115/scripts.pory"
lockall
# 113 "data/maps/Route115/scripts.pory"
setvar VAR_0x8008, LOCALID_HECTOR
# 114 "data/maps/Route115/scripts.pory"
playse SE_PIN
# 115 "data/maps/Route115/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 116 "data/maps/Route115/scripts.pory"
waitmovement 0
# 117 "data/maps/Route115/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 118 "data/maps/Route115/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 119 "data/maps/Route115/scripts.pory"
waitmovement 0
# 120 "data/maps/Route115/scripts.pory"
msgbox Route115_Text_HectorIntro MSGBOX_AUTOCLOSE
# 121 "data/maps/Route115/scripts.pory"
setvar VAR_0x8008, LOCALID_MARLENE
# 122 "data/maps/Route115/scripts.pory"
playse SE_PIN
# 123 "data/maps/Route115/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 124 "data/maps/Route115/scripts.pory"
waitmovement 0
# 125 "data/maps/Route115/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 126 "data/maps/Route115/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 127 "data/maps/Route115/scripts.pory"
waitmovement 0
# 128 "data/maps/Route115/scripts.pory"
msgbox Route115_Text_MarleneIntro MSGBOX_AUTOCLOSE
# 129 "data/maps/Route115/scripts.pory"
goto Route115_EventScript_HectorMarleneDoMultiBattle
# 130 "data/maps/Route115/scripts.pory"
releaseall
# 131 "data/maps/Route115/scripts.pory"
end
# 132 "data/maps/Route115/scripts.pory"

# 133 "data/maps/Route115/scripts.pory"
Route115_EventScript_HectorMarleneDoMultiBattle::
# 134 "data/maps/Route115/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 135 "data/maps/Route115/scripts.pory"
multi_2p_vs_2 TRAINER_HECTOR, Route115_Text_HectorDefeat, TRAINER_MARLENE, Route115_Text_MarleneDefeat, PARTNER_EMMIE
# 136 "data/maps/Route115/scripts.pory"
switch VAR_RESULT
# 137 "data/maps/Route115/scripts.pory"
case 1, Route115_EventScript_HectorMarleneVictory
# 138 "data/maps/Route115/scripts.pory"
fadescreen FADE_TO_BLACK
# 139 "data/maps/Route115/scripts.pory"
special SetCB2WhiteOut
# 140 "data/maps/Route115/scripts.pory"
waitstate
# 141 "data/maps/Route115/scripts.pory"

# 142 "data/maps/Route115/scripts.pory"
Route115_EventScript_HectorMarleneVictory::
# 143 "data/maps/Route115/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 144 "data/maps/Route115/scripts.pory"
waitmovement 0
# 145 "data/maps/Route115/scripts.pory"
msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
# 146 "data/maps/Route115/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 147 "data/maps/Route115/scripts.pory"
waitmovement 0
# 148 "data/maps/Route115/scripts.pory"
msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
# 149 "data/maps/Route115/scripts.pory"
addvar VAR_ROUTE115_STATE, 1
# 150 "data/maps/Route115/scripts.pory"
end
# 151 "data/maps/Route115/scripts.pory"

# 152 "data/maps/Route115/scripts.pory"
Route115_EventScript_Hector::
# 153 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
# 154 "data/maps/Route115/scripts.pory"
	end
# 155 "data/maps/Route115/scripts.pory"

# 156 "data/maps/Route115/scripts.pory"
Route115_EventScript_Kyra::
# 157 "data/maps/Route115/scripts.pory"
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat
# 158 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
# 159 "data/maps/Route115/scripts.pory"
	end
# 160 "data/maps/Route115/scripts.pory"

# 161 "data/maps/Route115/scripts.pory"
Route115_EventScript_Jaiden::
# 162 "data/maps/Route115/scripts.pory"
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat
# 163 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
# 164 "data/maps/Route115/scripts.pory"
	end
# 165 "data/maps/Route115/scripts.pory"

# 166 "data/maps/Route115/scripts.pory"
Route115_EventScript_AlixNob::
# 167 "data/maps/Route115/scripts.pory"
lockall
# 168 "data/maps/Route115/scripts.pory"
setvar VAR_0x8008, LOCALID_ALIX
# 169 "data/maps/Route115/scripts.pory"
playse SE_PIN
# 170 "data/maps/Route115/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 171 "data/maps/Route115/scripts.pory"
waitmovement 0
# 172 "data/maps/Route115/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 173 "data/maps/Route115/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 174 "data/maps/Route115/scripts.pory"
waitmovement 0
# 175 "data/maps/Route115/scripts.pory"
msgbox Route115_Text_AlixIntro MSGBOX_AUTOCLOSE
# 176 "data/maps/Route115/scripts.pory"
setvar VAR_0x8008, LOCALID_NOB
# 177 "data/maps/Route115/scripts.pory"
playse SE_PIN
# 178 "data/maps/Route115/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 179 "data/maps/Route115/scripts.pory"
waitmovement 0
# 180 "data/maps/Route115/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 181 "data/maps/Route115/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 182 "data/maps/Route115/scripts.pory"
waitmovement 0
# 183 "data/maps/Route115/scripts.pory"
msgbox Route115_Text_NobIntro MSGBOX_AUTOCLOSE
# 184 "data/maps/Route115/scripts.pory"
goto Route115_EventScript_AlixNobDoMultiBattle
# 185 "data/maps/Route115/scripts.pory"
releaseall
# 186 "data/maps/Route115/scripts.pory"
end
# 187 "data/maps/Route115/scripts.pory"

# 188 "data/maps/Route115/scripts.pory"
Route115_EventScript_AlixNobDoMultiBattle::
# 189 "data/maps/Route115/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 190 "data/maps/Route115/scripts.pory"
multi_2p_vs_2 TRAINER_ALIX, Route115_Text_AlixDefeat, TRAINER_NOB_1, Route115_Text_NobDefeat, PARTNER_EMMIE
# 191 "data/maps/Route115/scripts.pory"
switch VAR_RESULT
# 192 "data/maps/Route115/scripts.pory"
case 1, Route115_EventScript_AlixNobVictory
# 193 "data/maps/Route115/scripts.pory"
fadescreen FADE_TO_BLACK
# 194 "data/maps/Route115/scripts.pory"
special SetCB2WhiteOut
# 195 "data/maps/Route115/scripts.pory"
waitstate
# 196 "data/maps/Route115/scripts.pory"

# 197 "data/maps/Route115/scripts.pory"
Route115_EventScript_AlixNobVictory::
# 198 "data/maps/Route115/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 199 "data/maps/Route115/scripts.pory"
waitmovement 0
# 200 "data/maps/Route115/scripts.pory"
msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
# 201 "data/maps/Route115/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 202 "data/maps/Route115/scripts.pory"
waitmovement 0
# 203 "data/maps/Route115/scripts.pory"
msgbox Route115_Text_NobPostBattle, MSGBOX_AUTOCLOSE
# 204 "data/maps/Route115/scripts.pory"
addvar VAR_ROUTE115_STATE, 1
# 205 "data/maps/Route115/scripts.pory"
end
# 206 "data/maps/Route115/scripts.pory"

# 207 "data/maps/Route115/scripts.pory"
Route115_EventScript_Alix::
# 208 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
# 209 "data/maps/Route115/scripts.pory"
	end
# 210 "data/maps/Route115/scripts.pory"

# 211 "data/maps/Route115/scripts.pory"
Route115_EventScript_Helene::
# 212 "data/maps/Route115/scripts.pory"
	trainerbattle_single TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat
# 213 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_HelenePostBattle, MSGBOX_AUTOCLOSE
# 214 "data/maps/Route115/scripts.pory"
	end
# 215 "data/maps/Route115/scripts.pory"

# 216 "data/maps/Route115/scripts.pory"
Route115_EventScript_Marlene::
# 217 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
# 218 "data/maps/Route115/scripts.pory"
	end
# 219 "data/maps/Route115/scripts.pory"

# 220 "data/maps/Route115/scripts.pory"
Route115_Text_NeverKnowWhenCavePokemonWillAppear:
# 221 "data/maps/Route115/scripts.pory"
	.string "Exploring a cave isn't like walking\n"
# 222 "data/maps/Route115/scripts.pory"
	.string "on a road.\p"
# 223 "data/maps/Route115/scripts.pory"
	.string "You never know when wild POKéMON will\n"
# 224 "data/maps/Route115/scripts.pory"
	.string "appear. It's full of suspense.$"
# 225 "data/maps/Route115/scripts.pory"

# 226 "data/maps/Route115/scripts.pory"
Route115_Text_RouteSignRustboro:
# 227 "data/maps/Route115/scripts.pory"
	.string "ROUTE 115\n"
# 228 "data/maps/Route115/scripts.pory"
	.string "{DOWN_ARROW} RUSTBORO CITY$"
# 229 "data/maps/Route115/scripts.pory"

# 230 "data/maps/Route115/scripts.pory"
Route115_Text_MeteorFallsSign:
# 231 "data/maps/Route115/scripts.pory"
	.string "METEOR FALLS\n"
# 232 "data/maps/Route115/scripts.pory"
	.string "FALLARBOR TOWN THROUGH HERE$"
