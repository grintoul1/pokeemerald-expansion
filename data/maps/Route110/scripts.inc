# 1 "data/maps/Route110/scripts.pory"

# 2 "data/maps/Route110/scripts.pory"
.set LOCALID_CHALLENGE_BIKER, 21
# 3 "data/maps/Route110/scripts.pory"
.set LOCALID_BIRCH, 36
# 4 "data/maps/Route110/scripts.pory"
.set LOCALID_ISABEL, 28
# 5 "data/maps/Route110/scripts.pory"
.set LOCALID_KALEB, 29
# 6 "data/maps/Route110/scripts.pory"
.set LOCALID_JOSEPH, 31
# 7 "data/maps/Route110/scripts.pory"
.set LOCALID_EDWIN, 14
# 8 "data/maps/Route110/scripts.pory"
.set LOCALID_TIMMY, 27
# 9 "data/maps/Route110/scripts.pory"
.set LOCALID_EDWARD, 12
# 10 "data/maps/Route110/scripts.pory"
.set LOCALID_ANTHONY, 9
# 11 "data/maps/Route110/scripts.pory"
.set LOCALID_ABIGAIL, 10
# 12 "data/maps/Route110/scripts.pory"
.set LOCALID_ALYSSA, 30
# 13 "data/maps/Route110/scripts.pory"
.set LOCALID_BENJAMIN, 11
# 14 "data/maps/Route110/scripts.pory"
.set LOCALID_JASMINE, 8
# 15 "data/maps/Route110/scripts.pory"
.set LOCALID_JACOB, 26
# 16 "data/maps/Route110/scripts.pory"

# 17 "data/maps/Route110/scripts.pory"

# 18 "data/maps/Route110/scripts.pory"
Route110_MapScripts::
# 19 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
# 20 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
# 21 "data/maps/Route110/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
# 22 "data/maps/Route110/scripts.pory"
	.byte 0
# 23 "data/maps/Route110/scripts.pory"

# 24 "data/maps/Route110/scripts.pory"
Route110_OnResume:
# 25 "data/maps/Route110/scripts.pory"
	special UpdateCyclingRoadState
# 26 "data/maps/Route110/scripts.pory"
	end
# 27 "data/maps/Route110/scripts.pory"

# 28 "data/maps/Route110/scripts.pory"
Route110_OnTransition:
# 29 "data/maps/Route110/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 30 "data/maps/Route110/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 31 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
# 32 "data/maps/Route110/scripts.pory"
	end
# 33 "data/maps/Route110/scripts.pory"

# 34 "data/maps/Route110/scripts.pory"
Route110_EventScript_SaveCyclingMusic::
# 35 "data/maps/Route110/scripts.pory"
	savebgm MUS_CYCLING
# 36 "data/maps/Route110/scripts.pory"
	return
# 37 "data/maps/Route110/scripts.pory"

# 38 "data/maps/Route110/scripts.pory"
Route110_OnFrame:
# 39 "data/maps/Route110/scripts.pory"
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
# 40 "data/maps/Route110/scripts.pory"
	.2byte 0
# 41 "data/maps/Route110/scripts.pory"

# 42 "data/maps/Route110/scripts.pory"
Route110_EventScript_BeginCylcingRoadChallenge::
# 43 "data/maps/Route110/scripts.pory"
	special Special_BeginCyclingRoadChallenge
# 44 "data/maps/Route110/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
# 45 "data/maps/Route110/scripts.pory"
	return
# 46 "data/maps/Route110/scripts.pory"

# 47 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt1::
# 48 "data/maps/Route110/scripts.pory"
	lock
# 49 "data/maps/Route110/scripts.pory"
	faceplayer
# 50 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
# 51 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 52 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 53 "data/maps/Route110/scripts.pory"
	release
# 54 "data/maps/Route110/scripts.pory"
	end
# 55 "data/maps/Route110/scripts.pory"

# 56 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt2::
# 57 "data/maps/Route110/scripts.pory"
	lock
# 58 "data/maps/Route110/scripts.pory"
	faceplayer
# 59 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
# 60 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 61 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 62 "data/maps/Route110/scripts.pory"
	release
# 63 "data/maps/Route110/scripts.pory"
	end
# 64 "data/maps/Route110/scripts.pory"

# 65 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt3::
# 66 "data/maps/Route110/scripts.pory"
	lock
# 67 "data/maps/Route110/scripts.pory"
	faceplayer
# 68 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
# 69 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 70 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 71 "data/maps/Route110/scripts.pory"
	release
# 72 "data/maps/Route110/scripts.pory"
	end
# 73 "data/maps/Route110/scripts.pory"

# 74 "data/maps/Route110/scripts.pory"
Route110_EventScript_AquaGrunt4::
# 75 "data/maps/Route110/scripts.pory"
	lock
# 76 "data/maps/Route110/scripts.pory"
	faceplayer
# 77 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
# 78 "data/maps/Route110/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 79 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 80 "data/maps/Route110/scripts.pory"
	release
# 81 "data/maps/Route110/scripts.pory"
	end
# 82 "data/maps/Route110/scripts.pory"

# 83 "data/maps/Route110/scripts.pory"
Route110_EventScript_Boy1::
# 84 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
# 85 "data/maps/Route110/scripts.pory"
	end
# 86 "data/maps/Route110/scripts.pory"

# 87 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGirl1::
# 88 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
# 89 "data/maps/Route110/scripts.pory"
	end
# 90 "data/maps/Route110/scripts.pory"

# 91 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGuy1::
# 92 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
# 93 "data/maps/Route110/scripts.pory"
	end
# 94 "data/maps/Route110/scripts.pory"

# 95 "data/maps/Route110/scripts.pory"
Route110_EventScript_OldMan::
# 96 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
# 97 "data/maps/Route110/scripts.pory"
	end
# 98 "data/maps/Route110/scripts.pory"

# 99 "data/maps/Route110/scripts.pory"
Route110_EventScript_OldWoman::
# 100 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
# 101 "data/maps/Route110/scripts.pory"
	end
# 102 "data/maps/Route110/scripts.pory"

# 103 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingGuy2::
# 104 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
# 105 "data/maps/Route110/scripts.pory"
	end
# 106 "data/maps/Route110/scripts.pory"

# 107 "data/maps/Route110/scripts.pory"
Route110_EventScript_Boy2::
# 108 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
# 109 "data/maps/Route110/scripts.pory"
	end
# 110 "data/maps/Route110/scripts.pory"

# 111 "data/maps/Route110/scripts.pory"
Route110_EventScript_SlateportCitySign::
# 112 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
# 113 "data/maps/Route110/scripts.pory"
	end
# 114 "data/maps/Route110/scripts.pory"

# 115 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingRoadSign::
# 116 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
# 117 "data/maps/Route110/scripts.pory"
	end
# 118 "data/maps/Route110/scripts.pory"

# 119 "data/maps/Route110/scripts.pory"
Route110_EventScript_VandalizedSign::
# 120 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
# 121 "data/maps/Route110/scripts.pory"
	end
# 122 "data/maps/Route110/scripts.pory"

# 123 "data/maps/Route110/scripts.pory"
Route110_EventScript_Route103Sign::
# 124 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
# 125 "data/maps/Route110/scripts.pory"
	end
# 126 "data/maps/Route110/scripts.pory"

# 127 "data/maps/Route110/scripts.pory"
Route110_EventScript_SeasideParkingSign::
# 128 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
# 129 "data/maps/Route110/scripts.pory"
	end
# 130 "data/maps/Route110/scripts.pory"

# 131 "data/maps/Route110/scripts.pory"
Route110_EventScript_MauvilleCitySign::
# 132 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
# 133 "data/maps/Route110/scripts.pory"
	end
# 134 "data/maps/Route110/scripts.pory"

# 135 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrainerTipsPrlzSleep::
# 136 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
# 137 "data/maps/Route110/scripts.pory"
	end
# 138 "data/maps/Route110/scripts.pory"

# 139 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrainerTipsRegisterItems::
# 140 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
# 141 "data/maps/Route110/scripts.pory"
	end
# 142 "data/maps/Route110/scripts.pory"

# 143 "data/maps/Route110/scripts.pory"
Route110_EventScript_TrickHouseSign::
# 144 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
# 145 "data/maps/Route110/scripts.pory"
	end
# 146 "data/maps/Route110/scripts.pory"

# 147 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingRoadResultsSign::
# 148 "data/maps/Route110/scripts.pory"
	lockall
# 149 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
# 150 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
# 151 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
# 152 "data/maps/Route110/scripts.pory"
	releaseall
# 153 "data/maps/Route110/scripts.pory"
	end
# 154 "data/maps/Route110/scripts.pory"

# 155 "data/maps/Route110/scripts.pory"
Route110_EventScript_NoRecordSet::
# 156 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
# 157 "data/maps/Route110/scripts.pory"
	releaseall
# 158 "data/maps/Route110/scripts.pory"
	end
# 159 "data/maps/Route110/scripts.pory"

# 160 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeGuy::
# 161 "data/maps/Route110/scripts.pory"
	lock
# 162 "data/maps/Route110/scripts.pory"
	faceplayer
# 163 "data/maps/Route110/scripts.pory"
	specialvar VAR_RESULT, GetPlayerAvatarBike
# 164 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
# 165 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
# 166 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
# 167 "data/maps/Route110/scripts.pory"
	release
# 168 "data/maps/Route110/scripts.pory"
	end
# 169 "data/maps/Route110/scripts.pory"

# 170 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayerNotRidingBike::
# 171 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
# 172 "data/maps/Route110/scripts.pory"
	release
# 173 "data/maps/Route110/scripts.pory"
	end
# 174 "data/maps/Route110/scripts.pory"

