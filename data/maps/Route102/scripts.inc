# 1 "data/maps/Route102/scripts.pory"

# 2 "data/maps/Route102/scripts.pory"
.set LOCALID_CALVIN, 2
# 3 "data/maps/Route102/scripts.pory"
.set LOCALID_RICK, 3
# 4 "data/maps/Route102/scripts.pory"
.set LOCALID_ALLEN, 9
# 5 "data/maps/Route102/scripts.pory"
.set LOCALID_TIANA, 4
# 6 "data/maps/Route102/scripts.pory"

# 7 "data/maps/Route102/scripts.pory"
Route102_MapScripts::
# 8 "data/maps/Route102/scripts.pory"
	.byte 0
# 9 "data/maps/Route102/scripts.pory"

# 10 "data/maps/Route102/scripts.pory"
Route102_EventScript_LittleBoy::
# 11 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
# 12 "data/maps/Route102/scripts.pory"
	end
# 13 "data/maps/Route102/scripts.pory"

# 14 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignOldale::
# 15 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
# 16 "data/maps/Route102/scripts.pory"
	end
# 17 "data/maps/Route102/scripts.pory"

# 18 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignPetalburg::
# 19 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
# 20 "data/maps/Route102/scripts.pory"
	end
# 21 "data/maps/Route102/scripts.pory"

# 22 "data/maps/Route102/scripts.pory"
Route102_EventScript_Boy::
# 23 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
# 24 "data/maps/Route102/scripts.pory"
	end
# 25 "data/maps/Route102/scripts.pory"

# 26 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRick::
# 27 "data/maps/Route102/scripts.pory"
lockall
# 28 "data/maps/Route102/scripts.pory"
setvar VAR_0x8008, LOCALID_CALVIN
# 29 "data/maps/Route102/scripts.pory"
playse SE_PIN
# 30 "data/maps/Route102/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 31 "data/maps/Route102/scripts.pory"
waitmovement 0
# 32 "data/maps/Route102/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 33 "data/maps/Route102/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 34 "data/maps/Route102/scripts.pory"
waitmovement 0
# 35 "data/maps/Route102/scripts.pory"
msgbox Route102_Text_CalvinIntro MSGBOX_AUTOCLOSE
# 36 "data/maps/Route102/scripts.pory"
setvar VAR_0x8008, LOCALID_RICK
# 37 "data/maps/Route102/scripts.pory"
playse SE_PIN
# 38 "data/maps/Route102/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 39 "data/maps/Route102/scripts.pory"
waitmovement 0
# 40 "data/maps/Route102/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 41 "data/maps/Route102/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 42 "data/maps/Route102/scripts.pory"
waitmovement 0
# 43 "data/maps/Route102/scripts.pory"
msgbox Route102_Text_RickIntro MSGBOX_AUTOCLOSE
# 44 "data/maps/Route102/scripts.pory"
goto Route102_EventScript_CalvinRickDoMultiBattle
# 45 "data/maps/Route102/scripts.pory"
releaseall
# 46 "data/maps/Route102/scripts.pory"
end
# 47 "data/maps/Route102/scripts.pory"

# 48 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRickDoMultiBattle::
# 49 "data/maps/Route102/scripts.pory"
playbgm MUS_ROUTE101, TRUE
# 50 "data/maps/Route102/scripts.pory"
multi_2p_vs_2 TRAINER_CALVIN_1, Route102_Text_CalvinDefeated, TRAINER_RICK, Route102_Text_RickDefeated, PARTNER_EMMIE
# 51 "data/maps/Route102/scripts.pory"
switch VAR_RESULT
# 52 "data/maps/Route102/scripts.pory"
case 1, Route102_EventScript_CalvinRickVictory
# 53 "data/maps/Route102/scripts.pory"
fadescreen FADE_TO_BLACK
# 54 "data/maps/Route102/scripts.pory"
special SetCB2WhiteOut
# 55 "data/maps/Route102/scripts.pory"
waitstate
# 56 "data/maps/Route102/scripts.pory"

