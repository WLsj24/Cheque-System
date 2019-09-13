/*Search:
	{ "align",		NUMBER	},

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	{ "cheque",		NUMBER },
#endif
/*--------------------------------------------------*/
/*Search:
		case 8: // alignment
			{
				int	amount = 0;
				str_to_number(amount, arg3);
				tch->UpdateAlignment(amount - ch->GetRealAlignment());
			}
			break;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		case 9: // cheque
			{
				int cheque = 0;
				str_to_number(cheque, arg3);
				tch->PointChange(POINT_CHEQUE, cheque, true);
				tch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Cheque: ADD[%d] TOTAL[%d]"), cheque, tch->GetCheque());
			}
			break;
#endif
/*--------------------------------------------------*/