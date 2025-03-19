# 1 "data/maps/Route123/scripts.pory"

# 2 "data/maps/Route123/scripts.pory"
.set LOCALID_DAVIS, 42
# 3 "data/maps/Route123/scripts.pory"
.set LOCALID_JAZMYN, 41
# 4 "data/maps/Route123/scripts.pory"
.set LOCALID_JACKI, 30
# 5 "data/maps/Route123/scripts.pory"
.set LOCALID_FREDERICK, 39
# 6 "data/maps/Route123/scripts.pory"
.set LOCALID_BRAXTON, 9
# 7 "data/maps/Route123/scripts.pory"
.set LOCALID_WENDY, 8
# 8 "data/maps/Route123/scripts.pory"
.set LOCALID_MIU, 28
# 9 "data/maps/Route123/scripts.pory"
.set LOCALID_YUKI, 27
# 10 "data/maps/Route123/scripts.pory"
.set LOCALID_VIOLET, 26
# 11 "data/maps/Route123/scripts.pory"
.set LOCALID_CAMERON, 29
# 12 "data/maps/Route123/scripts.pory"
.set LOCALID_ALBERTO, 38
# 13 "data/maps/Route123/scripts.pory"
.set LOCALID_FERNANDO, 37
# 14 "data/maps/Route123/scripts.pory"
.set LOCALID_ED, 36
# 15 "data/maps/Route123/scripts.pory"
.set LOCALID_KINDRA, 31
# 16 "data/maps/Route123/scripts.pory"
.set LOCALID_KAYLEY, 35
# 17 "data/maps/Route123/scripts.pory"
.set LOCALID_JONAS, 34
# 18 "data/maps/Route123/scripts.pory"

# 19 "data/maps/Route123/scripts.pory"
Route123_MapScripts::
# 20 "data/maps/Route123/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
# 21 "data/maps/Route123/scripts.pory"
	.byte 0
# 22 "data/maps/Route123/scripts.pory"

# 23 "data/maps/Route123/scripts.pory"
Route123_OnTransition:
# 24 "data/maps/Route123/scripts.pory"
	special SetRoute123Weather
# 25 "data/maps/Route123/scripts.pory"
	end
# 26 "data/maps/Route123/scripts.pory"

# 27 "data/maps/Route123/scripts.pory"
Route123_EventScript_GigaDrainGirl::
# 28 "data/maps/Route123/scripts.pory"
	lock
# 29 "data/maps/Route123/scripts.pory"
	faceplayer
# 30 "data/maps/Route123/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_GIGA_DRAIN, Route123_EventScript_ReceivedGigaDrain
# 31 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_LoveGrassMonsHaveAny, MSGBOX_DEFAULT
# 32 "data/maps/Route123/scripts.pory"
	special IsGrassTypeInParty
# 33 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route123_EventScript_NoGrassMons
# 34 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_YouLikeGrassMonsTooHaveThis, MSGBOX_DEFAULT
# 35 "data/maps/Route123/scripts.pory"
	giveitem ITEM_TM_GIGA_DRAIN
# 36 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 37 "data/maps/Route123/scripts.pory"
	setflag FLAG_RECEIVED_TM_GIGA_DRAIN
# 38 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 39 "data/maps/Route123/scripts.pory"
	release
# 40 "data/maps/Route123/scripts.pory"
	end
# 41 "data/maps/Route123/scripts.pory"

# 42 "data/maps/Route123/scripts.pory"
Route123_EventScript_NoGrassMons::
# 43 "data/maps/Route123/scripts.pory"
	release
# 44 "data/maps/Route123/scripts.pory"
	end
# 45 "data/maps/Route123/scripts.pory"

# 46 "data/maps/Route123/scripts.pory"
Route123_EventScript_ReceivedGigaDrain::
# 47 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 48 "data/maps/Route123/scripts.pory"
	release
# 49 "data/maps/Route123/scripts.pory"
	end
# 50 "data/maps/Route123/scripts.pory"

# 51 "data/maps/Route123/scripts.pory"
Route123_EventScript_RouteSign::
# 52 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
# 53 "data/maps/Route123/scripts.pory"
	end