# 175 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayerRidingAcroBike::
# 176 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
# 177 "data/maps/Route110/scripts.pory"
	release
# 178 "data/maps/Route110/scripts.pory"
	end
# 179 "data/maps/Route110/scripts.pory"

# 180 "data/maps/Route110/scripts.pory"
Route110_EventScript_TimmyEdward::
# 181 "data/maps/Route110/scripts.pory"
	lockall
# 182 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, LOCALID_TIMMY
# 183 "data/maps/Route110/scripts.pory"
	playse SE_PIN
# 184 "data/maps/Route110/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 185 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 186 "data/maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_MALE, TRUE
# 187 "data/maps/Route110/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 188 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 189 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TimmyIntro MSGBOX_AUTOCLOSE
# 190 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, LOCALID_EDWARD
# 191 "data/maps/Route110/scripts.pory"
	playse SE_PIN
# 192 "data/maps/Route110/scripts.pory"
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 193 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 194 "data/maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 195 "data/maps/Route110/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 196 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 197 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwardIntro MSGBOX_AUTOCLOSE
# 198 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_TimmyEdwardDoMultiBattle
# 199 "data/maps/Route110/scripts.pory"
	releaseall
# 200 "data/maps/Route110/scripts.pory"
	end
# 201 "data/maps/Route110/scripts.pory"

# 202 "data/maps/Route110/scripts.pory"
Route110_EventScript_TimmyEdwardDoMultiBattle::
# 203 "data/maps/Route110/scripts.pory"
	playbgm MUS_ROUTE110, TRUE
# 204 "data/maps/Route110/scripts.pory"
	multi_2p_vs_2 TRAINER_TIMMY, Route110_Text_TimmyDefeated, TRAINER_EDWARD, Route110_Text_EdwardDefeated, PARTNER_EMMIE
# 205 "data/maps/Route110/scripts.pory"
	switch VAR_RESULT
# 206 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_TimmyEdwardVictory
# 207 "data/maps/Route110/scripts.pory"
	fadescreen FADE_TO_BLACK
# 208 "data/maps/Route110/scripts.pory"
	special SetCB2WhiteOut
# 209 "data/maps/Route110/scripts.pory"
	waitstate
# 210 "data/maps/Route110/scripts.pory"

# 211 "data/maps/Route110/scripts.pory"
Route110_EventScript_TimmyEdwardVictory::
# 212 "data/maps/Route110/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 213 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 214 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
# 215 "data/maps/Route110/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 216 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 217 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
# 218 "data/maps/Route110/scripts.pory"
	addvar VAR_ROUTE110_STATE, 1
# 219 "data/maps/Route110/scripts.pory"
	end
# 220 "data/maps/Route110/scripts.pory"

# 221 "data/maps/Route110/scripts.pory"
Route110_EventScript_Edward::
# 222 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
# 223 "data/maps/Route110/scripts.pory"
	end
# 224 "data/maps/Route110/scripts.pory"

# 225 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jaclyn::
# 226 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
# 227 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
# 228 "data/maps/Route110/scripts.pory"
	end
# 229 "data/maps/Route110/scripts.pory"

# 230 "data/maps/Route110/scripts.pory"
Route110_EventScript_Edwin::
# 231 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
# 232 "data/maps/Route110/scripts.pory"
	release
# 233 "data/maps/Route110/scripts.pory"
	end
# 234 "data/maps/Route110/scripts.pory"

# 235 "data/maps/Route110/scripts.pory"
Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
# 236 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 237 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 238 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
# 239 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_EDWIN_1
# 240 "data/maps/Route110/scripts.pory"
	release
# 241 "data/maps/Route110/scripts.pory"
	end
# 242 "data/maps/Route110/scripts.pory"

# 243 "data/maps/Route110/scripts.pory"
Route110_EventScript_EdwinRematch::
# 244 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
# 245 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
# 246 "data/maps/Route110/scripts.pory"
	end
# 247 "data/maps/Route110/scripts.pory"

# 248 "data/maps/Route110/scripts.pory"
Route110_EventScript_Dale::
# 249 "data/maps/Route110/scripts.pory"
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
# 250 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
# 251 "data/maps/Route110/scripts.pory"
	end
# 252 "data/maps/Route110/scripts.pory"

# 253 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jacob::
# 254 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
# 255 "data/maps/Route110/scripts.pory"
	end
# 256 "data/maps/Route110/scripts.pory"

# 257 "data/maps/Route110/scripts.pory"
Route110_EventScript_AnthonyAbigail::
# 258 "data/maps/Route110/scripts.pory"
lockall
# 259 "data/maps/Route110/scripts.pory"
setvar VAR_0x8008, LOCALID_ANTHONY
# 260 "data/maps/Route110/scripts.pory"
playse SE_PIN
# 261 "data/maps/Route110/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 262 "data/maps/Route110/scripts.pory"
waitmovement 0
# 263 "data/maps/Route110/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 264 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 265 "data/maps/Route110/scripts.pory"
waitmovement 0
# 266 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_AnthonyIntro MSGBOX_AUTOCLOSE
# 267 "data/maps/Route110/scripts.pory"
setvar VAR_0x8008, LOCALID_ABIGAIL
# 268 "data/maps/Route110/scripts.pory"
playse SE_PIN
# 269 "data/maps/Route110/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 270 "data/maps/Route110/scripts.pory"
waitmovement 0
# 271 "data/maps/Route110/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 272 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 273 "data/maps/Route110/scripts.pory"
waitmovement 0
# 274 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_AbigailIntro MSGBOX_AUTOCLOSE
# 275 "data/maps/Route110/scripts.pory"
goto Route110_EventScript_AnthonyAbigailDoMultiBattle
# 276 "data/maps/Route110/scripts.pory"
releaseall
# 277 "data/maps/Route110/scripts.pory"
end
# 278 "data/maps/Route110/scripts.pory"

# 279 "data/maps/Route110/scripts.pory"
Route110_EventScript_AnthonyAbigailDoMultiBattle::
# 280 "data/maps/Route110/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 281 "data/maps/Route110/scripts.pory"
multi_2p_vs_2 TRAINER_ANTHONY, Route110_Text_AnthonyDefeated, TRAINER_ABIGAIL_1, Route110_Text_AbigailDefeated, PARTNER_EMMIE
# 282 "data/maps/Route110/scripts.pory"
switch VAR_RESULT
# 283 "data/maps/Route110/scripts.pory"
case 1, Route110_EventScript_AnthonyAbigailVictory
# 284 "data/maps/Route110/scripts.pory"
fadescreen FADE_TO_BLACK
# 285 "data/maps/Route110/scripts.pory"
special SetCB2WhiteOut
# 286 "data/maps/Route110/scripts.pory"
waitstate
# 287 "data/maps/Route110/scripts.pory"

# 288 "data/maps/Route110/scripts.pory"
Route110_EventScript_AnthonyAbigailVictory::
# 289 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 290 "data/maps/Route110/scripts.pory"
waitmovement 0
# 291 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
# 292 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 293 "data/maps/Route110/scripts.pory"
waitmovement 0
# 294 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_AbigailPostBattle, MSGBOX_AUTOCLOSE
# 295 "data/maps/Route110/scripts.pory"
addvar VAR_ROUTE110_STATE, 1
# 296 "data/maps/Route110/scripts.pory"
end
# 297 "data/maps/Route110/scripts.pory"

# 298 "data/maps/Route110/scripts.pory"
Route110_EventScript_Anthony::
# 299 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
# 300 "data/maps/Route110/scripts.pory"
	end
# 301 "data/maps/Route110/scripts.pory"

# 302 "data/maps/Route110/scripts.pory"
Route110_EventScript_Benjamin::
# 303 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
# 304 "data/maps/Route110/scripts.pory"
	release
# 305 "data/maps/Route110/scripts.pory"
	end
# 306 "data/maps/Route110/scripts.pory"

# 307 "data/maps/Route110/scripts.pory"
Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
# 308 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 309 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 310 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
# 311 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_BENJAMIN_1
# 312 "data/maps/Route110/scripts.pory"
	release
# 313 "data/maps/Route110/scripts.pory"
	end
# 314 "data/maps/Route110/scripts.pory"

# 315 "data/maps/Route110/scripts.pory"
Route110_EventScript_BenjaminRematch::
# 316 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
# 317 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
# 318 "data/maps/Route110/scripts.pory"
	end
# 319 "data/maps/Route110/scripts.pory"

# 320 "data/maps/Route110/scripts.pory"
Route110_EventScript_JasmineJacob::
# 321 "data/maps/Route110/scripts.pory"
lockall
# 322 "data/maps/Route110/scripts.pory"
setvar VAR_0x8008, LOCALID_JASMINE
# 323 "data/maps/Route110/scripts.pory"
playse SE_PIN
# 324 "data/maps/Route110/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 325 "data/maps/Route110/scripts.pory"
waitmovement 0
# 326 "data/maps/Route110/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 327 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 328 "data/maps/Route110/scripts.pory"
waitmovement 0
# 329 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_JasmineIntro MSGBOX_AUTOCLOSE
# 330 "data/maps/Route110/scripts.pory"
setvar VAR_0x8008, LOCALID_JACOB
# 331 "data/maps/Route110/scripts.pory"
playse SE_PIN
# 332 "data/maps/Route110/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 333 "data/maps/Route110/scripts.pory"
waitmovement 0
# 334 "data/maps/Route110/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 335 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 336 "data/maps/Route110/scripts.pory"
waitmovement 0
# 337 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_JacobIntro MSGBOX_AUTOCLOSE
# 338 "data/maps/Route110/scripts.pory"
goto Route110_EventScript_JasmineJacobDoMultiBattle
# 339 "data/maps/Route110/scripts.pory"
releaseall
# 340 "data/maps/Route110/scripts.pory"
end
# 341 "data/maps/Route110/scripts.pory"

