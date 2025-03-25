# 1 "data/maps/FortreeCity/scripts.pory"

# 2 "data/maps/FortreeCity/scripts.pory"
.set LOCALID_SHELLY, 8
# 3 "data/maps/FortreeCity/scripts.pory"

# 4 "data/maps/FortreeCity/scripts.pory"

# 5 "data/maps/FortreeCity/scripts.pory"
FortreeCity_MapScripts::
# 6 "data/maps/FortreeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
# 7 "data/maps/FortreeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
# 8 "data/maps/FortreeCity/scripts.pory"
	.byte 0
# 9 "data/maps/FortreeCity/scripts.pory"

# 10 "data/maps/FortreeCity/scripts.pory"
FortreeCity_OnTransition:
# 11 "data/maps/FortreeCity/scripts.pory"
	setflag FLAG_VISITED_FORTREE_CITY
# 12 "data/maps/FortreeCity/scripts.pory"
	end
# 13 "data/maps/FortreeCity/scripts.pory"

# 14 "data/maps/FortreeCity/scripts.pory"
FortreeCity_OnResume:
# 15 "data/maps/FortreeCity/scripts.pory"
	setstepcallback STEP_CB_FORTREE_BRIDGE
# 16 "data/maps/FortreeCity/scripts.pory"
	end
# 17 "data/maps/FortreeCity/scripts.pory"

# 18 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Shelly::
# 19 "data/maps/FortreeCity/scripts.pory"
	lockall 
# 20 "data/maps/FortreeCity/scripts.pory"
	delay 50
# 21 "data/maps/FortreeCity/scripts.pory"
	setfieldeffectargument 0, 1
# 22 "data/maps/FortreeCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 23 "data/maps/FortreeCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 24 "data/maps/FortreeCity/scripts.pory"
	addobject LOCALID_SHELLY
# 25 "data/maps/FortreeCity/scripts.pory"
	applymovement LOCALID_SHELLY, FortreeCity_Movement_ShellyApproachPlayer
# 26 "data/maps/FortreeCity/scripts.pory"
	waitmovement 0
# 27 "data/maps/FortreeCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 28 "data/maps/FortreeCity/scripts.pory"
	waitmovement 0
# 29 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_ShellyComeToJaggedPass, MSGBOX_DEFAULT
# 30 "data/maps/FortreeCity/scripts.pory"
	closemessage
# 31 "data/maps/FortreeCity/scripts.pory"
	giveitem ITEM_HM_FLY
# 32 "data/maps/FortreeCity/scripts.pory"
	closemessage
# 33 "data/maps/FortreeCity/scripts.pory"
	applymovement LOCALID_SHELLY, Common_Movement_WalkInPlaceFasterDown
# 34 "data/maps/FortreeCity/scripts.pory"
	waitmovement 0
# 35 "data/maps/FortreeCity/scripts.pory"
	delay 50
# 36 "data/maps/FortreeCity/scripts.pory"
	setfieldeffectargument 0, 1
# 37 "data/maps/FortreeCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 38 "data/maps/FortreeCity/scripts.pory"
	delay 15
# 39 "data/maps/FortreeCity/scripts.pory"
	removeobject LOCALID_SHELLY
# 40 "data/maps/FortreeCity/scripts.pory"
	setflag FLAG_HIDE_FORTREE_SHELLY
# 41 "data/maps/FortreeCity/scripts.pory"
	clearflag FLAG_HIDE_JAGGED_PASS_SHELLY
# 42 "data/maps/FortreeCity/scripts.pory"
	addvar VAR_FORTREE_CITY_STATE, 1 
# 43 "data/maps/FortreeCity/scripts.pory"
	end
# 44 "data/maps/FortreeCity/scripts.pory"

# 45 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Movement_ShellyApproachPlayer:
# 46 "data/maps/FortreeCity/scripts.pory"
	walk_right
# 47 "data/maps/FortreeCity/scripts.pory"
	step_end
# 48 "data/maps/FortreeCity/scripts.pory"

# 49 "data/maps/FortreeCity/scripts.pory"

# 50 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Man::
# 51 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
# 52 "data/maps/FortreeCity/scripts.pory"
	end
# 53 "data/maps/FortreeCity/scripts.pory"

