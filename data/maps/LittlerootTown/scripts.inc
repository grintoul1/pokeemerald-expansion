# 1 "data/maps/LittlerootTown/scripts.pory"

# 2 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_TWIN, 1
# 3 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_MOM, 4
# 4 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_RIVAL, 7
# 5 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_BIRCH, 8
# 6 "data/maps/LittlerootTown/scripts.pory"
.set LOCALID_EMMIE, 9
# 7 "data/maps/LittlerootTown/scripts.pory"

# 8 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_MapScripts::
# 9 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
# 10 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
# 11 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
# 12 "data/maps/LittlerootTown/scripts.pory"
	.byte 0
# 13 "data/maps/LittlerootTown/scripts.pory"

# 14 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
# 15 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Met Rival
# 16 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Saving Birch
# 17 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Received Pokedex
# 18 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Running Shoes
# 19 "data/maps/LittlerootTown/scripts.pory"

# 20 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
# 21 "data/maps/LittlerootTown/scripts.pory"
	@ 1: In truck male
# 22 "data/maps/LittlerootTown/scripts.pory"
	@ 2: In truck female
# 23 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered house
# 24 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Told to go set clock
# 25 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Entered 2F to set clock
# 26 "data/maps/LittlerootTown/scripts.pory"
	@ 6: Set clock
# 27 "data/maps/LittlerootTown/scripts.pory"
	@ 7: Told to go meet rival
# 28 "data/maps/LittlerootTown/scripts.pory"

# 29 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
# 30 "data/maps/LittlerootTown/scripts.pory"
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
# 31 "data/maps/LittlerootTown/scripts.pory"
	@ 1: On Truck (and is corresponding gender)
# 32 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Met Rival's Mom (and is corresponding gender)
# 33 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Entered Hall of Fame
# 34 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Completed Lati TV / SS Ticket event
# 35 "data/maps/LittlerootTown/scripts.pory"
	@ 5: Exited house after above event
# 36 "data/maps/LittlerootTown/scripts.pory"

# 37 "data/maps/LittlerootTown/scripts.pory"
	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
# 38 "data/maps/LittlerootTown/scripts.pory"
	@ 1: Never occurs
# 39 "data/maps/LittlerootTown/scripts.pory"
	@ 2: Entered Rival's bedroom
# 40 "data/maps/LittlerootTown/scripts.pory"
	@ 3: Met Rival
# 41 "data/maps/LittlerootTown/scripts.pory"
	@ 4: Received Pokedex
# 42 "data/maps/LittlerootTown/scripts.pory"

# 43 "data/maps/LittlerootTown/scripts.pory"

# 44 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnTransition:
# 45 "data/maps/LittlerootTown/scripts.pory"
	call_if_set FLAG_ABNORMAL_WEATHER_SUN, Common_EventScript_SetWeatherIntenseSun
# 46 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 47 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 48 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
# 49 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 50 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
# 51 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 52 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
# 53 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
# 54 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
# 55 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
# 56 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
# 57 "data/maps/LittlerootTown/scripts.pory"
	end
# 58 "data/maps/LittlerootTown/scripts.pory"

# 59 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
# 60 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
# 61 "data/maps/LittlerootTown/scripts.pory"
	return
# 62 "data/maps/LittlerootTown/scripts.pory"

# 63 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_HideMapNamePopup::
# 64 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 65 "data/maps/LittlerootTown/scripts.pory"
	return
# 66 "data/maps/LittlerootTown/scripts.pory"

# 67 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalLeftForRoute103::
# 68 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
# 69 "data/maps/LittlerootTown/scripts.pory"
	return
# 70 "data/maps/LittlerootTown/scripts.pory"

# 71 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveRivalFromOldale::
# 72 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 73 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 74 "data/maps/LittlerootTown/scripts.pory"
	return
# 75 "data/maps/LittlerootTown/scripts.pory"

# 76 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
# 77 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
# 78 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
# 79 "data/maps/LittlerootTown/scripts.pory"
	return
# 80 "data/maps/LittlerootTown/scripts.pory"

# 81 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MoveMomToMaysDoor::
# 82 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 8
# 83 "data/maps/LittlerootTown/scripts.pory"
	return
# 84 "data/maps/LittlerootTown/scripts.pory"

# 85 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinPos::
# 86 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 87 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 10, 1
# 88 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_UP
# 89 "data/maps/LittlerootTown/scripts.pory"
	return
# 90 "data/maps/LittlerootTown/scripts.pory"

# 91 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 92 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_TWIN, 7, 2
# 93 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_TWIN, MOVEMENT_TYPE_FACE_DOWN
# 94 "data/maps/LittlerootTown/scripts.pory"
	return
# 95 "data/maps/LittlerootTown/scripts.pory"

# 96 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
# 97 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_DOWN
# 98 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 99 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
# 100 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
# 101 "data/maps/LittlerootTown/scripts.pory"
	return
# 102 "data/maps/LittlerootTown/scripts.pory"

# 103 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
# 104 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 5, 9
# 105 "data/maps/LittlerootTown/scripts.pory"
	return
# 106 "data/maps/LittlerootTown/scripts.pory"

# 107 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
# 108 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm LOCALID_MOM, 14, 9
# 109 "data/maps/LittlerootTown/scripts.pory"
	return
# 110 "data/maps/LittlerootTown/scripts.pory"

# 111 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnFrame:
# 112 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
# 113 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
# 114 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
# 115 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 116 "data/maps/LittlerootTown/scripts.pory"

