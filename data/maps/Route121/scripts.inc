# 1 "data/maps/Route121/scripts.pory"

# 2 "data/maps/Route121/scripts.pory"
.set LOCALID_GRUNT_1, 12
# 3 "data/maps/Route121/scripts.pory"
.set LOCALID_GRUNT_2, 13
# 4 "data/maps/Route121/scripts.pory"
.set LOCALID_GRUNT_3, 14
# 5 "data/maps/Route121/scripts.pory"
.set LOCALID_CALE, 23
# 6 "data/maps/Route121/scripts.pory"
.set LOCALID_TAMMY, 19
# 7 "data/maps/Route121/scripts.pory"
.set LOCALID_KATE, 10
# 8 "data/maps/Route121/scripts.pory"
.set LOCALID_JOY, 11
# 9 "data/maps/Route121/scripts.pory"
.set LOCALID_MARCEL, 26
# 10 "data/maps/Route121/scripts.pory"
.set LOCALID_CRISTIN, 27
# 11 "data/maps/Route121/scripts.pory"
.set LOCALID_VANESSA, 17
# 12 "data/maps/Route121/scripts.pory"
.set LOCALID_WALTER, 18
# 13 "data/maps/Route121/scripts.pory"
.set LOCALID_MYLES, 24
# 14 "data/maps/Route121/scripts.pory"
.set LOCALID_PAT, 25
# 15 "data/maps/Route121/scripts.pory"

# 16 "data/maps/Route121/scripts.pory"
Route121_MapScripts::
# 17 "data/maps/Route121/scripts.pory"
	.byte 0
# 18 "data/maps/Route121/scripts.pory"

# 19 "data/maps/Route121/scripts.pory"
Route121_EventScript_Woman::
# 20 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_AheadLoomsMtPyre, MSGBOX_NPC
# 21 "data/maps/Route121/scripts.pory"
	end
# 22 "data/maps/Route121/scripts.pory"

# 23 "data/maps/Route121/scripts.pory"
Route121_EventScript_MtPyrePierSign::
# 24 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MtPyrePierSign, MSGBOX_SIGN
# 25 "data/maps/Route121/scripts.pory"
	end
# 26 "data/maps/Route121/scripts.pory"

# 27 "data/maps/Route121/scripts.pory"
Route121_EventScript_SafariZoneSign::
# 28 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_SafariZoneSign, MSGBOX_SIGN
# 29 "data/maps/Route121/scripts.pory"
	end
# 30 "data/maps/Route121/scripts.pory"

# 31 "data/maps/Route121/scripts.pory"
Route121_EventScript_AquaGruntsMoveOut::
# 32 "data/maps/Route121/scripts.pory"
	lockall
# 33 "data/maps/Route121/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 34 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceRight
# 35 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 36 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_OkayMoveOutToMtPyre, MSGBOX_DEFAULT
# 37 "data/maps/Route121/scripts.pory"
	closemessage
# 38 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_1, Route121_Movement_Grunt1Exit
# 39 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_2, Route121_Movement_Grunt2Exit
# 40 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_3, Route121_Movement_Grunt3Exit
# 41 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 42 "data/maps/Route121/scripts.pory"
	fadedefaultbgm
# 43 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 44 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 45 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 46 "data/maps/Route121/scripts.pory"
	setvar VAR_ROUTE121_STATE, 1
# 47 "data/maps/Route121/scripts.pory"
	releaseall
# 48 "data/maps/Route121/scripts.pory"
	end
# 49 "data/maps/Route121/scripts.pory"

# 50 "data/maps/Route121/scripts.pory"
Route121_EventScript_AquaGrunt1::
# 51 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_AquaGrunt1, MSGBOX_DEFAULT
# 52 "data/maps/Route121/scripts.pory"
	closemessage
# 53 "data/maps/Route121/scripts.pory"
	end
# 54 "data/maps/Route121/scripts.pory"

# 55 "data/maps/Route121/scripts.pory"
Route121_EventScript_AquaGrunt2::
# 56 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_AquaGrunt2, MSGBOX_DEFAULT
# 57 "data/maps/Route121/scripts.pory"
	closemessage
# 58 "data/maps/Route121/scripts.pory"
	end
# 59 "data/maps/Route121/scripts.pory"

