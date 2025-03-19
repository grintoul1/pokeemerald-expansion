# 1 "data/maps/JaggedPass/scripts.pory"

# 2 "data/maps/JaggedPass/scripts.pory"
.set LOCALID_HIDEOUT_GUARD, 5
# 3 "data/maps/JaggedPass/scripts.pory"
.set LOCALID_ERIC, 1
# 4 "data/maps/JaggedPass/scripts.pory"
.set LOCALID_DIANA, 4
# 5 "data/maps/JaggedPass/scripts.pory"
.set LOCALID_AUTUMN, 6
# 6 "data/maps/JaggedPass/scripts.pory"
.set LOCALID_JULIO, 7
# 7 "data/maps/JaggedPass/scripts.pory"

# 8 "data/maps/JaggedPass/scripts.pory"
JaggedPass_MapScripts::
# 9 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
# 10 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
# 11 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
# 12 "data/maps/JaggedPass/scripts.pory"
	.byte 0
# 13 "data/maps/JaggedPass/scripts.pory"

# 14 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnResume:
# 15 "data/maps/JaggedPass/scripts.pory"
	setstepcallback STEP_CB_ASH
# 16 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_STATE, 3, JaggedPass_EventScript_CheckHasMagmaEmblem
# 17 "data/maps/JaggedPass/scripts.pory"
	end
# 18 "data/maps/JaggedPass/scripts.pory"

# 19 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_CheckHasMagmaEmblem::
# 20 "data/maps/JaggedPass/scripts.pory"
	checkitem ITEM_MAGMA_EMBLEM
# 21 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
# 22 "data/maps/JaggedPass/scripts.pory"
	return
# 23 "data/maps/JaggedPass/scripts.pory"

# 24 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetReadyToOpenHideout::
# 25 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_STATE, 4
# 26 "data/maps/JaggedPass/scripts.pory"
	return
# 27 "data/maps/JaggedPass/scripts.pory"

# 28 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnTransition:
# 29 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
# 30 "data/maps/JaggedPass/scripts.pory"
	end
# 31 "data/maps/JaggedPass/scripts.pory"

# 32 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetWeatherAsh::
# 33 "data/maps/JaggedPass/scripts.pory"
	setweather WEATHER_VOLCANIC_ASH
# 34 "data/maps/JaggedPass/scripts.pory"
	doweather
# 35 "data/maps/JaggedPass/scripts.pory"
	return
# 36 "data/maps/JaggedPass/scripts.pory"

# 37 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnLoad:
# 38 "data/maps/JaggedPass/scripts.pory"
	goto_if_le VAR_JAGGED_PASS_STATE, 4, JaggedPass_EventScript_ConcealHideoutEntrance
# 39 "data/maps/JaggedPass/scripts.pory"
	end
# 40 "data/maps/JaggedPass/scripts.pory"

# 41 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_ConcealHideoutEntrance::
# 42 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
# 43 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
# 44 "data/maps/JaggedPass/scripts.pory"
	end
# 45 "data/maps/JaggedPass/scripts.pory"

# 46 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_OpenMagmaHideout::
# 47 "data/maps/JaggedPass/scripts.pory"
	lockall
# 48 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 49 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 50 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 51 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 52 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 53 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 54 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
# 55 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 56 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 57 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 58 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 16  @ num shakes
# 59 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 3   @ shake delay
# 60 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 61 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 62 "data/maps/JaggedPass/scripts.pory"
	playse SE_EFFECTIVE
# 63 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
# 64 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
# 65 "data/maps/JaggedPass/scripts.pory"
	special DrawWholeMapView
# 66 "data/maps/JaggedPass/scripts.pory"
	delay 30
# 67 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_STATE, 4
# 68 "data/maps/JaggedPass/scripts.pory"
	waitse
# 69 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 70 "data/maps/JaggedPass/scripts.pory"
	end
# 71 "data/maps/JaggedPass/scripts.pory"

# 72 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MagmaHideoutGuard::
# 73 "data/maps/JaggedPass/scripts.pory"
	lockall
# 74 "data/maps/JaggedPass/scripts.pory"
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
# 75 "data/maps/JaggedPass/scripts.pory"
	waitse