# 117 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckMale::
# 118 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 119 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 120 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 121 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 122 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 123 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 124 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 125 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 126 "data/maps/LittlerootTown/scripts.pory"
	end
# 127 "data/maps/LittlerootTown/scripts.pory"

# 128 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_StepOffTruckFemale::
# 129 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 130 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 131 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 132 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 133 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 134 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 135 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 136 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 137 "data/maps/LittlerootTown/scripts.pory"
	end
# 138 "data/maps/LittlerootTown/scripts.pory"

# 139 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoInsideWithMom::
# 140 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 141 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 142 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 143 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 144 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 145 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 146 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_MOM
# 147 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitHouse
# 148 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 149 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 150 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 151 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 152 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 153 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 154 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 155 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 156 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachDoor
# 157 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 158 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 159 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 160 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 161 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomEnterHouse
# 162 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 163 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 164 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 165 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 166 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 167 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 168 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 169 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 170 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 171 "data/maps/LittlerootTown/scripts.pory"
	return
# 172 "data/maps/LittlerootTown/scripts.pory"

# 173 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 174 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 175 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 176 "data/maps/LittlerootTown/scripts.pory"

# 177 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 178 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 179 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
# 180 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 181 "data/maps/LittlerootTown/scripts.pory"

# 182 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 183 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 184 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 185 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 186 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 187 "data/maps/LittlerootTown/scripts.pory"

# 188 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 189 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 190 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
# 191 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 192 "data/maps/LittlerootTown/scripts.pory"

# 193 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 194 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 195 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 196 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 197 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 198 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 199 "data/maps/LittlerootTown/scripts.pory"

# 200 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 201 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 202 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 203 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 204 "data/maps/LittlerootTown/scripts.pory"

# 205 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 206 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 207 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 208 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 209 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 210 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 211 "data/maps/LittlerootTown/scripts.pory"

# 212 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BeginDexUpgradeScene::
# 213 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 214 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 215 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
# 216 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 217 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 218 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 219 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 220 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 221 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 222 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 223 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 224 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 225 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 226 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 227 "data/maps/LittlerootTown/scripts.pory"
	end
# 228 "data/maps/LittlerootTown/scripts.pory"

# 229 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_OnWarp:
# 230 "data/maps/LittlerootTown/scripts.pory"
	call_if_set FLAG_ABNORMAL_WEATHER_SUN, Common_EventScript_SetWeatherIntenseSun
# 231 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
# 232 "data/maps/LittlerootTown/scripts.pory"
	.2byte 0
# 233 "data/maps/LittlerootTown/scripts.pory"

# 234 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 235 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_BIRCH
# 236 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_RIVAL
# 237 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 238 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
# 239 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
# 240 "data/maps/LittlerootTown/scripts.pory"
	end
# 241 "data/maps/LittlerootTown/scripts.pory"

# 242 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
# 243 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 6, 10
# 244 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 5, 10
# 245 "data/maps/LittlerootTown/scripts.pory"
	end
# 246 "data/maps/LittlerootTown/scripts.pory"

# 247 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
# 248 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_RIVAL, 13, 10
# 249 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_BIRCH, 14, 10
# 250 "data/maps/LittlerootTown/scripts.pory"
	end
# 251 "data/maps/LittlerootTown/scripts.pory"

# 252 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_FatMan::
# 253 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 254 "data/maps/LittlerootTown/scripts.pory"
	end
# 255 "data/maps/LittlerootTown/scripts.pory"

# 256 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Boy::
# 257 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 258 "data/maps/LittlerootTown/scripts.pory"
	end
# 259 "data/maps/LittlerootTown/scripts.pory"

# 260 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Twin::
# 261 "data/maps/LittlerootTown/scripts.pory"
	lock
# 262 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 263 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 264 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 265 "data/maps/LittlerootTown/scripts.pory"
	goto_if_ne VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_GoSaveBirch
# 266 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 267 "data/maps/LittlerootTown/scripts.pory"
	release
# 268 "data/maps/LittlerootTown/scripts.pory"
	end
# 269 "data/maps/LittlerootTown/scripts.pory"

# 270 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirch::
# 271 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 272 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 273 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 274 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 275 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 276 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 277 "data/maps/LittlerootTown/scripts.pory"
	release
# 278 "data/maps/LittlerootTown/scripts.pory"
	end
# 279 "data/maps/LittlerootTown/scripts.pory"

# 280 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_YouSavedBirch::
# 281 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 282 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 283 "data/maps/LittlerootTown/scripts.pory"
	release
# 284 "data/maps/LittlerootTown/scripts.pory"
	end
# 285 "data/maps/LittlerootTown/scripts.pory"

# 286 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoodLuck::
# 287 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 288 "data/maps/LittlerootTown/scripts.pory"
	release
# 289 "data/maps/LittlerootTown/scripts.pory"
	end
# 290 "data/maps/LittlerootTown/scripts.pory"

# 291 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 292 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 293 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
# 294 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 295 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 296 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnLeft
# 297 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 298 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 299 "data/maps/LittlerootTown/scripts.pory"
	end
# 300 "data/maps/LittlerootTown/scripts.pory"

# 301 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_DangerousWithoutPokemon::
# 302 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 303 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 304 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 305 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 306 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 307 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 308 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 309 "data/maps/LittlerootTown/scripts.pory"
	return
# 310 "data/maps/LittlerootTown/scripts.pory"

# 311 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 312 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 313 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 314 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 315 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 316 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 317 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 318 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 319 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 320 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 321 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 322 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 323 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 324 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 325 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 326 "data/maps/LittlerootTown/scripts.pory"

