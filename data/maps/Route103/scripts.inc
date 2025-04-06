# 1 "data/maps/Route103/scripts.pory"

# 2 "data/maps/Route103/scripts.pory"
.set LOCALID_ANDREW, 6
# 3 "data/maps/Route103/scripts.pory"
.set LOCALID_MIGUEL, 12
# 4 "data/maps/Route103/scripts.pory"
.set LOCALID_AMY, 5
# 5 "data/maps/Route103/scripts.pory"
.set LOCALID_RHETT, 16
# 6 "data/maps/Route103/scripts.pory"
.set LOCALID_MARCOS, 17
# 7 "data/maps/Route103/scripts.pory"

# 8 "data/maps/Route103/scripts.pory"
Route103_MapScripts::
# 9 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
# 10 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
# 11 "data/maps/Route103/scripts.pory"
	.byte 0
# 12 "data/maps/Route103/scripts.pory"

# 13 "data/maps/Route103/scripts.pory"
Route103_OnTransition:
# 14 "data/maps/Route103/scripts.pory"
	call_if_set FLAG_ABNORMAL_WEATHER_SUN, Common_EventScript_SetWeatherIntenseSun
# 15 "data/maps/Route103/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 16 "data/maps/Route103/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 17 "data/maps/Route103/scripts.pory"
	end
# 18 "data/maps/Route103/scripts.pory"

# 19 "data/maps/Route103/scripts.pory"
Route103_OnLoad:
# 20 "data/maps/Route103/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
# 21 "data/maps/Route103/scripts.pory"
	end
# 22 "data/maps/Route103/scripts.pory"

# 23 "data/maps/Route103/scripts.pory"
Route103_EventScript_OpenAlteringCave::
# 24 "data/maps/Route103/scripts.pory"
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
# 25 "data/maps/Route103/scripts.pory"
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
# 26 "data/maps/Route103/scripts.pory"
	return
# 27 "data/maps/Route103/scripts.pory"

# 28 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rival::
# 29 "data/maps/Route103/scripts.pory"
	lockall
# 30 "data/maps/Route103/scripts.pory"
	checkplayergender
# 31 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
# 32 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan
# 33 "data/maps/Route103/scripts.pory"
	end
# 34 "data/maps/Route103/scripts.pory"

# 35 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalMay::
# 36 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
# 37 "data/maps/Route103/scripts.pory"
	closemessage
# 38 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 39 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 40 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 41 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 42 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 43 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 44 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 45 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
# 46 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 47 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartMayBattleTreecko
# 48 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartMayBattleTorchic
# 49 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartMayBattleMudkip
# 50 "data/maps/Route103/scripts.pory"
	end
# 51 "data/maps/Route103/scripts.pory"

# 52 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendan::
# 53 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
# 54 "data/maps/Route103/scripts.pory"
	closemessage
# 55 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 56 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 57 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 58 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 59 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 60 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 61 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 62 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 63 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 64 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartBrendanBattleTreecko
# 65 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartBrendanBattleTorchic
# 66 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartBrendanBattleMudkip
# 67 "data/maps/Route103/scripts.pory"
	end
# 68 "data/maps/Route103/scripts.pory"

# 69 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTreecko::
# 70 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
# 71 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 72 "data/maps/Route103/scripts.pory"
	end
# 73 "data/maps/Route103/scripts.pory"

# 74 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTorchic::
# 75 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
# 76 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 77 "data/maps/Route103/scripts.pory"
	end
# 78 "data/maps/Route103/scripts.pory"

# 79 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleMudkip::
# 80 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
# 81 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 82 "data/maps/Route103/scripts.pory"
	end
# 83 "data/maps/Route103/scripts.pory"

# 84 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTreecko::
# 85 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
# 86 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 87 "data/maps/Route103/scripts.pory"
	end
# 88 "data/maps/Route103/scripts.pory"

# 89 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTorchic::
# 90 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
# 91 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 92 "data/maps/Route103/scripts.pory"
	end