# 76 "data/maps/JaggedPass/scripts.pory"
	playse SE_PIN
# 77 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
# 78 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 79 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
# 80 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 81 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 82 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 83 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
# 84 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 85 "data/maps/JaggedPass/scripts.pory"
	multi_2p_vs_1 TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat, PARTNER_EMMIE
# 86 "data/maps/JaggedPass/scripts.pory"
	switch VAR_RESULT
# 87 "data/maps/JaggedPass/scripts.pory"
	case 1, JaggedPass_EventScript_MagmaGruntVictory
# 88 "data/maps/JaggedPass/scripts.pory"
	fadescreen FADE_TO_BLACK
# 89 "data/maps/JaggedPass/scripts.pory"
	special SetCB2WhiteOut
# 90 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 91 "data/maps/JaggedPass/scripts.pory"

# 92 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MagmaGruntVictory::
# 93 "data/maps/JaggedPass/scripts.pory"
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
# 94 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 95 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 96 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 97 "data/maps/JaggedPass/scripts.pory"
	end
# 98 "data/maps/JaggedPass/scripts.pory"

# 99 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_GuardDefeated::
# 100 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 101 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 102 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
# 103 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 104 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 105 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 106 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 107 "data/maps/JaggedPass/scripts.pory"
	end
# 108 "data/maps/JaggedPass/scripts.pory"

# 109 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDiana::
# 110 "data/maps/JaggedPass/scripts.pory"
lockall
# 111 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_ERIC
# 112 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 113 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 114 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 115 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 116 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 117 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 118 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_EricIntro MSGBOX_AUTOCLOSE
# 119 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_DIANA
# 120 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 121 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 122 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 123 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 124 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 125 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 126 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_DianaIntro MSGBOX_AUTOCLOSE
# 127 "data/maps/JaggedPass/scripts.pory"
goto JaggedPass_EventScript_EricDianaDoMultiBattle
# 128 "data/maps/JaggedPass/scripts.pory"
releaseall
# 129 "data/maps/JaggedPass/scripts.pory"
end
# 130 "data/maps/JaggedPass/scripts.pory"

# 131 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDianaDoMultiBattle::
# 132 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_PETALBURG_WOODS, TRUE
# 133 "data/maps/JaggedPass/scripts.pory"
multi_2p_vs_2 TRAINER_ERIC, JaggedPass_Text_EricDefeat, TRAINER_DIANA_1, JaggedPass_Text_DianaDefeat, PARTNER_EMMIE
# 134 "data/maps/JaggedPass/scripts.pory"
switch VAR_RESULT
# 135 "data/maps/JaggedPass/scripts.pory"
case 1, JaggedPass_EventScript_EricDianaVictory
# 136 "data/maps/JaggedPass/scripts.pory"
fadescreen FADE_TO_BLACK
# 137 "data/maps/JaggedPass/scripts.pory"
special SetCB2WhiteOut
# 138 "data/maps/JaggedPass/scripts.pory"
waitstate
# 139 "data/maps/JaggedPass/scripts.pory"

# 140 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDianaVictory::
# 141 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 142 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 143 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
# 144 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 145 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 146 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
# 147 "data/maps/JaggedPass/scripts.pory"
addvar VAR_JAGGED_PASS_STATE, 1
# 148 "data/maps/JaggedPass/scripts.pory"
end
# 149 "data/maps/JaggedPass/scripts.pory"

# 150 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Eric::
# 151 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
# 152 "data/maps/JaggedPass/scripts.pory"
	end
# 153 "data/maps/JaggedPass/scripts.pory"

# 154 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Diana::
# 155 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
# 156 "data/maps/JaggedPass/scripts.pory"
	release
# 157 "data/maps/JaggedPass/scripts.pory"
	end
# 158 "data/maps/JaggedPass/scripts.pory"

# 159 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterDiana::
# 160 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 161 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
# 162 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_DIANA_1
# 163 "data/maps/JaggedPass/scripts.pory"
	release
# 164 "data/maps/JaggedPass/scripts.pory"
	end
# 165 "data/maps/JaggedPass/scripts.pory"

# 166 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_DianaRematch::
# 167 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
# 168 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
# 169 "data/maps/JaggedPass/scripts.pory"
	end
