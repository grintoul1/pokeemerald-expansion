# 1 "data/maps/Route121/scripts.pory"

# 2 "data/maps/Route121/scripts.pory"
.set LOCALID_GRUNT_1, 12
# 3 "data/maps/Route121/scripts.pory"
.set LOCALID_GRUNT_2, 13
# 4 "data/maps/Route121/scripts.pory"
.set LOCALID_GRUNT_3, 14
# 5 "data/maps/Route121/scripts.pory"

# 6 "data/maps/Route121/scripts.pory"
Route121_MapScripts::
# 7 "data/maps/Route121/scripts.pory"
	.byte 0
# 8 "data/maps/Route121/scripts.pory"

# 9 "data/maps/Route121/scripts.pory"
Route121_EventScript_Woman::
# 10 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_AheadLoomsMtPyre, MSGBOX_NPC
# 11 "data/maps/Route121/scripts.pory"
	end
# 12 "data/maps/Route121/scripts.pory"

# 13 "data/maps/Route121/scripts.pory"
Route121_EventScript_MtPyrePierSign::
# 14 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MtPyrePierSign, MSGBOX_SIGN
# 15 "data/maps/Route121/scripts.pory"
	end
# 16 "data/maps/Route121/scripts.pory"

# 17 "data/maps/Route121/scripts.pory"
Route121_EventScript_SafariZoneSign::
# 18 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_SafariZoneSign, MSGBOX_SIGN
# 19 "data/maps/Route121/scripts.pory"
	end
# 20 "data/maps/Route121/scripts.pory"

# 21 "data/maps/Route121/scripts.pory"
Route121_EventScript_AquaGruntsMoveOut::
# 22 "data/maps/Route121/scripts.pory"
	lockall
# 23 "data/maps/Route121/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 24 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceRight
# 25 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 26 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_OkayMoveOutToMtPyre, MSGBOX_DEFAULT
# 27 "data/maps/Route121/scripts.pory"
	closemessage
# 28 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_1, Route121_Movement_Grunt1Exit
# 29 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_2, Route121_Movement_Grunt2Exit
# 30 "data/maps/Route121/scripts.pory"
	applymovement LOCALID_GRUNT_3, Route121_Movement_Grunt3Exit
# 31 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 32 "data/maps/Route121/scripts.pory"
	fadedefaultbgm
# 33 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 34 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 35 "data/maps/Route121/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 36 "data/maps/Route121/scripts.pory"
	setvar VAR_ROUTE121_STATE, 1
# 37 "data/maps/Route121/scripts.pory"
	releaseall
# 38 "data/maps/Route121/scripts.pory"
	end
# 39 "data/maps/Route121/scripts.pory"

# 40 "data/maps/Route121/scripts.pory"
Route121_EventScript_AquaGrunt1::
# 41 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_AquaGrunt1, MSGBOX_DEFAULT
# 42 "data/maps/Route121/scripts.pory"
	closemessage
# 43 "data/maps/Route121/scripts.pory"
	end
# 44 "data/maps/Route121/scripts.pory"

# 45 "data/maps/Route121/scripts.pory"
Route121_EventScript_AquaGrunt2::
# 46 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_AquaGrunt2, MSGBOX_DEFAULT
# 47 "data/maps/Route121/scripts.pory"
	closemessage
# 48 "data/maps/Route121/scripts.pory"
	end
# 49 "data/maps/Route121/scripts.pory"

# 50 "data/maps/Route121/scripts.pory"
Route121_EventScript_AquaGrunt3::
# 51 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_AquaGrunt3, MSGBOX_DEFAULT
# 52 "data/maps/Route121/scripts.pory"
	closemessage
# 53 "data/maps/Route121/scripts.pory"
	end
# 54 "data/maps/Route121/scripts.pory"

# 55 "data/maps/Route121/scripts.pory"
Route121_EventScript_MagmaGrunt1::
# 56 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MagmaGrunt1, MSGBOX_DEFAULT
# 57 "data/maps/Route121/scripts.pory"
	closemessage
# 58 "data/maps/Route121/scripts.pory"
	end
# 59 "data/maps/Route121/scripts.pory"