# 342 "data/maps/Route110/scripts.pory"
Route110_EventScript_JasmineJacobDoMultiBattle::
# 343 "data/maps/Route110/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 344 "data/maps/Route110/scripts.pory"
multi_2p_vs_2 TRAINER_JASMINE, Route110_Text_JasmineDefeated, TRAINER_JACOB, Route110_Text_JacobDefeated, PARTNER_EMMIE
# 345 "data/maps/Route110/scripts.pory"
switch VAR_RESULT
# 346 "data/maps/Route110/scripts.pory"
case 1, Route110_EventScript_JasmineJacobVictory
# 347 "data/maps/Route110/scripts.pory"
fadescreen FADE_TO_BLACK
# 348 "data/maps/Route110/scripts.pory"
special SetCB2WhiteOut
# 349 "data/maps/Route110/scripts.pory"
waitstate
# 350 "data/maps/Route110/scripts.pory"

# 351 "data/maps/Route110/scripts.pory"
Route110_EventScript_JasmineJacobVictory::
# 352 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 353 "data/maps/Route110/scripts.pory"
waitmovement 0
# 354 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
# 355 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 356 "data/maps/Route110/scripts.pory"
waitmovement 0
# 357 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
# 358 "data/maps/Route110/scripts.pory"
addvar VAR_ROUTE110_STATE, 1
# 359 "data/maps/Route110/scripts.pory"
end
# 360 "data/maps/Route110/scripts.pory"

# 361 "data/maps/Route110/scripts.pory"
Route110_EventScript_Jasmine::
# 362 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
# 363 "data/maps/Route110/scripts.pory"
	end
# 364 "data/maps/Route110/scripts.pory"

# 365 "data/maps/Route110/scripts.pory"
Route110_EventScript_Abigail::
# 366 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
# 367 "data/maps/Route110/scripts.pory"
	release
# 368 "data/maps/Route110/scripts.pory"
	end
# 369 "data/maps/Route110/scripts.pory"

# 370 "data/maps/Route110/scripts.pory"
Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
# 371 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 372 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 373 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
# 374 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_ABIGAIL_1
# 375 "data/maps/Route110/scripts.pory"
	release
# 376 "data/maps/Route110/scripts.pory"
	end
# 377 "data/maps/Route110/scripts.pory"

# 378 "data/maps/Route110/scripts.pory"
Route110_EventScript_AbigailRematch::
# 379 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
# 380 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
# 381 "data/maps/Route110/scripts.pory"
	end
# 382 "data/maps/Route110/scripts.pory"

# 383 "data/maps/Route110/scripts.pory"
Route110_EventScript_IsabelKaleb::
# 384 "data/maps/Route110/scripts.pory"
lockall
# 385 "data/maps/Route110/scripts.pory"
setvar VAR_0x8008, LOCALID_ISABEL
# 386 "data/maps/Route110/scripts.pory"
playse SE_PIN
# 387 "data/maps/Route110/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 388 "data/maps/Route110/scripts.pory"
waitmovement 0
# 389 "data/maps/Route110/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 390 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 391 "data/maps/Route110/scripts.pory"
waitmovement 0
# 392 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_IsabelIntro MSGBOX_AUTOCLOSE
# 393 "data/maps/Route110/scripts.pory"
setvar VAR_0x8008, LOCALID_KALEB
# 394 "data/maps/Route110/scripts.pory"
playse SE_PIN
# 395 "data/maps/Route110/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 396 "data/maps/Route110/scripts.pory"
waitmovement 0
# 397 "data/maps/Route110/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 398 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 399 "data/maps/Route110/scripts.pory"
waitmovement 0
# 400 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_KalebIntro MSGBOX_AUTOCLOSE
# 401 "data/maps/Route110/scripts.pory"
goto Route110_EventScript_IsabelKalebDoMultiBattle
# 402 "data/maps/Route110/scripts.pory"
releaseall
# 403 "data/maps/Route110/scripts.pory"
end
# 404 "data/maps/Route110/scripts.pory"

# 405 "data/maps/Route110/scripts.pory"
Route110_EventScript_IsabelKalebDoMultiBattle::
# 406 "data/maps/Route110/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 407 "data/maps/Route110/scripts.pory"
multi_2p_vs_2 TRAINER_ISABEL_1, Route110_Text_IsabelDefeated, TRAINER_KALEB, Route110_Text_KalebDefeated, PARTNER_EMMIE
# 408 "data/maps/Route110/scripts.pory"
switch VAR_RESULT
# 409 "data/maps/Route110/scripts.pory"
case 1, Route110_EventScript_IsabelKalebVictory
# 410 "data/maps/Route110/scripts.pory"
fadescreen FADE_TO_BLACK
# 411 "data/maps/Route110/scripts.pory"
special SetCB2WhiteOut
# 412 "data/maps/Route110/scripts.pory"
waitstate
# 413 "data/maps/Route110/scripts.pory"

# 414 "data/maps/Route110/scripts.pory"
Route110_EventScript_IsabelKalebVictory::
# 415 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 416 "data/maps/Route110/scripts.pory"
waitmovement 0
# 417 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_IsabelPostBattle, MSGBOX_AUTOCLOSE
# 418 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 419 "data/maps/Route110/scripts.pory"
waitmovement 0
# 420 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
# 421 "data/maps/Route110/scripts.pory"
addvar VAR_ROUTE110_STATE, 1
# 422 "data/maps/Route110/scripts.pory"
end
# 423 "data/maps/Route110/scripts.pory"

# 424 "data/maps/Route110/scripts.pory"
Route110_EventScript_Isabel::
# 425 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
# 426 "data/maps/Route110/scripts.pory"
	release
# 427 "data/maps/Route110/scripts.pory"
	end
# 428 "data/maps/Route110/scripts.pory"

# 429 "data/maps/Route110/scripts.pory"
Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
# 430 "data/maps/Route110/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 431 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 432 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
# 433 "data/maps/Route110/scripts.pory"
	register_matchcall TRAINER_ISABEL_1
# 434 "data/maps/Route110/scripts.pory"
	release
# 435 "data/maps/Route110/scripts.pory"
	end
# 436 "data/maps/Route110/scripts.pory"

# 437 "data/maps/Route110/scripts.pory"
Route110_EventScript_IsabelRematch::
# 438 "data/maps/Route110/scripts.pory"
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
# 439 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
# 440 "data/maps/Route110/scripts.pory"
	end
# 441 "data/maps/Route110/scripts.pory"

# 442 "data/maps/Route110/scripts.pory"
Route110_EventScript_Timmy::
# 443 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
# 444 "data/maps/Route110/scripts.pory"
	end
# 445 "data/maps/Route110/scripts.pory"

# 446 "data/maps/Route110/scripts.pory"
Route110_EventScript_Unused::
# 447 "data/maps/Route110/scripts.pory"
	end
# 448 "data/maps/Route110/scripts.pory"

# 449 "data/maps/Route110/scripts.pory"
Route110_EventScript_Kaleb::
# 450 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
# 451 "data/maps/Route110/scripts.pory"
	end
# 452 "data/maps/Route110/scripts.pory"

# 453 "data/maps/Route110/scripts.pory"
Route110_EventScript_JosephEdwin::
# 454 "data/maps/Route110/scripts.pory"
lockall
# 455 "data/maps/Route110/scripts.pory"
setvar VAR_0x8008, LOCALID_JOSEPH
# 456 "data/maps/Route110/scripts.pory"
playse SE_PIN
# 457 "data/maps/Route110/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 458 "data/maps/Route110/scripts.pory"
waitmovement 0
# 459 "data/maps/Route110/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 460 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 461 "data/maps/Route110/scripts.pory"
waitmovement 0
# 462 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_JosephIntro MSGBOX_AUTOCLOSE
# 463 "data/maps/Route110/scripts.pory"
setvar VAR_0x8008, LOCALID_EDWIN
# 464 "data/maps/Route110/scripts.pory"
playse SE_PIN
# 465 "data/maps/Route110/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 466 "data/maps/Route110/scripts.pory"
waitmovement 0
# 467 "data/maps/Route110/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 468 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 469 "data/maps/Route110/scripts.pory"
waitmovement 0
# 470 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_EdwinIntro MSGBOX_AUTOCLOSE
# 471 "data/maps/Route110/scripts.pory"
goto Route110_EventScript_JosephEdwinDoMultiBattle
# 472 "data/maps/Route110/scripts.pory"
releaseall
# 473 "data/maps/Route110/scripts.pory"
end
# 474 "data/maps/Route110/scripts.pory"

# 475 "data/maps/Route110/scripts.pory"
Route110_EventScript_JosephEdwinDoMultiBattle::
# 476 "data/maps/Route110/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 477 "data/maps/Route110/scripts.pory"
multi_2p_vs_2 TRAINER_JOSEPH, Route110_Text_JosephDefeated, TRAINER_EDWIN_1, Route110_Text_EdwinDefeated, PARTNER_EMMIE
# 478 "data/maps/Route110/scripts.pory"
switch VAR_RESULT
# 479 "data/maps/Route110/scripts.pory"
case 1, Route110_EventScript_JosephEdwinVictory
# 480 "data/maps/Route110/scripts.pory"
fadescreen FADE_TO_BLACK
# 481 "data/maps/Route110/scripts.pory"
special SetCB2WhiteOut
# 482 "data/maps/Route110/scripts.pory"
waitstate
# 483 "data/maps/Route110/scripts.pory"

