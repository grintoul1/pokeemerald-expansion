# 1 "data/maps/Route117/scripts.pory"

# 2 "data/maps/Route117/scripts.pory"
.set LOCALID_DAYCARE_MAN, 3
# 3 "data/maps/Route117/scripts.pory"
.set LOCALID_DAYCARE_MON_0, 25
# 4 "data/maps/Route117/scripts.pory"
.set LOCALID_DAYCARE_MON_1, 26
# 5 "data/maps/Route117/scripts.pory"
.set LOCALID_ANNA, 19
# 6 "data/maps/Route117/scripts.pory"
.set LOCALID_LYDIA, 9
# 7 "data/maps/Route117/scripts.pory"
.set LOCALID_ISAAC, 10
# 8 "data/maps/Route117/scripts.pory"
.set LOCALID_DYLAN, 8
# 9 "data/maps/Route117/scripts.pory"
.set LOCALID_MARIA, 17
# 10 "data/maps/Route117/scripts.pory"
.set LOCALID_MELINA, 24
# 11 "data/maps/Route117/scripts.pory"
.set LOCALID_DEREK, 17
# 12 "data/maps/Route117/scripts.pory"
.set LOCALID_BRANDI, 22
# 13 "data/maps/Route117/scripts.pory"
.set LOCALID_AISHA, 23
# 14 "data/maps/Route117/scripts.pory"

# 15 "data/maps/Route117/scripts.pory"

# 16 "data/maps/Route117/scripts.pory"
Route117_MapScripts::
# 17 "data/maps/Route117/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_OnTransition
# 18 "data/maps/Route117/scripts.pory"
	.byte 0
# 19 "data/maps/Route117/scripts.pory"

# 20 "data/maps/Route117/scripts.pory"
Route117_OnTransition:
# 21 "data/maps/Route117/scripts.pory"
	call Route117_EventScript_TryMoveDayCareMan
# 22 "data/maps/Route117/scripts.pory"
	@ set flags for OW daycare mons
# 23 "data/maps/Route117/scripts.pory"
	setflag FLAG_TEMP_1
# 24 "data/maps/Route117/scripts.pory"
	setflag FLAG_TEMP_2
# 25 "data/maps/Route117/scripts.pory"
	getdaycaregfx VAR_OBJ_GFX_ID_0, VAR_OBJ_GFX_ID_1, VAR_TEMP_0, VAR_TEMP_1
# 26 "data/maps/Route117/scripts.pory"
	switch VAR_RESULT
# 27 "data/maps/Route117/scripts.pory"
	case 2, Route117_EventScript_ShowDaycareMon1
# 28 "data/maps/Route117/scripts.pory"
	case 1, Route117_EventScript_ShowDaycareMon0
# 29 "data/maps/Route117/scripts.pory"
	end
# 30 "data/maps/Route117/scripts.pory"

# 31 "data/maps/Route117/scripts.pory"
Route117_EventScript_ShowDaycareMon1:
# 32 "data/maps/Route117/scripts.pory"
	@ set pokemon movement type based on compatibility
# 33 "data/maps/Route117/scripts.pory"
	special SetDaycareCompatibilityString
# 34 "data/maps/Route117/scripts.pory"
	call_if_eq VAR_RESULT, PARENTS_INCOMPATIBLE, Route117_EventScript_DaycareMonIncompatible
# 35 "data/maps/Route117/scripts.pory"
	@ Don't do anything if PARENTS_LOW_COMPATIBILITY
# 36 "data/maps/Route117/scripts.pory"
	call_if_eq VAR_RESULT, PARENTS_MED_COMPATIBILITY, Route117_EventScript_DaycareMonMedCompatibility
# 37 "data/maps/Route117/scripts.pory"
	call_if_eq VAR_RESULT, PARENTS_MAX_COMPATIBILITY, Route117_EventScript_DaycareMonMaxCompatibility
# 38 "data/maps/Route117/scripts.pory"
	clearflag FLAG_TEMP_2
