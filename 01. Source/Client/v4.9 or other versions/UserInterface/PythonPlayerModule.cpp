/*--------------------------------------------------*/
/*Search:
PyObject * playerGetElk(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", CPythonPlayer::Instance().GetStatus(POINT_GOLD));
}

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
PyObject * playerGetCheque(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", CPythonPlayer::Instance().GetStatus(POINT_CHEQUE));
}
#endif
/*--------------------------------------------------*/
/*Search:
		{ "GetMoney",						playerGetElk,						METH_VARARGS },

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
		{ "GetCheque",					playerGetCheque,					METH_VARARGS },
#endif
/*--------------------------------------------------*/
/*Search:
	PyModule_AddIntConstant(poModule, "ENERGY_END_TIME",		POINT_ENERGY_END_TIME);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	PyModule_AddIntConstant(poModule, "CHEQUE",			POINT_CHEQUE);
#endif
/*--------------------------------------------------*/
/*Search:
	PyModule_AddIntConstant(poModule, "ITEM_MONEY",					-1);

Add after:
*/
#ifdef ENABLE_CHEQUE_SYSTEM
	PyModule_AddIntConstant(poModule, "ITEM_CHEQUE",				-2);
#endif
/*--------------------------------------------------*/