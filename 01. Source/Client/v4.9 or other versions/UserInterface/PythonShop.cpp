/*--------------------------------------------------*/
/*Search:
void CPythonShop::AddPrivateShopItemStock(TItemPos ItemPos, BYTE dwDisplayPos, DWORD dwPrice)

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
void CPythonShop::AddPrivateShopItemStock(TItemPos ItemPos, BYTE dwDisplayPos, DWORD dwPrice, DWORD dwCheque)
#else
void CPythonShop::AddPrivateShopItemStock(TItemPos ItemPos, BYTE dwDisplayPos, DWORD dwPrice)
#endif
/*--------------------------------------------------*/
/*Search:
	SellingItem.price = dwPrice;

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	SellingItem.cheque = dwCheque;
#endif
/*--------------------------------------------------*/
/*Search:
int CPythonShop::GetPrivateShopItemPrice(TItemPos ItemPos)
{
	[...]
}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
int CPythonShop::GetPrivateShopItemCheque(TItemPos ItemPos)
{
	TPrivateShopItemStock::iterator itor = m_PrivateShopItemStock.find(ItemPos);

	if (m_PrivateShopItemStock.end() == itor)
		return 0;

	TShopItemTable & rShopItemTable = itor->second;
	return rShopItemTable.cheque;
}
#endif
/*--------------------------------------------------*/
/*Search:
PyObject * shopGetItemPrice(PyObject * poSelf, PyObject * poArgs)
{
	[...]
}


Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
PyObject * shopGetItemCheque(PyObject * poSelf, PyObject * poArgs)
{
	int iIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iIndex))
		return Py_BuildException();

	const TShopItemData * c_pItemData;
	if (CPythonShop::Instance().GetItemData(iIndex, &c_pItemData))
		return Py_BuildValue("i", c_pItemData->cheque);

	return Py_BuildValue("i", 0);
}
#endif
/*--------------------------------------------------*/
/*Search:
	CPythonShop::Instance().AddPrivateShopItemStock(TItemPos(bItemWindowType, wItemSlotIndex), iDisplaySlotIndex, iPrice);

Replace with:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	int iCheque;
	if (!PyTuple_GetInteger(poArgs, 4, &iCheque))
		return Py_BuildException();
#endif

#ifdef ENABLE_CHEQUE_SYSTEM
	CPythonShop::Instance().AddPrivateShopItemStock(TItemPos(bItemWindowType, wItemSlotIndex), iDisplaySlotIndex, iPrice, iCheque);
#else
	CPythonShop::Instance().AddPrivateShopItemStock(TItemPos(bItemWindowType, wItemSlotIndex), iDisplaySlotIndex, iPrice);
#endif
/*--------------------------------------------------*/
/*Search:
PyObject * shopGetPrivateShopItemPrice(PyObject * poSelf, PyObject * poArgs)
{
	[...]
}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
PyObject * shopGetPrivateShopItemCheque(PyObject * poSelf, PyObject * poArgs)
{
	BYTE bItemWindowType;
	if (!PyTuple_GetInteger(poArgs, 0, &bItemWindowType))
		return Py_BuildException();
	WORD wItemSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 1, &wItemSlotIndex))
		return Py_BuildException();

	int iValue = CPythonShop::Instance().GetPrivateShopItemCheque(TItemPos(bItemWindowType, wItemSlotIndex));
	return Py_BuildValue("i", iValue);
}
#endif
/*--------------------------------------------------*/
/*Search:
		{ "GetItemCount",				shopGetItemCount,				METH_VARARGS },

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		{ "GetItemCheque",				shopGetItemCheque,				METH_VARARGS },
#endif
/*--------------------------------------------------*/
/*Search:
		{ "GetPrivateShopItemPrice",	shopGetPrivateShopItemPrice,	METH_VARARGS },

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		{ "GetPrivateShopItemCheque",	shopGetPrivateShopItemCheque,	METH_VARARGS },
#endif
/*--------------------------------------------------*/