# 170 "data/maps/JaggedPass/scripts.pory"

# 171 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Ethan::
# 172 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
# 173 "data/maps/JaggedPass/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 174 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
# 175 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
# 176 "data/maps/JaggedPass/scripts.pory"
	release
# 177 "data/maps/JaggedPass/scripts.pory"
	end
# 178 "data/maps/JaggedPass/scripts.pory"

# 179 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterEthan::
# 180 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 181 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
# 182 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_ETHAN_1
# 183 "data/maps/JaggedPass/scripts.pory"
	release
# 184 "data/maps/JaggedPass/scripts.pory"
	end
# 185 "data/maps/JaggedPass/scripts.pory"

# 186 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EthanRematch::
# 187 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
# 188 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
# 189 "data/maps/JaggedPass/scripts.pory"
	end
# 190 "data/maps/JaggedPass/scripts.pory"

# 191 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Julio::
# 192 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
# 193 "data/maps/JaggedPass/scripts.pory"
	end
# 194 "data/maps/JaggedPass/scripts.pory"

# 195 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulio::
# 196 "data/maps/JaggedPass/scripts.pory"
lockall
# 197 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_AUTUMN
# 198 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 199 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 200 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 201 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 202 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 203 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 204 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_AutumnIntro MSGBOX_AUTOCLOSE
# 205 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_JULIO
# 206 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 207 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 208 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 209 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 210 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 211 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 212 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_JulioIntro MSGBOX_AUTOCLOSE
# 213 "data/maps/JaggedPass/scripts.pory"
goto JaggedPass_EventScript_AutumnJulioDoMultiBattle
# 214 "data/maps/JaggedPass/scripts.pory"
releaseall
# 215 "data/maps/JaggedPass/scripts.pory"
end
# 216 "data/maps/JaggedPass/scripts.pory"

# 217 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulioDoMultiBattle::
# 218 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_PETALBURG_WOODS, TRUE
# 219 "data/maps/JaggedPass/scripts.pory"
multi_2p_vs_2 TRAINER_AUTUMN, JaggedPass_Text_AutumnDefeat, TRAINER_JULIO, JaggedPass_Text_JulioDefeat, PARTNER_EMMIE
# 220 "data/maps/JaggedPass/scripts.pory"
switch VAR_RESULT
# 221 "data/maps/JaggedPass/scripts.pory"
case 1, JaggedPass_EventScript_AutumnJulioVictory
# 222 "data/maps/JaggedPass/scripts.pory"
fadescreen FADE_TO_BLACK
# 223 "data/maps/JaggedPass/scripts.pory"
special SetCB2WhiteOut
# 224 "data/maps/JaggedPass/scripts.pory"
waitstate
# 225 "data/maps/JaggedPass/scripts.pory"

# 226 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulioVictory::
# 227 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 228 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 229 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
# 230 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 231 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 232 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
# 233 "data/maps/JaggedPass/scripts.pory"
addvar VAR_JAGGED_PASS_STATE, 1
# 234 "data/maps/JaggedPass/scripts.pory"
end
# 235 "data/maps/JaggedPass/scripts.pory"

# 236 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Autumn::
# 237 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
# 238 "data/maps/JaggedPass/scripts.pory"
	end
# 239 "data/maps/JaggedPass/scripts.pory"

# 240 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricIntro:
# 241 "data/maps/JaggedPass/scripts.pory"
	.string "MT. CHIMNEY's JAGGED PASS…\p"
# 242 "data/maps/JaggedPass/scripts.pory"
	.string "Now this is what I've always wanted\n"
# 243 "data/maps/JaggedPass/scripts.pory"
	.string "in a mountain.\p"
# 244 "data/maps/JaggedPass/scripts.pory"
	.string "This jagged bumpiness…\n"
# 245 "data/maps/JaggedPass/scripts.pory"
	.string "It rocks my soul!$"
# 246 "data/maps/JaggedPass/scripts.pory"

# 247 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricDefeat:
# 248 "data/maps/JaggedPass/scripts.pory"
	.string "Losing left me bitter!$"
# 249 "data/maps/JaggedPass/scripts.pory"

