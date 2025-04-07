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
.set LOCALID_EMMIE, 9
# 9 "data/maps/JaggedPass/scripts.pory"
.set LOCALID_MAXIE, 10
# 10 "data/maps/JaggedPass/scripts.pory"
.set LOCALID_TABITHA, 11
# 11 "data/maps/JaggedPass/scripts.pory"
.set LOCALID_COURTNEY, 12
# 12 "data/maps/JaggedPass/scripts.pory"

# 13 "data/maps/JaggedPass/scripts.pory"
JaggedPass_MapScripts::
# 14 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
# 15 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
# 16 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
# 17 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, JaggedPass_OnWarp
# 18 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, JaggedPass_OnFrame
# 19 "data/maps/JaggedPass/scripts.pory"
	.byte 0
# 20 "data/maps/JaggedPass/scripts.pory"

# 21 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnFrame:
# 22 "data/maps/JaggedPass/scripts.pory"
	map_script_2 VAR_JAGGED_PASS_STATE, 6, JaggedPass_EventScript_GroudonReleased
# 23 "data/maps/JaggedPass/scripts.pory"
	.2byte 0
# 24 "data/maps/JaggedPass/scripts.pory"

# 25 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnWarp:
# 26 "data/maps/JaggedPass/scripts.pory"
	call_if_set FLAG_ABNORMAL_WEATHER_SUN, JaggedPass_EventScript_SetWeatherIntenseSun
# 27 "data/maps/JaggedPass/scripts.pory"
	end
# 28 "data/maps/JaggedPass/scripts.pory"

# 29 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnResume:
# 30 "data/maps/JaggedPass/scripts.pory"
	setstepcallback STEP_CB_ASH
# 31 "data/maps/JaggedPass/scripts.pory"
	call_if_set FLAG_ABNORMAL_WEATHER_SUN, JaggedPass_EventScript_SetWeatherIntenseSun
# 32 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_STATE, 2, JaggedPass_EventScript_CheckHasMagmaEmblem
# 33 "data/maps/JaggedPass/scripts.pory"
	end
# 34 "data/maps/JaggedPass/scripts.pory"

# 35 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_CheckHasMagmaEmblem::
# 36 "data/maps/JaggedPass/scripts.pory"
	checkitem ITEM_MAGMA_EMBLEM
# 37 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
# 38 "data/maps/JaggedPass/scripts.pory"
	return
# 39 "data/maps/JaggedPass/scripts.pory"

# 40 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetReadyToOpenHideout::
# 41 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_STATE, 3
# 42 "data/maps/JaggedPass/scripts.pory"
	return
# 43 "data/maps/JaggedPass/scripts.pory"

# 44 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnTransition:
# 45 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
# 46 "data/maps/JaggedPass/scripts.pory"
	call_if_set FLAG_ABNORMAL_WEATHER_SUN, JaggedPass_EventScript_SetWeatherIntenseSun
# 47 "data/maps/JaggedPass/scripts.pory"
	end
# 48 "data/maps/JaggedPass/scripts.pory"

# 49 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetWeatherAsh::
# 50 "data/maps/JaggedPass/scripts.pory"
	setweather WEATHER_VOLCANIC_ASH
# 51 "data/maps/JaggedPass/scripts.pory"
	doweather
# 52 "data/maps/JaggedPass/scripts.pory"
	return
# 53 "data/maps/JaggedPass/scripts.pory"

# 54 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetWeatherIntenseSun::
# 55 "data/maps/JaggedPass/scripts.pory"
	playbgm MUS_ABNORMAL_WEATHER, TRUE
# 56 "data/maps/JaggedPass/scripts.pory"
	setweather WEATHER_DROUGHT
# 57 "data/maps/JaggedPass/scripts.pory"
	doweather
# 58 "data/maps/JaggedPass/scripts.pory"
	return
# 59 "data/maps/JaggedPass/scripts.pory"

# 60 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnLoad:
# 61 "data/maps/JaggedPass/scripts.pory"
	goto_if_le VAR_JAGGED_PASS_STATE, 2, JaggedPass_EventScript_ConcealHideoutEntrance