# 327 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 328 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 329 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 330 "data/maps/LittlerootTown/scripts.pory"

# 331 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 332 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 333 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 334 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 335 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 336 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 337 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 338 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 339 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 340 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 341 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 342 "data/maps/LittlerootTown/scripts.pory"

# 343 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 344 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 345 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 346 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
# 347 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 348 "data/maps/LittlerootTown/scripts.pory"

# 349 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 350 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 351 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
# 352 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 353 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 354 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, LittlerootTown_Movement_TwinReturnRight
# 355 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 356 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 357 "data/maps/LittlerootTown/scripts.pory"
	end
# 358 "data/maps/LittlerootTown/scripts.pory"

# 359 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 360 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 361 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 362 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 363 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 364 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 365 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 366 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 367 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 368 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 369 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 370 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 371 "data/maps/LittlerootTown/scripts.pory"
	face_down
# 372 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 373 "data/maps/LittlerootTown/scripts.pory"

# 374 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 375 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 376 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 377 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 378 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 379 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 380 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
# 381 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 382 "data/maps/LittlerootTown/scripts.pory"

# 383 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GoSaveBirchTrigger::
# 384 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 385 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterRight
# 386 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 387 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 388 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 389 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 390 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 391 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 392 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
# 393 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 394 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 395 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 396 "data/maps/LittlerootTown/scripts.pory"
	end
# 397 "data/maps/LittlerootTown/scripts.pory"

# 398 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_TownSign::
# 399 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 400 "data/maps/LittlerootTown/scripts.pory"
	end
# 401 "data/maps/LittlerootTown/scripts.pory"

# 402 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsLabSign::
# 403 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 404 "data/maps/LittlerootTown/scripts.pory"
	end
# 405 "data/maps/LittlerootTown/scripts.pory"

# 406 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BrendansHouseSign::
# 407 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 408 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 409 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
# 410 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
# 411 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 412 "data/maps/LittlerootTown/scripts.pory"
	end
# 413 "data/maps/LittlerootTown/scripts.pory"

# 414 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignMale::
# 415 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 416 "data/maps/LittlerootTown/scripts.pory"
	return
# 417 "data/maps/LittlerootTown/scripts.pory"

# 418 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignFemale::
# 419 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 420 "data/maps/LittlerootTown/scripts.pory"
	return
# 421 "data/maps/LittlerootTown/scripts.pory"

# 422 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MaysHouseSign::
# 423 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 424 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 425 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
# 426 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
# 427 "data/maps/LittlerootTown/scripts.pory"
	releaseall
# 428 "data/maps/LittlerootTown/scripts.pory"
	end
# 429 "data/maps/LittlerootTown/scripts.pory"

# 430 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_BirchsHouseSignMale::
# 431 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
# 432 "data/maps/LittlerootTown/scripts.pory"
	return
# 433 "data/maps/LittlerootTown/scripts.pory"

# 434 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_PlayersHouseSignFemale::
# 435 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
# 436 "data/maps/LittlerootTown/scripts.pory"
	return
# 437 "data/maps/LittlerootTown/scripts.pory"

# 438 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 439 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 440 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 441 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 10, 9
# 442 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_EMMIE, 9, 9
# 443 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_MOM
# 444 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_EMMIE
# 445 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 446 "data/maps/LittlerootTown/scripts.pory"
	end
# 447 "data/maps/LittlerootTown/scripts.pory"

# 448 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 449 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 450 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 451 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_MOM, 11, 9
# 452 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy LOCALID_EMMIE, 10, 9
# 453 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_MOM
# 454 "data/maps/LittlerootTown/scripts.pory"
	addobject LOCALID_EMMIE
# 455 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 456 "data/maps/LittlerootTown/scripts.pory"
	end
# 457 "data/maps/LittlerootTown/scripts.pory"

# 458 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 459 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 460 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 461 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 462 "data/maps/LittlerootTown/scripts.pory"
	end
# 463 "data/maps/LittlerootTown/scripts.pory"

# 464 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 465 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 466 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 467 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 468 "data/maps/LittlerootTown/scripts.pory"
	end
# 469 "data/maps/LittlerootTown/scripts.pory"

# 470 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 471 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 472 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 473 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 474 "data/maps/LittlerootTown/scripts.pory"
	end
# 475 "data/maps/LittlerootTown/scripts.pory"

# 476 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 477 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 478 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 479 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
# 480 "data/maps/LittlerootTown/scripts.pory"
	end
# 481 "data/maps/LittlerootTown/scripts.pory"

# 482 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 483 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 484 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomNoticePlayerMale
# 485 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomNoticePlayerFemale
# 486 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 487 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 488 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 489 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 490 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 491 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 492 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomApproachPlayerMale
# 493 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomApproachPlayerFemale
# 494 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 495 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 496 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_EMMIE, Common_Movement_WalkInPlaceFasterDown
# 497 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 498 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_MomReturnHomeMale
# 499 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_MomReturnHomeFemale
# 500 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkUp
# 501 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 502 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_FacePlayer
# 503 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 504 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_EmmieIntroduction
# 505 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_EMMIE
# 506 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_EMMIE
# 507 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 508 "data/maps/LittlerootTown/scripts.pory"
	end
# 509 "data/maps/LittlerootTown/scripts.pory"

