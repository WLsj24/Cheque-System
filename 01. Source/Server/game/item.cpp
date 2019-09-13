/*--------------------------------------------------*/
/*Search:
	if (GetType() == ITEM_ELK) return MIN(m_dwCount, INT_MAX);

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	if (GetType() == ITEM_ELK || GetType() == ITEM_CHEQUE) return MIN(m_dwCount, INT_MAX);
#else
	if (GetType() == ITEM_ELK) return MIN(m_dwCount, INT_MAX);
#endif
/*--------------------------------------------------*/
/*Search:
	if (GetType() == ITEM_ELK)

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	if (GetType() == ITEM_ELK || GetType() == ITEM_CHEQUE)
#else
	if (GetType() == ITEM_ELK)
#endif
/*--------------------------------------------------*/