# 62 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_STATE, 2, JaggedPass_EventScript_CheckHasMagmaEmblem
# 63 "data/maps/JaggedPass/scripts.pory"
	call_if_set FLAG_ABNORMAL_WEATHER_SUN, JaggedPass_EventScript_SetWeatherIntenseSun
# 64 "data/maps/JaggedPass/scripts.pory"
	end
# 65 "data/maps/JaggedPass/scripts.pory"

# 66 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_GroudonReleased::
# 67 "data/maps/JaggedPass/scripts.pory"
	lockall
# 68 "data/maps/JaggedPass/scripts.pory"
	setobjectxyperm LOCALID_EMMIE, 17, 19
# 69 "data/maps/JaggedPass/scripts.pory"
	goto JaggedPass_EventScript_MaxieSpeech
# 70 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 71 "data/maps/JaggedPass/scripts.pory"
	end
# 72 "data/maps/JaggedPass/scripts.pory"

# 73 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MaxieSpeech::
# 74 "data/maps/JaggedPass/scripts.pory"
	lockall
# 75 "data/maps/JaggedPass/scripts.pory"
	delay 20
# 76 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFasterRight
# 77 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 78 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_MaxieTabithaGoToLilycove, MSGBOX_DEFAULT
# 79 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 80 "data/maps/JaggedPass/scripts.pory"
	delay 4
# 81 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_TABITHA, Common_Movement_WalkInPlaceFasterLeft
# 82 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 83 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_TabithaYouGotIt, MSGBOX_DEFAULT
# 84 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 85 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_TABITHA, Common_Movement_WalkInPlaceFasterDown
# 86 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 87 "data/maps/JaggedPass/scripts.pory"
	delay 20
# 88 "data/maps/JaggedPass/scripts.pory"
	setfieldeffectargument 0, 1
# 89 "data/maps/JaggedPass/scripts.pory"
	setfieldeffectargument 1, 0
# 90 "data/maps/JaggedPass/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 91 "data/maps/JaggedPass/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 92 "data/maps/JaggedPass/scripts.pory"
	removeobject LOCALID_TABITHA
# 93 "data/maps/JaggedPass/scripts.pory"
	delay 16
# 94 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_COURTNEY, Common_Movement_WalkInPlaceFasterLeft
# 95 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 96 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_CourtneyWeShouldGo, MSGBOX_DEFAULT
# 97 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 98 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFasterRight
# 99 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 100 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_MaxieYoureRight, MSGBOX_DEFAULT
# 101 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 102 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_COURTNEY, Common_Movement_WalkInPlaceFasterDown
# 103 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 104 "data/maps/JaggedPass/scripts.pory"
	delay 20
# 105 "data/maps/JaggedPass/scripts.pory"
	setfieldeffectargument 0, 1
# 106 "data/maps/JaggedPass/scripts.pory"
	setfieldeffectargument 1, -1
# 107 "data/maps/JaggedPass/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 108 "data/maps/JaggedPass/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 109 "data/maps/JaggedPass/scripts.pory"
	removeobject LOCALID_COURTNEY
# 110 "data/maps/JaggedPass/scripts.pory"
	delay 16
# 111 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFasterUp
# 112 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 113 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_MaxieYouLose, MSGBOX_DEFAULT
# 114 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 115 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFasterDown
# 116 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 117 "data/maps/JaggedPass/scripts.pory"
	delay 20
# 118 "data/maps/JaggedPass/scripts.pory"
	setfieldeffectargument 0, 0
# 119 "data/maps/JaggedPass/scripts.pory"
	setfieldeffectargument 1, -1
# 120 "data/maps/JaggedPass/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 121 "data/maps/JaggedPass/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 122 "data/maps/JaggedPass/scripts.pory"
	removeobject LOCALID_MAXIE
# 123 "data/maps/JaggedPass/scripts.pory"
	setflag FLAG_HIDE_JAGGED_PASS_MAXIE
# 124 "data/maps/JaggedPass/scripts.pory"
	delay 16
# 125 "data/maps/JaggedPass/scripts.pory"
	addvar VAR_JAGGED_PASS_STATE, 1
# 126 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 127 "data/maps/JaggedPass/scripts.pory"
	end