# 510 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_EmmieIntroduction::
# 511 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_EmmieLetMeExplain, MSGBOX_DEFAULT
# 512 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 513 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_STUFFUL, 5
# 514 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_SKITTY, 5, ITEM_MOON_STONE
# 515 "data/maps/LittlerootTown/scripts.pory"
	givemon SPECIES_STUFFUL, 5
# 516 "data/maps/LittlerootTown/scripts.pory"
	return
# 517 "data/maps/LittlerootTown/scripts.pory"

# 518 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsMale::
# 519 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 520 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 521 "data/maps/LittlerootTown/scripts.pory"
	return
# 522 "data/maps/LittlerootTown/scripts.pory"

# 523 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
# 524 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 525 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
# 526 "data/maps/LittlerootTown/scripts.pory"
	return
# 527 "data/maps/LittlerootTown/scripts.pory"

# 528 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerMale::
# 529 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterRight
# 530 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 531 "data/maps/LittlerootTown/scripts.pory"
	return
# 532 "data/maps/LittlerootTown/scripts.pory"

# 533 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomNoticePlayerFemale::
# 534 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterLeft
# 535 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 536 "data/maps/LittlerootTown/scripts.pory"
	return
# 537 "data/maps/LittlerootTown/scripts.pory"

# 538 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale::
# 539 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 540 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 541 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
# 542 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
# 543 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
# 544 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
# 545 "data/maps/LittlerootTown/scripts.pory"
	return
# 546 "data/maps/LittlerootTown/scripts.pory"

# 547 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale::
# 548 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
# 549 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
# 550 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
# 551 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
# 552 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
# 553 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
# 554 "data/maps/LittlerootTown/scripts.pory"
	return
# 555 "data/maps/LittlerootTown/scripts.pory"

# 556 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer0::
# 557 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 558 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 559 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer0
# 560 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 561 "data/maps/LittlerootTown/scripts.pory"
	return
# 562 "data/maps/LittlerootTown/scripts.pory"

# 563 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayer1::
# 564 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 565 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 566 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayer1
# 567 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 568 "data/maps/LittlerootTown/scripts.pory"
	return
# 569 "data/maps/LittlerootTown/scripts.pory"

# 570 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale2::
# 571 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 572 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 573 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
# 574 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 575 "data/maps/LittlerootTown/scripts.pory"
	return
# 576 "data/maps/LittlerootTown/scripts.pory"

# 577 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale3::
# 578 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 579 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 580 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
# 581 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 582 "data/maps/LittlerootTown/scripts.pory"
	return
# 583 "data/maps/LittlerootTown/scripts.pory"

# 584 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale4::
# 585 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 586 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 587 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
# 588 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 589 "data/maps/LittlerootTown/scripts.pory"
	return
# 590 "data/maps/LittlerootTown/scripts.pory"

# 591 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerMale5::
# 592 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 593 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 594 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
# 595 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 596 "data/maps/LittlerootTown/scripts.pory"
	return
# 597 "data/maps/LittlerootTown/scripts.pory"

# 598 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale2::
# 599 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 600 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 601 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
# 602 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 603 "data/maps/LittlerootTown/scripts.pory"
	return
# 604 "data/maps/LittlerootTown/scripts.pory"

# 605 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale3::
# 606 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 607 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 608 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
# 609 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 610 "data/maps/LittlerootTown/scripts.pory"
	return
# 611 "data/maps/LittlerootTown/scripts.pory"

# 612 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale4::
# 613 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 614 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 615 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
# 616 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 617 "data/maps/LittlerootTown/scripts.pory"
	return
# 618 "data/maps/LittlerootTown/scripts.pory"

# 619 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomApproachPlayerFemale5::
# 620 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 621 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 622 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
# 623 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 624 "data/maps/LittlerootTown/scripts.pory"
	return
# 625 "data/maps/LittlerootTown/scripts.pory"

# 626 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale::
# 627 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 628 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 629 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
# 630 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
# 631 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
# 632 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
# 633 "data/maps/LittlerootTown/scripts.pory"
	return
# 634 "data/maps/LittlerootTown/scripts.pory"

# 635 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale::
# 636 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
# 637 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
# 638 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
# 639 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
# 640 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
# 641 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
# 642 "data/maps/LittlerootTown/scripts.pory"
	return
# 643 "data/maps/LittlerootTown/scripts.pory"

# 644 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome0::
# 645 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome0
# 646 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 647 "data/maps/LittlerootTown/scripts.pory"
	return
# 648 "data/maps/LittlerootTown/scripts.pory"

# 649 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHome1::
# 650 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHome1
# 651 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 652 "data/maps/LittlerootTown/scripts.pory"
	return
# 653 "data/maps/LittlerootTown/scripts.pory"

# 654 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale2::
# 655 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale2
# 656 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 657 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 658 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 659 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 660 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 661 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 662 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 663 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 664 "data/maps/LittlerootTown/scripts.pory"
	return
# 665 "data/maps/LittlerootTown/scripts.pory"

# 666 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale3::
# 667 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale3
# 668 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 669 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 670 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 671 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 672 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 673 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 674 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 675 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 676 "data/maps/LittlerootTown/scripts.pory"
	return
# 677 "data/maps/LittlerootTown/scripts.pory"

# 678 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale4::
# 679 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale4
# 680 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 681 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 682 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 683 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 684 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 685 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 686 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 687 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 688 "data/maps/LittlerootTown/scripts.pory"
	return
# 689 "data/maps/LittlerootTown/scripts.pory"

# 690 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeMale5::
# 691 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeMale5
# 692 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 693 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 694 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 695 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 696 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 697 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 698 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 699 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 700 "data/maps/LittlerootTown/scripts.pory"
	return