# 60 "data/maps/Route121/scripts.pory"
Route121_EventScript_AquaGrunt3::
# 61 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_AquaGrunt3, MSGBOX_DEFAULT
# 62 "data/maps/Route121/scripts.pory"
	closemessage
# 63 "data/maps/Route121/scripts.pory"
	end
# 64 "data/maps/Route121/scripts.pory"

# 65 "data/maps/Route121/scripts.pory"
Route121_EventScript_MagmaGrunt1::
# 66 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MagmaGrunt1, MSGBOX_DEFAULT
# 67 "data/maps/Route121/scripts.pory"
	closemessage
# 68 "data/maps/Route121/scripts.pory"
	end
# 69 "data/maps/Route121/scripts.pory"

# 70 "data/maps/Route121/scripts.pory"
Route121_EventScript_MagmaGrunt2::
# 71 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MagmaGrunt2, MSGBOX_DEFAULT
# 72 "data/maps/Route121/scripts.pory"
	closemessage
# 73 "data/maps/Route121/scripts.pory"
	end
# 74 "data/maps/Route121/scripts.pory"

# 75 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt1Exit:
# 76 "data/maps/Route121/scripts.pory"
	walk_down
# 77 "data/maps/Route121/scripts.pory"
	walk_down
# 78 "data/maps/Route121/scripts.pory"
	walk_down
# 79 "data/maps/Route121/scripts.pory"
	walk_down
# 80 "data/maps/Route121/scripts.pory"
	walk_down
# 81 "data/maps/Route121/scripts.pory"
	walk_down
# 82 "data/maps/Route121/scripts.pory"
	walk_down
# 83 "data/maps/Route121/scripts.pory"
	walk_down
# 84 "data/maps/Route121/scripts.pory"
	step_end
# 85 "data/maps/Route121/scripts.pory"

# 86 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt2Exit:
# 87 "data/maps/Route121/scripts.pory"
	walk_down
# 88 "data/maps/Route121/scripts.pory"
	walk_down
# 89 "data/maps/Route121/scripts.pory"
	walk_down
# 90 "data/maps/Route121/scripts.pory"
	walk_down
# 91 "data/maps/Route121/scripts.pory"
	walk_down
# 92 "data/maps/Route121/scripts.pory"
	walk_down
# 93 "data/maps/Route121/scripts.pory"
	walk_down
# 94 "data/maps/Route121/scripts.pory"
	walk_down
# 95 "data/maps/Route121/scripts.pory"
	step_end
# 96 "data/maps/Route121/scripts.pory"

# 97 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt3Exit:
# 98 "data/maps/Route121/scripts.pory"
	walk_down
# 99 "data/maps/Route121/scripts.pory"
	walk_down
# 100 "data/maps/Route121/scripts.pory"
	walk_down
# 101 "data/maps/Route121/scripts.pory"
	walk_down
# 102 "data/maps/Route121/scripts.pory"
	walk_down
# 103 "data/maps/Route121/scripts.pory"
	walk_down
# 104 "data/maps/Route121/scripts.pory"
	walk_down
# 105 "data/maps/Route121/scripts.pory"
	walk_down
# 106 "data/maps/Route121/scripts.pory"
	step_end
# 107 "data/maps/Route121/scripts.pory"

# 108 "data/maps/Route121/scripts.pory"
Route121_EventScript_Vanessa::
# 109 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_VanessaPostBattle, MSGBOX_AUTOCLOSE
# 110 "data/maps/Route121/scripts.pory"
	end
# 111 "data/maps/Route121/scripts.pory"

# 112 "data/maps/Route121/scripts.pory"
Route121_EventScript_VanessaWalter::
# 113 "data/maps/Route121/scripts.pory"
lockall
# 114 "data/maps/Route121/scripts.pory"
setvar VAR_0x8008, LOCALID_VANESSA
# 115 "data/maps/Route121/scripts.pory"
playse SE_PIN
# 116 "data/maps/Route121/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 117 "data/maps/Route121/scripts.pory"
waitmovement 0
# 118 "data/maps/Route121/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 119 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 120 "data/maps/Route121/scripts.pory"
waitmovement 0
# 121 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_VanessaIntro MSGBOX_AUTOCLOSE
# 122 "data/maps/Route121/scripts.pory"
setvar VAR_0x8008, LOCALID_WALTER
# 123 "data/maps/Route121/scripts.pory"
playse SE_PIN
# 124 "data/maps/Route121/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 125 "data/maps/Route121/scripts.pory"
waitmovement 0
# 126 "data/maps/Route121/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 127 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 128 "data/maps/Route121/scripts.pory"
waitmovement 0
# 129 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_WalterIntro MSGBOX_AUTOCLOSE
# 130 "data/maps/Route121/scripts.pory"
goto Route121_EventScript_VanessaWalterDoMultiBattle
# 131 "data/maps/Route121/scripts.pory"
releaseall
# 132 "data/maps/Route121/scripts.pory"
end
# 133 "data/maps/Route121/scripts.pory"