# 93 "data/maps/Route103/scripts.pory"

# 94 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleMudkip::
# 95 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
# 96 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 97 "data/maps/Route103/scripts.pory"
	end
# 98 "data/maps/Route103/scripts.pory"

# 99 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle::
# 100 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 101 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 102 "data/maps/Route103/scripts.pory"
	end
# 103 "data/maps/Route103/scripts.pory"

# 104 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle::
# 105 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 106 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 107 "data/maps/Route103/scripts.pory"
	end
# 108 "data/maps/Route103/scripts.pory"

# 109 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 110 "data/maps/Route103/scripts.pory"
	closemessage
# 111 "data/maps/Route103/scripts.pory"
	switch VAR_FACING
# 112 "data/maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 113 "data/maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 114 "data/maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 115 "data/maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 116 "data/maps/Route103/scripts.pory"
	end
# 117 "data/maps/Route103/scripts.pory"

# 118 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 119 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 120 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 121 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 122 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 123 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 124 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 125 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 126 "data/maps/Route103/scripts.pory"
	end
# 127 "data/maps/Route103/scripts.pory"

# 128 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 129 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 130 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 131 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 132 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 133 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 134 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 135 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 136 "data/maps/Route103/scripts.pory"
	end
# 137 "data/maps/Route103/scripts.pory"

# 138 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 139 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 140 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 141 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 142 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 143 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 144 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 145 "data/maps/Route103/scripts.pory"
	end
# 146 "data/maps/Route103/scripts.pory"

# 147 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 148 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 149 "data/maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 150 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 151 "data/maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 152 "data/maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 153 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 154 "data/maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 155 "data/maps/Route103/scripts.pory"
	fadedefaultbgm
# 156 "data/maps/Route103/scripts.pory"
	releaseall
# 157 "data/maps/Route103/scripts.pory"
	end
# 158 "data/maps/Route103/scripts.pory"

# 159 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 160 "data/maps/Route103/scripts.pory"
	walk_left
# 161 "data/maps/Route103/scripts.pory"
	walk_down
# 162 "data/maps/Route103/scripts.pory"
	step_end
# 163 "data/maps/Route103/scripts.pory"

# 164 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 165 "data/maps/Route103/scripts.pory"
	jump_2_down
# 166 "data/maps/Route103/scripts.pory"
	delay_16
# 167 "data/maps/Route103/scripts.pory"
	walk_down
# 168 "data/maps/Route103/scripts.pory"
	walk_down
# 169 "data/maps/Route103/scripts.pory"
	walk_down
# 170 "data/maps/Route103/scripts.pory"
	walk_down
# 171 "data/maps/Route103/scripts.pory"
	step_end
# 172 "data/maps/Route103/scripts.pory"

# 173 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 174 "data/maps/Route103/scripts.pory"
	delay_16
# 175 "data/maps/Route103/scripts.pory"
	delay_4
# 176 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 177 "data/maps/Route103/scripts.pory"
	delay_16
# 178 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 179 "data/maps/Route103/scripts.pory"
	step_end
# 180 "data/maps/Route103/scripts.pory"

# 181 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 182 "data/maps/Route103/scripts.pory"
	walk_down
# 183 "data/maps/Route103/scripts.pory"
	step_end
# 184 "data/maps/Route103/scripts.pory"

# 185 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 186 "data/maps/Route103/scripts.pory"
	jump_2_down
# 187 "data/maps/Route103/scripts.pory"
	delay_16
# 188 "data/maps/Route103/scripts.pory"
	walk_down
# 189 "data/maps/Route103/scripts.pory"
	walk_down
# 190 "data/maps/Route103/scripts.pory"
	walk_down
# 191 "data/maps/Route103/scripts.pory"
	step_end
# 192 "data/maps/Route103/scripts.pory"

# 193 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 194 "data/maps/Route103/scripts.pory"
	delay_16
# 195 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 196 "data/maps/Route103/scripts.pory"
	step_end