# 39 "data/maps/Route117/scripts.pory"
Route117_EventScript_ShowDaycareMon0:
# 40 "data/maps/Route117/scripts.pory"
	clearflag FLAG_TEMP_1
# 41 "data/maps/Route117/scripts.pory"
	end
# 42 "data/maps/Route117/scripts.pory"

# 43 "data/maps/Route117/scripts.pory"
Route117_EventScript_DaycareMonIncompatible: @ mons never face each other
# 44 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT
# 45 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT
# 46 "data/maps/Route117/scripts.pory"
	return
# 47 "data/maps/Route117/scripts.pory"

# 48 "data/maps/Route117/scripts.pory"
Route117_EventScript_DaycareMonMedCompatibility: @ down and towards each other
# 49 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
# 50 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT
# 51 "data/maps/Route117/scripts.pory"
	return
# 52 "data/maps/Route117/scripts.pory"

# 53 "data/maps/Route117/scripts.pory"
Route117_EventScript_DaycareMonMaxCompatibility: @ facing; walk in place
# 54 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
# 55 "data/maps/Route117/scripts.pory"
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
# 56 "data/maps/Route117/scripts.pory"
	return
# 57 "data/maps/Route117/scripts.pory"

# 58 "data/maps/Route117/scripts.pory"
Route117_EventScript_TryMoveDayCareMan::
# 59 "data/maps/Route117/scripts.pory"
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_StopMoveDayCareMan
# 60 "data/maps/Route117/scripts.pory"
	setobjectxyperm LOCALID_DAYCARE_MAN, 47, 6
# 61 "data/maps/Route117/scripts.pory"
Route117_EventScript_StopMoveDayCareMan::
# 62 "data/maps/Route117/scripts.pory"
	return
# 63 "data/maps/Route117/scripts.pory"

# 64 "data/maps/Route117/scripts.pory"
Route117_EventScript_Woman::
# 65 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_ArentTheseFlowersPretty, MSGBOX_NPC
# 66 "data/maps/Route117/scripts.pory"
	end
# 67 "data/maps/Route117/scripts.pory"

# 68 "data/maps/Route117/scripts.pory"
Route117_EventScript_LittleBoy::
# 69 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AirIsTastyHere, MSGBOX_NPC
# 70 "data/maps/Route117/scripts.pory"
	end
# 71 "data/maps/Route117/scripts.pory"

# 72 "data/maps/Route117/scripts.pory"
Route117_EventScript_Girl::
# 73 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DayCarePokemonHadNewMove, MSGBOX_NPC
# 74 "data/maps/Route117/scripts.pory"
	end
# 75 "data/maps/Route117/scripts.pory"

# 76 "data/maps/Route117/scripts.pory"
Route117_EventScript_RouteSignVerdanturf::
# 77 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_RouteSignVerdanturf, MSGBOX_SIGN
# 78 "data/maps/Route117/scripts.pory"
	end
# 79 "data/maps/Route117/scripts.pory"

# 80 "data/maps/Route117/scripts.pory"
Route117_EventScript_RouteSignMauville::
# 81 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_RouteSignMauville, MSGBOX_SIGN
# 82 "data/maps/Route117/scripts.pory"
	end
# 83 "data/maps/Route117/scripts.pory"

# 84 "data/maps/Route117/scripts.pory"
Route117_EventScript_DayCareSign::
# 85 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DayCareSign, MSGBOX_SIGN
# 86 "data/maps/Route117/scripts.pory"
	end
# 87 "data/maps/Route117/scripts.pory"

# 88 "data/maps/Route117/scripts.pory"
Route117_EventScript_Isaac::
# 89 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacPostBattle, MSGBOX_DEFAULT
# 90 "data/maps/Route117/scripts.pory"
	release
# 91 "data/maps/Route117/scripts.pory"
	end
# 92 "data/maps/Route117/scripts.pory"

# 93 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterIsaac::
# 94 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 95 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 96 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacRegister, MSGBOX_DEFAULT
# 97 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ISAAC_1
# 98 "data/maps/Route117/scripts.pory"
	release
