# 1 "data/maps/Route104/scripts.pory"

# 2 "data/maps/Route104/scripts.pory"
@ NOTE: Route 104's sail to Dewford script references local IDs from Dewford's map.
# 3 "data/maps/Route104/scripts.pory"
@  These are labeled in DewfordTown/scripts.inc
# 4 "data/maps/Route104/scripts.pory"
.set LOCALID_RIVAL, 33
# 5 "data/maps/Route104/scripts.pory"
.set LOCALID_DARIAN, 32
# 6 "data/maps/Route104/scripts.pory"
.set LOCALID_IVAN, 8
# 7 "data/maps/Route104/scripts.pory"
.set LOCALID_HALEY, 34
# 8 "data/maps/Route104/scripts.pory"
.set LOCALID_BILLY, 27
# 9 "data/maps/Route104/scripts.pory"
.set LOCALID_CINDY, 25
# 10 "data/maps/Route104/scripts.pory"
.set LOCALID_WINSTON, 24
# 11 "data/maps/Route104/scripts.pory"
.set LOCALID_GINA, 22
# 12 "data/maps/Route104/scripts.pory"
.set LOCALID_MIA, 23
# 13 "data/maps/Route104/scripts.pory"

# 14 "data/maps/Route104/scripts.pory"
Route104_MapScripts::
# 15 "data/maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_OnFrame
# 16 "data/maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
# 17 "data/maps/Route104/scripts.pory"
	.byte 0
# 18 "data/maps/Route104/scripts.pory"

# 19 "data/maps/Route104/scripts.pory"
Route104_OnFrame:
# 20 "data/maps/Route104/scripts.pory"
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_StartSailToDewford
# 21 "data/maps/Route104/scripts.pory"
	.2byte 0
# 22 "data/maps/Route104/scripts.pory"

# 23 "data/maps/Route104/scripts.pory"
Route104_EventScript_StartSailToDewford::
# 24 "data/maps/Route104/scripts.pory"
	lockall
# 25 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_SailToDewford
# 26 "data/maps/Route104/scripts.pory"
	end
# 27 "data/maps/Route104/scripts.pory"

# 28 "data/maps/Route104/scripts.pory"
Route104_OnTransition:
# 29 "data/maps/Route104/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 30 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_TrySetRivalPos
# 31 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
# 32 "data/maps/Route104/scripts.pory"
	end
# 33 "data/maps/Route104/scripts.pory"

# 34 "data/maps/Route104/scripts.pory"
Route104_EventScript_ShowOrHideWhiteHerbFlorist::
# 35 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_HideWhiteHerbFlorist
# 36 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
# 37 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 38 "data/maps/Route104/scripts.pory"
	return
# 39 "data/maps/Route104/scripts.pory"

# 40 "data/maps/Route104/scripts.pory"
Route104_EventScript_HideWhiteHerbFlorist::
# 41 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 42 "data/maps/Route104/scripts.pory"
	return
# 43 "data/maps/Route104/scripts.pory"

# 44 "data/maps/Route104/scripts.pory"
Route104_EventScript_TrySetRivalPos::
# 45 "data/maps/Route104/scripts.pory"
	goto_if_ge VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_DontSetRivalPos
# 46 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, Route104_EventScript_DontSetRivalPos
# 47 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_DontSetRivalPos
# 48 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 17, 52
# 49 "data/maps/Route104/scripts.pory"
	return
# 50 "data/maps/Route104/scripts.pory"

# 51 "data/maps/Route104/scripts.pory"
Route104_EventScript_DontSetRivalPos::
# 52 "data/maps/Route104/scripts.pory"
	return
# 53 "data/maps/Route104/scripts.pory"

# 54 "data/maps/Route104/scripts.pory"
Route104_EventScript_Rival::
# 55 "data/maps/Route104/scripts.pory"
	lockall
# 56 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8008, 1
# 57 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 58 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 59 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 60 "data/maps/Route104/scripts.pory"

# 61 "data/maps/Route104/scripts.pory"
Route104_EventScript_RivalTrigger::
# 62 "data/maps/Route104/scripts.pory"
	lockall
# 63 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 64 "data/maps/Route104/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 65 "data/maps/Route104/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 66 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 67 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 68 "data/maps/Route104/scripts.pory"
	delay 10
# 69 "data/maps/Route104/scripts.pory"
	addobject LOCALID_RIVAL
# 70 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_RIVAL
# 71 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBackUp
# 72 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 73 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalExitBrineysCottage
# 74 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 75 "data/maps/Route104/scripts.pory"
	delay 20
# 76 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8008, 0
# 77 "data/maps/Route104/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 78 "data/maps/Route104/scripts.pory"
	playse SE_PIN
# 79 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 80 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 81 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 82 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 83 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 84 "data/maps/Route104/scripts.pory"

# 85 "data/maps/Route104/scripts.pory"
@ Unused, shares script with Rustboro encounter instead
# 86 "data/maps/Route104/scripts.pory"
Route104_EventScript_PlayRivalMusic::
# 87 "data/maps/Route104/scripts.pory"
	checkplayergender
# 88 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_PlayMayMusic
# 89 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_PlayBrendanMusic
# 90 "data/maps/Route104/scripts.pory"
	return
# 91 "data/maps/Route104/scripts.pory"

# 92 "data/maps/Route104/scripts.pory"
Route104_EventScript_PlayMayMusic::
# 93 "data/maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 94 "data/maps/Route104/scripts.pory"
	return
# 95 "data/maps/Route104/scripts.pory"

# 96 "data/maps/Route104/scripts.pory"
Route104_EventScript_PlayBrendanMusic::
# 97 "data/maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 98 "data/maps/Route104/scripts.pory"
	return
# 99 "data/maps/Route104/scripts.pory"

# 100 "data/maps/Route104/scripts.pory"
Route104_EventScript_RivalEncounter::
# 101 "data/maps/Route104/scripts.pory"
	checkplayergender
# 102 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_MayEncounter
# 103 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_BrendanEncounter
# 104 "data/maps/Route104/scripts.pory"
	end
# 105 "data/maps/Route104/scripts.pory"

# 106 "data/maps/Route104/scripts.pory"
Route104_EventScript_MayEncounter::
# 107 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_MayDefeated
# 108 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_MayAskToBattle
# 109 "data/maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 110 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayWeShouldRegister, MSGBOX_DEFAULT
# 111 "data/maps/Route104/scripts.pory"
	closemessage
# 112 "data/maps/Route104/scripts.pory"
	delay 30
# 113 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 114 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredMay, MSGBOX_DEFAULT
# 115 "data/maps/Route104/scripts.pory"
	waitfanfare
# 116 "data/maps/Route104/scripts.pory"
	closemessage
# 117 "data/maps/Route104/scripts.pory"
	delay 30
# 118 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 119 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
# 120 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 121 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHowsYourPokedex, MSGBOX_DEFAULT
# 122 "data/maps/Route104/scripts.pory"
	closemessage
# 123 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 124 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
# 125 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 126 "data/maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_RIVAL
# 127 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayMinesDecentLetsBattle, MSGBOX_YESNO
# 128 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 129 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 130 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 131 "data/maps/Route104/scripts.pory"
	releaseall
# 132 "data/maps/Route104/scripts.pory"
	end
# 133 "data/maps/Route104/scripts.pory"

# 134 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalWalkSlowLeft:
# 135 "data/maps/Route104/scripts.pory"
	walk_slow_left
# 136 "data/maps/Route104/scripts.pory"
	step_end
# 137 "data/maps/Route104/scripts.pory"

# 138 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalApproachPlayer:
# 139 "data/maps/Route104/scripts.pory"
	walk_down
# 140 "data/maps/Route104/scripts.pory"
	face_right
# 141 "data/maps/Route104/scripts.pory"
	step_end
# 142 "data/maps/Route104/scripts.pory"