# 60 "data/maps/Route121/scripts.pory"
Route121_EventScript_MagmaGrunt2::
# 61 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MagmaGrunt2, MSGBOX_DEFAULT
# 62 "data/maps/Route121/scripts.pory"
	closemessage
# 63 "data/maps/Route121/scripts.pory"
	end
# 64 "data/maps/Route121/scripts.pory"

# 65 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt1Exit:
# 66 "data/maps/Route121/scripts.pory"
	walk_down
# 67 "data/maps/Route121/scripts.pory"
	walk_down
# 68 "data/maps/Route121/scripts.pory"
	walk_down
# 69 "data/maps/Route121/scripts.pory"
	walk_down
# 70 "data/maps/Route121/scripts.pory"
	walk_down
# 71 "data/maps/Route121/scripts.pory"
	walk_down
# 72 "data/maps/Route121/scripts.pory"
	walk_down
# 73 "data/maps/Route121/scripts.pory"
	walk_down
# 74 "data/maps/Route121/scripts.pory"
	step_end
# 75 "data/maps/Route121/scripts.pory"

# 76 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt2Exit:
# 77 "data/maps/Route121/scripts.pory"
	walk_down
# 78 "data/maps/Route121/scripts.pory"
	walk_down
# 79 "data/maps/Route121/scripts.pory"
	walk_down
# 80 "data/maps/Route121/scripts.pory"
	walk_down
# 81 "data/maps/Route121/scripts.pory"
	walk_down
# 82 "data/maps/Route121/scripts.pory"
	walk_down
# 83 "data/maps/Route121/scripts.pory"
	walk_down
# 84 "data/maps/Route121/scripts.pory"
	walk_down
# 85 "data/maps/Route121/scripts.pory"
	step_end
# 86 "data/maps/Route121/scripts.pory"

# 87 "data/maps/Route121/scripts.pory"
Route121_Movement_Grunt3Exit:
# 88 "data/maps/Route121/scripts.pory"
	walk_down
# 89 "data/maps/Route121/scripts.pory"
	walk_down
# 90 "data/maps/Route121/scripts.pory"
	walk_down
# 91 "data/maps/Route121/scripts.pory"
	walk_down
# 92 "data/maps/Route121/scripts.pory"
	walk_down
# 93 "data/maps/Route121/scripts.pory"
	walk_down
# 94 "data/maps/Route121/scripts.pory"
	walk_down
# 95 "data/maps/Route121/scripts.pory"
	walk_down
# 96 "data/maps/Route121/scripts.pory"
	step_end
# 97 "data/maps/Route121/scripts.pory"

# 98 "data/maps/Route121/scripts.pory"
Route121_EventScript_Vanessa::
# 99 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_VANESSA, Route121_Text_VanessaIntro, Route121_Text_VanessaDefeat
# 100 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_VanessaPostBattle, MSGBOX_AUTOCLOSE
# 101 "data/maps/Route121/scripts.pory"
	end
# 102 "data/maps/Route121/scripts.pory"

# 103 "data/maps/Route121/scripts.pory"
Route121_EventScript_Walter::
# 104 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_WALTER_1, Route121_Text_WalterIntro, Route121_Text_WalterDefeat, Route121_EventScript_RegisterWalter
# 105 "data/maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 106 "data/maps/Route121/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchWalter
# 107 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterPostBattle, MSGBOX_DEFAULT
# 108 "data/maps/Route121/scripts.pory"
	release
# 109 "data/maps/Route121/scripts.pory"
	end
# 110 "data/maps/Route121/scripts.pory"

# 111 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterWalter::
# 112 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 113 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 114 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterRegister, MSGBOX_DEFAULT
# 115 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_WALTER_1
# 116 "data/maps/Route121/scripts.pory"
	release
# 117 "data/maps/Route121/scripts.pory"
	end
# 118 "data/maps/Route121/scripts.pory"

# 119 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchWalter::
# 120 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_WALTER_1, Route121_Text_WalterRematchIntro, Route121_Text_WalterRematchDefeat
# 121 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterPostRematch, MSGBOX_AUTOCLOSE
# 122 "data/maps/Route121/scripts.pory"
	end
# 123 "data/maps/Route121/scripts.pory"