# 99 "data/maps/Route117/scripts.pory"
	end
# 100 "data/maps/Route117/scripts.pory"

# 101 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchIsaac::
# 102 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_ISAAC_1, Route117_Text_IsaacRematchIntro, Route117_Text_IsaacRematchDefeat
# 103 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacPostRematch, MSGBOX_AUTOCLOSE
# 104 "data/maps/Route117/scripts.pory"
	end
# 105 "data/maps/Route117/scripts.pory"

# 106 "data/maps/Route117/scripts.pory"
Route117_EventScript_LydiaIsaac::
# 107 "data/maps/Route117/scripts.pory"
lockall
# 108 "data/maps/Route117/scripts.pory"
setvar VAR_0x8008, LOCALID_LYDIA
# 109 "data/maps/Route117/scripts.pory"
playse SE_PIN
# 110 "data/maps/Route117/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 111 "data/maps/Route117/scripts.pory"
waitmovement 0
# 112 "data/maps/Route117/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 113 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 114 "data/maps/Route117/scripts.pory"
waitmovement 0
# 115 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_LydiaIntro MSGBOX_AUTOCLOSE
# 116 "data/maps/Route117/scripts.pory"
setvar VAR_0x8008, LOCALID_ISAAC
# 117 "data/maps/Route117/scripts.pory"
playse SE_PIN
# 118 "data/maps/Route117/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 119 "data/maps/Route117/scripts.pory"
waitmovement 0
# 120 "data/maps/Route117/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 121 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 122 "data/maps/Route117/scripts.pory"
waitmovement 0
# 123 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_IsaacIntro MSGBOX_AUTOCLOSE
# 124 "data/maps/Route117/scripts.pory"
goto Route117_EventScript_LydiaIsaacDoMultiBattle
# 125 "data/maps/Route117/scripts.pory"
releaseall
# 126 "data/maps/Route117/scripts.pory"
end
# 127 "data/maps/Route117/scripts.pory"

# 128 "data/maps/Route117/scripts.pory"
Route117_EventScript_LydiaIsaacDoMultiBattle::
# 129 "data/maps/Route117/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 130 "data/maps/Route117/scripts.pory"
multi_2p_vs_2 TRAINER_LYDIA_1, Route117_Text_LydiaDefeat, TRAINER_ISAAC_1, Route117_Text_IsaacDefeat, PARTNER_EMMIE
# 131 "data/maps/Route117/scripts.pory"
switch VAR_RESULT
# 132 "data/maps/Route117/scripts.pory"
case 1, Route117_EventScript_LydiaIsaacVictory
# 133 "data/maps/Route117/scripts.pory"
fadescreen FADE_TO_BLACK
# 134 "data/maps/Route117/scripts.pory"
special SetCB2WhiteOut
# 135 "data/maps/Route117/scripts.pory"
waitstate
# 136 "data/maps/Route117/scripts.pory"

# 137 "data/maps/Route117/scripts.pory"
Route117_EventScript_LydiaIsaacVictory::
# 138 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 139 "data/maps/Route117/scripts.pory"
waitmovement 0
# 140 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_LydiaPostBattle, MSGBOX_AUTOCLOSE
# 141 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 142 "data/maps/Route117/scripts.pory"
waitmovement 0
# 143 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_IsaacPostBattle, MSGBOX_AUTOCLOSE
# 144 "data/maps/Route117/scripts.pory"
addvar VAR_ROUTE117_STATE, 1
# 145 "data/maps/Route117/scripts.pory"
end
# 146 "data/maps/Route117/scripts.pory"

# 147 "data/maps/Route117/scripts.pory"
Route117_EventScript_Lydia::
# 148 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaPostBattle, MSGBOX_DEFAULT
# 149 "data/maps/Route117/scripts.pory"
	release
# 150 "data/maps/Route117/scripts.pory"
	end
# 151 "data/maps/Route117/scripts.pory"

# 152 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterLydia::
# 153 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 154 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 155 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaRegister, MSGBOX_DEFAULT
# 156 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_LYDIA_1
# 157 "data/maps/Route117/scripts.pory"
	release
