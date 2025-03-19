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
	call Common_EventScript_SetupRivalGfxId
# 15 "data/maps/Route103/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 16 "data/maps/Route103/scripts.pory"
	end
# 17 "data/maps/Route103/scripts.pory"

# 18 "data/maps/Route103/scripts.pory"
Route103_OnLoad:
# 19 "data/maps/Route103/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
# 20 "data/maps/Route103/scripts.pory"
	end
# 21 "data/maps/Route103/scripts.pory"

# 22 "data/maps/Route103/scripts.pory"
Route103_EventScript_OpenAlteringCave::
# 23 "data/maps/Route103/scripts.pory"
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
# 24 "data/maps/Route103/scripts.pory"
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
# 25 "data/maps/Route103/scripts.pory"
	return
# 26 "data/maps/Route103/scripts.pory"

# 27 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rival::
# 28 "data/maps/Route103/scripts.pory"
	lockall
# 29 "data/maps/Route103/scripts.pory"
	checkplayergender
# 30 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
# 31 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan
# 32 "data/maps/Route103/scripts.pory"
	end
# 33 "data/maps/Route103/scripts.pory"

# 34 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalMay::
# 35 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
# 36 "data/maps/Route103/scripts.pory"
	closemessage
# 37 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 38 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 39 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 40 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 41 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 42 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 43 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 44 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
# 45 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 46 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartMayBattleTreecko
# 47 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartMayBattleTorchic
# 48 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartMayBattleMudkip
# 49 "data/maps/Route103/scripts.pory"
	end
# 50 "data/maps/Route103/scripts.pory"

# 51 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalBrendan::
# 52 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
# 53 "data/maps/Route103/scripts.pory"
	closemessage
# 54 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 55 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 56 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 57 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 58 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 59 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 60 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 61 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
# 62 "data/maps/Route103/scripts.pory"
	switch VAR_STARTER_MON
# 63 "data/maps/Route103/scripts.pory"
	case 0, Route103_EventScript_StartBrendanBattleTreecko
# 64 "data/maps/Route103/scripts.pory"
	case 1, Route103_EventScript_StartBrendanBattleTorchic
# 65 "data/maps/Route103/scripts.pory"
	case 2, Route103_EventScript_StartBrendanBattleMudkip
# 66 "data/maps/Route103/scripts.pory"
	end
# 67 "data/maps/Route103/scripts.pory"

# 68 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTreecko::
# 69 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
# 70 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 71 "data/maps/Route103/scripts.pory"
	end
# 72 "data/maps/Route103/scripts.pory"

# 73 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleTorchic::
# 74 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
# 75 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 76 "data/maps/Route103/scripts.pory"
	end
# 77 "data/maps/Route103/scripts.pory"

# 78 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartMayBattleMudkip::
# 79 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
# 80 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterMayBattle
# 81 "data/maps/Route103/scripts.pory"
	end
# 82 "data/maps/Route103/scripts.pory"

# 83 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTreecko::
# 84 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
# 85 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 86 "data/maps/Route103/scripts.pory"
	end
# 87 "data/maps/Route103/scripts.pory"

# 88 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleTorchic::
# 89 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
# 90 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 91 "data/maps/Route103/scripts.pory"
	end
# 92 "data/maps/Route103/scripts.pory"

# 93 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrendanBattleMudkip::
# 94 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
# 95 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrendanBattle
# 96 "data/maps/Route103/scripts.pory"
	end
# 97 "data/maps/Route103/scripts.pory"

# 98 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterMayBattle::
# 99 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
# 100 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 101 "data/maps/Route103/scripts.pory"
	end
# 102 "data/maps/Route103/scripts.pory"

# 103 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterBrendanBattle::
# 104 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
# 105 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 106 "data/maps/Route103/scripts.pory"
	end
# 107 "data/maps/Route103/scripts.pory"

# 108 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 109 "data/maps/Route103/scripts.pory"
	closemessage