# 54 "data/maps/Route123/scripts.pory"

# 55 "data/maps/Route123/scripts.pory"
Route123_EventScript_RouteSignMtPyre::
# 56 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
# 57 "data/maps/Route123/scripts.pory"
	end
# 58 "data/maps/Route123/scripts.pory"

# 59 "data/maps/Route123/scripts.pory"
Route123_EventScript_BerryMastersHouseSign::
# 60 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
# 61 "data/maps/Route123/scripts.pory"
	end
# 62 "data/maps/Route123/scripts.pory"

# 63 "data/maps/Route123/scripts.pory"
Route123_EventScript_BraxtonWendy::
# 64 "data/maps/Route123/scripts.pory"
lockall
# 65 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_BRAXTON
# 66 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 67 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 68 "data/maps/Route123/scripts.pory"
waitmovement 0
# 69 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 70 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 71 "data/maps/Route123/scripts.pory"
waitmovement 0
# 72 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_BraxtonIntro MSGBOX_AUTOCLOSE
# 73 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_WENDY
# 74 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 75 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 76 "data/maps/Route123/scripts.pory"
waitmovement 0
# 77 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 78 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 79 "data/maps/Route123/scripts.pory"
waitmovement 0
# 80 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_WendyIntro MSGBOX_AUTOCLOSE
# 81 "data/maps/Route123/scripts.pory"
goto Route123_EventScript_BraxtonWendyDoMultiBattle
# 82 "data/maps/Route123/scripts.pory"
releaseall
# 83 "data/maps/Route123/scripts.pory"
end
# 84 "data/maps/Route123/scripts.pory"

# 85 "data/maps/Route123/scripts.pory"
Route123_EventScript_BraxtonWendyDoMultiBattle::
# 86 "data/maps/Route123/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 87 "data/maps/Route123/scripts.pory"
multi_2p_vs_2 TRAINER_BRAXTON, Route123_Text_BraxtonDefeat, TRAINER_WENDY, Route123_Text_WendyDefeat, PARTNER_EMMIE
# 88 "data/maps/Route123/scripts.pory"
switch VAR_RESULT
# 89 "data/maps/Route123/scripts.pory"
case 1, Route123_EventScript_BraxtonWendyVictory
# 90 "data/maps/Route123/scripts.pory"
fadescreen FADE_TO_BLACK
# 91 "data/maps/Route123/scripts.pory"
special SetCB2WhiteOut
# 92 "data/maps/Route123/scripts.pory"
waitstate
# 93 "data/maps/Route123/scripts.pory"

# 94 "data/maps/Route123/scripts.pory"
Route123_EventScript_BraxtonWendyVictory::
# 95 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 96 "data/maps/Route123/scripts.pory"
waitmovement 0
# 97 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
# 98 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 99 "data/maps/Route123/scripts.pory"
waitmovement 0
# 100 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
# 101 "data/maps/Route123/scripts.pory"
addvar VAR_ROUTE123_STATE, 1
# 102 "data/maps/Route123/scripts.pory"
end
# 103 "data/maps/Route123/scripts.pory"

# 104 "data/maps/Route123/scripts.pory"
Route123_EventScript_Wendy::
# 105 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
# 106 "data/maps/Route123/scripts.pory"
	end
# 107 "data/maps/Route123/scripts.pory"

# 108 "data/maps/Route123/scripts.pory"
Route123_EventScript_Braxton::
# 109 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
# 110 "data/maps/Route123/scripts.pory"
	end
# 111 "data/maps/Route123/scripts.pory"

# 112 "data/maps/Route123/scripts.pory"
Route123_EventScript_Violet::
# 113 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
# 114 "data/maps/Route123/scripts.pory"
	end
# 115 "data/maps/Route123/scripts.pory"

