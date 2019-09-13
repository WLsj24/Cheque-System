/*--------------------------------------------------*/
/*Search in:
void CInputMain::ItemDrop(LPCHARACTER ch, const char * data)

This:
	if (pinfo->gold > 0)
		ch->DropGold(pinfo->gold);
	else
		ch->DropItem(pinfo->Cell);

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	if (pinfo->gold >0 && pinfo->cheque >0)
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't do it."));
	else if (pinfo->cheque > 0)
		ch->DropCheque(pinfo->cheque);
	else if (pinfo->gold > 0)
		ch->DropGold(pinfo->gold);
	else
		ch->DropItem(pinfo->Cell);
#else
	// 엘크가 0보다 크면 엘크를 버리는 것 이다.
	if (pinfo->gold > 0)
		ch->DropGold(pinfo->gold);
	else
		ch->DropItem(pinfo->Cell);
#endif
/*--------------------------------------------------*/
/*Search in:
void CInputMain::ItemDrop2(LPCHARACTER ch, const char * data)

This:
	if (pinfo->gold > 0)
		ch->DropGold(pinfo->gold);
	else
		ch->DropItem(pinfo->Cell, pinfo->count);

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	if (pinfo->gold >0 && pinfo->cheque >0)
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't do it."));
	else if (pinfo->cheque > 0)
		ch->DropCheque(pinfo->cheque);
	else if (pinfo->gold > 0)
		ch->DropGold(pinfo->gold);
	else
		ch->DropItem(pinfo->Cell);
#else
	if (pinfo->gold > 0)
		ch->DropGold(pinfo->gold);
	else
		ch->DropItem(pinfo->Cell, pinfo->count);
#endif
/*--------------------------------------------------*/
/*Search:
		case EXCHANGE_SUBHEADER_CG_ELK_ADD:	// arg1 == amount of gold
			[...]
			break;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		case EXCHANGE_SUBHEADER_CG_CHEQUE_ADD:	// arg1 == amount of cheque
			if (ch->GetExchange())
			{
				const int64_t nTotalCheque = static_cast<int64_t>(ch->GetExchange()->GetCompany()->GetOwner()->GetCheque()) + static_cast<int64_t>(pinfo->arg1);

				if (CHEQUE_MAX <= nTotalCheque)
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can't trade because the other character exceeds 999 won."));

					sys_err("[OVERFLOW_CHEQUE] CHEQUE_ADD (%u) id %u name %s ",
						ch->GetExchange()->GetCompany()->GetOwner()->GetCheque(),
						ch->GetExchange()->GetCompany()->GetOwner()->GetPlayerID(),
						ch->GetExchange()->GetCompany()->GetOwner()->GetName());

					return;
				}

				if (ch->GetExchange()->GetCompany()->GetAcceptStatus() != true)
					ch->GetExchange()->AddCheque(pinfo->arg1);
			}
			break;
#endif
/*--------------------------------------------------*/