# 134 "data/maps/Route121/scripts.pory"
Route121_EventScript_VanessaWalterDoMultiBattle::
# 135 "data/maps/Route121/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 136 "data/maps/Route121/scripts.pory"
multi_2p_vs_2 TRAINER_VANESSA, Route121_Text_VanessaDefeat, TRAINER_WALTER_1, Route121_Text_WalterDefeat, PARTNER_EMMIE
# 137 "data/maps/Route121/scripts.pory"
switch VAR_RESULT
# 138 "data/maps/Route121/scripts.pory"
case 1, Route121_EventScript_VanessaWalterVictory
# 139 "data/maps/Route121/scripts.pory"
fadescreen FADE_TO_BLACK
# 140 "data/maps/Route121/scripts.pory"
special SetCB2WhiteOut
# 141 "data/maps/Route121/scripts.pory"
waitstate
# 142 "data/maps/Route121/scripts.pory"

# 143 "data/maps/Route121/scripts.pory"
Route121_EventScript_VanessaWalterVictory::
# 144 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 145 "data/maps/Route121/scripts.pory"
waitmovement 0
# 146 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_VanessaPostBattle, MSGBOX_AUTOCLOSE
# 147 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 148 "data/maps/Route121/scripts.pory"
waitmovement 0
# 149 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_WalterPostBattle, MSGBOX_AUTOCLOSE
# 150 "data/maps/Route121/scripts.pory"
addvar VAR_ROUTE121_STATE, 1
# 151 "data/maps/Route121/scripts.pory"
end
# 152 "data/maps/Route121/scripts.pory"

# 153 "data/maps/Route121/scripts.pory"
Route121_EventScript_Walter::
# 154 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterPostBattle, MSGBOX_DEFAULT
# 155 "data/maps/Route121/scripts.pory"
	release
# 156 "data/maps/Route121/scripts.pory"
	end
# 157 "data/maps/Route121/scripts.pory"

# 158 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterWalter::
# 159 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 160 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 161 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterRegister, MSGBOX_DEFAULT
# 162 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_WALTER_1
# 163 "data/maps/Route121/scripts.pory"
	release
# 164 "data/maps/Route121/scripts.pory"
	end
# 165 "data/maps/Route121/scripts.pory"

# 166 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchWalter::
# 167 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_WALTER_1, Route121_Text_WalterRematchIntro, Route121_Text_WalterRematchDefeat
# 168 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterPostRematch, MSGBOX_AUTOCLOSE
# 169 "data/maps/Route121/scripts.pory"
	end
# 170 "data/maps/Route121/scripts.pory"

# 171 "data/maps/Route121/scripts.pory"
Route121_EventScript_Tammy::
# 172 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
# 173 "data/maps/Route121/scripts.pory"
	end
# 174 "data/maps/Route121/scripts.pory"

# 175 "data/maps/Route121/scripts.pory"
Route121_EventScript_KateJoy::
# 176 "data/maps/Route121/scripts.pory"
lockall
# 177 "data/maps/Route121/scripts.pory"
setvar VAR_0x8008, LOCALID_KATE
# 178 "data/maps/Route121/scripts.pory"
playse SE_PIN
# 179 "data/maps/Route121/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 180 "data/maps/Route121/scripts.pory"
applymovement LOCALID_JOY, Common_Movement_ExclamationMark
# 181 "data/maps/Route121/scripts.pory"
waitmovement 0
# 182 "data/maps/Route121/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 183 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 184 "data/maps/Route121/scripts.pory"
waitmovement 0
# 185 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_KateIntro MSGBOX_AUTOCLOSE
# 186 "data/maps/Route121/scripts.pory"
goto Route121_EventScript_KateJoyDoMultiBattle
# 187 "data/maps/Route121/scripts.pory"
releaseall
# 188 "data/maps/Route121/scripts.pory"
end
# 189 "data/maps/Route121/scripts.pory"