# 701 "data/maps/LittlerootTown/scripts.pory"

# 702 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale2::
# 703 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
# 704 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 705 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 706 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 707 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 708 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 709 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 710 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 711 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 712 "data/maps/LittlerootTown/scripts.pory"
	return
# 713 "data/maps/LittlerootTown/scripts.pory"

# 714 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale3::
# 715 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
# 716 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 717 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 718 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 719 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 720 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 721 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 722 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 723 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 724 "data/maps/LittlerootTown/scripts.pory"
	return
# 725 "data/maps/LittlerootTown/scripts.pory"

# 726 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale4::
# 727 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
# 728 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 729 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 730 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 731 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 732 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 733 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 734 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 735 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 736 "data/maps/LittlerootTown/scripts.pory"
	return
# 737 "data/maps/LittlerootTown/scripts.pory"

# 738 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_MomReturnHomeFemale5::
# 739 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
# 740 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 741 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 742 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 743 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 744 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 745 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 746 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 747 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 748 "data/maps/LittlerootTown/scripts.pory"
	return
# 749 "data/maps/LittlerootTown/scripts.pory"

# 750 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_EmmieApproachPlayer:
# 751 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 752 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 753 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 754 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 755 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 756 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 757 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 758 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 759 "data/maps/LittlerootTown/scripts.pory"

# 760 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 761 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 762 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 763 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 764 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 765 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 766 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 767 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 768 "data/maps/LittlerootTown/scripts.pory"

# 769 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 770 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 771 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 773 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 774 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 775 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 776 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 777 "data/maps/LittlerootTown/scripts.pory"

# 778 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 779 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 780 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 781 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 782 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 783 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 784 "data/maps/LittlerootTown/scripts.pory"

# 785 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 786 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 787 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 788 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 789 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 790 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 791 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 792 "data/maps/LittlerootTown/scripts.pory"

# 793 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 794 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 795 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 796 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 797 "data/maps/LittlerootTown/scripts.pory"

# 798 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 799 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 800 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 801 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 802 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 803 "data/maps/LittlerootTown/scripts.pory"

# 804 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 805 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 806 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 807 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 808 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 809 "data/maps/LittlerootTown/scripts.pory"

# 810 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 811 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 812 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 813 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 814 "data/maps/LittlerootTown/scripts.pory"

# 815 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 816 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 817 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 818 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 819 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 820 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 821 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 822 "data/maps/LittlerootTown/scripts.pory"

# 823 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 824 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 826 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 827 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 828 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 829 "data/maps/LittlerootTown/scripts.pory"

# 830 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 831 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 832 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 833 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 834 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 835 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 836 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 837 "data/maps/LittlerootTown/scripts.pory"

# 838 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 839 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 841 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 842 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 843 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 844 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 845 "data/maps/LittlerootTown/scripts.pory"

# 846 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 847 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 848 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 849 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 850 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 851 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 852 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 853 "data/maps/LittlerootTown/scripts.pory"

# 854 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 855 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 856 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 857 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 858 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 859 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 860 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 861 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 862 "data/maps/LittlerootTown/scripts.pory"

# 863 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 864 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 865 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 866 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 867 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 868 "data/maps/LittlerootTown/scripts.pory"

# 869 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 870 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 871 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 872 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 873 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 874 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 875 "data/maps/LittlerootTown/scripts.pory"

# 876 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 877 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 878 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 879 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 880 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 881 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 882 "data/maps/LittlerootTown/scripts.pory"

# 883 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 884 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 885 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 886 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 887 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 888 "data/maps/LittlerootTown/scripts.pory"

# 889 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 890 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 891 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 892 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 893 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 894 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 895 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 896 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 897 "data/maps/LittlerootTown/scripts.pory"

# 898 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 899 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 900 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 901 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 902 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 903 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
# 904 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 905 "data/maps/LittlerootTown/scripts.pory"

# 906 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 907 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 908 "data/maps/LittlerootTown/scripts.pory"
	step_end
# 909 "data/maps/LittlerootTown/scripts.pory"

# 910 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_Mom::
# 911 "data/maps/LittlerootTown/scripts.pory"
	lock
# 912 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 913 "data/maps/LittlerootTown/scripts.pory"
	checkplayergender
# 914 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetHomeDoorCoordsMale
# 915 "data/maps/LittlerootTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetHomeDoorCoordsFemale
# 916 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 917 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterUp
# 918 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 919 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 920 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 921 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitThroughDoor
# 922 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 923 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat LOCALID_MOM, MAP_LITTLEROOT_TOWN
# 924 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 925 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 926 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
# 927 "data/maps/LittlerootTown/scripts.pory"
	end
# 928 "data/maps/LittlerootTown/scripts.pory"

# 929 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_SetReceivedRunningShoes::
# 930 "data/maps/LittlerootTown/scripts.pory"
	removeobject LOCALID_MOM
# 931 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 932 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 933 "data/maps/LittlerootTown/scripts.pory"
	release
# 934 "data/maps/LittlerootTown/scripts.pory"
	end
# 935 "data/maps/LittlerootTown/scripts.pory"

# 936 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_EventScript_GiveRunningShoes::
# 937 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 938 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 939 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 940 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 941 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 942 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 943 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_SoWillYourSister, MSGBOX_DEFAULT
# 944 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 945 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterDown
# 946 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 947 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_EmmieComeHere, MSGBOX_DEFAULT
# 948 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 949 "data/maps/LittlerootTown/scripts.pory"
	delay 30
