/*--------------------------------------------------*/
/*Search:
	m_lGold = 0;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	m_lCheque = 0;
#endif
/*--------------------------------------------------*/
/*Search:
bool CExchange::AddGold(long gold)
{
	[...]
}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
bool CExchange::AddCheque(long cheque)
{
	if (cheque <= 0)
		return false;
	if (GetOwner()->GetCheque() < cheque)
	{
		exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_LESS_CHEQUE, 0, 0, NPOS, 0);
		return false;
	}
	Accept(false);
	GetCompany()->Accept(false);
	m_lCheque = cheque;
	exchange_packet(GetOwner(), EXCHANGE_SUBHEADER_GC_CHEQUE_ADD, true, m_lCheque, NPOS, 0);
	exchange_packet(GetCompany()->GetOwner(), EXCHANGE_SUBHEADER_GC_CHEQUE_ADD, false, m_lCheque, NPOS, 0);
	return true;
}
#endif
/*--------------------------------------------------*/
/*Search:
	if (GetOwner()->GetGold() < m_lGold)
		return false;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	if (GetOwner()->GetCheque() < (int)m_lCheque)
		return false;
#endif
/*--------------------------------------------------*/
/*Search in bool CExchange::Done():
	if (m_lGold)
	{
		[...]
	}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	if (m_lCheque)
	{
		GetOwner()->PointChange(POINT_CHEQUE, -m_lCheque, true);
		victim->PointChange(POINT_CHEQUE, m_lCheque, true);
	}
#endif
/*--------------------------------------------------*/
/*Search in bool CExchange::Accept(bool bAccept):
			if (m_lGold) // 돈이 있을 만 저장
				GetOwner()->Save();

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
			if (m_lCheque)
				GetOwner()->Save();
#endif
/*--------------------------------------------------*/
/*Search in bool CExchange::Accept(bool bAccept):
				if (GetCompany()->m_lGold) // 돈이 있을 때만 저장
					victim->Save();

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
				if (GetCompany()->m_lCheque)
					victim->Save();
#endif
/*--------------------------------------------------*/