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
.set LOCALID_SHELLY, 8
# 8 "data/maps/JaggedPass/scripts.pory"

# 9 "data/maps/JaggedPass/scripts.pory"
JaggedPass_MapScripts::
# 10 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
# 11 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
# 12 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
# 13 "data/maps/JaggedPass/scripts.pory"
	.byte 0
# 14 "data/maps/JaggedPass/scripts.pory"

# 15 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnResume:
# 16 "data/maps/JaggedPass/scripts.pory"
	setstepcallback STEP_CB_ASH
# 17 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_STATE, 2, JaggedPass_EventScript_CheckHasMagmaEmblem
# 18 "data/maps/JaggedPass/scripts.pory"
	end
# 19 "data/maps/JaggedPass/scripts.pory"

# 20 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_CheckHasMagmaEmblem::
# 21 "data/maps/JaggedPass/scripts.pory"
	checkitem ITEM_MAGMA_EMBLEM
# 22 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
# 23 "data/maps/JaggedPass/scripts.pory"
	return
# 24 "data/maps/JaggedPass/scripts.pory"

# 25 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetReadyToOpenHideout::
# 26 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_STATE, 3
# 27 "data/maps/JaggedPass/scripts.pory"
	return
# 28 "data/maps/JaggedPass/scripts.pory"

# 29 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnTransition:
# 30 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
# 31 "data/maps/JaggedPass/scripts.pory"
	end
# 32 "data/maps/JaggedPass/scripts.pory"

# 33 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetWeatherAsh::
# 34 "data/maps/JaggedPass/scripts.pory"
	setweather WEATHER_VOLCANIC_ASH
# 35 "data/maps/JaggedPass/scripts.pory"
	doweather
# 36 "data/maps/JaggedPass/scripts.pory"
	return
# 37 "data/maps/JaggedPass/scripts.pory"

# 38 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnLoad:
# 39 "data/maps/JaggedPass/scripts.pory"
	goto_if_le VAR_JAGGED_PASS_STATE, 2, JaggedPass_EventScript_ConcealHideoutEntrance
# 40 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_STATE, 2, JaggedPass_EventScript_CheckHasMagmaEmblem
# 41 "data/maps/JaggedPass/scripts.pory"
	end
# 42 "data/maps/JaggedPass/scripts.pory"

# 43 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_ConcealHideoutEntrance::
# 44 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
# 45 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
# 46 "data/maps/JaggedPass/scripts.pory"
	end
# 47 "data/maps/JaggedPass/scripts.pory"

# 48 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_ShellyTrigger::
# 49 "data/maps/JaggedPass/scripts.pory"
	lockall
# 50 "data/maps/JaggedPass/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 51 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 52 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_ShellyThanksForComing, MSGBOX_DEFAULT
# 53 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 54 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 55 "data/maps/JaggedPass/scripts.pory"
	end
# 56 "data/maps/JaggedPass/scripts.pory"

# 57 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Shelly::
# 58 "data/maps/JaggedPass/scripts.pory"
	lockall
# 59 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_FacePlayer
# 60 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_ShellyThanksForComing, MSGBOX_DEFAULT
# 61 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 62 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 63 "data/maps/JaggedPass/scripts.pory"
	end
# 64 "data/maps/JaggedPass/scripts.pory"

# 65 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_OpenMagmaHideout::
# 66 "data/maps/JaggedPass/scripts.pory"
	lockall
# 67 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 68 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 69 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 70 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 71 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 72 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 73 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
# 74 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 75 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 76 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 77 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 16  @ num shakes
# 78 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 3   @ shake delay
# 79 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 80 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 81 "data/maps/JaggedPass/scripts.pory"
	playse SE_EFFECTIVE
# 82 "data/maps/JaggedPass/scripts.pory"
	waitse
# 83 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
# 84 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
# 85 "data/maps/JaggedPass/scripts.pory"
	special DrawWholeMapView
# 86 "data/maps/JaggedPass/scripts.pory"
	delay 30