# 54 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Woman::
# 55 "data/maps/FortreeCity/scripts.pory"
	lock
# 56 "data/maps/FortreeCity/scripts.pory"
	faceplayer
# 57 "data/maps/FortreeCity/scripts.pory"
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
# 58 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
# 59 "data/maps/FortreeCity/scripts.pory"
	release
# 60 "data/maps/FortreeCity/scripts.pory"
	end
# 61 "data/maps/FortreeCity/scripts.pory"

# 62 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_WomanGymAccessible::
# 63 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
# 64 "data/maps/FortreeCity/scripts.pory"
	release
# 65 "data/maps/FortreeCity/scripts.pory"
	end
# 66 "data/maps/FortreeCity/scripts.pory"

# 67 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Girl::
# 68 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
# 69 "data/maps/FortreeCity/scripts.pory"
	end
# 70 "data/maps/FortreeCity/scripts.pory"

# 71 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_OldMan::
# 72 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
# 73 "data/maps/FortreeCity/scripts.pory"
	end
# 74 "data/maps/FortreeCity/scripts.pory"

# 75 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Boy::
# 76 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
# 77 "data/maps/FortreeCity/scripts.pory"
	end
# 78 "data/maps/FortreeCity/scripts.pory"

# 79 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_GameboyKid::
# 80 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
# 81 "data/maps/FortreeCity/scripts.pory"
	end
# 82 "data/maps/FortreeCity/scripts.pory"

# 83 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_CitySign::
# 84 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
# 85 "data/maps/FortreeCity/scripts.pory"
	end
# 86 "data/maps/FortreeCity/scripts.pory"

# 87 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_GymSign::
# 88 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
# 89 "data/maps/FortreeCity/scripts.pory"
	end
# 90 "data/maps/FortreeCity/scripts.pory"

# 91 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_Kecleon::
# 92 "data/maps/FortreeCity/scripts.pory"
	lock
# 93 "data/maps/FortreeCity/scripts.pory"
	faceplayer
# 94 "data/maps/FortreeCity/scripts.pory"
	checkitem ITEM_DEVON_SCOPE
# 95 "data/maps/FortreeCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
# 96 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
# 97 "data/maps/FortreeCity/scripts.pory"
	release
# 98 "data/maps/FortreeCity/scripts.pory"
	end
# 99 "data/maps/FortreeCity/scripts.pory"

# 100 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_AskUseDevonScope::
# 101 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
# 102 "data/maps/FortreeCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
# 103 "data/maps/FortreeCity/scripts.pory"
	release
# 104 "data/maps/FortreeCity/scripts.pory"
	end
# 105 "data/maps/FortreeCity/scripts.pory"

# 106 "data/maps/FortreeCity/scripts.pory"
FortreeCity_EventScript_UseDevonScope::
# 107 "data/maps/FortreeCity/scripts.pory"
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
# 108 "data/maps/FortreeCity/scripts.pory"
	closemessage
# 109 "data/maps/FortreeCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
# 110 "data/maps/FortreeCity/scripts.pory"
	waitmovement 0
# 111 "data/maps/FortreeCity/scripts.pory"
	waitse
# 112 "data/maps/FortreeCity/scripts.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
# 113 "data/maps/FortreeCity/scripts.pory"
	delay 40
# 114 "data/maps/FortreeCity/scripts.pory"
	waitmoncry
# 115 "data/maps/FortreeCity/scripts.pory"
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
# 116 "data/maps/FortreeCity/scripts.pory"
	waitmovement 0
# 117 "data/maps/FortreeCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 118 "data/maps/FortreeCity/scripts.pory"
	setflag FLAG_KECLEON_FLED_FORTREE
# 119 "data/maps/FortreeCity/scripts.pory"
	release
# 120 "data/maps/FortreeCity/scripts.pory"
	end
# 121 "data/maps/FortreeCity/scripts.pory"

# 122 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Movement_KecleonFlee:
# 123 "data/maps/FortreeCity/scripts.pory"
	walk_right
# 124 "data/maps/FortreeCity/scripts.pory"
	step_end
# 125 "data/maps/FortreeCity/scripts.pory"

