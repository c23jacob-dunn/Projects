from menu import Menu, MenuItem
from coffee_maker import CoffeeMaker
from money_machine import MoneyMachine

menu = Menu()
make_coffee = CoffeeMaker()
register = MoneyMachine()

machine_on = True

while machine_on:
    selection = input("What would you like? (espresso/latte/cappuccino): ")
    menu_item = Menu.find_drink(menu, selection)
    if selection == "off":
        machine_on = False
        print("Powering off, Goodbye")
    elif selection == "report":
        print(make_coffee.report())
    elif menu_item != "None":
        make_coffee.is_resource_sufficient(menu_item)
        if register.make_payment(menu_item.cost):
            make_coffee.make_coffee(menu_item)
    else:
        print("Order not recognized")