# 197 "data/maps/Route103/scripts.pory"

# 198 "data/maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 199 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 200 "data/maps/Route103/scripts.pory"
	end
# 201 "data/maps/Route103/scripts.pory"

# 202 "data/maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 203 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 204 "data/maps/Route103/scripts.pory"
	end
# 205 "data/maps/Route103/scripts.pory"

# 206 "data/maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 207 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 208 "data/maps/Route103/scripts.pory"
	end
# 209 "data/maps/Route103/scripts.pory"

# 210 "data/maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 211 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 212 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 213 "data/maps/Route103/scripts.pory"
	end
# 214 "data/maps/Route103/scripts.pory"

# 215 "data/maps/Route103/scripts.pory"
Route103_EventScript_AmyLiv::
# 216 "data/maps/Route103/scripts.pory"
lockall
# 217 "data/maps/Route103/scripts.pory"
setvar VAR_0x8008, LOCALID_AMY
# 218 "data/maps/Route103/scripts.pory"
playse SE_PIN
# 219 "data/maps/Route103/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 220 "data/maps/Route103/scripts.pory"
waitmovement 0
# 221 "data/maps/Route103/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 222 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 223 "data/maps/Route103/scripts.pory"
waitmovement 0
# 224 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_AmyIntro MSGBOX_AUTOCLOSE
# 225 "data/maps/Route103/scripts.pory"
goto Route103_EventScript_AmyLivDoMultiBattle
# 226 "data/maps/Route103/scripts.pory"
releaseall
# 227 "data/maps/Route103/scripts.pory"
end
# 228 "data/maps/Route103/scripts.pory"

# 229 "data/maps/Route103/scripts.pory"
Route103_EventScript_AmyLivDoMultiBattle::
# 230 "data/maps/Route103/scripts.pory"
playbgm MUS_ROUTE101, TRUE
# 231 "data/maps/Route103/scripts.pory"
multi_2p_vs_1 TRAINER_AMY_AND_LIV_1, Route103_Text_AmyDefeated, PARTNER_EMMIE
# 232 "data/maps/Route103/scripts.pory"
switch VAR_RESULT
# 233 "data/maps/Route103/scripts.pory"
case 1, Route103_EventScript_AmyLivVictory
# 234 "data/maps/Route103/scripts.pory"
fadescreen FADE_TO_BLACK
# 235 "data/maps/Route103/scripts.pory"
special SetCB2WhiteOut
# 236 "data/maps/Route103/scripts.pory"
waitstate
# 237 "data/maps/Route103/scripts.pory"

# 238 "data/maps/Route103/scripts.pory"
Route103_EventScript_AmyLivVictory::
# 239 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 240 "data/maps/Route103/scripts.pory"
waitmovement 0
# 241 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 242 "data/maps/Route103/scripts.pory"
addvar VAR_ROUTE103_STATE, 1
# 243 "data/maps/Route103/scripts.pory"
end
# 244 "data/maps/Route103/scripts.pory"

# 245 "data/maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 246 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 247 "data/maps/Route103/scripts.pory"
	end
# 248 "data/maps/Route103/scripts.pory"

# 249 "data/maps/Route103/scripts.pory"
Route103_EventScript_AmyRegisterMatchCallAfterBattle::
# 250 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 251 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 252 "data/maps/Route103/scripts.pory"
	release
# 253 "data/maps/Route103/scripts.pory"
	end
# 254 "data/maps/Route103/scripts.pory"

# 255 "data/maps/Route103/scripts.pory"
Route103_EventScript_AmyRematch::
# 256 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 257 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 258 "data/maps/Route103/scripts.pory"
	end
# 259 "data/maps/Route103/scripts.pory"

# 260 "data/maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 261 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 262 "data/maps/Route103/scripts.pory"
	end
# 263 "data/maps/Route103/scripts.pory"