# 143 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerFaceRival:
# 144 "data/maps/Route104/scripts.pory"
	delay_4
# 145 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 146 "data/maps/Route104/scripts.pory"
	step_end
# 147 "data/maps/Route104/scripts.pory"

# 148 "data/maps/Route104/scripts.pory"
Route104_EventScript_MayAskToBattle::
# 149 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayLetsBattle, MSGBOX_YESNO
# 150 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 151 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 152 "data/maps/Route104/scripts.pory"
	releaseall
# 153 "data/maps/Route104/scripts.pory"
	end
# 154 "data/maps/Route104/scripts.pory"

# 155 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMay::
# 156 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayIntro, MSGBOX_DEFAULT
# 157 "data/maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 158 "data/maps/Route104/scripts.pory"
	case 0, Route104_EventScript_BattleMayTreecko
# 159 "data/maps/Route104/scripts.pory"
	case 1, Route104_EventScript_BattleMayTorchic
# 160 "data/maps/Route104/scripts.pory"
	case 2, Route104_EventScript_BattleMayMudkip
# 161 "data/maps/Route104/scripts.pory"
	end
# 162 "data/maps/Route104/scripts.pory"

# 163 "data/maps/Route104/scripts.pory"
Route104_EventScript_MayDefeated::
# 164 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayPostBattle, MSGBOX_DEFAULT
# 165 "data/maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 166 "data/maps/Route104/scripts.pory"
	releaseall
# 167 "data/maps/Route104/scripts.pory"
	end
# 168 "data/maps/Route104/scripts.pory"

# 169 "data/maps/Route104/scripts.pory"
Route104_EventScript_RestoreMusic::
# 170 "data/maps/Route104/scripts.pory"
	savebgm MUS_DUMMY
# 171 "data/maps/Route104/scripts.pory"
	fadedefaultbgm
# 172 "data/maps/Route104/scripts.pory"
	return
# 173 "data/maps/Route104/scripts.pory"

# 174 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMayTreecko::
# 175 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, Route104_Text_MayDefeat
# 176 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 177 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 178 "data/maps/Route104/scripts.pory"
	end
# 179 "data/maps/Route104/scripts.pory"

# 180 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMayTorchic::
# 181 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, Route104_Text_MayDefeat
# 182 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 183 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 184 "data/maps/Route104/scripts.pory"
	end
# 185 "data/maps/Route104/scripts.pory"

# 186 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMayMudkip::
# 187 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, Route104_Text_MayDefeat
# 188 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 189 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 190 "data/maps/Route104/scripts.pory"
	end
# 191 "data/maps/Route104/scripts.pory"

# 192 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrendanEncounter::
# 193 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_BrendanDefeated
# 194 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_BrendanAskToBattle
# 195 "data/maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 196 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanWeShouldRegister, MSGBOX_DEFAULT
# 197 "data/maps/Route104/scripts.pory"
	closemessage
# 198 "data/maps/Route104/scripts.pory"
	delay 30
# 199 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 200 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 201 "data/maps/Route104/scripts.pory"
	waitfanfare
# 202 "data/maps/Route104/scripts.pory"
	closemessage
# 203 "data/maps/Route104/scripts.pory"
	delay 30
# 204 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 205 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
# 206 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 207 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanHowsYourPokedex, MSGBOX_DEFAULT
# 208 "data/maps/Route104/scripts.pory"
	closemessage
# 209 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 210 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
# 211 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 212 "data/maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_RIVAL
# 213 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanDoingGreatLetsBattle, MSGBOX_YESNO
# 214 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 215 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 216 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 217 "data/maps/Route104/scripts.pory"
	releaseall
# 218 "data/maps/Route104/scripts.pory"
	end
# 219 "data/maps/Route104/scripts.pory"

# 220 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrendanAskToBattle::
# 221 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanLetsBattle, MSGBOX_YESNO
# 222 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 223 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 224 "data/maps/Route104/scripts.pory"
	releaseall
# 225 "data/maps/Route104/scripts.pory"
	end
# 226 "data/maps/Route104/scripts.pory"

# 227 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendan::
# 228 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanIntro, MSGBOX_DEFAULT
# 229 "data/maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 230 "data/maps/Route104/scripts.pory"
	case 0, Route104_EventScript_BattleBrendanTreecko
# 231 "data/maps/Route104/scripts.pory"
	case 1, Route104_EventScript_BattleBrendanTorchic
# 232 "data/maps/Route104/scripts.pory"
	case 2, Route104_EventScript_BattleBrendanMudkip
# 233 "data/maps/Route104/scripts.pory"
	end
# 234 "data/maps/Route104/scripts.pory"

# 235 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrendanDefeated::
# 236 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanPostBattle, MSGBOX_DEFAULT
# 237 "data/maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 238 "data/maps/Route104/scripts.pory"
	releaseall
# 239 "data/maps/Route104/scripts.pory"
	end
# 240 "data/maps/Route104/scripts.pory"

# 241 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanTreecko::
# 242 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, Route104_Text_BrendanDefeat
# 243 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 244 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 245 "data/maps/Route104/scripts.pory"
	end
# 246 "data/maps/Route104/scripts.pory"

# 247 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanTorchic::
# 248 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, Route104_Text_BrendanDefeat
# 249 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 250 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 251 "data/maps/Route104/scripts.pory"
	end
# 252 "data/maps/Route104/scripts.pory"

# 253 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanMudkip::
# 254 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, Route104_Text_BrendanDefeat
# 255 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 256 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 257 "data/maps/Route104/scripts.pory"
	end
# 258 "data/maps/Route104/scripts.pory"

# 259 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerBackUp:
# 260 "data/maps/Route104/scripts.pory"
	lock_facing_direction
# 261 "data/maps/Route104/scripts.pory"
	walk_down
# 262 "data/maps/Route104/scripts.pory"
	unlock_facing_direction
# 263 "data/maps/Route104/scripts.pory"
	step_end
# 264 "data/maps/Route104/scripts.pory"

# 265 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalExitBrineysCottage:
# 266 "data/maps/Route104/scripts.pory"
	walk_down
# 267 "data/maps/Route104/scripts.pory"
	step_end
# 268 "data/maps/Route104/scripts.pory"

# 269 "data/maps/Route104/scripts.pory"
Route104_EventScript_ExpertF::
# 270 "data/maps/Route104/scripts.pory"
	lock
# 271 "data/maps/Route104/scripts.pory"
	faceplayer
# 272 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104, Route104_EventScript_ReceivedBerry
# 273 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_PlantBerriesInSoilTakeThis, MSGBOX_DEFAULT
# 274 "data/maps/Route104/scripts.pory"
	giveitem ITEM_CHESTO_BERRY
# 275 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 276 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104
# 277 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 278 "data/maps/Route104/scripts.pory"
	release
# 279 "data/maps/Route104/scripts.pory"
	end
# 280 "data/maps/Route104/scripts.pory"

# 281 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBerry::
# 282 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 283 "data/maps/Route104/scripts.pory"
	release
# 284 "data/maps/Route104/scripts.pory"
	end
# 285 "data/maps/Route104/scripts.pory"

# 286 "data/maps/Route104/scripts.pory"
Route104_EventScript_WhiteHerbFlorist::
# 287 "data/maps/Route104/scripts.pory"
	lock
# 288 "data/maps/Route104/scripts.pory"
	faceplayer
# 289 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_ReceivedWhiteHerb
# 290 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_DontNeedThisTakeIt, MSGBOX_DEFAULT
# 291 "data/maps/Route104/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 292 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 293 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_WHITE_HERB
# 294 "data/maps/Route104/scripts.pory"
	release
# 295 "data/maps/Route104/scripts.pory"
	end
# 296 "data/maps/Route104/scripts.pory"

