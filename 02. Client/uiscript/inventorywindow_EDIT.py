# ********************************************************************** #
#Search:
				## Print
				{
					"name":"Money_Icon",
					"type":"image",
					"vertical_align":"bottom",
					
					"x":57,
					"y":26,

					"image":"d:/ymir work/ui/game/windows/money_icon.sub",
				},
				{
					"name":"Money_Slot",
					"type":"button",

					"x":75,
					"y":28,

					#"horizontal_align":"center",
					"vertical_align":"bottom",

					"default_image" : "d:/ymir work/ui/public/gold_slot.sub",
					"over_image" : "d:/ymir work/ui/public/gold_slot.sub",
					"down_image" : "d:/ymir work/ui/public/gold_slot.sub",

					"children" :
					(
						{
							"name" : "Money",
							"type" : "text",

							"x" : 3,
							"y" : 3,

							"horizontal_align" : "right",
							"text_horizontal_align" : "right",

							"text" : "123456789",
						},
					),
				},

#Add after:
				{
					"name":"Cheque_Icon",
					"type":"image",
					"vertical_align":"bottom",
					
					"x":10,
					"y":26,

					"image":"d:/ymir work/ui/game/windows/cheque_icon.sub",
				},
				{
					"name":"Cheque_Slot",
					"type":"button",

					"x":28,
					"y":28,

					#"horizontal_align":"center",
					"vertical_align":"bottom",

					"default_image" : "d:/ymir work/ui/public/cheque_slot.sub",
					"over_image" : "d:/ymir work/ui/public/cheque_slot.sub",
					"down_image" : "d:/ymir work/ui/public/cheque_slot.sub",

					"children" :
					(
						{
							"name" : "Cheque",
							"type" : "text",

							"x" : 3,
							"y" : 3,

							"horizontal_align" : "right",
							"text_horizontal_align" : "right",

							"text" : "99",
						},
					),
				},
# ********************************************************************** #