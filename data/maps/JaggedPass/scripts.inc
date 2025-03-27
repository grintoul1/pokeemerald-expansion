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
	addvar VAR_JAGGED_PASS_STATE, 1
# 55 "data/maps/JaggedPass/scripts.pory"
	setflag FLAG_HIDE_MAGMA_HIDEOUT_SHELLY
# 56 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 57 "data/maps/JaggedPass/scripts.pory"
	end
# 58 "data/maps/JaggedPass/scripts.pory"

# 59 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Shelly::
# 60 "data/maps/JaggedPass/scripts.pory"
	lockall
# 61 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_FacePlayer
# 62 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_ShellyThanksForComing, MSGBOX_DEFAULT
# 63 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 64 "data/maps/JaggedPass/scripts.pory"
	addvar VAR_JAGGED_PASS_STATE, 1
# 65 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 66 "data/maps/JaggedPass/scripts.pory"
	end
# 67 "data/maps/JaggedPass/scripts.pory"

# 68 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_OpenMagmaHideout::
# 69 "data/maps/JaggedPass/scripts.pory"
	lockall
# 70 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 71 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 72 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 73 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 74 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 75 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 76 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
# 77 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 78 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 79 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 80 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 16  @ num shakes
# 81 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 3   @ shake delay
# 82 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 83 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 84 "data/maps/JaggedPass/scripts.pory"
	playse SE_EFFECTIVE
# 85 "data/maps/JaggedPass/scripts.pory"
	waitse
# 86 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
# 87 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
# 88 "data/maps/JaggedPass/scripts.pory"
	special DrawWholeMapView
# 89 "data/maps/JaggedPass/scripts.pory"
	delay 30
# 90 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_FaceLeft
# 91 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 92 "data/maps/JaggedPass/scripts.pory"
	playse SE_PIN
# 93 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
# 94 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 95 "data/maps/JaggedPass/scripts.pory"
	addvar VAR_JAGGED_PASS_STATE, 1
# 96 "data/maps/JaggedPass/scripts.pory"
	waitse
# 97 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 98 "data/maps/JaggedPass/scripts.pory"
	end
# 99 "data/maps/JaggedPass/scripts.pory"

# 100 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MagmaHideoutGuard::
# 101 "data/maps/JaggedPass/scripts.pory"
	lockall
# 102 "data/maps/JaggedPass/scripts.pory"
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
# 103 "data/maps/JaggedPass/scripts.pory"
	waitse
# 104 "data/maps/JaggedPass/scripts.pory"
	playse SE_PIN
# 105 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
# 106 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 107 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
# 108 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 109 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 110 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 111 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
# 112 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 113 "data/maps/JaggedPass/scripts.pory"
	multi_2p_vs_1 TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat, PARTNER_EMMIE
# 114 "data/maps/JaggedPass/scripts.pory"
	switch VAR_RESULT
# 115 "data/maps/JaggedPass/scripts.pory"
	case 1, JaggedPass_EventScript_MagmaGruntVictory
# 116 "data/maps/JaggedPass/scripts.pory"
	fadescreen FADE_TO_BLACK
# 117 "data/maps/JaggedPass/scripts.pory"
	special SetCB2WhiteOut
# 118 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 119 "data/maps/JaggedPass/scripts.pory"

# 120 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MagmaGruntVictory::
# 121 "data/maps/JaggedPass/scripts.pory"
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
# 122 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 123 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 124 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 125 "data/maps/JaggedPass/scripts.pory"
	end
# 126 "data/maps/JaggedPass/scripts.pory"

# 127 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_GuardDefeated::
# 128 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 129 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 130 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
# 131 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 132 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 133 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 134 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 135 "data/maps/JaggedPass/scripts.pory"
	end
# 136 "data/maps/JaggedPass/scripts.pory"

# 137 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDiana::
# 138 "data/maps/JaggedPass/scripts.pory"
lockall
# 139 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_ERIC
# 140 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 141 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 142 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 143 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 144 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 145 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 146 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_EricIntro MSGBOX_AUTOCLOSE
# 147 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_DIANA
# 148 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 149 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 150 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 151 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 152 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 153 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 154 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_DianaIntro MSGBOX_AUTOCLOSE
# 155 "data/maps/JaggedPass/scripts.pory"
goto JaggedPass_EventScript_EricDianaDoMultiBattle
# 156 "data/maps/JaggedPass/scripts.pory"
releaseall
# 157 "data/maps/JaggedPass/scripts.pory"
end
# 158 "data/maps/JaggedPass/scripts.pory"