# 128 "data/maps/JaggedPass/scripts.pory"
	@state 7
# 129 "data/maps/JaggedPass/scripts.pory"

# 130 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_MaxieTabithaGoToLilycove:
# 131 "data/maps/JaggedPass/scripts.pory"
	.string "Maxie: This is exactly as we envisaged!\p"
# 132 "data/maps/JaggedPass/scripts.pory"
	.string "Now we just need to ensure Team Aqua\n"
# 133 "data/maps/JaggedPass/scripts.pory"
	.string "cannot awaken Kyogre, else all our\l"
# 134 "data/maps/JaggedPass/scripts.pory"
	.string "efforts will have been for nothing.\p"
# 135 "data/maps/JaggedPass/scripts.pory"
	.string "Tabitha, go to their hideout in Lilycove\n"
# 136 "data/maps/JaggedPass/scripts.pory"
	.string "and try to uncover Team Aqua's plans.$"
# 137 "data/maps/JaggedPass/scripts.pory"

# 138 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_TabithaYouGotIt:
# 139 "data/maps/JaggedPass/scripts.pory"
	.string "Tabitha: You got it boss!$"
# 140 "data/maps/JaggedPass/scripts.pory"
	
# 141 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_CourtneyWeShouldGo:
# 142 "data/maps/JaggedPass/scripts.pory"
	.string "Courtney: Sir, we should get to Mossdeep.$"
# 143 "data/maps/JaggedPass/scripts.pory"

# 144 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_MaxieYoureRight:
# 145 "data/maps/JaggedPass/scripts.pory"
	.string "Maxie: You're right. Mt. Chimney has but\n"
# 146 "data/maps/JaggedPass/scripts.pory"
	.string "one purpose now.\p"
# 147 "data/maps/JaggedPass/scripts.pory"
	.string "Let us take our leave.$"
# 148 "data/maps/JaggedPass/scripts.pory"

# 149 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_MaxieYouLose:
# 150 "data/maps/JaggedPass/scripts.pory"
	.string "Maxie: As for you, it appears you lose\n"
# 151 "data/maps/JaggedPass/scripts.pory"
	.string "this time.\p"
# 152 "data/maps/JaggedPass/scripts.pory"
	.string "Despite everything, I truly do wish you\n"
# 153 "data/maps/JaggedPass/scripts.pory"
	.string "both the very best.\p"
# 154 "data/maps/JaggedPass/scripts.pory"
	.string "Farewell…$"
# 155 "data/maps/JaggedPass/scripts.pory"

# 156 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_ConcealHideoutEntrance::
# 157 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
# 158 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
# 159 "data/maps/JaggedPass/scripts.pory"
	end
# 160 "data/maps/JaggedPass/scripts.pory"

# 161 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_ShellyTrigger::
# 162 "data/maps/JaggedPass/scripts.pory"
	lockall
# 163 "data/maps/JaggedPass/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 164 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 165 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_ShellyThanksForComing, MSGBOX_DEFAULT
# 166 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 167 "data/maps/JaggedPass/scripts.pory"
	addvar VAR_JAGGED_PASS_STATE, 1
# 168 "data/maps/JaggedPass/scripts.pory"
	setflag FLAG_HIDE_MAGMA_HIDEOUT_SHELLY
# 169 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 170 "data/maps/JaggedPass/scripts.pory"
	end
# 171 "data/maps/JaggedPass/scripts.pory"

# 172 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Shelly::
# 173 "data/maps/JaggedPass/scripts.pory"
	lockall
# 174 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_FacePlayer
# 175 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_ShellyThanksForComing, MSGBOX_DEFAULT
# 176 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 177 "data/maps/JaggedPass/scripts.pory"
	addvar VAR_JAGGED_PASS_STATE, 1
# 178 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 179 "data/maps/JaggedPass/scripts.pory"
	end
# 180 "data/maps/JaggedPass/scripts.pory"

# 181 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_OpenMagmaHideout::
# 182 "data/maps/JaggedPass/scripts.pory"
	lockall