# 110 "data/maps/Route103/scripts.pory"
	switch VAR_FACING
# 111 "data/maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 112 "data/maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 113 "data/maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 114 "data/maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 115 "data/maps/Route103/scripts.pory"
	end
# 116 "data/maps/Route103/scripts.pory"

# 117 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 118 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 119 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 120 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 121 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 122 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 123 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 124 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 125 "data/maps/Route103/scripts.pory"
	end
# 126 "data/maps/Route103/scripts.pory"

# 127 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 128 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 129 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 130 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 131 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 132 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 133 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 134 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 135 "data/maps/Route103/scripts.pory"
	end
# 136 "data/maps/Route103/scripts.pory"

# 137 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 138 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 139 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 140 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 141 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 142 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 143 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 144 "data/maps/Route103/scripts.pory"
	end
# 145 "data/maps/Route103/scripts.pory"

# 146 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 147 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 148 "data/maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 149 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 150 "data/maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 151 "data/maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 152 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 153 "data/maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 154 "data/maps/Route103/scripts.pory"
	fadedefaultbgm
# 155 "data/maps/Route103/scripts.pory"
	releaseall
# 156 "data/maps/Route103/scripts.pory"
	end
# 157 "data/maps/Route103/scripts.pory"

# 158 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 159 "data/maps/Route103/scripts.pory"
	walk_left
# 160 "data/maps/Route103/scripts.pory"
	walk_down
# 161 "data/maps/Route103/scripts.pory"
	step_end
# 162 "data/maps/Route103/scripts.pory"

# 163 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 164 "data/maps/Route103/scripts.pory"
	jump_2_down
# 165 "data/maps/Route103/scripts.pory"
	delay_16
# 166 "data/maps/Route103/scripts.pory"
	walk_down
# 167 "data/maps/Route103/scripts.pory"
	walk_down
# 168 "data/maps/Route103/scripts.pory"
	walk_down
# 169 "data/maps/Route103/scripts.pory"
	walk_down
# 170 "data/maps/Route103/scripts.pory"
	step_end
# 171 "data/maps/Route103/scripts.pory"

# 172 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 173 "data/maps/Route103/scripts.pory"
	delay_16
# 174 "data/maps/Route103/scripts.pory"
	delay_4
# 175 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 176 "data/maps/Route103/scripts.pory"
	delay_16
# 177 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 178 "data/maps/Route103/scripts.pory"
	step_end
# 179 "data/maps/Route103/scripts.pory"

# 180 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 181 "data/maps/Route103/scripts.pory"
	walk_down
# 182 "data/maps/Route103/scripts.pory"
	step_end
# 183 "data/maps/Route103/scripts.pory"

# 184 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 185 "data/maps/Route103/scripts.pory"
	jump_2_down
# 186 "data/maps/Route103/scripts.pory"
	delay_16
# 187 "data/maps/Route103/scripts.pory"
	walk_down
# 188 "data/maps/Route103/scripts.pory"
	walk_down
# 189 "data/maps/Route103/scripts.pory"
	walk_down
# 190 "data/maps/Route103/scripts.pory"
	step_end
# 191 "data/maps/Route103/scripts.pory"

# 192 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 193 "data/maps/Route103/scripts.pory"
	delay_16
# 194 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 195 "data/maps/Route103/scripts.pory"
	step_end
# 196 "data/maps/Route103/scripts.pory"

# 197 "data/maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 198 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 199 "data/maps/Route103/scripts.pory"
	end
# 200 "data/maps/Route103/scripts.pory"

# 201 "data/maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 202 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 203 "data/maps/Route103/scripts.pory"
	end
# 204 "data/maps/Route103/scripts.pory"

# 205 "data/maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 206 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 207 "data/maps/Route103/scripts.pory"
	end
# 208 "data/maps/Route103/scripts.pory"

# 209 "data/maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 210 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 211 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 212 "data/maps/Route103/scripts.pory"
	end