# 158 "data/maps/Route117/scripts.pory"
	end
# 159 "data/maps/Route117/scripts.pory"

# 160 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchLydia::
# 161 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_LYDIA_1, Route117_Text_LydiaRematchIntro, Route117_Text_LydiaRematchDefeat
# 162 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaPostRematch, MSGBOX_AUTOCLOSE
# 163 "data/maps/Route117/scripts.pory"
	end
# 164 "data/maps/Route117/scripts.pory"

# 165 "data/maps/Route117/scripts.pory"
Route117_EventScript_DylanMaria::
# 166 "data/maps/Route117/scripts.pory"
lockall
# 167 "data/maps/Route117/scripts.pory"
setvar VAR_0x8008, LOCALID_DYLAN
# 168 "data/maps/Route117/scripts.pory"
playse SE_PIN
# 169 "data/maps/Route117/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 170 "data/maps/Route117/scripts.pory"
waitmovement 0
# 171 "data/maps/Route117/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 172 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 173 "data/maps/Route117/scripts.pory"
waitmovement 0
# 174 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_DylanIntro MSGBOX_AUTOCLOSE
# 175 "data/maps/Route117/scripts.pory"
setvar VAR_0x8008, LOCALID_MARIA
# 176 "data/maps/Route117/scripts.pory"
playse SE_PIN
# 177 "data/maps/Route117/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 178 "data/maps/Route117/scripts.pory"
waitmovement 0
# 179 "data/maps/Route117/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 180 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 181 "data/maps/Route117/scripts.pory"
waitmovement 0
# 182 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_MariaIntro MSGBOX_AUTOCLOSE
# 183 "data/maps/Route117/scripts.pory"
goto Route117_EventScript_DylanMariaDoMultiBattle
# 184 "data/maps/Route117/scripts.pory"
releaseall
# 185 "data/maps/Route117/scripts.pory"
end
# 186 "data/maps/Route117/scripts.pory"

# 187 "data/maps/Route117/scripts.pory"
Route117_EventScript_DylanMariaDoMultiBattle::
# 188 "data/maps/Route117/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 189 "data/maps/Route117/scripts.pory"
multi_2p_vs_2 TRAINER_DYLAN_1, Route117_Text_DylanDefeat, TRAINER_MARIA_1, Route117_Text_MariaDefeat, PARTNER_EMMIE
# 190 "data/maps/Route117/scripts.pory"
switch VAR_RESULT
# 191 "data/maps/Route117/scripts.pory"
case 1, Route117_EventScript_DylanMariaVictory
# 192 "data/maps/Route117/scripts.pory"
fadescreen FADE_TO_BLACK
# 193 "data/maps/Route117/scripts.pory"
special SetCB2WhiteOut
# 194 "data/maps/Route117/scripts.pory"
waitstate
# 195 "data/maps/Route117/scripts.pory"

# 196 "data/maps/Route117/scripts.pory"
Route117_EventScript_DylanMariaVictory::
# 197 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 198 "data/maps/Route117/scripts.pory"
waitmovement 0
# 199 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_DylanPostBattle, MSGBOX_AUTOCLOSE
# 200 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 201 "data/maps/Route117/scripts.pory"
waitmovement 0
# 202 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_MariaPostBattle, MSGBOX_AUTOCLOSE
# 203 "data/maps/Route117/scripts.pory"
addvar VAR_ROUTE117_STATE, 1
# 204 "data/maps/Route117/scripts.pory"
end
# 205 "data/maps/Route117/scripts.pory"

# 206 "data/maps/Route117/scripts.pory"
Route117_EventScript_Dylan::
# 207 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanPostBattle, MSGBOX_DEFAULT
# 208 "data/maps/Route117/scripts.pory"
	release
# 209 "data/maps/Route117/scripts.pory"
	end
# 210 "data/maps/Route117/scripts.pory"

# 211 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterDylan::
# 212 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 213 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 214 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanRegister, MSGBOX_DEFAULT
# 215 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_DYLAN_1
# 216 "data/maps/Route117/scripts.pory"
	release