# 159 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDianaDoMultiBattle::
# 160 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_PETALBURG_WOODS, TRUE
# 161 "data/maps/JaggedPass/scripts.pory"
multi_2p_vs_2 TRAINER_ERIC, JaggedPass_Text_EricDefeat, TRAINER_DIANA_1, JaggedPass_Text_DianaDefeat, PARTNER_EMMIE
# 162 "data/maps/JaggedPass/scripts.pory"
switch VAR_RESULT
# 163 "data/maps/JaggedPass/scripts.pory"
case 1, JaggedPass_EventScript_EricDianaVictory
# 164 "data/maps/JaggedPass/scripts.pory"
fadescreen FADE_TO_BLACK
# 165 "data/maps/JaggedPass/scripts.pory"
special SetCB2WhiteOut
# 166 "data/maps/JaggedPass/scripts.pory"
waitstate
# 167 "data/maps/JaggedPass/scripts.pory"

# 168 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDianaVictory::
# 169 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 170 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 171 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
# 172 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 173 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 174 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
# 175 "data/maps/JaggedPass/scripts.pory"
addvar VAR_JAGGED_PASS_STATE, 1
# 176 "data/maps/JaggedPass/scripts.pory"
end
# 177 "data/maps/JaggedPass/scripts.pory"

# 178 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Eric::
# 179 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
# 180 "data/maps/JaggedPass/scripts.pory"
	end
# 181 "data/maps/JaggedPass/scripts.pory"

# 182 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Diana::
# 183 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
# 184 "data/maps/JaggedPass/scripts.pory"
	release
# 185 "data/maps/JaggedPass/scripts.pory"
	end
# 186 "data/maps/JaggedPass/scripts.pory"

# 187 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterDiana::
# 188 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 189 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
# 190 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_DIANA_1
# 191 "data/maps/JaggedPass/scripts.pory"
	release
# 192 "data/maps/JaggedPass/scripts.pory"
	end
# 193 "data/maps/JaggedPass/scripts.pory"

# 194 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_DianaRematch::
# 195 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
# 196 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
# 197 "data/maps/JaggedPass/scripts.pory"
	end
# 198 "data/maps/JaggedPass/scripts.pory"

# 199 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Ethan::
# 200 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
# 201 "data/maps/JaggedPass/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 202 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
# 203 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
# 204 "data/maps/JaggedPass/scripts.pory"
	release
# 205 "data/maps/JaggedPass/scripts.pory"
	end
# 206 "data/maps/JaggedPass/scripts.pory"

# 207 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterEthan::
# 208 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 209 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
# 210 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_ETHAN_1
# 211 "data/maps/JaggedPass/scripts.pory"
	release
# 212 "data/maps/JaggedPass/scripts.pory"
	end
# 213 "data/maps/JaggedPass/scripts.pory"

# 214 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EthanRematch::
# 215 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
# 216 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
# 217 "data/maps/JaggedPass/scripts.pory"
	end
# 218 "data/maps/JaggedPass/scripts.pory"

# 219 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Julio::
# 220 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
# 221 "data/maps/JaggedPass/scripts.pory"
	end
# 222 "data/maps/JaggedPass/scripts.pory"

# 223 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulio::
# 224 "data/maps/JaggedPass/scripts.pory"
lockall
# 225 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_AUTUMN
# 226 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 227 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 228 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 229 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 230 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 231 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 232 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_AutumnIntro MSGBOX_AUTOCLOSE
# 233 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_JULIO
# 234 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 235 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 236 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 237 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 238 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 239 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 240 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_JulioIntro MSGBOX_AUTOCLOSE
# 241 "data/maps/JaggedPass/scripts.pory"
goto JaggedPass_EventScript_AutumnJulioDoMultiBattle
# 242 "data/maps/JaggedPass/scripts.pory"
releaseall
# 243 "data/maps/JaggedPass/scripts.pory"
end
# 244 "data/maps/JaggedPass/scripts.pory"