# 250 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricPostBattle:
# 251 "data/maps/JaggedPass/scripts.pory"
	.string "Yes, I did lose at POKéMON…\p"
# 252 "data/maps/JaggedPass/scripts.pory"
	.string "But, when it comes to the love of\n"
# 253 "data/maps/JaggedPass/scripts.pory"
	.string "the mountains, I have you beat!$"
# 254 "data/maps/JaggedPass/scripts.pory"

# 255 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaIntro:
# 256 "data/maps/JaggedPass/scripts.pory"
	.string "This place isn't your casual hike.\n"
# 257 "data/maps/JaggedPass/scripts.pory"
	.string "It's not suited for a picnic.$"
# 258 "data/maps/JaggedPass/scripts.pory"

# 259 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaDefeat:
# 260 "data/maps/JaggedPass/scripts.pory"
	.string "Ohhh, no!\n"
# 261 "data/maps/JaggedPass/scripts.pory"
	.string "The ground is too bumpy…$"
# 262 "data/maps/JaggedPass/scripts.pory"

# 263 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostBattle:
# 264 "data/maps/JaggedPass/scripts.pory"
	.string "Did you know?\p"
# 265 "data/maps/JaggedPass/scripts.pory"
	.string "Some people cleverly ride their\n"
# 266 "data/maps/JaggedPass/scripts.pory"
	.string "bicycles up this horribly bumpy pass.$"
# 267 "data/maps/JaggedPass/scripts.pory"

# 268 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRegister:
# 269 "data/maps/JaggedPass/scripts.pory"
	.string "Will you ever be back in this area?\n"
# 270 "data/maps/JaggedPass/scripts.pory"
	.string "If you do return, I'd like a rematch.$"
# 271 "data/maps/JaggedPass/scripts.pory"

# 272 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchIntro:
# 273 "data/maps/JaggedPass/scripts.pory"
	.string "Picnics are fun wherever you go.\n"
# 274 "data/maps/JaggedPass/scripts.pory"
	.string "Just like POKéMON!$"
# 275 "data/maps/JaggedPass/scripts.pory"

# 276 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchDefeat:
# 277 "data/maps/JaggedPass/scripts.pory"
	.string "I only lost because the ground is\n"
# 278 "data/maps/JaggedPass/scripts.pory"
	.string "too bumpy!$"
# 279 "data/maps/JaggedPass/scripts.pory"

# 280 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostRematch:
# 281 "data/maps/JaggedPass/scripts.pory"
	.string "I'll forget about losing and just\n"
# 282 "data/maps/JaggedPass/scripts.pory"
	.string "enjoy this bumpy hike.$"
# 283 "data/maps/JaggedPass/scripts.pory"

# 284 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanIntro:
# 285 "data/maps/JaggedPass/scripts.pory"
	.string "JAGGED PASS is hard to walk on.\n"
# 286 "data/maps/JaggedPass/scripts.pory"
	.string "It's a good place for training.$"
# 287 "data/maps/JaggedPass/scripts.pory"

# 288 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanDefeat:
# 289 "data/maps/JaggedPass/scripts.pory"
	.string "It was all over while we were still\n"
# 290 "data/maps/JaggedPass/scripts.pory"
	.string "trying to find a good footing…$"
# 291 "data/maps/JaggedPass/scripts.pory"

# 292 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostBattle:
# 293 "data/maps/JaggedPass/scripts.pory"
	.string "If I had an ACRO BIKE, I'd be able to\n"
# 294 "data/maps/JaggedPass/scripts.pory"
	.string "jump ledges.$"
# 295 "data/maps/JaggedPass/scripts.pory"

# 296 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRegister:
# 297 "data/maps/JaggedPass/scripts.pory"
	.string "When I get more used to this bumpiness,\n"
# 298 "data/maps/JaggedPass/scripts.pory"
	.string "I'll be sure to win!\p"
# 299 "data/maps/JaggedPass/scripts.pory"
	.string "Can you register me in your POKéNAV?$"
# 300 "data/maps/JaggedPass/scripts.pory"

# 301 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchIntro:
# 302 "data/maps/JaggedPass/scripts.pory"
	.string "I got used to this bumpiness.\n"
# 303 "data/maps/JaggedPass/scripts.pory"
	.string "I sing while I climb now.$"