# 116 "data/maps/Route123/scripts.pory"
Route123_EventScript_CameronViolet::
# 117 "data/maps/Route123/scripts.pory"
lockall
# 118 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_CAMERON
# 119 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 120 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 121 "data/maps/Route123/scripts.pory"
waitmovement 0
# 122 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 123 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 124 "data/maps/Route123/scripts.pory"
waitmovement 0
# 125 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_CameronIntro MSGBOX_AUTOCLOSE
# 126 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_VIOLET
# 127 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 128 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 129 "data/maps/Route123/scripts.pory"
waitmovement 0
# 130 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 131 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 132 "data/maps/Route123/scripts.pory"
waitmovement 0
# 133 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_VioletIntro MSGBOX_AUTOCLOSE
# 134 "data/maps/Route123/scripts.pory"
goto Route123_EventScript_CameronVioletDoMultiBattle
# 135 "data/maps/Route123/scripts.pory"
releaseall
# 136 "data/maps/Route123/scripts.pory"
end
# 137 "data/maps/Route123/scripts.pory"

# 138 "data/maps/Route123/scripts.pory"
Route123_EventScript_CameronVioletDoMultiBattle::
# 139 "data/maps/Route123/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 140 "data/maps/Route123/scripts.pory"
multi_2p_vs_2 TRAINER_CAMERON_1, Route123_Text_CameronDefeat, TRAINER_VIOLET, Route123_Text_VioletDefeat, PARTNER_EMMIE
# 141 "data/maps/Route123/scripts.pory"
switch VAR_RESULT
# 142 "data/maps/Route123/scripts.pory"
case 1, Route123_EventScript_CameronVioletVictory
# 143 "data/maps/Route123/scripts.pory"
fadescreen FADE_TO_BLACK
# 144 "data/maps/Route123/scripts.pory"
special SetCB2WhiteOut
# 145 "data/maps/Route123/scripts.pory"
waitstate
# 146 "data/maps/Route123/scripts.pory"

# 147 "data/maps/Route123/scripts.pory"
Route123_EventScript_CameronVioletVictory::
# 148 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 149 "data/maps/Route123/scripts.pory"
waitmovement 0
# 150 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
# 151 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 152 "data/maps/Route123/scripts.pory"
waitmovement 0
# 153 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
# 154 "data/maps/Route123/scripts.pory"
addvar VAR_ROUTE123_STATE, 1
# 155 "data/maps/Route123/scripts.pory"
end
# 156 "data/maps/Route123/scripts.pory"

# 157 "data/maps/Route123/scripts.pory"
Route123_EventScript_Cameron::
# 158 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostBattle, MSGBOX_DEFAULT
# 159 "data/maps/Route123/scripts.pory"
	release
# 160 "data/maps/Route123/scripts.pory"
	end
# 161 "data/maps/Route123/scripts.pory"

# 162 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterCameron::
# 163 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 164 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 165 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronRegister, MSGBOX_DEFAULT
# 166 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_CAMERON_1
# 167 "data/maps/Route123/scripts.pory"
	release
# 168 "data/maps/Route123/scripts.pory"
	end
# 169 "data/maps/Route123/scripts.pory"

# 170 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchCameron::
# 171 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_CameronRematchIntro, Route123_Text_CameronRematchDefeat
# 172 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostRematch, MSGBOX_AUTOCLOSE
# 173 "data/maps/Route123/scripts.pory"
	end
# 174 "data/maps/Route123/scripts.pory"

# 175 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jacki::
# 176 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostBattle, MSGBOX_DEFAULT
# 177 "data/maps/Route123/scripts.pory"
	release
# 178 "data/maps/Route123/scripts.pory"
	end
# 179 "data/maps/Route123/scripts.pory"

# 180 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterJacki::
# 181 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 182 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 183 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiRegister, MSGBOX_DEFAULT
# 184 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_JACKI_1
# 185 "data/maps/Route123/scripts.pory"
	release
# 186 "data/maps/Route123/scripts.pory"
	end
# 187 "data/maps/Route123/scripts.pory"

# 188 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchJacki::
# 189 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_JACKI_1, Route123_Text_JackiRematchIntro, Route123_Text_JackiRematchDefeat
# 190 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostRematch, MSGBOX_AUTOCLOSE
# 191 "data/maps/Route123/scripts.pory"
	end
# 192 "data/maps/Route123/scripts.pory"