# 950 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_EMMIE, LittlerootTown_Movement_EmmieApproachPlayer
# 951 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 952 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_EMMIE, Common_Movement_QuestionMark
# 953 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterLeft
# 954 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 955 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_EmmieWhatsGoingOn, MSGBOX_DEFAULT
# 956 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 957 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_PlayerHasAPokemon, MSGBOX_DEFAULT
# 958 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 959 "data/maps/LittlerootTown/scripts.pory"
	applymovement LOCALID_EMMIE, Common_Movement_ExclamationMark
# 960 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 961 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_EmmieHowExciting, MSGBOX_DEFAULT
# 962 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 963 "data/maps/LittlerootTown/scripts.pory"
	setfollower 9, FNPC_ALL, Common_EventScript_Emmie, PARTNER_EMMIE
# 964 "data/maps/LittlerootTown/scripts.pory"
	return
# 965 "data/maps/LittlerootTown/scripts.pory"

# 966 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_OurNewHomeLetsGoInside:
# 967 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, we're here, honey!\p"
# 968 "data/maps/LittlerootTown/scripts.pory"
	.string "It must be tiring riding with our things\n"
# 969 "data/maps/LittlerootTown/scripts.pory"
	.string "in the moving truck.\p"
# 970 "data/maps/LittlerootTown/scripts.pory"
	.string "Well, this is LITTLEROOT TOWN.\p"
# 971 "data/maps/LittlerootTown/scripts.pory"
	.string "How do you like it?\n"
# 972 "data/maps/LittlerootTown/scripts.pory"
	.string "This is our new home!\p"
# 973 "data/maps/LittlerootTown/scripts.pory"
	.string "It has a quaint feel, but it seems to be\n"
# 974 "data/maps/LittlerootTown/scripts.pory"
	.string "an easy place to live, don't you think?\p"
# 975 "data/maps/LittlerootTown/scripts.pory"
	.string "And, you get your own room, {PLAYER}!\n"
# 976 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go inside.$"
# 977 "data/maps/LittlerootTown/scripts.pory"

# 978 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WaitPlayer:
# 979 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"
# 980 "data/maps/LittlerootTown/scripts.pory"

# 981 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_WearTheseRunningShoes:
# 982 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
# 983 "data/maps/LittlerootTown/scripts.pory"
	.string "introduce yourself to PROF. BIRCH?\p"
# 984 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh! What an adorable POKéMON!\n"
# 985 "data/maps/LittlerootTown/scripts.pory"
	.string "You got it from PROF. BIRCH. How nice!\p"
# 986 "data/maps/LittlerootTown/scripts.pory"
	.string "You're your father's child, all right.\n"
# 987 "data/maps/LittlerootTown/scripts.pory"
	.string "You look good together with POKéMON!\p"
# 988 "data/maps/LittlerootTown/scripts.pory"
	.string "Here, honey! If you're going out on an\n"
# 989 "data/maps/LittlerootTown/scripts.pory"
	.string "adventure, wear these RUNNING SHOES.\p"
# 990 "data/maps/LittlerootTown/scripts.pory"
	.string "They'll put a zip in your step!$"
# 991 "data/maps/LittlerootTown/scripts.pory"

# 992 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_SwitchShoesWithRunningShoes:
# 993 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
# 994 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES.$"
# 995 "data/maps/LittlerootTown/scripts.pory"

# 996 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ExplainRunningShoes:
# 997 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
# 998 "data/maps/LittlerootTown/scripts.pory"
	.string "instructions.\p"
# 999 "data/maps/LittlerootTown/scripts.pory"
	.string "“Press the B Button while wearing these\n"
# 1000 "data/maps/LittlerootTown/scripts.pory"
	.string "RUNNING SHOES to run extra-fast!\p"
# 1001 "data/maps/LittlerootTown/scripts.pory"
	.string "“Slip on these RUNNING SHOES and race\n"
# 1002 "data/maps/LittlerootTown/scripts.pory"
	.string "in the great outdoors!”$"
# 1003 "data/maps/LittlerootTown/scripts.pory"

# 1004 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_SoWillYourSister:
# 1005 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
# 1006 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\p"
# 1007 "data/maps/LittlerootTown/scripts.pory"
	.string "To think that you have your very own\n"
# 1008 "data/maps/LittlerootTown/scripts.pory"
	.string "POKéMON now…\p"
# 1009 "data/maps/LittlerootTown/scripts.pory"
	.string "Your father will be overjoyed.\n"
# 1010 "data/maps/LittlerootTown/scripts.pory"
	.string "So will your sister!\p"
# 1011 "data/maps/LittlerootTown/scripts.pory"
	.string "She's been so excited to take you out\n"
# 1012 "data/maps/LittlerootTown/scripts.pory"
	.string "to see the world.$"
# 1013 "data/maps/LittlerootTown/scripts.pory"

# 1014 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_EmmieComeHere:
# 1015 "data/maps/LittlerootTown/scripts.pory"
	.string "Emmie! Come here dear!$"
# 1016 "data/maps/LittlerootTown/scripts.pory"

# 1017 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_EmmieWhatsGoingOn:
# 1018 "data/maps/LittlerootTown/scripts.pory"
	.string "Emmie: Mom? {PLAYER}? What's going on?$"
# 1019 "data/maps/LittlerootTown/scripts.pory"

# 1020 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayerHasAPokemon:
# 1021 "data/maps/LittlerootTown/scripts.pory"
	.string "Mom: Professor Birch has been kind\n"