# 264 "data/maps/Route103/scripts.pory"
Route103_EventScript_LivRegisterMatchCallAfterBattle::
# 265 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 266 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 267 "data/maps/Route103/scripts.pory"
	release
# 268 "data/maps/Route103/scripts.pory"
	end
# 269 "data/maps/Route103/scripts.pory"

# 270 "data/maps/Route103/scripts.pory"
Route103_EventScript_LivRematch::
# 271 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 272 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 273 "data/maps/Route103/scripts.pory"
	end
# 274 "data/maps/Route103/scripts.pory"

# 275 "data/maps/Route103/scripts.pory"
Route103_EventScript_AndrewMiguel::
# 276 "data/maps/Route103/scripts.pory"
lockall
# 277 "data/maps/Route103/scripts.pory"
setvar VAR_0x8008, LOCALID_ANDREW
# 278 "data/maps/Route103/scripts.pory"
playse SE_PIN
# 279 "data/maps/Route103/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 280 "data/maps/Route103/scripts.pory"
waitmovement 0
# 281 "data/maps/Route103/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 282 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 283 "data/maps/Route103/scripts.pory"
waitmovement 0
# 284 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_AndrewIntro MSGBOX_AUTOCLOSE
# 285 "data/maps/Route103/scripts.pory"
setvar VAR_0x8008, LOCALID_MIGUEL
# 286 "data/maps/Route103/scripts.pory"
playse SE_PIN
# 287 "data/maps/Route103/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 288 "data/maps/Route103/scripts.pory"
waitmovement 0
# 289 "data/maps/Route103/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 290 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 291 "data/maps/Route103/scripts.pory"
waitmovement 0
# 292 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_MiguelIntro MSGBOX_AUTOCLOSE
# 293 "data/maps/Route103/scripts.pory"
goto Route103_EventScript_AndrewMiguelDoMultiBattle
# 294 "data/maps/Route103/scripts.pory"
releaseall
# 295 "data/maps/Route103/scripts.pory"
end
# 296 "data/maps/Route103/scripts.pory"

# 297 "data/maps/Route103/scripts.pory"
Route103_EventScript_AndrewMiguelDoMultiBattle::
# 298 "data/maps/Route103/scripts.pory"
playbgm MUS_ROUTE101, TRUE
# 299 "data/maps/Route103/scripts.pory"
multi_2p_vs_2 TRAINER_ANDREW, Route103_Text_AndrewDefeated, TRAINER_MIGUEL_1, Route103_Text_MiguelDefeated, PARTNER_EMMIE
# 300 "data/maps/Route103/scripts.pory"
switch VAR_RESULT
# 301 "data/maps/Route103/scripts.pory"
case 1, Route103_EventScript_AndrewMiguelVictory
# 302 "data/maps/Route103/scripts.pory"
fadescreen FADE_TO_BLACK
# 303 "data/maps/Route103/scripts.pory"
special SetCB2WhiteOut
# 304 "data/maps/Route103/scripts.pory"
waitstate
# 305 "data/maps/Route103/scripts.pory"

# 306 "data/maps/Route103/scripts.pory"
Route103_EventScript_AndrewMiguelVictory::
# 307 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 308 "data/maps/Route103/scripts.pory"
waitmovement 0
# 309 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 310 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 311 "data/maps/Route103/scripts.pory"
waitmovement 0
# 312 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_MiguelPostBattle, MSGBOX_AUTOCLOSE
# 313 "data/maps/Route103/scripts.pory"
addvar VAR_ROUTE103_STATE, 1
# 314 "data/maps/Route103/scripts.pory"
end
# 315 "data/maps/Route103/scripts.pory"

# 316 "data/maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 317 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 318 "data/maps/Route103/scripts.pory"
	end
# 319 "data/maps/Route103/scripts.pory"

# 320 "data/maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 321 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 322 "data/maps/Route103/scripts.pory"
	release
# 323 "data/maps/Route103/scripts.pory"
	end
# 324 "data/maps/Route103/scripts.pory"

