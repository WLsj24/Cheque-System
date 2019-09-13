/*--------------------------------------------------*/
/*Search:
uint32_t CPythonExchange::GetElkFromSelf() const
{
	[...]
}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
void CPythonExchange::SetChequeToTarget(uint32_t cheque)
{
	m_victim.cheque = cheque;
}

void CPythonExchange::SetChequeToSelf(uint32_t cheque)
{
	m_self.cheque = cheque;
}

uint32_t CPythonExchange::GetChequeFromTarget() const
{
	return m_victim.cheque;
}

uint32_t CPythonExchange::GetChequeFromSelf() const
{
	return m_self.cheque;
}
#endif
/*--------------------------------------------------*/