# 484 "data/maps/Route110/scripts.pory"
Route110_EventScript_JosephEdwinVictory::
# 485 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 486 "data/maps/Route110/scripts.pory"
waitmovement 0
# 487 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
# 488 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 489 "data/maps/Route110/scripts.pory"
waitmovement 0
# 490 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_EdwinPostBattle, MSGBOX_AUTOCLOSE
# 491 "data/maps/Route110/scripts.pory"
addvar VAR_ROUTE110_STATE, 1
# 492 "data/maps/Route110/scripts.pory"
end
# 493 "data/maps/Route110/scripts.pory"

# 494 "data/maps/Route110/scripts.pory"
Route110_EventScript_Joseph::
# 495 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
# 496 "data/maps/Route110/scripts.pory"
	end
# 497 "data/maps/Route110/scripts.pory"

# 498 "data/maps/Route110/scripts.pory"
Route110_EventScript_AlyssaBenjamin::
# 499 "data/maps/Route110/scripts.pory"
lockall
# 500 "data/maps/Route110/scripts.pory"
setvar VAR_0x8008, LOCALID_ALYSSA
# 501 "data/maps/Route110/scripts.pory"
playse SE_PIN
# 502 "data/maps/Route110/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 503 "data/maps/Route110/scripts.pory"
waitmovement 0
# 504 "data/maps/Route110/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 505 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 506 "data/maps/Route110/scripts.pory"
waitmovement 0
# 507 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_AlyssaIntro MSGBOX_AUTOCLOSE
# 508 "data/maps/Route110/scripts.pory"
setvar VAR_0x8008, LOCALID_BENJAMIN
# 509 "data/maps/Route110/scripts.pory"
playse SE_PIN
# 510 "data/maps/Route110/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 511 "data/maps/Route110/scripts.pory"
waitmovement 0
# 512 "data/maps/Route110/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 513 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 514 "data/maps/Route110/scripts.pory"
waitmovement 0
# 515 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_BenjaminIntro MSGBOX_AUTOCLOSE
# 516 "data/maps/Route110/scripts.pory"
goto Route110_EventScript_AlyssaBenjaminDoMultiBattle
# 517 "data/maps/Route110/scripts.pory"
releaseall
# 518 "data/maps/Route110/scripts.pory"
end
# 519 "data/maps/Route110/scripts.pory"

# 520 "data/maps/Route110/scripts.pory"
Route110_EventScript_AlyssaBenjaminDoMultiBattle::
# 521 "data/maps/Route110/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 522 "data/maps/Route110/scripts.pory"
multi_2p_vs_2 TRAINER_ALYSSA, Route110_Text_AlyssaDefeated, TRAINER_BENJAMIN_1, Route110_Text_BenjaminDefeated, PARTNER_EMMIE
# 523 "data/maps/Route110/scripts.pory"
switch VAR_RESULT
# 524 "data/maps/Route110/scripts.pory"
case 1, Route110_EventScript_AlyssaBenjaminVictory
# 525 "data/maps/Route110/scripts.pory"
fadescreen FADE_TO_BLACK
# 526 "data/maps/Route110/scripts.pory"
special SetCB2WhiteOut
# 527 "data/maps/Route110/scripts.pory"
waitstate
# 528 "data/maps/Route110/scripts.pory"

# 529 "data/maps/Route110/scripts.pory"
Route110_EventScript_AlyssaBenjaminVictory::
# 530 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 531 "data/maps/Route110/scripts.pory"
waitmovement 0
# 532 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
# 533 "data/maps/Route110/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 534 "data/maps/Route110/scripts.pory"
waitmovement 0
# 535 "data/maps/Route110/scripts.pory"
msgbox Route110_Text_BenjaminPostBattle, MSGBOX_AUTOCLOSE
# 536 "data/maps/Route110/scripts.pory"
addvar VAR_ROUTE110_STATE, 1
# 537 "data/maps/Route110/scripts.pory"
end
# 538 "data/maps/Route110/scripts.pory"

# 539 "data/maps/Route110/scripts.pory"
Route110_EventScript_Alyssa::
# 540 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
# 541 "data/maps/Route110/scripts.pory"
	end
# 542 "data/maps/Route110/scripts.pory"

# 543 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingChallengeEnd::
# 544 "data/maps/Route110/scripts.pory"
	lockall
# 545 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
# 546 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 547 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_CyclingChallengeResults
# 548 "data/maps/Route110/scripts.pory"
	releaseall
# 549 "data/maps/Route110/scripts.pory"
	end
# 550 "data/maps/Route110/scripts.pory"

# 551 "data/maps/Route110/scripts.pory"
Route110_EventScript_CyclingChallengeResults::
# 552 "data/maps/Route110/scripts.pory"
	special FinishCyclingRoadChallenge
# 553 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
# 554 "data/maps/Route110/scripts.pory"
	switch VAR_RESULT
# 555 "data/maps/Route110/scripts.pory"
	case 10, Route110_EventScript_ChallengeReactionBest
# 556 "data/maps/Route110/scripts.pory"
	case 9, Route110_EventScript_ChallengeReactionGood
# 557 "data/maps/Route110/scripts.pory"
	case 8, Route110_EventScript_ChallengeReactionGood
# 558 "data/maps/Route110/scripts.pory"
	case 7, Route110_EventScript_ChallengeReactionGood
# 559 "data/maps/Route110/scripts.pory"
	case 6, Route110_EventScript_ChallengeReactionOk
# 560 "data/maps/Route110/scripts.pory"
	case 5, Route110_EventScript_ChallengeReactionOk
# 561 "data/maps/Route110/scripts.pory"
	case 4, Route110_EventScript_ChallengeReactionOk
# 562 "data/maps/Route110/scripts.pory"
	case 3, Route110_EventScript_ChallengeReactionBad
# 563 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_ChallengeReactionBad
# 564 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_ChallengeReactionBad
# 565 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_ChallengeReactionWorst
# 566 "data/maps/Route110/scripts.pory"
	end
# 567 "data/maps/Route110/scripts.pory"

# 568 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionBest::
# 569 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
# 570 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 571 "data/maps/Route110/scripts.pory"
	end
# 572 "data/maps/Route110/scripts.pory"

# 573 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionGood::
# 574 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
# 575 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 576 "data/maps/Route110/scripts.pory"
	end
# 577 "data/maps/Route110/scripts.pory"

# 578 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionOk::
# 579 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
# 580 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 581 "data/maps/Route110/scripts.pory"
	end
# 582 "data/maps/Route110/scripts.pory"

# 583 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionBad::
# 584 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
# 585 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 586 "data/maps/Route110/scripts.pory"
	end
# 587 "data/maps/Route110/scripts.pory"

# 588 "data/maps/Route110/scripts.pory"
Route110_EventScript_ChallengeReactionWorst::
# 589 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
# 590 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_EndChallenge
# 591 "data/maps/Route110/scripts.pory"
	end
# 592 "data/maps/Route110/scripts.pory"

# 593 "data/maps/Route110/scripts.pory"
Route110_EventScript_EndChallenge::
# 594 "data/maps/Route110/scripts.pory"
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
# 595 "data/maps/Route110/scripts.pory"
	savebgm MUS_DUMMY
# 596 "data/maps/Route110/scripts.pory"
	fadedefaultbgm
# 597 "data/maps/Route110/scripts.pory"
	return
# 598 "data/maps/Route110/scripts.pory"

# 599 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger1::
# 600 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 1
# 601 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 602 "data/maps/Route110/scripts.pory"
	end
# 603 "data/maps/Route110/scripts.pory"

# 604 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger2::
# 605 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 2
# 606 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 607 "data/maps/Route110/scripts.pory"
	end
# 608 "data/maps/Route110/scripts.pory"

# 609 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalTrigger3::
# 610 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 3
# 611 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalScene
# 612 "data/maps/Route110/scripts.pory"
	end
# 613 "data/maps/Route110/scripts.pory"

# 614 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalScene::
# 615 "data/maps/Route110/scripts.pory"
	lockall
# 616 "data/maps/Route110/scripts.pory"
	checkplayergender
# 617 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
# 618 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
# 619 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 620 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 621 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 622 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 623 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 624 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 625 "data/maps/Route110/scripts.pory"
	delay 30
# 626 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
# 627 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
# 628 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
# 629 "data/maps/Route110/scripts.pory"
	checkplayergender
# 630 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
# 631 "data/maps/Route110/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
# 632 "data/maps/Route110/scripts.pory"
	releaseall
# 633 "data/maps/Route110/scripts.pory"
	end
# 634 "data/maps/Route110/scripts.pory"

# 635 "data/maps/Route110/scripts.pory"
Route110_EventScript_NorthBlock::
# 636 "data/maps/Route110/scripts.pory"
	lockall
# 637 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 638 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 639 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 640 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 641 "data/maps/Route110/scripts.pory"
	delay 30
# 642 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_LetsCycleHome, MSGBOX_DEFAULT
# 643 "data/maps/Route110/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER Route110_Movement_NorthBlock
# 644 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 645 "data/maps/Route110/scripts.pory"
	releaseall
# 646 "data/maps/Route110/scripts.pory"
	end
# 647 "data/maps/Route110/scripts.pory"

# 648 "data/maps/Route110/scripts.pory"
Route110_Movement_NorthBlock:
# 649 "data/maps/Route110/scripts.pory"
	walk_up
# 650 "data/maps/Route110/scripts.pory"
	step_end
# 651 "data/maps/Route110/scripts.pory"

# 652 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayMayMusic::
# 653 "data/maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 654 "data/maps/Route110/scripts.pory"
	return
# 655 "data/maps/Route110/scripts.pory"

# 656 "data/maps/Route110/scripts.pory"
Route110_EventScript_PlayBrendanMusic::
# 657 "data/maps/Route110/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 658 "data/maps/Route110/scripts.pory"
	return