# 217 "data/maps/Route117/scripts.pory"
	end
# 218 "data/maps/Route117/scripts.pory"

# 219 "data/maps/Route117/scripts.pory"
Route117_EventScript_MelinaDerek::
# 220 "data/maps/Route117/scripts.pory"
lockall
# 221 "data/maps/Route117/scripts.pory"
setvar VAR_0x8008, LOCALID_MELINA
# 222 "data/maps/Route117/scripts.pory"
playse SE_PIN
# 223 "data/maps/Route117/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 224 "data/maps/Route117/scripts.pory"
waitmovement 0
# 225 "data/maps/Route117/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 226 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 227 "data/maps/Route117/scripts.pory"
waitmovement 0
# 228 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_MelinaIntro MSGBOX_AUTOCLOSE
# 229 "data/maps/Route117/scripts.pory"
setvar VAR_0x8008, LOCALID_DEREK
# 230 "data/maps/Route117/scripts.pory"
playse SE_PIN
# 231 "data/maps/Route117/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 232 "data/maps/Route117/scripts.pory"
waitmovement 0
# 233 "data/maps/Route117/scripts.pory"
playbgm MUS_ENCOUNTER_SUSPICIOUS, TRUE
# 234 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 235 "data/maps/Route117/scripts.pory"
waitmovement 0
# 236 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_DerekIntro MSGBOX_AUTOCLOSE
# 237 "data/maps/Route117/scripts.pory"
goto Route117_EventScript_MelinaDerekDoMultiBattle
# 238 "data/maps/Route117/scripts.pory"
releaseall
# 239 "data/maps/Route117/scripts.pory"
end
# 240 "data/maps/Route117/scripts.pory"

# 241 "data/maps/Route117/scripts.pory"
Route117_EventScript_MelinaDerekDoMultiBattle::
# 242 "data/maps/Route117/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 243 "data/maps/Route117/scripts.pory"
multi_2p_vs_2 TRAINER_MELINA, Route117_Text_MelinaDefeat, TRAINER_DEREK, Route117_Text_DerekDefeat, PARTNER_EMMIE
# 244 "data/maps/Route117/scripts.pory"
switch VAR_RESULT
# 245 "data/maps/Route117/scripts.pory"
case 1, Route117_EventScript_MelinaDerekVictory
# 246 "data/maps/Route117/scripts.pory"
fadescreen FADE_TO_BLACK
# 247 "data/maps/Route117/scripts.pory"
special SetCB2WhiteOut
# 248 "data/maps/Route117/scripts.pory"
waitstate
# 249 "data/maps/Route117/scripts.pory"

# 250 "data/maps/Route117/scripts.pory"
Route117_EventScript_MelinaDerekVictory::
# 251 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 252 "data/maps/Route117/scripts.pory"
waitmovement 0
# 253 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_MelinaPostBattle, MSGBOX_AUTOCLOSE
# 254 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 255 "data/maps/Route117/scripts.pory"
waitmovement 0
# 256 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_DerekPostBattle, MSGBOX_AUTOCLOSE
# 257 "data/maps/Route117/scripts.pory"
addvar VAR_ROUTE117_STATE, 1
# 258 "data/maps/Route117/scripts.pory"
end
# 259 "data/maps/Route117/scripts.pory"

# 260 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchDylan::
# 261 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_DYLAN_1, Route117_Text_DylanRematchIntro, Route117_Text_DylanRematchDefeat
# 262 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanPostRematch, MSGBOX_AUTOCLOSE
# 263 "data/maps/Route117/scripts.pory"
	end
# 264 "data/maps/Route117/scripts.pory"

# 265 "data/maps/Route117/scripts.pory"
Route117_EventScript_Maria::
# 266 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaPostBattle, MSGBOX_DEFAULT
# 267 "data/maps/Route117/scripts.pory"
	release
# 268 "data/maps/Route117/scripts.pory"
	end
# 269 "data/maps/Route117/scripts.pory"