# 190 "data/maps/Route121/scripts.pory"
Route121_EventScript_KateJoyDoMultiBattle::
# 191 "data/maps/Route121/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 192 "data/maps/Route121/scripts.pory"
multi_2p_vs_1 TRAINER_KATE_AND_JOY, Route121_Text_KateDefeat, PARTNER_EMMIE
# 193 "data/maps/Route121/scripts.pory"
switch VAR_RESULT
# 194 "data/maps/Route121/scripts.pory"
case 1, Route121_EventScript_KateJoyVictory
# 195 "data/maps/Route121/scripts.pory"
fadescreen FADE_TO_BLACK
# 196 "data/maps/Route121/scripts.pory"
special SetCB2WhiteOut
# 197 "data/maps/Route121/scripts.pory"
waitstate
# 198 "data/maps/Route121/scripts.pory"

# 199 "data/maps/Route121/scripts.pory"
Route121_EventScript_KateJoyVictory::
# 200 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 201 "data/maps/Route121/scripts.pory"
waitmovement 0
# 202 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
# 203 "data/maps/Route121/scripts.pory"
addvar VAR_ROUTE121_STATE, 1
# 204 "data/maps/Route121/scripts.pory"
end
# 205 "data/maps/Route121/scripts.pory"

# 206 "data/maps/Route121/scripts.pory"
Route121_EventScript_Kate::
# 207 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
# 208 "data/maps/Route121/scripts.pory"
	end
# 209 "data/maps/Route121/scripts.pory"

# 210 "data/maps/Route121/scripts.pory"
Route121_EventScript_Joy::
# 211 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
# 212 "data/maps/Route121/scripts.pory"
	end
# 213 "data/maps/Route121/scripts.pory"

# 214 "data/maps/Route121/scripts.pory"
Route121_EventScript_Jessica::
# 215 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_JESSICA_1, Route121_Text_JessicaIntro, Route121_Text_JessicaDefeat, Route121_EventScript_RegisterJessica
# 216 "data/maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 217 "data/maps/Route121/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchJessica
# 218 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaPostBattle, MSGBOX_DEFAULT
# 219 "data/maps/Route121/scripts.pory"
	release
# 220 "data/maps/Route121/scripts.pory"
	end
# 221 "data/maps/Route121/scripts.pory"

# 222 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterJessica::
# 223 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 224 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 225 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaRegister, MSGBOX_DEFAULT
# 226 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_JESSICA_1
# 227 "data/maps/Route121/scripts.pory"
	release
# 228 "data/maps/Route121/scripts.pory"
	end
# 229 "data/maps/Route121/scripts.pory"

# 230 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchJessica::
# 231 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_JESSICA_1, Route121_Text_JessicaRematchIntro, Route121_Text_JessicaRematchDefeat
# 232 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaPostRematch, MSGBOX_AUTOCLOSE
# 233 "data/maps/Route121/scripts.pory"
	end
# 234 "data/maps/Route121/scripts.pory"

# 235 "data/maps/Route121/scripts.pory"
Route121_EventScript_Cale::
# 236 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CalePostBattle, MSGBOX_AUTOCLOSE
# 237 "data/maps/Route121/scripts.pory"
	end
# 238 "data/maps/Route121/scripts.pory"

# 239 "data/maps/Route121/scripts.pory"
Route121_EventScript_CaleTammy::
# 240 "data/maps/Route121/scripts.pory"
lockall
# 241 "data/maps/Route121/scripts.pory"
setvar VAR_0x8008, LOCALID_CALE
# 242 "data/maps/Route121/scripts.pory"
playse SE_PIN
# 243 "data/maps/Route121/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 244 "data/maps/Route121/scripts.pory"
waitmovement 0
# 245 "data/maps/Route121/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 246 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 247 "data/maps/Route121/scripts.pory"
waitmovement 0
# 248 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_CaleIntro MSGBOX_AUTOCLOSE
# 249 "data/maps/Route121/scripts.pory"
setvar VAR_0x8008, LOCALID_TAMMY
# 250 "data/maps/Route121/scripts.pory"
playse SE_PIN
# 251 "data/maps/Route121/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 252 "data/maps/Route121/scripts.pory"
waitmovement 0
# 253 "data/maps/Route121/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 254 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 255 "data/maps/Route121/scripts.pory"
waitmovement 0
# 256 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_TammyIntro MSGBOX_AUTOCLOSE
# 257 "data/maps/Route121/scripts.pory"
goto Route121_EventScript_CaleTammyDoMultiBattle
# 258 "data/maps/Route121/scripts.pory"
releaseall
# 259 "data/maps/Route121/scripts.pory"
end
# 260 "data/maps/Route121/scripts.pory"