# 659 "data/maps/Route110/scripts.pory"

# 660 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattle::
# 661 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
# 662 "data/maps/Route110/scripts.pory"
	switch VAR_STARTER_MON
# 663 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_MayBattleTreecko
# 664 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_MayBattleTorchic
# 665 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_MayBattleMudkip
# 666 "data/maps/Route110/scripts.pory"
	end
# 667 "data/maps/Route110/scripts.pory"

# 668 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleTreecko::
# 669 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
# 670 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 671 "data/maps/Route110/scripts.pory"
	end
# 672 "data/maps/Route110/scripts.pory"

# 673 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleTorchic::
# 674 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
# 675 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 676 "data/maps/Route110/scripts.pory"
	end
# 677 "data/maps/Route110/scripts.pory"

# 678 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayBattleMudkip::
# 679 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
# 680 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_MayDefeated
# 681 "data/maps/Route110/scripts.pory"
	end
# 682 "data/maps/Route110/scripts.pory"

# 683 "data/maps/Route110/scripts.pory"
Route110_EventScript_MayDefeated::
# 684 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
# 685 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_GiveItemfinder
# 686 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
# 687 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalExit
# 688 "data/maps/Route110/scripts.pory"
	end
# 689 "data/maps/Route110/scripts.pory"

# 690 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattle::
# 691 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 692 "data/maps/Route110/scripts.pory"
	switch VAR_STARTER_MON
# 693 "data/maps/Route110/scripts.pory"
	case 0, Route110_EventScript_BrendanBattleTreecko
# 694 "data/maps/Route110/scripts.pory"
	case 1, Route110_EventScript_BrendanBattleTorchic
# 695 "data/maps/Route110/scripts.pory"
	case 2, Route110_EventScript_BrendanBattleMudkip
# 696 "data/maps/Route110/scripts.pory"
	end
# 697 "data/maps/Route110/scripts.pory"

# 698 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleTreecko::
# 699 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
# 700 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 701 "data/maps/Route110/scripts.pory"
	end
# 702 "data/maps/Route110/scripts.pory"

# 703 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleTorchic::
# 704 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
# 705 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 706 "data/maps/Route110/scripts.pory"
	end
# 707 "data/maps/Route110/scripts.pory"

# 708 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanBattleMudkip::
# 709 "data/maps/Route110/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, Route110_Text_BrendanDefeated
# 710 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BrendanDefeated
# 711 "data/maps/Route110/scripts.pory"
	end
# 712 "data/maps/Route110/scripts.pory"

# 713 "data/maps/Route110/scripts.pory"
Route110_EventScript_BrendanDefeated::
# 714 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
# 715 "data/maps/Route110/scripts.pory"
	call Route110_EventScript_GiveItemfinder
# 716 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
# 717 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_RivalExit
# 718 "data/maps/Route110/scripts.pory"
	end
# 719 "data/maps/Route110/scripts.pory"

# 720 "data/maps/Route110/scripts.pory"
Route110_EventScript_GiveItemfinder::
# 721 "data/maps/Route110/scripts.pory"
	giveitem ITEM_DOWSING_MACHINE
# 722 "data/maps/Route110/scripts.pory"
	return
# 723 "data/maps/Route110/scripts.pory"

# 724 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit::
# 725 "data/maps/Route110/scripts.pory"
	closemessage
# 726 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
# 727 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
# 728 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
# 729 "data/maps/Route110/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
# 730 "data/maps/Route110/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
# 731 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_RIVAL
# 732 "data/maps/Route110/scripts.pory"
	addobject LOCALID_RIVAL_ON_BIKE
# 733 "data/maps/Route110/scripts.pory"
	delay 45
# 734 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
# 735 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
# 736 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
# 737 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_RIVAL_ON_BIKE
# 738 "data/maps/Route110/scripts.pory"
	setvar VAR_ROUTE110_STATE, 1
# 739 "data/maps/Route110/scripts.pory"
	savebgm MUS_DUMMY
# 740 "data/maps/Route110/scripts.pory"
	fadedefaultbgm
# 741 "data/maps/Route110/scripts.pory"
	releaseall
# 742 "data/maps/Route110/scripts.pory"
	end
# 743 "data/maps/Route110/scripts.pory"

# 744 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer1::
# 745 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer1
# 746 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 747 "data/maps/Route110/scripts.pory"
	return
# 748 "data/maps/Route110/scripts.pory"

# 749 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer2::
# 750 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer2
# 751 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 752 "data/maps/Route110/scripts.pory"
	return
# 753 "data/maps/Route110/scripts.pory"

# 754 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalApproachPlayer3::
# 755 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer3
# 756 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 757 "data/maps/Route110/scripts.pory"
	return
# 758 "data/maps/Route110/scripts.pory"

# 759 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit1::
# 760 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
# 761 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 762 "data/maps/Route110/scripts.pory"
	return
# 763 "data/maps/Route110/scripts.pory"

# 764 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit2::
# 765 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
# 766 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 767 "data/maps/Route110/scripts.pory"
	return
# 768 "data/maps/Route110/scripts.pory"

# 769 "data/maps/Route110/scripts.pory"
Route110_EventScript_RivalExit3::
# 770 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
# 771 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 772 "data/maps/Route110/scripts.pory"
	return
# 773 "data/maps/Route110/scripts.pory"

# 774 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival1::
# 775 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 33, 55
# 776 "data/maps/Route110/scripts.pory"
	return
# 777 "data/maps/Route110/scripts.pory"

# 778 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival2::
# 779 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 34, 55
# 780 "data/maps/Route110/scripts.pory"
	return
# 781 "data/maps/Route110/scripts.pory"

# 782 "data/maps/Route110/scripts.pory"
Route110_EventScript_MoveRival3::
# 783 "data/maps/Route110/scripts.pory"
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 35, 55
# 784 "data/maps/Route110/scripts.pory"
	return
# 785 "data/maps/Route110/scripts.pory"

# 786 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer1:
# 787 "data/maps/Route110/scripts.pory"
	walk_down
# 788 "data/maps/Route110/scripts.pory"
	walk_left
# 789 "data/maps/Route110/scripts.pory"
	walk_in_place_faster_down
# 790 "data/maps/Route110/scripts.pory"
	step_end
# 791 "data/maps/Route110/scripts.pory"

# 792 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer2:
# 793 "data/maps/Route110/scripts.pory"
	walk_down
# 794 "data/maps/Route110/scripts.pory"
	step_end
# 795 "data/maps/Route110/scripts.pory"

# 796 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalApproachPlayer3:
# 797 "data/maps/Route110/scripts.pory"
	walk_down
# 798 "data/maps/Route110/scripts.pory"
	walk_right
# 799 "data/maps/Route110/scripts.pory"
	walk_in_place_faster_down
# 800 "data/maps/Route110/scripts.pory"
	step_end
# 801 "data/maps/Route110/scripts.pory"

# 802 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit1:
# 803 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 804 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 805 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 806 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 807 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 808 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 809 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 810 "data/maps/Route110/scripts.pory"
	step_end
# 811 "data/maps/Route110/scripts.pory"

# 812 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit2:
# 813 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 814 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 815 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 816 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 817 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 818 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 819 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 820 "data/maps/Route110/scripts.pory"
	walk_fast_down
# 821 "data/maps/Route110/scripts.pory"
	step_end
# 822 "data/maps/Route110/scripts.pory"

# 823 "data/maps/Route110/scripts.pory"
Route110_Movement_RivalExit3:
# 824 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 825 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 826 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 827 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 828 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 829 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 830 "data/maps/Route110/scripts.pory"
	walk_fast_up
# 831 "data/maps/Route110/scripts.pory"
	step_end
# 832 "data/maps/Route110/scripts.pory"

# 833 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene1::
# 834 "data/maps/Route110/scripts.pory"
	lockall
# 835 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 1
# 836 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 837 "data/maps/Route110/scripts.pory"

# 838 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene2::
# 839 "data/maps/Route110/scripts.pory"
	lockall
# 840 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 2
# 841 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 842 "data/maps/Route110/scripts.pory"

# 843 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene3::
# 844 "data/maps/Route110/scripts.pory"
	lockall
# 845 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 3
# 846 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 847 "data/maps/Route110/scripts.pory"

# 848 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene4::
# 849 "data/maps/Route110/scripts.pory"
	lockall
# 850 "data/maps/Route110/scripts.pory"
	setvar VAR_0x8008, 4
# 851 "data/maps/Route110/scripts.pory"
	goto Route110_EventScript_BirchScene
# 852 "data/maps/Route110/scripts.pory"

# 853 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchScene::
# 854 "data/maps/Route110/scripts.pory"
	addobject LOCALID_BIRCH
# 855 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchEntrance
# 856 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 857 "data/maps/Route110/scripts.pory"
	playse SE_PIN
# 858 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
# 859 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 860 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_Delay48
# 861 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 862 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
# 863 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
# 864 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
# 865 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
# 866 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
# 867 "data/maps/Route110/scripts.pory"
	closemessage
# 868 "data/maps/Route110/scripts.pory"
	delay 20
# 869 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterLeft
# 870 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 871 "data/maps/Route110/scripts.pory"
	delay 10
# 872 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 873 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 874 "data/maps/Route110/scripts.pory"
	delay 20
# 875 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterDown
# 876 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 877 "data/maps/Route110/scripts.pory"
	delay 30
# 878 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
# 879 "data/maps/Route110/scripts.pory"
	closemessage
# 880 "data/maps/Route110/scripts.pory"
	delay 30
# 881 "data/maps/Route110/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 882 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
# 883 "data/maps/Route110/scripts.pory"
	waitfanfare