# 270 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterMaria::
# 271 "data/maps/Route117/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 272 "data/maps/Route117/scripts.pory"
	waitmovement 0
# 273 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaRegister, MSGBOX_DEFAULT
# 274 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_MARIA_1
# 275 "data/maps/Route117/scripts.pory"
	release
# 276 "data/maps/Route117/scripts.pory"
	end
# 277 "data/maps/Route117/scripts.pory"

# 278 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchMaria::
# 279 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch TRAINER_MARIA_1, Route117_Text_MariaRematchIntro, Route117_Text_MariaRematchDefeat
# 280 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaPostRematch, MSGBOX_AUTOCLOSE
# 281 "data/maps/Route117/scripts.pory"
	end
# 282 "data/maps/Route117/scripts.pory"

# 283 "data/maps/Route117/scripts.pory"
Route117_EventScript_Derek::
# 284 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DerekPostBattle, MSGBOX_AUTOCLOSE
# 285 "data/maps/Route117/scripts.pory"
	end
# 286 "data/maps/Route117/scripts.pory"

# 287 "data/maps/Route117/scripts.pory"
Route117_EventScript_AnnaMeg::
# 288 "data/maps/Route117/scripts.pory"
lockall
# 289 "data/maps/Route117/scripts.pory"
setvar VAR_0x8008, LOCALID_ANNA
# 290 "data/maps/Route117/scripts.pory"
playse SE_PIN
# 291 "data/maps/Route117/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 292 "data/maps/Route117/scripts.pory"
waitmovement 0
# 293 "data/maps/Route117/scripts.pory"
playbgm MUS_ENCOUNTER_TWINS, TRUE
# 294 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 295 "data/maps/Route117/scripts.pory"
waitmovement 0
# 296 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_AnnaIntro MSGBOX_AUTOCLOSE
# 297 "data/maps/Route117/scripts.pory"
goto Route117_EventScript_AnnaMegDoMultiBattle
# 298 "data/maps/Route117/scripts.pory"
releaseall
# 299 "data/maps/Route117/scripts.pory"
end
# 300 "data/maps/Route117/scripts.pory"

# 301 "data/maps/Route117/scripts.pory"
Route117_EventScript_AnnaMegDoMultiBattle::
# 302 "data/maps/Route117/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 303 "data/maps/Route117/scripts.pory"
multi_2p_vs_1 TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaDefeat, PARTNER_EMMIE
# 304 "data/maps/Route117/scripts.pory"
switch VAR_RESULT
# 305 "data/maps/Route117/scripts.pory"
case 1, Route117_EventScript_AnnaMegVictory
# 306 "data/maps/Route117/scripts.pory"
fadescreen FADE_TO_BLACK
# 307 "data/maps/Route117/scripts.pory"
special SetCB2WhiteOut
# 308 "data/maps/Route117/scripts.pory"
waitstate
# 309 "data/maps/Route117/scripts.pory"

# 310 "data/maps/Route117/scripts.pory"
Route117_EventScript_AnnaMegVictory::
# 311 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 312 "data/maps/Route117/scripts.pory"
waitmovement 0
# 313 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_AnnaPostBattle, MSGBOX_AUTOCLOSE
# 314 "data/maps/Route117/scripts.pory"
addvar VAR_ROUTE117_STATE, 1
# 315 "data/maps/Route117/scripts.pory"
end
# 316 "data/maps/Route117/scripts.pory"

# 317 "data/maps/Route117/scripts.pory"
Route117_EventScript_Anna::
# 318 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaPostBattle, MSGBOX_DEFAULT
# 319 "data/maps/Route117/scripts.pory"
	release
# 320 "data/maps/Route117/scripts.pory"
	end
# 321 "data/maps/Route117/scripts.pory"

# 322 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterAnna::
# 323 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
# 324 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ANNA_AND_MEG_1
# 325 "data/maps/Route117/scripts.pory"
	release
# 326 "data/maps/Route117/scripts.pory"
	end
# 327 "data/maps/Route117/scripts.pory"