# 57 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRickVictory::
# 58 "data/maps/Route102/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 59 "data/maps/Route102/scripts.pory"
waitmovement 0
# 60 "data/maps/Route102/scripts.pory"
msgbox Route102_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
# 61 "data/maps/Route102/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 62 "data/maps/Route102/scripts.pory"
waitmovement 0
# 63 "data/maps/Route102/scripts.pory"
msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 64 "data/maps/Route102/scripts.pory"
addvar VAR_ROUTE102_STATE, 1
# 65 "data/maps/Route102/scripts.pory"
end
# 66 "data/maps/Route102/scripts.pory"

# 67 "data/maps/Route102/scripts.pory"
Route102_Movement_CalvinRick_NotReady:
# 68 "data/maps/Route102/scripts.pory"
	walk_right
# 69 "data/maps/Route102/scripts.pory"
	step_end
# 70 "data/maps/Route102/scripts.pory"

# 71 "data/maps/Route102/scripts.pory"
Route102_EventScript_Calvin::
# 72 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
# 73 "data/maps/Route102/scripts.pory"
	end
# 74 "data/maps/Route102/scripts.pory"

# 75 "data/maps/Route102/scripts.pory"
Route102_EventScript_Rick::
# 76 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 77 "data/maps/Route102/scripts.pory"
	end
# 78 "data/maps/Route102/scripts.pory"

# 79 "data/maps/Route102/scripts.pory"
Route102_EventScript_AllenTiana::
# 80 "data/maps/Route102/scripts.pory"
lockall
# 81 "data/maps/Route102/scripts.pory"
setvar VAR_0x8008, LOCALID_ALLEN
# 82 "data/maps/Route102/scripts.pory"
playse SE_PIN
# 83 "data/maps/Route102/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 84 "data/maps/Route102/scripts.pory"
waitmovement 0
# 85 "data/maps/Route102/scripts.pory"
playbgm MUS_ENCOUNTER_MALE, TRUE
# 86 "data/maps/Route102/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 87 "data/maps/Route102/scripts.pory"
waitmovement 0
# 88 "data/maps/Route102/scripts.pory"
msgbox Route102_Text_AllenIntro MSGBOX_AUTOCLOSE
# 89 "data/maps/Route102/scripts.pory"
setvar VAR_0x8008, LOCALID_TIANA
# 90 "data/maps/Route102/scripts.pory"
playse SE_PIN
# 91 "data/maps/Route102/scripts.pory"
applymovement VAR_0x8008, Common_Movement_ExclamationMark
# 92 "data/maps/Route102/scripts.pory"
waitmovement 0
# 93 "data/maps/Route102/scripts.pory"
playbgm MUS_ENCOUNTER_GIRL, TRUE
# 94 "data/maps/Route102/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 95 "data/maps/Route102/scripts.pory"
waitmovement 0
# 96 "data/maps/Route102/scripts.pory"
msgbox Route102_Text_TianaIntro MSGBOX_AUTOCLOSE
# 97 "data/maps/Route102/scripts.pory"
goto Route102_EventScript_AllenTianaDoMultiBattle
# 98 "data/maps/Route102/scripts.pory"
releaseall
# 99 "data/maps/Route102/scripts.pory"
end
# 100 "data/maps/Route102/scripts.pory"

# 101 "data/maps/Route102/scripts.pory"
Route102_EventScript_AllenTianaDoMultiBattle::
# 102 "data/maps/Route102/scripts.pory"
playbgm MUS_ROUTE101, TRUE
# 103 "data/maps/Route102/scripts.pory"
multi_2p_vs_2 TRAINER_ALLEN, Route102_Text_AllenDefeated, TRAINER_TIANA, Route102_Text_TianaDefeated, PARTNER_EMMIE
# 104 "data/maps/Route102/scripts.pory"
switch VAR_RESULT
# 105 "data/maps/Route102/scripts.pory"
case 1, Route102_EventScript_AllenTianaVictory
# 106 "data/maps/Route102/scripts.pory"
fadescreen FADE_TO_BLACK
# 107 "data/maps/Route102/scripts.pory"
special SetCB2WhiteOut
# 108 "data/maps/Route102/scripts.pory"
waitstate
# 109 "data/maps/Route102/scripts.pory"