# 884 "data/maps/Route110/scripts.pory"
	closemessage
# 885 "data/maps/Route110/scripts.pory"
	delay 30
# 886 "data/maps/Route110/scripts.pory"
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
# 887 "data/maps/Route110/scripts.pory"
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
# 888 "data/maps/Route110/scripts.pory"
	closemessage
# 889 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
# 890 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
# 891 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
# 892 "data/maps/Route110/scripts.pory"
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
# 893 "data/maps/Route110/scripts.pory"
	removeobject LOCALID_BIRCH
# 894 "data/maps/Route110/scripts.pory"
	setvar VAR_REGISTER_BIRCH_STATE, 2
# 895 "data/maps/Route110/scripts.pory"
	releaseall
# 896 "data/maps/Route110/scripts.pory"
	end
# 897 "data/maps/Route110/scripts.pory"

# 898 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer1::
# 899 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer1
# 900 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 901 "data/maps/Route110/scripts.pory"
	return
# 902 "data/maps/Route110/scripts.pory"

# 903 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer2::
# 904 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer2
# 905 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 906 "data/maps/Route110/scripts.pory"
	return
# 907 "data/maps/Route110/scripts.pory"

# 908 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer3::
# 909 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer3
# 910 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 911 "data/maps/Route110/scripts.pory"
	return
# 912 "data/maps/Route110/scripts.pory"

# 913 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchApproachPlayer4::
# 914 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer4
# 915 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 916 "data/maps/Route110/scripts.pory"
	return
# 917 "data/maps/Route110/scripts.pory"

# 918 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit1::
# 919 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit1
# 920 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 921 "data/maps/Route110/scripts.pory"
	return
# 922 "data/maps/Route110/scripts.pory"

# 923 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit2::
# 924 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit2
# 925 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 926 "data/maps/Route110/scripts.pory"
	return
# 927 "data/maps/Route110/scripts.pory"

# 928 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit3::
# 929 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit3
# 930 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 931 "data/maps/Route110/scripts.pory"
	return
# 932 "data/maps/Route110/scripts.pory"

# 933 "data/maps/Route110/scripts.pory"
Route110_EventScript_BirchExit4::
# 934 "data/maps/Route110/scripts.pory"
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit4
# 935 "data/maps/Route110/scripts.pory"
	waitmovement 0
# 936 "data/maps/Route110/scripts.pory"
	return
# 937 "data/maps/Route110/scripts.pory"

# 938 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchEntrance:
# 939 "data/maps/Route110/scripts.pory"
	walk_down
# 940 "data/maps/Route110/scripts.pory"
	walk_down
# 941 "data/maps/Route110/scripts.pory"
	walk_down
# 942 "data/maps/Route110/scripts.pory"
	step_end
# 943 "data/maps/Route110/scripts.pory"

# 944 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer1:
# 945 "data/maps/Route110/scripts.pory"
	walk_down
# 946 "data/maps/Route110/scripts.pory"
	walk_left
# 947 "data/maps/Route110/scripts.pory"
	walk_left
# 948 "data/maps/Route110/scripts.pory"
	walk_down
# 949 "data/maps/Route110/scripts.pory"
	step_end
# 950 "data/maps/Route110/scripts.pory"

# 951 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer2:
# 952 "data/maps/Route110/scripts.pory"
	walk_down
# 953 "data/maps/Route110/scripts.pory"
	walk_left
# 954 "data/maps/Route110/scripts.pory"
	walk_down
# 955 "data/maps/Route110/scripts.pory"
	step_end
# 956 "data/maps/Route110/scripts.pory"

# 957 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer3:
# 958 "data/maps/Route110/scripts.pory"
	walk_down
# 959 "data/maps/Route110/scripts.pory"
	walk_down
# 960 "data/maps/Route110/scripts.pory"
	step_end
# 961 "data/maps/Route110/scripts.pory"

# 962 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchApproachPlayer4:
# 963 "data/maps/Route110/scripts.pory"
	walk_down
# 964 "data/maps/Route110/scripts.pory"
	walk_right
# 965 "data/maps/Route110/scripts.pory"
	walk_down
# 966 "data/maps/Route110/scripts.pory"
	step_end
# 967 "data/maps/Route110/scripts.pory"

# 968 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit1:
# 969 "data/maps/Route110/scripts.pory"
	walk_up
# 970 "data/maps/Route110/scripts.pory"
	walk_up
# 971 "data/maps/Route110/scripts.pory"
	walk_right
# 972 "data/maps/Route110/scripts.pory"
	walk_up
# 973 "data/maps/Route110/scripts.pory"
	walk_up
# 974 "data/maps/Route110/scripts.pory"
	walk_up
# 975 "data/maps/Route110/scripts.pory"
	step_end
# 976 "data/maps/Route110/scripts.pory"

# 977 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit2:
# 978 "data/maps/Route110/scripts.pory"
	walk_up
# 979 "data/maps/Route110/scripts.pory"
	walk_up
# 980 "data/maps/Route110/scripts.pory"
	walk_up
# 981 "data/maps/Route110/scripts.pory"
	walk_up
# 982 "data/maps/Route110/scripts.pory"
	walk_up
# 983 "data/maps/Route110/scripts.pory"
	step_end
# 984 "data/maps/Route110/scripts.pory"

# 985 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit3:
# 986 "data/maps/Route110/scripts.pory"
	walk_up
# 987 "data/maps/Route110/scripts.pory"
	walk_up
# 988 "data/maps/Route110/scripts.pory"
	walk_up
# 989 "data/maps/Route110/scripts.pory"
	walk_up
# 990 "data/maps/Route110/scripts.pory"
	walk_up
# 991 "data/maps/Route110/scripts.pory"
	step_end
# 992 "data/maps/Route110/scripts.pory"

# 993 "data/maps/Route110/scripts.pory"
Route110_Movement_BirchExit4:
# 994 "data/maps/Route110/scripts.pory"
	walk_up
# 995 "data/maps/Route110/scripts.pory"
	walk_up
# 996 "data/maps/Route110/scripts.pory"
	walk_up
# 997 "data/maps/Route110/scripts.pory"
	walk_up
# 998 "data/maps/Route110/scripts.pory"
	walk_up
# 999 "data/maps/Route110/scripts.pory"
	step_end
# 1000 "data/maps/Route110/scripts.pory"

# 1001 "data/maps/Route110/scripts.pory"
Route110_Text_WeCantTalkAboutAquaActivities:
# 1002 "data/maps/Route110/scripts.pory"
	.string "TEAM AQUA's activities…\n"
# 1003 "data/maps/Route110/scripts.pory"
	.string "We can't talk about them yet.$"
# 1004 "data/maps/Route110/scripts.pory"

# 1005 "data/maps/Route110/scripts.pory"
Route110_Text_KickUpARuckus:
# 1006 "data/maps/Route110/scripts.pory"
	.string "I want to get going to SLATEPORT and\n"
# 1007 "data/maps/Route110/scripts.pory"
	.string "kick up a ruckus!$"
# 1008 "data/maps/Route110/scripts.pory"

# 1009 "data/maps/Route110/scripts.pory"
Route110_Text_MyFirstJobInAqua:
# 1010 "data/maps/Route110/scripts.pory"
	.string "This is my first job after joining\n"
# 1011 "data/maps/Route110/scripts.pory"
	.string "TEAM AQUA. It's a little scary.$"
# 1012 "data/maps/Route110/scripts.pory"

# 1013 "data/maps/Route110/scripts.pory"
Route110_Text_AquaActionsBringSmiles:
# 1014 "data/maps/Route110/scripts.pory"
	.string "TEAM AQUA's actions should bring\n"
# 1015 "data/maps/Route110/scripts.pory"
	.string "smiles to people's faces!$"
# 1016 "data/maps/Route110/scripts.pory"

# 1017 "data/maps/Route110/scripts.pory"
Route110_Text_LetsCycleHome:
# 1018 "data/maps/Route110/scripts.pory"
	.string "You know, {PLAYER}, I've never been\n"
# 1019 "data/maps/Route110/scripts.pory"
	.string "on the Cycling Road.\p"
# 1020 "data/maps/Route110/scripts.pory"
	.string "Why don't we check out the Mauville\n"
# 1021 "data/maps/Route110/scripts.pory"
	.string "bike shop and take that route home?$"
# 1022 "data/maps/Route110/scripts.pory"

# 1023 "data/maps/Route110/scripts.pory"
Route110_Text_MayLetsBattle:
# 1024 "data/maps/Route110/scripts.pory"
	.string "MAY: Hi, {PLAYER}{KUN}, long time no see!\p"
# 1025 "data/maps/Route110/scripts.pory"
	.string "While I was searching for other\n"
# 1026 "data/maps/Route110/scripts.pory"
	.string "POKéMON, my POKéMON grew stronger.\p"
# 1027 "data/maps/Route110/scripts.pory"
	.string "So…\n"
# 1028 "data/maps/Route110/scripts.pory"
	.string "How about a little battle?$"
# 1029 "data/maps/Route110/scripts.pory"

# 1030 "data/maps/Route110/scripts.pory"
Route110_Text_MayDefeated:
# 1031 "data/maps/Route110/scripts.pory"
	.string "Yikes!\n"
# 1032 "data/maps/Route110/scripts.pory"
	.string "You're better than I expected!$"
# 1033 "data/maps/Route110/scripts.pory"

# 1034 "data/maps/Route110/scripts.pory"
Route110_Text_MayTakeThis:
# 1035 "data/maps/Route110/scripts.pory"
	.string "MAY: {PLAYER}{KUN}, you've been busy\n"
# 1036 "data/maps/Route110/scripts.pory"
	.string "training, too, haven't you?\p"
# 1037 "data/maps/Route110/scripts.pory"
	.string "I think you deserve a reward!\n"
