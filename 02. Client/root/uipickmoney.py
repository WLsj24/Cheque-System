# ********************************************************************** #
#Search in:
	def __init__(self):

#This:
		self.eventAccept = 0

#Add after:
		if app.ENABLE_CHEQUE_SYSTEM:
			self.chequeMaxValue = 0
# ********************************************************************** #
#Search:
			self.cancelButton = self.GetChild("cancel_button")

#Add after:
			if app.ENABLE_CHEQUE_SYSTEM:
				self.maxChequeValueTextLine = self.GetChild("cheque_max_value")
				self.pickChequeValueEditLine = self.GetChild("cheque_value")
				self.pickChequeValueEditLine.OnMouseLeftButtonDown = ui.__mem_func__(self.__ClickChequeEditLine)
				self.pickValueEditLine.OnMouseLeftButtonDown = ui.__mem_func__(self.__ClickValueEditLine)
# ********************************************************************** #
#Search:
		self.board = None

#Add after:
		if app.ENABLE_CHEQUE_SYSTEM:
			self.chequeMaxValue = 0
# ********************************************************************** #
#Search:
	def Open(self, maxValue, unitValue=1):
		[...]

#Replace with:
	if app.ENABLE_CHEQUE_SYSTEM:
		def SetMaxCheque(self, max):
			self.pickChequeValueEditLine.SetMax(max)

		def SetFocus(self, focus_idx) :
			if focus_idx == 1:
				self.pickChequeValueEditLine.SetText("")
				self.pickChequeValueEditLine.SetFocus()
				self.pickValueEditLine.SetText(str(0))
			else :
				return
		
		def __ClickChequeEditLine(self) :
			self.pickChequeValueEditLine.SetFocus()
			if len(self.pickValueEditLine.GetText()) <= 0:
				self.pickValueEditLine.SetText(str(0))

		def __ClickValueEditLine(self) :
			self.pickValueEditLine.SetFocus()
			if len(self.pickChequeValueEditLine.GetText()) <= 0:
				self.pickChequeValueEditLine.SetText(str(0))

		def Open(self, maxValue, chequeMaxValue = 0):

			width = self.GetWidth()
			(mouseX, mouseY) = wndMgr.GetMousePosition()

			if mouseX + width/2 > wndMgr.GetScreenWidth():
				xPos = wndMgr.GetScreenWidth() - width
			elif mouseX - width/2 < 0:
				xPos = 0
			else:
				xPos = mouseX - width/2

			self.SetPosition(xPos, mouseY - self.GetHeight() - 20)

			if localeInfo.IsARABIC():
				self.maxValueTextLine.SetText("/" + str(maxValue))
				self.maxChequeValueTextLine.SetText("/" + str(chequeMaxValue))
			else:
				self.maxValueTextLine.SetText(" / " + str(maxValue))
				self.maxChequeValueTextLine.SetText(" / " + str(chequeMaxValue))
			
			self.pickChequeValueEditLine.SetText(str(0))
			
			self.pickValueEditLine.SetText("")
			self.pickValueEditLine.SetFocus()

			ime.SetCursorPosition(1)

			self.chequeMaxValue = chequeMaxValue
			self.maxValue = maxValue
			self.Show()
			self.SetTop()
	else:
		def Open(self, maxValue, unitValue=1):
			[...]
# ********************************************************************** #
#Search:
		self.pickValueEditLine.KillFocus()

#Add after:
		if app.ENABLE_CHEQUE_SYSTEM:
			self.pickChequeValueEditLine.KillFocus()
# ********************************************************************** #
#Search:
	def OnAccept(self):
		[...]

#Replace with:
	if app.ENABLE_CHEQUE_SYSTEM :
		def OnAccept(self):
			cheque_text	= self.pickChequeValueEditLine.GetText()
			money_text	= self.pickValueEditLine.GetText()

			if len(cheque_text) > 0 and cheque_text.isdigit() \
				 and len(money_text) > 0 and money_text.isdigit():
				cheque = int(cheque_text)
				cheque = min(cheque, self.chequeMaxValue)
				money = int(money_text)
				money = min(money, self.maxValue)

				if cheque > 0 or money > 0 :
					if self.eventAccept:
						self.eventAccept(money, cheque)
			self.Close()
	else :
		def OnAccept(self):
			[...]
# ********************************************************************** #