# 1022 "data/maps/LittlerootTown/scripts.pory"
	.string "to give {PLAYER} a Pokémon!\p"
# 1023 "data/maps/LittlerootTown/scripts.pory"
	.string "I know you've been looking forward\n"
# 1024 "data/maps/LittlerootTown/scripts.pory"
	.string "to seeing the world together.\p"
# 1025 "data/maps/LittlerootTown/scripts.pory"
	.string "Just promise me you will look after\n"
# 1026 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}, and please be careful.\p"
# 1027 "data/maps/LittlerootTown/scripts.pory"
	.string "If anything happens, you can come home.\p"
# 1028 "data/maps/LittlerootTown/scripts.pory"
	.string "Go on, go get them, kids!$"
# 1029 "data/maps/LittlerootTown/scripts.pory"

# 1030 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_EmmieHowExciting:
# 1031 "data/maps/LittlerootTown/scripts.pory"
	.string "Emmie: Oh, how exciting! I'll keep a\n"
# 1032 "data/maps/LittlerootTown/scripts.pory"
	.string "close eye on {PLAYER}, don't worry!$"
# 1033 "data/maps/LittlerootTown/scripts.pory"

# 1034 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_EmmieLetMeExplain:
# 1035 "data/maps/LittlerootTown/scripts.pory"
	.string "Emmie: {PLAYER}, I'm so happy to that\n"
# 1036 "data/maps/LittlerootTown/scripts.pory"
	.string "we can finally go on an adventure!\p"
# 1037 "data/maps/LittlerootTown/scripts.pory"
	.string "Let me explain how things will work.\p"
# 1038 "data/maps/LittlerootTown/scripts.pory"
	.string "In the world of Pokémon we can carry\n"
# 1039 "data/maps/LittlerootTown/scripts.pory"
	.string "up to 6 Pokémon in our party.\p"
# 1040 "data/maps/LittlerootTown/scripts.pory"
	.string "When we are battling together, the first\n"
# 1041 "data/maps/LittlerootTown/scripts.pory"
	.string "3 Pokémon in our party will be used\l"
# 1042 "data/maps/LittlerootTown/scripts.pory"
	.string "by you, and the last 3 I will control.\p"
# 1043 "data/maps/LittlerootTown/scripts.pory"
	.string "I am happy to let you decide the moves\n"
# 1044 "data/maps/LittlerootTown/scripts.pory"
	.string "and items for my Pokémon.\p"
# 1045 "data/maps/LittlerootTown/scripts.pory"
	.string "When we go into battle, I will restore\n"
# 1046 "data/maps/LittlerootTown/scripts.pory"
	.string "the HP and PP of my Pokémon only.\p"
# 1047 "data/maps/LittlerootTown/scripts.pory"
	.string "The levels of my Pokémon will also\n"
# 1048 "data/maps/LittlerootTown/scripts.pory"
	.string "scale to match the current level cap.\p"
# 1049 "data/maps/LittlerootTown/scripts.pory"
	.string "I will leave any status conditions\n"
# 1050 "data/maps/LittlerootTown/scripts.pory"
	.string "afflicting my Pokémon as they are.\p"
# 1051 "data/maps/LittlerootTown/scripts.pory"
	.string "At the end of battle, I won't heal my\n"
# 1052 "data/maps/LittlerootTown/scripts.pory"
	.string "Pokémon until the next battle begins.\p"
# 1053 "data/maps/LittlerootTown/scripts.pory"
	.string "My Pokémon's levels will return to\n"
# 1054 "data/maps/LittlerootTown/scripts.pory"
	.string "their original levels at the end of\l"
# 1055 "data/maps/LittlerootTown/scripts.pory"
	.string "each battle.\p"
# 1056 "data/maps/LittlerootTown/scripts.pory"
	.string "As we are going on this journey together\n"
# 1057 "data/maps/LittlerootTown/scripts.pory"
	.string "we need to be carrying at least 4\l"
# 1058 "data/maps/LittlerootTown/scripts.pory"
	.string "Pokémon at all times.\p"
# 1059 "data/maps/LittlerootTown/scripts.pory"
	.string "Therefore, if any of our Pokémon faint\n"
# 1060 "data/maps/LittlerootTown/scripts.pory"
	.string "in battle, I will restore their HP to\l"
# 1061 "data/maps/LittlerootTown/scripts.pory"
	.string "1 when we are finished.\p"
# 1062 "data/maps/LittlerootTown/scripts.pory"
	.string "If any of my Pokémon faint in battle,\n"
# 1063 "data/maps/LittlerootTown/scripts.pory"
	.string "please don't blame yourself!\p"
# 1064 "data/maps/LittlerootTown/scripts.pory"
	.string "We work together as a team, but I am\n"
# 1065 "data/maps/LittlerootTown/scripts.pory"
	.string "making my own decisions.\p"
# 1066 "data/maps/LittlerootTown/scripts.pory"
	.string "Also, if all of your Pokémon faint but\n"
# 1067 "data/maps/LittlerootTown/scripts.pory"
	.string "I still carry us to victory, I would\l"
# 1068 "data/maps/LittlerootTown/scripts.pory"
	.string "still view this as a win for us.\p"
# 1069 "data/maps/LittlerootTown/scripts.pory"
	.string "We are a team, and in my eyes a win\n"
# 1070 "data/maps/LittlerootTown/scripts.pory"
	.string "is a win!\p"
# 1071 "data/maps/LittlerootTown/scripts.pory"
	.string "Lastly, there may be times where we\n"