# 126 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_ShellyComeToJaggedPass:
# 127 "data/maps/FortreeCity/scripts.pory"
	.string "Shelly: Hey kid. Remember me?\p"
# 128 "data/maps/FortreeCity/scripts.pory"
	.string "Archie told me what happened at Mt.\n"
# 129 "data/maps/FortreeCity/scripts.pory"
	.string "Pyre.\p"
# 130 "data/maps/FortreeCity/scripts.pory"
	.string "Whatever your opinion on Team Aqua's\n"
# 131 "data/maps/FortreeCity/scripts.pory"
	.string "goals, you have so recognise the harm\l"
# 132 "data/maps/FortreeCity/scripts.pory"
	.string "Team Magma will cause to Hoenn.\p"
# 133 "data/maps/FortreeCity/scripts.pory"
	.string "I stuck around Mt. Chimney after you\n"
# 134 "data/maps/FortreeCity/scripts.pory"
	.string "left and believe I have located Team\l"
# 135 "data/maps/FortreeCity/scripts.pory"
	.string "Magma's hideout.\p"
# 136 "data/maps/FortreeCity/scripts.pory"
	.string "Archie doesn't trust you, perhaps with\n"
# 137 "data/maps/FortreeCity/scripts.pory"
	.string "good reason, but I trust that you also\l"
# 138 "data/maps/FortreeCity/scripts.pory"
	.string "don't want Team Magma to succeed.\p"
# 139 "data/maps/FortreeCity/scripts.pory"
	.string "I could use some help infiltrating the\n"
# 140 "data/maps/FortreeCity/scripts.pory"
	.string "Team Magma hideout, and I can't call on\l"
# 141 "data/maps/FortreeCity/scripts.pory"
	.string "Matt right now.\p"
# 142 "data/maps/FortreeCity/scripts.pory"
	.string "If you fancy doing something useful for\n"
# 143 "data/maps/FortreeCity/scripts.pory"
	.string "once, meet me on Jagged Pass near\l"
# 144 "data/maps/FortreeCity/scripts.pory"
	.string "Lavaridge Town.\p"
# 145 "data/maps/FortreeCity/scripts.pory"
	.string "Here, take this as well. I hope to see\n"
# 146 "data/maps/FortreeCity/scripts.pory"
	.string "you there.$"
# 147 "data/maps/FortreeCity/scripts.pory"

# 148 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_SawGiganticPokemonInSky:
# 149 "data/maps/FortreeCity/scripts.pory"
	.string "No one believes me, but I saw this\n"
# 150 "data/maps/FortreeCity/scripts.pory"
	.string "gigantic POKéMON in the sky.\p"
# 151 "data/maps/FortreeCity/scripts.pory"
	.string "It seemed to squirm as it flew toward\n"
# 152 "data/maps/FortreeCity/scripts.pory"
	.string "ROUTE 131.\p"
# 153 "data/maps/FortreeCity/scripts.pory"
	.string "By the way… Sniff…\n"
# 154 "data/maps/FortreeCity/scripts.pory"
	.string "Um… You, uh…smell singed.\p"
# 155 "data/maps/FortreeCity/scripts.pory"
	.string "Were you at a volcano or something?$"
# 156 "data/maps/FortreeCity/scripts.pory"

# 157 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_SomethingBlockingGym:
# 158 "data/maps/FortreeCity/scripts.pory"
	.string "I want to go to the POKéMON GYM,\n"
# 159 "data/maps/FortreeCity/scripts.pory"
	.string "but something's blocking the way.\p"
# 160 "data/maps/FortreeCity/scripts.pory"
	.string "After all the bother I went through\n"
# 161 "data/maps/FortreeCity/scripts.pory"
	.string "training on ROUTE 120…$"
# 162 "data/maps/FortreeCity/scripts.pory"

# 163 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_ThisTimeIllBeatWinona:
# 164 "data/maps/FortreeCity/scripts.pory"
	.string "I've got my pride-and-joy POKéMON\n"
# 165 "data/maps/FortreeCity/scripts.pory"
	.string "with me. This time, I'll beat WINONA.$"
# 166 "data/maps/FortreeCity/scripts.pory"