# 193 "data/maps/Route123/scripts.pory"
Route123_EventScript_YukiMiu::
# 194 "data/maps/Route123/scripts.pory"
lockall
# 195 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_YUKI
# 196 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 197 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 198 "data/maps/Route123/scripts.pory"
waitmovement 0
# 199 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 200 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 201 "data/maps/Route123/scripts.pory"
waitmovement 0
# 202 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_YukiIntro MSGBOX_AUTOCLOSE
# 203 "data/maps/Route123/scripts.pory"
goto Route123_EventScript_YukiMiuDoMultiBattle
# 204 "data/maps/Route123/scripts.pory"
releaseall
# 205 "data/maps/Route123/scripts.pory"
end
# 206 "data/maps/Route123/scripts.pory"

# 207 "data/maps/Route123/scripts.pory"
Route123_EventScript_YukiMiuDoMultiBattle::
# 208 "data/maps/Route123/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 209 "data/maps/Route123/scripts.pory"
multi_2p_vs_1 TRAINER_MIU_AND_YUKI, Route123_Text_YukiDefeat, PARTNER_EMMIE
# 210 "data/maps/Route123/scripts.pory"
switch VAR_RESULT
# 211 "data/maps/Route123/scripts.pory"
case 1, Route123_EventScript_YukiMiuVictory
# 212 "data/maps/Route123/scripts.pory"
fadescreen FADE_TO_BLACK
# 213 "data/maps/Route123/scripts.pory"
special SetCB2WhiteOut
# 214 "data/maps/Route123/scripts.pory"
waitstate
# 215 "data/maps/Route123/scripts.pory"

# 216 "data/maps/Route123/scripts.pory"
Route123_EventScript_YukiMiuVictory::
# 217 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 218 "data/maps/Route123/scripts.pory"
waitmovement 0
# 219 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
# 220 "data/maps/Route123/scripts.pory"
addvar VAR_ROUTE123_STATE, 1
# 221 "data/maps/Route123/scripts.pory"
end
# 222 "data/maps/Route123/scripts.pory"

# 223 "data/maps/Route123/scripts.pory"
Route123_EventScript_Miu::
# 224 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
# 225 "data/maps/Route123/scripts.pory"
	end
# 226 "data/maps/Route123/scripts.pory"

# 227 "data/maps/Route123/scripts.pory"
Route123_EventScript_Yuki::
# 228 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
# 229 "data/maps/Route123/scripts.pory"
	end
# 230 "data/maps/Route123/scripts.pory"

# 231 "data/maps/Route123/scripts.pory"
Route123_EventScript_KindraEd::
# 232 "data/maps/Route123/scripts.pory"
lockall
# 233 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_KINDRA
# 234 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 235 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 236 "data/maps/Route123/scripts.pory"
waitmovement 0
# 237 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 238 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 239 "data/maps/Route123/scripts.pory"
waitmovement 0
# 240 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_KindraIntro MSGBOX_AUTOCLOSE
# 241 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_ED
# 242 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 243 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 244 "data/maps/Route123/scripts.pory"
waitmovement 0
# 245 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 246 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 247 "data/maps/Route123/scripts.pory"
waitmovement 0
# 248 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_EdIntro MSGBOX_AUTOCLOSE
# 249 "data/maps/Route123/scripts.pory"
goto Route123_EventScript_KindraEdDoMultiBattle
# 250 "data/maps/Route123/scripts.pory"
releaseall
# 251 "data/maps/Route123/scripts.pory"
end
# 252 "data/maps/Route123/scripts.pory"

# 253 "data/maps/Route123/scripts.pory"
Route123_EventScript_KindraEdDoMultiBattle::
# 254 "data/maps/Route123/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 255 "data/maps/Route123/scripts.pory"
multi_2p_vs_2 TRAINER_KINDRA, Route123_Text_KindraDefeat, TRAINER_ED, Route123_Text_EdDefeat, PARTNER_EMMIE
# 256 "data/maps/Route123/scripts.pory"
switch VAR_RESULT
# 257 "data/maps/Route123/scripts.pory"
case 1, Route123_EventScript_KindraEdVictory
# 258 "data/maps/Route123/scripts.pory"
fadescreen FADE_TO_BLACK
# 259 "data/maps/Route123/scripts.pory"
special SetCB2WhiteOut
# 260 "data/maps/Route123/scripts.pory"
waitstate
# 261 "data/maps/Route123/scripts.pory"