# 87 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_FaceLeft
# 88 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 89 "data/maps/JaggedPass/scripts.pory"
	playse SE_PIN
# 90 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
# 91 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 92 "data/maps/JaggedPass/scripts.pory"
	addvar VAR_JAGGED_PASS_STATE, 1
# 93 "data/maps/JaggedPass/scripts.pory"
	waitse
# 94 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 95 "data/maps/JaggedPass/scripts.pory"
	end
# 96 "data/maps/JaggedPass/scripts.pory"

# 97 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MagmaHideoutGuard::
# 98 "data/maps/JaggedPass/scripts.pory"
	lockall
# 99 "data/maps/JaggedPass/scripts.pory"
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
# 100 "data/maps/JaggedPass/scripts.pory"
	waitse
# 101 "data/maps/JaggedPass/scripts.pory"
	playse SE_PIN
# 102 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
# 103 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 104 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
# 105 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 106 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 107 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 108 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
# 109 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 110 "data/maps/JaggedPass/scripts.pory"
	multi_2p_vs_1 TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat, PARTNER_EMMIE
# 111 "data/maps/JaggedPass/scripts.pory"
	switch VAR_RESULT
# 112 "data/maps/JaggedPass/scripts.pory"
	case 1, JaggedPass_EventScript_MagmaGruntVictory
# 113 "data/maps/JaggedPass/scripts.pory"
	fadescreen FADE_TO_BLACK
# 114 "data/maps/JaggedPass/scripts.pory"
	special SetCB2WhiteOut
# 115 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 116 "data/maps/JaggedPass/scripts.pory"

# 117 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MagmaGruntVictory::
# 118 "data/maps/JaggedPass/scripts.pory"
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
# 119 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 120 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 121 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 122 "data/maps/JaggedPass/scripts.pory"
	end
# 123 "data/maps/JaggedPass/scripts.pory"

# 124 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_GuardDefeated::
# 125 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 126 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 127 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
# 128 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 129 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 130 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 131 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 132 "data/maps/JaggedPass/scripts.pory"
	end
# 133 "data/maps/JaggedPass/scripts.pory"

# 134 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDiana::
# 135 "data/maps/JaggedPass/scripts.pory"
lockall
# 136 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_ERIC
# 137 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 138 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 139 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 140 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 141 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 142 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 143 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_EricIntro MSGBOX_AUTOCLOSE
# 144 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_DIANA
# 145 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 146 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 147 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 148 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 149 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 150 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 151 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_DianaIntro MSGBOX_AUTOCLOSE
# 152 "data/maps/JaggedPass/scripts.pory"
goto JaggedPass_EventScript_EricDianaDoMultiBattle
# 153 "data/maps/JaggedPass/scripts.pory"
releaseall
# 154 "data/maps/JaggedPass/scripts.pory"
end
# 155 "data/maps/JaggedPass/scripts.pory"

# 156 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDianaDoMultiBattle::
# 157 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_PETALBURG_WOODS, TRUE
# 158 "data/maps/JaggedPass/scripts.pory"
multi_2p_vs_2 TRAINER_ERIC, JaggedPass_Text_EricDefeat, TRAINER_DIANA_1, JaggedPass_Text_DianaDefeat, PARTNER_EMMIE
# 159 "data/maps/JaggedPass/scripts.pory"
switch VAR_RESULT
# 160 "data/maps/JaggedPass/scripts.pory"
case 1, JaggedPass_EventScript_EricDianaVictory
# 161 "data/maps/JaggedPass/scripts.pory"
fadescreen FADE_TO_BLACK
# 162 "data/maps/JaggedPass/scripts.pory"
special SetCB2WhiteOut
# 163 "data/maps/JaggedPass/scripts.pory"
waitstate
# 164 "data/maps/JaggedPass/scripts.pory"