# 304 "data/maps/JaggedPass/scripts.pory"

# 305 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchDefeat:
# 306 "data/maps/JaggedPass/scripts.pory"
	.string "It's still not easy to battle on this\n"
# 307 "data/maps/JaggedPass/scripts.pory"
	.string "bumpy ground…$"
# 308 "data/maps/JaggedPass/scripts.pory"

# 309 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostRematch:
# 310 "data/maps/JaggedPass/scripts.pory"
	.string "I should get an ACRO BIKE from RYDEL\n"
# 311 "data/maps/JaggedPass/scripts.pory"
	.string "in MAUVILLE CITY…$"
# 312 "data/maps/JaggedPass/scripts.pory"

# 313 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntIntro:
# 314 "data/maps/JaggedPass/scripts.pory"
	.string "Wah!\n"
# 315 "data/maps/JaggedPass/scripts.pory"
	.string "What are you doing here?\p"
# 316 "data/maps/JaggedPass/scripts.pory"
	.string "What am I doing in a place like this?\p"
# 317 "data/maps/JaggedPass/scripts.pory"
	.string "What business is it of yours?$"
# 318 "data/maps/JaggedPass/scripts.pory"

# 319 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntDefeat:
# 320 "data/maps/JaggedPass/scripts.pory"
	.string "Urrrgh…\p"
# 321 "data/maps/JaggedPass/scripts.pory"
	.string "I should've ducked into our HIDEOUT\n"
# 322 "data/maps/JaggedPass/scripts.pory"
	.string "right away…$"
# 323 "data/maps/JaggedPass/scripts.pory"

# 324 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GoWhereverYouWant:
# 325 "data/maps/JaggedPass/scripts.pory"
	.string "Okay, oh-kay!\n"
# 326 "data/maps/JaggedPass/scripts.pory"
	.string "I admit it--you're strong!\p"
# 327 "data/maps/JaggedPass/scripts.pory"
	.string "Don't worry about me.\n"
# 328 "data/maps/JaggedPass/scripts.pory"
	.string "Go wherever you want!$"
# 329 "data/maps/JaggedPass/scripts.pory"

# 330 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_BoulderShakingInResponseToEmblem:
# 331 "data/maps/JaggedPass/scripts.pory"
	.string "Oh! This boulder is shaking in response\n"
# 332 "data/maps/JaggedPass/scripts.pory"
	.string "to the MAGMA EMBLEM!$"
# 333 "data/maps/JaggedPass/scripts.pory"

# 334 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioIntro:
# 335 "data/maps/JaggedPass/scripts.pory"
	.string "Aiyeeh! It's awfully scary to shoot\n"
# 336 "data/maps/JaggedPass/scripts.pory"
	.string "down the mountain in one go!$"
# 337 "data/maps/JaggedPass/scripts.pory"

# 338 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioDefeat:
# 339 "data/maps/JaggedPass/scripts.pory"
	.string "I feel like I'm falling apart…$"
# 340 "data/maps/JaggedPass/scripts.pory"

# 341 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioPostBattle:
# 342 "data/maps/JaggedPass/scripts.pory"
	.string "My bicycle bounced around so much,\n"
# 343 "data/maps/JaggedPass/scripts.pory"
	.string "my rear end's sore…$"
# 344 "data/maps/JaggedPass/scripts.pory"

# 345 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnIntro:
# 346 "data/maps/JaggedPass/scripts.pory"
	.string "I climb this hill every day.\n"
# 347 "data/maps/JaggedPass/scripts.pory"
	.string "I have confidence in my strength!$"
# 348 "data/maps/JaggedPass/scripts.pory"

# 349 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnDefeat:
# 350 "data/maps/JaggedPass/scripts.pory"
	.string "Hmm…\n"
# 351 "data/maps/JaggedPass/scripts.pory"
	.string "What went wrong?$"
# 352 "data/maps/JaggedPass/scripts.pory"

# 353 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnPostBattle:
# 354 "data/maps/JaggedPass/scripts.pory"
	.string "What is that odd rock protrusion\n"
# 355 "data/maps/JaggedPass/scripts.pory"
	.string "a little up the hill from here?$"