# 183 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 184 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 185 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 186 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 187 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 188 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 189 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
# 190 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 191 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 192 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 193 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 16  @ num shakes
# 194 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 3   @ shake delay
# 195 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 196 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 197 "data/maps/JaggedPass/scripts.pory"
	playse SE_EFFECTIVE
# 198 "data/maps/JaggedPass/scripts.pory"
	waitse
# 199 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
# 200 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
# 201 "data/maps/JaggedPass/scripts.pory"
	special DrawWholeMapView
# 202 "data/maps/JaggedPass/scripts.pory"
	delay 30
# 203 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_FaceLeft
# 204 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 205 "data/maps/JaggedPass/scripts.pory"
	playse SE_PIN
# 206 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
# 207 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 208 "data/maps/JaggedPass/scripts.pory"
	addvar VAR_JAGGED_PASS_STATE, 1
# 209 "data/maps/JaggedPass/scripts.pory"
	waitse
# 210 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 211 "data/maps/JaggedPass/scripts.pory"
	end
# 212 "data/maps/JaggedPass/scripts.pory"

# 213 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MagmaHideoutGuard::
# 214 "data/maps/JaggedPass/scripts.pory"
	lockall
# 215 "data/maps/JaggedPass/scripts.pory"
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
# 216 "data/maps/JaggedPass/scripts.pory"
	waitse
# 217 "data/maps/JaggedPass/scripts.pory"
	playse SE_PIN
# 218 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
# 219 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 220 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
# 221 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 222 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 223 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 224 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
# 225 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 226 "data/maps/JaggedPass/scripts.pory"
	multi_2p_vs_1 TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat, PARTNER_EMMIE
# 227 "data/maps/JaggedPass/scripts.pory"
	switch VAR_RESULT
# 228 "data/maps/JaggedPass/scripts.pory"
	case 1, JaggedPass_EventScript_MagmaGruntVictory
# 229 "data/maps/JaggedPass/scripts.pory"
	fadescreen FADE_TO_BLACK
# 230 "data/maps/JaggedPass/scripts.pory"
	special SetCB2WhiteOut
# 231 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 232 "data/maps/JaggedPass/scripts.pory"

# 233 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MagmaGruntVictory::
# 234 "data/maps/JaggedPass/scripts.pory"
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
# 235 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 236 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 237 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 238 "data/maps/JaggedPass/scripts.pory"
	end
# 239 "data/maps/JaggedPass/scripts.pory"

# 240 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_GuardDefeated::
# 241 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 242 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 243 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
# 244 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 245 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 246 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 247 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 248 "data/maps/JaggedPass/scripts.pory"
	end
# 249 "data/maps/JaggedPass/scripts.pory"

# 250 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDiana::
# 251 "data/maps/JaggedPass/scripts.pory"
lockall
# 252 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_ERIC
# 253 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 254 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 255 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 256 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_HIKER, TRUE
# 257 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 258 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 259 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_EricIntro MSGBOX_AUTOCLOSE
# 260 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_DIANA
# 261 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 262 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 263 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 264 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 265 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 266 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 267 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_DianaIntro MSGBOX_AUTOCLOSE
# 268 "data/maps/JaggedPass/scripts.pory"
goto JaggedPass_EventScript_EricDianaDoMultiBattle
# 269 "data/maps/JaggedPass/scripts.pory"
releaseall
# 270 "data/maps/JaggedPass/scripts.pory"
end
# 271 "data/maps/JaggedPass/scripts.pory"

# 272 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDianaDoMultiBattle::
# 273 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_PETALBURG_WOODS, TRUE
# 274 "data/maps/JaggedPass/scripts.pory"
multi_2p_vs_2 TRAINER_ERIC, JaggedPass_Text_EricDefeat, TRAINER_DIANA_1, JaggedPass_Text_DianaDefeat, PARTNER_EMMIE
# 275 "data/maps/JaggedPass/scripts.pory"
switch VAR_RESULT
# 276 "data/maps/JaggedPass/scripts.pory"
case 1, JaggedPass_EventScript_EricDianaVictory
# 277 "data/maps/JaggedPass/scripts.pory"
fadescreen FADE_TO_BLACK
# 278 "data/maps/JaggedPass/scripts.pory"
special SetCB2WhiteOut
# 279 "data/maps/JaggedPass/scripts.pory"
waitstate
# 280 "data/maps/JaggedPass/scripts.pory"