# 328 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchAnna::
# 329 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaRematchIntro, Route117_Text_AnnaRematchDefeat, Route117_Text_AnnaRematchNotEnoughMons
# 330 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaPostRematch, MSGBOX_AUTOCLOSE
# 331 "data/maps/Route117/scripts.pory"
	end
# 332 "data/maps/Route117/scripts.pory"

# 333 "data/maps/Route117/scripts.pory"
Route117_EventScript_Meg::
# 334 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MegPostBattle, MSGBOX_DEFAULT
# 335 "data/maps/Route117/scripts.pory"
	release
# 336 "data/maps/Route117/scripts.pory"
	end
# 337 "data/maps/Route117/scripts.pory"

# 338 "data/maps/Route117/scripts.pory"
Route117_EventScript_RegisterMeg::
# 339 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
# 340 "data/maps/Route117/scripts.pory"
	register_matchcall TRAINER_ANNA_AND_MEG_1
# 341 "data/maps/Route117/scripts.pory"
	release
# 342 "data/maps/Route117/scripts.pory"
	end
# 343 "data/maps/Route117/scripts.pory"

# 344 "data/maps/Route117/scripts.pory"
Route117_EventScript_RematchMeg::
# 345 "data/maps/Route117/scripts.pory"
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegRematchIntro, Route117_Text_MegRematchDefeat, Route117_Text_MegRematchNotEnoughMons
# 346 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MegPostRematch, MSGBOX_AUTOCLOSE
# 347 "data/maps/Route117/scripts.pory"
	end
# 348 "data/maps/Route117/scripts.pory"

# 349 "data/maps/Route117/scripts.pory"
Route117_EventScript_Melina::
# 350 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MelinaPostBattle, MSGBOX_AUTOCLOSE
# 351 "data/maps/Route117/scripts.pory"
	end
# 352 "data/maps/Route117/scripts.pory"

# 353 "data/maps/Route117/scripts.pory"
Route117_EventScript_BrandiAisha::
# 354 "data/maps/Route117/scripts.pory"
lockall
# 355 "data/maps/Route117/scripts.pory"
setvar VAR_0x8008, LOCALID_BRANDI
# 356 "data/maps/Route117/scripts.pory"
playse SE_PIN
# 357 "data/maps/Route117/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 358 "data/maps/Route117/scripts.pory"
waitmovement 0
# 359 "data/maps/Route117/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 360 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 361 "data/maps/Route117/scripts.pory"
waitmovement 0
# 362 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_BrandiIntro MSGBOX_AUTOCLOSE
# 363 "data/maps/Route117/scripts.pory"
setvar VAR_0x8008, LOCALID_AISHA
# 364 "data/maps/Route117/scripts.pory"
playse SE_PIN
# 365 "data/maps/Route117/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 366 "data/maps/Route117/scripts.pory"
waitmovement 0
# 367 "data/maps/Route117/scripts.pory"
playbgm MUS_ENCOUNTER_INTENSE, TRUE
# 368 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 369 "data/maps/Route117/scripts.pory"
waitmovement 0
# 370 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_AishaIntro MSGBOX_AUTOCLOSE
# 371 "data/maps/Route117/scripts.pory"
goto Route117_EventScript_BrandiAishaDoMultiBattle
# 372 "data/maps/Route117/scripts.pory"
releaseall
# 373 "data/maps/Route117/scripts.pory"
end
# 374 "data/maps/Route117/scripts.pory"

# 375 "data/maps/Route117/scripts.pory"
Route117_EventScript_BrandiAishaDoMultiBattle::
# 376 "data/maps/Route117/scripts.pory"
playbgm MUS_ROUTE110, TRUE
# 377 "data/maps/Route117/scripts.pory"
multi_2p_vs_2 TRAINER_BRANDI, Route117_Text_BrandiDefeat, TRAINER_AISHA, Route117_Text_AishaDefeat, PARTNER_EMMIE
# 378 "data/maps/Route117/scripts.pory"
switch VAR_RESULT
# 379 "data/maps/Route117/scripts.pory"
case 1, Route117_EventScript_BrandiAishaVictory
# 380 "data/maps/Route117/scripts.pory"
fadescreen FADE_TO_BLACK
# 381 "data/maps/Route117/scripts.pory"
special SetCB2WhiteOut
# 382 "data/maps/Route117/scripts.pory"
waitstate
# 383 "data/maps/Route117/scripts.pory"