# 213 "data/maps/Route103/scripts.pory"

# 214 "data/maps/Route103/scripts.pory"
Route103_EventScript_AmyLiv::
# 215 "data/maps/Route103/scripts.pory"
lockall
# 216 "data/maps/Route103/scripts.pory"
setvar VAR_0x8008, LOCALID_AMY
# 217 "data/maps/Route103/scripts.pory"
playse SE_PIN
# 218 "data/maps/Route103/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 219 "data/maps/Route103/scripts.pory"
waitmovement 0
# 220 "data/maps/Route103/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 221 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 222 "data/maps/Route103/scripts.pory"
waitmovement 0
# 223 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_AmyIntro MSGBOX_AUTOCLOSE
# 224 "data/maps/Route103/scripts.pory"
goto Route103_EventScript_AmyLivDoMultiBattle
# 225 "data/maps/Route103/scripts.pory"
releaseall
# 226 "data/maps/Route103/scripts.pory"
end
# 227 "data/maps/Route103/scripts.pory"

# 228 "data/maps/Route103/scripts.pory"
Route103_EventScript_AmyLivDoMultiBattle::
# 229 "data/maps/Route103/scripts.pory"
playbgm MUS_ROUTE101, TRUE
# 230 "data/maps/Route103/scripts.pory"
multi_2p_vs_1 TRAINER_AMY_AND_LIV_1, Route103_Text_AmyDefeated, PARTNER_EMMIE
# 231 "data/maps/Route103/scripts.pory"
switch VAR_RESULT
# 232 "data/maps/Route103/scripts.pory"
case 1, Route103_EventScript_AmyLivVictory
# 233 "data/maps/Route103/scripts.pory"
fadescreen FADE_TO_BLACK
# 234 "data/maps/Route103/scripts.pory"
special SetCB2WhiteOut
# 235 "data/maps/Route103/scripts.pory"
waitstate
# 236 "data/maps/Route103/scripts.pory"

# 237 "data/maps/Route103/scripts.pory"
Route103_EventScript_AmyLivVictory::
# 238 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 239 "data/maps/Route103/scripts.pory"
waitmovement 0
# 240 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 241 "data/maps/Route103/scripts.pory"
addvar VAR_ROUTE103_STATE, 1
# 242 "data/maps/Route103/scripts.pory"
end
# 243 "data/maps/Route103/scripts.pory"

# 244 "data/maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 245 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 246 "data/maps/Route103/scripts.pory"
	end
# 247 "data/maps/Route103/scripts.pory"

# 248 "data/maps/Route103/scripts.pory"
Route103_EventScript_AmyRegisterMatchCallAfterBattle::
# 249 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 250 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 251 "data/maps/Route103/scripts.pory"
	release
# 252 "data/maps/Route103/scripts.pory"
	end
# 253 "data/maps/Route103/scripts.pory"

# 254 "data/maps/Route103/scripts.pory"
Route103_EventScript_AmyRematch::
# 255 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 256 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 257 "data/maps/Route103/scripts.pory"
	end
# 258 "data/maps/Route103/scripts.pory"

# 259 "data/maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 260 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 261 "data/maps/Route103/scripts.pory"
	end
# 262 "data/maps/Route103/scripts.pory"

# 263 "data/maps/Route103/scripts.pory"
Route103_EventScript_LivRegisterMatchCallAfterBattle::
# 264 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 265 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 266 "data/maps/Route103/scripts.pory"
	release
# 267 "data/maps/Route103/scripts.pory"
	end
# 268 "data/maps/Route103/scripts.pory"

# 269 "data/maps/Route103/scripts.pory"
Route103_EventScript_LivRematch::
# 270 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 271 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 272 "data/maps/Route103/scripts.pory"
	end
# 273 "data/maps/Route103/scripts.pory"