# 261 "data/maps/Route121/scripts.pory"
Route121_EventScript_CaleTammyDoMultiBattle::
# 262 "data/maps/Route121/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 263 "data/maps/Route121/scripts.pory"
multi_2p_vs_2 TRAINER_CALE, Route121_Text_CaleDefeat, TRAINER_TAMMY, Route121_Text_TammyDefeat, PARTNER_EMMIE
# 264 "data/maps/Route121/scripts.pory"
switch VAR_RESULT
# 265 "data/maps/Route121/scripts.pory"
case 1, Route121_EventScript_CaleTammyVictory
# 266 "data/maps/Route121/scripts.pory"
fadescreen FADE_TO_BLACK
# 267 "data/maps/Route121/scripts.pory"
special SetCB2WhiteOut
# 268 "data/maps/Route121/scripts.pory"
waitstate
# 269 "data/maps/Route121/scripts.pory"

# 270 "data/maps/Route121/scripts.pory"
Route121_EventScript_CaleTammyVictory::
# 271 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 272 "data/maps/Route121/scripts.pory"
waitmovement 0
# 273 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_CalePostBattle, MSGBOX_AUTOCLOSE
# 274 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 275 "data/maps/Route121/scripts.pory"
waitmovement 0
# 276 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
# 277 "data/maps/Route121/scripts.pory"
addvar VAR_ROUTE121_STATE, 1
# 278 "data/maps/Route121/scripts.pory"
end
# 279 "data/maps/Route121/scripts.pory"

# 280 "data/maps/Route121/scripts.pory"
Route121_EventScript_PatMyles::
# 281 "data/maps/Route121/scripts.pory"
lockall
# 282 "data/maps/Route121/scripts.pory"
setvar VAR_0x8008, LOCALID_PAT
# 283 "data/maps/Route121/scripts.pory"
playse SE_PIN
# 284 "data/maps/Route121/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 285 "data/maps/Route121/scripts.pory"
waitmovement 0
# 286 "data/maps/Route121/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 287 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 288 "data/maps/Route121/scripts.pory"
waitmovement 0
# 289 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_PatIntro MSGBOX_AUTOCLOSE
# 290 "data/maps/Route121/scripts.pory"
setvar VAR_0x8008, LOCALID_MYLES
# 291 "data/maps/Route121/scripts.pory"
playse SE_PIN
# 292 "data/maps/Route121/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 293 "data/maps/Route121/scripts.pory"
waitmovement 0
# 294 "data/maps/Route121/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 295 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 296 "data/maps/Route121/scripts.pory"
waitmovement 0
# 297 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_MylesIntro MSGBOX_AUTOCLOSE
# 298 "data/maps/Route121/scripts.pory"
goto Route121_EventScript_PatMylesDoMultiBattle
# 299 "data/maps/Route121/scripts.pory"
releaseall
# 300 "data/maps/Route121/scripts.pory"
end
# 301 "data/maps/Route121/scripts.pory"

# 302 "data/maps/Route121/scripts.pory"
Route121_EventScript_PatMylesDoMultiBattle::
# 303 "data/maps/Route121/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 304 "data/maps/Route121/scripts.pory"
multi_2p_vs_2 TRAINER_PAT, Route121_Text_PatDefeat, TRAINER_MYLES, Route121_Text_MylesDefeat, PARTNER_EMMIE
# 305 "data/maps/Route121/scripts.pory"
switch VAR_RESULT
# 306 "data/maps/Route121/scripts.pory"
case 1, Route121_EventScript_PatMylesVictory
# 307 "data/maps/Route121/scripts.pory"
fadescreen FADE_TO_BLACK
# 308 "data/maps/Route121/scripts.pory"
special SetCB2WhiteOut
# 309 "data/maps/Route121/scripts.pory"
waitstate
# 310 "data/maps/Route121/scripts.pory"