# 262 "data/maps/Route123/scripts.pory"
Route123_EventScript_KindraEdVictory::
# 263 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 264 "data/maps/Route123/scripts.pory"
waitmovement 0
# 265 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
# 266 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 267 "data/maps/Route123/scripts.pory"
waitmovement 0
# 268 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
# 269 "data/maps/Route123/scripts.pory"
addvar VAR_ROUTE123_STATE, 1
# 270 "data/maps/Route123/scripts.pory"
end
# 271 "data/maps/Route123/scripts.pory"

# 272 "data/maps/Route123/scripts.pory"
Route123_EventScript_Kindra::
# 273 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
# 274 "data/maps/Route123/scripts.pory"
	end
# 275 "data/maps/Route123/scripts.pory"

# 276 "data/maps/Route123/scripts.pory"
Route123_EventScript_JackiFrederick::
# 277 "data/maps/Route123/scripts.pory"
lockall
# 278 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_JACKI
# 279 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 280 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 281 "data/maps/Route123/scripts.pory"
waitmovement 0
# 282 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 283 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 284 "data/maps/Route123/scripts.pory"
waitmovement 0
# 285 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_JackiIntro MSGBOX_AUTOCLOSE
# 286 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_FREDERICK
# 287 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 288 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 289 "data/maps/Route123/scripts.pory"
waitmovement 0
# 290 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 291 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 292 "data/maps/Route123/scripts.pory"
waitmovement 0
# 293 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_FrederickIntro MSGBOX_AUTOCLOSE
# 294 "data/maps/Route123/scripts.pory"
goto Route123_EventScript_JackiFrederickDoMultiBattle
# 295 "data/maps/Route123/scripts.pory"
releaseall
# 296 "data/maps/Route123/scripts.pory"
end
# 297 "data/maps/Route123/scripts.pory"

# 298 "data/maps/Route123/scripts.pory"
Route123_EventScript_JackiFrederickDoMultiBattle::
# 299 "data/maps/Route123/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 300 "data/maps/Route123/scripts.pory"
multi_2p_vs_2 TRAINER_JACKI_1, Route123_Text_JackiDefeat, TRAINER_FREDRICK, Route123_Text_FrederickDefeat, PARTNER_EMMIE
# 301 "data/maps/Route123/scripts.pory"
switch VAR_RESULT
# 302 "data/maps/Route123/scripts.pory"
case 1, Route123_EventScript_JackiFrederickVictory
# 303 "data/maps/Route123/scripts.pory"
fadescreen FADE_TO_BLACK
# 304 "data/maps/Route123/scripts.pory"
special SetCB2WhiteOut
# 305 "data/maps/Route123/scripts.pory"
waitstate
# 306 "data/maps/Route123/scripts.pory"

# 307 "data/maps/Route123/scripts.pory"
Route123_EventScript_JackiFrederickVictory::
# 308 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 309 "data/maps/Route123/scripts.pory"
waitmovement 0
# 310 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_JackiPostBattle, MSGBOX_AUTOCLOSE
# 311 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 312 "data/maps/Route123/scripts.pory"
waitmovement 0
# 313 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_FrederickPostBattle, MSGBOX_AUTOCLOSE
# 314 "data/maps/Route123/scripts.pory"
addvar VAR_ROUTE123_STATE, 1
# 315 "data/maps/Route123/scripts.pory"
end
# 316 "data/maps/Route123/scripts.pory"

# 317 "data/maps/Route123/scripts.pory"
Route123_EventScript_Frederick::
# 318 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FrederickPostBattle, MSGBOX_AUTOCLOSE
# 319 "data/maps/Route123/scripts.pory"
	end
# 320 "data/maps/Route123/scripts.pory"