# 274 "data/maps/Route103/scripts.pory"
Route103_EventScript_AndrewMiguel::
# 275 "data/maps/Route103/scripts.pory"
lockall
# 276 "data/maps/Route103/scripts.pory"
setvar VAR_0x8008, LOCALID_ANDREW
# 277 "data/maps/Route103/scripts.pory"
playse SE_PIN
# 278 "data/maps/Route103/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 279 "data/maps/Route103/scripts.pory"
waitmovement 0
# 280 "data/maps/Route103/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 281 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 282 "data/maps/Route103/scripts.pory"
waitmovement 0
# 283 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_AndrewIntro MSGBOX_AUTOCLOSE
# 284 "data/maps/Route103/scripts.pory"
setvar VAR_0x8008, LOCALID_MIGUEL
# 285 "data/maps/Route103/scripts.pory"
playse SE_PIN
# 286 "data/maps/Route103/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 287 "data/maps/Route103/scripts.pory"
waitmovement 0
# 288 "data/maps/Route103/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 289 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 290 "data/maps/Route103/scripts.pory"
waitmovement 0
# 291 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_MiguelIntro MSGBOX_AUTOCLOSE
# 292 "data/maps/Route103/scripts.pory"
goto Route103_EventScript_AndrewMiguelDoMultiBattle
# 293 "data/maps/Route103/scripts.pory"
releaseall
# 294 "data/maps/Route103/scripts.pory"
end
# 295 "data/maps/Route103/scripts.pory"

# 296 "data/maps/Route103/scripts.pory"
Route103_EventScript_AndrewMiguelDoMultiBattle::
# 297 "data/maps/Route103/scripts.pory"
playbgm MUS_ROUTE101, TRUE
# 298 "data/maps/Route103/scripts.pory"
multi_2p_vs_2 TRAINER_ANDREW, Route103_Text_AndrewDefeated, TRAINER_MIGUEL_1, Route103_Text_MiguelDefeated, PARTNER_EMMIE
# 299 "data/maps/Route103/scripts.pory"
switch VAR_RESULT
# 300 "data/maps/Route103/scripts.pory"
case 1, Route103_EventScript_AndrewMiguelVictory
# 301 "data/maps/Route103/scripts.pory"
fadescreen FADE_TO_BLACK
# 302 "data/maps/Route103/scripts.pory"
special SetCB2WhiteOut
# 303 "data/maps/Route103/scripts.pory"
waitstate
# 304 "data/maps/Route103/scripts.pory"

# 305 "data/maps/Route103/scripts.pory"
Route103_EventScript_AndrewMiguelVictory::
# 306 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 307 "data/maps/Route103/scripts.pory"
waitmovement 0
# 308 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 309 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 310 "data/maps/Route103/scripts.pory"
waitmovement 0
# 311 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_MiguelPostBattle, MSGBOX_AUTOCLOSE
# 312 "data/maps/Route103/scripts.pory"
addvar VAR_ROUTE103_STATE, 1
# 313 "data/maps/Route103/scripts.pory"
end
# 314 "data/maps/Route103/scripts.pory"

# 315 "data/maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 316 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 317 "data/maps/Route103/scripts.pory"
	end
# 318 "data/maps/Route103/scripts.pory"

# 319 "data/maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 320 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 321 "data/maps/Route103/scripts.pory"
	release
# 322 "data/maps/Route103/scripts.pory"
	end
# 323 "data/maps/Route103/scripts.pory"

# 324 "data/maps/Route103/scripts.pory"
Route103_EventScript_MiguelRegisterMatchCallAfterBattle::
# 325 "data/maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 326 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 327 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 328 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 329 "data/maps/Route103/scripts.pory"
	release
# 330 "data/maps/Route103/scripts.pory"
	end
# 331 "data/maps/Route103/scripts.pory"

# 332 "data/maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 333 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 334 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 335 "data/maps/Route103/scripts.pory"
	end
# 336 "data/maps/Route103/scripts.pory"