# 124 "data/maps/Route121/scripts.pory"
Route121_EventScript_Tammy::
# 125 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_TAMMY, Route121_Text_TammyIntro, Route121_Text_TammyDefeat
# 126 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
# 127 "data/maps/Route121/scripts.pory"
	end
# 128 "data/maps/Route121/scripts.pory"

# 129 "data/maps/Route121/scripts.pory"
Route121_EventScript_Kate::
# 130 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_KateIntro, Route121_Text_KateDefeat, Route121_Text_KateNotEnoughMons
# 131 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
# 132 "data/maps/Route121/scripts.pory"
	end
# 133 "data/maps/Route121/scripts.pory"

# 134 "data/maps/Route121/scripts.pory"
Route121_EventScript_Joy::
# 135 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_JoyIntro, Route121_Text_JoyDefeat, Route121_Text_JoyNotEnoughMons
# 136 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
# 137 "data/maps/Route121/scripts.pory"
	end
# 138 "data/maps/Route121/scripts.pory"

# 139 "data/maps/Route121/scripts.pory"
Route121_EventScript_Jessica::
# 140 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_JESSICA_1, Route121_Text_JessicaIntro, Route121_Text_JessicaDefeat, Route121_EventScript_RegisterJessica
# 141 "data/maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 142 "data/maps/Route121/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchJessica
# 143 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaPostBattle, MSGBOX_DEFAULT
# 144 "data/maps/Route121/scripts.pory"
	release
# 145 "data/maps/Route121/scripts.pory"
	end
# 146 "data/maps/Route121/scripts.pory"

# 147 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterJessica::
# 148 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 149 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 150 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaRegister, MSGBOX_DEFAULT
# 151 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_JESSICA_1
# 152 "data/maps/Route121/scripts.pory"
	release
# 153 "data/maps/Route121/scripts.pory"
	end
# 154 "data/maps/Route121/scripts.pory"

# 155 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchJessica::
# 156 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_JESSICA_1, Route121_Text_JessicaRematchIntro, Route121_Text_JessicaRematchDefeat
# 157 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaPostRematch, MSGBOX_AUTOCLOSE
# 158 "data/maps/Route121/scripts.pory"
	end
# 159 "data/maps/Route121/scripts.pory"

# 160 "data/maps/Route121/scripts.pory"
Route121_EventScript_Cale::
# 161 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_CALE, Route121_Text_CaleIntro, Route121_Text_CaleDefeat
# 162 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CalePostBattle, MSGBOX_AUTOCLOSE
# 163 "data/maps/Route121/scripts.pory"
	end
# 164 "data/maps/Route121/scripts.pory"

# 165 "data/maps/Route121/scripts.pory"
Route121_EventScript_Myles::
# 166 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_MYLES, Route121_Text_MylesIntro, Route121_Text_MylesDefeat
# 167 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
# 168 "data/maps/Route121/scripts.pory"
	end
# 169 "data/maps/Route121/scripts.pory"

# 170 "data/maps/Route121/scripts.pory"
Route121_EventScript_Pat::
# 171 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_PAT, Route121_Text_PatIntro, Route121_Text_PatDefeat
# 172 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_PatPostBattle, MSGBOX_AUTOCLOSE
# 173 "data/maps/Route121/scripts.pory"
	end
# 174 "data/maps/Route121/scripts.pory"

# 175 "data/maps/Route121/scripts.pory"
Route121_EventScript_Marcel::
# 176 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_MARCEL, Route121_Text_MarcelIntro, Route121_Text_MarcelDefeat
# 177 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
# 178 "data/maps/Route121/scripts.pory"
	end
# 179 "data/maps/Route121/scripts.pory"

# 180 "data/maps/Route121/scripts.pory"
Route121_EventScript_Cristin::
# 181 "data/maps/Route121/scripts.pory"
	trainerbattle_single TRAINER_CRISTIN_1, Route121_Text_CristinIntro, Route121_Text_CristinDefeat, Route121_EventScript_RegisterCristin
# 182 "data/maps/Route121/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 183 "data/maps/Route121/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchCristin
# 184 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinPostBattle, MSGBOX_DEFAULT
# 185 "data/maps/Route121/scripts.pory"
	release
# 186 "data/maps/Route121/scripts.pory"
	end