# 1038 "data/maps/Route110/scripts.pory"
	.string "This is from me!$"
# 1039 "data/maps/Route110/scripts.pory"

# 1040 "data/maps/Route110/scripts.pory"
Route110_Text_MayExplainItemfinder:
# 1041 "data/maps/Route110/scripts.pory"
	.string "MAY: That's an ITEMFINDER.\p"
# 1042 "data/maps/Route110/scripts.pory"
	.string "Try it out. If there is an item that's\n"
# 1043 "data/maps/Route110/scripts.pory"
	.string "not visible, it emits a sound.\p"
# 1044 "data/maps/Route110/scripts.pory"
	.string "Okay, {PLAYER}{KUN}, let's meet again!\p"
# 1045 "data/maps/Route110/scripts.pory"
	.string "I know it's a little silly coming from\n"
# 1046 "data/maps/Route110/scripts.pory"
	.string "me, but I think you should train a lot\l"
# 1047 "data/maps/Route110/scripts.pory"
	.string "harder for the next time.$"
# 1048 "data/maps/Route110/scripts.pory"

# 1049 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanLetsBattle:
# 1050 "data/maps/Route110/scripts.pory"
	.string "BRENDAN: Hey, {PLAYER}.\n"
# 1051 "data/maps/Route110/scripts.pory"
	.string "So this is where you were.\l"
# 1052 "data/maps/Route110/scripts.pory"
	.string "How's it going?\p"
# 1053 "data/maps/Route110/scripts.pory"
	.string "Have you been raising your POKéMON?\n"
# 1054 "data/maps/Route110/scripts.pory"
	.string "I'll check for you.$"
# 1055 "data/maps/Route110/scripts.pory"

# 1056 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanDefeated:
# 1057 "data/maps/Route110/scripts.pory"
	.string "Hmm…\n"
# 1058 "data/maps/Route110/scripts.pory"
	.string "You're pretty good.$"
# 1059 "data/maps/Route110/scripts.pory"

# 1060 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanTakeThis:
# 1061 "data/maps/Route110/scripts.pory"
	.string "BRENDAN: {PLAYER}, you've trained\n"
# 1062 "data/maps/Route110/scripts.pory"
	.string "without me noticing…\p"
# 1063 "data/maps/Route110/scripts.pory"
	.string "Good enough!\n"
# 1064 "data/maps/Route110/scripts.pory"
	.string "Here, take this.$"
# 1065 "data/maps/Route110/scripts.pory"

# 1066 "data/maps/Route110/scripts.pory"
Route110_Text_BrendanExplainItemfinder:
# 1067 "data/maps/Route110/scripts.pory"
	.string "BRENDAN: That's an ITEMFINDER.\p"
# 1068 "data/maps/Route110/scripts.pory"
	.string "Use it to root around for items that\n"
# 1069 "data/maps/Route110/scripts.pory"
	.string "aren't visible.\p"
# 1070 "data/maps/Route110/scripts.pory"
	.string "If it senses something, it emits\n"
# 1071 "data/maps/Route110/scripts.pory"
	.string "a sound.\p"
# 1072 "data/maps/Route110/scripts.pory"
	.string "Anyway, I'm off to look for new\n"
# 1073 "data/maps/Route110/scripts.pory"
	.string "POKéMON.$"
# 1074 "data/maps/Route110/scripts.pory"

# 1075 "data/maps/Route110/scripts.pory"
Route110_Text_RideBikeAtFullSpeed:
# 1076 "data/maps/Route110/scripts.pory"
	.string "Wouldn't it be great to ride a BIKE\n"
# 1077 "data/maps/Route110/scripts.pory"
	.string "at full speed on CYCLING ROAD?$"
# 1078 "data/maps/Route110/scripts.pory"

# 1079 "data/maps/Route110/scripts.pory"
Route110_Text_HairStreamsBehindMe:
# 1080 "data/maps/Route110/scripts.pory"
	.string "How do you like the way my raven-\n"
# 1081 "data/maps/Route110/scripts.pory"
	.string "colored hair streams behind me?\p"
# 1082 "data/maps/Route110/scripts.pory"
	.string "I grew my hair out just for that.$"
# 1083 "data/maps/Route110/scripts.pory"

# 1084 "data/maps/Route110/scripts.pory"
Route110_Text_YouGotBikeFromRydel:
# 1085 "data/maps/Route110/scripts.pory"
	.string "Oh, hey, you got that BIKE from RYDEL!\p"
# 1086 "data/maps/Route110/scripts.pory"
	.string "Oh, it's glaringly obvious.\n"
# 1087 "data/maps/Route110/scripts.pory"
	.string "It says right on your bike…\p"
# 1088 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 1089 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 1090 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 1091 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 1092 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 1093 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 1094 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
# 1095 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
# 1096 "data/maps/Route110/scripts.pory"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
# 1097 "data/maps/Route110/scripts.pory"
	.string "That name's everywhere.\p"
# 1098 "data/maps/Route110/scripts.pory"
	.string "You should ride it around all over\n"
# 1099 "data/maps/Route110/scripts.pory"
	.string "the place--it's good advertising!$"
# 1100 "data/maps/Route110/scripts.pory"

# 1101 "data/maps/Route110/scripts.pory"
Route110_Text_TwoRoads:
# 1102 "data/maps/Route110/scripts.pory"
	.string "The two roads, one above, one below…\p"
# 1103 "data/maps/Route110/scripts.pory"
	.string "A road each for people and POKéMON.\n"
# 1104 "data/maps/Route110/scripts.pory"
	.string "Perhaps that is right and fair.$"
# 1105 "data/maps/Route110/scripts.pory"

# 1106 "data/maps/Route110/scripts.pory"
Route110_Text_WalkOnTheLowRoad:
# 1107 "data/maps/Route110/scripts.pory"
	.string "I don't have a BIKE, so I'll take\n"
# 1108 "data/maps/Route110/scripts.pory"
	.string "a leisurely walk on the low road.$"
# 1109 "data/maps/Route110/scripts.pory"

# 1110 "data/maps/Route110/scripts.pory"
Route110_Text_BikeTechniques:
# 1111 "data/maps/Route110/scripts.pory"
	.string "Learning techniques will make BIKE\n"
# 1112 "data/maps/Route110/scripts.pory"
	.string "riding even more fun.\p"
# 1113 "data/maps/Route110/scripts.pory"
	.string "There are some places that you can\n"
# 1114 "data/maps/Route110/scripts.pory"
	.string "reach only by using a BIKE technique.$"
# 1115 "data/maps/Route110/scripts.pory"

# 1116 "data/maps/Route110/scripts.pory"
Route110_Text_WhichShouldIChoose:
# 1117 "data/maps/Route110/scripts.pory"
	.string "Which should I choose?\p"
# 1118 "data/maps/Route110/scripts.pory"
	.string "Make a beeline for MAUVILLE on\n"
# 1119 "data/maps/Route110/scripts.pory"
	.string "CYCLING ROAD, or take the low road\l"
# 1120 "data/maps/Route110/scripts.pory"
	.string "and look for POKéMON?$"
# 1121 "data/maps/Route110/scripts.pory"

# 1122 "data/maps/Route110/scripts.pory"
Route110_Text_CyclingChallengeResultSummary:
# 1123 "data/maps/Route110/scripts.pory"
	.string "Number of collisions:\n"
# 1124 "data/maps/Route110/scripts.pory"
	.string "… … {STR_VAR_1}!\p"
# 1125 "data/maps/Route110/scripts.pory"
	.string "Total time:\n"
# 1126 "data/maps/Route110/scripts.pory"
	.string "… … {STR_VAR_2}!$"
# 1127 "data/maps/Route110/scripts.pory"

# 1128 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionBest:
# 1129 "data/maps/Route110/scripts.pory"
	.string "Bravo! Splendid showing!\p"
# 1130 "data/maps/Route110/scripts.pory"
	.string "Your love of cycling comes from deep\n"
# 1131 "data/maps/Route110/scripts.pory"
	.string "within your heart.\l"
# 1132 "data/maps/Route110/scripts.pory"
	.string "You've shaken me to my very soul!$"
# 1133 "data/maps/Route110/scripts.pory"

# 1134 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionGood:
# 1135 "data/maps/Route110/scripts.pory"
	.string "Your technique is remarkable.\p"
# 1136 "data/maps/Route110/scripts.pory"
	.string "I suggest you speed up a bit while\n"
# 1137 "data/maps/Route110/scripts.pory"
	.string "still avoiding collisions.$"
# 1138 "data/maps/Route110/scripts.pory"

# 1139 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionOk:
# 1140 "data/maps/Route110/scripts.pory"
	.string "I would consider you a work in\n"
# 1141 "data/maps/Route110/scripts.pory"
	.string "progress.\p"
# 1142 "data/maps/Route110/scripts.pory"
	.string "Still, I hope you don't forget the\n"
# 1143 "data/maps/Route110/scripts.pory"
	.string "sheer pleasure of cycling.$"
# 1144 "data/maps/Route110/scripts.pory"

# 1145 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionBad:
# 1146 "data/maps/Route110/scripts.pory"
	.string "My word… Your cycling skills border\n"
# 1147 "data/maps/Route110/scripts.pory"
	.string "on terrifying.\p"
# 1148 "data/maps/Route110/scripts.pory"
	.string "Most certainly, you need much more\n"
# 1149 "data/maps/Route110/scripts.pory"
	.string "practice riding.$"
# 1150 "data/maps/Route110/scripts.pory"

# 1151 "data/maps/Route110/scripts.pory"
Route110_Text_ChallengeReactionWorst:
# 1152 "data/maps/Route110/scripts.pory"
	.string "…I am aghast…\p"