# 337 "data/maps/Route103/scripts.pory"
Route103_EventScript_MarcosRhett::
# 338 "data/maps/Route103/scripts.pory"
lockall
# 339 "data/maps/Route103/scripts.pory"
setvar VAR_0x8008, LOCALID_MARCOS
# 340 "data/maps/Route103/scripts.pory"
playse SE_PIN
# 341 "data/maps/Route103/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 342 "data/maps/Route103/scripts.pory"
waitmovement 0
# 343 "data/maps/Route103/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 344 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 345 "data/maps/Route103/scripts.pory"
waitmovement 0
# 346 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_MarcosIntro MSGBOX_AUTOCLOSE
# 347 "data/maps/Route103/scripts.pory"
setvar VAR_0x8008, LOCALID_RHETT
# 348 "data/maps/Route103/scripts.pory"
playse SE_PIN
# 349 "data/maps/Route103/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 350 "data/maps/Route103/scripts.pory"
waitmovement 0
# 351 "data/maps/Route103/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 352 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 353 "data/maps/Route103/scripts.pory"
waitmovement 0
# 354 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_RhettIntro MSGBOX_AUTOCLOSE
# 355 "data/maps/Route103/scripts.pory"
goto Route103_EventScript_MarcosRhettDoMultiBattle
# 356 "data/maps/Route103/scripts.pory"
releaseall
# 357 "data/maps/Route103/scripts.pory"
end
# 358 "data/maps/Route103/scripts.pory"

# 359 "data/maps/Route103/scripts.pory"
Route103_EventScript_MarcosRhettDoMultiBattle::
# 360 "data/maps/Route103/scripts.pory"
playbgm MUS_ROUTE101, TRUE
# 361 "data/maps/Route103/scripts.pory"
multi_2p_vs_2 TRAINER_MARCOS, Route103_Text_MarcosDefeated, TRAINER_RHETT, Route103_Text_RhettDefeated, PARTNER_EMMIE
# 362 "data/maps/Route103/scripts.pory"
switch VAR_RESULT
# 363 "data/maps/Route103/scripts.pory"
case 1, Route103_EventScript_MarcosRhettVictory
# 364 "data/maps/Route103/scripts.pory"
fadescreen FADE_TO_BLACK
# 365 "data/maps/Route103/scripts.pory"
special SetCB2WhiteOut
# 366 "data/maps/Route103/scripts.pory"
waitstate
# 367 "data/maps/Route103/scripts.pory"

# 368 "data/maps/Route103/scripts.pory"
Route103_EventScript_MarcosRhettVictory::
# 369 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 370 "data/maps/Route103/scripts.pory"
waitmovement 0
# 371 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 372 "data/maps/Route103/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 373 "data/maps/Route103/scripts.pory"
waitmovement 0
# 374 "data/maps/Route103/scripts.pory"
msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 375 "data/maps/Route103/scripts.pory"
addvar VAR_ROUTE103_STATE, 1
# 376 "data/maps/Route103/scripts.pory"
end
# 377 "data/maps/Route103/scripts.pory"

# 378 "data/maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 379 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 380 "data/maps/Route103/scripts.pory"
	end
# 381 "data/maps/Route103/scripts.pory"

# 382 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 383 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 384 "data/maps/Route103/scripts.pory"
	end
# 385 "data/maps/Route103/scripts.pory"

# 386 "data/maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 387 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 388 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 389 "data/maps/Route103/scripts.pory"
	end
# 390 "data/maps/Route103/scripts.pory"

# 391 "data/maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 392 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 393 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 394 "data/maps/Route103/scripts.pory"
	end
# 395 "data/maps/Route103/scripts.pory"

# 396 "data/maps/Route103/scripts.pory"
Route103_Text_MayRoute103Pokemon:
# 397 "data/maps/Route103/scripts.pory"
	.string "MAY: Let's see… The POKéMON found\n"
# 398 "data/maps/Route103/scripts.pory"
	.string "on ROUTE 103 include…$"
# 399 "data/maps/Route103/scripts.pory"