# 167 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_TreesGrowByDrinkingRainwater:
# 168 "data/maps/FortreeCity/scripts.pory"
	.string "The ground absorbs rainwater, and\n"
# 169 "data/maps/FortreeCity/scripts.pory"
	.string "trees grow by drinking that water…\p"
# 170 "data/maps/FortreeCity/scripts.pory"
	.string "Our FORTREE CITY exists because\n"
# 171 "data/maps/FortreeCity/scripts.pory"
	.string "there's both water and soil.$"
# 172 "data/maps/FortreeCity/scripts.pory"

# 173 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_EveryoneHealthyAndLively:
# 174 "data/maps/FortreeCity/scripts.pory"
	.string "The CITY consists of homes built on\n"
# 175 "data/maps/FortreeCity/scripts.pory"
	.string "trees.\p"
# 176 "data/maps/FortreeCity/scripts.pory"
	.string "Perhaps because of that lifestyle,\n"
# 177 "data/maps/FortreeCity/scripts.pory"
	.string "everyone is healthy and lively.\p"
# 178 "data/maps/FortreeCity/scripts.pory"
	.string "Why, even myself--I feel as if I've\n"
# 179 "data/maps/FortreeCity/scripts.pory"
	.string "grown thirty years younger.$"
# 180 "data/maps/FortreeCity/scripts.pory"

# 181 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_BugPokemonComeThroughWindow:
# 182 "data/maps/FortreeCity/scripts.pory"
	.string "Living on top of trees is okay.\p"
# 183 "data/maps/FortreeCity/scripts.pory"
	.string "But sometimes BUG POKéMON come in\n"
# 184 "data/maps/FortreeCity/scripts.pory"
	.string "through windows.\l"
# 185 "data/maps/FortreeCity/scripts.pory"
	.string "It can be really startling.$"
# 186 "data/maps/FortreeCity/scripts.pory"

# 187 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_PokemonThatEvolveWhenTraded:
# 188 "data/maps/FortreeCity/scripts.pory"
	.string "There are POKéMON that evolve when\n"
# 189 "data/maps/FortreeCity/scripts.pory"
	.string "you trade them! That's what I heard.$"
# 190 "data/maps/FortreeCity/scripts.pory"

# 191 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_SomethingUnseeable:
# 192 "data/maps/FortreeCity/scripts.pory"
	.string "Something unseeable is in the way.$"
# 193 "data/maps/FortreeCity/scripts.pory"

# 194 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_UnseeableUseDevonScope:
# 195 "data/maps/FortreeCity/scripts.pory"
	.string "Something unseeable is in the way.\p"
# 196 "data/maps/FortreeCity/scripts.pory"
	.string "Want to use the DEVON SCOPE?$"
# 197 "data/maps/FortreeCity/scripts.pory"

# 198 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_UsedDevonScopePokemonFled:
# 199 "data/maps/FortreeCity/scripts.pory"
	.string "{PLAYER} used the DEVON SCOPE.\p"
# 200 "data/maps/FortreeCity/scripts.pory"
	.string "An invisible POKéMON became completely\n"
# 201 "data/maps/FortreeCity/scripts.pory"
	.string "visible!\p"
# 202 "data/maps/FortreeCity/scripts.pory"
	.string "The startled POKéMON fled!$"
# 203 "data/maps/FortreeCity/scripts.pory"

# 204 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_CitySign:
# 205 "data/maps/FortreeCity/scripts.pory"
	.string "FORTREE CITY\n"
# 206 "data/maps/FortreeCity/scripts.pory"
	.string "“The treetop city that frolics with\l"
# 207 "data/maps/FortreeCity/scripts.pory"
	.string "nature.”$"
# 208 "data/maps/FortreeCity/scripts.pory"

# 209 "data/maps/FortreeCity/scripts.pory"
FortreeCity_Text_GymSign:
# 210 "data/maps/FortreeCity/scripts.pory"
	.string "FORTREE CITY POKéMON GYM\n"
# 211 "data/maps/FortreeCity/scripts.pory"
	.string "LEADER: WINONA\p"
# 212 "data/maps/FortreeCity/scripts.pory"
	.string "“The bird user taking flight into\n"
# 213 "data/maps/FortreeCity/scripts.pory"
	.string "the world.”$"