# 325 "data/maps/Route103/scripts.pory"
Route103_EventScript_MiguelRegisterMatchCallAfterBattle::
# 326 "data/maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 327 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 328 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 329 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 330 "data/maps/Route103/scripts.pory"
	release
# 331 "data/maps/Route103/scripts.pory"
	end
# 332 "data/maps/Route103/scripts.pory"

# 333 "data/maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 334 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 335 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 336 "data/maps/Route103/scripts.pory"
	end
# 337 "data/maps/Route103/scripts.pory"

# 338 "data/maps/Route103/scripts.pory"
Route103_EventScript_MarcosRhett::
# 339 "data/maps/Route103/scripts.pory"
lockall
# 340 "data/maps/Route103/scripts.pory"
setvar VAR_0x8008, LOCALID_MARCOS
# 341 "data/maps/Route103/scripts.pory"
playse SE_PIN
# 342 "data/maps/Route103/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 343 "data/maps/Route103/scripts.pory"
waitmovement 0
# 344 "data/maps/Route103/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 345 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 346 "data/maps/Route103/scripts.pory"
waitmovement 0
# 347 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_MarcosIntro MSGBOX_AUTOCLOSE
# 348 "data/maps/Route103/scripts.pory"
setvar VAR_0x8008, LOCALID_RHETT
# 349 "data/maps/Route103/scripts.pory"
playse SE_PIN
# 350 "data/maps/Route103/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 351 "data/maps/Route103/scripts.pory"
waitmovement 0
# 352 "data/maps/Route103/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 353 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 354 "data/maps/Route103/scripts.pory"
waitmovement 0
# 355 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_RhettIntro MSGBOX_AUTOCLOSE
# 356 "data/maps/Route103/scripts.pory"
goto Route103_EventScript_MarcosRhettDoMultiBattle
# 357 "data/maps/Route103/scripts.pory"
releaseall
# 358 "data/maps/Route103/scripts.pory"
end
# 359 "data/maps/Route103/scripts.pory"

# 360 "data/maps/Route103/scripts.pory"
Route103_EventScript_MarcosRhettDoMultiBattle::
# 361 "data/maps/Route103/scripts.pory"
playbgm MUS_ROUTE101, TRUE
# 362 "data/maps/Route103/scripts.pory"
multi_2p_vs_2 TRAINER_MARCOS, Route103_Text_MarcosDefeated, TRAINER_RHETT, Route103_Text_RhettDefeated, PARTNER_EMMIE
# 363 "data/maps/Route103/scripts.pory"
switch VAR_RESULT
# 364 "data/maps/Route103/scripts.pory"
case 1, Route103_EventScript_MarcosRhettVictory
# 365 "data/maps/Route103/scripts.pory"
fadescreen FADE_TO_BLACK
# 366 "data/maps/Route103/scripts.pory"
special SetCB2WhiteOut
# 367 "data/maps/Route103/scripts.pory"
waitstate
# 368 "data/maps/Route103/scripts.pory"

# 369 "data/maps/Route103/scripts.pory"
Route103_EventScript_MarcosRhettVictory::
# 370 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 371 "data/maps/Route103/scripts.pory"
waitmovement 0
# 372 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 373 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 374 "data/maps/Route103/scripts.pory"
waitmovement 0
# 375 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 376 "data/maps/Route103/scripts.pory"
addvar VAR_ROUTE103_STATE, 1
# 377 "data/maps/Route103/scripts.pory"
end
# 378 "data/maps/Route103/scripts.pory"

# 379 "data/maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 380 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 381 "data/maps/Route103/scripts.pory"
	end
# 382 "data/maps/Route103/scripts.pory"

# 383 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 384 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 385 "data/maps/Route103/scripts.pory"
	end
# 386 "data/maps/Route103/scripts.pory"

# 387 "data/maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 388 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 389 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 390 "data/maps/Route103/scripts.pory"
	end
# 391 "data/maps/Route103/scripts.pory"