# 400 "data/maps/Route103/scripts.pory"
Route103_Text_MayLetsBattle:
# 401 "data/maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 402 "data/maps/Route103/scripts.pory"
	.string "…Oh, I see, my dad gave you\n"
# 403 "data/maps/Route103/scripts.pory"
	.string "a POKéMON as a gift.\p"
# 404 "data/maps/Route103/scripts.pory"
	.string "Since we're here, let's have a quick\n"
# 405 "data/maps/Route103/scripts.pory"
	.string "battle!\p"
# 406 "data/maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 407 "data/maps/Route103/scripts.pory"
	.string "a TRAINER is like.$"
# 408 "data/maps/Route103/scripts.pory"

# 409 "data/maps/Route103/scripts.pory"
Route103_Text_MayDefeated:
# 410 "data/maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 411 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 412 "data/maps/Route103/scripts.pory"

# 413 "data/maps/Route103/scripts.pory"
Route103_Text_MayTimeToHeadBack:
# 414 "data/maps/Route103/scripts.pory"
	.string "MAY: I think I know why my dad has\n"
# 415 "data/maps/Route103/scripts.pory"
	.string "an eye out for you now.\p"
# 416 "data/maps/Route103/scripts.pory"
	.string "I mean, you just got that POKéMON,\n"
# 417 "data/maps/Route103/scripts.pory"
	.string "but it already likes you.\p"
# 418 "data/maps/Route103/scripts.pory"
	.string "You might be able to befriend any\n"
# 419 "data/maps/Route103/scripts.pory"
	.string "kind of POKéMON easily.\p"
# 420 "data/maps/Route103/scripts.pory"
	.string "Well, it's time to head back to\n"
# 421 "data/maps/Route103/scripts.pory"
	.string "the LAB.$"
# 422 "data/maps/Route103/scripts.pory"

# 423 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanRoute103Pokemon:
# 424 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 425 "data/maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 426 "data/maps/Route103/scripts.pory"

# 427 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanLetsBattle:
# 428 "data/maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 429 "data/maps/Route103/scripts.pory"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
# 430 "data/maps/Route103/scripts.pory"
	.string "Since we're here, how about a little\n"
# 431 "data/maps/Route103/scripts.pory"
	.string "battle?\p"
# 432 "data/maps/Route103/scripts.pory"
	.string "I'll teach you what being a TRAINER's\n"
# 433 "data/maps/Route103/scripts.pory"
	.string "about!$"
# 434 "data/maps/Route103/scripts.pory"

# 435 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanDefeated:
# 436 "data/maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 437 "data/maps/Route103/scripts.pory"

# 438 "data/maps/Route103/scripts.pory"
Route103_Text_BrendanTimeToHeadBack:
# 439 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 440 "data/maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 441 "data/maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 442 "data/maps/Route103/scripts.pory"
	.string "Look, your POKéMON already likes you,\n"
# 443 "data/maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 444 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 445 "data/maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 446 "data/maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 447 "data/maps/Route103/scripts.pory"

# 448 "data/maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 449 "data/maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
# 450 "data/maps/Route103/scripts.pory"
	.string "I should have brought a POTION…$"
# 451 "data/maps/Route103/scripts.pory"

# 452 "data/maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 453 "data/maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 454 "data/maps/Route103/scripts.pory"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
# 455 "data/maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 456 "data/maps/Route103/scripts.pory"

# 457 "data/maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 458 "data/maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 459 "data/maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"
# 460 "data/maps/Route103/scripts.pory"

# 461 "data/maps/Route103/scripts.pory"
Route103_Text_ReadyToFight:
# 462 "data/maps/Route103/scripts.pory"
	.string "Are you ready?$"
# 463 "data/maps/Route103/scripts.pory"

# 464 "data/maps/Route103/scripts.pory"
Route103_Text_ComeBackWhenReady:
# 465 "data/maps/Route103/scripts.pory"
	.string "Come back when you're ready.$"