# 281 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EricDianaVictory::
# 282 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 283 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 284 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
# 285 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 286 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 287 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
# 288 "data/maps/JaggedPass/scripts.pory"
addvar VAR_JAGGED_PASS_STATE, 1
# 289 "data/maps/JaggedPass/scripts.pory"
end
# 290 "data/maps/JaggedPass/scripts.pory"

# 291 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Eric::
# 292 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
# 293 "data/maps/JaggedPass/scripts.pory"
	end
# 294 "data/maps/JaggedPass/scripts.pory"

# 295 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Diana::
# 296 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
# 297 "data/maps/JaggedPass/scripts.pory"
	release
# 298 "data/maps/JaggedPass/scripts.pory"
	end
# 299 "data/maps/JaggedPass/scripts.pory"

# 300 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterDiana::
# 301 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 302 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
# 303 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_DIANA_1
# 304 "data/maps/JaggedPass/scripts.pory"
	release
# 305 "data/maps/JaggedPass/scripts.pory"
	end
# 306 "data/maps/JaggedPass/scripts.pory"

# 307 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_DianaRematch::
# 308 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
# 309 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
# 310 "data/maps/JaggedPass/scripts.pory"
	end
# 311 "data/maps/JaggedPass/scripts.pory"

# 312 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Ethan::
# 313 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
# 314 "data/maps/JaggedPass/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 315 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
# 316 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
# 317 "data/maps/JaggedPass/scripts.pory"
	release
# 318 "data/maps/JaggedPass/scripts.pory"
	end
# 319 "data/maps/JaggedPass/scripts.pory"

# 320 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterEthan::
# 321 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 322 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
# 323 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_ETHAN_1
# 324 "data/maps/JaggedPass/scripts.pory"
	release
# 325 "data/maps/JaggedPass/scripts.pory"
	end
# 326 "data/maps/JaggedPass/scripts.pory"

# 327 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EthanRematch::
# 328 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
# 329 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
# 330 "data/maps/JaggedPass/scripts.pory"
	end
# 331 "data/maps/JaggedPass/scripts.pory"

# 332 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Julio::
# 333 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
# 334 "data/maps/JaggedPass/scripts.pory"
	end
# 335 "data/maps/JaggedPass/scripts.pory"

# 336 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulio::
# 337 "data/maps/JaggedPass/scripts.pory"
lockall
# 338 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_AUTUMN
# 339 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 340 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 341 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 342 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 343 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 344 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 345 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_AutumnIntro MSGBOX_AUTOCLOSE
# 346 "data/maps/JaggedPass/scripts.pory"
setvar VAR_0x8008, LOCALID_JULIO
# 347 "data/maps/JaggedPass/scripts.pory"
playse SE_PIN
# 348 "data/maps/JaggedPass/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 349 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 350 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 351 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 352 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 353 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_JulioIntro MSGBOX_AUTOCLOSE
# 354 "data/maps/JaggedPass/scripts.pory"
goto JaggedPass_EventScript_AutumnJulioDoMultiBattle
# 355 "data/maps/JaggedPass/scripts.pory"
releaseall
# 356 "data/maps/JaggedPass/scripts.pory"
end
# 357 "data/maps/JaggedPass/scripts.pory"

# 358 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulioDoMultiBattle::
# 359 "data/maps/JaggedPass/scripts.pory"
playbgm MUS_PETALBURG_WOODS, TRUE
# 360 "data/maps/JaggedPass/scripts.pory"
multi_2p_vs_2 TRAINER_AUTUMN, JaggedPass_Text_AutumnDefeat, TRAINER_JULIO, JaggedPass_Text_JulioDefeat, PARTNER_EMMIE
# 361 "data/maps/JaggedPass/scripts.pory"
switch VAR_RESULT
# 362 "data/maps/JaggedPass/scripts.pory"
case 1, JaggedPass_EventScript_AutumnJulioVictory
# 363 "data/maps/JaggedPass/scripts.pory"
fadescreen FADE_TO_BLACK
# 364 "data/maps/JaggedPass/scripts.pory"
special SetCB2WhiteOut
# 365 "data/maps/JaggedPass/scripts.pory"
waitstate
# 366 "data/maps/JaggedPass/scripts.pory"