# 297 "data/maps/Route104/scripts.pory"
Route104_EventScript_Reporters::
# 298 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_Reporters, MSGBOX_NPC
# 299 "data/maps/Route104/scripts.pory"
	end
# 300 "data/maps/Route104/scripts.pory"

# 301 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedWhiteHerb::
# 302 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
# 303 "data/maps/Route104/scripts.pory"
	release
# 304 "data/maps/Route104/scripts.pory"
	end
# 305 "data/maps/Route104/scripts.pory"

# 306 "data/maps/Route104/scripts.pory"
Route104_EventScript_Girl1::
# 307 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrineyLivesInSeasideCottage, MSGBOX_NPC
# 308 "data/maps/Route104/scripts.pory"
	end
# 309 "data/maps/Route104/scripts.pory"

# 310 "data/maps/Route104/scripts.pory"
Route104_EventScript_BugCatcher::
# 311 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WhatsItLikeAtBottomOfSea, MSGBOX_SIGN
# 312 "data/maps/Route104/scripts.pory"
	end
# 313 "data/maps/Route104/scripts.pory"

# 314 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrineysCottageSign::
# 315 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
# 316 "data/maps/Route104/scripts.pory"
	end
# 317 "data/maps/Route104/scripts.pory"

# 318 "data/maps/Route104/scripts.pory"
Route104_EventScript_RouteSignPetalburg::
# 319 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
# 320 "data/maps/Route104/scripts.pory"
	end
# 321 "data/maps/Route104/scripts.pory"

# 322 "data/maps/Route104/scripts.pory"
Route104_EventScript_RouteSignRustboro::
# 323 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
# 324 "data/maps/Route104/scripts.pory"
	end
# 325 "data/maps/Route104/scripts.pory"

# 326 "data/maps/Route104/scripts.pory"
Route104_EventScript_FlowerShopSign::
# 327 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
# 328 "data/maps/Route104/scripts.pory"
	end
# 329 "data/maps/Route104/scripts.pory"

# 330 "data/maps/Route104/scripts.pory"
Route104_EventScript_TrainerTipsDoubleBattles::
# 331 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
# 332 "data/maps/Route104/scripts.pory"
	end
# 333 "data/maps/Route104/scripts.pory"

# 334 "data/maps/Route104/scripts.pory"
Route104_EventScript_Boy1::
# 335 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_ThrowBallAtWeakenedPokemon, MSGBOX_NPC
# 336 "data/maps/Route104/scripts.pory"
	end
# 337 "data/maps/Route104/scripts.pory"

# 338 "data/maps/Route104/scripts.pory"
Route104_EventScript_Woman::
# 339 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_OnlyThrowBallAtWildPokemon, MSGBOX_NPC
# 340 "data/maps/Route104/scripts.pory"
	end
# 341 "data/maps/Route104/scripts.pory"

# 342 "data/maps/Route104/scripts.pory"
Route104_EventScript_Boy2::
# 343 "data/maps/Route104/scripts.pory"
	lock
# 344 "data/maps/Route104/scripts.pory"
	faceplayer
# 345 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_BULLET_SEED, Route104_EventScript_ReceivedBulletSeed
# 346 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 347 "data/maps/Route104/scripts.pory"
	giveitem ITEM_TM_BULLET_SEED
# 348 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 349 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULLET_SEED
# 350 "data/maps/Route104/scripts.pory"
	release
# 351 "data/maps/Route104/scripts.pory"
	end
# 352 "data/maps/Route104/scripts.pory"

# 353 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBulletSeed::
# 354 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
# 355 "data/maps/Route104/scripts.pory"
	release
# 356 "data/maps/Route104/scripts.pory"
	end
# 357 "data/maps/Route104/scripts.pory"

# 358 "data/maps/Route104/scripts.pory"
Route104_EventScript_Girl2::
# 359 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
# 360 "data/maps/Route104/scripts.pory"
	end
# 361 "data/maps/Route104/scripts.pory"

# 362 "data/maps/Route104/scripts.pory"
Route104_EventScript_SailToDewford::
# 363 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_R104, MAP_ROUTE104, 0
# 364 "data/maps/Route104/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104, 0
# 365 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BRINEY_R104, Route104_Movement_BrineyBoardBoat
# 366 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 367 "data/maps/Route104/scripts.pory"
	removeobject LOCALID_BRINEY_R104
# 368 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBoardBoat
# 369 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 370 "data/maps/Route104/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 371 "data/maps/Route104/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 372 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_SailToDewfordNoCall
# 373 "data/maps/Route104/scripts.pory"
	end
# 374 "data/maps/Route104/scripts.pory"

# 375 "data/maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordNoCall::
# 376 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewford
# 377 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewford
# 378 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 379 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 380 "data/maps/Route104/scripts.pory"

# 381 "data/maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordDadCalls::
# 382 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordBeforeDadCalls
# 383 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordBeforeDadCalls
# 384 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 385 "data/maps/Route104/scripts.pory"
	pokenavcall Route104_Text_DadPokenavCall
# 386 "data/maps/Route104/scripts.pory"
	waitmessage
# 387 "data/maps/Route104/scripts.pory"
	delay 30
# 388 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 389 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredDadInPokenav, MSGBOX_DEFAULT
# 390 "data/maps/Route104/scripts.pory"
	waitfanfare
# 391 "data/maps/Route104/scripts.pory"
	closemessage
# 392 "data/maps/Route104/scripts.pory"
	delay 30
# 393 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
# 394 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordAfterDadCalls
# 395 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordAfterDadCalls, MAP_ROUTE104
# 396 "data/maps/Route104/scripts.pory"
	waitmovement LOCALID_BOAT_R104, MAP_ROUTE104
# 397 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 398 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 399 "data/maps/Route104/scripts.pory"

# 400 "data/maps/Route104/scripts.pory"
Route104_EventScript_ArriveInDewford::
# 401 "data/maps/Route104/scripts.pory"
	delay 50
# 402 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerExitBoat
# 403 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 404 "data/maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 405 "data/maps/Route104/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
# 406 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerMoveForBriney
# 407 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 408 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_BRINEY_DEWFORD, 12, 8
# 409 "data/maps/Route104/scripts.pory"
	addobject LOCALID_BRINEY_DEWFORD
# 410 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
# 411 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
# 412 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BRINEY_DEWFORD, Route104_Movement_BrineyExitBoat
# 413 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 414 "data/maps/Route104/scripts.pory"
	addobject LOCALID_BOAT_DEWFORD
# 415 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 416 "data/maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 417 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
# 418 "data/maps/Route104/scripts.pory"
	hideobjectat LOCALID_BOAT_R104, MAP_ROUTE104
# 419 "data/maps/Route104/scripts.pory"
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 420 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 421 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN
# 422 "data/maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_BRINEY_DEWFORD
# 423 "data/maps/Route104/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
# 424 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_DeliverLetterReminder
# 425 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_LandedInDewford
# 426 "data/maps/Route104/scripts.pory"
	end
# 427 "data/maps/Route104/scripts.pory"

# 428 "data/maps/Route104/scripts.pory"
Route104_EventScript_DeliverLetterReminder::
# 429 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_LandedInDewfordDeliverLetter, MSGBOX_DEFAULT
# 430 "data/maps/Route104/scripts.pory"
	releaseall
# 431 "data/maps/Route104/scripts.pory"
	end
# 432 "data/maps/Route104/scripts.pory"

# 433 "data/maps/Route104/scripts.pory"
Route104_EventScript_LandedInDewford::
# 434 "data/maps/Route104/scripts.pory"
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
# 435 "data/maps/Route104/scripts.pory"
	releaseall
# 436 "data/maps/Route104/scripts.pory"
	end
# 437 "data/maps/Route104/scripts.pory"

# 438 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordBeforeDadCalls:
# 439 "data/maps/Route104/scripts.pory"
	walk_down
# 440 "data/maps/Route104/scripts.pory"
	walk_down
