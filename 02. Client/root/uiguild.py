# ********************************************************************** #
#Add this import:
if app.ENABLE_CHEQUE_SYSTEM:
	import uiPickETC
# ********************************************************************** #
#Search:
		self.offerDialog = uiPickMoney.PickMoneyDialog()

#Replace with:
		if app.ENABLE_CHEQUE_SYSTEM:
			self.offerDialog = uiPickETC.PickETCDialog()
		else:
			self.offerDialog = uiPickMoney.PickMoneyDialog()
# ********************************************************************** #
#Search:
		pickDialog = uiPickMoney.PickMoneyDialog()

#Replace with:
		if app.ENABLE_CHEQUE_SYSTEM:
			pickDialog = uiPickETC.PickETCDialog()
		else:
			pickDialog = uiPickMoney.PickMoneyDialog()
# ********************************************************************** #