# 367 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_AutumnJulioVictory::
# 368 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 369 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 370 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
# 371 "data/maps/JaggedPass/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 372 "data/maps/JaggedPass/scripts.pory"
waitmovement 0
# 373 "data/maps/JaggedPass/scripts.pory"
msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
# 374 "data/maps/JaggedPass/scripts.pory"
addvar VAR_JAGGED_PASS_STATE, 1
# 375 "data/maps/JaggedPass/scripts.pory"
end
# 376 "data/maps/JaggedPass/scripts.pory"

# 377 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Autumn::
# 378 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
# 379 "data/maps/JaggedPass/scripts.pory"
	end
# 380 "data/maps/JaggedPass/scripts.pory"

# 381 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_ShellyThanksForComing:
# 382 "data/maps/JaggedPass/scripts.pory"
	.string "Shelly: Thanks for coming.\p"
# 383 "data/maps/JaggedPass/scripts.pory"
	.string "What's that? An emblem dropped by\n"
# 384 "data/maps/JaggedPass/scripts.pory"
	.string "Team Magma at Mt. Pyre?\p"
# 385 "data/maps/JaggedPass/scripts.pory"
	.string "I suppose that explains why I couldn't\n"
# 386 "data/maps/JaggedPass/scripts.pory"
	.string "find my own way in!\p"
# 387 "data/maps/JaggedPass/scripts.pory"
	.string "Anyway, this the Magma Hideout.\p"
# 388 "data/maps/JaggedPass/scripts.pory"
	.string "Team Aqua believes that the legendary\n"
# 389 "data/maps/JaggedPass/scripts.pory"
	.string "Pokémon Groudon has been found here.\p"
# 390 "data/maps/JaggedPass/scripts.pory"
	.string "After holding your own in the company\n"
# 391 "data/maps/JaggedPass/scripts.pory"
	.string "of Archie and Maxie on Mt. Pyre,\p"
# 392 "data/maps/JaggedPass/scripts.pory"
	.string "I'm confident we find out what's going\n"
# 393 "data/maps/JaggedPass/scripts.pory"
	.string "on in there if we work together.\p"
# 394 "data/maps/JaggedPass/scripts.pory"
	.string "Emmie, I understand that the two of\n"
# 395 "data/maps/JaggedPass/scripts.pory"
	.string "you are used to working as a team.\p"
# 396 "data/maps/JaggedPass/scripts.pory"
	.string "However, I'd appreciate it if you would\n"
# 397 "data/maps/JaggedPass/scripts.pory"
	.string "let me accompany {PLAYER} through the\l"
# 398 "data/maps/JaggedPass/scripts.pory"
	.string "hideout, and you wait at the entrance.\p"
# 399 "data/maps/JaggedPass/scripts.pory"
	.string "Anyway, I'll see you inside.$"
# 400 "data/maps/JaggedPass/scripts.pory"

# 401 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricIntro:
# 402 "data/maps/JaggedPass/scripts.pory"
	.string "MT. CHIMNEY's JAGGED PASS…\p"
# 403 "data/maps/JaggedPass/scripts.pory"
	.string "Now this is what I've always wanted\n"
# 404 "data/maps/JaggedPass/scripts.pory"
	.string "in a mountain.\p"
# 405 "data/maps/JaggedPass/scripts.pory"
	.string "This jagged bumpiness…\n"
# 406 "data/maps/JaggedPass/scripts.pory"
	.string "It rocks my soul!$"
# 407 "data/maps/JaggedPass/scripts.pory"

# 408 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricDefeat:
# 409 "data/maps/JaggedPass/scripts.pory"
	.string "Losing left me bitter!$"
# 410 "data/maps/JaggedPass/scripts.pory"

# 411 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricPostBattle:
# 412 "data/maps/JaggedPass/scripts.pory"
	.string "Yes, I did lose at POKéMON…\p"