# 441 "data/maps/Route104/scripts.pory"
	walk_down
# 442 "data/maps/Route104/scripts.pory"
	walk_down
# 443 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 444 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 445 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 446 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 447 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 448 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 449 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 450 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 451 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 452 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 453 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 454 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 455 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 456 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 457 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 458 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 459 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 460 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 461 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 462 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 463 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 464 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 465 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 466 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 467 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 468 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 469 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 470 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 471 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 472 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 473 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 474 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 475 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 476 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 477 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 478 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 479 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 480 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 481 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 482 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 483 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 484 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 485 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 486 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 487 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 488 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 489 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 490 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 491 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 492 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 493 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 494 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 495 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 496 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 497 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 498 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 499 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 500 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 501 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 502 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 503 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 504 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 505 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 506 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 507 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 508 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 509 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 510 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 511 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 512 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 513 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 514 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 515 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 516 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 517 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 518 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 519 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 520 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 521 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 522 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 523 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 524 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 525 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 526 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 527 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 528 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 529 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 530 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 531 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 532 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 533 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 534 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 535 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 536 "data/maps/Route104/scripts.pory"
	step_end
# 537 "data/maps/Route104/scripts.pory"

# 538 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordAfterDadCalls:
# 539 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 540 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 541 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 542 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 543 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 544 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 545 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 546 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 547 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 548 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 549 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 550 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 551 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 552 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 553 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 554 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 555 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 556 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 557 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 558 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 559 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 560 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 561 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 562 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 563 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 564 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 565 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 566 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 567 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 568 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 569 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 570 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 571 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 572 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 573 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 574 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 575 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 576 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 577 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 578 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 579 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 580 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 581 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 582 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 583 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 584 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 585 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 586 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 587 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 588 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 589 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 590 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 591 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 592 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 593 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 594 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 595 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 596 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 597 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 598 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 599 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 600 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 601 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 602 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 603 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 604 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 605 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 606 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 607 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 608 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 609 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 610 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 611 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 612 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 613 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 614 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 615 "data/maps/Route104/scripts.pory"
	walk_right
# 616 "data/maps/Route104/scripts.pory"
	walk_right
# 617 "data/maps/Route104/scripts.pory"
	walk_down
# 618 "data/maps/Route104/scripts.pory"
	walk_down
# 619 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 620 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 621 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 622 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 623 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 624 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 625 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 626 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 627 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 628 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 629 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 630 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 631 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 632 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 633 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 634 "data/maps/Route104/scripts.pory"
	walk_down
# 635 "data/maps/Route104/scripts.pory"
	walk_down
# 636 "data/maps/Route104/scripts.pory"
	step_end
# 637 "data/maps/Route104/scripts.pory"

# 638 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewford:
# 639 "data/maps/Route104/scripts.pory"
	walk_down
# 640 "data/maps/Route104/scripts.pory"
	walk_down
# 641 "data/maps/Route104/scripts.pory"
	walk_down
# 642 "data/maps/Route104/scripts.pory"
	walk_down
# 643 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 644 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 645 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 646 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 647 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 648 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 649 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 650 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 651 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 652 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 653 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 654 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 655 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 656 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 657 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 658 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 659 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 660 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 661 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 662 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 663 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 664 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 665 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 666 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 667 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 668 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 669 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 670 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 671 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 672 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 673 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 674 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 675 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 676 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 677 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 678 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 679 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 680 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 681 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 682 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 683 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 684 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 685 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 686 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 687 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 688 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 689 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 690 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 691 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 692 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 693 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 694 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 695 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 696 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 697 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 698 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 699 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 700 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 701 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 702 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 703 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 704 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 705 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 706 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 707 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 708 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 709 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 710 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 711 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 712 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 713 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 714 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 715 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 716 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 717 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 718 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 719 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 720 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 721 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 722 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 723 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 724 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 725 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 726 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 727 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 728 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 729 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 730 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 731 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 732 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 733 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 734 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 735 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 736 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 737 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 738 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 739 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 740 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 741 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 742 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 743 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 744 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 745 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 746 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 747 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 748 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 749 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 750 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 751 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 752 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 753 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 754 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 755 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 756 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 757 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 758 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 759 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 760 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 761 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 762 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 763 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 764 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 765 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 766 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 767 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 768 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 769 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 770 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 771 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 772 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 773 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 774 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 775 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 776 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 777 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 778 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 779 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 780 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 781 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 782 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 783 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 784 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 785 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 786 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 787 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 788 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 789 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 790 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 791 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 792 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 793 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 794 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 795 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 796 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 797 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 798 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 799 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 800 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 801 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 802 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 803 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 804 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 805 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 806 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 807 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 808 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 809 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 810 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 811 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 812 "data/maps/Route104/scripts.pory"
	walk_right
# 813 "data/maps/Route104/scripts.pory"
	walk_right
# 814 "data/maps/Route104/scripts.pory"
	walk_down
# 815 "data/maps/Route104/scripts.pory"
	walk_down
# 816 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 817 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 818 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 819 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 820 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 821 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 822 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 823 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 824 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 825 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 826 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 827 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 828 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 829 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 830 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 831 "data/maps/Route104/scripts.pory"
	walk_down
# 832 "data/maps/Route104/scripts.pory"
	walk_down
# 833 "data/maps/Route104/scripts.pory"
	step_end
# 834 "data/maps/Route104/scripts.pory"

# 835 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerBoardBoat:
# 836 "data/maps/Route104/scripts.pory"
	walk_left
# 837 "data/maps/Route104/scripts.pory"
	walk_down
# 838 "data/maps/Route104/scripts.pory"
	walk_down
# 839 "data/maps/Route104/scripts.pory"
	step_end
# 840 "data/maps/Route104/scripts.pory"

# 841 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerExitBoat:
# 842 "data/maps/Route104/scripts.pory"
	walk_down
# 843 "data/maps/Route104/scripts.pory"
	step_end
# 844 "data/maps/Route104/scripts.pory"

# 845 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerMoveForBriney:
# 846 "data/maps/Route104/scripts.pory"
	walk_down
# 847 "data/maps/Route104/scripts.pory"
	walk_left
# 848 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_right
# 849 "data/maps/Route104/scripts.pory"
	step_end
# 850 "data/maps/Route104/scripts.pory"

# 851 "data/maps/Route104/scripts.pory"
Route104_Movement_BrineyBoardBoat:
# 852 "data/maps/Route104/scripts.pory"
	walk_down
# 853 "data/maps/Route104/scripts.pory"
	walk_down
# 854 "data/maps/Route104/scripts.pory"
	step_end
# 855 "data/maps/Route104/scripts.pory"

# 856 "data/maps/Route104/scripts.pory"
Route104_Movement_BrineyExitBoat:
# 857 "data/maps/Route104/scripts.pory"
	walk_down
# 858 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 859 "data/maps/Route104/scripts.pory"
	step_end
# 860 "data/maps/Route104/scripts.pory"

# 861 "data/maps/Route104/scripts.pory"
Route104_EventScript_IvanDarian::
# 862 "data/maps/Route104/scripts.pory"
lockall
# 863 "data/maps/Route104/scripts.pory"
setvar VAR_0x8008, LOCALID_IVAN
# 864 "data/maps/Route104/scripts.pory"
playse SE_PIN
# 865 "data/maps/Route104/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 866 "data/maps/Route104/scripts.pory"
waitmovement 0
# 867 "data/maps/Route104/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 868 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 869 "data/maps/Route104/scripts.pory"
waitmovement 0
# 870 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_IvanIntro MSGBOX_AUTOCLOSE
# 871 "data/maps/Route104/scripts.pory"
setvar VAR_0x8008, LOCALID_DARIAN
# 872 "data/maps/Route104/scripts.pory"
playse SE_PIN
# 873 "data/maps/Route104/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 874 "data/maps/Route104/scripts.pory"
waitmovement 0
# 875 "data/maps/Route104/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 876 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 877 "data/maps/Route104/scripts.pory"
waitmovement 0
# 878 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_DarianIntro MSGBOX_AUTOCLOSE
# 879 "data/maps/Route104/scripts.pory"
goto Route104_EventScript_IvanDarianDoMultiBattle
# 880 "data/maps/Route104/scripts.pory"
releaseall
# 881 "data/maps/Route104/scripts.pory"
end
# 882 "data/maps/Route104/scripts.pory"