# 321 "data/maps/Route123/scripts.pory"
Route123_EventScript_FernandoAlberto::
# 322 "data/maps/Route123/scripts.pory"
lockall
# 323 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_FERNANDO
# 324 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 325 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 326 "data/maps/Route123/scripts.pory"
waitmovement 0
# 327 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 328 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 329 "data/maps/Route123/scripts.pory"
waitmovement 0
# 330 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_FernandoIntro MSGBOX_AUTOCLOSE
# 331 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_ALBERTO
# 332 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 333 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 334 "data/maps/Route123/scripts.pory"
waitmovement 0
# 335 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 336 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 337 "data/maps/Route123/scripts.pory"
waitmovement 0
# 338 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_AlbertoIntro MSGBOX_AUTOCLOSE
# 339 "data/maps/Route123/scripts.pory"
goto Route123_EventScript_FernandoAlbertoDoMultiBattle
# 340 "data/maps/Route123/scripts.pory"
releaseall
# 341 "data/maps/Route123/scripts.pory"
end
# 342 "data/maps/Route123/scripts.pory"

# 343 "data/maps/Route123/scripts.pory"
Route123_EventScript_FernandoAlbertoDoMultiBattle::
# 344 "data/maps/Route123/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 345 "data/maps/Route123/scripts.pory"
multi_2p_vs_2 TRAINER_FERNANDO_1, Route123_Text_FernandoDefeat, TRAINER_ALBERTO, Route123_Text_AlbertoDefeat, PARTNER_EMMIE
# 346 "data/maps/Route123/scripts.pory"
switch VAR_RESULT
# 347 "data/maps/Route123/scripts.pory"
case 1, Route123_EventScript_FernandoAlbertoVictory
# 348 "data/maps/Route123/scripts.pory"
fadescreen FADE_TO_BLACK
# 349 "data/maps/Route123/scripts.pory"
special SetCB2WhiteOut
# 350 "data/maps/Route123/scripts.pory"
waitstate
# 351 "data/maps/Route123/scripts.pory"

# 352 "data/maps/Route123/scripts.pory"
Route123_EventScript_FernandoAlbertoVictory::
# 353 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 354 "data/maps/Route123/scripts.pory"
waitmovement 0
# 355 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_FernandoPostBattle, MSGBOX_AUTOCLOSE
# 356 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 357 "data/maps/Route123/scripts.pory"
waitmovement 0
# 358 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
# 359 "data/maps/Route123/scripts.pory"
addvar VAR_ROUTE123_STATE, 1
# 360 "data/maps/Route123/scripts.pory"
end
# 361 "data/maps/Route123/scripts.pory"

# 362 "data/maps/Route123/scripts.pory"
Route123_EventScript_Alberto::
# 363 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
# 364 "data/maps/Route123/scripts.pory"
	end
# 365 "data/maps/Route123/scripts.pory"

# 366 "data/maps/Route123/scripts.pory"
Route123_EventScript_Ed::
# 367 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
# 368 "data/maps/Route123/scripts.pory"
	end
# 369 "data/maps/Route123/scripts.pory"

# 370 "data/maps/Route123/scripts.pory"
Route123_EventScript_JonasKayley::
# 371 "data/maps/Route123/scripts.pory"
lockall
# 372 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_JONAS
# 373 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 374 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 375 "data/maps/Route123/scripts.pory"
waitmovement 0
# 376 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 377 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 378 "data/maps/Route123/scripts.pory"
waitmovement 0
# 379 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_JonasIntro MSGBOX_AUTOCLOSE
# 380 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_KAYLEY
# 381 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 382 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 383 "data/maps/Route123/scripts.pory"
waitmovement 0
# 384 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 385 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 386 "data/maps/Route123/scripts.pory"
waitmovement 0
# 387 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_KayleyIntro MSGBOX_AUTOCLOSE
# 388 "data/maps/Route123/scripts.pory"
goto Route123_EventScript_JonasKayleyDoMultiBattle
# 389 "data/maps/Route123/scripts.pory"
releaseall
# 390 "data/maps/Route123/scripts.pory"
end
# 391 "data/maps/Route123/scripts.pory"