# 311 "data/maps/Route121/scripts.pory"
Route121_EventScript_PatMylesVictory::
# 312 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 313 "data/maps/Route121/scripts.pory"
waitmovement 0
# 314 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_PatPostBattle, MSGBOX_AUTOCLOSE
# 315 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 316 "data/maps/Route121/scripts.pory"
waitmovement 0
# 317 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
# 318 "data/maps/Route121/scripts.pory"
addvar VAR_ROUTE121_STATE, 1
# 319 "data/maps/Route121/scripts.pory"
end
# 320 "data/maps/Route121/scripts.pory"

# 321 "data/maps/Route121/scripts.pory"
Route121_EventScript_Myles::
# 322 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
# 323 "data/maps/Route121/scripts.pory"
	end
# 324 "data/maps/Route121/scripts.pory"

# 325 "data/maps/Route121/scripts.pory"
Route121_EventScript_Pat::
# 326 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_PatPostBattle, MSGBOX_AUTOCLOSE
# 327 "data/maps/Route121/scripts.pory"
	end
# 328 "data/maps/Route121/scripts.pory"

# 329 "data/maps/Route121/scripts.pory"
Route121_EventScript_Marcel::
# 330 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
# 331 "data/maps/Route121/scripts.pory"
	end
# 332 "data/maps/Route121/scripts.pory"

# 333 "data/maps/Route121/scripts.pory"
Route121_EventScript_MarcelCristin::
# 334 "data/maps/Route121/scripts.pory"
lockall
# 335 "data/maps/Route121/scripts.pory"
setvar VAR_0x8008, LOCALID_MARCEL
# 336 "data/maps/Route121/scripts.pory"
playse SE_PIN
# 337 "data/maps/Route121/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 338 "data/maps/Route121/scripts.pory"
waitmovement 0
# 339 "data/maps/Route121/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 340 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 341 "data/maps/Route121/scripts.pory"
waitmovement 0
# 342 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_MarcelIntro MSGBOX_AUTOCLOSE
# 343 "data/maps/Route121/scripts.pory"
setvar VAR_0x8008, LOCALID_CRISTIN
# 344 "data/maps/Route121/scripts.pory"
playse SE_PIN
# 345 "data/maps/Route121/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 346 "data/maps/Route121/scripts.pory"
waitmovement 0
# 347 "data/maps/Route121/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 348 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 349 "data/maps/Route121/scripts.pory"
waitmovement 0
# 350 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_CristinIntro MSGBOX_AUTOCLOSE
# 351 "data/maps/Route121/scripts.pory"
goto Route121_EventScript_MarcelCristinDoMultiBattle
# 352 "data/maps/Route121/scripts.pory"
releaseall
# 353 "data/maps/Route121/scripts.pory"
end
# 354 "data/maps/Route121/scripts.pory"

# 355 "data/maps/Route121/scripts.pory"
Route121_EventScript_MarcelCristinDoMultiBattle::
# 356 "data/maps/Route121/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 357 "data/maps/Route121/scripts.pory"
multi_2p_vs_2 TRAINER_MARCEL, Route121_Text_MarcelDefeat, TRAINER_CRISTIN_1, Route121_Text_CristinDefeat, PARTNER_EMMIE
# 358 "data/maps/Route121/scripts.pory"
switch VAR_RESULT
# 359 "data/maps/Route121/scripts.pory"
case 1, Route121_EventScript_MarcelCristinVictory
# 360 "data/maps/Route121/scripts.pory"
fadescreen FADE_TO_BLACK
# 361 "data/maps/Route121/scripts.pory"
special SetCB2WhiteOut
# 362 "data/maps/Route121/scripts.pory"
waitstate
# 363 "data/maps/Route121/scripts.pory"

# 364 "data/maps/Route121/scripts.pory"
Route121_EventScript_MarcelCristinVictory::
# 365 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 366 "data/maps/Route121/scripts.pory"
waitmovement 0
# 367 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
# 368 "data/maps/Route121/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 369 "data/maps/Route121/scripts.pory"
waitmovement 0
# 370 "data/maps/Route121/scripts.pory"
msgbox Route121_Text_CristinPostBattle, MSGBOX_AUTOCLOSE
# 371 "data/maps/Route121/scripts.pory"
addvar VAR_ROUTE121_STATE, 1
# 372 "data/maps/Route121/scripts.pory"
end
# 373 "data/maps/Route121/scripts.pory"