# 883 "data/maps/Route104/scripts.pory"
Route104_EventScript_IvanDarianDoMultiBattle::
# 884 "data/maps/Route104/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 885 "data/maps/Route104/scripts.pory"
multi_2p_vs_2 TRAINER_IVAN, Route104_Text_IvanDefeat, TRAINER_DARIAN, Route104_Text_DarianDefeat, PARTNER_EMMIE
# 886 "data/maps/Route104/scripts.pory"
switch VAR_RESULT
# 887 "data/maps/Route104/scripts.pory"
case 1, Route104_EventScript_IvanDarianVictory
# 888 "data/maps/Route104/scripts.pory"
fadescreen FADE_TO_BLACK
# 889 "data/maps/Route104/scripts.pory"
special SetCB2WhiteOut
# 890 "data/maps/Route104/scripts.pory"
waitstate
# 891 "data/maps/Route104/scripts.pory"

# 892 "data/maps/Route104/scripts.pory"
Route104_EventScript_IvanDarianVictory::
# 893 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 894 "data/maps/Route104/scripts.pory"
waitmovement 0
# 895 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
# 896 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 897 "data/maps/Route104/scripts.pory"
waitmovement 0
# 898 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
# 899 "data/maps/Route104/scripts.pory"
addvar VAR_ROUTE104_STATE, 1
# 900 "data/maps/Route104/scripts.pory"
end
# 901 "data/maps/Route104/scripts.pory"

# 902 "data/maps/Route104/scripts.pory"
Route104_EventScript_Ivan::
# 903 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
# 904 "data/maps/Route104/scripts.pory"
	end
# 905 "data/maps/Route104/scripts.pory"

# 906 "data/maps/Route104/scripts.pory"
Route104_EventScript_HaleyBilly::
# 907 "data/maps/Route104/scripts.pory"
lockall
# 908 "data/maps/Route104/scripts.pory"
setvar VAR_0x8008, LOCALID_HALEY
# 909 "data/maps/Route104/scripts.pory"
playse SE_PIN
# 910 "data/maps/Route104/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 911 "data/maps/Route104/scripts.pory"
waitmovement 0
# 912 "data/maps/Route104/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 913 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 914 "data/maps/Route104/scripts.pory"
waitmovement 0
# 915 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_HaleyIntro MSGBOX_AUTOCLOSE
# 916 "data/maps/Route104/scripts.pory"
setvar VAR_0x8008, LOCALID_BILLY
# 917 "data/maps/Route104/scripts.pory"
playse SE_PIN
# 918 "data/maps/Route104/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 919 "data/maps/Route104/scripts.pory"
waitmovement 0
# 920 "data/maps/Route104/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 921 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 922 "data/maps/Route104/scripts.pory"
waitmovement 0
# 923 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_BillyIntro MSGBOX_AUTOCLOSE
# 924 "data/maps/Route104/scripts.pory"
goto Route104_EventScript_HaleyBillyDoMultiBattle
# 925 "data/maps/Route104/scripts.pory"
releaseall
# 926 "data/maps/Route104/scripts.pory"
end
# 927 "data/maps/Route104/scripts.pory"

# 928 "data/maps/Route104/scripts.pory"
Route104_EventScript_HaleyBillyDoMultiBattle::
# 929 "data/maps/Route104/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 930 "data/maps/Route104/scripts.pory"
multi_2p_vs_2 TRAINER_HALEY_1, Route104_Text_HaleyDefeat, TRAINER_BILLY, Route104_Text_BillyDefeat, PARTNER_EMMIE
# 931 "data/maps/Route104/scripts.pory"
switch VAR_RESULT
# 932 "data/maps/Route104/scripts.pory"
case 1, Route104_EventScript_HaleyBillyVictory
# 933 "data/maps/Route104/scripts.pory"
fadescreen FADE_TO_BLACK
# 934 "data/maps/Route104/scripts.pory"
special SetCB2WhiteOut
# 935 "data/maps/Route104/scripts.pory"
waitstate
# 936 "data/maps/Route104/scripts.pory"

# 937 "data/maps/Route104/scripts.pory"
Route104_EventScript_HaleyBillyVictory::
# 938 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 939 "data/maps/Route104/scripts.pory"
waitmovement 0
# 940 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_HaleyPostBattle, MSGBOX_AUTOCLOSE
# 941 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 942 "data/maps/Route104/scripts.pory"
waitmovement 0
# 943 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
# 944 "data/maps/Route104/scripts.pory"
addvar VAR_ROUTE104_STATE, 1
# 945 "data/maps/Route104/scripts.pory"
end
# 946 "data/maps/Route104/scripts.pory"

# 947 "data/maps/Route104/scripts.pory"
Route104_EventScript_Billy::
# 948 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
# 949 "data/maps/Route104/scripts.pory"
	end
# 950 "data/maps/Route104/scripts.pory"

# 951 "data/maps/Route104/scripts.pory"
Route104_EventScript_Haley::
# 952 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 953 "data/maps/Route104/scripts.pory"
	release
# 954 "data/maps/Route104/scripts.pory"
	end
# 955 "data/maps/Route104/scripts.pory"

# 956 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaleyAfterBattle::
# 957 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 958 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 959 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaleyAfterBattle
# 960 "data/maps/Route104/scripts.pory"
	release
# 961 "data/maps/Route104/scripts.pory"
	end
# 962 "data/maps/Route104/scripts.pory"

# 963 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaleyAfterBattle::
# 964 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister2, MSGBOX_DEFAULT
# 965 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 966 "data/maps/Route104/scripts.pory"
	release
# 967 "data/maps/Route104/scripts.pory"
	end
# 968 "data/maps/Route104/scripts.pory"

# 969 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaley::
# 970 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaley
# 971 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 972 "data/maps/Route104/scripts.pory"
	release
# 973 "data/maps/Route104/scripts.pory"
	end
# 974 "data/maps/Route104/scripts.pory"

# 975 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaley::
# 976 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister1, MSGBOX_DEFAULT
# 977 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 978 "data/maps/Route104/scripts.pory"
	release
# 979 "data/maps/Route104/scripts.pory"
	end
# 980 "data/maps/Route104/scripts.pory"

# 981 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchHaley::
# 982 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_HaleyRematchIntro, Route104_Text_HaleyRematchDefeat
# 983 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostRematch, MSGBOX_AUTOCLOSE
# 984 "data/maps/Route104/scripts.pory"
	end
# 985 "data/maps/Route104/scripts.pory"

# 986 "data/maps/Route104/scripts.pory"
Route104_EventScript_Winston::
# 987 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 988 "data/maps/Route104/scripts.pory"
	release
# 989 "data/maps/Route104/scripts.pory"
	end
# 990 "data/maps/Route104/scripts.pory"

# 991 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinstonAfterBattle::
# 992 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 993 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 994 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinstonAfterBattle
# 995 "data/maps/Route104/scripts.pory"
	release
# 996 "data/maps/Route104/scripts.pory"
	end
# 997 "data/maps/Route104/scripts.pory"

# 998 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinstonAfterBattle::
# 999 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister2, MSGBOX_DEFAULT
# 1000 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 1001 "data/maps/Route104/scripts.pory"
	release
# 1002 "data/maps/Route104/scripts.pory"
	end
# 1003 "data/maps/Route104/scripts.pory"