# 187 "data/maps/Route121/scripts.pory"

# 188 "data/maps/Route121/scripts.pory"
Route121_EventScript_RegisterCristin::
# 189 "data/maps/Route121/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 190 "data/maps/Route121/scripts.pory"
	waitmovement 0
# 191 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinRegister, MSGBOX_DEFAULT
# 192 "data/maps/Route121/scripts.pory"
	register_matchcall TRAINER_CRISTIN_1
# 193 "data/maps/Route121/scripts.pory"
	release
# 194 "data/maps/Route121/scripts.pory"
	end
# 195 "data/maps/Route121/scripts.pory"

# 196 "data/maps/Route121/scripts.pory"
Route121_EventScript_RematchCristin::
# 197 "data/maps/Route121/scripts.pory"
	trainerbattle_rematch TRAINER_CRISTIN_1, Route121_Text_CristinRematchIntro, Route121_Text_CristinRematchDefeat
# 198 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinPostRematch, MSGBOX_AUTOCLOSE
# 199 "data/maps/Route121/scripts.pory"
	end
# 200 "data/maps/Route121/scripts.pory"

# 201 "data/maps/Route121/scripts.pory"
Route121_Text_OkayMoveOutToMtPyre:
# 202 "data/maps/Route121/scripts.pory"
	.string "Okay!\n"
# 203 "data/maps/Route121/scripts.pory"
	.string "We're to move out to MT. PYRE!$"
# 204 "data/maps/Route121/scripts.pory"

# 205 "data/maps/Route121/scripts.pory"
Route121_Text_AheadLoomsMtPyre:
# 206 "data/maps/Route121/scripts.pory"
	.string "Ahead looms MT. PYRE…\p"
# 207 "data/maps/Route121/scripts.pory"
	.string "It is a natural monument to the spirits \n"
# 208 "data/maps/Route121/scripts.pory"
	.string "of departed POKéMON…$"
# 209 "data/maps/Route121/scripts.pory"

# 210 "data/maps/Route121/scripts.pory"
Route121_Text_MtPyrePierSign:
# 211 "data/maps/Route121/scripts.pory"
	.string "MT. PYRE PIER\p"
# 212 "data/maps/Route121/scripts.pory"
	.string "…The sign is old and worn out.\n"
# 213 "data/maps/Route121/scripts.pory"
	.string "The words are barely legible…$"
# 214 "data/maps/Route121/scripts.pory"

# 215 "data/maps/Route121/scripts.pory"
Route121_Text_SafariZoneSign:
# 216 "data/maps/Route121/scripts.pory"
	.string "“Filled with rare POKéMON!”\n"
# 217 "data/maps/Route121/scripts.pory"
	.string "SAFARI ZONE$"
# 218 "data/maps/Route121/scripts.pory"

# 219 "data/maps/Route121/scripts.pory"
Route121_Text_AquaGrunt1:
# 220 "data/maps/Route121/scripts.pory"
	.string "Beat it kid!$"
# 221 "data/maps/Route121/scripts.pory"

# 222 "data/maps/Route121/scripts.pory"
Route121_Text_AquaGrunt2:
# 223 "data/maps/Route121/scripts.pory"
	.string "Team Aqua control this area!$"
# 224 "data/maps/Route121/scripts.pory"

# 225 "data/maps/Route121/scripts.pory"
Route121_Text_AquaGrunt3:
# 226 "data/maps/Route121/scripts.pory"
	.string "We're standing guard until the boss\n"
# 227 "data/maps/Route121/scripts.pory"
	.string "tells us to stand down!$"
# 228 "data/maps/Route121/scripts.pory"

# 229 "data/maps/Route121/scripts.pory"
Route121_Text_MagmaGrunt1:
# 230 "data/maps/Route121/scripts.pory"
	.string "Team Magma have this area under control!$"
# 231 "data/maps/Route121/scripts.pory"

# 232 "data/maps/Route121/scripts.pory"
Route121_Text_MagmaGrunt2:
# 233 "data/maps/Route121/scripts.pory"
	.string "Nobody goes through this area while\n"
# 234 "data/maps/Route121/scripts.pory"
	.string "Team Magma operate in Mt. Pyre!$"
