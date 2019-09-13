/*--------------------------------------------------*/
/*Search:
DWORD CPythonExchange::GetElkFromSelf()
{
	[...]
}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
void CPythonExchange::SetChequeToTarget(DWORD cheque)
{
	m_victim.cheque = cheque;
}

void CPythonExchange::SetChequeToSelf(DWORD cheque)
{
	m_self.cheque = cheque;
}

DWORD CPythonExchange::GetChequeFromTarget()
{
	return m_victim.cheque;
}

DWORD CPythonExchange::GetChequeFromSelf()
{
	return m_self.cheque;
}
#endif
/*--------------------------------------------------*/