# 1004 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinston::
# 1005 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinston
# 1006 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 1007 "data/maps/Route104/scripts.pory"
	release
# 1008 "data/maps/Route104/scripts.pory"
	end
# 1009 "data/maps/Route104/scripts.pory"

# 1010 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinston::
# 1011 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister1, MSGBOX_DEFAULT
# 1012 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 1013 "data/maps/Route104/scripts.pory"
	release
# 1014 "data/maps/Route104/scripts.pory"
	end
# 1015 "data/maps/Route104/scripts.pory"

# 1016 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchWinston::
# 1017 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_WinstonRematchIntro, Route104_Text_WinstonRematchDefeat
# 1018 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostRematch, MSGBOX_AUTOCLOSE
# 1019 "data/maps/Route104/scripts.pory"
	end
# 1020 "data/maps/Route104/scripts.pory"

# 1021 "data/maps/Route104/scripts.pory"
Route104_EventScript_CindyWinston::
# 1022 "data/maps/Route104/scripts.pory"
lockall
# 1023 "data/maps/Route104/scripts.pory"
setvar VAR_0x8008, LOCALID_CINDY
# 1024 "data/maps/Route104/scripts.pory"
playse SE_PIN
# 1025 "data/maps/Route104/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 1026 "data/maps/Route104/scripts.pory"
waitmovement 0
# 1027 "data/maps/Route104/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 1028 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1029 "data/maps/Route104/scripts.pory"
waitmovement 0
# 1030 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_CindyIntro MSGBOX_AUTOCLOSE
# 1031 "data/maps/Route104/scripts.pory"
setvar VAR_0x8008, LOCALID_WINSTON
# 1032 "data/maps/Route104/scripts.pory"
playse SE_PIN
# 1033 "data/maps/Route104/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 1034 "data/maps/Route104/scripts.pory"
waitmovement 0
# 1035 "data/maps/Route104/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 1036 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1037 "data/maps/Route104/scripts.pory"
waitmovement 0
# 1038 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_WinstonIntro MSGBOX_AUTOCLOSE
# 1039 "data/maps/Route104/scripts.pory"
goto Route104_EventScript_CindyWinstonDoMultiBattle
# 1040 "data/maps/Route104/scripts.pory"
releaseall
# 1041 "data/maps/Route104/scripts.pory"
end
# 1042 "data/maps/Route104/scripts.pory"

# 1043 "data/maps/Route104/scripts.pory"
Route104_EventScript_CindyWinstonDoMultiBattle::
# 1044 "data/maps/Route104/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 1045 "data/maps/Route104/scripts.pory"
multi_2p_vs_2 TRAINER_CINDY_1, Route104_Text_CindyDefeat, TRAINER_WINSTON_1, Route104_Text_WinstonDefeat, PARTNER_EMMIE
# 1046 "data/maps/Route104/scripts.pory"
switch VAR_RESULT
# 1047 "data/maps/Route104/scripts.pory"
case 1, Route104_EventScript_CindyWinstonVictory
# 1048 "data/maps/Route104/scripts.pory"
fadescreen FADE_TO_BLACK
# 1049 "data/maps/Route104/scripts.pory"
special SetCB2WhiteOut
# 1050 "data/maps/Route104/scripts.pory"
waitstate
# 1051 "data/maps/Route104/scripts.pory"

# 1052 "data/maps/Route104/scripts.pory"
Route104_EventScript_CindyWinstonVictory::
# 1053 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1054 "data/maps/Route104/scripts.pory"
waitmovement 0
# 1055 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_CindyPostBattle, MSGBOX_AUTOCLOSE
# 1056 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1057 "data/maps/Route104/scripts.pory"
waitmovement 0
# 1058 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_WinstonPostBattle, MSGBOX_AUTOCLOSE
# 1059 "data/maps/Route104/scripts.pory"
addvar VAR_ROUTE104_STATE, 1
# 1060 "data/maps/Route104/scripts.pory"
end
# 1061 "data/maps/Route104/scripts.pory"

# 1062 "data/maps/Route104/scripts.pory"
Route104_EventScript_Cindy::
# 1063 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 1064 "data/maps/Route104/scripts.pory"
	release
# 1065 "data/maps/Route104/scripts.pory"
	end
# 1066 "data/maps/Route104/scripts.pory"

# 1067 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindyAfterBattle::
# 1068 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 1069 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 1070 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindyAfterBattle
# 1071 "data/maps/Route104/scripts.pory"
	release
# 1072 "data/maps/Route104/scripts.pory"
	end
# 1073 "data/maps/Route104/scripts.pory"

# 1074 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindyAfterBattle::
# 1075 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister2, MSGBOX_DEFAULT
# 1076 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 1077 "data/maps/Route104/scripts.pory"
	release
# 1078 "data/maps/Route104/scripts.pory"
	end
# 1079 "data/maps/Route104/scripts.pory"

# 1080 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindy::
# 1081 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindy
# 1082 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 1083 "data/maps/Route104/scripts.pory"
	release
# 1084 "data/maps/Route104/scripts.pory"
	end
# 1085 "data/maps/Route104/scripts.pory"

# 1086 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindy::
# 1087 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister1, MSGBOX_DEFAULT
# 1088 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 1089 "data/maps/Route104/scripts.pory"
	release
# 1090 "data/maps/Route104/scripts.pory"
	end
# 1091 "data/maps/Route104/scripts.pory"

# 1092 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchCindy::
# 1093 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_CindyRematchIntro, Route104_Text_CindyRematchDefeat
# 1094 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostRematch, MSGBOX_AUTOCLOSE
# 1095 "data/maps/Route104/scripts.pory"
	end
# 1096 "data/maps/Route104/scripts.pory"

# 1097 "data/maps/Route104/scripts.pory"
Route104_EventScript_GinaMia::
# 1098 "data/maps/Route104/scripts.pory"
lockall
# 1099 "data/maps/Route104/scripts.pory"
setvar VAR_0x8008, LOCALID_GINA
# 1100 "data/maps/Route104/scripts.pory"
playse SE_PIN
# 1101 "data/maps/Route104/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 1102 "data/maps/Route104/scripts.pory"
waitmovement 0
# 1103 "data/maps/Route104/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 1104 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1105 "data/maps/Route104/scripts.pory"
waitmovement 0
# 1106 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_GinaIntro MSGBOX_AUTOCLOSE
# 1107 "data/maps/Route104/scripts.pory"
goto Route104_EventScript_GinaMiaDoMultiBattle
# 1108 "data/maps/Route104/scripts.pory"
releaseall
# 1109 "data/maps/Route104/scripts.pory"
end
# 1110 "data/maps/Route104/scripts.pory"

# 1111 "data/maps/Route104/scripts.pory"
Route104_EventScript_GinaMiaDoMultiBattle::
# 1112 "data/maps/Route104/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 1113 "data/maps/Route104/scripts.pory"
multi_2p_vs_1 TRAINER_GINA_AND_MIA_1, Route104_Text_GinaDefeat, PARTNER_EMMIE
# 1114 "data/maps/Route104/scripts.pory"
switch VAR_RESULT
# 1115 "data/maps/Route104/scripts.pory"
case 1, Route104_EventScript_GinaMiaVictory
# 1116 "data/maps/Route104/scripts.pory"
fadescreen FADE_TO_BLACK
# 1117 "data/maps/Route104/scripts.pory"
special SetCB2WhiteOut
# 1118 "data/maps/Route104/scripts.pory"
waitstate
# 1119 "data/maps/Route104/scripts.pory"

# 1120 "data/maps/Route104/scripts.pory"
Route104_EventScript_GinaMiaVictory::
# 1121 "data/maps/Route104/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1122 "data/maps/Route104/scripts.pory"
waitmovement 0
# 1123 "data/maps/Route104/scripts.pory"
msgbox Route104_Text_GinaPostBattle, MSGBOX_AUTOCLOSE
# 1124 "data/maps/Route104/scripts.pory"
addvar VAR_ROUTE104_STATE, 1
# 1125 "data/maps/Route104/scripts.pory"
end
# 1126 "data/maps/Route104/scripts.pory"