# 392 "data/maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 393 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 394 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 395 "data/maps/Route103/scripts.pory"
	end
# 396 "data/maps/Route103/scripts.pory"

# 397 "data/maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon:
# 398 "data/maps/Route103/scripts.pory"
	.string "MAY: Let's see… The POKéMON found\n"
# 399 "data/maps/Route103/scripts.pory"
	.string "on ROUTE 103 include…$"
# 400 "data/maps/Route103/scripts.pory"

# 401 "data/maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle:
# 402 "data/maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 403 "data/maps/Route103/scripts.pory"
	.string "…Oh, I see, my dad gave you\n"
# 404 "data/maps/Route103/scripts.pory"
	.string "a POKéMON as a gift.\p"
# 405 "data/maps/Route103/scripts.pory"
	.string "Since we're here, let's have a quick\n"
# 406 "data/maps/Route103/scripts.pory"
	.string "battle!\p"
# 407 "data/maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 408 "data/maps/Route103/scripts.pory"
	.string "a TRAINER is like.$"
# 409 "data/maps/Route103/scripts.pory"

# 410 "data/maps/Route103/scripts.pory"
Route103_Text_MayDefeated:
# 411 "data/maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 412 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 413 "data/maps/Route103/scripts.pory"

# 414 "data/maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack:
# 415 "data/maps/Route103/scripts.pory"
	.string "MAY: I think I know why my dad has\n"
# 416 "data/maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 417 "data/maps/Route103/scripts.pory"
	.string "I mean, you just got that POKéMON,\n"
# 418 "data/maps/Route103/scripts.pory"
	.string "but it already likes you.\p"
# 419 "data/maps/Route103/scripts.pory"
	.string "You might be able to befriend any\n"
# 420 "data/maps/Route103/scripts.pory"
	.string "kind of POKéMON easily.\p"
# 421 "data/maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 422 "data/maps/Route103/scripts.pory"
	.string "the LAB.$"
# 423 "data/maps/Route103/scripts.pory"

# 424 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon:
# 425 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 426 "data/maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 427 "data/maps/Route103/scripts.pory"

# 428 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle:
# 429 "data/maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 430 "data/maps/Route103/scripts.pory"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
# 431 "data/maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 432 "data/maps/Route103/scripts.pory"
	.string "battle?\p"
# 433 "data/maps/Route103/scripts.pory"
	.string "I'll teach you what being a TRAINER's\n"
# 434 "data/maps/Route103/scripts.pory"
	.string "about!$"
# 435 "data/maps/Route103/scripts.pory"

# 436 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated:
# 437 "data/maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 438 "data/maps/Route103/scripts.pory"

# 439 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack:
# 440 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 441 "data/maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 442 "data/maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 443 "data/maps/Route103/scripts.pory"
	.string "Look, your POKéMON already likes you,\n"
# 444 "data/maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 445 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 446 "data/maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 447 "data/maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 448 "data/maps/Route103/scripts.pory"

# 449 "data/maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 450 "data/maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
# 451 "data/maps/Route103/scripts.pory"
	.string "I should have brought a POTION…$"
# 452 "data/maps/Route103/scripts.pory"

# 453 "data/maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 454 "data/maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 455 "data/maps/Route103/scripts.pory"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
# 456 "data/maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 457 "data/maps/Route103/scripts.pory"

# 458 "data/maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 459 "data/maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 460 "data/maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"
# 461 "data/maps/Route103/scripts.pory"

# 462 "data/maps/Route103/scripts.pory"
Route103_Text_ReadyToFight:
# 463 "data/maps/Route103/scripts.pory"
	.string "Are you ready?$"
# 464 "data/maps/Route103/scripts.pory"

# 465 "data/maps/Route103/scripts.pory"
Route103_Text_ComeBackWhenReady:
# 466 "data/maps/Route103/scripts.pory"
	.string "Come back when you're ready.$"
