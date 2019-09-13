/*Search:
namespace DoSetTypes{
typedef enum do_set_types_s {GOLD, RACE, SEX, JOB, EXP, MAX_HP, MAX_SP, SKILL, ALIGNMENT, ALIGN} do_set_types_t;
}

Replace with:
*/
namespace DoSetTypes
{
	typedef enum do_set_types_s
	{
		GOLD, RACE, SEX, JOB, EXP, MAX_HP, MAX_SP, SKILL, ALIGNMENT, ALIGN
#ifdef ENABLE_CHEQUE_SYSTEM
		, CHEQUE
#endif
	} do_set_types_t;
}
/*--------------------------------------------------*/
/*Search:
	{ "align",		NUMBER,	NULL	},

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	{ "cheque",		NUMBER,	NULL	},
#endif
/*--------------------------------------------------*/
/*Search:
		case DoSetTypes::ALIGNMENT: // alignment
			{
				int	amount = 0;
				str_to_number(amount, arg3);
				tch->UpdateAlignment(amount - ch->GetRealAlignment());
			}
			break;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		case DoSetTypes::CHEQUE: // cheque
			{
				int cheque = 0;
				str_to_number(cheque, arg3);
				tch->PointChange(POINT_CHEQUE, cheque, true);
				tch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Cheque: ADD[%d] TOTAL[%d]"), cheque, tch->GetCheque());
			}
			break;
#endif
/*--------------------------------------------------*/