# 165 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDianaVictory::
# 166 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 167 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 168 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
# 169 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 170 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 171 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
# 172 "data/maps/JaggedPass/scripts.pory"
addvar VAR_JAGGED_PASS_STATE, 1
# 173 "data/maps/JaggedPass/scripts.pory"
end
# 174 "data/maps/JaggedPass/scripts.pory"

# 175 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Eric::
# 176 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
# 177 "data/maps/JaggedPass/scripts.pory"
	end
# 178 "data/maps/JaggedPass/scripts.pory"

# 179 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Diana::
# 180 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
# 181 "data/maps/JaggedPass/scripts.pory"
	release
# 182 "data/maps/JaggedPass/scripts.pory"
	end
# 183 "data/maps/JaggedPass/scripts.pory"

# 184 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterDiana::
# 185 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 186 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
# 187 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_DIANA_1
# 188 "data/maps/JaggedPass/scripts.pory"
	release
# 189 "data/maps/JaggedPass/scripts.pory"
	end
# 190 "data/maps/JaggedPass/scripts.pory"

# 191 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_DianaRematch::
# 192 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
# 193 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
# 194 "data/maps/JaggedPass/scripts.pory"
	end
# 195 "data/maps/JaggedPass/scripts.pory"

# 196 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Ethan::
# 197 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
# 198 "data/maps/JaggedPass/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 199 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
# 200 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
# 201 "data/maps/JaggedPass/scripts.pory"
	release
# 202 "data/maps/JaggedPass/scripts.pory"
	end
# 203 "data/maps/JaggedPass/scripts.pory"

# 204 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterEthan::
# 205 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 206 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
# 207 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_ETHAN_1
# 208 "data/maps/JaggedPass/scripts.pory"
	release
# 209 "data/maps/JaggedPass/scripts.pory"
	end
# 210 "data/maps/JaggedPass/scripts.pory"

# 211 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EthanRematch::
# 212 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
# 213 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
# 214 "data/maps/JaggedPass/scripts.pory"
	end
# 215 "data/maps/JaggedPass/scripts.pory"

# 216 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Julio::
# 217 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
# 218 "data/maps/JaggedPass/scripts.pory"
	end
# 219 "data/maps/JaggedPass/scripts.pory"

# 220 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulio::
# 221 "data/maps/JaggedPass/scripts.pory"
lockall
# 222 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_AUTUMN
# 223 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 224 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 225 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 226 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 227 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 228 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 229 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_AutumnIntro MSGBOX_AUTOCLOSE
# 230 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_JULIO
# 231 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 232 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 233 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 234 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 235 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 236 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 237 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_JulioIntro MSGBOX_AUTOCLOSE
# 238 "data/maps/JaggedPass/scripts.pory"
goto JaggedPass_EventScript_AutumnJulioDoMultiBattle
# 239 "data/maps/JaggedPass/scripts.pory"
releaseall
# 240 "data/maps/JaggedPass/scripts.pory"
end
# 241 "data/maps/JaggedPass/scripts.pory"

# 242 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulioDoMultiBattle::
# 243 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_PETALBURG_WOODS, TRUE
# 244 "data/maps/JaggedPass/scripts.pory"
multi_2p_vs_2 TRAINER_AUTUMN, JaggedPass_Text_AutumnDefeat, TRAINER_JULIO, JaggedPass_Text_JulioDefeat, PARTNER_EMMIE
# 245 "data/maps/JaggedPass/scripts.pory"
switch VAR_RESULT
# 246 "data/maps/JaggedPass/scripts.pory"
case 1, JaggedPass_EventScript_AutumnJulioVictory
# 247 "data/maps/JaggedPass/scripts.pory"
fadescreen FADE_TO_BLACK
# 248 "data/maps/JaggedPass/scripts.pory"
special SetCB2WhiteOut
# 249 "data/maps/JaggedPass/scripts.pory"
waitstate
# 250 "data/maps/JaggedPass/scripts.pory"