# 413 "data/maps/JaggedPass/scripts.pory"
	.string "But, when it comes to the love of\n"
# 414 "data/maps/JaggedPass/scripts.pory"
	.string "the mountains, I have you beat!$"
# 415 "data/maps/JaggedPass/scripts.pory"

# 416 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaIntro:
# 417 "data/maps/JaggedPass/scripts.pory"
	.string "This place isn't your casual hike.\n"
# 418 "data/maps/JaggedPass/scripts.pory"
	.string "It's not suited for a picnic.$"
# 419 "data/maps/JaggedPass/scripts.pory"

# 420 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaDefeat:
# 421 "data/maps/JaggedPass/scripts.pory"
	.string "Ohhh, no!\n"
# 422 "data/maps/JaggedPass/scripts.pory"
	.string "The ground is too bumpy…$"
# 423 "data/maps/JaggedPass/scripts.pory"

# 424 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostBattle:
# 425 "data/maps/JaggedPass/scripts.pory"
	.string "Did you know?\p"
# 426 "data/maps/JaggedPass/scripts.pory"
	.string "Some people cleverly ride their\n"
# 427 "data/maps/JaggedPass/scripts.pory"
	.string "bicycles up this horribly bumpy pass.$"
# 428 "data/maps/JaggedPass/scripts.pory"

# 429 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRegister:
# 430 "data/maps/JaggedPass/scripts.pory"
	.string "Will you ever be back in this area?\n"
# 431 "data/maps/JaggedPass/scripts.pory"
	.string "If you do return, I'd like a rematch.$"
# 432 "data/maps/JaggedPass/scripts.pory"

# 433 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchIntro:
# 434 "data/maps/JaggedPass/scripts.pory"
	.string "Picnics are fun wherever you go.\n"
# 435 "data/maps/JaggedPass/scripts.pory"
	.string "Just like POKéMON!$"
# 436 "data/maps/JaggedPass/scripts.pory"

# 437 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchDefeat:
# 438 "data/maps/JaggedPass/scripts.pory"
	.string "I only lost because the ground is\n"
# 439 "data/maps/JaggedPass/scripts.pory"
	.string "too bumpy!$"
# 440 "data/maps/JaggedPass/scripts.pory"

# 441 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostRematch:
# 442 "data/maps/JaggedPass/scripts.pory"
	.string "I'll forget about losing and just\n"
# 443 "data/maps/JaggedPass/scripts.pory"
	.string "enjoy this bumpy hike.$"
# 444 "data/maps/JaggedPass/scripts.pory"

# 445 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanIntro:
# 446 "data/maps/JaggedPass/scripts.pory"
	.string "JAGGED PASS is hard to walk on.\n"
# 447 "data/maps/JaggedPass/scripts.pory"
	.string "It's a good place for training.$"
# 448 "data/maps/JaggedPass/scripts.pory"

# 449 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanDefeat:
# 450 "data/maps/JaggedPass/scripts.pory"
	.string "It was all over while we were still\n"
# 451 "data/maps/JaggedPass/scripts.pory"
	.string "trying to find a good footing…$"
# 452 "data/maps/JaggedPass/scripts.pory"

# 453 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostBattle:
# 454 "data/maps/JaggedPass/scripts.pory"
	.string "If I had an ACRO BIKE, I'd be able to\n"
# 455 "data/maps/JaggedPass/scripts.pory"
	.string "jump ledges.$"
# 456 "data/maps/JaggedPass/scripts.pory"

# 457 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRegister:
# 458 "data/maps/JaggedPass/scripts.pory"
	.string "When I get more used to this bumpiness,\n"
# 459 "data/maps/JaggedPass/scripts.pory"
	.string "I'll be sure to win!\p"
# 460 "data/maps/JaggedPass/scripts.pory"
	.string "Can you register me in your POKéNAV?$"
# 461 "data/maps/JaggedPass/scripts.pory"

# 462 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchIntro:
# 463 "data/maps/JaggedPass/scripts.pory"
	.string "I got used to this bumpiness.\n"
# 464 "data/maps/JaggedPass/scripts.pory"
	.string "I sing while I climb now.$"
