# ********************************************************************** #
#Search:
		self.OwnerMoneyButton.SetEvent(ui.__mem_func__(self.OpenPickMoneyDialog))

#Add after:
		if app.ENABLE_CHEQUE_SYSTEM:
			self.OwnerChequeIcon = self.GetChild("Owner_Cheque_Icon")
			self.OwnerCheque = self.GetChild("Owner_Cheque_Value")
			self.OwnerChequeButton = self.GetChild("Owner_Cheque")
			self.OwnerChequeButton.SetEvent(ui.__mem_func__(self.OpenPickChequeDialog))
# ********************************************************************** #
#Search:
		self.TargetMoney = self.GetChild("Target_Money_Value")

#Add after:
		if app.ENABLE_CHEQUE_SYSTEM:
			self.TargetCheque = self.GetChild("Target_Cheque_Value")
			self.TargetChequeIcon = self.GetChild("Target_Cheque_Icon")
# ********************************************************************** #
#Search:
		dlgPickMoney.SetMax(7)

#Add after:
		if app.ENABLE_CHEQUE_SYSTEM:
			dlgPickMoney.SetMaxCheque(3)
# ********************************************************************** #
#Search:
		self.OwnerMoneyButton = 0

#Add after:
		if app.ENABLE_CHEQUE_SYSTEM:
			self.OwnerChequeIcon = 0
# ********************************************************************** #
#Search:
		self.dlgPickMoney.Open(player.GetElk())

#Replace with:
		if app.ENABLE_CHEQUE_SYSTEM:
			self.dlgPickMoney.Open(player.GetElk(),player.GetCheque())
			self.dlgPickMoney.SetFocus(0)
		else:
			self.dlgPickMoney.Open(player.GetElk())
# ********************************************************************** #
#Search:
	def OnPickMoney(self, money):
		net.SendExchangeElkAddPacket(money)

#Replace with:
	if app.ENABLE_CHEQUE_SYSTEM:
		def OpenPickChequeDialog(self):
			if exchange.GetChequeFromSelf() > 0:
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.EXCHANGE_CANT_EDIT_MONEY)
				return
			self.dlgPickMoney.Open(player.GetElk(),player.GetCheque())
			self.dlgPickMoney.SetFocus(1)

		def OnPickMoney(self, money, cheque):
			if exchange.GetChequeFromSelf() <=0:
				net.SendExchangeChequeAddPacket(cheque)
			if exchange.GetElkFromSelf() <= 0:
				net.SendExchangeElkAddPacket(money)
	else:
		def OnPickMoney(self, money):
			net.SendExchangeElkAddPacket(money)
# ********************************************************************** #
#Search:
		self.OwnerMoney.SetText(str(exchange.GetElkFromSelf()))
		self.TargetMoney.SetText(str(exchange.GetElkFromTarget()))

#Replace with:
		if app.ENABLE_CHEQUE_SYSTEM:
			self.OwnerMoney.SetText(localeInfo.NumberToGoldNotText(exchange.GetElkFromSelf()))
			self.TargetMoney.SetText(localeInfo.NumberToGoldNotText(exchange.GetElkFromTarget()))

			self.OwnerCheque.SetText(str(exchange.GetChequeFromSelf()))
			self.TargetCheque.SetText(str(exchange.GetChequeFromTarget()))
		else:
			self.OwnerMoney.SetText(str(exchange.GetElkFromSelf()))
			self.TargetMoney.SetText(str(exchange.GetElkFromTarget()))
# ********************************************************************** #