# 1153 "data/maps/Route110/scripts.pory"
	.string "You're perhaps not cut out for this\n"
# 1154 "data/maps/Route110/scripts.pory"
	.string "unfortunate cycling business.\p"
# 1155 "data/maps/Route110/scripts.pory"
	.string "You ought to give serious thought to\n"
# 1156 "data/maps/Route110/scripts.pory"
	.string "returning that BIKE to RYDEL.$"
# 1157 "data/maps/Route110/scripts.pory"

# 1158 "data/maps/Route110/scripts.pory"
Route110_Text_RatedForNumberOfCollisions:
# 1159 "data/maps/Route110/scripts.pory"
	.string "This is CYCLING ROAD.\p"
# 1160 "data/maps/Route110/scripts.pory"
	.string "If you were to ride from MAUVILLE to\n"
# 1161 "data/maps/Route110/scripts.pory"
	.string "SLATEPORT on a MACH BIKE, you would\l"
# 1162 "data/maps/Route110/scripts.pory"
	.string "be rated for the number of collisions\l"
# 1163 "data/maps/Route110/scripts.pory"
	.string "and your total time.$"
# 1164 "data/maps/Route110/scripts.pory"

# 1165 "data/maps/Route110/scripts.pory"
Route110_Text_AlwaysAimHigher:
# 1166 "data/maps/Route110/scripts.pory"
	.string "Regardless of the results, I count on\n"
# 1167 "data/maps/Route110/scripts.pory"
	.string "seeing more challenges from you.\l"
# 1168 "data/maps/Route110/scripts.pory"
	.string "Always aim higher!$"
# 1169 "data/maps/Route110/scripts.pory"

# 1170 "data/maps/Route110/scripts.pory"
Route110_Text_AcroBikesDoNotQualify:
# 1171 "data/maps/Route110/scripts.pory"
	.string "On this CYCLING ROAD, those riding\n"
# 1172 "data/maps/Route110/scripts.pory"
	.string "MACH BIKES are rated for their number\l"
# 1173 "data/maps/Route110/scripts.pory"
	.string "of collisions and their total times.\p"
# 1174 "data/maps/Route110/scripts.pory"
	.string "ACRO BIKES do not qualify for rating.\n"
# 1175 "data/maps/Route110/scripts.pory"
	.string "They are easy to turn, so it's not fair.$"
# 1176 "data/maps/Route110/scripts.pory"

# 1177 "data/maps/Route110/scripts.pory"
Route110_Text_SlateportCitySign:
# 1178 "data/maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 1179 "data/maps/Route110/scripts.pory"
	.string "{DOWN_ARROW} SLATEPORT CITY$"
# 1180 "data/maps/Route110/scripts.pory"

# 1181 "data/maps/Route110/scripts.pory"
Route110_Text_CyclingRoadSign:
# 1182 "data/maps/Route110/scripts.pory"
	.string "SEASIDE CYCLING ROAD$"
# 1183 "data/maps/Route110/scripts.pory"

# 1184 "data/maps/Route110/scripts.pory"
Route110_Text_AquaWasHere:
# 1185 "data/maps/Route110/scripts.pory"
	.string "“TEAM AQUA was here!”\p"
# 1186 "data/maps/Route110/scripts.pory"
	.string "Someone painted that onto this sign,\n"
# 1187 "data/maps/Route110/scripts.pory"
	.string "but then someone else painted over it.\p"
# 1188 "data/maps/Route110/scripts.pory"
	.string "“TEAM MAGMA rules!” is what it\n"
# 1189 "data/maps/Route110/scripts.pory"
	.string "says now.$"
# 1190 "data/maps/Route110/scripts.pory"

# 1191 "data/maps/Route110/scripts.pory"
Route110_Text_Route103Sign:
# 1192 "data/maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 1193 "data/maps/Route110/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 103$"
# 1194 "data/maps/Route110/scripts.pory"

# 1195 "data/maps/Route110/scripts.pory"
Route110_Text_SeasideParkingSign:
# 1196 "data/maps/Route110/scripts.pory"
	.string "SEASIDE PARKING$"
# 1197 "data/maps/Route110/scripts.pory"

# 1198 "data/maps/Route110/scripts.pory"
Route110_Text_MauvilleCitySign:
# 1199 "data/maps/Route110/scripts.pory"
	.string "ROUTE 110\n"
# 1200 "data/maps/Route110/scripts.pory"
	.string "{UP_ARROW} MAUVILLE CITY$"
# 1201 "data/maps/Route110/scripts.pory"

# 1202 "data/maps/Route110/scripts.pory"
Route110_Text_TrainerTipsPrlzSleep:
# 1203 "data/maps/Route110/scripts.pory"
	.string "TRAINER TIPS\p"
# 1204 "data/maps/Route110/scripts.pory"
	.string "The foe can be made helpless by\n"
# 1205 "data/maps/Route110/scripts.pory"
	.string "paralyzing it or causing it to sleep.\p"
# 1206 "data/maps/Route110/scripts.pory"
	.string "It is an important technique for\n"
# 1207 "data/maps/Route110/scripts.pory"
	.string "POKéMON battles.$"
# 1208 "data/maps/Route110/scripts.pory"

# 1209 "data/maps/Route110/scripts.pory"
Route110_Text_TrainerTipsRegisterItems:
# 1210 "data/maps/Route110/scripts.pory"
	.string "TRAINER TIPS\p"
# 1211 "data/maps/Route110/scripts.pory"
	.string "The items in the BAG can be reorganized\n"
# 1212 "data/maps/Route110/scripts.pory"
	.string "by pressing SELECT.$"
# 1213 "data/maps/Route110/scripts.pory"

# 1214 "data/maps/Route110/scripts.pory"
Route110_Text_TrickHouseSign:
# 1215 "data/maps/Route110/scripts.pory"
	.string "“Three steps {RIGHT_ARROW} and two steps {UP_ARROW}\n"
# 1216 "data/maps/Route110/scripts.pory"
	.string "to reach the wondrous TRICK HOUSE.”$"
# 1217 "data/maps/Route110/scripts.pory"

# 1218 "data/maps/Route110/scripts.pory"
Route110_Text_BestRecord:
# 1219 "data/maps/Route110/scripts.pory"
	.string "THE BEST RECORD TO DATE…\p"
# 1220 "data/maps/Route110/scripts.pory"
	.string "No. of collisions: {STR_VAR_1}\p"
# 1221 "data/maps/Route110/scripts.pory"
	.string "Elapsed time: {STR_VAR_2}$"
# 1222 "data/maps/Route110/scripts.pory"

# 1223 "data/maps/Route110/scripts.pory"
Route110_Text_ThereIsNoRecord:
# 1224 "data/maps/Route110/scripts.pory"
	.string "THE BEST RECORD TO DATE…\p"
# 1225 "data/maps/Route110/scripts.pory"
	.string "No one seems to have taken the\n"
# 1226 "data/maps/Route110/scripts.pory"
	.string "challenge. There is no record…$"
# 1227 "data/maps/Route110/scripts.pory"

# 1228 "data/maps/Route110/scripts.pory"
Route110_Text_ImagineSeeingYouHere:
# 1229 "data/maps/Route110/scripts.pory"
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
# 1230 "data/maps/Route110/scripts.pory"
	.string "Imagine seeing you here!\p"
# 1231 "data/maps/Route110/scripts.pory"
	.string "And where might my {RIVAL} be?$"
# 1232 "data/maps/Route110/scripts.pory"

# 1233 "data/maps/Route110/scripts.pory"
Route110_Text_HeardYouInstallMatchCall:
# 1234 "data/maps/Route110/scripts.pory"
	.string "Oh, I see!\n"
# 1235 "data/maps/Route110/scripts.pory"
	.string "You two are running separately.\l"
# 1236 "data/maps/Route110/scripts.pory"
	.string "Well, that's fine.\p"
# 1237 "data/maps/Route110/scripts.pory"
	.string "Oh, yes, I heard that your POKéNAV\n"
# 1238 "data/maps/Route110/scripts.pory"
	.string "had the MATCH CALL system installed.\p"
# 1239 "data/maps/Route110/scripts.pory"
	.string "Well, then, I should register you in\n"
# 1240 "data/maps/Route110/scripts.pory"
	.string "my POKéNAV as well.\p"
# 1241 "data/maps/Route110/scripts.pory"
	.string "That way, even when we're apart,\n"
# 1242 "data/maps/Route110/scripts.pory"
	.string "I can rate your POKéDEX anytime.\p"
# 1243 "data/maps/Route110/scripts.pory"
	.string "… … … … … …$"
# 1244 "data/maps/Route110/scripts.pory"

# 1245 "data/maps/Route110/scripts.pory"
Route110_Text_RegisteredBirchInPokenav:
# 1246 "data/maps/Route110/scripts.pory"
	.string "Registered PROF. BIRCH\n"
# 1247 "data/maps/Route110/scripts.pory"
	.string "in the POKéNAV.$"
# 1248 "data/maps/Route110/scripts.pory"

# 1249 "data/maps/Route110/scripts.pory"
Route110_Text_KeepAnEyeOutForRival:
# 1250 "data/maps/Route110/scripts.pory"
	.string "PROF. BIRCH: {PLAYER}{KUN}…\p"
# 1251 "data/maps/Route110/scripts.pory"
	.string "Please keep an eye out for my {RIVAL}.\n"
# 1252 "data/maps/Route110/scripts.pory"
	.string "… … … … … …\p"
# 1253 "data/maps/Route110/scripts.pory"
	.string "Well, I had better get going.\n"
# 1254 "data/maps/Route110/scripts.pory"
	.string "See you again, {PLAYER}{KUN}!$"