# 1072 "data/maps/LittlerootTown/scripts.pory"
	.string "meet other trainers who want to\l"
# 1073 "data/maps/LittlerootTown/scripts.pory"
	.string "battle alongside you.\p"
# 1074 "data/maps/LittlerootTown/scripts.pory"
	.string "When this happens, I will stand aside\n"
# 1075 "data/maps/LittlerootTown/scripts.pory"
	.string "and you can choose which 3 of our\l"
# 1076 "data/maps/LittlerootTown/scripts.pory"
	.string "Pokémon you want to take into battle.\p"
# 1077 "data/maps/LittlerootTown/scripts.pory"
	.string "Now, as you know I already have 3\n"
# 1078 "data/maps/LittlerootTown/scripts.pory"
	.string "Pokémon of my own.\p"
# 1079 "data/maps/LittlerootTown/scripts.pory"
	.string "I'll add these to our party now, then\n"
# 1080 "data/maps/LittlerootTown/scripts.pory"
	.string "we can finally get started!$"
# 1081 "data/maps/LittlerootTown/scripts.pory"

# 1082 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanUsePCToStoreItems:
# 1083 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
# 1084 "data/maps/LittlerootTown/scripts.pory"
	.string "and POKéMON.\p"
# 1085 "data/maps/LittlerootTown/scripts.pory"
	.string "The power of science is staggering!$"
# 1086 "data/maps/LittlerootTown/scripts.pory"

# 1087 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSpendsDaysInLab:
# 1088 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
# 1089 "data/maps/LittlerootTown/scripts.pory"
	.string "studying, then he'll suddenly go out in\l"
# 1090 "data/maps/LittlerootTown/scripts.pory"
	.string "the wild to do more research…\p"
# 1091 "data/maps/LittlerootTown/scripts.pory"
	.string "When does PROF. BIRCH spend time\n"
# 1092 "data/maps/LittlerootTown/scripts.pory"
	.string "at home?$"
# 1093 "data/maps/LittlerootTown/scripts.pory"

# 1094 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
# 1095 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
# 1096 "data/maps/LittlerootTown/scripts.pory"
	.string "If you go outside and go in the grass,\n"
# 1097 "data/maps/LittlerootTown/scripts.pory"
	.string "wild POKéMON will jump out!$"
# 1098 "data/maps/LittlerootTown/scripts.pory"

# 1099 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_DangerousIfYouDontHavePokemon:
# 1100 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
# 1101 "data/maps/LittlerootTown/scripts.pory"
	.string "your own POKéMON.$"
# 1102 "data/maps/LittlerootTown/scripts.pory"

# 1103 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_CanYouGoSeeWhatsHappening:
# 1104 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
# 1105 "data/maps/LittlerootTown/scripts.pory"
	.string "There are scary POKéMON outside!\n"
# 1106 "data/maps/LittlerootTown/scripts.pory"
	.string "I can hear their cries!\p"
# 1107 "data/maps/LittlerootTown/scripts.pory"
	.string "I want to go see what's going on,\n"
# 1108 "data/maps/LittlerootTown/scripts.pory"
	.string "but I don't have any POKéMON…\p"
# 1109 "data/maps/LittlerootTown/scripts.pory"
	.string "Can you go see what's happening\n"
# 1110 "data/maps/LittlerootTown/scripts.pory"
	.string "for me?$"
# 1111 "data/maps/LittlerootTown/scripts.pory"

# 1112 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_YouSavedBirch:
# 1113 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
# 1114 "data/maps/LittlerootTown/scripts.pory"
	.string "I'm so glad!$"
# 1115 "data/maps/LittlerootTown/scripts.pory"

# 1116 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_GoodLuckCatchingPokemon:
# 1117 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
# 1118 "data/maps/LittlerootTown/scripts.pory"
	.string "Good luck!$"
# 1119 "data/maps/LittlerootTown/scripts.pory"

# 1120 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_TownSign:
# 1121 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
# 1122 "data/maps/LittlerootTown/scripts.pory"
	.string "“A town that can't be shaded any hue.”$"
# 1123 "data/maps/LittlerootTown/scripts.pory"

# 1124 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsLab:
# 1125 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"
# 1126 "data/maps/LittlerootTown/scripts.pory"

# 1127 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_PlayersHouse:
# 1128 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER}'s HOUSE$"
# 1129 "data/maps/LittlerootTown/scripts.pory"

# 1130 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_ProfBirchsHouse:
# 1131 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S HOUSE$"
# 1132 "data/maps/LittlerootTown/scripts.pory"

# 1133 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Text_BirchSomethingToShowYouAtLab:
# 1134 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
# 1135 "data/maps/LittlerootTown/scripts.pory"
	.string "That was good work out there!\p"
# 1136 "data/maps/LittlerootTown/scripts.pory"
	.string "I knew there was something special\n"
# 1137 "data/maps/LittlerootTown/scripts.pory"
	.string "about you when I first saw you,\l"
# 1138 "data/maps/LittlerootTown/scripts.pory"
	.string "but I never expected this.\p"
# 1139 "data/maps/LittlerootTown/scripts.pory"
	.string "Oh, yes. Do you still have the POKéDEX\n"
# 1140 "data/maps/LittlerootTown/scripts.pory"
	.string "I gave you?\p"
# 1141 "data/maps/LittlerootTown/scripts.pory"
	.string "I have something to show you.\n"
# 1142 "data/maps/LittlerootTown/scripts.pory"
	.string "Let's go to my LAB.$"