# 384 "data/maps/Route117/scripts.pory"
Route117_EventScript_BrandiAishaVictory::
# 385 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 386 "data/maps/Route117/scripts.pory"
waitmovement 0
# 387 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_BrandiPostBattle, MSGBOX_AUTOCLOSE
# 388 "data/maps/Route117/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 389 "data/maps/Route117/scripts.pory"
waitmovement 0
# 390 "data/maps/Route117/scripts.pory"
msgbox Route117_Text_AishaPostBattle, MSGBOX_AUTOCLOSE
# 391 "data/maps/Route117/scripts.pory"
addvar VAR_ROUTE117_STATE, 1
# 392 "data/maps/Route117/scripts.pory"
end
# 393 "data/maps/Route117/scripts.pory"

# 394 "data/maps/Route117/scripts.pory"
Route117_EventScript_Brandi::
# 395 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_BrandiPostBattle, MSGBOX_AUTOCLOSE
# 396 "data/maps/Route117/scripts.pory"
	end
# 397 "data/maps/Route117/scripts.pory"

# 398 "data/maps/Route117/scripts.pory"
Route117_EventScript_Aisha::
# 399 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AishaPostBattle, MSGBOX_AUTOCLOSE
# 400 "data/maps/Route117/scripts.pory"
	end
# 401 "data/maps/Route117/scripts.pory"

# 402 "data/maps/Route117/scripts.pory"
Route117_Text_DayCarePokemonHadNewMove:
# 403 "data/maps/Route117/scripts.pory"
	.string "I left my POKéMON at the DAY CARE.\p"
# 404 "data/maps/Route117/scripts.pory"
	.string "When I got it back, it had a new move\n"
# 405 "data/maps/Route117/scripts.pory"
	.string "that I didn't teach it.\l"
# 406 "data/maps/Route117/scripts.pory"
	.string "I was really, really surprised.$"
# 407 "data/maps/Route117/scripts.pory"

# 408 "data/maps/Route117/scripts.pory"
Route117_Text_ArentTheseFlowersPretty:
# 409 "data/maps/Route117/scripts.pory"
	.string "What do you think?\n"
# 410 "data/maps/Route117/scripts.pory"
	.string "Aren't these flowers pretty?\p"
# 411 "data/maps/Route117/scripts.pory"
	.string "I planted them all!$"
# 412 "data/maps/Route117/scripts.pory"

# 413 "data/maps/Route117/scripts.pory"
Route117_Text_AirIsTastyHere:
# 414 "data/maps/Route117/scripts.pory"
	.string "The air is tasty here!$"
# 415 "data/maps/Route117/scripts.pory"

# 416 "data/maps/Route117/scripts.pory"
Route117_Text_RouteSignVerdanturf:
# 417 "data/maps/Route117/scripts.pory"
	.string "ROUTE 117\n"
# 418 "data/maps/Route117/scripts.pory"
	.string "{LEFT_ARROW} VERDANTURF TOWN$"
# 419 "data/maps/Route117/scripts.pory"

# 420 "data/maps/Route117/scripts.pory"
Route117_Text_RouteSignMauville:
# 421 "data/maps/Route117/scripts.pory"
	.string "ROUTE 117\n"
# 422 "data/maps/Route117/scripts.pory"
	.string "{RIGHT_ARROW} MAUVILLE CITY$"
# 423 "data/maps/Route117/scripts.pory"

# 424 "data/maps/Route117/scripts.pory"
Route117_Text_DayCareSign:
# 425 "data/maps/Route117/scripts.pory"
	.string "POKéMON DAY CARE\n"
# 426 "data/maps/Route117/scripts.pory"
	.string "“Let us raise your POKéMON.”$"