# 392 "data/maps/Route123/scripts.pory"
Route123_EventScript_JonasKayleyDoMultiBattle::
# 393 "data/maps/Route123/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 394 "data/maps/Route123/scripts.pory"
multi_2p_vs_2 TRAINER_JONAS, Route123_Text_JonasDefeat, TRAINER_KAYLEY, Route123_Text_KayleyDefeat, PARTNER_EMMIE
# 395 "data/maps/Route123/scripts.pory"
switch VAR_RESULT
# 396 "data/maps/Route123/scripts.pory"
case 1, Route123_EventScript_JonasKayleyVictory
# 397 "data/maps/Route123/scripts.pory"
fadescreen FADE_TO_BLACK
# 398 "data/maps/Route123/scripts.pory"
special SetCB2WhiteOut
# 399 "data/maps/Route123/scripts.pory"
waitstate
# 400 "data/maps/Route123/scripts.pory"

# 401 "data/maps/Route123/scripts.pory"
Route123_EventScript_JonasKayleyVictory::
# 402 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 403 "data/maps/Route123/scripts.pory"
waitmovement 0
# 404 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
# 405 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 406 "data/maps/Route123/scripts.pory"
waitmovement 0
# 407 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_KayleyPostBattle, MSGBOX_AUTOCLOSE
# 408 "data/maps/Route123/scripts.pory"
addvar VAR_ROUTE123_STATE, 1
# 409 "data/maps/Route123/scripts.pory"
end
# 410 "data/maps/Route123/scripts.pory"

# 411 "data/maps/Route123/scripts.pory"
Route123_EventScript_Kayley::
# 412 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KayleyPostBattle, MSGBOX_AUTOCLOSE
# 413 "data/maps/Route123/scripts.pory"
	end
# 414 "data/maps/Route123/scripts.pory"

# 415 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jonas::
# 416 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
# 417 "data/maps/Route123/scripts.pory"
	end
# 418 "data/maps/Route123/scripts.pory"

# 419 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jazmyn::
# 420 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
# 421 "data/maps/Route123/scripts.pory"
	end
# 422 "data/maps/Route123/scripts.pory"

# 423 "data/maps/Route123/scripts.pory"
Route123_EventScript_DavisJazmyn::
# 424 "data/maps/Route123/scripts.pory"
lockall
# 425 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_DAVIS
# 426 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 427 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 428 "data/maps/Route123/scripts.pory"
waitmovement 0
# 429 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 430 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 431 "data/maps/Route123/scripts.pory"
waitmovement 0
# 432 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_DavisIntro MSGBOX_AUTOCLOSE
# 433 "data/maps/Route123/scripts.pory"
setvar VAR_0x8008, LOCALID_JAZMYN
# 434 "data/maps/Route123/scripts.pory"
playse SE_PIN
# 435 "data/maps/Route123/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 436 "data/maps/Route123/scripts.pory"
waitmovement 0
# 437 "data/maps/Route123/scripts.pory"
playbgm MUS_ENCOUNTER_COOL, TRUE
# 438 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 439 "data/maps/Route123/scripts.pory"
waitmovement 0
# 440 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_JazmynIntro MSGBOX_AUTOCLOSE
# 441 "data/maps/Route123/scripts.pory"
goto Route123_EventScript_DavisJazmynDoMultiBattle
# 442 "data/maps/Route123/scripts.pory"
releaseall
# 443 "data/maps/Route123/scripts.pory"
end
# 444 "data/maps/Route123/scripts.pory"

# 445 "data/maps/Route123/scripts.pory"
Route123_EventScript_DavisJazmynDoMultiBattle::
# 446 "data/maps/Route123/scripts.pory"
playbgm MUS_ROUTE120, TRUE
# 447 "data/maps/Route123/scripts.pory"
multi_2p_vs_2 TRAINER_DAVIS, Route123_Text_DavisDefeat, TRAINER_JAZMYN, Route123_Text_JazmynDefeat, PARTNER_EMMIE
# 448 "data/maps/Route123/scripts.pory"
switch VAR_RESULT
# 449 "data/maps/Route123/scripts.pory"
case 1, Route123_EventScript_DavisJazmynVictory
# 450 "data/maps/Route123/scripts.pory"
fadescreen FADE_TO_BLACK
# 451 "data/maps/Route123/scripts.pory"
special SetCB2WhiteOut
# 452 "data/maps/Route123/scripts.pory"
waitstate
# 453 "data/maps/Route123/scripts.pory"