# 1127 "data/maps/Route104/scripts.pory"
Route104_EventScript_Gina::
# 1128 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
# 1129 "data/maps/Route104/scripts.pory"
	release
# 1130 "data/maps/Route104/scripts.pory"
	end
# 1131 "data/maps/Route104/scripts.pory"

# 1132 "data/maps/Route104/scripts.pory"
Route104_EventScript_Mia::
# 1133 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
# 1134 "data/maps/Route104/scripts.pory"
	release
# 1135 "data/maps/Route104/scripts.pory"
	end
# 1136 "data/maps/Route104/scripts.pory"

# 1137 "data/maps/Route104/scripts.pory"
Route104_EventScript_Darian::
# 1138 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
# 1139 "data/maps/Route104/scripts.pory"
	end
# 1140 "data/maps/Route104/scripts.pory"

# 1141 "data/maps/Route104/scripts.pory"
Route104_Text_BrineyLivesInSeasideCottage:
# 1142 "data/maps/Route104/scripts.pory"
	.string "That seaside cottage is where\n"
# 1143 "data/maps/Route104/scripts.pory"
	.string "MR. BRINEY lives.\p"
# 1144 "data/maps/Route104/scripts.pory"
	.string "He was once a mighty sailor who never\n"
# 1145 "data/maps/Route104/scripts.pory"
	.string "feared the sea, however stormy.$"
# 1146 "data/maps/Route104/scripts.pory"

# 1147 "data/maps/Route104/scripts.pory"
Route104_Text_WhatsItLikeAtBottomOfSea:
# 1148 "data/maps/Route104/scripts.pory"
	.string "The sea, huh?\p"
# 1149 "data/maps/Route104/scripts.pory"
	.string "I wonder what it's like at the bottom\n"
# 1150 "data/maps/Route104/scripts.pory"
	.string "of the sea?$"
# 1151 "data/maps/Route104/scripts.pory"

# 1152 "data/maps/Route104/scripts.pory"
Route104_Text_ThrowBallAtWeakenedPokemon:
# 1153 "data/maps/Route104/scripts.pory"
	.string "If you're going to throw a POKé BALL,\n"
# 1154 "data/maps/Route104/scripts.pory"
	.string "weaken the wild POKéMON first.\p"
# 1155 "data/maps/Route104/scripts.pory"
	.string "It will be easier to catch if it's been\n"
# 1156 "data/maps/Route104/scripts.pory"
	.string "poisoned, burned, or lulled to sleep.$"
# 1157 "data/maps/Route104/scripts.pory"

# 1158 "data/maps/Route104/scripts.pory"
Route104_Text_OnlyThrowBallAtWildPokemon:
# 1159 "data/maps/Route104/scripts.pory"
	.string "You're a thief if you try to steal\n"
# 1160 "data/maps/Route104/scripts.pory"
	.string "someone else's POKéMON.\p"
# 1161 "data/maps/Route104/scripts.pory"
	.string "You should throw POKé BALLS only at\n"
# 1162 "data/maps/Route104/scripts.pory"
	.string "wild POKéMON.$"
# 1163 "data/maps/Route104/scripts.pory"

# 1164 "data/maps/Route104/scripts.pory"
Route104_Text_ImNotATrainer:
# 1165 "data/maps/Route104/scripts.pory"
	.string "Oh, no, I'm not a TRAINER.\p"
# 1166 "data/maps/Route104/scripts.pory"
	.string "But that's right, if TRAINERS lock eyes,\n"
# 1167 "data/maps/Route104/scripts.pory"
	.string "it's a challenge to battle.\p"
# 1168 "data/maps/Route104/scripts.pory"
	.string "If you don't want to battle, stay out\n"
# 1169 "data/maps/Route104/scripts.pory"
	.string "of their sight.$"
# 1170 "data/maps/Route104/scripts.pory"

# 1171 "data/maps/Route104/scripts.pory"
Route104_Text_LikeFillingMouthWithSeedsTakeThis:
# 1172 "data/maps/Route104/scripts.pory"
	.string "I like filling my mouth with seeds,\n"
# 1173 "data/maps/Route104/scripts.pory"
	.string "then spitting them out fast!\p"
# 1174 "data/maps/Route104/scripts.pory"
	.string "You can have this, so you try it out!\p"
# 1175 "data/maps/Route104/scripts.pory"
	.string "Use it on a POKéMON, and it will learn\n"
# 1176 "data/maps/Route104/scripts.pory"
	.string "a move for firing seeds rapidly.$"
# 1177 "data/maps/Route104/scripts.pory"

# 1178 "data/maps/Route104/scripts.pory"
Route104_Text_TMsAreOneTimeUse:
# 1179 "data/maps/Route104/scripts.pory"
	.string "A word of advice!\p"
# 1180 "data/maps/Route104/scripts.pory"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
# 1181 "data/maps/Route104/scripts.pory"
	.string "for one-time use.\p"
# 1182 "data/maps/Route104/scripts.pory"
	.string "Once you use it, it's gone.\n"
# 1183 "data/maps/Route104/scripts.pory"
	.string "Think twice before using it!$"
# 1184 "data/maps/Route104/scripts.pory"

# 1185 "data/maps/Route104/scripts.pory"
Route104_Text_DontNeedThisTakeIt:
# 1186 "data/maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1187 "data/maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1188 "data/maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1189 "data/maps/Route104/scripts.pory"
	.string "shopping.\p"
# 1190 "data/maps/Route104/scripts.pory"
	.string "I don't need this WHITE HERB anymore.\n"
# 1191 "data/maps/Route104/scripts.pory"
	.string "Would you take it, please?$"
# 1192 "data/maps/Route104/scripts.pory"

# 1193 "data/maps/Route104/scripts.pory"
Route104_Text_FlowerShopSellingSaplings:
# 1194 "data/maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1195 "data/maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1196 "data/maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1197 "data/maps/Route104/scripts.pory"
	.string "shopping. Where should I put them?$"
# 1198 "data/maps/Route104/scripts.pory"

# 1199 "data/maps/Route104/scripts.pory"
Route104_Text_MrBrineysCottage:
# 1200 "data/maps/Route104/scripts.pory"
	.string "MR. BRINEY'S COTTAGE$"
# 1201 "data/maps/Route104/scripts.pory"

# 1202 "data/maps/Route104/scripts.pory"
Route104_Text_RouteSignPetalburg:
# 1203 "data/maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1204 "data/maps/Route104/scripts.pory"
	.string "{RIGHT_ARROW} PETALBURG CITY$"
# 1205 "data/maps/Route104/scripts.pory"

# 1206 "data/maps/Route104/scripts.pory"
Route104_Text_RouteSignRustboro:
# 1207 "data/maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1208 "data/maps/Route104/scripts.pory"
	.string "{UP_ARROW} RUSTBORO CITY$"
# 1209 "data/maps/Route104/scripts.pory"

# 1210 "data/maps/Route104/scripts.pory"
Route104_Text_PrettyPetalFlowShop:
# 1211 "data/maps/Route104/scripts.pory"
	.string "PRETTY PETAL FLOWER SHOP$"
# 1212 "data/maps/Route104/scripts.pory"

# 1213 "data/maps/Route104/scripts.pory"
Route104_Text_TrainerTipsDoubleBattles:
# 1214 "data/maps/Route104/scripts.pory"
	.string "TRAINER TIPS\p"
# 1215 "data/maps/Route104/scripts.pory"
	.string "In the HOENN region there are pairs\n"
# 1216 "data/maps/Route104/scripts.pory"
	.string "of TRAINERS who challenge others\l"
