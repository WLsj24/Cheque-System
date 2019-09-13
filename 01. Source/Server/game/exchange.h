/*--------------------------------------------------*/
/*Search:
		bool		AddGold(long lGold);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		bool		AddCheque(long Cheque);
#endif
/*--------------------------------------------------*/
/*Search:
		long		m_lGold;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		DWORD		m_lCheque;
#endif
/*--------------------------------------------------*/