# 251 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulioVictory::
# 252 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 253 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 254 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
# 255 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 256 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 257 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
# 258 "data/maps/JaggedPass/scripts.pory"
addvar VAR_JAGGED_PASS_STATE, 1
# 259 "data/maps/JaggedPass/scripts.pory"
end
# 260 "data/maps/JaggedPass/scripts.pory"

# 261 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Autumn::
# 262 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
# 263 "data/maps/JaggedPass/scripts.pory"
	end
# 264 "data/maps/JaggedPass/scripts.pory"

# 265 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_ShellyThanksForComing:
# 266 "data/maps/JaggedPass/scripts.pory"
	.string "Shelly: Thanks for coming.\p"
# 267 "data/maps/JaggedPass/scripts.pory"
	.string "What's that? An emblem dropped by\n"
# 268 "data/maps/JaggedPass/scripts.pory"
	.string "Team Magma at Mt. Pyre?\p"
# 269 "data/maps/JaggedPass/scripts.pory"
	.string "I suppose that explains why I\n"
# 270 "data/maps/JaggedPass/scripts.pory"
	.string "couldn't find my own way in!\p"
# 271 "data/maps/JaggedPass/scripts.pory"
	.string "Anyway, this is Team Magma's hideout,\n"
# 272 "data/maps/JaggedPass/scripts.pory"
	.string "where Team Aqua believes they have\l"
# 273 "data/maps/JaggedPass/scripts.pory"
	.string "located the legendary Pokémon Groudon.\p"
# 274 "data/maps/JaggedPass/scripts.pory"
	.string "After holding your own in the company\n"
# 275 "data/maps/JaggedPass/scripts.pory"
	.string "of Archie and Maxie on Mt. Pyre,\p"
# 276 "data/maps/JaggedPass/scripts.pory"
	.string "confident we can get inside if we\n"
# 277 "data/maps/JaggedPass/scripts.pory"
	.string "work together.\p"
# 278 "data/maps/JaggedPass/scripts.pory"
	.string "Emmie, I understand that the two of\n"
# 279 "data/maps/JaggedPass/scripts.pory"
	.string "you are used to working as a team.\p"
# 280 "data/maps/JaggedPass/scripts.pory"
	.string "However, I'd appreciate it if you would\n"
# 281 "data/maps/JaggedPass/scripts.pory"
	.string "let me accompany {PLAYER} through the\l"
# 282 "data/maps/JaggedPass/scripts.pory"
	.string "hideout, and you wait at the entrance.\p"
# 283 "data/maps/JaggedPass/scripts.pory"
	.string "Anyway, I'll see you inside.$"
# 284 "data/maps/JaggedPass/scripts.pory"

# 285 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricIntro:
# 286 "data/maps/JaggedPass/scripts.pory"
	.string "MT. CHIMNEY's JAGGED PASS…\p"
# 287 "data/maps/JaggedPass/scripts.pory"
	.string "Now this is what I've always wanted\n"
# 288 "data/maps/JaggedPass/scripts.pory"
	.string "in a mountain.\p"
# 289 "data/maps/JaggedPass/scripts.pory"
	.string "This jagged bumpiness…\n"
# 290 "data/maps/JaggedPass/scripts.pory"
	.string "It rocks my soul!$"
# 291 "data/maps/JaggedPass/scripts.pory"

# 292 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricDefeat:
# 293 "data/maps/JaggedPass/scripts.pory"
	.string "Losing left me bitter!$"
# 294 "data/maps/JaggedPass/scripts.pory"

# 295 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricPostBattle:
# 296 "data/maps/JaggedPass/scripts.pory"
	.string "Yes, I did lose at POKéMON…\p"
# 297 "data/maps/JaggedPass/scripts.pory"
	.string "But, when it comes to the love of\n"
# 298 "data/maps/JaggedPass/scripts.pory"
	.string "the mountains, I have you beat!$"
# 299 "data/maps/JaggedPass/scripts.pory"

# 300 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaIntro:
# 301 "data/maps/JaggedPass/scripts.pory"
	.string "This place isn't your casual hike.\n"