# 454 "data/maps/Route123/scripts.pory"
Route123_EventScript_DavisJazmynVictory::
# 455 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 456 "data/maps/Route123/scripts.pory"
waitmovement 0
# 457 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
# 458 "data/maps/Route123/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 459 "data/maps/Route123/scripts.pory"
waitmovement 0
# 460 "data/maps/Route123/scripts.pory"
msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
# 461 "data/maps/Route123/scripts.pory"
addvar VAR_ROUTE123_STATE, 1
# 462 "data/maps/Route123/scripts.pory"
end
# 463 "data/maps/Route123/scripts.pory"

# 464 "data/maps/Route123/scripts.pory"
Route123_EventScript_Davis::
# 465 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
# 466 "data/maps/Route123/scripts.pory"
	end
# 467 "data/maps/Route123/scripts.pory"

# 468 "data/maps/Route123/scripts.pory"
Route123_EventScript_Fernando::
# 469 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostBattle, MSGBOX_DEFAULT
# 470 "data/maps/Route123/scripts.pory"
	release
# 471 "data/maps/Route123/scripts.pory"
	end
# 472 "data/maps/Route123/scripts.pory"

# 473 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterFernando::
# 474 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 475 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 476 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoRegister, MSGBOX_DEFAULT
# 477 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_FERNANDO_1
# 478 "data/maps/Route123/scripts.pory"
	release
# 479 "data/maps/Route123/scripts.pory"
	end
# 480 "data/maps/Route123/scripts.pory"

# 481 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchFernando::
# 482 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_FernandoRematchIntro, Route123_Text_FernandoRematchDefeat
# 483 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostRematch, MSGBOX_AUTOCLOSE
# 484 "data/maps/Route123/scripts.pory"
	end
# 485 "data/maps/Route123/scripts.pory"

# 486 "data/maps/Route123/scripts.pory"
Route123_Text_LoveGrassMonsHaveAny:
# 487 "data/maps/Route123/scripts.pory"
	.string "I love GRASS-type POKéMON!\p"
# 488 "data/maps/Route123/scripts.pory"
	.string "Do you have any GRASS-type POKéMON?$"
# 489 "data/maps/Route123/scripts.pory"

# 490 "data/maps/Route123/scripts.pory"
Route123_Text_YouLikeGrassMonsTooHaveThis:
# 491 "data/maps/Route123/scripts.pory"
	.string "Oh?\p"
# 492 "data/maps/Route123/scripts.pory"
	.string "You like GRASS-type POKéMON, too,\n"
# 493 "data/maps/Route123/scripts.pory"
	.string "don't you?\p"
# 494 "data/maps/Route123/scripts.pory"
	.string "I'm so happy, you can have this!\n"
# 495 "data/maps/Route123/scripts.pory"
	.string "It's a token of our friendship.$"
# 496 "data/maps/Route123/scripts.pory"

# 497 "data/maps/Route123/scripts.pory"
Route123_Text_CheckTreesWithMyGrassMon:
# 498 "data/maps/Route123/scripts.pory"
	.string "I check trees with my GRASS-type\n"
# 499 "data/maps/Route123/scripts.pory"
	.string "POKéMON. I'm like a tree doctor.$"
# 500 "data/maps/Route123/scripts.pory"

# 501 "data/maps/Route123/scripts.pory"
Route123_Text_RouteSign:
# 502 "data/maps/Route123/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 123\n"
# 503 "data/maps/Route123/scripts.pory"
	.string "{LEFT_ARROW} ROUTE 118$"
# 504 "data/maps/Route123/scripts.pory"

# 505 "data/maps/Route123/scripts.pory"
Route123_Text_RouteSignMtPyre:
# 506 "data/maps/Route123/scripts.pory"
	.string "{UP_ARROW} MT. PYRE\n"
# 507 "data/maps/Route123/scripts.pory"
	.string "“Forbidden to the faint of heart.”$"
# 508 "data/maps/Route123/scripts.pory"

# 509 "data/maps/Route123/scripts.pory"
Route123_Text_BerryMastersHouse:
# 510 "data/maps/Route123/scripts.pory"
	.string "BERRY MASTER'S HOUSE$"