# 245 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulioDoMultiBattle::
# 246 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_PETALBURG_WOODS, TRUE
# 247 "data/maps/JaggedPass/scripts.pory"
multi_2p_vs_2 TRAINER_AUTUMN, JaggedPass_Text_AutumnDefeat, TRAINER_JULIO, JaggedPass_Text_JulioDefeat, PARTNER_EMMIE
# 248 "data/maps/JaggedPass/scripts.pory"
switch VAR_RESULT
# 249 "data/maps/JaggedPass/scripts.pory"
case 1, JaggedPass_EventScript_AutumnJulioVictory
# 250 "data/maps/JaggedPass/scripts.pory"
fadescreen FADE_TO_BLACK
# 251 "data/maps/JaggedPass/scripts.pory"
special SetCB2WhiteOut
# 252 "data/maps/JaggedPass/scripts.pory"
waitstate
# 253 "data/maps/JaggedPass/scripts.pory"

# 254 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulioVictory::
# 255 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 256 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 257 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
# 258 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 259 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 260 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
# 261 "data/maps/JaggedPass/scripts.pory"
addvar VAR_JAGGED_PASS_STATE, 1
# 262 "data/maps/JaggedPass/scripts.pory"
end
# 263 "data/maps/JaggedPass/scripts.pory"

# 264 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Autumn::
# 265 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
# 266 "data/maps/JaggedPass/scripts.pory"
	end
# 267 "data/maps/JaggedPass/scripts.pory"

# 268 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_ShellyThanksForComing:
# 269 "data/maps/JaggedPass/scripts.pory"
	.string "Shelly: Thanks for coming.\p"
# 270 "data/maps/JaggedPass/scripts.pory"
	.string "What's that? An emblem dropped by\n"
# 271 "data/maps/JaggedPass/scripts.pory"
	.string "Team Magma at Mt. Pyre?\p"
# 272 "data/maps/JaggedPass/scripts.pory"
	.string "I suppose that explains why I couldn't\n"
# 273 "data/maps/JaggedPass/scripts.pory"
	.string "find my own way in!\p"
# 274 "data/maps/JaggedPass/scripts.pory"
	.string "Anyway, this the Magma Hideout.\p"
# 275 "data/maps/JaggedPass/scripts.pory"
	.string "Team Aqua believes that the legendary\n"
# 276 "data/maps/JaggedPass/scripts.pory"
	.string "Pokémon Groudon has been found here.\p"
# 277 "data/maps/JaggedPass/scripts.pory"
	.string "After holding your own in the company\n"
# 278 "data/maps/JaggedPass/scripts.pory"
	.string "of Archie and Maxie on Mt. Pyre,\p"
# 279 "data/maps/JaggedPass/scripts.pory"
	.string "I'm confident we find out what's going\n"
# 280 "data/maps/JaggedPass/scripts.pory"
	.string "on in there if we work together.\p"
# 281 "data/maps/JaggedPass/scripts.pory"
	.string "Emmie, I understand that the two of\n"
# 282 "data/maps/JaggedPass/scripts.pory"
	.string "you are used to working as a team.\p"
# 283 "data/maps/JaggedPass/scripts.pory"
	.string "However, I'd appreciate it if you would\n"
# 284 "data/maps/JaggedPass/scripts.pory"
	.string "let me accompany {PLAYER} through the\l"
# 285 "data/maps/JaggedPass/scripts.pory"
	.string "hideout, and you wait at the entrance.\p"
# 286 "data/maps/JaggedPass/scripts.pory"
	.string "Anyway, I'll see you inside.$"
# 287 "data/maps/JaggedPass/scripts.pory"

# 288 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricIntro:
# 289 "data/maps/JaggedPass/scripts.pory"
	.string "MT. CHIMNEY's JAGGED PASS…\p"
# 290 "data/maps/JaggedPass/scripts.pory"
	.string "Now this is what I've always wanted\n"
# 291 "data/maps/JaggedPass/scripts.pory"
	.string "in a mountain.\p"
# 292 "data/maps/JaggedPass/scripts.pory"
	.string "This jagged bumpiness…\n"
# 293 "data/maps/JaggedPass/scripts.pory"
	.string "It rocks my soul!$"
# 294 "data/maps/JaggedPass/scripts.pory"

# 295 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricDefeat:
# 296 "data/maps/JaggedPass/scripts.pory"
	.string "Losing left me bitter!$"