# 302 "data/maps/JaggedPass/scripts.pory"
	.string "It's not suited for a picnic.$"
# 303 "data/maps/JaggedPass/scripts.pory"

# 304 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaDefeat:
# 305 "data/maps/JaggedPass/scripts.pory"
	.string "Ohhh, no!\n"
# 306 "data/maps/JaggedPass/scripts.pory"
	.string "The ground is too bumpy…$"
# 307 "data/maps/JaggedPass/scripts.pory"

# 308 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostBattle:
# 309 "data/maps/JaggedPass/scripts.pory"
	.string "Did you know?\p"
# 310 "data/maps/JaggedPass/scripts.pory"
	.string "Some people cleverly ride their\n"
# 311 "data/maps/JaggedPass/scripts.pory"
	.string "bicycles up this horribly bumpy pass.$"
# 312 "data/maps/JaggedPass/scripts.pory"

# 313 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRegister:
# 314 "data/maps/JaggedPass/scripts.pory"
	.string "Will you ever be back in this area?\n"
# 315 "data/maps/JaggedPass/scripts.pory"
	.string "If you do return, I'd like a rematch.$"
# 316 "data/maps/JaggedPass/scripts.pory"

# 317 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchIntro:
# 318 "data/maps/JaggedPass/scripts.pory"
	.string "Picnics are fun wherever you go.\n"
# 319 "data/maps/JaggedPass/scripts.pory"
	.string "Just like POKéMON!$"
# 320 "data/maps/JaggedPass/scripts.pory"

# 321 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchDefeat:
# 322 "data/maps/JaggedPass/scripts.pory"
	.string "I only lost because the ground is\n"
# 323 "data/maps/JaggedPass/scripts.pory"
	.string "too bumpy!$"
# 324 "data/maps/JaggedPass/scripts.pory"

# 325 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostRematch:
# 326 "data/maps/JaggedPass/scripts.pory"
	.string "I'll forget about losing and just\n"
# 327 "data/maps/JaggedPass/scripts.pory"
	.string "enjoy this bumpy hike.$"
# 328 "data/maps/JaggedPass/scripts.pory"

# 329 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanIntro:
# 330 "data/maps/JaggedPass/scripts.pory"
	.string "JAGGED PASS is hard to walk on.\n"
# 331 "data/maps/JaggedPass/scripts.pory"
	.string "It's a good place for training.$"
# 332 "data/maps/JaggedPass/scripts.pory"

# 333 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanDefeat:
# 334 "data/maps/JaggedPass/scripts.pory"
	.string "It was all over while we were still\n"
# 335 "data/maps/JaggedPass/scripts.pory"
	.string "trying to find a good footing…$"
# 336 "data/maps/JaggedPass/scripts.pory"

# 337 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostBattle:
# 338 "data/maps/JaggedPass/scripts.pory"
	.string "If I had an ACRO BIKE, I'd be able to\n"
# 339 "data/maps/JaggedPass/scripts.pory"
	.string "jump ledges.$"
# 340 "data/maps/JaggedPass/scripts.pory"

# 341 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRegister:
# 342 "data/maps/JaggedPass/scripts.pory"
	.string "When I get more used to this bumpiness,\n"
# 343 "data/maps/JaggedPass/scripts.pory"
	.string "I'll be sure to win!\p"
# 344 "data/maps/JaggedPass/scripts.pory"
	.string "Can you register me in your POKéNAV?$"
# 345 "data/maps/JaggedPass/scripts.pory"

# 346 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchIntro:
# 347 "data/maps/JaggedPass/scripts.pory"
	.string "I got used to this bumpiness.\n"
# 348 "data/maps/JaggedPass/scripts.pory"
	.string "I sing while I climb now.$"
# 349 "data/maps/JaggedPass/scripts.pory"

# 350 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchDefeat:
# 351 "data/maps/JaggedPass/scripts.pory"
	.string "It's still not easy to battle on this\n"
