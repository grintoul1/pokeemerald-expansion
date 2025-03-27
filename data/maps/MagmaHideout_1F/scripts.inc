# 1 "data/maps/MagmaHideout_1F/scripts.pory"

# 2 "data/maps/MagmaHideout_1F/scripts.pory"
.set LOCALID_GRUNT1, 1
# 3 "data/maps/MagmaHideout_1F/scripts.pory"
.set LOCALID_GRUNT2, 3
# 4 "data/maps/MagmaHideout_1F/scripts.pory"
.set LOCALID_SHELLY, 7
# 5 "data/maps/MagmaHideout_1F/scripts.pory"

# 6 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_MapScripts::
# 7 "data/maps/MagmaHideout_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
# 8 "data/maps/MagmaHideout_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MagmaHideout_1F_OnWarp
# 9 "data/maps/MagmaHideout_1F/scripts.pory"
	.byte 0
# 10 "data/maps/MagmaHideout_1F/scripts.pory"

# 11 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_OnTransition:
# 12 "data/maps/MagmaHideout_1F/scripts.pory"
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
# 13 "data/maps/MagmaHideout_1F/scripts.pory"
	goto_if_lt VAR_MAGMAHIDEOUT_SHELLY_STATE, 1, MagmaHideout_1F_EventScript_GetShellyPosition
# 14 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 15 "data/maps/MagmaHideout_1F/scripts.pory"

# 16 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_OnWarp:
# 17 "data/maps/MagmaHideout_1F/scripts.pory"
	goto_if_lt VAR_MAGMAHIDEOUT_SHELLY_STATE, 1, MagmaHideout_1F_EventScript_GetShellyPosition
# 18 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 19 "data/maps/MagmaHideout_1F/scripts.pory"

# 20 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_EventScript_GetShellyPosition::
# 21 "data/maps/MagmaHideout_1F/scripts.pory"
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
# 22 "data/maps/MagmaHideout_1F/scripts.pory"
	goto_if_eq VAR_TEMP_2, 10, MagmaHideout_1F_EventScript_SetShellyPositionA
# 23 "data/maps/MagmaHideout_1F/scripts.pory"
	goto_if_eq VAR_TEMP_2, 25, MagmaHideout_1F_EventScript_SetShellyPositionB
# 24 "data/maps/MagmaHideout_1F/scripts.pory"
	goto_if_eq VAR_TEMP_2, 31, MagmaHideout_1F_EventScript_SetShellyPositionC
# 25 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 26 "data/maps/MagmaHideout_1F/scripts.pory"

# 27 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_EventScript_SetShellyPositionA::
# 28 "data/maps/MagmaHideout_1F/scripts.pory"
	setobjectxyperm LOCALID_SHELLY, 10, 34
# 29 "data/maps/MagmaHideout_1F/scripts.pory"
	waitmovement 0
# 30 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 31 "data/maps/MagmaHideout_1F/scripts.pory"

# 32 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_EventScript_SetShellyPositionB::
# 33 "data/maps/MagmaHideout_1F/scripts.pory"
	setobjectxyperm LOCALID_SHELLY, 25, 34
# 34 "data/maps/MagmaHideout_1F/scripts.pory"
	waitmovement 0
# 35 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 36 "data/maps/MagmaHideout_1F/scripts.pory"

# 37 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_EventScript_SetShellyPositionC::
# 38 "data/maps/MagmaHideout_1F/scripts.pory"
	setobjectxyperm LOCALID_SHELLY, 31, 3
# 39 "data/maps/MagmaHideout_1F/scripts.pory"
	waitmovement 0
# 40 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 41 "data/maps/MagmaHideout_1F/scripts.pory"

# 42 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_EventScript_AddShelly::
# 43 "data/maps/MagmaHideout_1F/scripts.pory"
	lockall
# 44 "data/maps/MagmaHideout_1F/scripts.pory"
	addobject LOCALID_SHELLY
# 45 "data/maps/MagmaHideout_1F/scripts.pory"
	delay 15
# 46 "data/maps/MagmaHideout_1F/scripts.pory"
	releaseall
# 47 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 48 "data/maps/MagmaHideout_1F/scripts.pory"

# 49 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_EventScript_Grunt1::
# 50 "data/maps/MagmaHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
# 51 "data/maps/MagmaHideout_1F/scripts.pory"
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 52 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 53 "data/maps/MagmaHideout_1F/scripts.pory"

# 54 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_EventScript_Grunt2::
# 55 "data/maps/MagmaHideout_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
# 56 "data/maps/MagmaHideout_1F/scripts.pory"
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 57 "data/maps/MagmaHideout_1F/scripts.pory"
	end
# 58 "data/maps/MagmaHideout_1F/scripts.pory"

# 59 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt1Intro:
# 60 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "When TEAM MAGMA has roll call, we get\n"
# 61 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "important guarding assignments in\l"
# 62 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "the order that we line up.\p"
# 63 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "That's why I'm stuck off in this corner.\n"
# 64 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "I'm always late to roll call!$"
# 65 "data/maps/MagmaHideout_1F/scripts.pory"

# 66 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt1Defeat:
# 67 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "I'm always late for training sessions,\n"
# 68 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "too!\p"
# 69 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "I hate to say it, but I'm wimpy…$"
# 70 "data/maps/MagmaHideout_1F/scripts.pory"

# 71 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt1PostBattle:
# 72 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Okay, I'll try to put a little more\n"
# 73 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "effort into things from now on…$"
# 74 "data/maps/MagmaHideout_1F/scripts.pory"

# 75 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt2Intro:
# 76 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Our leader told us to dig into\n"
# 77 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "MT. CHIMNEY, so we dug and dug.\p"
# 78 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "And in the course of digging, we came\n"
# 79 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "across something that blew our minds!\p"
# 80 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "What did we find?\p"
# 81 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Fuhahaha!\n"
# 82 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "I'll tell you if you beat me!$"
# 83 "data/maps/MagmaHideout_1F/scripts.pory"

# 84 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt2Defeat:
# 85 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Arrgh!\n"
# 86 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Taken down!$"
# 87 "data/maps/MagmaHideout_1F/scripts.pory"

# 88 "data/maps/MagmaHideout_1F/scripts.pory"
MagmaHideout_1F_Text_Grunt2PostBattle:
# 89 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "I won't tell you after all.\n"
# 90 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "You'll find out when you get there!\p"
# 91 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "It'd be better if you saved surprises\n"
# 92 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "to the end, don't you think?$"