# 297 "data/maps/JaggedPass/scripts.pory"

# 298 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricPostBattle:
# 299 "data/maps/JaggedPass/scripts.pory"
	.string "Yes, I did lose at POKéMON…\p"
# 300 "data/maps/JaggedPass/scripts.pory"
	.string "But, when it comes to the love of\n"
# 301 "data/maps/JaggedPass/scripts.pory"
	.string "the mountains, I have you beat!$"
# 302 "data/maps/JaggedPass/scripts.pory"

# 303 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaIntro:
# 304 "data/maps/JaggedPass/scripts.pory"
	.string "This place isn't your casual hike.\n"
# 305 "data/maps/JaggedPass/scripts.pory"
	.string "It's not suited for a picnic.$"
# 306 "data/maps/JaggedPass/scripts.pory"

# 307 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaDefeat:
# 308 "data/maps/JaggedPass/scripts.pory"
	.string "Ohhh, no!\n"
# 309 "data/maps/JaggedPass/scripts.pory"
	.string "The ground is too bumpy…$"
# 310 "data/maps/JaggedPass/scripts.pory"

# 311 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostBattle:
# 312 "data/maps/JaggedPass/scripts.pory"
	.string "Did you know?\p"
# 313 "data/maps/JaggedPass/scripts.pory"
	.string "Some people cleverly ride their\n"
# 314 "data/maps/JaggedPass/scripts.pory"
	.string "bicycles up this horribly bumpy pass.$"
# 315 "data/maps/JaggedPass/scripts.pory"

# 316 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRegister:
# 317 "data/maps/JaggedPass/scripts.pory"
	.string "Will you ever be back in this area?\n"
# 318 "data/maps/JaggedPass/scripts.pory"
	.string "If you do return, I'd like a rematch.$"
# 319 "data/maps/JaggedPass/scripts.pory"

# 320 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchIntro:
# 321 "data/maps/JaggedPass/scripts.pory"
	.string "Picnics are fun wherever you go.\n"
# 322 "data/maps/JaggedPass/scripts.pory"
	.string "Just like POKéMON!$"
# 323 "data/maps/JaggedPass/scripts.pory"

# 324 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchDefeat:
# 325 "data/maps/JaggedPass/scripts.pory"
	.string "I only lost because the ground is\n"
# 326 "data/maps/JaggedPass/scripts.pory"
	.string "too bumpy!$"
# 327 "data/maps/JaggedPass/scripts.pory"

# 328 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostRematch:
# 329 "data/maps/JaggedPass/scripts.pory"
	.string "I'll forget about losing and just\n"
# 330 "data/maps/JaggedPass/scripts.pory"
	.string "enjoy this bumpy hike.$"
# 331 "data/maps/JaggedPass/scripts.pory"

# 332 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanIntro:
# 333 "data/maps/JaggedPass/scripts.pory"
	.string "JAGGED PASS is hard to walk on.\n"
# 334 "data/maps/JaggedPass/scripts.pory"
	.string "It's a good place for training.$"
# 335 "data/maps/JaggedPass/scripts.pory"

# 336 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanDefeat:
# 337 "data/maps/JaggedPass/scripts.pory"
	.string "It was all over while we were still\n"
# 338 "data/maps/JaggedPass/scripts.pory"
	.string "trying to find a good footing…$"
# 339 "data/maps/JaggedPass/scripts.pory"

# 340 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostBattle:
# 341 "data/maps/JaggedPass/scripts.pory"
	.string "If I had an ACRO BIKE, I'd be able to\n"
# 342 "data/maps/JaggedPass/scripts.pory"
	.string "jump ledges.$"
# 343 "data/maps/JaggedPass/scripts.pory"

# 344 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRegister:
# 345 "data/maps/JaggedPass/scripts.pory"
	.string "When I get more used to this bumpiness,\n"
# 346 "data/maps/JaggedPass/scripts.pory"
	.string "I'll be sure to win!\p"
# 347 "data/maps/JaggedPass/scripts.pory"
	.string "Can you register me in your POKéNAV?$"
# 348 "data/maps/JaggedPass/scripts.pory"

# 349 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchIntro:
# 350 "data/maps/JaggedPass/scripts.pory"
	.string "I got used to this bumpiness.\n"