# 1217 "data/maps/Route104/scripts.pory"
	.string "for 2-on-2 POKéMON battles called\l"
# 1218 "data/maps/Route104/scripts.pory"
	.string "DOUBLE BATTLES.\p"
# 1219 "data/maps/Route104/scripts.pory"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
# 1220 "data/maps/Route104/scripts.pory"
	.string "send out two POKéMON, the one at the\l"
# 1221 "data/maps/Route104/scripts.pory"
	.string "left of the list and the top one.\l"
# 1222 "data/maps/Route104/scripts.pory"
	.string "Watch how POKéMON are lined up.$"
# 1223 "data/maps/Route104/scripts.pory"

# 1224 "data/maps/Route104/scripts.pory"
Route104_Text_MayWeShouldRegister:
# 1225 "data/maps/Route104/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1226 "data/maps/Route104/scripts.pory"
	.string "DEVON upgraded your POKéNAV with\n"
# 1227 "data/maps/Route104/scripts.pory"
	.string "the MATCH CALL system, huh?\p"
# 1228 "data/maps/Route104/scripts.pory"
	.string "We should register each other so we\n"
# 1229 "data/maps/Route104/scripts.pory"
	.string "can get in contact anytime.$"
# 1230 "data/maps/Route104/scripts.pory"

# 1231 "data/maps/Route104/scripts.pory"
Route104_Text_RegisteredMay:
# 1232 "data/maps/Route104/scripts.pory"
	.string "{PLAYER} registered MAY\n"
# 1233 "data/maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1234 "data/maps/Route104/scripts.pory"

# 1235 "data/maps/Route104/scripts.pory"
Route104_Text_MayHowsYourPokedex:
# 1236 "data/maps/Route104/scripts.pory"
	.string "MAY: Oh, by the way, {PLAYER}{KUN},\n"
# 1237 "data/maps/Route104/scripts.pory"
	.string "how's your POKéDEX coming along?$"
# 1238 "data/maps/Route104/scripts.pory"

# 1239 "data/maps/Route104/scripts.pory"
Route104_Text_MayMinesDecentLetsBattle:
# 1240 "data/maps/Route104/scripts.pory"
	.string "Mine's looking pretty decent.\n"
# 1241 "data/maps/Route104/scripts.pory"
	.string "So…\l"
# 1242 "data/maps/Route104/scripts.pory"
	.string "How about a little battle?$"
# 1243 "data/maps/Route104/scripts.pory"

# 1244 "data/maps/Route104/scripts.pory"
Route104_Text_MayHaventRaisedPokemon:
# 1245 "data/maps/Route104/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1246 "data/maps/Route104/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1247 "data/maps/Route104/scripts.pory"
	.string "POKéMON very much?\p"
# 1248 "data/maps/Route104/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1249 "data/maps/Route104/scripts.pory"

# 1250 "data/maps/Route104/scripts.pory"
Route104_Text_MayLetsBattle:
# 1251 "data/maps/Route104/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1252 "data/maps/Route104/scripts.pory"
	.string "How about a little battle here?$"
# 1253 "data/maps/Route104/scripts.pory"

# 1254 "data/maps/Route104/scripts.pory"
Route104_Text_MayIntro:
# 1255 "data/maps/Route104/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1256 "data/maps/Route104/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1257 "data/maps/Route104/scripts.pory"

# 1258 "data/maps/Route104/scripts.pory"
Route104_Text_MayDefeat:
# 1259 "data/maps/Route104/scripts.pory"
	.string "Yikes!\n"
# 1260 "data/maps/Route104/scripts.pory"
	.string "You're better than I expected!$"
# 1261 "data/maps/Route104/scripts.pory"

# 1262 "data/maps/Route104/scripts.pory"
Route104_Text_MayPostBattle:
# 1263 "data/maps/Route104/scripts.pory"
	.string "MAY: I can tell you've gotten pretty\n"
# 1264 "data/maps/Route104/scripts.pory"
	.string "good with the way you handle POKéMON.\p"
# 1265 "data/maps/Route104/scripts.pory"
	.string "But instead of only making them\n"
# 1266 "data/maps/Route104/scripts.pory"
	.string "battle, you should be like MR. BRINEY.\p"
# 1267 "data/maps/Route104/scripts.pory"
	.string "It's important to become friends with\n"
# 1268 "data/maps/Route104/scripts.pory"
	.string "POKéMON, too.$"
# 1269 "data/maps/Route104/scripts.pory"

# 1270 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanWeShouldRegister:
# 1271 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1272 "data/maps/Route104/scripts.pory"
	.string "Cool, you had DEVON install the MATCH\n"
# 1273 "data/maps/Route104/scripts.pory"
	.string "CALL system on your POKéNAV!\p"
# 1274 "data/maps/Route104/scripts.pory"
	.string "Let's register each other in our\n"
# 1275 "data/maps/Route104/scripts.pory"
	.string "POKéNAVS so we can keep in touch.$"
# 1276 "data/maps/Route104/scripts.pory"

# 1277 "data/maps/Route104/scripts.pory"
Route104_Text_RegisteredBrendan:
# 1278 "data/maps/Route104/scripts.pory"
	.string "{PLAYER} registered BRENDAN\n"
# 1279 "data/maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1280 "data/maps/Route104/scripts.pory"

# 1281 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanHowsYourPokedex:
# 1282 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: {PLAYER}, how's your POKéDEX?\n"
# 1283 "data/maps/Route104/scripts.pory"
	.string "Have you filled in any pages yet?$"
# 1284 "data/maps/Route104/scripts.pory"

# 1285 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanDoingGreatLetsBattle:
# 1286 "data/maps/Route104/scripts.pory"
	.string "Me, I'm doing great!\p"
# 1287 "data/maps/Route104/scripts.pory"
	.string "Want to check out how good I am with\n"
# 1288 "data/maps/Route104/scripts.pory"
	.string "a battle?$"
# 1289 "data/maps/Route104/scripts.pory"

# 1290 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanNoConfidence:
# 1291 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1292 "data/maps/Route104/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1293 "data/maps/Route104/scripts.pory"

# 1294 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanLetsBattle:
# 1295 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1296 "data/maps/Route104/scripts.pory"
	.string "Want to have a battle with me?$"
# 1297 "data/maps/Route104/scripts.pory"

# 1298 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanIntro:
# 1299 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1300 "data/maps/Route104/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1301 "data/maps/Route104/scripts.pory"

# 1302 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanDefeat:
# 1303 "data/maps/Route104/scripts.pory"
	.string "Hmm…\n"
# 1304 "data/maps/Route104/scripts.pory"
	.string "You're pretty good.$"
# 1305 "data/maps/Route104/scripts.pory"

# 1306 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanPostBattle:
# 1307 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: You've gotten pretty decent\n"
# 1308 "data/maps/Route104/scripts.pory"
	.string "at handling POKéMON.\p"
# 1309 "data/maps/Route104/scripts.pory"
	.string "But, you know, you shouldn't just be\n"
# 1310 "data/maps/Route104/scripts.pory"
	.string "making POKéMON battle.\p"
# 1311 "data/maps/Route104/scripts.pory"
	.string "Like MR. BRINEY, it's important to\n"
# 1312 "data/maps/Route104/scripts.pory"
	.string "become friends with your POKéMON.$"
# 1313 "data/maps/Route104/scripts.pory"

# 1314 "data/maps/Route104/scripts.pory"
Route104_Text_Reporters:
# 1315 "data/maps/Route104/scripts.pory"
	.string "We are covering an ongoing incident\n"
# 1316 "data/maps/Route104/scripts.pory"
	.string "with Team Aqua and a missing Wingull.\p"
# 1317 "data/maps/Route104/scripts.pory"
	.string "Apologies but we cannot let you\n"
# 1318 "data/maps/Route104/scripts.pory"
	.string "through at this time.$"