# 352 "data/maps/JaggedPass/scripts.pory"
	.string "bumpy ground…$"
# 353 "data/maps/JaggedPass/scripts.pory"

# 354 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostRematch:
# 355 "data/maps/JaggedPass/scripts.pory"
	.string "I should get an ACRO BIKE from RYDEL\n"
# 356 "data/maps/JaggedPass/scripts.pory"
	.string "in MAUVILLE CITY…$"
# 357 "data/maps/JaggedPass/scripts.pory"

# 358 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntIntro:
# 359 "data/maps/JaggedPass/scripts.pory"
	.string "Wah!\n"
# 360 "data/maps/JaggedPass/scripts.pory"
	.string "What are you doing here?\p"
# 361 "data/maps/JaggedPass/scripts.pory"
	.string "What am I doing in a place like this?\p"
# 362 "data/maps/JaggedPass/scripts.pory"
	.string "What business is it of yours?$"
# 363 "data/maps/JaggedPass/scripts.pory"

# 364 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntDefeat:
# 365 "data/maps/JaggedPass/scripts.pory"
	.string "Urrrgh…\p"
# 366 "data/maps/JaggedPass/scripts.pory"
	.string "I should've ducked into our HIDEOUT\n"
# 367 "data/maps/JaggedPass/scripts.pory"
	.string "right away…$"
# 368 "data/maps/JaggedPass/scripts.pory"

# 369 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GoWhereverYouWant:
# 370 "data/maps/JaggedPass/scripts.pory"
	.string "Okay, oh-kay!\n"
# 371 "data/maps/JaggedPass/scripts.pory"
	.string "I admit it--you're strong!\p"
# 372 "data/maps/JaggedPass/scripts.pory"
	.string "Don't worry about me.\n"
# 373 "data/maps/JaggedPass/scripts.pory"
	.string "Go wherever you want!$"
# 374 "data/maps/JaggedPass/scripts.pory"

# 375 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_BoulderShakingInResponseToEmblem:
# 376 "data/maps/JaggedPass/scripts.pory"
	.string "Oh! This boulder is shaking in response\n"
# 377 "data/maps/JaggedPass/scripts.pory"
	.string "to the MAGMA EMBLEM!$"
# 378 "data/maps/JaggedPass/scripts.pory"

# 379 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioIntro:
# 380 "data/maps/JaggedPass/scripts.pory"
	.string "Aiyeeh! It's awfully scary to shoot\n"
# 381 "data/maps/JaggedPass/scripts.pory"
	.string "down the mountain in one go!$"
# 382 "data/maps/JaggedPass/scripts.pory"

# 383 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioDefeat:
# 384 "data/maps/JaggedPass/scripts.pory"
	.string "I feel like I'm falling apart…$"
# 385 "data/maps/JaggedPass/scripts.pory"

# 386 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioPostBattle:
# 387 "data/maps/JaggedPass/scripts.pory"
	.string "My bicycle bounced around so much,\n"
# 388 "data/maps/JaggedPass/scripts.pory"
	.string "my rear end's sore…$"
# 389 "data/maps/JaggedPass/scripts.pory"

# 390 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnIntro:
# 391 "data/maps/JaggedPass/scripts.pory"
	.string "I climb this hill every day.\n"
# 392 "data/maps/JaggedPass/scripts.pory"
	.string "I have confidence in my strength!$"
# 393 "data/maps/JaggedPass/scripts.pory"

# 394 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnDefeat:
# 395 "data/maps/JaggedPass/scripts.pory"
	.string "Hmm…\n"
# 396 "data/maps/JaggedPass/scripts.pory"
	.string "What went wrong?$"
# 397 "data/maps/JaggedPass/scripts.pory"

# 398 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnPostBattle:
# 399 "data/maps/JaggedPass/scripts.pory"
	.string "What is that odd rock protrusion\n"
# 400 "data/maps/JaggedPass/scripts.pory"
	.string "a little up the hill from here?$"