# 465 "data/maps/JaggedPass/scripts.pory"

# 466 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchDefeat:
# 467 "data/maps/JaggedPass/scripts.pory"
	.string "It's still not easy to battle on this\n"
# 468 "data/maps/JaggedPass/scripts.pory"
	.string "bumpy ground…$"
# 469 "data/maps/JaggedPass/scripts.pory"

# 470 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostRematch:
# 471 "data/maps/JaggedPass/scripts.pory"
	.string "I should get an ACRO BIKE from RYDEL\n"
# 472 "data/maps/JaggedPass/scripts.pory"
	.string "in MAUVILLE CITY…$"
# 473 "data/maps/JaggedPass/scripts.pory"

# 474 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntIntro:
# 475 "data/maps/JaggedPass/scripts.pory"
	.string "Wah!\n"
# 476 "data/maps/JaggedPass/scripts.pory"
	.string "What are you doing here?\p"
# 477 "data/maps/JaggedPass/scripts.pory"
	.string "What am I doing in a place like this?\p"
# 478 "data/maps/JaggedPass/scripts.pory"
	.string "What business is it of yours?$"
# 479 "data/maps/JaggedPass/scripts.pory"

# 480 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntDefeat:
# 481 "data/maps/JaggedPass/scripts.pory"
	.string "Urrrgh…\p"
# 482 "data/maps/JaggedPass/scripts.pory"
	.string "I should've ducked into our HIDEOUT\n"
# 483 "data/maps/JaggedPass/scripts.pory"
	.string "right away…$"
# 484 "data/maps/JaggedPass/scripts.pory"

# 485 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GoWhereverYouWant:
# 486 "data/maps/JaggedPass/scripts.pory"
	.string "Okay, oh-kay!\n"
# 487 "data/maps/JaggedPass/scripts.pory"
	.string "I admit it--you're strong!\p"
# 488 "data/maps/JaggedPass/scripts.pory"
	.string "Don't worry about me.\n"
# 489 "data/maps/JaggedPass/scripts.pory"
	.string "Go wherever you want!$"
# 490 "data/maps/JaggedPass/scripts.pory"

# 491 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_BoulderShakingInResponseToEmblem:
# 492 "data/maps/JaggedPass/scripts.pory"
	.string "Oh! This boulder is shaking in response\n"
# 493 "data/maps/JaggedPass/scripts.pory"
	.string "to the MAGMA EMBLEM!$"
# 494 "data/maps/JaggedPass/scripts.pory"

# 495 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioIntro:
# 496 "data/maps/JaggedPass/scripts.pory"
	.string "Aiyeeh! It's awfully scary to shoot\n"
# 497 "data/maps/JaggedPass/scripts.pory"
	.string "down the mountain in one go!$"
# 498 "data/maps/JaggedPass/scripts.pory"

# 499 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioDefeat:
# 500 "data/maps/JaggedPass/scripts.pory"
	.string "I feel like I'm falling apart…$"
# 501 "data/maps/JaggedPass/scripts.pory"

# 502 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioPostBattle:
# 503 "data/maps/JaggedPass/scripts.pory"
	.string "My bicycle bounced around so much,\n"
# 504 "data/maps/JaggedPass/scripts.pory"
	.string "my rear end's sore…$"
# 505 "data/maps/JaggedPass/scripts.pory"

# 506 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnIntro:
# 507 "data/maps/JaggedPass/scripts.pory"
	.string "I climb this hill every day.\n"
# 508 "data/maps/JaggedPass/scripts.pory"
	.string "I have confidence in my strength!$"
# 509 "data/maps/JaggedPass/scripts.pory"

# 510 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnDefeat:
# 511 "data/maps/JaggedPass/scripts.pory"
	.string "Hmm…\n"
# 512 "data/maps/JaggedPass/scripts.pory"
	.string "What went wrong?$"
# 513 "data/maps/JaggedPass/scripts.pory"

# 514 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnPostBattle:
# 515 "data/maps/JaggedPass/scripts.pory"
	.string "What is that odd rock protrusion\n"
# 516 "data/maps/JaggedPass/scripts.pory"
	.string "a little up the hill from here?$"