# 351 "data/maps/JaggedPass/scripts.pory"
	.string "I sing while I climb now.$"
# 352 "data/maps/JaggedPass/scripts.pory"

# 353 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchDefeat:
# 354 "data/maps/JaggedPass/scripts.pory"
	.string "It's still not easy to battle on this\n"
# 355 "data/maps/JaggedPass/scripts.pory"
	.string "bumpy ground…$"
# 356 "data/maps/JaggedPass/scripts.pory"

# 357 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostRematch:
# 358 "data/maps/JaggedPass/scripts.pory"
	.string "I should get an ACRO BIKE from RYDEL\n"
# 359 "data/maps/JaggedPass/scripts.pory"
	.string "in MAUVILLE CITY…$"
# 360 "data/maps/JaggedPass/scripts.pory"

# 361 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntIntro:
# 362 "data/maps/JaggedPass/scripts.pory"
	.string "Wah!\n"
# 363 "data/maps/JaggedPass/scripts.pory"
	.string "What are you doing here?\p"
# 364 "data/maps/JaggedPass/scripts.pory"
	.string "What am I doing in a place like this?\p"
# 365 "data/maps/JaggedPass/scripts.pory"
	.string "What business is it of yours?$"
# 366 "data/maps/JaggedPass/scripts.pory"

# 367 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntDefeat:
# 368 "data/maps/JaggedPass/scripts.pory"
	.string "Urrrgh…\p"
# 369 "data/maps/JaggedPass/scripts.pory"
	.string "I should've ducked into our HIDEOUT\n"
# 370 "data/maps/JaggedPass/scripts.pory"
	.string "right away…$"
# 371 "data/maps/JaggedPass/scripts.pory"

# 372 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GoWhereverYouWant:
# 373 "data/maps/JaggedPass/scripts.pory"
	.string "Okay, oh-kay!\n"
# 374 "data/maps/JaggedPass/scripts.pory"
	.string "I admit it--you're strong!\p"
# 375 "data/maps/JaggedPass/scripts.pory"
	.string "Don't worry about me.\n"
# 376 "data/maps/JaggedPass/scripts.pory"
	.string "Go wherever you want!$"
# 377 "data/maps/JaggedPass/scripts.pory"

# 378 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_BoulderShakingInResponseToEmblem:
# 379 "data/maps/JaggedPass/scripts.pory"
	.string "Oh! This boulder is shaking in response\n"
# 380 "data/maps/JaggedPass/scripts.pory"
	.string "to the MAGMA EMBLEM!$"
# 381 "data/maps/JaggedPass/scripts.pory"

# 382 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioIntro:
# 383 "data/maps/JaggedPass/scripts.pory"
	.string "Aiyeeh! It's awfully scary to shoot\n"
# 384 "data/maps/JaggedPass/scripts.pory"
	.string "down the mountain in one go!$"
# 385 "data/maps/JaggedPass/scripts.pory"

# 386 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioDefeat:
# 387 "data/maps/JaggedPass/scripts.pory"
	.string "I feel like I'm falling apart…$"
# 388 "data/maps/JaggedPass/scripts.pory"

# 389 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioPostBattle:
# 390 "data/maps/JaggedPass/scripts.pory"
	.string "My bicycle bounced around so much,\n"
# 391 "data/maps/JaggedPass/scripts.pory"
	.string "my rear end's sore…$"
# 392 "data/maps/JaggedPass/scripts.pory"

# 393 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnIntro:
# 394 "data/maps/JaggedPass/scripts.pory"
	.string "I climb this hill every day.\n"
# 395 "data/maps/JaggedPass/scripts.pory"
	.string "I have confidence in my strength!$"
# 396 "data/maps/JaggedPass/scripts.pory"

# 397 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnDefeat:
# 398 "data/maps/JaggedPass/scripts.pory"
	.string "Hmm…\n"
# 399 "data/maps/JaggedPass/scripts.pory"
	.string "What went wrong?$"
# 400 "data/maps/JaggedPass/scripts.pory"

# 401 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnPostBattle:
# 402 "data/maps/JaggedPass/scripts.pory"
	.string "What is that odd rock protrusion\n"
# 403 "data/maps/JaggedPass/scripts.pory"
	.string "a little up the hill from here?$"