# 374 "data/maps/Route121/scripts.pory"
Route121_EventScript_Cristin::
# 375 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinPostBattle, MSGBOX_DEFAULT
# 376 "data/maps/Route121/scripts.pory"
	release
# 377 "data/maps/Route121/scripts.pory"
	end
# 378 "data/maps/Route121/scripts.pory"

# 379 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterCristin::
# 380 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 381 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 382 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinRegister, MSGBOX_DEFAULT
# 383 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_CRISTIN_1
# 384 "data/maps/Route121/scripts.pory"
	release
# 385 "data/maps/Route121/scripts.pory"
	end
# 386 "data/maps/Route121/scripts.pory"

# 387 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchCristin::
# 388 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_CRISTIN_1, Route121_Text_CristinRematchIntro, Route121_Text_CristinRematchDefeat
# 389 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinPostRematch, MSGBOX_AUTOCLOSE
# 390 "data/maps/Route121/scripts.pory"
	end
# 391 "data/maps/Route121/scripts.pory"

# 392 "data/maps/Route121/scripts.pory"
Route121_Text_OkayMoveOutToMtPyre:
# 393 "data/maps/Route121/scripts.pory"
	.string "Okay!\n"
# 394 "data/maps/Route121/scripts.pory"
	.string "We're to move out to MT. PYRE!$"
# 395 "data/maps/Route121/scripts.pory"

# 396 "data/maps/Route121/scripts.pory"
Route121_Text_AheadLoomsMtPyre:
# 397 "data/maps/Route121/scripts.pory"
	.string "Ahead looms MT. PYRE…\p"
# 398 "data/maps/Route121/scripts.pory"
	.string "It is a natural monument to the spirits \n"
# 399 "data/maps/Route121/scripts.pory"
	.string "of departed POKéMON…$"
# 400 "data/maps/Route121/scripts.pory"

# 401 "data/maps/Route121/scripts.pory"
Route121_Text_MtPyrePierSign:
# 402 "data/maps/Route121/scripts.pory"
	.string "MT. PYRE PIER\p"
# 403 "data/maps/Route121/scripts.pory"
	.string "…The sign is old and worn out.\n"
# 404 "data/maps/Route121/scripts.pory"
	.string "The words are barely legible…$"
# 405 "data/maps/Route121/scripts.pory"

# 406 "data/maps/Route121/scripts.pory"
Route121_Text_SafariZoneSign:
# 407 "data/maps/Route121/scripts.pory"
	.string "“Filled with rare POKéMON!”\n"
# 408 "data/maps/Route121/scripts.pory"
	.string "SAFARI ZONE$"
# 409 "data/maps/Route121/scripts.pory"

# 410 "data/maps/Route121/scripts.pory"
Route121_Text_AquaGrunt1:
# 411 "data/maps/Route121/scripts.pory"
	.string "Beat it kid!$"
# 412 "data/maps/Route121/scripts.pory"

# 413 "data/maps/Route121/scripts.pory"
Route121_Text_AquaGrunt2:
# 414 "data/maps/Route121/scripts.pory"
	.string "Team Aqua control this area!$"
# 415 "data/maps/Route121/scripts.pory"

# 416 "data/maps/Route121/scripts.pory"
Route121_Text_AquaGrunt3:
# 417 "data/maps/Route121/scripts.pory"
	.string "We're standing guard until the boss\n"
# 418 "data/maps/Route121/scripts.pory"
	.string "tells us to stand down!$"
# 419 "data/maps/Route121/scripts.pory"

# 420 "data/maps/Route121/scripts.pory"
Route121_Text_MagmaGrunt1:
# 421 "data/maps/Route121/scripts.pory"
	.string "Team Magma have this area under control!$"
# 422 "data/maps/Route121/scripts.pory"

# 423 "data/maps/Route121/scripts.pory"
Route121_Text_MagmaGrunt2:
# 424 "data/maps/Route121/scripts.pory"
	.string "Nobody goes through this area while\n"
# 425 "data/maps/Route121/scripts.pory"
	.string "Team Magma operate in Mt. Pyre!$"