# 110 "data/maps/Route102/scripts.pory"
Route102_EventScript_AllenTianaVictory::
# 111 "data/maps/Route102/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 112 "data/maps/Route102/scripts.pory"
waitmovement 0
# 113 "data/maps/Route102/scripts.pory"
msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
# 114 "data/maps/Route102/scripts.pory"
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 115 "data/maps/Route102/scripts.pory"
waitmovement 0
# 116 "data/maps/Route102/scripts.pory"
msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
# 117 "data/maps/Route102/scripts.pory"
addvar VAR_ROUTE102_STATE, 1
# 118 "data/maps/Route102/scripts.pory"
end
# 119 "data/maps/Route102/scripts.pory"

# 120 "data/maps/Route102/scripts.pory"
Route102_EventScript_Tiana::
# 121 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
# 122 "data/maps/Route102/scripts.pory"
	end
# 123 "data/maps/Route102/scripts.pory"

# 124 "data/maps/Route102/scripts.pory"
Route102_EventScript_Allen::
# 125 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
# 126 "data/maps/Route102/scripts.pory"
	end
# 127 "data/maps/Route102/scripts.pory"

# 128 "data/maps/Route102/scripts.pory"
Route102_Text_WatchMeCatchPokemon:
# 129 "data/maps/Route102/scripts.pory"
	.string "WALLY: {PLAYER}…\n"
# 130 "data/maps/Route102/scripts.pory"
	.string "POKéMON hide in tall grass like this,\l"
# 131 "data/maps/Route102/scripts.pory"
	.string "don't they?\p"
# 132 "data/maps/Route102/scripts.pory"
	.string "Please watch me and see if I can\n"
# 133 "data/maps/Route102/scripts.pory"
	.string "catch one properly.\p"
# 134 "data/maps/Route102/scripts.pory"
	.string "…Whoa!$"
# 135 "data/maps/Route102/scripts.pory"

# 136 "data/maps/Route102/scripts.pory"
Route102_Text_WallyIDidIt:
# 137 "data/maps/Route102/scripts.pory"
	.string "WALLY: I did it… It's my…\n"
# 138 "data/maps/Route102/scripts.pory"
	.string "My POKéMON!$"
# 139 "data/maps/Route102/scripts.pory"

# 140 "data/maps/Route102/scripts.pory"
Route102_Text_LetsGoBack:
# 141 "data/maps/Route102/scripts.pory"
	.string "{PLAYER}, thank you!\n"
# 142 "data/maps/Route102/scripts.pory"
	.string "Let's go back to the GYM!$"
# 143 "data/maps/Route102/scripts.pory"

# 144 "data/maps/Route102/scripts.pory"
Route102_Text_ImNotVeryTall:
# 145 "data/maps/Route102/scripts.pory"
	.string "I'm…not very tall, so I sink right\n"
# 146 "data/maps/Route102/scripts.pory"
	.string "into tall grass.\p"
# 147 "data/maps/Route102/scripts.pory"
	.string "The grass goes up my nose and…\n"
# 148 "data/maps/Route102/scripts.pory"
	.string "Fwafwafwafwafwa…\p"
# 149 "data/maps/Route102/scripts.pory"
	.string "Fwatchoo!$"
# 150 "data/maps/Route102/scripts.pory"

# 151 "data/maps/Route102/scripts.pory"
Route102_Text_CatchWholeBunchOfPokemon:
# 152 "data/maps/Route102/scripts.pory"
	.string "I'm going to catch a whole bunch of\n"
# 153 "data/maps/Route102/scripts.pory"
	.string "POKéMON!$"
# 154 "data/maps/Route102/scripts.pory"

# 155 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignOldale:
# 156 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 157 "data/maps/Route102/scripts.pory"
	.string "{RIGHT_ARROW} OLDALE TOWN$"
# 158 "data/maps/Route102/scripts.pory"

# 159 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignPetalburg:
# 160 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 161 "data/maps/Route102/scripts.pory"
	.string "{LEFT_ARROW} PETALBURG CITY$"
# 162 "data/maps/Route102/scripts.pory"

# 163 "data/maps/Route102/scripts.pory"
Route102_Text_ReadyToFight:
# 164 "data/maps/Route102/scripts.pory"
	.string "Are you ready?$"
# 165 "data/maps/Route102/scripts.pory"

# 166 "data/maps/Route102/scripts.pory"
Route102_Text_ComeBackWhenReady:
# 167 "data/maps/Route102/scripts.pory"
	.string "Come back when you're ready.$"
